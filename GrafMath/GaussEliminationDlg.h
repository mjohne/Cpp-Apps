#if !defined(AFX_GAUSSELIMINATIONDLG_H__F82627F5_C238_4C48_8B31_DFB157F47C9D__INCLUDED_)
#define AFX_GAUSSELIMINATIONDLG_H__F82627F5_C238_4C48_8B31_DFB157F47C9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"

// GaussEliminationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGaussEliminationDlg dialog

class CGaussEliminationDlg : public CDialog
{
// Construction
public:
	CGaussEliminationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGaussEliminationDlg)
	enum { IDD = IDD_DIALOG_GAUSSELIM };
	CXPStyleButtonST	m_btnSetCoefficients;
	CXPStyleButtonST	m_btnCalc;
	int		m_nNumberOfEquations;
  CThemeHelperST m_ThemeHelper;
	float	m_fResultX1;
	float	m_fResultX2;
	float	m_fResultX3;
	float	m_fResultX4;
	float	m_fResultX5;
	float	m_fCoefficientA11;
	float	m_fCoefficientA12;
	float	m_fCoefficientA13;
	float	m_fCoefficientA14;
	float	m_fCoefficientA15;
	float	m_fCoefficientA21;
	float	m_fCoefficientA22;
	float	m_fCoefficientA23;
	float	m_fCoefficientA24;
	float	m_fCoefficientA25;
	float	m_fCoefficientA31;
	float	m_fCoefficientA32;
	float	m_fCoefficientA33;
	float	m_fCoefficientA34;
	float	m_fCoefficientA35;
	float	m_fCoefficientA41;
	float	m_fCoefficientA42;
	float	m_fCoefficientA43;
	float	m_fCoefficientA44;
	float	m_fCoefficientA45;
	float	m_fCoefficientA51;
	float	m_fCoefficientA52;
	float	m_fCoefficientA53;
	float	m_fCoefficientA54;
	float	m_fCoefficientA55;
	float	m_fCoefficientB1;
	float	m_fCoefficientB2;
	float	m_fCoefficientB3;
	float	m_fCoefficientB4;
	float	m_fCoefficientB5;
	//}}AFX_DATA

private:
  float m_fResultX[10];
  float m_fCoefficientA[10][10];
  float m_fCoefficientB[10];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaussEliminationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGaussEliminationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonCalc();
	afx_msg void OnButtonSetCoefficients();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// Helper functions
void	EnableThemeDialogTexture(HWND hwndDlg);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAUSSELIMINATIONDLG_H__F82627F5_C238_4C48_8B31_DFB157F47C9D__INCLUDED_)
