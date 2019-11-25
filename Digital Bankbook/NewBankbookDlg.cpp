// NewBankbookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalBankbook.h"
#include "NewBankbookDlg.h"
#include "NewUserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewBankbookDlg dialog


CNewBankbookDlg::CNewBankbookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewBankbookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewBankbookDlg)
	m_strBankbookDescription = _T("");
	m_strBankbookName = _T("");
	//}}AFX_DATA_INIT
}


void CNewBankbookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewBankbookDlg)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_USER, m_btnUser);
	DDX_Control(pDX, IDC_BUTTON_BANKBOOK_CREATE, m_btnCreateBankbook);
	DDX_Text(pDX, IDC_EDIT_BANKBOOK_DESCRIPTION, m_strBankbookDescription);
	DDX_Text(pDX, IDC_EDIT_BANKBOOK_NAME, m_strBankbookName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewBankbookDlg, CDialog)
	//{{AFX_MSG_MAP(CNewBankbookDlg)
	ON_BN_CLICKED(IDC_BUTTON_USER, OnButtonUser)
	ON_BN_CLICKED(IDC_BUTTON_BANKBOOK_CREATE, OnButtonBankbookCreate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewBankbookDlg message handlers

BOOL CNewBankbookDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_btnUser.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnUser.DrawAsToolbar(false);
  m_btnUser.SetThemeHelper(&m_ThemeHelper);
  m_btnUser.EnableBalloonTooltip();
  m_btnUser.SetTooltipText(IDS_USER_ADD);
  m_btnUser.SetIcon(IDI_ICON_BUSINESSMAN_32);

  m_btnCreateBankbook.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCreateBankbook.DrawAsToolbar(false);
  m_btnCreateBankbook.SetThemeHelper(&m_ThemeHelper);
  m_btnCreateBankbook.EnableBalloonTooltip();
  m_btnCreateBankbook.SetTooltipText(IDS_BANKBOOK_CREATE);
  m_btnCreateBankbook.SetIcon(IDI_ICON_CHECK_32);

  m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.DrawAsToolbar(false);
  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText(IDS_CANCEL);
  m_btnCancel.SetIcon(IDI_ICON_DELETE_32);

	m_strUserName = _T("");
	m_strUserPlace = _T("");
	m_strUserStreet = _T("");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewBankbookDlg::OnButtonUser() 
{
  CNewUserDlg dlgNewUser;
	dlgNewUser.m_strUserName = m_strUserName;
	dlgNewUser.m_strUserPlace = m_strUserPlace;
	dlgNewUser.m_strUserStreet = m_strUserStreet;
  dlgNewUser.DoModal();
	m_strUserName = dlgNewUser.m_strUserName;
	m_strUserPlace = dlgNewUser.m_strUserPlace;
	m_strUserStreet = dlgNewUser.m_strUserStreet;
}

void CNewBankbookDlg::OnButtonBankbookCreate() 
{
  UpdateData(true);
	if (m_strBankbookName.IsEmpty())	
  {
    MessageBox(_T("Geben Sie eine Bezeichnung für das digitale Sparbuch an!"),_T("Bezeichnung fehlt"), MB_OK | MB_ICONSTOP);
  }
  else if (m_strUserName.IsEmpty() || m_strUserPlace.IsEmpty() || m_strUserStreet.IsEmpty())	
  {
    if (MessageBox(_T("Es wurden unvollständige Angaben über einen Sparbuch-Inhaber\ngefunden. Es wird empfohlen, die Informationen komplett anzulegen.\n\nMöchten Sie trotzdem weitermachen?"),_T("Sparbuch-Inhaber fehlt"), MB_YESNO | MB_ICONWARNING) == IDYES)
    {
      CString strFilter = _T("Digital Bankbook (*.dbb)|*.dbb|");
      strFilter += _T("Alle Dateien (*.*)|*.*|");
	    CFileDialog dlgBankbookFile(false,NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,strFilter,NULL);
      dlgBankbookFile.m_ofn.lpstrTitle = _T("Als digitales Sparbuch speichern");
      //dlgBankbookFile.m_ofn.lpstrFileTitle = LPCTSTR(m_strBankbookName);
      if (dlgBankbookFile.DoModal())
      {
        // Datei erstellen hier!!!
        CDialog::OnOK();
      }      
    }
  } else  {
    CString strFilter = _T("Digital Bankbook (*.dbb)|*.dbb|");
    strFilter += _T("Alle Dateien (*.*)|*.*|");
    CFileDialog dlgBankbookFile(false,NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,strFilter,NULL);
    dlgBankbookFile.m_ofn.lpstrTitle = _T("Als digitales Sparbuch speichern");
    //dlgBankbookFile.m_ofn.lpstrFileTitle = LPCTSTR(m_strBankbookName);
    if (dlgBankbookFile.DoModal())
    {
      // Datei erstellen hier!!!
      CDialog::OnOK();
    }      
  }
}

void CNewBankbookDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
