// GrafMath.h : main header file for the GRAFMATH application
//

#if !defined(AFX_GRAFMATH_H__2AD6F394_21DD_42F0_B7D8_C86F2A1587D7__INCLUDED_)
#define AFX_GRAFMATH_H__2AD6F394_21DD_42F0_B7D8_C86F2A1587D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGrafMathApp:
// See GrafMath.cpp for the implementation of this class
//

class CGrafMathApp : public CWinApp
{
public:
	CGrafMathApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGrafMathApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGrafMathApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAFMATH_H__2AD6F394_21DD_42F0_B7D8_C86F2A1587D7__INCLUDED_)
