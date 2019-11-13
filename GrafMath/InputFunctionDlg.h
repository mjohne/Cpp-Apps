#if !defined(AFX_INPUTFUNCTIONDLG_H__63A0E5C8_7AF4_455F_93E7_4E3BB193EE82__INCLUDED_)
#define AFX_INPUTFUNCTIONDLG_H__63A0E5C8_7AF4_455F_93E7_4E3BB193EE82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputFunctionDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CInputFunctionDlg dialog

class CInputFunctionDlg : public CDialog
{
// Construction
public:
	CInputFunctionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInputFunctionDlg)
	enum { IDD = IDD_DIALOG_INPUT_FUNCTION };
	CSpinButtonCtrl	m_sbtnKoeffizientD;
	CSpinButtonCtrl	m_sbtnKoeffizientC;
	CSpinButtonCtrl	m_sbtnKoeffizientB;
	CSpinButtonCtrl	m_sbtnKoeffizientA;
	CXPStyleButtonST	m_btnOK;
	CXPStyleButtonST	m_btnAbbruch;
  CThemeHelperST m_ThemeHelper;
	float	m_fKoeffizientA;
	float	m_fKoeffizientB;
	float	m_fKoeffizientC;
	float	m_fKoeffizientD;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputFunctionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInputFunctionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSetfocusEditCoefficientA();
	afx_msg void OnSetfocusEditCoefficientB();
	afx_msg void OnSetfocusEditCoefficientC();
	afx_msg void OnSetfocusEditCoefficientD();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Helper functions
void	EnableThemeDialogTexture(HWND hwndDlg);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTFUNCTIONDLG_H__63A0E5C8_7AF4_455F_93E7_4E3BB193EE82__INCLUDED_)
