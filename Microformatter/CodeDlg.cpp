// CodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "CodeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCodeDlg dialog


CCodeDlg::CCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCodeDlg)
	m_strCode = _T("");
	//}}AFX_DATA_INIT
}


void CCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCodeDlg)
	DDX_Text(pDX, IDC_EDIT_CODE, m_strCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCodeDlg, CDialog)
	//{{AFX_MSG_MAP(CCodeDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCodeDlg message handlers
