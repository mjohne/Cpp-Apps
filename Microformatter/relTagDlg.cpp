// relTagDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "relTagDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CrelTagDlg dialog


CrelTagDlg::CrelTagDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CrelTagDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CrelTagDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CrelTagDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CrelTagDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CrelTagDlg, CDialog)
	//{{AFX_MSG_MAP(CrelTagDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CrelTagDlg message handlers

BOOL CrelTagDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
