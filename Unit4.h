//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormPrint : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TCheckBox *CheckComplect;
	TCheckBox *CheckTrud;
	TLabel *Label2;
	TButton *Button1;
	TButton *Button2;
	TListBox *ListName;
	TPrintDialog *PrintDialog1;
	TADOQuery *ADOtemp;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	void PrintRes(float dpix, float dpiy, int offset, double time, double money, double percent);
	UnicodeString prepare(double source);
	__fastcall TFormPrint(TComponent* Owner);
	float f_offset;
	TStringList *ListId;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrint *FormPrint;
//---------------------------------------------------------------------------
#endif
