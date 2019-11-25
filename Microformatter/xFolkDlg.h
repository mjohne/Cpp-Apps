#if !defined(AFX_XFOLKDLG_H__3304FC58_ABD6_41FD_B02C_CBD0ED819AA8__INCLUDED_)
#define AFX_XFOLKDLG_H__3304FC58_ABD6_41FD_B02C_CBD0ED819AA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// xFolkDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CxFolkDlg dialog

class CxFolkDlg : public CDialog
{
// Construction
public:
	CxFolkDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CxFolkDlg)
	enum { IDD = IDD_XFOLK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CxFolkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CxFolkDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XFOLKDLG_H__3304FC58_ABD6_41FD_B02C_CBD0ED819AA8__INCLUDED_)
