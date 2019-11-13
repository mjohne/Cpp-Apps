// InputFunctionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "InputFunctionDlg.h"
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
// CInputFunctionDlg dialog


CInputFunctionDlg::CInputFunctionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInputFunctionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInputFunctionDlg)
	m_fKoeffizientA = 0.0f;
	m_fKoeffizientB = 0.0f;
	m_fKoeffizientC = 0.0f;
	m_fKoeffizientD = 0.0f;
	//}}AFX_DATA_INIT
}


void CInputFunctionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputFunctionDlg)
	DDX_Control(pDX, IDC_SPIN_COEFFICIENT_D, m_sbtnKoeffizientD);
	DDX_Control(pDX, IDC_SPIN_COEFFICIENT_C, m_sbtnKoeffizientC);
	DDX_Control(pDX, IDC_SPIN_COEFFICIENT_B, m_sbtnKoeffizientB);
	DDX_Control(pDX, IDC_SPIN_COEFFICIENT_A, m_sbtnKoeffizientA);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnAbbruch);
	DDX_Text(pDX, IDC_EDIT_COEFFICIENT_A, m_fKoeffizientA);
	DDX_Text(pDX, IDC_EDIT_COEFFICIENT_B, m_fKoeffizientB);
	DDX_Text(pDX, IDC_EDIT_COEFFICIENT_C, m_fKoeffizientC);
	DDX_Text(pDX, IDC_EDIT_COEFFICIENT_D, m_fKoeffizientD);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputFunctionDlg, CDialog)
	//{{AFX_MSG_MAP(CInputFunctionDlg)
	ON_EN_SETFOCUS(IDC_EDIT_COEFFICIENT_A, OnSetfocusEditCoefficientA)
	ON_EN_SETFOCUS(IDC_EDIT_COEFFICIENT_B, OnSetfocusEditCoefficientB)
	ON_EN_SETFOCUS(IDC_EDIT_COEFFICIENT_C, OnSetfocusEditCoefficientC)
	ON_EN_SETFOCUS(IDC_EDIT_COEFFICIENT_D, OnSetfocusEditCoefficientD)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputFunctionDlg message handlers

BOOL CInputFunctionDlg::OnInitDialog() 
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
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInputFunctionDlg::OnSetfocusEditCoefficientA() 
{
  m_sbtnKoeffizientA.SetRange(-100,100);
}

void CInputFunctionDlg::OnSetfocusEditCoefficientB() 
{
  m_sbtnKoeffizientB.SetRange(-100,100);
}

void CInputFunctionDlg::OnSetfocusEditCoefficientC() 
{
  m_sbtnKoeffizientC.SetRange(-100,100);
}

void CInputFunctionDlg::OnSetfocusEditCoefficientD() 
{
  m_sbtnKoeffizientD.SetRange(-100,100);
}

void CInputFunctionDlg::OnOK() 
{
	CDialog::OnOK();
}
