// Salah.h : main header file for the SALAH application
//

#if !defined(AFX_SALAH_H__0439A852_FA38_46AE_9A1D_2CAC8B282B0D__INCLUDED_)
#define AFX_SALAH_H__0439A852_FA38_46AE_9A1D_2CAC8B282B0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSalahApp:
// See Salah.cpp for the implementation of this class
//

class CSalahApp : public CWinApp
{
public:
	CSalahApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSalahApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSalahApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SALAH_H__0439A852_FA38_46AE_9A1D_2CAC8B282B0D__INCLUDED_)
