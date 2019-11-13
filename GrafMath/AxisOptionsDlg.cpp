// AxisOptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "AxisOptionsDlg.h"
#include <cmath>
#include "HelpDialog.h"
#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAxisOptionsDlg dialog


CAxisOptionsDlg::CAxisOptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAxisOptionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAxisOptionsDlg)
	m_nAxisDivision = 0;
	m_nDecimalPlaces = 0;
	m_bAxisDescription = FALSE;
	m_nHelpAxisWidth = 0;
	//}}AFX_DATA_INIT
}


void CAxisOptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAxisOptionsDlg)
	DDX_Control(pDX, IDC_SPIN_HELPAXISWIDTH, m_sbtnHelpAxisWidth);
	DDX_Control(pDX, IDC_SPIN_DECIMALPARTS, m_sbtnDecimalPlaces);
	DDX_Control(pDX, IDC_SPIN_AXISPARTS, m_sbtnAxisDivision);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnAbbruch);
	DDX_Control(pDX, IDC_BUTTON_DEFAULT, m_btnDefault);
	DDX_Text(pDX, IDC_EDIT_AXISPARTS, m_nAxisDivision);
	DDX_Text(pDX, IDC_EDIT_DECIMALPARTS, m_nDecimalPlaces);
	DDX_Check(pDX, IDC_CHECK_AXISDESCRIPTION, m_bAxisDescription);
	DDX_Text(pDX, IDC_EDIT_HELPAXISWIDTH, m_nHelpAxisWidth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAxisOptionsDlg, CDialog)
	//{{AFX_MSG_MAP(CAxisOptionsDlg)
	ON_EN_CHANGE(IDC_EDIT_AXISPARTS, OnChangeEditAxisparts)
	ON_BN_CLICKED(IDC_BUTTON_DEFAULT, OnButtonDefault)
	ON_EN_SETFOCUS(IDC_EDIT_AXISPARTS, OnSetfocusEditAxisparts)
	ON_EN_SETFOCUS(IDC_EDIT_DECIMALPARTS, OnSetfocusEditDecimalparts)
	ON_EN_SETFOCUS(IDC_EDIT_HELPAXISWIDTH, OnSetfocusEditHelpaxiswidth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAxisOptionsDlg message handlers

BOOL CAxisOptionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

  EnableThemeDialogTexture(GetSafeHwnd());
  
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText("OK!");

  m_btnAbbruch.SetThemeHelper(&m_ThemeHelper);
  m_btnAbbruch.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAbbruch.EnableBalloonTooltip();
  m_btnAbbruch.SetTooltipText("Abbruch!");

  m_btnDefault.SetThemeHelper(&m_ThemeHelper);
  m_btnDefault.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnDefault.EnableBalloonTooltip();
  m_btnDefault.SetTooltipText("Standardwerte setzen");

  return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAxisOptionsDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CAxisOptionsDlg::OnChangeEditAxisparts() 
{
	if (m_nAxisDivision	% 2 == 1) m_nAxisDivision++;
}

void CAxisOptionsDlg::OnButtonDefault() 
{
  m_nAxisDivision = 10;
	m_nDecimalPlaces = 2;
	m_bAxisDescription = true;
	m_nHelpAxisWidth = 4;
  UpdateData(false);
}

void CAxisOptionsDlg::OnSetfocusEditAxisparts() 
{
	m_sbtnHelpAxisWidth.SetRange(1,10);
}

void CAxisOptionsDlg::OnSetfocusEditDecimalparts() 
{
	m_sbtnDecimalPlaces.SetRange(1,5);
}

void CAxisOptionsDlg::OnSetfocusEditHelpaxiswidth() 
{
	m_sbtnAxisDivision.SetRange(1,10);
}
