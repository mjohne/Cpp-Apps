// OptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ayat Finder.h"
#include "OptionsDlg.h"
#include <io.h>
#include "XZip.h"
#include "XUnzip.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog


COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDlg::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(COptionsDlg)
	m_checkCaseSensitive = FALSE;
	m_checkWordsOnly = FALSE;
	m_strInformation = _T("");
	//}}AFX_DATA_INIT
}


void COptionsDlg::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDlg)
	DDX_Control(pDX, IDC_CHECK_SURA, m_btnSuraCheck);
	DDX_Control(pDX, IDC_LIST_SURA, m_listSura);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_LIST_QURAN, m_listQuran);
	DDX_Check(pDX, IDC_CHECK_CASESENS, m_checkCaseSensitive);
	DDX_Check(pDX, IDC_CHECK_WORDSONLY, m_checkWordsOnly);
	DDX_Text(pDX, IDC_EDIT_INFO, m_strInformation);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
	//{{AFX_MSG_MAP(COptionsDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST_QURAN, OnClickListQuran)
	ON_NOTIFY(NM_SETFOCUS, IDC_LIST_QURAN, OnSetfocusListQuran)
	ON_BN_CLICKED(IDC_CHECK_SURA, OnCheckSura)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COptionsDlg, CDialog)
	//{{AFX_DISPATCH_MAP(COptionsDlg)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOptionsDlg to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {0AF6CAF6-5319-4303-9812-AA60A6C19DC4}
static const IID IID_IOptionsDlg =
{ 0xaf6caf6, 0x5319, 0x4303, { 0x98, 0x12, 0xaa, 0x60, 0xa6, 0xc1, 0x9d, 0xc4 } };

