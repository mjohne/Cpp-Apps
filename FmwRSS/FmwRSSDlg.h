// FmwRSSDlg.h : header file
//

#if !defined(AFX_FMWRSSDLG_H__C3CD5A6C_9C8A_42E8_B465_AC7F0269A53F__INCLUDED_)
#define AFX_FMWRSSDLG_H__C3CD5A6C_9C8A_42E8_B465_AC7F0269A53F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"

class CFmwRSSDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CFmwRSSDlg dialog

class CFmwRSSDlg : public CDialog
{
	DECLARE_DYNAMIC(CFmwRSSDlg);
	friend class CFmwRSSDlgAutoProxy;

// Construction
public:
	CFmwRSSDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CFmwRSSDlg();

// Dialog Data
	//{{AFX_DATA(CFmwRSSDlg)
	enum { IDD = IDD_FMWRSS_DIALOG };
	CListCtrl	m_lstNews;
	CTreeCtrl	m_treeFeeds;
	CButton	m_stcView;
	CButton	m_stcNews;
	CButton	m_stcFeed;
	CXPStyleButtonST m_btnAboutApp;
	CXPStyleButtonST m_btnViewAll;
	CXPStyleButtonST m_btnViewNoFeeds;
	CXPStyleButtonST m_btnViewNoNews;
	CXPStyleButtonST m_btnViewNoView;
	CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST m_btnCancel;
	CXPStyleButtonST m_btnUpdateNow;
	CXPStyleButtonST m_btnSetOptions;
	CXPStyleButtonST m_btnAddFeed;
	CXPStyleButtonST m_btnEditFeed;
	CXPStyleButtonST m_btnDeleteFeed;
	CXPStyleButtonST m_btnImportOPML;
	CXPStyleButtonST m_btnExportAsOPML;
	CXPStyleButtonST m_btnAddGroup;
	CXPStyleButtonST m_btnDeleteGroup;
	CXPStyleButtonST m_btnEditGroup;
	CString	m_strView;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFmwRSSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CFmwRSSDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CFmwRSSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonGroupNew();
	afx_msg void OnButtonGroupEdit();
	afx_msg void OnButtonGroupDelete();
	afx_msg void OnButtonFeedNew();
	afx_msg void OnButtonFeedEdit();
	afx_msg void OnButtonFeedDelete();
	afx_msg void OnButtonOpmlImport();
	afx_msg void OnButtonOpmlExport();
	afx_msg void OnButtonUpdateNow();
	afx_msg void OnButtonOptions();
	afx_msg void OnButtonView0();
	afx_msg void OnButtonView23();
	afx_msg void OnButtonView13();
	afx_msg void OnButtonView12();
	afx_msg void OnFileExit();
	afx_msg void OnFileFeedDelete();
	afx_msg void OnFileFeedEdit();
	afx_msg void OnFileFeedNew();
	afx_msg void OnFileGroupDelete();
	afx_msg void OnFileGroupEdit();
	afx_msg void OnFileGroupNew();
	afx_msg void OnFileOpmlExport();
	afx_msg void OnFileOpmlImport();
	afx_msg void OnMiscOptions();
	afx_msg void OnMiscUpdateFeedsNow();
	afx_msg void OnWindowAll();
	afx_msg void OnWindowNoFeeds();
	afx_msg void OnWindowNoNews();
	afx_msg void OnWindowNoView();
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  CImageList m_imageList;
	CRect m_rctWindowRect,m_rctWindowRectFrame;
	CRect m_rctLayoutFeedsRect,m_rctLayoutFeedsRectFrame;
	CRect m_rctLayoutNewsRect,m_rctLayoutNewsRectFrame;
	CRect m_rctLayoutViewRect,m_rctLayoutViewRectFrame;
  CPoint m_cpLayoutFeedsLeft,m_cpLayoutFeedsRight;
	CPoint m_cpLayoutNewsLeft,m_cpLayoutNewsRight;
	CPoint m_cpLayoutViewLeft,m_cpLayoutViewRight;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FMWRSSDLG_H__C3CD5A6C_9C8A_42E8_B465_AC7F0269A53F__INCLUDED_)
