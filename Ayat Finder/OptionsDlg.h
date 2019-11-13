#if !defined(AFX_OPTIONSDLG_H__1E755AA5_69EA_4D22_9679_B78A6D9645E8__INCLUDED_)
#define AFX_OPTIONSDLG_H__1E755AA5_69EA_4D22_9679_B78A6D9645E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsDlg.h : header file
//

#include "BCMenu.h"
#include "HyperLink.h"
#include "ThemeHelperST.h"
#include "XPStyleButtonST.h"
#include "XPTabCtrl.h"
#include "XZip.h"

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog

class COptionsDlg : public CDialog
{
// Construction
public:
	COptionsDlg(CWnd* pParent = NULL);   // standard constructor
 	CStringArray FilenameList;
  CStringArray FilenameListUsed;
 	CStringArray SuraList;
  CStringArray SuraListUsed;

// Dialog Data
	//{{AFX_DATA(COptionsDlg)
	enum { IDD = IDD_DIALOG_OPTIONS };
	CListCtrl	m_listSura;
	CXPStyleButtonST	m_btnOK;
	CXPStyleButtonST	m_btnSuraCheck;
	CXPStyleButtonST	m_btnCancel;
	CListCtrl	m_listQuran;
	BOOL	m_checkCaseSensitive;
	BOOL	m_checkWordsOnly;
	CString	m_strInformation;
	CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsDlg)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptionsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnClickListQuran(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusListQuran(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownListQuran(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCheckSura();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COptionsDlg)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSDLG_H__1E755AA5_69EA_4D22_9679_B78A6D9645E8__INCLUDED_)
