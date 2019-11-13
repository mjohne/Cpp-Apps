// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__B995D122_3D5F_46D5_8B21_77E533EA549E__INCLUDED_)
#define AFX_DLGPROXY_H__B995D122_3D5F_46D5_8B21_77E533EA549E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStarCalcDlg;

/////////////////////////////////////////////////////////////////////////////
// CStarCalcDlgAutoProxy command target

class CStarCalcDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CStarCalcDlgAutoProxy)

	CStarCalcDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CStarCalcDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarCalcDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CStarCalcDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CStarCalcDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CStarCalcDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CStarCalcDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__B995D122_3D5F_46D5_8B21_77E533EA549E__INCLUDED_)
