// BonfireDlg.cpp : implementation file
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
// CBonfireDlg dialog

CBonfireDlg::CBonfireDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBonfireDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBonfireDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBonfireDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBonfireDlg)
	DDX_Control(pDX, IDC_FIRE, m_wndFire);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBonfireDlg, CDialog)
	//{{AFX_MSG_MAP(CBonfireDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBonfireDlg message handlers

BOOL CBonfireDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_wndFire.InitFire(CFireWnd::red);

	SetTimer(1, 33, NULL);

	ModifyStyleEx(0, WS_EX_TOPMOST, 0);
	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBonfireDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CBonfireDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBonfireDlg::OnTimer(UINT nIDEvent) 
{
	m_wndFire.RenderFlame();
	m_wndFire.PaintFlame();
	
	CDialog::OnTimer(nIDEvent);
}

void CBonfireDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	SendMessage(WM_SYSCOMMAND, 0xf012, 0);
	
	CDialog::OnLButtonDown(nFlags, point);
}

int CBonfireDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	DragAcceptFiles();

	if (!m_Drop.Register(this)) {
		char szMessage[128];
		sprintf(szMessage, "Error %ld", GetLastError());
		MessageBox(szMessage, "OK", MB_OK);
	}

	return 0;
}
