#if !defined(AFX_CREDITSDLG_H__6368BD67_BB96_4284_8B6F_8E9E889E2C5F__INCLUDED_)
#define AFX_CREDITSDLG_H__6368BD67_BB96_4284_8B6F_8E9E889E2C5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CreditsDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CCreditsDlg dialog

class CCreditsDlg : public CDialog
{
// Construction
public:
	CCreditsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCreditsDlg)
	enum { IDD = IDD_DIALOG_CREDITS };
	CXPStyleButtonST	m_btnOK;
  CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreditsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCreditsDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Helper functions
void	EnableThemeDialogTexture(HWND hwndDlg);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREDITSDLG_H__6368BD67_BB96_4284_8B6F_8E9E889E2C5F__INCLUDED_)
