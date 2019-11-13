// LscGenDlg.h : header file
//

#if !defined(AFX_LSCGENDLG_H__48172850_31AA_4589_ABB6_11DB00C7C477__INCLUDED_)
#define AFX_LSCGENDLG_H__48172850_31AA_4589_ABB6_11DB00C7C477__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"

/////////////////////////////////////////////////////////////////////////////
// CLscGenDlg dialog

class CLscGenDlg : public CDialog
{
// Construction
public:
	CMatrix<UINT> *m_arrHeightfield;
	CLscGenDlg(CWnd* pParent = NULL);	// standard constructor
	CXPStyleButtonST m_btnLscNew;
	CXPStyleButtonST m_btnLscLoad;
	CXPStyleButtonST m_btnLscSave;
	CXPStyleButtonST m_btnLscClose;
	CXPStyleButtonST m_btnLscEdit;
	CXPStyleButtonST m_btnExportAsModel;
	CXPStyleButtonST m_btnExportAsGraphic;
	CXPStyleButtonST m_btnExportAsSQL;
	CXPStyleButtonST m_btnAppAbout;
	CXPStyleButtonST m_btnAppExit;
  CThemeHelperST m_ThemeHelper;

// Dialog Data
	//{{AFX_DATA(CLscGenDlg)
	enum { IDD = IDD_LSCGEN_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLscGenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLscGenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAppExit();
	afx_msg void OnButtonAppAbout();
	afx_msg void OnButtonLscNew();
	afx_msg void OnButtonLscClose();
	afx_msg void OnButtonLscEdit();
	afx_msg void OnButtonExportAsModel();
	afx_msg void OnButtonExportAsGraphic();
	afx_msg void OnButtonExportAsSQL();
	afx_msg void OnButtonLscSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LSCGENDLG_H__48172850_31AA_4589_ABB6_11DB00C7C477__INCLUDED_)
