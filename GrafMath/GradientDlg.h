#if !defined(AFX_GradientDlg_H__F972CB5C_1EF4_4355_A155_1531D05B4099__INCLUDED_)
#define AFX_GradientDlg_H__F972CB5C_1EF4_4355_A155_1531D05B4099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GradientDlg.h : header file


#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"


/////////////////////////////////////////////////////////////////////////////
// CGradientDlg dialog

class CGradientDlg : public CDialog
{
// Construction
public:
	CGradientDlg(CWnd* pParent = NULL);   // standard constructor
  CArray<float,float> m_arrFunction,m_arr1stDerivatedFunction;
  float GetYofFunction(float x);
// Dialog Data
	//{{AFX_DATA(CGradientDlg)
	enum { IDD = IDD_DIALOG_GRADIENT };
	CXPStyleButtonST	m_btnCancel;
	CXPStyleButtonST	m_btnCalc;
  CThemeHelperST m_ThemeHelper;
	float	m_fGradient;
	float	m_fX;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGradientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGradientDlg)
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

#endif // !defined(AFX_GradientDlg_H__F972CB5C_1EF4_4355_A155_1531D05B4099__INCLUDED_)
