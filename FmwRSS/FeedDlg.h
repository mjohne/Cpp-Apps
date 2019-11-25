#if !defined(AFX_FEEDDLG_H__13BC0CA5_7844_42D0_B21D_908FBA457285__INCLUDED_)
#define AFX_FEEDDLG_H__13BC0CA5_7844_42D0_B21D_908FBA457285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FeedDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"

/////////////////////////////////////////////////////////////////////////////
// CFeedDlg dialog

class CFeedDlg : public CDialog
{
// Construction
public:
	CFeedDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFeedDlg)
	enum { IDD = IDD_DIALOG_FEED };
	CXPStyleButtonST m_btnOK;
	CXPStyleButtonST m_btnCancel;
  CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFeedDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFeedDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FEEDDLG_H__13BC0CA5_7844_42D0_B21D_908FBA457285__INCLUDED_)
