// AppOptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalBankbook.h"
#include "AppOptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppOptionsDlg dialog


CAppOptionsDlg::CAppOptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAppOptionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAppOptionsDlg)
	m_cbtnAppOptionsAxisDescription = FALSE;
	m_cbtnAppOptionsBGArea = FALSE;
	m_cbtnAppOptionsHelpaxis = FALSE;
	m_cbtnAppOptionsLegend = FALSE;
	m_cbtnAppOptionsMainaxis = FALSE;
	m_cbtnAppOptionsScale100 = FALSE;
	m_cbtnAppOptionsTitle = FALSE;
	m_rbtnSave = -1;
	//}}AFX_DATA_INIT
}


void CAppOptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAppOptionsDlg)
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Check(pDX, IDC_CHECK_OP_AXISDESCRIPT, m_cbtnAppOptionsAxisDescription);
	DDX_Check(pDX, IDC_CHECK_OP_BGAREA, m_cbtnAppOptionsBGArea);
	DDX_Check(pDX, IDC_CHECK_OP_HELPAXIS, m_cbtnAppOptionsHelpaxis);
	DDX_Check(pDX, IDC_CHECK_OP_LEGEND, m_cbtnAppOptionsLegend);
	DDX_Check(pDX, IDC_CHECK_OP_MAINAXIS, m_cbtnAppOptionsMainaxis);
	DDX_Check(pDX, IDC_CHECK_OP_SCALE100, m_cbtnAppOptionsScale100);
	DDX_Check(pDX, IDC_CHECK_OP_TITLE, m_cbtnAppOptionsTitle);
	DDX_Radio(pDX, IDC_RADIO_SAVE_INI, m_rbtnSave);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAppOptionsDlg, CDialog)
	//{{AFX_MSG_MAP(CAppOptionsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppOptionsDlg message handlers

BOOL CAppOptionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.DrawAsToolbar(false);
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText(IDS_USER_ADD);
  m_btnOK.SetIcon(IDI_ICON_CHECK_32);

  m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.DrawAsToolbar(false);
  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText(IDS_CANCEL);
  m_btnCancel.SetIcon(IDI_ICON_DELETE_32);

 	m_cbtnAppOptionsAxisDescription = true;
	m_cbtnAppOptionsBGArea = FALSE;
	m_cbtnAppOptionsHelpaxis = FALSE;
	m_cbtnAppOptionsLegend = FALSE;
	m_cbtnAppOptionsMainaxis = true;
	m_cbtnAppOptionsScale100 = true;
	m_cbtnAppOptionsTitle = true;
  m_rbtnSave = 0;

  UpdateData(false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAppOptionsDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CAppOptionsDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
