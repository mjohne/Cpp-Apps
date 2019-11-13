// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "StarCalc.h"
#include "DlgProxy.h"
#include "StarCalcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStarCalcDlgAutoProxy

IMPLEMENT_DYNCREATE(CStarCalcDlgAutoProxy, CCmdTarget)

CStarCalcDlgAutoProxy::CStarCalcDlgAutoProxy()
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
	ASSERT_KINDOF(CStarCalcDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CStarCalcDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CStarCalcDlgAutoProxy::~CStarCalcDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CStarCalcDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CStarCalcDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CStarCalcDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CStarCalcDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CStarCalcDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IStarCalc to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {9001C50D-9796-4F8A-93E1-DD3224EB5102}
static const IID IID_IStarCalc =
{ 0x9001c50d, 0x9796, 0x4f8a, { 0x93, 0xe1, 0xdd, 0x32, 0x24, 0xeb, 0x51, 0x2 } };

BEGIN_INTERFACE_MAP(CStarCalcDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CStarCalcDlgAutoProxy, IID_IStarCalc, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {F4A40C0F-6D75-46C8-85E3-CB2589DAE43B}
IMPLEMENT_OLECREATE2(CStarCalcDlgAutoProxy, "StarCalc.Application", 0xf4a40c0f, 0x6d75, 0x46c8, 0x85, 0xe3, 0xcb, 0x25, 0x89, 0xda, 0xe4, 0x3b)

/////////////////////////////////////////////////////////////////////////////
// CStarCalcDlgAutoProxy message handlers
