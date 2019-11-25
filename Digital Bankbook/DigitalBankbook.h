// DigitalBankbook.h : main header file for the DigitalBankbook application
//

#if !defined(AFX_DIGITALBANKBOOK_H__04BE0077_4D12_40DF_9D81_297EA2855B00__INCLUDED_)
#define AFX_DIGITALBANKBOOK_H__04BE0077_4D12_40DF_9D81_297EA2855B00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDigitalBankbookApp:
// See DigitalBankbook.cpp for the implementation of this class
//

class CDigitalBankbookApp : public CWinApp
{
public:
	CDigitalBankbookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDigitalBankbookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDigitalBankbookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIGITALBANKBOOK_H__04BE0077_4D12_40DF_9D81_297EA2855B00__INCLUDED_)
