#include "UnitClose.h"
//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#include "Unit1.h"
#pragma hdrstop

#include "UnitClose.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPClose *FormPClose;
//---------------------------------------------------------------------------
__fastcall TFormPClose::TFormPClose(TComponent* Owner)
	: TForm(Owner)
{   
    //read path to databases
	AnsiString mdb,dbf,conn;
	try {   TIniFile *ini;
		ini = new TIniFile( ExtractFilePath( Application->ExeName ) + "Setting.ini" );
		dbf = ini->ReadString("path","dbf","");
		if( !FileExists(dbf) ) throw 1;
	}
	catch(...) {
		ShowMessage("Не удалось подключиться к БД.\nВозможно нет INI-файла или файлов БД.");
		Application->Terminate();
	}
	//connect to *.dbf
	conn="Provider=Advantage OLE DB Provider;User ID=adssys;Data Source=";
	conn += dbf;
	conn += ";Initial Catalog=\"\";Mode=ReadWrite;Advantage Character Data Type=ADS_OEM;Advantage Compression=\"\";";
	conn += "Advantage Encryption Password=\"\";Advantage Filter Options=IGNORE_WHEN_COUNTING;";
	conn += "Advantage Locking Mode=ADS_COMPATIBLE_LOCKING;Advantage Security Mode=ADS_IGNORERIGHTS;";
	conn += "Advantage Server Type=ADS_LOCAL_SERVER;Increment User Count=FALSE;";
	conn += "Show Deleted Records in DBF Tables with Advantage=FALSE;Stored Procedure Connection=FALSE;";
	conn += "Advantage Table Type=ADS_NTX;Trim Trailing Spaces=FALSE;";
	conn += "Use NULL values in DBF Tables with Advantage=FALSE;Advantage Communication Type=\"\";";
	conn += "FIPS=FALSE;EncryptionType=\"\";DDPassword=\"\";TLSCiphers=\"\";TLSCertificate=\"\";";
	conn += "TLSCommonName=\"\";";
	this->ADOconn_dbf->Connected=false;
	this->ADOconn_dbf->ConnectionString = conn;
	this->ADOconn_dbf->Connected=true;

	this->Resizing(wsMinimized);
}
//---------------------------------------------------------------------------
void __fastcall TFormPClose::Timer1Timer(TObject *Sender)
{     
try { 
	Timer1->Enabled = false;
	ProgressBar1->Position = 0;
	//open list which 'shifrs' we must convert
	ADOmdb->Close();
	ADOmdb->SQL->Clear();
	ADOmdb->SQL->Add("select * from to_old_dbf;");
	ADOmdb->Open();
	//if we have no 'shifrs' to convert -> then exit
	if(ADOmdb->IsEmpty()) {
		Application->Terminate();
	}
	int shifr_id = ADOmdb->FieldByName("shifr_id")->AsInteger;

	//delete 'shifr' from list
	ADOsqlexec->Close();
	ADOsqlexec->SQL->Clear();
	ADOsqlexec->SQL->Add("DELETE FROM to_old_dbf ");
	ADOsqlexec->SQL->Add("WHERE (shifr_id = "+AnsiString(shifr_id)+");");
	ADOsqlexec->ExecSQL();

	Application->Title = "Осталось: "+AnsiString(ADOmdb->RecordCount);
	Label2->Caption = "Осталось: "+AnsiString(ADOmdb->RecordCount);

	//open information about selected 'shifr'
	ADOmdb->Close();
	ADOmdb->SQL->Clear();
	ADOmdb->SQL->Add("SELECT * FROM m_karta WHERE id = "+AnsiString(shifr_id)+";");
	ADOmdb->Open();
	//if we have no information about selected 'shifr' -> then go to next
	if(ADOmdb->IsEmpty()) {
		Timer1->Enabled = true;
		return;
	}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// WRITE in other databases ( not my databases) )
// WRITE IN 'KARTOSN' ----->>>
	ProgressBar1->Position = 10;
	//calculate 'time' for current 'shifr' in 'chex=17'...
	/*ADOsqlexec->Close();
	ADOsqlexec->SQL->Clear();
	ADOsqlexec->SQL->Add("SELECT Sum((list.kol*list.time_min)+list.pzv_min) AS [Sum-time] ");
	ADOsqlexec->SQL->Add("FROM ((m_karta INNER JOIN detail ON m_karta.id = detail.shifr_id) ");
	ADOsqlexec->SQL->Add("INNER JOIN list ON detail.id = list.detail) ");
	ADOsqlexec->SQL->Add("WHERE (m_karta.id = "+AnsiString(shifr_id)+") AND (list.chex = \'17\');");
	ADOsqlexec->Open();
	double time_all, time_c17 = ADOsqlexec->FieldByName("Sum-time")->AsFloat / 60.0; //in hours
	//...and 'chex=all'
	ADOsqlexec->Close();
	ADOsqlexec->SQL->Strings[3] = "WHERE (m_karta.id = "+AnsiString(shifr_id)+");";
	ADOsqlexec->Open();
	time_all = ADOsqlexec->FieldByName("Sum-time")->AsFloat / 60.0; //in hours

	ProgressBar1->Position = 20;
	//convert to right format
	UnicodeString table,str_all,str_c17 = FormatFloat("0.00",time_c17);
	str_c17[str_c17.Length()-2]='.'; //format '12.50'
	str_all = FormatFloat("0.00",time_all);
	str_all[str_all.Length()-2]='.'; //format '12.50'
	//in what table we must write 'time'
	int group = ADOmdb->FieldByName("igroup")->AsInteger;
	switch(group) {
		case 1: table = "KARTOSN1";
				break;
		case 2: table = "KARTOSN1";
				break;
		case 3: table = "KARTOSN2";
				break;
		case 4: table = "KARTOSN3";
				break;
		case 5: table = "KARTOSN";
				break;
		case 6: table = "KARTOSN";
				break;
		default:table = "";
				break;
	}
	if(table != "") {
	  int iterations = 1;
	  if(group == 1) iterations = 3;
	  for(int k = 1; k <= iterations; k++) {
		//group=1 writed in "KARTOSN1" and "KARTOSN2" and "KARTOSN3"
		if(k == 2) table[8] = '2';
		if(k == 3) table[8] = '3';
		//update 'time' in other databases ( not my databases) )
		ADOdbf->Close();
		ADOdbf->SQL->Clear();
		ADOdbf->SQL->Add("UPDATE "+table+" SET "+table+".TRED = "+str_c17+", "+table+".TRTOTAL = "+str_all);
		ADOdbf->SQL->Add(" WHERE ("+table+".SH = \'"+ADOmdb->FieldByName("shifr")->AsString+"\')");
		ADOdbf->SQL->Add(" AND ("+table+".CI = 17) AND ("+table+".GR = "+AnsiString(group)+");");
		ADOdbf->ExecSQL();
	  }
	}  */
// <<<----- WRITE IN 'KARTOSN'

// WRITE IN 'SELMK' ------>>>
	ProgressBar1->Position = 40;
	//select 'zagotov' for current 'shifr'
	ADOsqlexec->Close();
	ADOsqlexec->SQL->Clear();
	ADOsqlexec->SQL->Add("SELECT m_karta.shifr, m_karta.num_kart, m_karta.num_zakaz, zagotov.priznak,");
	ADOsqlexec->SQL->Add(" detail.number, detail.dname, material.kod, zagotov.kodzag, zagotov.razmer,");
	ADOsqlexec->SQL->Add(" zagotov.massa, zagotov.kol_zag");
	ADOsqlexec->SQL->Add("FROM material INNER JOIN ((m_karta INNER JOIN detail ON m_karta.id = detail.shifr_id)");
	ADOsqlexec->SQL->Add(" INNER JOIN zagotov ON detail.id = zagotov.detail) ON material.id = zagotov.material ");
	ADOsqlexec->SQL->Add("WHERE (m_karta.id = "+AnsiString(shifr_id)+");");
	ADOsqlexec->Open();
	ProgressBar1->Position = 50;
if( ! ADOsqlexec->IsEmpty() ) {
	//write in 'SELMK1' ('shifrs')
	//delete old 'shifr' if exists
	ADOdbf->Close();
	ADOdbf->SQL->Clear();
	ADOdbf->SQL->Add("DELETE FROM SELMK1 ");
	ADOdbf->SQL->Add("WHERE (SELMK1.SH = \'"+ADOmdb->FieldByName("shifr")->AsString.SubString(1,16)+"\')");
	ADOdbf->SQL->Add(" AND (SELMK1.ZAK = '"+ADOmdb->FieldByName("num_zakaz")->AsString.SubString(1,6)+"')");
	ADOdbf->SQL->Add(" AND (SELMK1.NMK = '"+ADOmdb->FieldByName("num_kart")->AsString.SubString(1,6)+"');");
	ADOdbf->ExecSQL();

	ProgressBar1->Position = 60;
	AnsiString now_date = Date().FormatString("mm\'/\'dd\'/\'yyyy");
	//write new 'shifr'
	ADOdbf->Close();
	ADOdbf->SQL->Clear();
	ADOdbf->SQL->Add("INSERT INTO SELMK1 (SH, ZAK, NMK, NAME, NC, NG, RZAK, NCZAK, DZAP, PRIZNZAP)");
	ADOdbf->SQL->Add(" VALUES (\'"+ADOmdb->FieldByName("shifr")->AsString.SubString(1,16)+"\',");
	ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("num_zakaz")->AsString.SubString(1,6)+"\',");
	ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("num_kart")->AsString.SubString(1,6)+"\',");
	ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("name")->AsString.SubString(1,40)+"\', 17,");
	ADOdbf->SQL->Add(" "+ADOmdb->FieldByName("igroup")->AsString.SubString(1,2)+",");
	ADOdbf->SQL->Add(" "+ADOmdb->FieldByName("kol_shifrov")->AsString.SubString(1,4)+",");
	ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("zakazchik")->AsString.SubString(1,6)+"\', \'"+now_date+"\' , FALSE);");
	ADOdbf->ExecSQL();
	//write in 'SELMK2' ('zagotov')
	//delete old 'zagotov' in 'shifr'
	ADOdbf->Close();
	ADOdbf->SQL->Clear();
	ADOdbf->SQL->Add("DELETE FROM SELMK2 ");
	ADOdbf->SQL->Add("WHERE (SELMK2.SH = \'"+ADOmdb->FieldByName("shifr")->AsString.SubString(1,16)+"\')");
	ADOdbf->SQL->Add(" AND (SELMK2.ZAK = '"+ADOmdb->FieldByName("num_zakaz")->AsString.SubString(1,6)+"')");
	ADOdbf->SQL->Add(" AND (SELMK2.NMK = '"+ADOmdb->FieldByName("num_kart")->AsString.SubString(1,6)+"');");
	ADOdbf->ExecSQL();

	AnsiString convert;
	float massa;
	ADOsqlexec->First();
	ProgressBar1->Position = 80;
	//write new 'zagotov' in 'shifr'
	while( ! ADOsqlexec->Eof ) {
		ADOdbf->Close();
		ADOdbf->SQL->Clear();
		ADOdbf->SQL->Add("INSERT INTO SELMK2 (SH, ZAK, NMK, PRIZN, NDET, NAMDET, KODMAT, KZAG, GAB, VES, KOL)");
		ADOdbf->SQL->Add(" VALUES (\'"+ADOmdb->FieldByName("shifr")->AsString.SubString(1,16)+"\',");
		ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("num_zakaz")->AsString.SubString(1,6)+"\',");
		ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("num_kart")->AsString.SubString(1,6)+"\',");
		ADOdbf->SQL->Add(" \'"+ADOsqlexec->FieldByName("priznak")->AsString.SubString(1,1)+"\',");
		ADOdbf->SQL->Add(" \'"+ADOsqlexec->FieldByName("number")->AsString.SubString(1,14)+"\',");
		ADOdbf->SQL->Add(" \'"+ADOsqlexec->FieldByName("dname")->AsString.SubString(1,30)+"\',");
		ADOdbf->SQL->Add(" \'"+ADOsqlexec->FieldByName("kod")->AsString.SubString(1,6)+"\',");
		ADOdbf->SQL->Add(" \'"+ADOsqlexec->FieldByName("kodzag")->AsString.SubString(1,2)+"\',");
		AnsiString razm = ADOsqlexec->FieldByName("razmer")->AsString;
		if(razm != "") {
			if( (razm[1] == ']') || (razm[1] == '<') ) {
				razm = razm.SubString(2,21);
			} else
			if( ((razm[1] == 'С') || (razm[1] == 'Ш')) && (razm.Length() > 11) )
				razm = razm.SubString(10,21);
			else
				razm = razm.SubString(1,21);
			StringReplace(razm,",",".",TReplaceFlags(rfReplaceAll));
		}
		ADOdbf->SQL->Add(" \'"+razm+"\',");
		massa = ADOsqlexec->FieldByName("massa")->AsFloat;
		if(massa > 99999.99) massa = 99999.99;
		convert = FormatFloat("0.00",massa);
		convert[convert.Pos(",")] = '.'; //format '12.50'
		ADOdbf->SQL->Add(" "+convert+", "+ADOsqlexec->FieldByName("kol_zag")->AsString.SubString(1,6)+" );");
		ADOdbf->ExecSQL();

		ADOsqlexec->Next();
	}
}
// <<<------ WRITE IN 'SELMK'
// WRITE IN 'CHPU' ----->>>
	ProgressBar1->Position = 95;
	//calculate time for 'chpu'
	ADOsqlexec->Close();
	ADOsqlexec->SQL->Clear();
	ADOsqlexec->SQL->Add("SELECT Sum((list.kol*list.time_min)+list.pzv_min) AS [Sum-time], ");
	ADOsqlexec->SQL->Add(" Sum(((list.kol*list.time_min)+list.pzv_min)*tarif.hour) AS [Sum-money]");
	ADOsqlexec->SQL->Add("FROM tarif INNER JOIN (operation INNER JOIN ((m_karta INNER JOIN detail ON m_karta.id = detail.shifr_id) ");
	ADOsqlexec->SQL->Add("INNER JOIN list ON detail.id = list.detail) ON operation.id = list.operation) ON (tarif.razr = list.razr) AND (tarif.kod = operation.tar) ");
	ADOsqlexec->SQL->Add("WHERE (m_karta.id = "+AnsiString(shifr_id)+") AND (list.chex = \'17\')");
	ADOsqlexec->SQL->Add(" AND ( (operation.id >= 108) AND (operation.id <= 135) );");
	ADOsqlexec->Open();
	double t_chpu = ADOsqlexec->FieldByName("Sum-time")->AsFloat / 60.0; //in hours
	//write if 'time' > 0
	if(t_chpu > 0) {
	 if(t_chpu > 9999.99) t_chpu = 9999.99;
	 double m_chpu = ADOsqlexec->FieldByName("Sum-money")->AsFloat / 60.0; //in hours
	 if(m_chpu > 9999.99) m_chpu = 9999.99;
	 AnsiString time_chpu = FormatFloat("0.00", t_chpu );
	 time_chpu[time_chpu.Length()-2] = '.'; //convert to right format for dbf
	 AnsiString money_chpu = FormatFloat("0.00", m_chpu);
	 money_chpu[money_chpu.Length()-2] = '.'; //convert to right format for dbf

	 //write new 'chpu'
	 ADOdbf->Close();
	 ADOdbf->SQL->Clear();
	 ADOdbf->SQL->Add("INSERT INTO CHPU (SH, ZAK, NMK, CHEX, DZAP, CHTIM, MANY)");
	 ADOdbf->SQL->Add(" VALUES (\'"+ADOmdb->FieldByName("shifr")->AsString.SubString(1,16)+"\',");
	 ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("num_zakaz")->AsString.SubString(1,6)+"\',");
	 ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("num_kart")->AsString.SubString(1,6)+"\',");
	 ADOdbf->SQL->Add(" \'"+ADOmdb->FieldByName("zakazchik")->AsString.SubString(1,6)+"\',");
	 ADOdbf->SQL->Add(" \'"+Date().FormatString("mm\'/\'dd\'/\'yyyy")+"\',");
	 ADOdbf->SQL->Add(" "+time_chpu+", "+money_chpu+");");
	 ADOdbf->ExecSQL();
	}
// <<<----- WRITE IN 'CHPU'
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
ProgressBar1->Position = 100;
Timer1->Enabled = true;
} 
catch (...) {
	Application->Terminate();
} 
}
//---------------------------------------------------------------------------
void __fastcall TFormPClose::ADOdbfPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
{
//if post error -> cancel operation
	DataSet->Cancel();
	Action = daAbort;
}
//---------------------------------------------------------------------------

