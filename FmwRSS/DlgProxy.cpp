// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "FmwRSS.h"
#include "DlgProxy.h"
#include "FmwRSSDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFmwRSSDlgAutoProxy

IMPLEMENT_DYNCREATE(CFmwRSSDlgAutoProxy, CCmdTarget)

CFmwRSSDlgAutoProxy::CFmwRSSDlgAutoProxy()
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
	ASSERT_KINDOF(CFmwRSSDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CFmwRSSDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CFmwRSSDlgAutoProxy::~CFmwRSSDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CFmwRSSDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CFmwRSSDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CFmwRSSDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFmwRSSDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CFmwRSSDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IFmwRSS to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {EF0BA5A2-9105-471D-952F-4B77E80E5759}
static const IID IID_IFmwRSS =
{ 0xef0ba5a2, 0x9105, 0x471d, { 0x95, 0x2f, 0x4b, 0x77, 0xe8, 0xe, 0x57, 0x59 } };

BEGIN_INTERFACE_MAP(CFmwRSSDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CFmwRSSDlgAutoProxy, IID_IFmwRSS, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {530A1A2C-A468-44A1-84B0-B5E87627FD2A}
IMPLEMENT_OLECREATE2(CFmwRSSDlgAutoProxy, "FmwRSS.Application", 0x530a1a2c, 0xa468, 0x44a1, 0x84, 0xb0, 0xb5, 0xe8, 0x76, 0x27, 0xfd, 0x2a)

/////////////////////////////////////////////////////////////////////////////
// CFmwRSSDlgAutoProxy message handlers
