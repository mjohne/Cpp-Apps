// hAtomDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "hAtomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChAtomDlg dialog


ChAtomDlg::ChAtomDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ChAtomDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ChAtomDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ChAtomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChAtomDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ChAtomDlg, CDialog)
	//{{AFX_MSG_MAP(ChAtomDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ChAtomDlg message handlers

BOOL ChAtomDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
