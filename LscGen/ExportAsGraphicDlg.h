#if !defined(AFX_EXPORTASGRAPHICDLG_H__883B49C7_EA9D_4B24_896B_E4A5B8D5DAAC__INCLUDED_)
#define AFX_EXPORTASGRAPHICDLG_H__883B49C7_EA9D_4B24_896B_E4A5B8D5DAAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExportAsGraphicDlg.h : header file

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"

/////////////////////////////////////////////////////////////////////////////
// CExportAsGraphicDlg dialog

class CExportAsGraphicDlg : public CDialog
{
// Construction
public:
  CMatrix<UINT> *m_arrHeightfield;
  UINT m_uintSizeX;
  UINT m_uintSizeY;
	CExportAsGraphicDlg(CWnd* pParent = NULL);   // standard constructor
	CXPStyleButtonST m_btnExportAsPGM;
	CXPStyleButtonST m_btnExportAsRAW;
	CXPStyleButtonST m_btnExportAsXPM;
  CThemeHelperST m_ThemeHelper;

// Dialog Data
	//{{AFX_DATA(CExportAsGraphicDlg)
	enum { IDD = IDD_DIALOG_EXPORTAS_GRAPHIC };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExportAsGraphicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExportAsGraphicDlg)
	afx_msg void OnButtonExportAsPgm();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPORTASGRAPHICDLG_H__883B49C7_EA9D_4B24_896B_E4A5B8D5DAAC__INCLUDED_)
