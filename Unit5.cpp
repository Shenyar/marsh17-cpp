//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
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
TFormDopOsn *FormDopOsn;
//---------------------------------------------------------------------------
__fastcall TFormDopOsn::TFormDopOsn(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDopOsn::b_addClick(TObject *Sender)
{
//add record
	ADOosn->Insert();
}
//---------------------------------------------------------------------------
void __fastcall TFormDopOsn::b_delClick(TObject *Sender)
{
//del record
	if(IDYES == Application->MessageBoxW(L"Удалить выбранную запись?",L"Удаление",MB_YESNOCANCEL)) {
		ADOosn->Delete();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDopOsn::ADOosnBeforePost(TDataSet *DataSet)
{
//connect records with selected 'shifr'
	ADOosn->FieldByName("shifr_id")->AsInteger = FormMain->ADOQuery1->FieldByName("id")->AsInteger;
}
//---------------------------------------------------------------------------
void __fastcall TFormDopOsn::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
//close form on 'esc'
	if(Key == VK_ESCAPE) {
		this->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormDopOsn::ADOosnPostError(TDataSet *DataSet, EDatabaseError *E,
          TDataAction &Action)
{
	Action = daAbort;
	DataSet->Cancel();
}
//---------------------------------------------------------------------------

