// NewUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalBankbook.h"
#include "NewUserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewUserDlg dialog


CNewUserDlg::CNewUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewUserDlg)
	m_strUserName = _T("");
	m_strUserPlace = _T("");
	m_strUserStreet = _T("");
	//}}AFX_DATA_INIT
}


void CNewUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewUserDlg)
	DDX_Control(pDX, IDC_BUTTON_VCARDEXPORT, m_btnExportAsVCard);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_USER_BIRTHDATE, m_dtUserBirthday);
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_strUserName);
	DDX_Text(pDX, IDC_EDIT_USER_PLACE, m_strUserPlace);
	DDX_Text(pDX, IDC_EDIT_USER_STREET, m_strUserStreet);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewUserDlg, CDialog)
	//{{AFX_MSG_MAP(CNewUserDlg)
	ON_BN_CLICKED(IDC_BUTTON_VCARDEXPORT, OnButtonVCardExport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewUserDlg message handlers

BOOL CNewUserDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.DrawAsToolbar(false);
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText(IDS_USER_ADD);
  m_btnOK.SetIcon(IDI_ICON_CHECK_32);

  m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.DrawAsToolbar(false);
  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText(IDS_CANCEL);
  m_btnCancel.SetIcon(IDI_ICON_DELETE_32);
	
  m_btnExportAsVCard.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsVCard.DrawAsToolbar(false);
  m_btnExportAsVCard.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsVCard.EnableBalloonTooltip();
  m_btnExportAsVCard.SetTooltipText(IDS_VCARD_EXPORT);
  m_btnExportAsVCard.SetIcon(IDI_ICON_IDCARD_32);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CNewUserDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CNewUserDlg::OnButtonVCardExport() 
{
  UpdateData(true);
  if (m_strUserName.IsEmpty() || m_strUserPlace.IsEmpty() || m_strUserStreet.IsEmpty())	
  {
    if (MessageBox(_T("Es wurden unvollständige Angaben über einen Sparbuch-Inhaber\ngefunden. Es wird empfohlen, die Informationen komplett anzulegen.\n\nMöchten Sie trotzdem weitermachen?"),_T("Sparbuch-Inhaber fehlt"), MB_YESNO | MB_ICONWARNING) == IDYES)
    {
      CString strFilter = _T("VCard (*.vcd)|*.vcd|");
      strFilter += _T("Alle Dateien (*.*)|*.*|");
	    CFileDialog dlgVCardFile(false,NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,strFilter,NULL);
      dlgVCardFile.m_ofn.lpstrTitle = _T("Als VCard speichern");
      if (dlgVCardFile.DoModal() == IDOK)
      {
        // Datei erstellen hier!!!
        CDialog::OnOK();
      }      
    }
  } else {
    CString strFilter = _T("VCard (*.vcd)|*.vcd|");
    strFilter += _T("Alle Dateien (*.*)|*.*|");
    CFileDialog dlgVCardFile(false,NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,strFilter,NULL);
    dlgVCardFile.m_ofn.lpstrTitle = _T("Als VCard speichern");
    if (dlgVCardFile.DoModal() == IDOK)
    {
      // Datei erstellen hier!!!
      CDialog::OnOK();
    }      
  }
}
