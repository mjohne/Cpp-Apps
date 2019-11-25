// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__C25287DA_E091_4050_B8A9_A4E5FAE9A358__INCLUDED_)
#define AFX_DLGPROXY_H__C25287DA_E091_4050_B8A9_A4E5FAE9A358__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFmwRSSDlg;

/////////////////////////////////////////////////////////////////////////////
// CFmwRSSDlgAutoProxy command target

class CFmwRSSDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CFmwRSSDlgAutoProxy)

	CFmwRSSDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CFmwRSSDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFmwRSSDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFmwRSSDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CFmwRSSDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CFmwRSSDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CFmwRSSDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__C25287DA_E091_4050_B8A9_A4E5FAE9A358__INCLUDED_)
