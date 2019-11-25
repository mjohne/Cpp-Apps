// FeedDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FmwRSS.h"
#include "FeedDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFeedDlg dialog


CFeedDlg::CFeedDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFeedDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFeedDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFeedDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFeedDlg)
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFeedDlg, CDialog)
	//{{AFX_MSG_MAP(CFeedDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFeedDlg message handlers

BOOL CFeedDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.SetIcon(IDI_ICON_CHECK);
  m_btnOK.DrawAsToolbar(false);
  m_btnOK.DrawFlatFocus(true);
  m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText("");

  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.SetIcon(IDI_ICON_CANCEL);
  m_btnCancel.DrawAsToolbar(false);
  m_btnCancel.DrawFlatFocus(true);
  m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText("");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
