#if !defined(AFX_NEWUSERDLG_H__92A394A3_0ED5_4A7A_84E6_BD638B3F49E6__INCLUDED_)
#define AFX_NEWUSERDLG_H__92A394A3_0ED5_4A7A_84E6_BD638B3F49E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewUserDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"
#include "BCMenu.h"

/////////////////////////////////////////////////////////////////////////////
// CNewUserDlg dialog

class CNewUserDlg : public CDialog
{
// Construction
public:
	CNewUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewUserDlg)
	enum { IDD = IDD_DIALOG_USER_NEW };
	CXPStyleButtonST	m_btnExportAsVCard;
        CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST	m_btnOK;
	CXPStyleButtonST	m_btnCancel;
	CDateTimeCtrl	m_dtUserBirthday;
	CString	m_strUserName;
	CString	m_strUserPlace;
	CString	m_strUserStreet;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewUserDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonVCardExport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWUSERDLG_H__92A394A3_0ED5_4A7A_84E6_BD638B3F49E6__INCLUDED_)
