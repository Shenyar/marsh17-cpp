//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit4.cpp", FormPrint);
USEFORM("Unit3.cpp", FormOp);
USEFORM("UnitClose.cpp", FormPClose);
USEFORM("Unit5.cpp", FormDopOsn);
USEFORM("Unit2.cpp", FormDetail);
USEFORM("Unit1.cpp", FormMain);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		//Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TFormDetail), &FormDetail);
		Application->CreateForm(__classid(TFormOp), &FormOp);
		Application->CreateForm(__classid(TFormPrint), &FormPrint);
		Application->CreateForm(__classid(TFormDopOsn), &FormDopOsn);
		Application->CreateForm(__classid(TFormPClose), &FormPClose);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
