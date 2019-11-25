#if !defined(AFX_HATOMDLG_H__B9D5F98C_413E_44EF_9826_8E72947F6D96__INCLUDED_)
#define AFX_HATOMDLG_H__B9D5F98C_413E_44EF_9826_8E72947F6D96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hAtomDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ChAtomDlg dialog

class ChAtomDlg : public CDialog
{
// Construction
public:
	ChAtomDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ChAtomDlg)
	enum { IDD = IDD_HATOM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChAtomDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ChAtomDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HATOMDLG_H__B9D5F98C_413E_44EF_9826_8E72947F6D96__INCLUDED_)
