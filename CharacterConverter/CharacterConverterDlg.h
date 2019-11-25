// CharacterConverterDlg.h : header file
//

#if !defined(AFX_CHARACTERCONVERTERDLG_H__F16C1170_233E_463C_BCED_52AC124410FD__INCLUDED_)
#define AFX_CHARACTERCONVERTERDLG_H__F16C1170_233E_463C_BCED_52AC124410FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CCharacterConverterDlg dialog

class CCharacterConverterDlg : public CDialog
{
// Construction
public:
	CCharacterConverterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCharacterConverterDlg)
	enum { IDD = IDD_CHARACTERCONVERTER_DIALOG };
	CXPStyleButtonST	m_btnAbout;
	CXPStyleButtonST	m_btnExit;
	CXPStyleButtonST	m_btnInfoCharset;
	CXPStyleButtonST	m_btnOutputFile;
	CXPStyleButtonST	m_btnInputFile;
	CComboBox	m_cmbCharset;
	CXPStyleButtonST	m_btnConvert;
	CString	m_strInputFile;
	CString	m_strOutputFile;
	CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharacterConverterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCharacterConverterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonIFile();
	afx_msg void OnButtonInfoCharset();
	afx_msg void OnButtonOFile();
	afx_msg void OnButtonConvert();
	afx_msg void OnButtonAbout();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARACTERCONVERTERDLG_H__F16C1170_233E_463C_BCED_52AC124410FD__INCLUDED_)
