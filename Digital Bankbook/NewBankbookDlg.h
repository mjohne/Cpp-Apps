#if !defined(AFX_NEWBANKBOOKDLG_H__1B74C7D6_C4CC_42E0_B5C5_599E923F6CC0__INCLUDED_)
#define AFX_NEWBANKBOOKDLG_H__1B74C7D6_C4CC_42E0_B5C5_599E923F6CC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewBankbookDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"
#include "BCMenu.h"

/////////////////////////////////////////////////////////////////////////////
// CNewBankbookDlg dialog

class CNewBankbookDlg : public CDialog
{
// Construction
public:
	CNewBankbookDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewBankbookDlg)
	enum { IDD = IDD_DIALOG_BANKBOOK_NEW };
	CXPStyleButtonST	m_btnCancel;
        CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST	m_btnUser;
	CXPStyleButtonST	m_btnCreateBankbook;
	CString	m_strBankbookDescription;
	CString	m_strBankbookName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewBankbookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewBankbookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonUser();
	afx_msg void OnButtonBankbookCreate();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDateTimeCtrl	m_dtUserBirthday;
	CString	m_strUserName;
	CString	m_strUserPlace;
	CString	m_strUserStreet;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWBANKBOOKDLG_H__1B74C7D6_C4CC_42E0_B5C5_599E923F6CC0__INCLUDED_)
