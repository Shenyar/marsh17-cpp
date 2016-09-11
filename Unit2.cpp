//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBCtrlsEh"
#pragma link "DBAxisGridsEh"
#pragma link "DBGridEh"
#pragma link "DBGridEhGrouping"
#pragma link "DBGridEhToolCtrls"
#pragma link "DynVarsEh"
#pragma link "EhLibVCL"
#pragma link "GridsEh"
#pragma link "ToolCtrlsEh"
#pragma resource "*.dfm"
TFormDetail *FormDetail;
//---------------------------------------------------------------------------
__fastcall TFormDetail::TFormDetail(TComponent* Owner)
	: TForm(Owner)
{
	refresh=0;
	this->Resizing(wsMaximized);
	ADOmaterial->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::e_shifrKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//on enter click - go to the next control
  if(Key == 13) {
	if(Sender->ClassName() == "TDBEditEh") {
		UnicodeString name = static_cast<TDBEditEh*>(Sender)->Name;
		if(name == "e_shifr") {
			e_marsh_kart->SetFocus();
		} else if(name == "e_marsh_kart") {
			e_num_zak->SetFocus();
		} else if(name == "e_num_zak") {
			e_name->SetFocus();
		} else if(name == "e_name") {
			e_zakaz->SetFocus();
		} else if(name == "e_zakaz") {
			e_group->SetFocus();
			e_group->DropDown();
			if(e_group->ItemIndex < 0) e_group->ItemIndex = 0;
		} else if(name == "e_kol_shifr") {
			e_kol_tech->SetFocus();
		} else if(name == "e_kol_tech") {
			e_metal->SetFocus();
			e_metal->DropDown();
			if(e_metal->ItemIndex < 0) e_metal->ItemIndex = 0;
		}
	} else {
		UnicodeString name = static_cast<TDBComboBoxEh*>(Sender)->Name;
		if(name == "e_group") {
			e_remont->SetFocus();
			e_remont->DropDown();
			if(e_remont->ItemIndex < 0) e_remont->ItemIndex = 0;
		} else if(name == "e_remont") {
			e_kol_shifr->SetFocus();
		} else if(name == "e_metal") {
			DBGridDetail->SetFocus();
		}
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::ADOdetailAfterScroll(TDataSet *DataSet)
{
//open 'zagotov' for the selected 'detail'
	ADOzag->Close();
	if( DataSet->FieldByName("id")->AsString != "" ) {
		ADOzag->SQL->Strings[1] = "where zagotov.detail = " + DataSet->FieldByName("id")->AsString + ";";
		ADOzag->Open();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::FormClose(TObject *Sender, TCloseAction &Action)
{
//go to the 'shifr`s' list
	//if 'shifr' modified -> post it (if user want it)
	if((FormMain->DataSource1->DataSet->State == dsEdit) ||
		(FormMain->DataSource1->DataSet->State == dsInsert)) {
			switch(Application->MessageBoxW(L"Сохранить изменения в шифре?",L"",MB_YESNOCANCEL)) {
				case IDYES:
					if(FormMain->ADOQuery1->FieldByName("date")->IsNull) {
						FormMain->ADOQuery1->FieldByName("date")->AsDateTime = Date();
					}
					FormMain->ADOQuery1->Post();
					break;

				case IDNO:
					FormMain->ADOQuery1->Cancel();
					break;

				case IDCANCEL:
					Action = caNone;
					return;
			}
	}

// this 'shifr' will be writed in other databases ( not my databases) )
if( this->isModified ) {
	//write 'shifr' to the list
	ADOsqlexec->Close();
	ADOsqlexec->SQL->Clear();
	ADOsqlexec->SQL->Add("INSERT INTO to_old_dbf (shifr_id)");
	ADOsqlexec->SQL->Add(" VALUES ("+FormMain->ADOQuery1->FieldByName("id")->AsString+");");
	ADOsqlexec->ExecSQL();
}

	/*int recNo = FormMain->ADOQuery1->RecNo;
	if(recNo == FormMain->ADOQuery1->RecordCount) recNo = 1;
	FormMain->ADOQuery1->Close();
	FormMain->ADOQuery1->Open();
	FormMain->ADOQuery1->RecNo = recNo;*/
	FormMain->Show();
	this->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::b_add_detClick(TObject *Sender)
{
//add 'detail'
	ADOdetail->Insert();
	DBGridDetail->SetFocus();
	DBGridDetail->SelectedIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::b_del_detClick(TObject *Sender)
{
//delete 'detail'
	switch(Application->MessageBoxW(L"Удалить выбранную деталь?",L"Подтвердите удаление",MB_YESNO)) {
		case IDYES:
			ADOdetail->Delete();
			break;
		case IDNO:
			return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::b_add_zagClick(TObject *Sender)
{
//add 'zagotov'
	ADOzag->Insert();
	DBGridZag->SetFocus();
	DBGridZag->SelectedIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::b_del_zagClick(TObject *Sender)
{
//delete 'zagotov'
	switch(Application->MessageBoxW(L"Удалить выбранную заготовку?",L"Подтвердите удаление",MB_YESNO)) {
		case IDYES:
			ADOzag->Delete();
			break;
		case IDNO:
			return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::DBGridDetailKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//go to the 'zagotov' table after "enter" on last column "detail"
  if(Key == 13) {
	if(DBGridDetail->SelectedIndex < 2) {
		DBGridDetail->SelectedIndex ++;
	} else if(DBGridDetail->SelectedIndex == 2) {
		if((DataSourceDetail->DataSet->State == dsEdit) ||
			(DataSourceDetail->DataSet->State == dsInsert)) {
				ADOdetail->Post();
		}
		ADOzag->Close();
		ADOzag->SQL->Strings[1] = "where zagotov.detail = " + ADOdetail->FieldByName("id")->AsString + ";";
		ADOzag->Open();
		DBGridZag->SetFocus();
		DBGridZag->SelectedIndex = 1;
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::ADOdetailAfterInsert(TDataSet *DataSet)
{
//connect 'detail' to the selected 'shifr'
	ADOdetail->FieldByName("shifr_id")->AsInteger = FormMain->ADOQuery1->FieldByName("id")->AsInteger;
}
//---------------------------------------------------------------------------

void __fastcall TFormDetail::ADOzagAfterInsert(TDataSet *DataSet)
{
//connect 'zagotov' to the selected 'detail'
	ADOzag->FieldByName("detail")->AsInteger = ADOdetail->FieldByName("id")->AsInteger;
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::ADOdetailPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
{
	Action = daAbort;
	DataSet->Cancel();
	//E->Message = "Кол-во деталей не заполнено!\nДля отмены ввода детали нажмите \'Esc\'.";
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::DBGridDetailEnter(TObject *Sender)
{
//if 'shifr' modified -> post it
	if((FormMain->DataSource1->DataSet->State == dsInsert)) {
			//if in the database present the same 'shifr' -> open it
			ADOsqlexec->Close();
			ADOsqlexec->SQL->Clear();
			ADOsqlexec->SQL->Add("select * from m_karta where (shifr = ");
			ADOsqlexec->SQL->Add("\'" + e_shifr->Text + "\') AND (num_kart = ");
			ADOsqlexec->SQL->Add("\'" + e_marsh_kart->Text + "\') AND (num_zakaz = ");
			ADOsqlexec->SQL->Add("\'" + e_num_zak->Text + "\') ;");
			ADOsqlexec->Open();
			if(ADOsqlexec->IsEmpty()) {
				FormMain->ADOQuery1->FieldByName("date")->AsDateTime = Date();
				FormMain->ADOQuery1->Post();
				ADOdetail->Close();
				ADOdetail->SQL->Strings[2] = "shifr_id = " + FormMain->ADOQuery1->FieldByName("id")->AsString;
				ADOdetail->Open();
			} else {
				FormMain->ADOQuery1->Cancel();
				//looking for 'shifr'
				FormMain->ADOQuery1->Close();
				FormMain->ADOQuery1->SQL->Strings[1] = "where id = " + ADOsqlexec->FieldByName("id")->AsString + " ";
				FormMain->ADOQuery1->Open();
				FormMain->Edit1->Text = e_shifr->Text;
				ADOdetail->Close();
				ADOdetail->SQL->Strings[2] = "shifr_id = " + ADOsqlexec->FieldByName("id")->AsString;
				ADOdetail->Open();
				ShowMessage("Такой шифр уже существует в Базе Данных.");
			}
	}
	else if(FormMain->DataSource1->DataSet->State == dsEdit) {
		FormMain->ADOQuery1->Post();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::b_info_detClick(TObject *Sender)
{
//open 'operations' of selected 'detail'
	if((ADOzag->State == dsEdit) || (ADOzag->State == dsInsert)) ADOzag->Cancel();
	FormOp->ADOoperation->Close();
	FormOp->ADOoperation->SQL->Strings[1] = "WHERE operation.group = " + FormMain->ADOQuery1->FieldByName("igroup")->AsString;
	FormOp->ADOoperation->Open();
	FormOp->ADOlist->Close();
	FormOp->ADOlist->SQL->Strings[1] = "WHERE list.detail = " + ADOdetail->FieldByName("id")->AsString;
	FormOp->ADOlist->Open();
	if(FormOp->ADOlist->IsEmpty()) FormOp->ADOlist->Insert();
	FormOp->Label2->Caption = "Деталь: " + ADOdetail->FieldByName("dname")->AsString;
	FormOp->ShowModal();
	//after close 'operations' -> go to next 'detail'
	DBGridDetail->SetFocus();
	DBGridDetail->SelectedIndex = 0;
	keybd_event(VK_DOWN,0,0,0);
	keybd_event(VK_DOWN,0,KEYEVENTF_KEYUP,0);
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::DBGridDetailDblClick(TObject *Sender)
{
//open 'operations' of selected 'detail'
	this->b_info_detClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//open 'operations' of selected 'detail' on pressed F2
	if(VK_F2 == Key) this->b_info_detClick(Sender);
//open 'dop_osnastka' of selected 'shifr' on pressed F4
	if(VK_F4 == Key) this->b_dop_osnClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::ADOzagPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
{
	Action = daAbort;
	DataSet->Cancel();
	//E->Message = "Поле \'Материал\' не заполнено!\nДля отмены ввода заготовки нажмите \'Esc\'.";
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::ADOzagBeforePost(TDataSet *DataSet)
{
//calculate weight and index of 'zagotov'
	ADOzagpriznak->Value = "О";
	if((ADOzagmaterial->AsString != "") && (ADOzagrazmer->AsString != "")) {

		ADOsqlexec->Close();
		ADOsqlexec->SQL->Clear();
		ADOsqlexec->SQL->Add("select material.ves from material where material.id = "+ADOzagmaterial->AsString+";");
		ADOsqlexec->Open();

		double res;
		try{
			//парсинг строки размера
			AnsiString kodzag="",work = ADOzagrazmer->AsString;
			//размер содержит макс 5 элементов
			float r[5]={1,1,1,0,1},gab[5]={1,1,1,0,1};
			if( ((work[1] >= '0') && (work[1] <= '9')) || ((work[1] == ']') || (work[1] == 'д') || (work[1] == 'Д') || (work[1] == 'S')))
			{
				AnsiString sub;
				int prev=1,n=work.Length(),idx=0;
				//проход по строке в поиске "*"
				for(int i=1;i<=n;i++) {
					if((work[i]=='*') || (i==n)) {
						if(i==n) i++;
						//выбор подстроки с 1 элементом (д213 или S12)
						sub = work.SubString(prev,i-prev);
						kodzag += AnsiString(sub[1]);
						//первоначальный размер
						if((sub[1]>='0') && (sub[1]<='9')) gab[idx]=sub.ToDouble();
						else {gab[idx]=sub.SubString(2,sub.Length()).ToDouble();}
						//результативный размер
						if(sub[1]==']') sub[1]=' ';
						if(sub[1]=='S') {
							sub[1]=' ';
							r[idx]=sub.ToDouble()*sub.ToDouble()*2.59807;
						} else if((sub[1]=='д') || (sub[1]=='Д')) {
							sub[1]=' ';
							r[idx]=(sub.ToDouble()/2)*(sub.ToDouble()/2)*3.14159;
							if(idx==1) r[idx]= -r[idx];
						} else {r[idx]=sub.ToDouble();}
						idx++;
						prev=i+1;
					}
				}
				//расчет итогового объема детали
				if(r[1]>0) res = r[0]*r[1]*r[2];
				else res = r[0]*r[2] + r[1]*r[2];
				if(r[4]==1) res -= r[3]*r[4];
				else res -= r[3]*r[2];
				//расчет веса
				double ves = ADOsqlexec->FieldByName("ves")->AsFloat;
				res = res * (ves/1000000.0);
			}
			//определение кода заготовки
			AnsiString kz="00";
			int kzlen = kodzag.Length();
			switch(work[1]) { //страшный код, но с такими условиями иначе никак(
				case 'П': kz="09"; break; //поковка
				case 'Л': kz="10"; break; //литье
				case 'С': kz="20"; break; //сварка
				case 'Т': kz="11"; break; //точное литье
				case 'Ш': kz="21"; break; //штамповка
				case 'N': kz="16"; break; //швеллер
				case 'S': kz="12"; break; //шестигранник
				case '<': kz="14"; break; //уголок
				case ']': kz="08"; break; //резка на ножницах
			}
			if(kz=="00") {
				if(kzlen == 2) {
				//если из 2-х элементов размер состоит, то диск(диаметр>250 или длина<100) или прут
					if(((kodzag[1]=='д') || (kodzag[1]=='Д')) && ((kodzag[2]>='0') && (kodzag[2]<='9'))) {
						if((gab[0]>250) || (gab[1]<100)) kz="02";
						else kz="01";
					} else throw 1;
				} else
				if(kzlen == 3) {
				//если из 3-х элементов размер состоит, то труба(с двумя диаметрами) или плита (только цифры)
					if(((kodzag[1]=='д') || (kodzag[1]=='Д')) && ((kodzag[2]=='д') || (kodzag[2]=='Д')) && ((kodzag[3]>='0') && (kodzag[3]<='9'))) {
						if((gab[2]<100)) kz="03";
						else kz="13";
					} else
					if(((kodzag[1]>='0') && (kodzag[1]<='9')) && ((kodzag[2]>='0') && (kodzag[2]<='9')) && ((kodzag[3]>='0') && (kodzag[3]<='9'))) {
						if((gab[0]>15) && (gab[1]>15) && (gab[2]>15)) kz="04";
						else kz="08";
					} else throw 1;
				} else
				if(kzlen > 3) {
				//если из 4;5-х элементов размер состоит, то плита с вырезом (круг или квадрат)
					if((kodzag[4]=='д') || (kodzag[4]=='Д')) {
						kodzag[4]='1';
						kodzag.ToInt();
						kz="23";
					} else {kodzag.ToInt(); kz="22";}
				} else throw 1;
			}
			//ввод результатов в БД
			ADOzagmassa->AsFloat = res/1000.0;
			ADOzagkodzag->AsString = kz;
		}
		catch(...) {
			ADOzagrazmer->AsString = "";
			ShowMessage("Неверно введен размер.");
			refresh=1;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::DBGridZagKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
//auto complete special symbols in the 'razmer'
	if( ((int)Key) < 65 ) return; //system keys are not interesting
	if((DBGridZag->SelectedIndex == 2) && (!DBGridZag->InplaceEditor->Text.IsEmpty())) {
		if((DBGridZag->InplaceEditor->Text == "п") || (DBGridZag->InplaceEditor->Text == "П")) {
				DBGridZag->InplaceEditor->Text = "Поковка ";
		}
		else if((DBGridZag->InplaceEditor->Text == "л") || (DBGridZag->InplaceEditor->Text == "Л")) {
				DBGridZag->InplaceEditor->Text = "Литье ";
		}
		else if((DBGridZag->InplaceEditor->Text == "с") || (DBGridZag->InplaceEditor->Text == "С")) {
				DBGridZag->InplaceEditor->Text = "Свар.Узел ";
		}
		else if((DBGridZag->InplaceEditor->Text == "Nо") || (DBGridZag->InplaceEditor->Text == "NО")) {
				DBGridZag->InplaceEditor->Text = "Точн.Литье ";
		}
		else if((DBGridZag->InplaceEditor->Text == "ш") || (DBGridZag->InplaceEditor->Text == "Ш")) {
				DBGridZag->InplaceEditor->Text = "Штамповка ";
		}
		else if((DBGridZag->InplaceEditor->Text == "ы") || (DBGridZag->InplaceEditor->Text == "Ы")) {
				DBGridZag->InplaceEditor->Text = "S";
		}
		else if((DBGridZag->InplaceEditor->Text == "т") || (DBGridZag->InplaceEditor->Text == "Т")) {
				DBGridZag->InplaceEditor->Text = "N";
		}
		else if((DBGridZag->InplaceEditor->Text == "ъ") || (DBGridZag->InplaceEditor->Text == "Ъ")) {
				DBGridZag->InplaceEditor->Text = "]";
		}
		else if((DBGridZag->InplaceEditor->Text == "б") || (DBGridZag->InplaceEditor->Text == "Б")) {
				DBGridZag->InplaceEditor->Text = "<";
		}

		//move cursor to the end
		DBGridZag->InplaceEditor->SelStart = DBGridZag->InplaceEditor->Text.Length();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::ADOzagAfterPost(TDataSet *DataSet)
{
	if(refresh) {DataSet->Refresh(); refresh=0;}
	FormDetail->isModified = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::ADOdetailAfterPost(TDataSet *DataSet)
{
	FormDetail->isModified = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::ADOdetailBeforePost(TDataSet *DataSet)
{
//if 'detail.kol' is modified -> recalc 'operations.kol'
  if(!ADOdetail->FieldByName("kol_na_shifr")->OldValue.IsNull()) {
	ADOsqlexec->Close();
	ADOsqlexec->SQL->Clear();
	ADOsqlexec->SQL->Add("UPDATE list SET list.kol = "+ADOdetail->FieldByName("kol_na_shifr")->NewValue.operator AnsiString());
	ADOsqlexec->SQL->Add(" WHERE (list.detail = "+ADOdetail->FieldByName("id")->AsString+")");
	ADOsqlexec->SQL->Add(" AND (list.kol = "+ADOdetail->FieldByName("kol_na_shifr")->OldValue.operator AnsiString()+");");
	ADOsqlexec->ExecSQL();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::b_dop_osnClick(TObject *Sender)
{
//open 'dop_osnastka' for the selected 'shifr'
	FormDopOsn->ADOosn->Close();
	FormDopOsn->ADOosn->SQL->Strings[2] = FormMain->ADOQuery1->FieldByName("id")->AsString+";";
	FormDopOsn->ADOosn->Open();
	FormDopOsn->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormDetail::DBGridZagKeyPress(TObject *Sender, System::WideChar &Key)
{
//add record to the end
	if(Key == VK_RETURN) {
		if( DBGridZag->SelectedIndex == 3 ) {
			Key = VK_CONTROL;
			DBGridZag->SelectedIndex = 1;
			keybd_event(VK_DOWN,0,0,0);
			keybd_event(VK_DOWN,0,KEYEVENTF_KEYUP,0);
		}
		else DBGridZag->SelectedIndex ++;
	}
}
//---------------------------------------------------------------------------
