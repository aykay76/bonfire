// Bonfire.h : main header file for the BONFIRE application
//

#if !defined(AFX_BONFIRE_H__4F3CDD66_FB1C_11D1_9DD1_0020182B6AB8__INCLUDED_)
#define AFX_BONFIRE_H__4F3CDD66_FB1C_11D1_9DD1_0020182B6AB8__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBonfireApp:
// See Bonfire.cpp for the implementation of this class
//

class CBonfireApp : public CWinApp
{
public:
	CBonfireApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBonfireApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBonfireApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BONFIRE_H__4F3CDD66_FB1C_11D1_9DD1_0020182B6AB8__INCLUDED_)
