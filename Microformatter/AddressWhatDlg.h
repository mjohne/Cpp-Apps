#if !defined(AFX_ADDRESSWHATDLG_H__E9CE2D40_1840_4BAF_9657_5D6D044A185A__INCLUDED_)
#define AFX_ADDRESSWHATDLG_H__E9CE2D40_1840_4BAF_9657_5D6D044A185A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddressWhatDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddressWhatDlg dialog

class CAddressWhatDlg : public CDialog
{
// Construction
public:
	CAddressWhatDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddressWhatDlg)
	enum { IDD = IDD_ADR_WHAT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressWhatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddressWhatDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRESSWHATDLG_H__E9CE2D40_1840_4BAF_9657_5D6D044A185A__INCLUDED_)
