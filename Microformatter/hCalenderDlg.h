#if !defined(AFX_hCalenderDlg_H__3FEC428F_4575_4746_98D8_B6120B3AE757__INCLUDED_)
#define AFX_hCalenderDlg_H__3FEC428F_4575_4746_98D8_B6120B3AE757__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hCalenderDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ChCalenderDlg dialog

class ChCalenderDlg : public CDialog
{
// Construction
public:
	ChCalenderDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ChCalenderDlg)
	enum { IDD = IDD_HCALENDER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChCalenderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ChCalenderDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_hCalenderDlg_H__3FEC428F_4575_4746_98D8_B6120B3AE757__INCLUDED_)
