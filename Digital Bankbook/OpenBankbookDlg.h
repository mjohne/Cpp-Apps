#if !defined(AFX_OPENBANKBOOKDLG_H__064347D3_14B7_4168_879A_560C7EC73EE1__INCLUDED_)
#define AFX_OPENBANKBOOKDLG_H__064347D3_14B7_4168_879A_560C7EC73EE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpenBankbookDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"
#include "BCMenu.h"

/////////////////////////////////////////////////////////////////////////////
// COpenBankbookDlg dialog

class COpenBankbookDlg : public CDialog
{
// Construction
public:
	CString m_strPathname;
	COpenBankbookDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COpenBankbookDlg)
	enum { IDD = IDD_DIALOG_OPENBANKBOOK };
	CXPStyleButtonST	m_btnSortDescending;
	CXPStyleButtonST	m_btnSortAscending;
	CXPStyleButtonST	m_btnMoveUp;
	CXPStyleButtonST	m_btnMoveDown;
	CListCtrl	m_lstTransactions;
	CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST	m_btnGraphicOutput;
	CXPStyleButtonST	m_btnDeleteEntry;
	CXPStyleButtonST	m_btnChangeEntry;
	CXPStyleButtonST	m_btnAddEntry;
	CXPStyleButtonST	m_btnCloseBankbook;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenBankbookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COpenBankbookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonEntryAdd();
	afx_msg void OnButtonEntryChange();
	afx_msg void OnButtonEntryDelete();
	afx_msg void OnButtonGraphicOutput();
	afx_msg void OnButtonBankbookClose();
	afx_msg void OnButtonEntrySortasc();
	afx_msg void OnButtonEntrySortdesc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENBANKBOOKDLG_H__064347D3_14B7_4168_879A_560C7EC73EE1__INCLUDED_)
