// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__52ECDADA_A104_45D3_8C9F_696544CD8C1B__INCLUDED_)
#define AFX_DLGPROXY_H__52ECDADA_A104_45D3_8C9F_696544CD8C1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUPXGuyDlg;

/////////////////////////////////////////////////////////////////////////////
// CUPXGuyDlgAutoProxy command target

class CUPXGuyDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CUPXGuyDlgAutoProxy)

	CUPXGuyDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CUPXGuyDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUPXGuyDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CUPXGuyDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CUPXGuyDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CUPXGuyDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CUPXGuyDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__52ECDADA_A104_45D3_8C9F_696544CD8C1B__INCLUDED_)
