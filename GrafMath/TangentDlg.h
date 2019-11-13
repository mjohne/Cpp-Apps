#if !defined(AFX_TANGENTDLG_H__C0703BA6_9D0E_4AA6_8563_273DC7EDED25__INCLUDED_)
#define AFX_TANGENTDLG_H__C0703BA6_9D0E_4AA6_8563_273DC7EDED25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// TangentDlg.h : header file


#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"


/////////////////////////////////////////////////////////////////////////////
// CTangentDlg dialog

class CTangentDlg : public CDialog
{
// Construction
public:
	CTangentDlg(CWnd* pParent = NULL);   // standard constructor
  CArray<float,float> m_arrFunction,m_arr1stDerivatedFunction;
  float GetYofFunction(float x);
  float GetYof1stDerivatedFunction(float x);

// Dialog Data
	//{{AFX_DATA(CTangentDlg)
	enum { IDD = IDD_DIALOG_TANGENT };
	CXPStyleButtonST	m_btnCancel;
	CXPStyleButtonST	m_btnCalc;
  CThemeHelperST m_ThemeHelper;
	float	m_fX;
	CString	m_strTangent;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTangentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTangentDlg)
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

#endif // !defined(AFX_TANGENTDLG_H__C0703BA6_9D0E_4AA6_8563_273DC7EDED25__INCLUDED_)
