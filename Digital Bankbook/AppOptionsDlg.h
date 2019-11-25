#if !defined(AFX_APPOPTIONSDLG_H__97EF62AC_D1E0_4E06_8399_94C8C510404E__INCLUDED_)
#define AFX_APPOPTIONSDLG_H__97EF62AC_D1E0_4E06_8399_94C8C510404E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AppOptionsDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"
#include "BCMenu.h"

/////////////////////////////////////////////////////////////////////////////
// CAppOptionsDlg dialog

class CAppOptionsDlg : public CDialog
{
// Construction
public:
	CAppOptionsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAppOptionsDlg)
	enum { IDD = IDD_DIALOG_APPOPTIONS };
        CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST	m_btnOK;
	CXPStyleButtonST	m_btnCancel;
	BOOL	m_cbtnAppOptionsAxisDescription;
	BOOL	m_cbtnAppOptionsBGArea;
	BOOL	m_cbtnAppOptionsHelpaxis;
	BOOL	m_cbtnAppOptionsLegend;
	BOOL	m_cbtnAppOptionsMainaxis;
	BOOL	m_cbtnAppOptionsScale100;
	BOOL	m_cbtnAppOptionsTitle;
	int		m_rbtnSave;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppOptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAppOptionsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPOPTIONSDLG_H__97EF62AC_D1E0_4E06_8399_94C8C510404E__INCLUDED_)
