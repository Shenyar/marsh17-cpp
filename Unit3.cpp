//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAxisGridsEh"
#pragma link "DBGridEh"
#pragma link "DBGridEhGrouping"
#pragma link "DBGridEhToolCtrls"
#pragma link "DynVarsEh"
#pragma link "EhLibVCL"
#pragma link "GridsEh"
#pragma link "ToolCtrlsEh"
#pragma resource "*.dfm"
TFormOp *FormOp;
//---------------------------------------------------------------------------
__fastcall TFormOp::TFormOp(TComponent* Owner)
	: TForm(Owner)
{
	refresh = 0;
//open with height form = height desktop
	int scrw = GetSystemMetrics(SM_CXSCREEN);
	int scrh = GetSystemMetrics(SM_CYSCREEN);
	SetWindowPos(this->Handle,HWND_BOTTOM,(scrw-(this->Width))/2,10,this->Width,scrh-50,SWP_HIDEWINDOW);
	DBGridEh1->Height = this->ClientHeight - 80;
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::ADOoperationAfterOpen(TDataSet *DataSet)
{
//show list of operations
	Memo1->Lines->Clear();
	this->ADOoperation->First();
	while( !ADOoperation->Eof ) {
		Memo1->Lines->Add(ADOoperation->FieldByName("oname")->AsString);
		ADOoperation->Next();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//close form on 'esc'
	if(Key == VK_ESCAPE) {
		/*if((ADOlist->State == dsEdit) || (ADOlist->State == dsInsert)) return;
		else*/ this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::ADOlistAfterInsert(TDataSet *DataSet)
{
//fill new record with standard values
	ADOlist->FieldByName("detail")->AsInteger = FormDetail->ADOdetail->FieldByName("id")->AsInteger;
	ADOlist->FieldByName("chex")->AsString = "17";
	ADOlist->FieldByName("razr")->AsInteger = 0;
	ADOlist->FieldByName("kol")->AsInteger = FormDetail->ADOdetail->FieldByName("kol_na_shifr")->AsInteger;
	ADOlist->FieldByName("num_op")->AsFloat = num_op;
	DBGridEh1->SelectedIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::ADOlistPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action)
{
	Action = daAbort;
	DataSet->Cancel();
	DataSet->Refresh();
	//E->Message = "Поле \'Операция\' не заполнено!\nДля отмены ввода операции нажмите \'Esc\'.";
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::Button2Click(TObject *Sender)
{
//delete operation
	switch(Application->MessageBoxW(L"Удалить выбранную операцию?",L"Подтвердите удаление",MB_YESNO)) {
		case IDYES:
			ADOlist->Delete();
			break;
		case IDNO:
			return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::Button1Click(TObject *Sender)
{
//add operation
	DBGridEh1->SetFocus();
	ADOlist->Insert();
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::ADOlistBeforeInsert(TDataSet *DataSet)
{
//calculate index of operation for right sorting
	if(ADOlist->IsEmpty()) {
		num_op = 1;
		return;
    }
	num_op = ADOlist->FieldByName("num_op")->AsFloat;
	if(ADOlist->Eof) {
		num_op++;
	} else
	if(ADOlist->Bof) {
		num_op = num_op / 2;
		refresh = 1;
	} else {
		ADOlist->Prior();
		float prev = ADOlist->FieldByName("num_op")->AsFloat;
		ADOlist->Next();
		num_op = (num_op + prev) / 2;
		refresh = 1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::ADOlistAfterPost(TDataSet *DataSet)
{
//refresh recordset if it needed
	if(refresh) {
		ADOlist->Close();
		ADOlist->Open();
		refresh = 0;
	}
	FormDetail->isModified = 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::DBGridEh1KeyPress(TObject *Sender, System::WideChar &Key)
{//обработчик KeyPress а не KeyDown, чтобы в поле DBGridEh1->Fields[2] уже записалось значение, иначе оно пустое

//add record to the end
	if(Key == VK_RETURN) {
		//if 'razr'==0 -> go to next record
		if( (DBGridEh1->SelectedIndex == 5) ||
			((DBGridEh1->SelectedIndex == 2) && ( DBGridEh1->Fields[2]->AsInteger == 0) )
		  ) {
			//приходится извращаться т.к. при добавлении в конец AfterInsert срабатывает
			//до отрисовки записи в таблице а не после как обычно( и переход на колонку 2
			//не работает оттуда (
			Key = VK_CONTROL;
			DBGridEh1->SelectedIndex = 0;
			keybd_event(VK_DOWN,0,0,0);
			keybd_event(VK_DOWN,0,KEYEVENTF_KEYUP,0);
		}
		else DBGridEh1->SelectedIndex ++;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::ADOlisttime_minSetText(TField *Sender, const UnicodeString Text)
{
//convert input value to correct format (for 'time_min' and 'pzv_min')
	UnicodeString h,m;
	//find delimiter '-'
	int l = Text.Pos("-");
	//parsing input string
	if( l ) {
		h = Text.SubString(0,l-1);
		m = Text.SubString(l+1,Text.Length()-l);
	}
	else {
		h = Text;
		m = "0";
	}
	//to avoid errors
	if(h == "") h = "0";
	if(m == "") m = "0";
	//result
	Sender->AsFloat = (h.ToDouble()*60) + m.ToDouble();
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::DBGridEh1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//when edit -> on 'left' or 'right' arrow go to next or prev column
	if(DBGridEh1->EditorMode) {
		if(Key == VK_LEFT) DBGridEh1->SelectedIndex --;
		else if(Key == VK_RIGHT) DBGridEh1->SelectedIndex ++;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormOp::DBGridEh1AdvDrawDataCell(TCustomDBGridEh *Sender, TGridCoord &Cell,
		  TGridCoord &AreaCell, TColumnEh *Column, const TRect &ARect, TColCellParamsEh *&Params,
          bool &Processed)
{
//draw time in format 'h-mm'
	if((Cell.X == 4) || (Cell.X == 5)) {
		float time = Column->Field->AsFloat;
		if( !time ) {
			Params->Text = "";//text out
			return;
		}
		float h,m;
		h = (int)(time/60);
		m = time - h*60;
		UnicodeString text = FormatFloat("0",h)+"-";
		if( ((int)m) == m ) text += FormatFloat("00",m);
		else text += FormatFloat("00.00",m);
		Params->Text = text;//text out
	}
}
//---------------------------------------------------------------------------
