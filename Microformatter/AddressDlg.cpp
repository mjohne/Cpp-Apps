// AddressDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Microformatter.h"
#include "AddressDlg.h"
#include "AddressWhatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddressDlg dialog


CAddressDlg::CAddressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddressDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddressDlg)
	m_strStreetAddress = _T("");
	m_strRegion = _T("");
	m_strPostOfficeBox = _T("");
	m_strPostalCode = _T("");
	m_strLocality = _T("");
	m_strExtendedAddress = _T("");
	m_strCountryName = _T("");
	//}}AFX_DATA_INIT
}


void CAddressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddressDlg)
	DDX_Control(pDX, IDC_COMBO_ELEMENTTEMPLATE, m_cmbxElementTemplate);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_cmbxType);
	DDX_Text(pDX, IDC_EDIT_STREETADDRESS, m_strStreetAddress);
	DDX_Text(pDX, IDC_EDIT_REGION, m_strRegion);
	DDX_Text(pDX, IDC_EDIT_POSTOFFICEBOX, m_strPostOfficeBox);
	DDX_Text(pDX, IDC_EDIT_POSTALCODE, m_strPostalCode);
	DDX_Text(pDX, IDC_EDIT_LOCALITY, m_strLocality);
	DDX_Text(pDX, IDC_EDIT_EXTENDEDADDRESS, m_strExtendedAddress);
	DDX_Text(pDX, IDC_EDIT_COUNTRYNAME, m_strCountryName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddressDlg, CDialog)
	//{{AFX_MSG_MAP(CAddressDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADR_WHAT, OnButtonAdrWhat)
	ON_CBN_SELCHANGE(IDC_COMBO_ELEMENTTEMPLATE, OnSelchangeComboElementTemplate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddressDlg message handlers

BOOL CAddressDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_cmbxElementTemplate.SetCurSel(0);
  m_cmbxType.SetCurSel(0);
  
  UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddressDlg::OnButtonAdrWhat() 
{
	CAddressWhatDlg dlgAddressWhat;
  dlgAddressWhat.DoModal();
}

void CAddressDlg::OnSelchangeComboElementTemplate() 
{
	int nID = m_cmbxElementTemplate.GetCurSel();

  UpdateData(false);
}


