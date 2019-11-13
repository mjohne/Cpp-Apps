// TangentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "TangentDlg.h"
#include <cmath>
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTangentDlg dialog


CTangentDlg::CTangentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTangentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTangentDlg)
	m_fX = 0.0f;
	m_strTangent = _T("");
	//}}AFX_DATA_INIT
}


void CTangentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTangentDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_CALC, m_btnCalc);
	DDX_Text(pDX, IDC_EDIT_X, m_fX);
	DDX_Text(pDX, IDC_EDIT_TANGENT, m_strTangent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTangentDlg, CDialog)
	//{{AFX_MSG_MAP(CTangentDlg)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTangentDlg message handlers

BOOL CTangentDlg::OnInitDialog() 
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

void CTangentDlg::OnButtonCalc() 
{
  UpdateData(true);
	float fM = GetYof1stDerivatedFunction(m_fX);
  float fX = 0;
	float fY = GetYofFunction(m_fX);
  float fTemp = 0;
  CString
    strOutp = _T(""),
    strOutp2 = _T(""),
    strOutp3 = _T("");

  m_strTangent = _T("t(x) = ");
  strOutp3 = _T("%0.3f");
  strOutp2.Format(strOutp3,fM);
  m_strTangent += strOutp2;
  m_strTangent += "x - ";
  fX = (fM*m_fX)+(fM*fY);
  strOutp3 = _T("%0.3f");
  strOutp2.Format(strOutp3,fX);
  m_strTangent += strOutp2;
  UpdateData(false);
}

float CTangentDlg::GetYofFunction(float x)
{
  float y = 0; // Y-Wert initialisieren
  y = y+(m_arrFunction.GetAt(0)*float(pow(x,0))); // entspricht d*x^0 einer Funktion
  y = y+(m_arrFunction.GetAt(1)*float(pow(x,1))); // entspricht c*x^1 einer Funktion
  y = y+(m_arrFunction.GetAt(2)*float(pow(x,2))); // entspricht b*x^2 einer Funktion
  y = y+(m_arrFunction.GetAt(3)*float(pow(x,3))); // entspricht a*x^3 einer Funktion
  return y; // Y-Wert zurückgeben
}

float CTangentDlg::GetYof1stDerivatedFunction(float x)
{
  float y = 0; // Y-Wert initialisieren
  y = y+(m_arr1stDerivatedFunction.GetAt(0)*float(pow(x,0))); // entspricht d*x^0 einer Funktion
  y = y+(m_arr1stDerivatedFunction.GetAt(1)*float(pow(x,1))); // entspricht c*x^1 einer Funktion
  y = y+(m_arr1stDerivatedFunction.GetAt(2)*float(pow(x,2))); // entspricht b*x^2 einer Funktion
  y = y+(m_arr1stDerivatedFunction.GetAt(3)*float(pow(x,3))); // entspricht a*x^3 einer Funktion
  return y; // Y-Wert zurückgeben
}
