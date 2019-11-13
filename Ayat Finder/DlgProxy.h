// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__8254D3A5_CB85_48CE_8AB9_EECF8EBE418C__INCLUDED_)
#define AFX_DLGPROXY_H__8254D3A5_CB85_48CE_8AB9_EECF8EBE418C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAyatFinderDlg;

/////////////////////////////////////////////////////////////////////////////
// CAyatFinderDlgAutoProxy command target

class CAyatFinderDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CAyatFinderDlgAutoProxy)

	CAyatFinderDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CAyatFinderDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAyatFinderDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAyatFinderDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CAyatFinderDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CAyatFinderDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CAyatFinderDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__8254D3A5_CB85_48CE_8AB9_EECF8EBE418C__INCLUDED_)
