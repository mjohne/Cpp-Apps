// GaussEliminationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "GaussEliminationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaussEliminationDlg dialog


CGaussEliminationDlg::CGaussEliminationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGaussEliminationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGaussEliminationDlg)
	m_nNumberOfEquations = 0;
	m_fResultX1 = 0.0f;
	m_fResultX2 = 0.0f;
	m_fResultX3 = 0.0f;
	m_fResultX4 = 0.0f;
	m_fResultX5 = 0.0f;
	m_fCoefficientA11 = 0.0f;
	m_fCoefficientA12 = 0.0f;
	m_fCoefficientA13 = 0.0f;
	m_fCoefficientA14 = 0.0f;
	m_fCoefficientA15 = 0.0f;
	m_fCoefficientA21 = 0.0f;
	m_fCoefficientA22 = 0.0f;
	m_fCoefficientA23 = 0.0f;
	m_fCoefficientA24 = 0.0f;
	m_fCoefficientA25 = 0.0f;
	m_fCoefficientA31 = 0.0f;
	m_fCoefficientA32 = 0.0f;
	m_fCoefficientA33 = 0.0f;
	m_fCoefficientA34 = 0.0f;
	m_fCoefficientA35 = 0.0f;
	m_fCoefficientA41 = 0.0f;
	m_fCoefficientA42 = 0.0f;
	m_fCoefficientA43 = 0.0f;
	m_fCoefficientA44 = 0.0f;
	m_fCoefficientA45 = 0.0f;
	m_fCoefficientA51 = 0.0f;
	m_fCoefficientA52 = 0.0f;
	m_fCoefficientA53 = 0.0f;
	m_fCoefficientA54 = 0.0f;
	m_fCoefficientA55 = 0.0f;
	m_fCoefficientB1 = 0.0f;
	m_fCoefficientB2 = 0.0f;
	m_fCoefficientB3 = 0.0f;
	m_fCoefficientB4 = 0.0f;
	m_fCoefficientB5 = 0.0f;
	//}}AFX_DATA_INIT
}


void CGaussEliminationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGaussEliminationDlg)
	DDX_Control(pDX, IDC_BUTTON_SET_COEFFICIENTS, m_btnSetCoefficients);
	DDX_Control(pDX, IDC_BUTTON_CALC, m_btnCalc);
	DDX_Text(pDX, IDC_EDIT_NUMB_OF_EQUATIONS, m_nNumberOfEquations);
	DDX_Text(pDX, IDC_EDIT_RESULTX1, m_fResultX1);
	DDX_Text(pDX, IDC_EDIT_RESULTX2, m_fResultX2);
	DDX_Text(pDX, IDC_EDIT_RESULTX3, m_fResultX3);
	DDX_Text(pDX, IDC_EDIT_RESULTX4, m_fResultX4);
	DDX_Text(pDX, IDC_EDIT_RESULTX5, m_fResultX5);
	DDX_Text(pDX, IDC_EDIT_COEFFA11, m_fCoefficientA11);
	DDX_Text(pDX, IDC_EDIT_COEFFA12, m_fCoefficientA12);
	DDX_Text(pDX, IDC_EDIT_COEFFA13, m_fCoefficientA13);
	DDX_Text(pDX, IDC_EDIT_COEFFA14, m_fCoefficientA14);
	DDX_Text(pDX, IDC_EDIT_COEFFA15, m_fCoefficientA15);
	DDX_Text(pDX, IDC_EDIT_COEFFA21, m_fCoefficientA21);
	DDX_Text(pDX, IDC_EDIT_COEFFA22, m_fCoefficientA22);
	DDX_Text(pDX, IDC_EDIT_COEFFA23, m_fCoefficientA23);
	DDX_Text(pDX, IDC_EDIT_COEFFA24, m_fCoefficientA24);
	DDX_Text(pDX, IDC_EDIT_COEFFA25, m_fCoefficientA25);
	DDX_Text(pDX, IDC_EDIT_COEFFA31, m_fCoefficientA31);
	DDX_Text(pDX, IDC_EDIT_COEFFA32, m_fCoefficientA32);
	DDX_Text(pDX, IDC_EDIT_COEFFA33, m_fCoefficientA33);
	DDX_Text(pDX, IDC_EDIT_COEFFA34, m_fCoefficientA34);
	DDX_Text(pDX, IDC_EDIT_COEFFA35, m_fCoefficientA35);
	DDX_Text(pDX, IDC_EDIT_COEFFA41, m_fCoefficientA41);
	DDX_Text(pDX, IDC_EDIT_COEFFA42, m_fCoefficientA42);
	DDX_Text(pDX, IDC_EDIT_COEFFA43, m_fCoefficientA43);
	DDX_Text(pDX, IDC_EDIT_COEFFA44, m_fCoefficientA44);
	DDX_Text(pDX, IDC_EDIT_COEFFA45, m_fCoefficientA45);
	DDX_Text(pDX, IDC_EDIT_COEFFA51, m_fCoefficientA51);
	DDX_Text(pDX, IDC_EDIT_COEFFA52, m_fCoefficientA52);
	DDX_Text(pDX, IDC_EDIT_COEFFA53, m_fCoefficientA53);
	DDX_Text(pDX, IDC_EDIT_COEFFA54, m_fCoefficientA54);
	DDX_Text(pDX, IDC_EDIT_COEFFA55, m_fCoefficientA55);
	DDX_Text(pDX, IDC_EDIT_COEFFB1, m_fCoefficientB1);
	DDX_Text(pDX, IDC_EDIT_COEFFB2, m_fCoefficientB2);
	DDX_Text(pDX, IDC_EDIT_COEFFB3, m_fCoefficientB3);
	DDX_Text(pDX, IDC_EDIT_COEFFB4, m_fCoefficientB4);
	DDX_Text(pDX, IDC_EDIT_COEFFB5, m_fCoefficientB5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGaussEliminationDlg, CDialog)
	//{{AFX_MSG_MAP(CGaussEliminationDlg)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	ON_BN_CLICKED(IDC_BUTTON_SET_COEFFICIENTS, OnButtonSetCoefficients)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGaussEliminationDlg message handlers

