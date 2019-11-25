// DigitalBankbookDlg.h : header file
//

#if !defined(AFX_DIGITALBANKBOOKDLG_H__D82AF6BE_4950_4782_9A8D_92BB8DDBAB4E__INCLUDED_)
#define AFX_DIGITALBANKBOOKDLG_H__D82AF6BE_4950_4782_9A8D_92BB8DDBAB4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"
#include "BCMenu.h"

/////////////////////////////////////////////////////////////////////////////
// CDigitalBankbookDlg dialog

class CDigitalBankbookDlg : public CDialog
{
// Construction
public:
	CDigitalBankbookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDigitalBankbookDlg)
	enum { IDD = IDD_DIGITALBANKBOOK_DIALOG };
	CXPStyleButtonST	m_btnAbout;
        CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST	m_btnCancel;
	CXPStyleButtonST	m_btnOpenBankbook;
	CXPStyleButtonST	m_btnAddBankbook;
	CXPStyleButtonST	m_btnAppOptions;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDigitalBankbookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDigitalBankbookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBankbookNew();
	afx_msg void OnButtonBankbookOpen();
	afx_msg void OnButtonAppOptions();
	virtual void OnCancel();
	afx_msg void OnButtonBankbookAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIGITALBANKBOOKDLG_H__D82AF6BE_4950_4782_9A8D_92BB8DDBAB4E__INCLUDED_)
