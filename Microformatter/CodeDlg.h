#if !defined(AFX_CodeDlg_H__06F11E4D_3852_4370_A26D_3BA368DD48C8__INCLUDED_)
#define AFX_CodeDlg_H__06F11E4D_3852_4370_A26D_3BA368DD48C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CodeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCodeDlg dialog

class CCodeDlg : public CDialog
{
// Construction
public:
	CCodeDlg(CWnd* pParent = NULL);   // standard constructor
  CString m_strCodeCompact;

// Dialog Data
	//{{AFX_DATA(CCodeDlg)
	enum { IDD = IDD_CODE };
	CString	m_strCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCodeDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CodeDlg_H__06F11E4D_3852_4370_A26D_3BA368DD48C8__INCLUDED_)
