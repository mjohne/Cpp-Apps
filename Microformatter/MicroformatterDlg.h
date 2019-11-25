// MicroformatterDlg.h : header file
//

#if !defined(AFX_MICROFORMATTERDLG_H__25C082EF_A072_40EA_BD54_47D68EF979F0__INCLUDED_)
#define AFX_MICROFORMATTERDLG_H__25C082EF_A072_40EA_BD54_47D68EF979F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMicroformatterDlg dialog

class CMicroformatterDlg : public CDialog
{
// Construction
public:
	CMicroformatterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMicroformatterDlg)
	enum { IDD = IDD_MICROFORMATTER_DIALOG };
	CTabCtrl	m_tcRegister;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMicroformatterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMicroformatterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtonExit();
	afx_msg void OnButtonCreate();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonCopy();
	afx_msg void OnButtonPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
   CAddressDlg m_dlg_Address;
   CCodeDlg m_dlg_Code;
   CGeolocationDlg m_dlg_Geolocation;
   ChAtomDlg m_dlg_hAtom;
   ChCalenderDlg m_dlg_hCalender;
   ChCardDlg m_dlg_hCard;
   ChResumeDlg m_dlg_hResume;
   ChReviewDlg m_dlg_hReview;
   CrelTagDlg m_dlg_relTag;
   CXFNDlg m_dlg_XFN;
   CxFolkDlg m_dlg_xFolk;

private:
	void UpdateVisibleWindow();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MICROFORMATTERDLG_H__25C082EF_A072_40EA_BD54_47D68EF979F0__INCLUDED_)

