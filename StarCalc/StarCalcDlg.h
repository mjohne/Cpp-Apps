// StarCalcDlg.h : header file
//

#if !defined(AFX_STARCALCDLG_H__1DB1C95B_F86F_4B4F_B064_5ACD9830D56F__INCLUDED_)
#define AFX_STARCALCDLG_H__1DB1C95B_F86F_4B4F_B064_5ACD9830D56F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStarCalcDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CStarCalcDlg dialog

class CStarCalcDlg : public CDialog
{
	DECLARE_DYNAMIC(CStarCalcDlg);
	friend class CStarCalcDlgAutoProxy;

// Construction
public:
	CStarCalcDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CStarCalcDlg();

// Dialog Data
	//{{AFX_DATA(CStarCalcDlg)
	enum { IDD = IDD_STARCALC_DIALOG };
	CButton	m_btnCalc;
	double m_Parallax;
	double m_MagnitudeVisual;
	double m_Distance;
	double m_Density;
	double m_Luminosity;
	double m_MagnitudeAbsolute;
	double m_Mass;
	double m_MagnitudeBolometric;
	CString	m_SpectralType;
	double m_TemperatureEffective;
	double	m_Radius;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarCalcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CStarCalcDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CStarCalcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnChangeEditParallax();
	afx_msg void OnChangeEditMvis();
	afx_msg void OnButtonCalc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARCALCDLG_H__1DB1C95B_F86F_4B4F_B064_5ACD9830D56F__INCLUDED_)
