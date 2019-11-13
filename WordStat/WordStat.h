// WordStat.h : main header file for the WORDSTAT application
//

#if !defined(AFX_WORDSTAT_H__2D7156C5_902F_4F84_AC3C_6B8B0E4F0ED8__INCLUDED_)
#define AFX_WORDSTAT_H__2D7156C5_902F_4F84_AC3C_6B8B0E4F0ED8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWordStatApp:
// See WordStat.cpp for the implementation of this class
//

class CWordStatApp : public CWinApp
{
public:
	CWordStatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordStatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation
	//{{AFX_MSG(CWordStatApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDSTAT_H__2D7156C5_902F_4F84_AC3C_6B8B0E4F0ED8__INCLUDED_)
