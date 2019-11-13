// GetXofYDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "GetXofYDlg.h"
#include <cmath>
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetXofYDlg dialog


CGetXofYDlg::CGetXofYDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetXofYDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetXofYDlg)
	m_fX = 0.0f;
	m_fY = 0.0f;
	//}}AFX_DATA_INIT
}


void CGetXofYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetXofYDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_CALC, m_btnCalc);
	DDX_Text(pDX, IDC_EDIT_X, m_fX);
	DDX_Text(pDX, IDC_EDIT_Y, m_fY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGetXofYDlg, CDialog)
	//{{AFX_MSG_MAP(CGetXofYDlg)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetXofYDlg message handlers

BOOL CGetXofYDlg::OnInitDialog() 
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

void CGetXofYDlg::OnButtonCalc() 
{
  UpdateData(true);
	m_fY = GetYofFunction(m_fX);
  UpdateData(false);
}

float CGetXofYDlg::GetYofFunction(float x)
{
  float y = 0; // Y-Wert initialisieren
  y = y+(float(m_arrFunction.GetAt(0))*float(pow(x,0))); // entspricht d*x^0 einer Funktion
  y = y+(float(m_arrFunction.GetAt(1))*float(pow(x,1))); // entspricht c*x^1 einer Funktion
  y = y+(float(m_arrFunction.GetAt(2))*float(pow(x,2))); // entspricht b*x^2 einer Funktion
  y = y+(float(m_arrFunction.GetAt(3))*float(pow(x,3))); // entspricht a*x^3 einer Funktion
  return y; // Y-Wert zurückgeben
}
