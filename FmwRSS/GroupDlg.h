#if !defined(AFX_GROUPDLG_H__3ABD36A7_903A_4499_A382_3693A1ED25AC__INCLUDED_)
#define AFX_GROUPDLG_H__3ABD36A7_903A_4499_A382_3693A1ED25AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"

// GroupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGroupDlg dialog

class CGroupDlg : public CDialog
{
// Construction
public:
	CGroupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGroupDlg)
	enum { IDD = IDD_DIALOG_GROUP };
	CXPStyleButtonST m_btnCancel;
	CXPStyleButtonST m_btnOK;
  CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGroupDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPDLG_H__3ABD36A7_903A_4499_A382_3693A1ED25AC__INCLUDED_)
