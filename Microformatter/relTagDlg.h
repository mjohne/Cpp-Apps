#if !defined(AFX_RELTAGDLG_H__1AABF33D_4B99_4F47_9088_F2915AFAB70B__INCLUDED_)
#define AFX_RELTAGDLG_H__1AABF33D_4B99_4F47_9088_F2915AFAB70B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// relTagDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CrelTagDlg dialog

class CrelTagDlg : public CDialog
{
// Construction
public:
	CrelTagDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CrelTagDlg)
	enum { IDD = IDD_RELTAG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CrelTagDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CrelTagDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RELTAGDLG_H__1AABF33D_4B99_4F47_9088_F2915AFAB70B__INCLUDED_)
