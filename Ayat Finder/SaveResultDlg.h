#if !defined(AFX_SAVERESULTDLG_H__F00864AB_7589_4D57_9254_0A363AA3CCA8__INCLUDED_)
#define AFX_SAVERESULTDLG_H__F00864AB_7589_4D57_9254_0A363AA3CCA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SaveResultDlg.h : header file
//

#include "BCMenu.h"
#include "HyperLink.h"
#include "ThemeHelperST.h"
#include "XPStyleButtonST.h"
#include "XPTabCtrl.h"
#include "XZip.h"

/////////////////////////////////////////////////////////////////////////////
// CSaveResultDlg dialog

class CSaveResultDlg : public CDialog
{
// Construction
public:
	CSaveResultDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSaveResultDlg)
	enum { IDD = IDD_DIALOG_SAVERESULT };
	CXPStyleButtonST	m_btnOK;
	CXPStyleButtonST	m_btnCancel;
	int		m_rbtnFormat;
	CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSaveResultDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSaveResultDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAVERESULTDLG_H__F00864AB_7589_4D57_9254_0A363AA3CCA8__INCLUDED_)