BEGIN_INTERFACE_MAP(COptionsDlg, CDialog)
	INTERFACE_PART(COptionsDlg, IID_IOptionsDlg, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg message handlers

BOOL COptionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  //m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.SetIcon(IDI_ICON_CHECK16);
  //m_btnOK.DrawAsToolbar(true);
  m_btnOK.DrawFlatFocus(false);
  //m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText(IDS_BTN_OK);
	
  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  //m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.SetIcon(IDI_ICON_CROSS16);
  //m_btnCancel.DrawAsToolbar(true);
  m_btnCancel.DrawFlatFocus(false);
  //m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText(IDS_BTN_ABORT);

  m_btnSuraCheck.SetThemeHelper(&m_ThemeHelper);
  //m_btnSuraCheck.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSuraCheck.SetIcon(IDI_ICON_ASTERIK16);
  //m_btnSuraCheck.DrawAsToolbar(true);
  m_btnSuraCheck.DrawFlatFocus(false);
  //m_btnSuraCheck.EnableBalloonTooltip();
  m_btnSuraCheck.SetTooltipText("");
  m_btnSuraCheck.SetCheck(1);

  m_listQuran.SetExtendedStyle(LVS_EX_CHECKBOXES + LVS_EX_GRIDLINES + LVS_EX_FULLROWSELECT + LVS_EX_INFOTIP);
  m_listQuran.InsertColumn(0,"Koran-Übersetzungen",LVCFMT_LEFT,300,-1);
  
  for (int i = 0; i < FilenameList.GetSize(); i++)
  {
    m_listQuran.InsertItem(0,FilenameList.GetAt(FilenameList.GetUpperBound()-i));
  }

  for (i = 0; i < FilenameList.GetSize(); i++)
  {
    m_listQuran.SetCheck(i);
  }

  m_listSura.SetExtendedStyle(LVS_EX_CHECKBOXES + LVS_EX_GRIDLINES + LVS_EX_FULLROWSELECT + LVS_EX_INFOTIP);
  m_listSura.InsertColumn(0,"Suren-Auswahl",LVCFMT_LEFT,170,-1);
 
  for (i = 0; i < SuraList.GetSize(); i++)
  {
    m_listSura.InsertItem(0,SuraList.GetAt(SuraList.GetUpperBound()-i));
  }
  
  for (i = 0; i < SuraList.GetSize(); i++)
  {
    m_listSura.SetCheck(i);
  }
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptionsDlg::OnOK() 
{
  for (int i = 0; i < FilenameList.GetSize(); i++)
  {
    if (m_listQuran.GetCheck(i))
    {
      FilenameListUsed.Add(FilenameList.GetAt(i));
    }
  }
  for (i = 0; i < SuraList.GetSize(); i++)
  {
    if (m_listSura.GetCheck(i))
    {
      SuraListUsed.Add(SuraList.GetAt(i));
    } else SuraListUsed.Add("");
  }
	CDialog::OnOK();
}

void COptionsDlg::OnClickListQuran(NMHDR* pNMHDR, LRESULT* pResult) 
{
  CStringArray strZipContent;
  strZipContent.Add("index.txt");
 
  #ifdef _UNICODE
	  ZIPENTRYW ze;
  #else
    ZIPENTRY ze; 
  #endif
  memset(&ze,0,sizeof(ze));

  char szTempPath[MAX_PATH] = {0};
  GetTempPath(MAX_PATH,szTempPath);

  CString strTemp = CString(szTempPath)+_T("\\");
  CString strRow,strTempPath,strTemp2;
  if (m_listQuran.GetFirstSelectedItemPosition() != NULL)
  {
    CString strZipfileName = FilenameList.GetAt((int)m_listQuran.GetFirstSelectedItemPosition()-1);

    int index = 0;
    ZRESULT zr;
    MSG msg;

    CStdioFile fFile;

    m_strInformation.Empty();
    UpdateData(false);

    TCHAR * pszArchive = _T(strZipfileName.LockBuffer());
	  HZIP hz = OpenZip(pszArchive,0,ZIP_FILENAME);
    if (hz) 
    {
      strTempPath = strTemp+strZipContent.GetAt(0);
      TCHAR * pszZipItem = _T(strTempPath.LockBuffer());
      zr = FindZipItem(hz,strZipContent.GetAt(0),false,&index,&ze);
      if (zr == ZR_OK)
      {
        zr = UnzipItem(hz,index,pszZipItem,0,ZIP_FILENAME);
        if (zr == ZR_OK)
        {
          SetFileAttributes(pszZipItem,FILE_ATTRIBUTE_NORMAL);
          if (!fFile.Open(strTempPath,CFile::modeRead | CFile::typeText))
          {
            #ifdef _DEBUG
              afxDump << "Unable to open file" << "\n";
            #endif
          } else {
            while (fFile.ReadString(strRow) || (!strRow.IsEmpty()))
            {
              while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
              {
                TranslateMessage(&msg);
	              DispatchMessage(&msg);
              }
              strRow = strRow+"\r\n";
              m_strInformation += strRow;
            }
          }  
          fFile.Close();
          ::DeleteFile(strTempPath);
        }
      }
    }
    CloseZip(hz);
    UpdateData(false);
  }
  *pResult = 0;
}

void COptionsDlg::OnSetfocusListQuran(NMHDR* pNMHDR, LRESULT* pResult) 
{
  CStringArray strZipContent;
  strZipContent.Add("index.txt");
 
  #ifdef _UNICODE
	  ZIPENTRYW ze;
  #else
    ZIPENTRY ze; 
  #endif
  memset(&ze,0,sizeof(ze));

  char szTempPath[MAX_PATH] = {0};
  GetTempPath(MAX_PATH,szTempPath);

  CString strTemp = CString(szTempPath)+"\\";
  CString strRow,strTempPath,strTemp2;
  if (m_listQuran.GetFirstSelectedItemPosition() != NULL)
  {
    CString strZipfileName = FilenameList.GetAt((int)m_listQuran.GetFirstSelectedItemPosition()-1);

    int index = 0;
    ZRESULT zr;
    MSG msg;

    CStdioFile fFile;

    m_strInformation.Empty();
    UpdateData(false);

    TCHAR * pszArchive = _T(strZipfileName.LockBuffer());
	  HZIP hz = OpenZip(pszArchive,0,ZIP_FILENAME);
    if (hz) 
    {
      strTempPath = strTemp+strZipContent.GetAt(0);
      TCHAR * pszZipItem = _T(strTempPath.LockBuffer());
      zr = FindZipItem(hz,strZipContent.GetAt(0),false,&index,&ze);
      if (zr == ZR_OK)
      {
        zr = UnzipItem(hz,index,pszZipItem,0,ZIP_FILENAME);
        if (zr == ZR_OK)
        {
          SetFileAttributes(pszZipItem,FILE_ATTRIBUTE_NORMAL);
          if (!fFile.Open(strTempPath,CFile::modeRead | CFile::typeText))
          {
            #ifdef _DEBUG
              afxDump << "Unable to open file" << "\n";
            #endif
          } else {
            while (fFile.ReadString(strRow) || (!strRow.IsEmpty()))
            {
              while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
              {
                TranslateMessage(&msg);
	              DispatchMessage(&msg);
              }
              strRow = strRow+"\r\n";
              m_strInformation += strRow;
            }
          }  
          fFile.Close();
          ::DeleteFile(strTempPath);
        }
      }
    }
    CloseZip(hz);
    UpdateData(false);
  }
	
	*pResult = 0;
}

void COptionsDlg::OnCheckSura() 
{
	if (m_btnSuraCheck.GetCheck() == 0)
  {
    for (int i = 0; i < SuraList.GetSize(); i++)
    {
      m_listSura.SetCheck(i);
    }
  } else if (m_btnSuraCheck.GetCheck() == 1){
    for (int i = 0; i < SuraList.GetSize(); i++)
    {
      m_listSura.SetCheck(i);
    }
  }
}
