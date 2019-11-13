#if !defined(AFX_MONOTONYDLG_H__C48B0BC7_695D_4E56_8433_22767DFECCF3__INCLUDED_)
#define AFX_MONOTONYDLG_H__C48B0BC7_695D_4E56_8433_22767DFECCF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MonotonyDlg.h : header file
//


#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"


/////////////////////////////////////////////////////////////////////////////
// CMonotonyDlg dialog

class CMonotonyDlg : public CDialog
{
// Construction
public:
	CMonotonyDlg(CWnd* pParent = NULL);   // standard constructor
  CArray<float,float> m_arrFunction,m_arr1stDerivatedFunction;
  float GetYof1stDerivatedFunction(float x);

// Dialog Data
	//{{AFX_DATA(CMonotonyDlg)
	enum { IDD = IDD_DIALOG_MONOTONY };
	CXPStyleButtonST	m_btnCancel;
	CXPStyleButtonST	m_btnCalc;
  CThemeHelperST m_ThemeHelper;
	float	m_fX;
	CString	m_strMonotony;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonotonyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMonotonyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonCalc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Helper functions
void	EnableThemeDialogTexture(HWND hwndDlg);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONOTONYDLG_H__C48B0BC7_695D_4E56_8433_22767DFECCF3__INCLUDED_)
