// hReviewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "hReviewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChReviewDlg dialog


ChReviewDlg::ChReviewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ChReviewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ChReviewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ChReviewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChReviewDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ChReviewDlg, CDialog)
	//{{AFX_MSG_MAP(ChReviewDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ChReviewDlg message handlers

BOOL ChReviewDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