BOOL CGaussEliminationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

  EnableThemeDialogTexture(GetSafeHwnd());

  GetDlgItem(IDC_EDIT_COEFFA11)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA12)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA13)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA14)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA15)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA21)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA22)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA23)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA24)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA25)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA31)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA32)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA33)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA34)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA35)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA41)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA42)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA43)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA44)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA45)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA51)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA52)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA53)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA54)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFA55)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFB1)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFB2)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFB3)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFB4)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_COEFFB5)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_RESULTX1)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_RESULTX2)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_RESULTX3)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_RESULTX4)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_RESULTX5)->EnableWindow(false);

  m_btnSetCoefficients.SetThemeHelper(&m_ThemeHelper);
  m_btnSetCoefficients.SetIcon(IDI_ICON_OK);
  m_btnSetCoefficients.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSetCoefficients.EnableBalloonTooltip();
  m_btnSetCoefficients.SetTooltipText("Anzahl lösbarer Gleichungen setzen");  
	
  m_btnCalc.SetThemeHelper(&m_ThemeHelper);
  m_btnCalc.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCalc.EnableBalloonTooltip();
  m_btnCalc.SetTooltipText("Unbekannte errechnen!");  
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGaussEliminationDlg::OnButtonCalc() 
{
  UpdateData(true);
	m_fCoefficientA[1][1] = m_fCoefficientA11;
	m_fCoefficientA[1][2] = m_fCoefficientA12;
	m_fCoefficientA[1][3] = m_fCoefficientA13;
	m_fCoefficientA[1][4] = m_fCoefficientA14;
	m_fCoefficientA[1][5] = m_fCoefficientA15;
	m_fCoefficientA[2][1] = m_fCoefficientA21;
	m_fCoefficientA[2][2] = m_fCoefficientA22;
	m_fCoefficientA[2][3] = m_fCoefficientA23;
	m_fCoefficientA[2][4] = m_fCoefficientA24;
	m_fCoefficientA[2][5] = m_fCoefficientA25;
	m_fCoefficientA[3][1] = m_fCoefficientA31;
	m_fCoefficientA[3][2] = m_fCoefficientA32;
	m_fCoefficientA[3][3] = m_fCoefficientA33;
	m_fCoefficientA[3][4] = m_fCoefficientA34;
	m_fCoefficientA[3][5] = m_fCoefficientA35;
	m_fCoefficientA[4][1] = m_fCoefficientA41;
	m_fCoefficientA[4][2] = m_fCoefficientA42;
	m_fCoefficientA[4][3] = m_fCoefficientA43;
	m_fCoefficientA[4][4] = m_fCoefficientA44;
	m_fCoefficientA[5][5] = m_fCoefficientA45;
	m_fCoefficientA[5][1] = m_fCoefficientA51;
	m_fCoefficientA[5][2] = m_fCoefficientA52;
	m_fCoefficientA[5][3] = m_fCoefficientA53;
	m_fCoefficientA[5][4] = m_fCoefficientA54;
	m_fCoefficientA[5][5] = m_fCoefficientA55;
	m_fCoefficientA[5][5] = m_fCoefficientA45;
	m_fCoefficientB[1] = m_fCoefficientB1;
	m_fCoefficientB[2] = m_fCoefficientB2;
	m_fCoefficientB[3] = m_fCoefficientB3;
	m_fCoefficientB[4] = m_fCoefficientB4;
	m_fCoefficientB[5] = m_fCoefficientB5;
  m_fResultX1 = 0;
  m_fResultX2 = 0;
  m_fResultX3 = 0;
  m_fResultX4 = 0;
  m_fResultX5 = 0;
  UpdateData(false);
  int n = m_nNumberOfEquations;
  for (int a = 1; a < n+1; a++) m_fResultX[a] = 0;
  //Spalten Elimination
  float q = 0, summe = 0;
  for (int i = 1; i <= n-1; i++)
  {
    for (int j = i+1; j <= n; j++)
    {
      if (m_fCoefficientA[i][i] != 0)
      {
        q = -m_fCoefficientA[j][i]/m_fCoefficientA[i][i];
      }
      for (int k = i; k <= n; k++)
      {
        m_fCoefficientA[j][k] = m_fCoefficientA[j][k]+m_fCoefficientA[i][k]*q;
      }
      m_fCoefficientB[j] = m_fCoefficientB[j]+m_fCoefficientB[i]*q;
    }
  }
  //Rücksubstitution
  for (i = n; i >= 1; i--)
  {
    summe = 0;
    for (int k = i+1; k <= n; k++)
    {
      summe = summe+m_fCoefficientA[i][k]*m_fResultX[k];
    }
    if (m_fCoefficientA[i][i] != 0) m_fResultX[i] = (m_fCoefficientB[i]-summe)/m_fCoefficientA[i][i];
  }

  m_fResultX1 = m_fResultX[1];
  m_fResultX2 = m_fResultX[2];
  m_fResultX3 = m_fResultX[3];
  m_fResultX4 = m_fResultX[4];
  m_fResultX5 = m_fResultX[5];
  UpdateData(false);
}

