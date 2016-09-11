//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "DBAxisGridsEh.hpp"
#include "DBGridEh.hpp"
#include "DBGridEhGrouping.hpp"
#include "DBGridEhToolCtrls.hpp"
#include "DynVarsEh.hpp"
#include "EhLibVCL.hpp"
#include "GridsEh.hpp"
#include "ToolCtrlsEh.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormOp : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TShape *Shape1;
	TADOQuery *ADOlist;
	TADOQuery *ADOoperation;
	TDataSource *DataSourceList;
	TDBGridEh *DBGridEh1;
	TButton *Button1;
	TButton *Button2;
	TDataSource *DataSourceOp;
	TMemo *Memo1;
	TAutoIncField *ADOlistid;
	TIntegerField *ADOlistdetail;
	TIntegerField *ADOlistoperation;
	TFloatField *ADOlisttime_min;
	TIntegerField *ADOlistrazr;
	TFloatField *ADOlistpzv_min;
	TIntegerField *ADOlistkol;
	TFloatField *ADOlistnum_op;
	TWideStringField *ADOlistchex;
	TStringField *ADOlistopname;
	void __fastcall ADOoperationAfterOpen(TDataSet *DataSet);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ADOlistAfterInsert(TDataSet *DataSet);
	void __fastcall ADOlistPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ADOlistBeforeInsert(TDataSet *DataSet);
	void __fastcall ADOlistAfterPost(TDataSet *DataSet);
	void __fastcall DBGridEh1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ADOlisttime_minSetText(TField *Sender, const UnicodeString Text);
	void __fastcall DBGridEh1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DBGridEh1AdvDrawDataCell(TCustomDBGridEh *Sender, TGridCoord &Cell,
          TGridCoord &AreaCell, TColumnEh *Column, const TRect &ARect, TColCellParamsEh *&Params,
          bool &Processed);





private:	// User declarations
public:		// User declarations
	__fastcall TFormOp(TComponent* Owner);
	float num_op;
	int refresh;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOp *FormOp;
//---------------------------------------------------------------------------
#endif
