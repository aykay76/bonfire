// BonfireDlg.h : header file
//

#if !defined(AFX_BONFIREDLG_H__4F3CDD68_FB1C_11D1_9DD1_0020182B6AB8__INCLUDED_)
#define AFX_BONFIREDLG_H__4F3CDD68_FB1C_11D1_9DD1_0020182B6AB8__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CBonfireDlg dialog

class CBonfireDlg : public CDialog
{
// Construction
public:
	CBonfireDlg(CWnd* pParent = NULL);	// standard constructor

	CDropper m_Drop;
// Dialog Data
	//{{AFX_DATA(CBonfireDlg)
	enum { IDD = IDD_BONFIRE_DIALOG };
	CFireWnd	m_wndFire;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBonfireDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBonfireDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BONFIREDLG_H__4F3CDD68_FB1C_11D1_9DD1_0020182B6AB8__INCLUDED_)
