// CharacterConverter.h : main header file for the CHARACTERCONVERTER application
//

#if !defined(AFX_CHARACTERCONVERTER_H__596EACAF_D585_4035_A94A_E3F681E7A6BA__INCLUDED_)
#define AFX_CHARACTERCONVERTER_H__596EACAF_D585_4035_A94A_E3F681E7A6BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCharacterConverterApp:
// See CharacterConverter.cpp for the implementation of this class
//

class CCharacterConverterApp : public CWinApp
{
public:
	CCharacterConverterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharacterConverterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCharacterConverterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARACTERCONVERTER_H__596EACAF_D585_4035_A94A_E3F681E7A6BA__INCLUDED_)
