#if !defined(AFX_HCARDDLG_H__041FFEDA_2E24_4FED_B292_520FD7651939__INCLUDED_)
#define AFX_HCARDDLG_H__041FFEDA_2E24_4FED_B292_520FD7651939__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hCardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ChCardDlg dialog

class ChCardDlg : public CDialog
{
// Construction
public:
	ChCardDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ChCardDlg)
	enum { IDD = IDD_HCARD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChCardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ChCardDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCARDDLG_H__041FFEDA_2E24_4FED_B292_520FD7651939__INCLUDED_)
