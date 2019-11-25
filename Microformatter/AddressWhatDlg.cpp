// AddressWhatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "AddressWhatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressWhatDlg dialog


CAddressWhatDlg::CAddressWhatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddressWhatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddressWhatDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAddressWhatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddressWhatDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddressWhatDlg, CDialog)
	//{{AFX_MSG_MAP(CAddressWhatDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddressWhatDlg message handlers
