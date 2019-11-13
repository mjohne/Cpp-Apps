// WeltkarteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Salah.h"
#include "WeltkarteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeltkarteDlg dialog


CWeltkarteDlg::CWeltkarteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWeltkarteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWeltkarteDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWeltkarteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeltkarteDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWeltkarteDlg, CDialog)
	//{{AFX_MSG_MAP(CWeltkarteDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeltkarteDlg message handlers

BOOL CWeltkarteDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWeltkarteDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
