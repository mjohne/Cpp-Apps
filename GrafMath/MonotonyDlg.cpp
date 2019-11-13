// MonotonyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "MonotonyDlg.h"
#include <cmath>
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonotonyDlg dialog


CMonotonyDlg::CMonotonyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMonotonyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMonotonyDlg)
	m_fX = 0.0f;
	m_strMonotony = _T("");
	//}}AFX_DATA_INIT
}


void CMonotonyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonotonyDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_CALC, m_btnCalc);
	DDX_Text(pDX, IDC_EDIT_X, m_fX);
	DDX_Text(pDX, IDC_EDIT_MONOTONY, m_strMonotony);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMonotonyDlg, CDialog)
	//{{AFX_MSG_MAP(CMonotonyDlg)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonotonyDlg message handlers

BOOL CMonotonyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  EnableThemeDialogTexture(GetSafeHwnd());

  m_btnCalc.SetThemeHelper(&m_ThemeHelper);
  m_btnCalc.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCalc.EnableBalloonTooltip();
  m_btnCalc.SetTooltipText("Berechnen!");

  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText("Abbruch!");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMonotonyDlg::OnButtonCalc() 
{
  UpdateData(true);
  float fM = GetYof1stDerivatedFunction(m_fX);
  if (fM  < 0) m_strMonotony = _T("fallend");
  if (fM == 0) m_strMonotony = _T("konstant");
  if (fM  > 0) m_strMonotony = _T("steigend");
  UpdateData(false);
}

float CMonotonyDlg::GetYof1stDerivatedFunction(float x)
{
  float y = 0; // Y-Wert initialisieren
  y = y+(m_arr1stDerivatedFunction.GetAt(0)*float(pow(x,0))); // entspricht d*x^0 einer Funktion
  y = y+(m_arr1stDerivatedFunction.GetAt(1)*float(pow(x,1))); // entspricht c*x^1 einer Funktion
  y = y+(m_arr1stDerivatedFunction.GetAt(2)*float(pow(x,2))); // entspricht b*x^2 einer Funktion
  y = y+(m_arr1stDerivatedFunction.GetAt(3)*float(pow(x,3))); // entspricht a*x^3 einer Funktion
  return y; // Y-Wert zurückgeben
}
