#if !defined(AFX_Tabelle_H__6FE99CF5_8F67_43C7_8009_26E733295F2F__INCLUDED_)
#define AFX_Tabelle_H__6FE99CF5_8F67_43C7_8009_26E733295F2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabelleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabelleDlg dialog

class CTabelleDlg : public CDialog
{
// Construction
public:
	CTabelleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTabelleDlg)
	enum { IDD = IDD_DIALOG_TABELLE_SPEICHERN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabelleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTabelleDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Tabelle_H__6FE99CF5_8F67_43C7_8009_26E733295F2F__INCLUDED_)
