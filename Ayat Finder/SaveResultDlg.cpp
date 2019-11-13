// SaveResultDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ayat Finder.h"
#include "SaveResultDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSaveResultDlg dialog


CSaveResultDlg::CSaveResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSaveResultDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSaveResultDlg)
	m_rbtnFormat = -1;
	//}}AFX_DATA_INIT
}


void CSaveResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSaveResultDlg)
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Radio(pDX, IDC_RADIO_FORMAT_TXT, m_rbtnFormat);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSaveResultDlg, CDialog)
	//{{AFX_MSG_MAP(CSaveResultDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSaveResultDlg message handlers

BOOL CSaveResultDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  //m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.SetIcon(IDI_ICON_CHECK16);
  //m_btnOK.DrawAsToolbar(true);
  m_btnOK.DrawFlatFocus(false);
  //m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText(IDS_BTN_OK);
	
  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  //m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.SetIcon(IDI_ICON_CROSS16);
  //m_btnCancel.DrawAsToolbar(true);
  m_btnCancel.DrawFlatFocus(false);
  //m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText(IDS_BTN_ABORT);
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSaveResultDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
