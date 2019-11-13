// IntegralDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GrafMath.h"
#include "IntegralDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIntegralDlg dialog


CIntegralDlg::CIntegralDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIntegralDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIntegralDlg)
	m_fXMax = 0.0f;
	m_fXMin = 0.0f;
	m_fArea = 0.0f;
	m_rbtnXDistriction = -1;
	m_rbtnYDistriction = -1;
	//}}AFX_DATA_INIT
}


void CIntegralDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIntegralDlg)
	DDX_Control(pDX, IDC_BUTTON_CALC, m_btnCalc);
	DDX_Text(pDX, IDC_EDIT_X_MAX, m_fXMax);
	DDX_Text(pDX, IDC_EDIT_X_MIN, m_fXMin);
	DDX_Text(pDX, IDC_EDIT_AREA, m_fArea);
	DDX_Radio(pDX, IDC_RADIO_X0, m_rbtnXDistriction);
	DDX_Radio(pDX, IDC_RADIO_Y0, m_rbtnYDistriction);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIntegralDlg, CDialog)
	//{{AFX_MSG_MAP(CIntegralDlg)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIntegralDlg message handlers

BOOL CIntegralDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CIntegralDlg::OnButtonCalc() 
{
	// TODO: Add your control notification handler code here
	
}
