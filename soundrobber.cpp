// soundrobber.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "scope.h"
#include "waveplay.h"
#include "memoryfile.h"
#include "soundrobber.h"
#include "soundrobberDlg.h"
#include "about.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSoundrobberApp

BEGIN_MESSAGE_MAP(CSoundrobberApp, CWinApp)
	//{{AFX_MSG_MAP(CSoundrobberApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoundrobberApp construction

CSoundrobberApp::CSoundrobberApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSoundrobberApp object

CSoundrobberApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSoundrobberApp initialization

BOOL CSoundrobberApp::InitInstance()
{
/*
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
*/
	// AboutBox anzeigen, aber Modeless!!!!
	{
		CAboutDlg cadlg;
		cadlg.Create (IDD_ABOUTBOX);
		Sleep (2000);
		cadlg.SendMessage (WM_CLOSE, 0, 0L);
		cadlg.DestroyWindow();
	}
	// HauptDialogBox starten
	CSoundrobberDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	return FALSE;
}



