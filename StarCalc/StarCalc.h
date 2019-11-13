// StarCalc.h : main header file for the STARCALC application
//

#if !defined(AFX_STARCALC_H__F7104FEE_777B_49BF_A333_462B29C589B3__INCLUDED_)
#define AFX_STARCALC_H__F7104FEE_777B_49BF_A333_462B29C589B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStarCalcApp:
// See StarCalc.cpp for the implementation of this class
//

class CStarCalcApp : public CWinApp
{
public:
	CStarCalcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarCalcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStarCalcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARCALC_H__F7104FEE_777B_49BF_A333_462B29C589B3__INCLUDED_)
