//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
UnicodeString group_name[] = {"Резцы","Режущая","Резьба","Сложно-фасонная","Мерительная","Точная механика","Инструмент II порядка"};
double group_percent[] = {0.07, 0.06, 0.07, 0.13, 0.12, 0.12, 0.000001};
TFormPrint *FormPrint;
//---------------------------------------------------------------------------
__fastcall TFormPrint::TFormPrint(TComponent* Owner)
	: TForm(Owner)
{
	ListId = new TStringList();
	ListName->Items->LoadFromFile(ExtractFilePath(Application->ExeName)+"PrintName.txt");
	ListId->LoadFromFile(ExtractFilePath(Application->ExeName)+"PrintId.txt");
}
//---------------------------------------------------------------------------
void __fastcall TFormPrint::Button2Click(TObject *Sender)
{
//detele not needed 'shifr' from print query
	if(ListName->ItemIndex >= 0) {
		ListId->Delete( ListName->ItemIndex );
		ListName->Items->Delete( ListName->ItemIndex );
	}
	else ShowMessage("Не выбран шифр, который удалить.");
}
//---------------------------------------------------------------------------
void __fastcall TFormPrint::Button1Click(TObject *Sender)
{
//print all 'shifrs' query
 if(PrintDialog1->Execute()) {
	int i=0;
	while( i < ListId->Count ) {
//!!!!!! print "Комплектовочная карта к приспособлению" !!!!!!!!
		if( CheckComplect->Checked ) {
			FormMain->ADOsql->Close();
			FormMain->ADOsql->SQL->Clear();
			FormMain->ADOsql->SQL->Add("select * from m_karta where m_karta.id = "+ListId->Strings[i]+";");
			FormMain->ADOsql->Open();
			//prepare printer
			int strx, stry, page = 1, noprn=0, pos;
			float dpix, dpiy, istr=0;
			TRect rect;
			UnicodeString num_zakaz = FormMain->ADOsql->FieldByName("num_zakaz")->AsString;
			UnicodeString num_kart = FormMain->ADOsql->FieldByName("num_kart")->AsString;
			UnicodeString shifr = FormMain->ADOsql->FieldByName("shifr")->AsString;
			UnicodeString name = FormMain->ADOsql->FieldByName("name")->AsString;
			//pixels per inch/2.54=sm
			dpix = GetDeviceCaps(Printer()->Handle,LOGPIXELSX) / 2.54;
			dpiy = GetDeviceCaps(Printer()->Handle,LOGPIXELSY) / 2.54;
			Printer()->Orientation = poLandscape;
			//begin print
			Printer()->BeginDoc();
			Printer()->Canvas->Brush->Color = clWhite;
			Printer()->Canvas->Pen->Color = clBlack;
			Printer()->Canvas->Font->Name = "Courier new";
			Printer()->Canvas->Font->Size = 10;
			TDateTime t;
			AnsiString temp;
			//select details of the 'shifr'
			FormMain->ADOsql->Close();
			FormMain->ADOsql->SQL->Clear();
			FormMain->ADOsql->SQL->Add("select * from detail where detail.shifr_id = "+ListId->Strings[i]+";");
			FormMain->ADOsql->Open();
			FormMain->ADOsql->First();
nextpage:   AnsiString toprn = "Комплектовочная карта к приспособлению ( от " + t.CurrentDateTime() + " )";
			Printer()->Canvas->TextOutW(8*dpix,1*dpiy,toprn);
			//information about 'shifr'
			Printer()->Canvas->MoveTo(0.9*dpix,1.6*dpiy);
			Printer()->Canvas->LineTo(28.6*dpix,1.6*dpiy);
			Printer()->Canvas->LineTo(28.6*dpix,2.2*dpiy);
			Printer()->Canvas->LineTo(0.9*dpix,2.2*dpiy);
			Printer()->Canvas->LineTo(0.9*dpix,1.6*dpiy);
			toprn = "Номер заказа: " + num_zakaz;
			Printer()->Canvas->TextOutW(1.0*dpix,1.65*dpiy,toprn);
			toprn = "Номер маршрутной карты: " + num_kart;
			Printer()->Canvas->TextOutW(5.9*dpix,1.65*dpiy,toprn);
			toprn = "Шифр: " + shifr;
			Printer()->Canvas->TextOutW(13.1*dpix,1.65*dpiy,toprn);
			toprn = "Наименование: " + name;
			Printer()->Canvas->TextOutW(17.9*dpix,1.65*dpiy,toprn);
			toprn = "Лист: " + AnsiString(page);
			Printer()->Canvas->TextOutW(26.6*dpix,1.65*dpiy,toprn);
			//header
			Printer()->Canvas->MoveTo(0.9*dpix,2.2*dpiy);
			Printer()->Canvas->LineTo(0.9*dpix,2.8*dpiy);
			Printer()->Canvas->LineTo(28.6*dpix,2.8*dpiy);
			Printer()->Canvas->LineTo(28.6*dpix,2.2*dpiy);
			Printer()->Canvas->MoveTo(4.1*dpix,2.2*dpiy);
			Printer()->Canvas->LineTo(4.1*dpix,2.8*dpiy);
			Printer()->Canvas->MoveTo(4.9*dpix,2.2*dpiy);
			Printer()->Canvas->LineTo(4.9*dpix,2.8*dpiy);
			Printer()->Canvas->MoveTo(7.4*dpix,2.2*dpiy);
			Printer()->Canvas->LineTo(7.4*dpix,2.8*dpiy);
			Printer()->Canvas->TextOutW(1.8*dpix,2.3*dpiy,"Деталь");
			Printer()->Canvas->TextOutW(4.2*dpix,2.3*dpiy,"Кол");
			Printer()->Canvas->TextOutW(5.3*dpix,2.3*dpiy,"Материал");
			Printer()->Canvas->TextOutW(16.4*dpix,2.3*dpiy,"Операции и время");
			//print string with detail and operations
			while( ! FormMain->ADOsql->Eof ) {
				if(istr > 6) {
					Printer()->NewPage();
					istr = 0;
					page++;
					goto nextpage;
				}
				int shifr_id = FormMain->ADOsql->FieldByName("id")->AsInteger;
				Printer()->Canvas->MoveTo(0.9*dpix,(2.8+istr*2.2)*dpiy);
				Printer()->Canvas->LineTo(0.9*dpix,(5.0+istr*2.2)*dpiy);
				Printer()->Canvas->MoveTo(28.6*dpix,(2.8+istr*2.2)*dpiy);
				Printer()->Canvas->LineTo(28.6*dpix,(5.0+istr*2.2)*dpiy);
				Printer()->Canvas->MoveTo(4.1*dpix,(2.8+istr*2.2)*dpiy);
				Printer()->Canvas->LineTo(4.1*dpix,(5.0+istr*2.2)*dpiy);
				Printer()->Canvas->MoveTo(4.9*dpix,(2.8+istr*2.2)*dpiy);
				Printer()->Canvas->LineTo(4.9*dpix,(5.0+istr*2.2)*dpiy);
				Printer()->Canvas->MoveTo(7.4*dpix,(2.8+istr*2.2)*dpiy);
				Printer()->Canvas->LineTo(7.4*dpix,(5.0+istr*2.2)*dpiy);
				//if 'detail' is not printed yet
				if(noprn==0) {
				   //print header for detail...
				   toprn = FormMain->ADOsql->FieldByName("dname")->AsString;
				   rect.left=1.0*dpix; rect.top=(2.9+istr*2.2)*dpiy; rect.right=4.05*dpix; rect.bottom=(3.4+istr*2.2)*dpiy;
				   Printer()->Canvas->TextRect(rect,1.0*dpix,(2.9+istr*2.2)*dpiy,toprn);
				   toprn = FormMain->ADOsql->FieldByName("number")->AsString;
				   rect.left=1.0*dpix; rect.top=(3.5+istr*2.2)*dpiy; rect.right=4.05*dpix; rect.bottom=(3.95+istr*2.2)*dpiy;
				   Printer()->Canvas->TextRect(rect,1.0*dpix,(3.5+istr*2.2)*dpiy,toprn);
				   toprn = FormMain->ADOsql->FieldByName("kol_na_shifr")->AsString;
				   if(toprn.ToInt() > 1000 ) {
					rect.left=4.05*dpix; rect.top=(2.9+istr*2.2)*dpiy; rect.right=4.89*dpix; rect.bottom=(3.4+istr*2.2)*dpiy;
					Printer()->Canvas->TextRect(rect,4.05*dpix,(2.9+istr*2.2)*dpiy,toprn);
				   }
				   else {
					rect.left=4.25*dpix; rect.top=(2.9+istr*2.2)*dpiy; rect.right=4.85*dpix; rect.bottom=(3.4+istr*2.2)*dpiy;
					Printer()->Canvas->TextRect(rect,4.25*dpix,(2.9+istr*2.2)*dpiy,toprn);
				   }
				   //select 'zagotov' of 'detail'
				   ADOtemp->Close();
				   ADOtemp->SQL->Clear();
				   ADOtemp->SQL->Add("SELECT material.mname, zagotov.razmer FROM material ");
				   ADOtemp->SQL->Add("INNER JOIN zagotov ON zagotov.material = material.id ");
				   ADOtemp->SQL->Add("WHERE zagotov.detail = "+FormMain->ADOsql->FieldByName("id")->AsString+";");
				   ADOtemp->Open();
				   while( ! ADOtemp->Eof ) {
						if(ADOtemp->FieldByName("mname")->AsString != "") {
							toprn = ADOtemp->FieldByName("mname")->AsString;
							pos = 0;
							pos = toprn.LastDelimiter(" ");
							//change words if we have spaces ("45 сталь" change to "сталь 45")
							if(pos) toprn = toprn.SubString(pos+1,toprn.Length())+" "+toprn.SubString(1,pos);
							rect.left=5.0*dpix; rect.top=(2.9+istr*2.2)*dpiy; rect.right=7.3*dpix; rect.bottom=(3.4+istr*2.2)*dpiy;
							//WordWrap for name of 'material'
							if(( Printer()->Canvas->TextWidth(toprn) > (2.3*dpix) ) && (pos)) {
								pos = toprn.Pos(" ");
								Printer()->Canvas->TextRect(rect,5.0*dpix,(2.9+istr*2.2)*dpiy,toprn.SubString(1,pos));
								toprn.Delete(1,pos);
								rect.top += 0.4*dpiy;
								rect.bottom += 0.4*dpiy;
								Printer()->Canvas->TextRect(rect,5.0*dpix,(3.3+istr*2.2)*dpiy,toprn);
							}
							else {
								Printer()->Canvas->TextRect(rect,5.0*dpix,(2.9+istr*2.2)*dpiy,toprn);
							}
							if(ADOtemp->FieldByName("razmer")->AsString != "") {
							 rect.left=5.0*dpix; rect.top=(4.0+istr*2.2)*dpiy; rect.right=7.3*dpix; rect.bottom=(4.45+istr*2.2)*dpiy;
							 Printer()->Canvas->TextRect(rect,5.0*dpix,(4.0+istr*2.2)*dpiy,ADOtemp->FieldByName("razmer")->AsString);
							}
							break;
						}
						ADOtemp->Next();
				   }
				   //...end print header for detail

				   //select 'operations' of 'detail'
				   ADOtemp->Close();
				   ADOtemp->SQL->Clear();
				   ADOtemp->SQL->Add("SELECT operation.oname, ((list.time_min*list.kol)+list.pzv_min) AS [sum_time]");
				   ADOtemp->SQL->Add("FROM list  INNER JOIN operation  ON list.operation = operation.id");
				   ADOtemp->SQL->Add("WHERE (list.detail = "+FormMain->ADOsql->FieldByName("id")->AsString+") ");
				   ADOtemp->SQL->Add("ORDER BY list.num_op;");
				   ADOtemp->Open();
				}
				//else continue printing 'operations' of 'detail'
				else noprn = 0;
				for(int i=1;i<10;i++) {
				   Printer()->Canvas->MoveTo((7.4+i*2.1)*dpix,(2.8+istr*2.2)*dpiy);
				   Printer()->Canvas->LineTo((7.4+i*2.1)*dpix,(5.0+istr*2.2)*dpiy);
				}
				//print 'operations'
				for(int i=1;i<11;i++) {
					if(ADOtemp->Eof) {
						//if 'operations' are ended -> go to next 'detail'
						FormMain->ADOsql->Next();
						break;
					}
					toprn = ADOtemp->FieldByName("oname")->AsString;
					//delete 'operation' number
					int id=0;
					id = toprn.Pos(" ");
					toprn = toprn.Delete(1,id);
					//print 'operation' with WordWrap
					for(int k=0;k<4;k++) {
						id = toprn.Pos(" ");
						rect.left=(5.4+i*2.1)*dpix; rect.top=(2.85+istr*2.2+k*0.35)*dpiy; rect.right=(7.35+i*2.1)*dpix; rect.bottom=(3.85+istr*2.2+k*0.35)*dpiy;
						if(id) {
							Printer()->Canvas->TextRect(rect,(5.4+i*2.1)*dpix,(2.85+istr*2.2+k*0.35)*dpiy,toprn.SubString(1,id-1));
							toprn.Delete(1,id);
						}
						else {
							Printer()->Canvas->TextRect(rect,(5.4+i*2.1)*dpix,(2.85+istr*2.2+k*0.35)*dpiy,toprn);
							break;
                        }
					}
					//if time > 0, then print 'time'
					if(ADOtemp->FieldByName("sum_time")->AsFloat > 0) {
						toprn = FormatFloat( "0.00", ADOtemp->FieldByName("sum_time")->AsFloat );
						rect.left=(5.4+i*2.1)*dpix; rect.top=(4.5+istr*2.2)*dpiy; rect.right=(7.35+i*2.1)*dpix; rect.bottom=(4.95+istr*2.2)*dpiy;
						Printer()->Canvas->TextRect(rect,(5.4+i*2.1)*dpix,(4.5+istr*2.2)*dpiy,toprn);
					}
					ADOtemp->Next();
				}
				//underline detail with operations (for starts new detail)
				Printer()->Canvas->MoveTo(28.6*dpix,(5.0+istr*2.2)*dpiy);
				if((shifr_id != FormMain->ADOsql->FieldByName("id")->AsInteger) ||
					(FormMain->ADOsql->Eof)) {
						Printer()->Canvas->LineTo(0.9*dpix,(5.0+istr*2.2)*dpiy);
				}
				else {
					Printer()->Canvas->LineTo(7.4*dpix,(5.0+istr*2.2)*dpiy);
					noprn=1;
				}
				//underline between 'operation name' and 'time'
				Printer()->Canvas->MoveTo((7.4)*dpix,(4.4+istr*2.2)*dpiy);
				Printer()->Canvas->LineTo((28.6)*dpix,(4.4+istr*2.2)*dpiy);
				istr++;
			}
			Printer()->EndDoc();
		}
//!!!!!! print "Карта трудоемкости шифра на изделие"  !!!!!!!!!!
		if( CheckTrud->Checked ) {
			//prepare printer
			FormMain->ADOsql->Close();
			FormMain->ADOsql->SQL->Clear();
			FormMain->ADOsql->SQL->Add("select * from m_karta where m_karta.id = "+ListId->Strings[i]+";");
			FormMain->ADOsql->Open();
			int id_marsh = FormMain->ADOsql->FieldByName("id")->AsInteger;
			int group = FormMain->ADOsql->FieldByName("igroup")->AsInteger;
			int kol_shifrov = FormMain->ADOsql->FieldByName("kol_shifrov")->AsInteger;
			int strx, stry, id;
			float dpix, dpiy, str = 0;
			TRect rect;
			//pixels per inch/2.54=sm
			dpix = GetDeviceCaps(Printer()->Handle,LOGPIXELSX) / 2.54;
			dpiy = GetDeviceCaps(Printer()->Handle,LOGPIXELSY) / 2.54;
			Printer()->Orientation = poLandscape;
			//begin print
			Printer()->BeginDoc();
			Printer()->Canvas->Brush->Color = clWhite;
			Printer()->Canvas->Pen->Color = clBlack;
			Printer()->Canvas->Font->Name = "Courier new";
			Printer()->Canvas->Font->Size = 10;
			TDateTime t;
			AnsiString temp;
			AnsiString toprn = "Карта трудоемкости шифра по профессиям на изделие ( от " + t.CurrentDateTime() + " )";
			Printer()->Canvas->TextOutW(7.1*dpix,1*dpiy,toprn);
			//header 1...
			Printer()->Canvas->MoveTo(0.7*dpix,1.6*dpiy);
			Printer()->Canvas->LineTo(28.6*dpix,1.6*dpiy);
			Printer()->Canvas->LineTo(28.6*dpix,2.6*dpiy);
			Printer()->Canvas->LineTo(0.7*dpix,2.6*dpiy);
			Printer()->Canvas->LineTo(0.7*dpix,1.6*dpiy);
			toprn = "Шифр: " + FormMain->ADOsql->FieldByName("shifr")->AsString;
			Printer()->Canvas->TextOutW(1.1*dpix,1.65*dpiy,toprn);
			toprn = "Наименование: " + FormMain->ADOsql->FieldByName("name")->AsString;
			Printer()->Canvas->TextOutW(6.5*dpix,1.65*dpiy,toprn);
			toprn = "Цех-заказчик: " + FormMain->ADOsql->FieldByName("zakazchik")->AsString;
			Printer()->Canvas->TextOutW(14.0*dpix,1.65*dpiy,toprn);
			toprn = "Группа-изготовитель: " + group_name[group-1];
			Printer()->Canvas->TextOutW(19.0*dpix,1.65*dpiy,toprn);
			//header 2...
			toprn = "Номер заказа: " + FormMain->ADOsql->FieldByName("num_zakaz")->AsString;
			Printer()->Canvas->TextOutW(1.1*dpix,2.15*dpiy,toprn);
			toprn = "Номер маршрутной карты: " + FormMain->ADOsql->FieldByName("num_kart")->AsString;
			Printer()->Canvas->TextOutW(6.5*dpix,2.15*dpiy,toprn);
			toprn = "Размер заказа: " + FormMain->ADOsql->FieldByName("kol_shifrov")->AsString;
			Printer()->Canvas->TextOutW(14.0*dpix,2.15*dpiy,toprn);
			toprn = "Кол-во технологий: " + FormMain->ADOsql->FieldByName("kol_tech")->AsString;
			Printer()->Canvas->TextOutW(19.0*dpix,2.15*dpiy,toprn);
			//select list of 'operations' for current 'group'
			FormMain->ADOsql->Close();
			FormMain->ADOsql->SQL->Clear();
			FormMain->ADOsql->SQL->Add("select * from operation where (operation.group = "+AnsiString(group)+")");
			FormMain->ADOsql->SQL->Add(" AND (operation.prof <> 0) order by operation.prof;");
			FormMain->ADOsql->Open();
			FormMain->ADOsql->First();

			int row = 0;
			while( ! FormMain->ADOsql->Eof ) {
			  //print strings with 'operations'
			  Printer()->Canvas->MoveTo(0.7*dpix,2.6*dpiy+str);
			  Printer()->Canvas->LineTo(0.7*dpix,5.5*dpiy+str);
			  for(int i=1; i<=9; i++) {
				Printer()->Canvas->MoveTo((0.7+3.1*i)*dpix,2.6*dpiy+str);
				Printer()->Canvas->LineTo((0.7+3.1*i)*dpix,5.5*dpiy+str);
				//don`t print last 'operation' many times
				if( FormMain->ADOsql->Eof ) continue;

				toprn = FormMain->ADOsql->FieldByName("oname")->AsString;
				//concatenate names of 'operations' with 'profession'=4 for groups = {1,3,5,6,7}
				if( FormMain->ADOsql->FieldByName("prof")->AsInteger == 4 ) {
					if((group == 2) || (group == 4)) {}
					else {
					 FormMain->ADOsql->Next();
					 UnicodeString tmp = FormMain->ADOsql->FieldByName("oname")->AsString;
					 tmp.Delete(1,tmp.Pos(" "));
					 toprn += " " + tmp;
					 toprn.Delete(1,1);
					}
				}

				//print 'operation' with WordWrap
				for(int k=-1;k<4;k++) {
					id = toprn.Pos(" ");
					if(k == -1) {
						//print number of 'operation'
						rect.left=(2.0+(i-1)*3.1)*dpix; rect.top=(4.15)*dpiy+str; rect.right=(0.5+i*3.1)*dpix; rect.bottom=(4.45)*dpiy+str;
						Printer()->Canvas->TextRect(rect,(2.0+(i-1)*3.1)*dpix,(4.15)*dpiy+str,toprn.SubString(1,id-1));
						toprn.Delete(1,id);
						continue;
					}
					//print name of 'operation'
					rect.left=(1.1+(i-1)*3.1)*dpix; rect.top=(2.65+k*0.35)*dpiy+str; rect.right=(0.5+i*3.1)*dpix; rect.bottom=(3.0+k*0.35)*dpiy+str;
					if(id) {
						Printer()->Canvas->TextRect(rect,(1.1+(i-1)*3.1)*dpix,(2.65+k*0.35)*dpiy+str,toprn.SubString(1,id-1));
						toprn.Delete(1,id);
					}
					else {
						Printer()->Canvas->TextRect(rect,(1.1+(i-1)*3.1)*dpix,(2.65+k*0.35)*dpiy+str,toprn);
						break;
					}
				}

				//print time associated with selected 'operation'
				ADOtemp->Close();
				ADOtemp->SQL->Clear();
				ADOtemp->SQL->Add("SELECT Sum(((list.kol*list.time_min)+list.pzv_min)/m_karta.kol_shifrov) AS [Sum-time]");
				ADOtemp->SQL->Add("FROM operation INNER JOIN ((m_karta INNER JOIN detail ON m_karta.id = detail.shifr_id) ");
				ADOtemp->SQL->Add("INNER JOIN list ON detail.id = list.detail) ON operation.id = list.operation ");
				ADOtemp->SQL->Add("WHERE (((m_karta.id)="+AnsiString(id_marsh)+") AND ");
				ADOtemp->SQL->Add("((operation.prof)="+AnsiString(i+row*9)+"));");
				ADOtemp->Open();
				toprn = FormatFloat("0.00",ADOtemp->FieldByName("Sum-time")->AsFloat);
				if( ADOtemp->FieldByName("Sum-time")->AsFloat > 0 ) {
				  rect.left=(1.25+(i-1)*3.1)*dpix; rect.top=(4.9)*dpiy+str; rect.right=(0.55+i*3.1)*dpix; rect.bottom=(5.4)*dpiy+str;
				  Printer()->Canvas->TextRect(rect,(1.25+(i-1)*3.1)*dpix,(4.9)*dpiy+str,toprn);
				}

				//go to next 'operation'
				if( ! FormMain->ADOsql->Eof ) {
					FormMain->ADOsql->Next();
				}
			  }
			  //underline between 'operation name' and 'operation time'
			  Printer()->Canvas->MoveTo(0.7*dpix,4.6*dpiy+str);
			  Printer()->Canvas->LineTo(28.6*dpix,4.6*dpiy+str);
			  Printer()->Canvas->MoveTo(0.7*dpix,5.5*dpiy+str);
			  Printer()->Canvas->LineTo(28.6*dpix,5.5*dpiy+str);

			  row++;
			  //add next string with 'operation'
			  if( ! FormMain->ADOsql->Eof ) str += 2.9*dpiy;
			}

			//print 'dop_osnastka'
			FormMain->ADOsql->Close();
			FormMain->ADOsql->SQL->Clear();
			FormMain->ADOsql->SQL->Add("SELECT Sum(zakaz*trud/"+AnsiString(kol_shifrov)+") AS [sum_time], ");
			FormMain->ADOsql->SQL->Add("Sum(zakaz*money/"+AnsiString(kol_shifrov)+") AS [sum_money]");
			FormMain->ADOsql->SQL->Add("FROM dop_osnastka");
			FormMain->ADOsql->SQL->Add("WHERE shifr_id = "+AnsiString(id_marsh)+";");
			FormMain->ADOsql->Open();
			//if 'dop_osnastka' is exist -> then print it
			if(FormMain->ADOsql->FieldByName("sum_time")->AsFloat > 0) {
				Printer()->Canvas->MoveTo(28.6*dpix,5.5*dpiy+str);
				Printer()->Canvas->LineTo(28.6*dpix,6.0*dpiy+str);
				Printer()->Canvas->LineTo(0.7*dpix,6.0*dpiy+str);
				Printer()->Canvas->LineTo(0.7*dpix,5.5*dpiy+str);
				Printer()->Canvas->TextOutW(2.0*dpix,5.6*dpiy+str,"Дополнительная оснастка:");

				double time = FormMain->ADOsql->FieldByName("sum_time")->AsFloat;
				double money = FormMain->ADOsql->FieldByName("sum_money")->AsFloat;
				Printer()->Canvas->TextOutW(8.5*dpix,5.6*dpiy+str,"трудоемкость: "+FormatFloat("0.00",time));
				Printer()->Canvas->TextOutW(14.0*dpix,5.6*dpiy+str,"стоимость: "+FormatFloat("0.00",money));

				f_offset = str/dpiy + 0.5;
			}
			else {
				f_offset = str/dpiy;
			}

			//select list of 'chex' != 17
			FormMain->ADOsql->Close();
			FormMain->ADOsql->SQL->Clear();
			FormMain->ADOsql->SQL->Add("SELECT list.chex");
			FormMain->ADOsql->SQL->Add("FROM (m_karta INNER JOIN detail ON m_karta.id = detail.shifr_id) INNER JOIN list ON detail.id = list.detail");
			FormMain->ADOsql->SQL->Add("WHERE m_karta.id = "+AnsiString(id_marsh));
			FormMain->ADOsql->SQL->Add("GROUP BY list.chex");
			FormMain->ADOsql->SQL->Add("HAVING list.chex <> \'17\';");
			FormMain->ADOsql->Open();
			FormMain->ADOsql->First();

			//how many 'chex' we must print?
			int len;
			if(FormMain->ADOsql->IsEmpty()) {
				len = 2;
				toprn = "";
			}
			else {
				len = 2 + FormMain->ADOsql->RecordCount;
				if(len > 7) {
					toprn = "Другие цеха";
					len = 3;
				}
				else toprn = "Цех: "+FormMain->ADOsql->FieldByName("chex")->AsString;
			}

			//print frame for every 'chex'
			for(int c = 0; c < len; c++) {
				Printer()->Canvas->MoveTo((28.6-c*4)*dpix,(5.5+f_offset)*dpiy);
				Printer()->Canvas->LineTo((28.6-c*4)*dpix,(9.8+f_offset)*dpiy);
				Printer()->Canvas->LineTo((24.6-c*4)*dpix,(9.8+f_offset)*dpiy);
				Printer()->Canvas->LineTo((24.6-c*4)*dpix,(5.5+f_offset)*dpiy);
				Printer()->Canvas->MoveTo((24.6-c*4)*dpix,(6.3+f_offset)*dpiy);
				Printer()->Canvas->LineTo((28.6-c*4)*dpix,(6.3+f_offset)*dpiy);
				Printer()->Canvas->MoveTo((26.6-c*4)*dpix,(6.3+f_offset)*dpiy);
				Printer()->Canvas->LineTo((26.6-c*4)*dpix,(9.8+f_offset)*dpiy);
				Printer()->Canvas->TextOutW((25.1-c*4)*dpix,(6.5+f_offset)*dpiy,"Время");
				Printer()->Canvas->TextOutW((27.0-c*4)*dpix,(6.5+f_offset)*dpiy,"Деньги");
				switch(c) {
					case 0:	//if we have only 'chex=17' then print "Цех 17" without "ИТОГО"
							if(len == 2) {Printer()->Canvas->TextOutW((25.9-c*4)*dpix,(5.7+f_offset)*dpiy,"Цех: 17"); c++;}
							else Printer()->Canvas->TextOutW((26.1-c*4)*dpix,(5.7+f_offset)*dpiy,"ИТОГО");
							break;
					case 1: Printer()->Canvas->TextOutW((25.9-c*4)*dpix,(5.7+f_offset)*dpiy,"Цех: 17");
							break;
					case 2: Printer()->Canvas->TextOutW((25.9-c*4)*dpix,(5.7+f_offset)*dpiy,toprn);
							break;
					default:FormMain->ADOsql->Next();
							toprn = "Цех: "+FormMain->ADOsql->FieldByName("chex")->AsString;
							Printer()->Canvas->TextOutW((25.9-c*4)*dpix,(5.7+f_offset)*dpiy,toprn);
							break;
				}
			}

			//print summary time and money for all 'operations' in the 'shifr'
			ADOtemp->Close();
			ADOtemp->SQL->Clear();
			ADOtemp->SQL->Add("SELECT Sum(((list.kol*list.time_min)+list.pzv_min)/m_karta.kol_shifrov) AS [Sum-time], ");
			ADOtemp->SQL->Add("Sum((((list.kol*list.time_min)+list.pzv_min)/m_karta.kol_shifrov)*tarif.hour/60) AS [Sum-money]");
			ADOtemp->SQL->Add("FROM tarif INNER JOIN (operation INNER JOIN ((m_karta INNER JOIN detail ON m_karta.id = detail.shifr_id) ");
			ADOtemp->SQL->Add("INNER JOIN list ON detail.id = list.detail) ON operation.id = list.operation) ON (tarif.razr = list.razr) AND (tarif.kod = operation.tar)");
			ADOtemp->SQL->Add("WHERE m_karta.id = "+AnsiString(id_marsh));
			ADOtemp->SQL->Add(";");
			ADOtemp->Open();

			//go to beg in list of 'chex' for current 'shifr'
			FormMain->ADOsql->First();
			double sum_time_all = ADOtemp->FieldByName("Sum-time")->AsFloat;
			double sum_money_all = ADOtemp->FieldByName("Sum-money")->AsFloat;
			double sum_time, sum_money;
			PrintRes(dpix,dpiy,0,sum_time_all,sum_money_all,group_percent[group-1]);
			//if 'operations' have not only 'chex=17' and others
			if( ! FormMain->ADOsql->IsEmpty() )
			  for( int c = 1; c < len; c++) {
				  //print summary time and money for every 'chex'
				  ADOtemp->Close();
				  ADOtemp->SQL->Strings[4] = "WHERE m_karta.id = " + AnsiString(id_marsh);
				  if(c == 1) {
					ADOtemp->SQL->Strings[5] = " AND list.chex = \'17\';";
				  }
				  else {
					ADOtemp->SQL->Strings[5] = " AND list.chex = \'" + FormMain->ADOsql->FieldByName("chex")->AsString + "\';";
					FormMain->ADOsql->Next();
				  }
				  ADOtemp->Open();
				  sum_time = ADOtemp->FieldByName("Sum-time")->AsFloat;
				  sum_money = ADOtemp->FieldByName("Sum-money")->AsFloat;
				  if(c == 1) {
					PrintRes(dpix,dpiy,c,sum_time,sum_money,group_percent[group-1]);
					//recalc data for field 'ИТОГО'
					PrintRes(dpix,dpiy,-1,sum_time,sum_money,group_percent[group-1]);
					Printer()->Canvas->TextOutW((24.65)*dpix,(8.2+f_offset)*dpiy,prepare((sum_time*group_percent[group-1])+sum_time_all));
					Printer()->Canvas->TextOutW((26.65)*dpix,(8.2+f_offset)*dpiy,prepare((sum_money*group_percent[group-1])+sum_money_all));
					Printer()->Canvas->TextOutW((24.65)*dpix,(8.7+f_offset)*dpiy,prepare(sum_time_all*0.0167));
					Printer()->Canvas->TextOutW((24.65)*dpix,(9.2+f_offset)*dpiy,prepare(((sum_time*group_percent[group-1])+sum_time_all)*0.0167));
				  }
				  else {
					PrintRes(dpix,dpiy,c,sum_time,sum_money,0.0);
                  }
			  }

			Printer()->EndDoc();
		}

	 i++;
	}

	//clear print query
	ListId->Clear();
	ListName->Items->Clear();
	ListId->SaveToFile(ExtractFilePath(Application->ExeName)+"PrintId.txt");
	ListName->Items->SaveToFile(ExtractFilePath(Application->ExeName)+"PrintName.txt");
	this->Close();
 }
}
//---------------------------------------------------------------------------
void TFormPrint::PrintRes(float dpix, float dpiy, int offset, double time, double money, double percent)
{
//print 'time' and 'money' in summary part of "Карта трудоемкости шифра на изделие"
	int k = offset*4;
	if(k < 0) k = 0;
	if(offset > -1)
		Printer()->Canvas->TextOutW((24.65-k)*dpix,(7.2+f_offset)*dpiy,prepare(time));
	if(percent > 0) {
		Printer()->Canvas->TextOutW((24.65-k)*dpix,(7.7+f_offset)*dpiy,prepare(time*percent));
		Printer()->Canvas->TextOutW((24.65-k)*dpix,(8.2+f_offset)*dpiy,prepare(time*(1+percent)));
		Printer()->Canvas->TextOutW((24.65-k)*dpix,(8.7+f_offset)*dpiy,prepare(time*0.0167));
		Printer()->Canvas->TextOutW((24.65-k)*dpix,(9.2+f_offset)*dpiy,prepare((time*(1+percent))*0.0167));
	}

	if(offset > -1)
		Printer()->Canvas->TextOutW((26.65-k)*dpix,(7.2+f_offset)*dpiy,prepare(money));
	if(percent > 0) {
		Printer()->Canvas->TextOutW((26.65-k)*dpix,(7.7+f_offset)*dpiy,prepare(money*percent));
		Printer()->Canvas->TextOutW((26.65-k)*dpix,(8.2+f_offset)*dpiy,prepare(money*(1+percent)));
	}
}
//---------------------------------------------------------------------------
UnicodeString TFormPrint::prepare(double source)
{
//convert double to UnicodeString with special format ( 145.9 to "___145.90" )
	UnicodeString dest;
	dest = FormatFloat("000000.00",source);
	for(int i = 1; i <= 5; i++) {
		if(dest[i] == '0') dest[i] = ' ';
		else break;
	}
	return dest;
}