void CGaussEliminationDlg::OnButtonSetCoefficients() 
{
	UpdateData(true);
	switch(m_nNumberOfEquations)
  {
    case 1 :
    {
      GetDlgItem(IDC_EDIT_COEFFA11)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA12)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFA13)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFA14)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFA15)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA21)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA22)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA23)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA24)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA25)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA31)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA32)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA33)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA34)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA35)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA41)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA42)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA43)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA44)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA45)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA51)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA52)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA53)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA54)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA55)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB1)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB2)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB3)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB4)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB5)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX1)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX2)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX3)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX4)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX5)->EnableWindow(false);
      break;
    }
    case 2 :
    {
      GetDlgItem(IDC_EDIT_COEFFA11)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA12)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA13)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFA14)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFA15)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA21)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA22)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA23)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA24)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA25)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA31)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA32)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA33)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA34)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA35)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA41)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA42)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA43)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA44)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA45)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA51)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA52)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA53)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA54)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA55)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB1)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB2)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB3)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB4)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB5)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX1)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX2)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX3)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX4)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX5)->EnableWindow(false);
      break;
    }
    case 3 :
    {
      GetDlgItem(IDC_EDIT_COEFFA11)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA12)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA13)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA14)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFA15)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA21)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA22)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA23)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA24)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA25)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA31)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA32)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA33)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA34)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA35)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA41)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA42)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA43)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA44)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA45)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA51)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA52)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA53)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA54)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA55)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB1)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB2)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB3)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB4)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB5)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX1)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX2)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX3)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX4)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX5)->EnableWindow(false);
      break;
    }
    case 4 :
    {
      GetDlgItem(IDC_EDIT_COEFFA11)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA12)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA13)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA14)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA15)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA21)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA22)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA23)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA24)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA25)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA31)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA32)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA33)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA34)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA35)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA41)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA42)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA43)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA44)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA45)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA51)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA52)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA53)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA54)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_COEFFA55)->EnableWindow(false);
      GetDlgItem(IDC_EDIT_COEFFB1)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB2)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB3)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB4)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB5)->EnableWindow(false);
	    GetDlgItem(IDC_EDIT_RESULTX1)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX2)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX3)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX4)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX5)->EnableWindow(false);
      break;
    }
    case 5 :
    {
      GetDlgItem(IDC_EDIT_COEFFA11)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA12)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA13)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA14)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFA15)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA21)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA22)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA23)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA24)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA25)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA31)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA32)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA33)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA34)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA35)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA41)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA42)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA43)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA44)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA45)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA51)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA52)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA53)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA54)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_COEFFA55)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB1)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB2)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB3)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB4)->EnableWindow(true);
      GetDlgItem(IDC_EDIT_COEFFB5)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX1)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX2)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX3)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX4)->EnableWindow(true);
	    GetDlgItem(IDC_EDIT_RESULTX5)->EnableWindow(true);
      break;
    }
  }	
}
