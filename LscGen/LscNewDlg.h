#if !defined(AFX_LSCNEW_H__297E344B_7307_4F9A_A5BE_A69DD13A8912__INCLUDED_)
#define AFX_LSCNEW_H__297E344B_7307_4F9A_A5BE_A69DD13A8912__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LscNewDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
	

/////////////////////////////////////////////////////////////////////////////
// CLscNewDlg dialog

class CLscNewDlg : public CDialog
{
// Construction
public:
	bool m_bAbort;
	CLscNewDlg(CWnd* pParent = NULL);   // standard constructor
	CMatrix<UINT> *m_arrHeightfield;
	CButtonST m_btnRouteUp;
	CButtonST m_btnRouteDown;
	CButtonST m_btnRouteLeft;
	CButtonST m_btnRouteRight;
	CButtonST m_btnRouteDefault;
	CXPStyleButtonST m_btnGenerate;
	CXPStyleButtonST m_btnOK;
	CXPStyleButtonST m_btnAbort;
  CThemeHelperST m_ThemeHelper;

// Dialog Data
	//{{AFX_DATA(CLscNewDlg)
	enum { IDD = IDD_DIALOG_LSC_NEW };
	CComboBox	m_cmbAlgorithm;
	CProgressCtrl	m_prgsGenerate;
	CComboBox	m_cmbMethod2Whatnext;
	CString	m_strLscName;
	UINT	m_uintAlgorithm;
	UINT	m_uintMethod1;
	UINT	m_uintMethod2;
	UINT	m_uintSizeX;
	UINT	m_uintSizeY;
	UINT	m_uintStartX;
	UINT	m_uintStartY;
	CString	m_strLscComments;
	UINT	m_uintHeightDescAfter;
	int		m_rbtnMethod;
	int		m_nStartpointXY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLscNewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLscNewDlg)
	afx_msg void OnChangeEditLscName();
	afx_msg void OnRadioMethod1();
	afx_msg void OnRadioMethod2();
	afx_msg void OnRadioStartXY();
	afx_msg void OnRadioStartRandom();
	afx_msg void OnButtonGenerate();
	afx_msg void OnRadioStartMidpoint();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnButtonHmPreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LSCNEW_H__297E344B_7307_4F9A_A5BE_A69DD13A8912__INCLUDED_)
