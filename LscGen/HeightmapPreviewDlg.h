#if !defined(AFX_HEIGHTMAPPREVIEWDLG_H__33FFC41C_98A6_4BD8_8EB3_E4D2AAF95757__INCLUDED_)
#define AFX_HEIGHTMAPPREVIEWDLG_H__33FFC41C_98A6_4BD8_8EB3_E4D2AAF95757__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HeightmapPreviewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHeightmapPreviewDlg dialog

class CHeightmapPreviewDlg : public CDialog
{
// Construction
public:
	CHeightmapPreviewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHeightmapPreviewDlg)
	enum { IDD = IDD_DIALOG_HM_PREVIEW };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHeightmapPreviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHeightmapPreviewDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEIGHTMAPPREVIEWDLG_H__33FFC41C_98A6_4BD8_8EB3_E4D2AAF95757__INCLUDED_)
