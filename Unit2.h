//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "DBCtrlsEh.hpp"
#include <Vcl.Mask.hpp>
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
class TFormDetail : public TForm
{
__published:	// IDE-managed Components
	TDBEditEh *e_shifr;
	TDBEditEh *e_marsh_kart;
	TDBEditEh *e_num_zak;
	TDBEditEh *e_name;
	TDBEditEh *e_zakaz;
	TDBComboBoxEh *e_group;
	TDBComboBoxEh *e_remont;
	TDBEditEh *e_kol_shifr;
	TDBEditEh *e_kol_tech;
	TDBComboBoxEh *e_metal;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TShape *Shape1;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TDBGridEh *DBGridDetail;
	TDBGridEh *DBGridZag;
	TButton *b_add_det;
	TButton *b_del_det;
	TButton *b_info_det;
	TButton *b_add_zag;
	TButton *b_del_zag;
	TADOQuery *ADOdetail;
	TADOQuery *ADOzag;
	TDataSource *DataSourceDetail;
	TDataSource *DataSourceZag;
	TShape *Shape2;
	TADOQuery *ADOmaterial;
	TDataSource *DataSourceMaterial;
	TStringField *ADOzaglookup;
	TAutoIncField *ADOzagid;
	TIntegerField *ADOzagdetail;
	TIntegerField *ADOzagmaterial;
	TFloatField *ADOzagmassa;
	TWideStringField *ADOzagrazmer;
	TWideStringField *ADOzagpriznak;
	TIntegerField *ADOzagkol_zag;
	TWideStringField *ADOzagkodzag;
	TADOQuery *ADOsqlexec;
	TADOQuery *ADOdbf;
	TLabel *Label14;
	TButton *b_dop_osn;
	void __fastcall e_shifrKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ADOdetailAfterScroll(TDataSet *DataSet);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall b_add_detClick(TObject *Sender);
	void __fastcall b_del_detClick(TObject *Sender);
	void __fastcall b_add_zagClick(TObject *Sender);
	void __fastcall b_del_zagClick(TObject *Sender);
	void __fastcall DBGridDetailKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ADOdetailAfterInsert(TDataSet *DataSet);
	void __fastcall ADOzagAfterInsert(TDataSet *DataSet);
	void __fastcall ADOdetailPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);
	void __fastcall DBGridDetailEnter(TObject *Sender);
	void __fastcall b_info_detClick(TObject *Sender);
	void __fastcall DBGridDetailDblClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ADOzagPostError(TDataSet *DataSet, EDatabaseError *E, TDataAction &Action);
	void __fastcall ADOzagBeforePost(TDataSet *DataSet);
	void __fastcall DBGridZagKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ADOzagAfterPost(TDataSet *DataSet);
	void __fastcall ADOdetailAfterPost(TDataSet *DataSet);
	void __fastcall ADOdetailBeforePost(TDataSet *DataSet);
	void __fastcall b_dop_osnClick(TObject *Sender);
	void __fastcall DBGridZagKeyPress(TObject *Sender, System::WideChar &Key);





private:	// User declarations
public:		// User declarations
	__fastcall TFormDetail(TComponent* Owner);
	int refresh,isModified;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDetail *FormDetail;
//---------------------------------------------------------------------------
#endif
