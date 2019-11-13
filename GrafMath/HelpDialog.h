#if !defined(AFX_HELPDIALOG_H__6A48D7EB_EA31_45F8_A5D2_18D3EB831E14__INCLUDED_)
#define AFX_HELPDIALOG_H__6A48D7EB_EA31_45F8_A5D2_18D3EB831E14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HelpDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHelpDialog dialog

class CHelpDialog : public CDialog
{
// Construction
public:
	CHelpDialog(CWnd* pParent = NULL,UINT RtfId = 0);   // standard constructor

	BOOL LoadRTFFile(CString RTFFileName);
	BOOL IsTopMost();
	void SetTopMost(BOOL value = TRUE);
	void SetTitle(CString title = "Help");

// Dialog Data
	//{{AFX_DATA(CHelpDialog)
	enum { IDD = IDD_HELP_DIALOG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelpDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	HICON			m_hIcon;
	CRichEditCtrl	m_RichEdit;

	// Generated message map functions
	//{{AFX_MSG(CHelpDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditCopy();
	afx_msg void OnPopupHelpPrint();
	afx_msg void OnFileKeephelpontopOntop();
	afx_msg void OnFileKeephelpontopNotontop();
	afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

    virtual BOOL OnWndMsg( UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult );

private:
	CString m_Msg;
	BOOL	m_bFileLoaded;		// set if RTF is loaded from file instead from resource
	BOOL	m_bOnTop;			// set if Help Dialog is On Top (default)
	CString m_strTitle;			// Title of Help Window
	UINT	m_ID;				// RTF resource ID
	CSize	m_dimMsg;			// message dimension (pixels)
	void	PrintTopic();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELPDIALOG_H__6A48D7EB_EA31_45F8_A5D2_18D3EB831E14__INCLUDED_)
