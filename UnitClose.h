//---------------------------------------------------------------------------

#ifndef UnitCloseH
#define UnitCloseH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormPClose : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *ADOconn_dbf;
	TADOQuery *ADOsqlexec;
	TADOQuery *ADOdbf;
	TLabel *Label1;
	TLabel *Label2;
	TProgressBar *ProgressBar1;
	TTimer *Timer1;
	TADOQuery *ADOmdb;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ADOdbfPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);

private:	// User declarations
public:		// User declarations
	__fastcall TFormPClose(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPClose *FormPClose;
//---------------------------------------------------------------------------
#endif
