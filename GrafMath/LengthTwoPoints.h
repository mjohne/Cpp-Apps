#if !defined(AFX_LENGTHTWOPOINTS_H__0B84086C_3923_4842_85A8_228C85FC4080__INCLUDED_)
#define AFX_LENGTHTWOPOINTS_H__0B84086C_3923_4842_85A8_228C85FC4080__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LengthTwoPoints.h : header file
//


#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "HyperLink.h"
#include "XPTabCtrl.h"


/////////////////////////////////////////////////////////////////////////////
// CLengthTwoPoints dialog

class CLengthTwoPoints : public CDialog
{
// Construction
public:
	CLengthTwoPoints(CWnd* pParent = NULL);   // standard constructor
	CArray<float,float> m_arrFunction;
  float GetYofFunction(float x);

// Dialog Data
	//{{AFX_DATA(CLengthTwoPoints)
	enum { IDD = IDD_DIALOG_LEN2P };
	CXPStyleButtonST	m_btnY2;
	CXPStyleButtonST	m_btnY1;
	CXPStyleButtonST	m_btnCancel;
	CXPStyleButtonST	m_btnCalc;
  CThemeHelperST m_ThemeHelper;
	float	m_fLength2Points;
	float	m_fP1X;
	float	m_fP2X;
	float	m_fP1Y;
	float	m_fP2Y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLengthTwoPoints)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLengthTwoPoints)
	afx_msg void OnButtonCalc();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonGetY1();
	afx_msg void OnButtonGetY2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// Helper functions
void	EnableThemeDialogTexture(HWND hwndDlg);

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LENGTHTWOPOINTS_H__0B84086C_3923_4842_85A8_228C85FC4080__INCLUDED_)
