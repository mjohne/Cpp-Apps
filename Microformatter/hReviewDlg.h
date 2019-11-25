#if !defined(AFX_HREVIEWDLG_H__BC765727_E4F3_4802_9322_3DA9EEB526B0__INCLUDED_)
#define AFX_HREVIEWDLG_H__BC765727_E4F3_4802_9322_3DA9EEB526B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hReviewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ChReviewDlg dialog

class ChReviewDlg : public CDialog
{
// Construction
public:
	ChReviewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ChReviewDlg)
	enum { IDD = IDD_HREVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChReviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ChReviewDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HREVIEWDLG_H__BC765727_E4F3_4802_9322_3DA9EEB526B0__INCLUDED_)
