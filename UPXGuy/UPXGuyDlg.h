// UPXGuyDlg.h : header file
//

#if !defined(AFX_UPXGUYDLG_H__C7312A4D_D58E_4B0F_BF81_2B501C012B97__INCLUDED_)
#define AFX_UPXGUYDLG_H__C7312A4D_D58E_4B0F_BF81_2B501C012B97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUPXGuyDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CUPXGuyDlg dialog

class CUPXGuyDlg : public CDialog
{
	DECLARE_DYNAMIC(CUPXGuyDlg);
	friend class CUPXGuyDlgAutoProxy;

// Construction
public:
	CUPXGuyDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CUPXGuyDlg();

// Dialog Data
	//{{AFX_DATA(CUPXGuyDlg)
	enum { IDD = IDD_UPXGUY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUPXGuyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CUPXGuyDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CUPXGuyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UPXGUYDLG_H__C7312A4D_D58E_4B0F_BF81_2B501C012B97__INCLUDED_)
