#if !defined(AFX_AXISOPTIONSDLG_H__33FF0D07_5959_45AB_8412_BF3718A4F6BC__INCLUDED_)
#define AFX_AXISOPTIONSDLG_H__33FF0D07_5959_45AB_8412_BF3718A4F6BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"

// AxisOptionsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAxisOptionsDlg dialog

class CAxisOptionsDlg : public CDialog
{
// Construction
public:
	CAxisOptionsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAxisOptionsDlg)
	enum { IDD = IDD_DIALOG_AXISOPTIONS };
	CSpinButtonCtrl	m_sbtnHelpAxisWidth;
	CSpinButtonCtrl	m_sbtnDecimalPlaces;
	CSpinButtonCtrl	m_sbtnAxisDivision;
	CXPStyleButtonST	m_btnOK;
	CXPStyleButtonST	m_btnAbbruch;
	CXPStyleButtonST	m_btnDefault;
	int		m_nAxisDivision;
	int		m_nDecimalPlaces;
	BOOL	m_bAxisDescription;
	int		m_nHelpAxisWidth;
  CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAxisOptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAxisOptionsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnChangeEditAxisparts();
	afx_msg void OnButtonDefault();
	afx_msg void OnSetfocusEditAxisparts();
	afx_msg void OnSetfocusEditDecimalparts();
	afx_msg void OnSetfocusEditHelpaxiswidth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Helper functions
void	EnableThemeDialogTexture(HWND hwndDlg);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AXISOPTIONSDLG_H__33FF0D07_5959_45AB_8412_BF3718A4F6BC__INCLUDED_)
