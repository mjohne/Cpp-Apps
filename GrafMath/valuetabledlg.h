#if !defined(AFX_ValueTableDlg_H__4479148B_A614_4976_B91D_710061014BFF__INCLUDED_)
#define AFX_ValueTableDlg_H__4479148B_A614_4976_B91D_710061014BFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ValueTableDlg.h : header file


#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"


/////////////////////////////////////////////////////////////////////////////
// CValueTableDlg dialog

class CValueTableDlg : public CDialog
{
// Construction
public:
	CValueTableDlg(CWnd* pParent = NULL);   // standard constructor
	float GetYofFunction(float x);
	CArray<float,float> m_arrFunction;

// Dialog Data
	//{{AFX_DATA(CValueTableDlg)
	enum { IDD = IDD_DIALOG_VALUETABLE };
	CXPStyleButtonST	m_btnCancel;
	CXPStyleButtonST	m_btnCalc;
	CListCtrl	m_lstValueTable;
  CThemeHelperST m_ThemeHelper;
	float	m_fXDelta;
	float	m_fXMax;
	float	m_fXMin;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CValueTableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CValueTableDlg)
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

#endif // !defined(AFX_ValueTableDlg_H__4479148B_A614_4976_B91D_710061014BFF__INCLUDED_)
