// TabelleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Salah.h"
#include "TabelleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabelleDlg dialog


CTabelleDlg::CTabelleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTabelleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabelleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTabelleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabelleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTabelleDlg, CDialog)
	//{{AFX_MSG_MAP(CTabelleDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabelleDlg message handlers

BOOL CTabelleDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
