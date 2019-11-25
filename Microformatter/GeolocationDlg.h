#if !defined(AFX_GEOLOCATIONDLG_H__32AFDCA7_3F16_40D4_87AC_B9B543DDD9B0__INCLUDED_)
#define AFX_GEOLOCATIONDLG_H__32AFDCA7_3F16_40D4_87AC_B9B543DDD9B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GeolocationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGeolocationDlg dialog

class CGeolocationDlg : public CDialog
{
// Construction
public:
	CGeolocationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGeolocationDlg)
	enum { IDD = IDD_GEO };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGeolocationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGeolocationDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GEOLOCATIONDLG_H__32AFDCA7_3F16_40D4_87AC_B9B543DDD9B0__INCLUDED_)
