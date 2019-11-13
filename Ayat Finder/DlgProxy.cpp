// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Ayat Finder.h"
#include "DlgProxy.h"
#include "Ayat FinderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAyatFinderDlgAutoProxy

IMPLEMENT_DYNCREATE(CAyatFinderDlgAutoProxy, CCmdTarget)

CAyatFinderDlgAutoProxy::CAyatFinderDlgAutoProxy()
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
	ASSERT_KINDOF(CAyatFinderDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CAyatFinderDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CAyatFinderDlgAutoProxy::~CAyatFinderDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CAyatFinderDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CAyatFinderDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CAyatFinderDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAyatFinderDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CAyatFinderDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IAyatFinder to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D26DEB44-EA16-4D36-B7D3-2ECE4DF6A471}
static const IID IID_IAyatFinder =
{ 0xd26deb44, 0xea16, 0x4d36, { 0xb7, 0xd3, 0x2e, 0xce, 0x4d, 0xf6, 0xa4, 0x71 } };

BEGIN_INTERFACE_MAP(CAyatFinderDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CAyatFinderDlgAutoProxy, IID_IAyatFinder, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {09C50B09-C22B-448B-B72D-87138C4D8DFC}
IMPLEMENT_OLECREATE2(CAyatFinderDlgAutoProxy, "AyatFinder.Application", 0x9c50b09, 0xc22b, 0x448b, 0xb7, 0x2d, 0x87, 0x13, 0x8c, 0x4d, 0x8d, 0xfc)

/////////////////////////////////////////////////////////////////////////////
// CAyatFinderDlgAutoProxy message handlers
