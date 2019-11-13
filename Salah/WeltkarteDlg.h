#if !defined(AFX_WELTKARTEDLG_H__8EC0C5CB_301A_40B5_B94F_76474B284D2F__INCLUDED_)
#define AFX_WELTKARTEDLG_H__8EC0C5CB_301A_40B5_B94F_76474B284D2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WeltkarteDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWeltkarteDlg dialog

class CWeltkarteDlg : public CDialog
{
// Construction
public:
	CWeltkarteDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWeltkarteDlg)
	enum { IDD = IDD_DIALOG_WELTKARTE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeltkarteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWeltkarteDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WELTKARTEDLG_H__8EC0C5CB_301A_40B5_B94F_76474B284D2F__INCLUDED_)
