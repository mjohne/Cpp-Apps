#if !defined(AFX_LIMITXDLG_H__4D45D550_F75E_4E13_8241_86353C3F4D39__INCLUDED_)
#define AFX_LIMITXDLG_H__4D45D550_F75E_4E13_8241_86353C3F4D39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LimitXDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLimitXDlg dialog

class CLimitXDlg : public CDialog
{
// Construction
public:
	CLimitXDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLimitXDlg)
	enum { IDD = IDD_DIALOG_LIMITX };
	UINT	m_uintLimitX;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLimitXDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLimitXDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIMITXDLG_H__4D45D550_F75E_4E13_8241_86353C3F4D39__INCLUDED_)
