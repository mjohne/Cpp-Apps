#if !defined(AFX_GETXOFYDLG_H__B2EF7BF3_3F4B_49C5_A62A_7A524CE1754B__INCLUDED_)
#define AFX_GETXOFYDLG_H__B2EF7BF3_3F4B_49C5_A62A_7A524CE1754B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GetXofYDlg.h : header file
//


#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"


/////////////////////////////////////////////////////////////////////////////
// CGetXofYDlg dialog

class CGetXofYDlg : public CDialog
{
// Construction
public:
	CGetXofYDlg(CWnd* pParent = NULL);   // standard constructor
  CArray<float,float> m_arrFunction;
  float GetYofFunction(float x);

// Dialog Data
	//{{AFX_DATA(CGetXofYDlg)
	enum { IDD = IDD_DIALOG_YAUSX };
	CXPStyleButtonST	m_btnCancel;
	CXPStyleButtonST	m_btnCalc;
  CThemeHelperST m_ThemeHelper;
	float	m_fX;
	float	m_fY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetXofYDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGetXofYDlg)
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

#endif // !defined(AFX_GETXOFYDLG_H__B2EF7BF3_3F4B_49C5_A62A_7A524CE1754B__INCLUDED_)
