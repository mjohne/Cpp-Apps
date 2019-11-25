// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "UPXGuy.h"
#include "DlgProxy.h"
#include "UPXGuyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUPXGuyDlgAutoProxy

IMPLEMENT_DYNCREATE(CUPXGuyDlgAutoProxy, CCmdTarget)

CUPXGuyDlgAutoProxy::CUPXGuyDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CUPXGuyDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CUPXGuyDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CUPXGuyDlgAutoProxy::~CUPXGuyDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CUPXGuyDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CUPXGuyDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CUPXGuyDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CUPXGuyDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CUPXGuyDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IUPXGuy to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {164FA0CF-910F-471F-88B3-2258211CB978}
static const IID IID_IUPXGuy =
{ 0x164fa0cf, 0x910f, 0x471f, { 0x88, 0xb3, 0x22, 0x58, 0x21, 0x1c, 0xb9, 0x78 } };

BEGIN_INTERFACE_MAP(CUPXGuyDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CUPXGuyDlgAutoProxy, IID_IUPXGuy, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {0BC18076-7549-40C0-B0F2-B51765F870EA}
IMPLEMENT_OLECREATE2(CUPXGuyDlgAutoProxy, "UPXGuy.Application", 0xbc18076, 0x7549, 0x40c0, 0xb0, 0xf2, 0xb5, 0x17, 0x65, 0xf8, 0x70, 0xea)

/////////////////////////////////////////////////////////////////////////////
// CUPXGuyDlgAutoProxy message handlers
