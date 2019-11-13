// LimitXDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WordStat.h"
#include "LimitXDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLimitXDlg dialog


CLimitXDlg::CLimitXDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLimitXDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLimitXDlg)
	m_uintLimitX = 0;
	//}}AFX_DATA_INIT
}


void CLimitXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLimitXDlg)
	DDX_Text(pDX, IDC_EDIT_LIMITX, m_uintLimitX);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLimitXDlg, CDialog)
	//{{AFX_MSG_MAP(CLimitXDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLimitXDlg message handlers
