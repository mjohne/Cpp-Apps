#if !defined(AFX_HRESUME_H__3C9B6E07_394D_4B85_B68E_B44D61CC389F__INCLUDED_)
#define AFX_HRESUME_H__3C9B6E07_394D_4B85_B68E_B44D61CC389F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hResume.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ChResume dialog

class ChResumeDlg : public CDialog
{
// Construction
public:
	ChResumeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ChResumeDlg)
	enum { IDD = IDD_HRESUME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChResumeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ChResumeDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HRESUME_H__3C9B6E07_394D_4B85_B68E_B44D61CC389F__INCLUDED_)
