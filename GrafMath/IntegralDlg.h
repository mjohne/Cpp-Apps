#if !defined(AFX_INTEGRALDLG_H__C9687E26_7B4E_487A_996B_D2FC04A4F34E__INCLUDED_)
#define AFX_INTEGRALDLG_H__C9687E26_7B4E_487A_996B_D2FC04A4F34E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IntegralDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIntegralDlg dialog

class CIntegralDlg : public CDialog
{
// Construction
public:
	CIntegralDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIntegralDlg)
	enum { IDD = IDD_DIALOG_INTEGRAL };
	CButton	m_btnCalc;
	float	m_fXMax;
	float	m_fXMin;
	float	m_fArea;
	int		m_rbtnXDistriction;
	int		m_rbtnYDistriction;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIntegralDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIntegralDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonCalc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTEGRALDLG_H__C9687E26_7B4E_487A_996B_D2FC04A4F34E__INCLUDED_)
