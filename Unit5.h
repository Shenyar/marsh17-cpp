//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
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
//---------------------------------------------------------------------------
class TFormDopOsn : public TForm
{
__published:	// IDE-managed Components
	TADOQuery *ADOosn;
	TDataSource *DataOsn;
	TDBGridEh *DBGridEh1;
	TButton *b_add;
	TButton *b_del;
	void __fastcall b_addClick(TObject *Sender);
	void __fastcall b_delClick(TObject *Sender);
	void __fastcall ADOosnBeforePost(TDataSet *DataSet);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ADOosnPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);

private:	// User declarations
public:		// User declarations
	__fastcall TFormDopOsn(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDopOsn *FormDopOsn;
//---------------------------------------------------------------------------
#endif
