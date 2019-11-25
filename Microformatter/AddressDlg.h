#if !defined(AFX_AddressDLG_H__32AFDCA7_3F16_40D4_87AC_B9B543DDD9B0__INCLUDED_)
#define AFX_AddressDLG_H__32AFDCA7_3F16_40D4_87AC_B9B543DDD9B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddressDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddressDlg dialog

class CAddressDlg : public CDialog
{
// Construction
public:
	CAddressDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddressDlg)
	enum { IDD = IDD_ADR };
	CComboBox	m_cmbxElementTemplate;
	CComboBox	m_cmbxType;
	CString	m_strStreetAddress;
	CString	m_strRegion;
	CString	m_strPostOfficeBox;
	CString	m_strPostalCode;
	CString	m_strLocality;
	CString	m_strExtendedAddress;
	CString	m_strCountryName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddressDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddressDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdrWhat();
	afx_msg void OnSelchangeComboElementTemplate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AddressDLG_H__32AFDCA7_3F16_40D4_87AC_B9B543DDD9B0__INCLUDED_)
