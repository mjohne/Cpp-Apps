// Matrix.h : main header file for the MATRIX application
//

#if !defined(AFX_MATRIX_H__ED501A05_7791_11D4_8FE3_0050DA4E6A7A__INCLUDED_)
#define AFX_MATRIX_H__ED501A05_7791_11D4_8FE3_0050DA4E6A7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMatrixApp:
// See Matrix.cpp for the implementation of this class
//

class CMatrixApp : public CWinApp
{
public:
	CMatrixApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMatrixApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMatrixApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATRIX_H__ED501A05_7791_11D4_8FE3_0050DA4E6A7A__INCLUDED_)
