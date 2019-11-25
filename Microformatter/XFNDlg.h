#if !defined(AFX_XFNDLG_H__02C900E1_705D_4982_B6B4_DDE925FBDB15__INCLUDED_)
#define AFX_XFNDLG_H__02C900E1_705D_4982_B6B4_DDE925FBDB15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// XFNDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CXFNDlg dialog

class CXFNDlg : public CDialog
{
// Construction
public:
	CXFNDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CXFNDlg)
	enum { IDD = IDD_XFN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXFNDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CXFNDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XFNDLG_H__02C900E1_705D_4982_B6B4_DDE925FBDB15__INCLUDED_)
