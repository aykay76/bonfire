// Bonfire.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Bonfire.h"
#include "BonfireDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBonfireApp

BEGIN_MESSAGE_MAP(CBonfireApp, CWinApp)
	//{{AFX_MSG_MAP(CBonfireApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBonfireApp construction

CBonfireApp::CBonfireApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBonfireApp object

CBonfireApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBonfireApp initialization

BOOL CBonfireApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	AfxOleInit();
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CBonfireDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
