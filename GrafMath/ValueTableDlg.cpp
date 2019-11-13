// ValueTableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "ValueTableDlg.h"
#include <cmath>
#include "HelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CValueTableDlg dialog


CValueTableDlg::CValueTableDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CValueTableDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CValueTableDlg)
	m_fXDelta = 1.0f;
	m_fXMax = 3.0f;
	m_fXMin = -3.0f;
	//}}AFX_DATA_INIT
}


void CValueTableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CValueTableDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_CALC, m_btnCalc);
	DDX_Control(pDX, IDC_LIST_VALUETABLE, m_lstValueTable);
	DDX_Text(pDX, IDC_EDIT_X_DELTA, m_fXDelta);
	DDX_Text(pDX, IDC_EDIT_X_MAX, m_fXMax);
	DDX_Text(pDX, IDC_EDIT_X_MIN, m_fXMin);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CValueTableDlg, CDialog)
	//{{AFX_MSG_MAP(CValueTableDlg)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CValueTableDlg message handlers

BOOL CValueTableDlg::OnInitDialog() 
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

  m_lstValueTable.SetExtendedStyle(LVS_EX_GRIDLINES + LVS_EX_FULLROWSELECT);
  m_lstValueTable.InsertColumn(0,"ID",LVCFMT_LEFT,0);
  m_lstValueTable.InsertColumn(1,"X",LVCFMT_LEFT,70);
  m_lstValueTable.InsertColumn(2,"Y",LVCFMT_LEFT,70);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/***********************************************************************************************************/
//   float CGrafMathDlg::GetYofFunction(float x)
// -----------------------------------------------
//
//  Diese Funktion errechnet den Y-Wert einer Funktion - eingegeben durch einen X-Wert des Koordinaten-
//  systems - und gibt den Y-Wert zurück.
//
/***********************************************************************************************************/
float CValueTableDlg::GetYofFunction(float x)
{
  float y = 0; // Y-Wert initialisieren
  y = y+(m_arrFunction.GetAt(0)*float(pow(x,0))); // entspricht d*x^0 einer Funktion
  y = y+(m_arrFunction.GetAt(1)*float(pow(x,1))); // entspricht c*x^1 einer Funktion
  y = y+(m_arrFunction.GetAt(2)*float(pow(x,2))); // entspricht b*x^2 einer Funktion
  y = y+(m_arrFunction.GetAt(3)*float(pow(x,3))); // entspricht a*x^3 einer Funktion
  return y; // Y-Wert zurückgeben
}

void CValueTableDlg::OnButtonCalc() 
{
  UpdateData(true);
  if (m_fXDelta <= 0) m_fXDelta = -1*m_fXDelta;
  if (m_fXDelta == 0) m_fXDelta = 1;
  UpdateData(false);
  int i = 0;
  CString strOutp = _T("");
  m_lstValueTable.DeleteAllItems();
	for (float f = m_fXMax; f >= m_fXMin; f = f-m_fXDelta)
  {
    i++;
    strOutp.Format("%d",i);
    m_lstValueTable.InsertItem(0,strOutp);
    strOutp.Format("%0.4f",f);
    m_lstValueTable.SetItemText(0,1,strOutp);
    strOutp.Format("%0.4f",GetYofFunction(f));
    m_lstValueTable.SetItemText(0,2,strOutp);
  }
}
