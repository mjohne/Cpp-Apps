// Ayat FinderDlg.h : header file
//

#if !defined(AFX_AYATFINDERDLG_H__7D4B0D18_208E_4576_A00E_E71E6E623751__INCLUDED_)
#define AFX_AYATFINDERDLG_H__7D4B0D18_208E_4576_A00E_E71E6E623751__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AutoRichEditCtrl.h"
#include "BCMenu.h"
#include "HyperLink.h"
#include "ResizableDialog.h"
#include "ThemeHelperST.h"
#include "XPStyleButtonST.h"
#include "XPTabCtrl.h"
#include "XZip.h"

class CAyatFinderDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CAyatFinderDlg dialog

class CAyatFinderDlg : public CResizableDialog
{
	DECLARE_DYNAMIC(CAyatFinderDlg);
	friend class CAyatFinderDlgAutoProxy;

// Construction
public:
	CAyatFinderDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CAyatFinderDlg();

// Dialog Data
	//{{AFX_DATA(CAyatFinderDlg)
	enum { IDD = IDD_AYATFINDER_DIALOG };
	CAutoRichEditCtrl	m_richeditResult;
	CEdit	m_editResult;
	CStatic	m_stcAyatFound;
	CStatic	m_stcPercent;
	CXPStyleButtonST	m_btnInfo;
	CXPStyleButtonST	m_btnExit;
	CXPStyleButtonST	m_btnSearchAbort;
	CXPStyleButtonST	m_btnSave;
	CXPStyleButtonST	m_btnOptions;
	CXPStyleButtonST	m_btnFind;
	CStatic	m_aniIcon;
	CProgressCtrl	m_prgsState;
	CString	m_strKeyword;
	CString	m_strQuran;
	CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAyatFinderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	boolean m_bCaseSensitive;
	boolean m_bFindOnlyWord;
	boolean m_bSearching;
	CStringArray FilenameList;
	CStringArray FilenameListUsed;
	CStringArray SuraList;
	CStringArray SuraListUsed;
	CFileFind FileFinder;
	CAyatFinderDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;
	int	m_iCurIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CAyatFinderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonFind();
	afx_msg void OnButtonOption();
	afx_msg void OnButtonSave();
	afx_msg void OnSetfocusEditKeyword();
	afx_msg void OnUpdateEditKeyword();
	afx_msg void OnSetfocusEditResult();
	afx_msg void OnUpdateEditResult();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonSearchAbort();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnButtonInfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AYATFINDERDLG_H__7D4B0D18_208E_4576_A00E_E71E6E623751__INCLUDED_)
