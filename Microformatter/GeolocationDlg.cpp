// GeolocationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "GeolocationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeolocationDlg dialog


CGeolocationDlg::CGeolocationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGeolocationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGeolocationDlg)
	//}}AFX_DATA_INIT
}


void CGeolocationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeolocationDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeolocationDlg, CDialog)
	//{{AFX_MSG_MAP(CGeolocationDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeolocationDlg message handlers

BOOL CGeolocationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
