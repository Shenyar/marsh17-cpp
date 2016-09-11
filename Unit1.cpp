//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "UnitClose.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DataDriverEh"
#pragma link "DBAxisGridsEh"
#pragma link "DBGridEh"
#pragma link "DBGridEhGrouping"
#pragma link "DBGridEhToolCtrls"
#pragma link "DynVarsEh"
#pragma link "EhLibVCL"
#pragma link "GridsEh"
#pragma link "MemTableDataEh"
#pragma link "MemTableEh"
#pragma link "ToolCtrlsEh"
#pragma resource "*.dfm"
TFormMain *FormMain;

TDateTime FileTimeToDateTime(FILETIME *lpftime)
{
	FILETIME localfiletime;
	SYSTEMTIME systime;
	FileTimeToLocalFileTime(lpftime,&localfiletime);
	FileTimeToSystemTime(&localfiletime,&systime);
	return(TDateTime(systime.wYear, systime.wMonth, systime.wDay,systime.wHour, systime.wMinute,systime.wSecond, systime.wMilliseconds));
}
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
	//read path to database
	UnicodeString newVer,mdb,conn;
	try {   TIniFile *ini;
		ini = new TIniFile( ExtractFilePath( Application->ExeName ) + "Setting.ini" );
		mdb = ini->ReadString("path","mdb","");
		newVer = ini->ReadString("path","new_version","");
		if( ! FileExists(mdb) ) throw 1;
		if( FileExists(newVer) ) updateProgram(&newVer);//copy new version of program
	} catch(...) {
		ShowMessage("Не удалось подключиться к БД.\nВозможно нет INI-файла или файлов БД.");
		Application->Terminate();
	}
	//connect to *.mdb
	conn = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
	conn += mdb;
	conn += ";Persist Security Info=False;";
	this->ADOConnection1->Connected=false;
	this->ADOConnection1->ConnectionString = conn;
	this->ADOConnection1->Connected=true;

	this->ADOQuery1->Open();
	this->DBGridEh1->DefaultApplySorting();
	this->Resizing(wsMaximized);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::b_findClick(TObject *Sender)
{
//looking for 'shifr'
	ADOQuery1->Close();
	ADOQuery1->SQL->Strings[1] = "where shifr like \'" + Edit1->Text + "%\'";
	ADOQuery1->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::b_cancel_findClick(TObject *Sender)
{
//cancel filter
	ADOQuery1->Close();
	ADOQuery1->SQL->Strings[1] = "";
	ADOQuery1->Open();
	Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//on enter looking for 'shifr'
	if(Key == 13) this->b_findClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::b_addClick(TObject *Sender)
{
//add new 'shifr'
	DBGridEh1->SetFocus();
	ADOQuery1->Insert();
	FormDetail->Show();
	this->Hide();
	FormDetail->ADOzag->Close();
	FormDetail->ADOdetail->Close();
	FormDetail->e_shifr->SetFocus();
	FormDetail->isModified = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::b_editClick(TObject *Sender)
{
//edit selected 'shifr'
	DBGridEh1->SetFocus();
	FormDetail->Show();
	this->Hide();
	FormDetail->ADOdetail->Close();
	FormDetail->ADOdetail->SQL->Strings[2] = "shifr_id = " + ADOQuery1->FieldByName("id")->AsString;
	FormDetail->ADOdetail->Open();
	FormDetail->DBGridDetail->SetFocus();
	FormDetail->isModified = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::DBGridEh1DblClick(TObject *Sender)
{
//edit 'shifr' on double click
	this->b_editClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ADOQuery1PostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
{
	E->Message = "Заполнены не все обязательные поля!\nНеобходимо заполнить:\n\"Шифр\"\n\"Маршрутная карта\"\n\"\№ заказа\"\n\"Группа\"\n\"Кол-во по заказу\"";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::b_delClick(TObject *Sender)
{
//delete 'shifr'
	switch(Application->MessageBoxW(L"Удалить выбранный шифр?",L"Подтвердите удаление",MB_YESNO)) {
		case IDYES:
			ADOQuery1->Delete();
			break;
		case IDNO:
			return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::b_copyClick(TObject *Sender)
{
//copy 'shifr'
	this->DBGridEh1->SetFocus();
	if(MessageDlg("Скопировать выбранный шифр?",mtConfirmation,mbYesNo,0) == mrNo) return;
	UnicodeString newid,id,shifr, m_karta, num_zakaz,sql,tmp[12];
	id = ADOQuery1->FieldByName("id")->AsString;
	shifr = ADOQuery1->FieldByName("shifr")->AsString;
	m_karta = ADOQuery1->FieldByName("num_kart")->AsString;
	num_zakaz = ADOQuery1->FieldByName("num_zakaz")->AsString;
	TDateTime d = Date();

	//copy 'm_karta'
	for(int i=1; i<11; i++) {
		tmp[i] = ADOQuery1->Fields->operator [](i)->AsString;
	}
	tmp[11] = d.DateString();
	ADOQuery1->Insert();
	for(int i=1; i<12; i++) {
		ADOQuery1->Fields->operator [](i)->AsString = tmp[i];
	}
	ADOQuery1->FieldByName("date")->AsDateTime = Date();
	ADOQuery1->Post();
	newid = ADOQuery1->FieldByName("id")->AsString;

	//copy 'details'
	sql = "";
	sql += "INSERT INTO detail ( shifr_id, [number], dname, kol_na_shifr )";
	sql += " SELECT "+newid+" AS var1, detail.number, detail.dname, detail.kol_na_shifr";
	sql += " FROM detail WHERE detail.shifr_id = "+id+" ORDER BY detail.id;";
	ADOexecsql->CommandText = sql;
	ADOexecsql->Execute();

	//open "old details" and copy "operations" to "new details"
	FormDetail->ADOsqlexec->Close();//- open old details --
	FormDetail->ADOsqlexec->SQL->Clear();
	FormDetail->ADOsqlexec->SQL->Add("SELECT id FROM detail WHERE shifr_id = "+id+" order by id;");
	FormDetail->ADOsqlexec->Open();
	FormDetail->ADOsqlexec->First(); //-------------------/
	FormMain->ADOsql->Close();//- open new details ------
	FormMain->ADOsql->SQL->Clear();
	FormMain->ADOsql->SQL->Add("SELECT id FROM detail WHERE shifr_id = "+newid+" order by id;");
	FormMain->ADOsql->Open();
	FormMain->ADOsql->First();//------------------------/
	while( !FormDetail->ADOsqlexec->Eof ) {
		newid = FormMain->ADOsql->FieldByName("id")->AsString; //new detail
		id = FormDetail->ADOsqlexec->FieldByName("id")->AsString;//old detail
		//copy operation
		sql = "";
		sql += "INSERT INTO list ( detail, operation, time_min, razr, pzv_min, kol, num_op, chex )";
		sql += " SELECT "+newid+" AS var1, list.operation, list.time_min, list.razr, list.pzv_min, list.kol, list.num_op, list.chex";
		sql += " FROM list WHERE list.detail = "+id+";";
		ADOexecsql->CommandText = sql;
		ADOexecsql->Execute();
		//copy 'zagotov'
        sql = "";
		sql += "INSERT INTO zagotov ( detail, material, razmer, massa, kol_zag, kodzag )";
		sql += " SELECT "+newid+" AS var1, zagotov.material, zagotov.razmer, zagotov.massa, zagotov.kol_zag, zagotov.kodzag ";
		sql += " FROM zagotov WHERE zagotov.detail = "+id+";";
		ADOexecsql->CommandText = sql;
		ADOexecsql->Execute();
		FormDetail->ADOsqlexec->Next();
		FormMain->ADOsql->Next();
	}

	FormDetail->Show();
	this->Hide();
	FormDetail->ADOdetail->Close();
	FormDetail->ADOdetail->SQL->Strings[2] = "shifr_id = " + ADOQuery1->FieldByName("id")->AsString;
	FormDetail->ADOdetail->Open();
	FormDetail->isModified = 0;

	ShowMessage("Шифр успешно скопирован.");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::b_printClick(TObject *Sender)
{
//print list of 'shifrs'
	FormPrint->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::b_add_printClick(TObject *Sender)
{
//add 'shifr' to print query
	FormPrint->ListName->Items->Add( ADOQuery1->FieldByName("shifr")->AsString );
	FormPrint->ListId->Add( ADOQuery1->FieldByName("id")->AsString );
	//Users want to save print query every time
	FormPrint->ListId->SaveToFile(ExtractFilePath(Application->ExeName)+"PrintId.txt");
	FormPrint->ListName->Items->SaveToFile(ExtractFilePath(Application->ExeName)+"PrintName.txt");
	ShowMessage("Шифр "+ADOQuery1->FieldByName("shifr")->AsString+" добавлен в печать.");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ADOQuery1AfterPost(TDataSet *DataSet)
{
	FormDetail->isModified = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
//transfer new 'shifrs' into the old database
	Action = caNone;
	this->Hide();
	FormPClose->Show();
	FormPClose->Timer1->Enabled = true;//run transfer
}
//---------------------------------------------------------------------------
void TFormMain::updateProgram(UnicodeString *newVer)
{
//copy new version of this program
	TWin32FileAttributeData fold,fnew;
	TFileTime ft1;
	TSystemTime st;
	//get last write time for both files
	GetFileAttributesEx(newVer->c_str(),GetFileExInfoStandard,&fnew);
	GetFileAttributesEx(Application->ExeName.c_str(),GetFileExInfoStandard,&fold);
	//if we have new version of our program
	if(FileTimeToDateTime(&fnew.ftLastWriteTime) > FileTimeToDateTime(&fold.ftLastWriteTime)) {
		//copy new version of program
		DeleteFile((Application->ExeName+".bak").c_str());
		RenameFile(Application->ExeName.c_str(),(Application->ExeName+".bak").c_str());
		CopyFile(newVer->c_str(),Application->ExeName.c_str(),false);
		//run new version
		ShellExecute(Handle, L"open", Application->ExeName.c_str(), NULL, NULL, SW_NORMAL);
		Application->Terminate();
	}
}

