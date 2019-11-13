#if !defined(AFX_LSCEDITDLG_H__42D0213C_113B_499B_BF48_C7B34D246328__INCLUDED_)
#define AFX_LSCEDITDLG_H__42D0213C_113B_499B_BF48_C7B34D246328__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LscEditDlg.h : header file
//

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
	

/////////////////////////////////////////////////////////////////////////////
// CLscEditDlg dialog

class CLscEditDlg : public CDialog
{
// Construction
public:
	CLscEditDlg(CWnd* pParent = NULL);   // standard constructor
	CMatrix<UINT> *m_arrHeightfield;
	CButtonST m_btnRouteUp;
	CButtonST m_btnRouteDown;
	CButtonST m_btnRouteLeft;
	CButtonST m_btnRouteRight;
	CXPStyleButtonST m_btnRaise;
	CXPStyleButtonST m_btnFlat;
	CXPStyleButtonST m_btnRotateLeft;
	CXPStyleButtonST m_btnRotateRight;
	CXPStyleButtonST m_btnOK;
	CXPStyleButtonST m_btnAbort;
	CXPStyleButtonST m_btnInvert;
	CXPStyleButtonST m_btnGlaciate;
	CXPStyleButtonST m_btnMirrorHorizontal;
	CXPStyleButtonST m_btnMirrorVertical;
  CThemeHelperST m_ThemeHelper;

// Dialog Data
	//{{AFX_DATA(CLscEditDlg)
	enum { IDD = IDD_DIALOG_LSC_EDIT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLscEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLscEditDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LSCEDITDLG_H__42D0213C_113B_499B_BF48_C7B34D246328__INCLUDED_)
