//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "DataDriverEh.hpp"
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "EhLibVCL.hpp"
#include "GridsEh.hpp"
#include "MemTableDataEh.hpp"
#include "MemTableEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDBGridEh *DBGridEh1;
	TDataSource *DataSource1;
	TToolBar *ToolBar1;
	TLabel *Label1;
	TEdit *Edit1;
	TBitBtn *b_find;
	TBitBtn *b_cancel_find;
	TButton *b_add;
	TButton *b_copy;
	TButton *b_edit;
	TButton *b_add_print;
	TButton *b_print;
	TButton *b_del;
	TADOQuery *ADOsql;
	TADOCommand *ADOexecsql;
	TAutoIncField *ADOQuery1id;
	TWideStringField *ADOQuery1shifr;
	TWideStringField *ADOQuery1name;
	TWideStringField *ADOQuery1zakazchik;
	TIntegerField *ADOQuery1igroup;
	TWordField *ADOQuery1remont;
	TIntegerField *ADOQuery1kol_shifrov;
	TIntegerField *ADOQuery1kol_tech;
	TWordField *ADOQuery1metal;
	TDateTimeField *ADOQuery1date;
	TWideStringField *ADOQuery1num_kart;
	TWideStringField *ADOQuery1num_zakaz;
	void __fastcall b_findClick(TObject *Sender);
	void __fastcall b_cancel_findClick(TObject *Sender);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall b_addClick(TObject *Sender);
	void __fastcall b_editClick(TObject *Sender);
	void __fastcall DBGridEh1DblClick(TObject *Sender);
	void __fastcall ADOQuery1PostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);
	void __fastcall b_delClick(TObject *Sender);
	void __fastcall b_copyClick(TObject *Sender);
	void __fastcall b_printClick(TObject *Sender);
	void __fastcall b_add_printClick(TObject *Sender);
	void __fastcall ADOQuery1AfterPost(TDataSet *DataSet);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
	void updateProgram(UnicodeString *newVer);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
