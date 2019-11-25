// UPXGuy.h : main header file for the UPXGUY application
//

#if !defined(AFX_UPXGUY_H__83A025BC_DC91_46C0_B212_5EC5ADA8835B__INCLUDED_)
#define AFX_UPXGUY_H__83A025BC_DC91_46C0_B212_5EC5ADA8835B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUPXGuyApp:
// See UPXGuy.cpp for the implementation of this class
//

class CUPXGuyApp : public CWinApp
{
public:
	CUPXGuyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUPXGuyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUPXGuyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPXGUY_H__83A025BC_DC91_46C0_B212_5EC5ADA8835B__INCLUDED_)
