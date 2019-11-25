// hCalenderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "hCalenderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChCalenderDlg dialog


ChCalenderDlg::ChCalenderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ChCalenderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ChCalenderDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ChCalenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChCalenderDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ChCalenderDlg, CDialog)
	//{{AFX_MSG_MAP(ChCalenderDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ChCalenderDlg message handlers

BOOL ChCalenderDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
