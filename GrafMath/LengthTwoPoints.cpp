// LengthTwoPoints.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "LengthTwoPoints.h"
#include <cmath>
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLengthTwoPoints dialog


CLengthTwoPoints::CLengthTwoPoints(CWnd* pParent /*=NULL*/)
	: CDialog(CLengthTwoPoints::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLengthTwoPoints)
	m_fLength2Points = 0.0f;
	m_fP1X = 0.0f;
	m_fP2X = 0.0f;
	m_fP1Y = 0.0f;
	m_fP2Y = 0.0f;
	//}}AFX_DATA_INIT
}


void CLengthTwoPoints::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLengthTwoPoints)
	DDX_Control(pDX, IDC_BUTTON_GETY2, m_btnY2);
	DDX_Control(pDX, IDC_BUTTON_GETY1, m_btnY1);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_CALC, m_btnCalc);
	DDX_Text(pDX, IDC_EDIT_LEN2P, m_fLength2Points);
	DDX_Text(pDX, IDC_EDIT_P1X, m_fP1X);
	DDX_Text(pDX, IDC_EDIT_P2X, m_fP2X);
	DDX_Text(pDX, IDC_EDIT_P1Y, m_fP1Y);
	DDX_Text(pDX, IDC_EDIT_P2Y, m_fP2Y);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLengthTwoPoints, CDialog)
	//{{AFX_MSG_MAP(CLengthTwoPoints)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	ON_BN_CLICKED(IDC_BUTTON_GETY1, OnButtonGetY1)
	ON_BN_CLICKED(IDC_BUTTON_GETY2, OnButtonGetY2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLengthTwoPoints message handlers


BOOL CLengthTwoPoints::OnInitDialog() 
{
  UpdateData(false);

  EnableThemeDialogTexture(GetSafeHwnd());

  m_btnY1.SetThemeHelper(&m_ThemeHelper);
  m_btnY1.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnY1.EnableBalloonTooltip();
  m_btnY1.SetTooltipText("'y' ermitteln");

  m_btnY2.SetThemeHelper(&m_ThemeHelper);
  m_btnY2.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnY2.EnableBalloonTooltip();
  m_btnY2.SetTooltipText("'y' ermitteln");

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

void CLengthTwoPoints::OnButtonCalc() 
{
  UpdateData(true);
  m_fLength2Points = sqrt(pow(fabs(m_fP2X-m_fP1X),2)+pow(fabs(m_fP2Y-m_fP1Y),2));
  UpdateData(false);
}

/***********************************************************************************************************/
//   float CGrafMathDlg::GetYofFunction(float x)
// -----------------------------------------------
//
//  Diese Funktion errechnet den Y-Wert einer Funktion - eingegeben durch einen X-Wert des Koordinaten-
//  systems - und gibt den Y-Wert zurück.
//
/***********************************************************************************************************/
float CLengthTwoPoints::GetYofFunction(float x)
{
  float y = 0; // Y-Wert initialisieren
  y = y+(m_arrFunction.GetAt(0)*float(pow(x,0))); // entspricht d*x^0 einer Funktion
  y = y+(m_arrFunction.GetAt(1)*float(pow(x,1))); // entspricht c*x^1 einer Funktion
  y = y+(m_arrFunction.GetAt(2)*float(pow(x,2))); // entspricht b*x^2 einer Funktion
  y = y+(m_arrFunction.GetAt(3)*float(pow(x,3))); // entspricht a*x^3 einer Funktion
  return y; // Y-Wert zurückgeben
}

void CLengthTwoPoints::OnButtonGetY1() 
{
  UpdateData(true);
  m_fP1Y = GetYofFunction(m_fP1X);
  UpdateData(false);
}

void CLengthTwoPoints::OnButtonGetY2() 
{
  UpdateData(true);
  m_fP2Y = GetYofFunction(m_fP2X);
  UpdateData(false);
}
