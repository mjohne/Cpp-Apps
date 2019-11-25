// FmwRSS.h : main header file for the FMWRSS application
//

#if !defined(AFX_FMWRSS_H__31470C39_0D7E_4571_8FB3_83F67AD64800__INCLUDED_)
#define AFX_FMWRSS_H__31470C39_0D7E_4571_8FB3_83F67AD64800__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFmwRSSApp:
// See FmwRSS.cpp for the implementation of this class
//

class CFmwRSSApp : public CWinApp
{
public:
	CFmwRSSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFmwRSSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFmwRSSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FMWRSS_H__31470C39_0D7E_4571_8FB3_83F67AD64800__INCLUDED_)
