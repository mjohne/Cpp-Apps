#if !defined(AFX_GRAPHICOUTPUTDLG_H__03D08568_3E29_45CE_899E_A123A61F4532__INCLUDED_)
#define AFX_GRAPHICOUTPUTDLG_H__03D08568_3E29_45CE_899E_A123A61F4532__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GraphicOutputDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"
#include "BCMenu.h"

/////////////////////////////////////////////////////////////////////////////
// CGraphicOutputDlg dialog

class CGraphicOutputDlg : public CDialog
{
// Construction
public:
	CGraphicOutputDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGraphicOutputDlg)
	enum { IDD = IDD_DIALOG_GRAPHIC_OUTPUT };
	CXPStyleButtonST	m_btnAppOptions;
	CXPStyleButtonST	m_btnSaveGraphic;
	CXPStyleButtonST	m_btnPrintGraphic;
        CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST	m_btnCourse;
	CXPStyleButtonST	m_btnDCDiff;
	CXPStyleButtonST	m_btnDCRatio;
	CXPStyleButtonST	m_btnTimescaleBackward;
	CXPStyleButtonST	m_btnTimescaleBegin;
	CXPStyleButtonST	m_btnTimescaleEnd;
	CXPStyleButtonST	m_btnTimescaleForward;
	CXPStyleButtonST	m_btnCancel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphicOutputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGraphicOutputDlg)
	afx_msg void OnButtonTimescaleBegin();
	afx_msg void OnButtonTimescaleBackward();
	afx_msg void OnButtonTimescaleForward();
	afx_msg void OnButtonTimescaleEnd();
	afx_msg void OnButtonCourse();
	afx_msg void OnButtonDcdiff();
	afx_msg void OnButtonDcratio();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonGraphicPrint();
	afx_msg void OnButtonGraphicSave();
	afx_msg void OnButtonAppOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHICOUTPUTDLG_H__03D08568_3E29_45CE_899E_A123A61F4532__INCLUDED_)
