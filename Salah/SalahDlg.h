// SalahDlg.h : header file
//

#if !defined(AFX_SALAHDLG_H__0038B0AD_CED9_4CC0_A516_4CE22035CCB0__INCLUDED_)
#define AFX_SALAHDLG_H__0038B0AD_CED9_4CC0_A516_4CE22035CCB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSalahDlg dialog

class CSalahDlg : public CDialog
{
// Construction
public:
	CSalahDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSalahDlg)
	enum { IDD = IDD_SALAH_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSalahDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSalahDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonWeltkarteOeffnen();
	afx_msg void OnButtonGebetszeitenErrechnen();
	afx_msg void OnButtonGebetszeiten();
	afx_msg void OnButtonTabelleSpeichern();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SALAHDLG_H__0038B0AD_CED9_4CC0_A516_4CE22035CCB0__INCLUDED_)
