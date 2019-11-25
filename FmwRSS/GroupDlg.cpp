// GroupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FmwRSS.h"
#include "GroupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGroupDlg dialog


CGroupDlg::CGroupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGroupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGroupDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGroupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGroupDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDOK, m_btnOK);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGroupDlg, CDialog)
	//{{AFX_MSG_MAP(CGroupDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGroupDlg message handlers

BOOL CGroupDlg::OnInitDialog() 
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
