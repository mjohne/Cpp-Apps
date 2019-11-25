// xFolkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "xFolkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CxFolkDlg dialog


CxFolkDlg::CxFolkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CxFolkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CxFolkDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CxFolkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CxFolkDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CxFolkDlg, CDialog)
	//{{AFX_MSG_MAP(CxFolkDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CxFolkDlg message handlers

BOOL CxFolkDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
