#if !defined(AFX_EXPORTASMODELDLG_H__D6D49AC4_D597_4192_B6C1_C89379B4D1E7__INCLUDED_)
#define AFX_EXPORTASMODELDLG_H__D6D49AC4_D597_4192_B6C1_C89379B4D1E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExportAsModelDlg.h : header file
//


#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"


/////////////////////////////////////////////////////////////////////////////
// CExportAsModelDlg dialog

class CExportAsModelDlg : public CDialog
{
// Construction
public:
	CExportAsModelDlg(CWnd* pParent = NULL);   // standard constructor
	CXPStyleButtonST m_btnExportAsVRML;
	CXPStyleButtonST m_btnExportAsX3D;
  CThemeHelperST m_ThemeHelper;

// Dialog Data
	//{{AFX_DATA(CExportAsModelDlg)
	enum { IDD = IDD_DIALOG_EXPORTAS_MODEL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExportAsModelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExportAsModelDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPORTASMODELDLG_H__D6D49AC4_D597_4192_B6C1_C89379B4D1E7__INCLUDED_)
