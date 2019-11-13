// Ayat FinderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ayat Finder.h"
#include "Ayat FinderDlg.h"
#include "DlgProxy.h"
#include "OptionsDlg.h"
#include "SaveResultDlg.h"
#include <io.h>
#include "XZip.h"
#include "XUnzip.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CResizableDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CHyperLink	m_stcMyMail;
	CHyperLink m_stcTawhedLink;
	CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST	m_btnOK;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CResizableDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CResizableDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_STATIC_MYMAIL, m_stcMyMail);
	DDX_Control(pDX, IDC_STATIC_TAWHEDLINK, m_stcTawhedLink);
	DDX_Control(pDX, IDOK, m_btnOK);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CResizableDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAyatFinderDlg dialog

IMPLEMENT_DYNAMIC(CAyatFinderDlg, CDialog);


CAyatFinderDlg::CAyatFinderDlg(CWnd* pParent /*=NULL*/)
	: CResizableDialog(CAyatFinderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAyatFinderDlg)
	m_strKeyword = _T("");
	m_strQuran = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CAyatFinderDlg::~CAyatFinderDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

BOOL CAboutDlg::OnInitDialog() 
{
	CResizableDialog::OnInitDialog();
	
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  //m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.SetIcon(IDI_ICON_CHECK16);
  //m_btnOK.DrawAsToolbar(true);
  m_btnOK.DrawFlatFocus(false);
  //m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText(IDS_BTN_OK);
  m_stcTawhedLink.SetURL("http://www.tawhed.de");
  m_stcMyMail.SetURL("mailto:michael-johne@gmx.de");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAyatFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CResizableDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAyatFinderDlg)
	DDX_Control(pDX, IDC_BUTTON_INFO, m_btnInfo);
	DDX_Control(pDX, IDC_RICHEDIT_RESULT, m_richeditResult);
 	DDX_Control(pDX, IDC_STATIC_AYATFOUND, m_stcAyatFound);
	DDX_Control(pDX, IDC_STATIC_PERCENT, m_stcPercent);
	DDX_Control(pDX, IDCANCEL, m_btnExit);
	DDX_Control(pDX, IDC_BUTTON_SEARCHABORT, m_btnSearchAbort);
	DDX_Control(pDX, IDC_BUTTON_SAVE, m_btnSave);
	DDX_Control(pDX, IDC_BUTTON_OPTION, m_btnOptions);
	DDX_Control(pDX, IDC_BUTTON_FIND, m_btnFind);
	DDX_Control(pDX, IDC_ANIICON, m_aniIcon);
	DDX_Control(pDX, IDC_PROGRESS, m_prgsState);
	DDX_Text(pDX, IDC_EDIT_KEYWORD, m_strKeyword);
	DDX_Text(pDX, IDC_STATIC_QURAN, m_strQuran);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAyatFinderDlg, CResizableDialog)
	//{{AFX_MSG_MAP(CAyatFinderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_FIND, OnButtonFind)
	ON_BN_CLICKED(IDC_BUTTON_OPTION, OnButtonOption)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_EN_SETFOCUS(IDC_EDIT_KEYWORD, OnSetfocusEditKeyword)
	ON_EN_UPDATE(IDC_EDIT_KEYWORD, OnUpdateEditKeyword)
	ON_EN_SETFOCUS(IDC_EDIT_RESULT, OnSetfocusEditResult)
	ON_EN_UPDATE(IDC_EDIT_RESULT, OnUpdateEditResult)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_SEARCHABORT, OnButtonSearchAbort)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_INFO, OnButtonInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAyatFinderDlg message handlers

BOOL CAyatFinderDlg::OnInitDialog()
{
	CResizableDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

  m_btnFind.SetThemeHelper(&m_ThemeHelper);
  //m_btnFind.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnFind.SetIcon(IDI_ICON_SEARCH16);
  //m_btnFind.DrawAsToolbar(true);
  m_btnFind.DrawFlatFocus(false);
  //m_btnFind.EnableBalloonTooltip();
  m_btnFind.SetTooltipText(IDS_BTN_FIND);

  m_btnOptions.SetThemeHelper(&m_ThemeHelper);
  //m_btnOptions.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOptions.SetIcon(IDI_ICON_CONFIG16);
  //m_btnOptions.DrawAsToolbar(true);
  m_btnOptions.DrawFlatFocus(false);
  //m_btnOptions.EnableBalloonTooltip();
  m_btnOptions.SetTooltipText(IDS_BTN_CONFIG);

  m_btnSave.SetThemeHelper(&m_ThemeHelper);
  //m_btnSave.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSave.SetIcon(IDI_ICON_SAVE16);
  //m_btnSave.DrawAsToolbar(true);
  m_btnSave.DrawFlatFocus(false);
  //m_btnSave.EnableBalloonTooltip();
  m_btnSave.SetTooltipText(IDS_BTN_SAVERESULT);
  
  m_btnInfo.SetThemeHelper(&m_ThemeHelper);
  //m_btnInfo.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnInfo.SetIcon(IDI_ICON_INFO16);
  //m_btnInfo.DrawAsToolbar(true);
  m_btnInfo.DrawFlatFocus(false);
  //m_btnInfo.EnableBalloonTooltip();
  m_btnInfo.SetTooltipText(IDS_ABOUTBOX);
  
  m_btnSearchAbort.SetThemeHelper(&m_ThemeHelper);
  //m_btnSearchAbort.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSearchAbort.SetIcon(IDI_ICON_CROSS16);
  //m_btnSearchAbort.DrawAsToolbar(true);
  m_btnSearchAbort.DrawFlatFocus(false);
  //m_btnSearchAbort.EnableBalloonTooltip();
  m_btnSearchAbort.SetTooltipText(IDS_BTN_SEARCHABORT);
  
  m_btnExit.SetThemeHelper(&m_ThemeHelper);
  //m_btnExit.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExit.SetIcon(IDI_ICON_EXIT16);
  //m_btnExit.DrawAsToolbar(true);
  m_btnExit.DrawFlatFocus(false);
  //m_btnExit.EnableBalloonTooltip();
  m_btnExit.SetTooltipText(IDS_BTN_EXIT);
  
  AddAnchor(IDC_STATIC_SEARCH,TOP_LEFT,TOP_RIGHT);
  AddAnchor(IDC_EDIT_KEYWORD,TOP_LEFT,TOP_RIGHT);
  AddAnchor(IDC_BUTTON_FIND,TOP_RIGHT,TOP_RIGHT);
  AddAnchor(IDC_BUTTON_OPTION,TOP_RIGHT,TOP_RIGHT);

  AddAnchor(IDC_STATIC_PROCESS,TOP_LEFT,TOP_RIGHT);
  AddAnchor(IDC_PROGRESS,TOP_LEFT,TOP_RIGHT);
  AddAnchor(IDC_STATIC_PERCENT,TOP_RIGHT,TOP_RIGHT);
  AddAnchor(IDC_STATIC_AYATFOUND,TOP_RIGHT,TOP_RIGHT);
  AddAnchor(IDC_ANIICON,TOP_RIGHT,TOP_RIGHT);

  AddAnchor(IDC_STATIC_RESULT,NOANCHOR,BOTTOM_RIGHT);
  AddAnchor(IDC_RICHEDIT_RESULT,NOANCHOR,BOTTOM_RIGHT);
  AddAnchor(IDC_BUTTON_SAVE,BOTTOM_LEFT,BOTTOM_LEFT);
  AddAnchor(IDC_BUTTON_INFO,BOTTOM_LEFT,BOTTOM_LEFT);
  AddAnchor(IDC_BUTTON_SEARCHABORT,BOTTOM_RIGHT,BOTTOM_RIGHT);
  AddAnchor(IDCANCEL,BOTTOM_RIGHT,BOTTOM_RIGHT);

  boolean bWorking = FileFinder.FindFile(_T("*.quran"));
  while (bWorking)
  {
    bWorking = FileFinder.FindNextFile();
    MSG msg;
	  while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
    {
  		TranslateMessage(&msg);
	  	DispatchMessage(&msg);
    }
    if (FileFinder.IsDirectory()) continue; 
    else {
      FilenameList.Add(FileFinder.GetFileName());
      FilenameListUsed.Add(FileFinder.GetFileName());
    }
  }
  FileFinder.Close();

  if (FilenameList.GetUpperBound() == -1)
  {
    MessageBox(_T("Es wurden keine Koran-Übersetzungen gefunden.\nOhne Koran-Übersetzungen ist das Programm nicht nutzbar.\n\nKopieren Sie bitte mindestens eine Koran-Übersetzungen \nins das aktuelle Programmverzeichnis!"),_T("Keine Koran-Übersetzungen gefunden"),MB_ICONWARNING);
    DestroyWindow();
    return false;
  }

  SuraList.Add("1. Sure (Al-fatiha)");
  SuraList.Add("2. Sure (Al-baqara)");
  SuraList.Add("3. Sure (Aali-'imran)");
  SuraList.Add("4. Sure (An-nisaa)");
  SuraList.Add("5. Sure (Al-maida)");
  SuraList.Add("6. Sure (Al-an'am)");
  SuraList.Add("7. Sure (Al-a'raf)");
  SuraList.Add("8. Sure (Al-anfal)");
  SuraList.Add("9. Sure (At-tauba)");
  SuraList.Add("10. Sure (Yunus)");
  SuraList.Add("11. Sure (Hud)");
  SuraList.Add("12. Sure (Yusuf)");
  SuraList.Add("13. Sure (Ar-ra'd)");
  SuraList.Add("14. Sure (Ibrahim)");
  SuraList.Add("15. Sure (Al-hidschr)");
  SuraList.Add("16. Sure (An-nahl)");
  SuraList.Add("17. Sure (Al-israa)");
  SuraList.Add("18. Sure (Al-kahf)");
  SuraList.Add("19. Sure (Maryam)");
  SuraList.Add("20. Sure (Ta-ha)");
  SuraList.Add("21. Sure (Al-anbiyaa)");
  SuraList.Add("22. Sure (Al-hadsch)");
  SuraList.Add("23. Sure (Al-muminun)");
  SuraList.Add("24. Sure (An-nur)");
  SuraList.Add("25. Sure (Al-furqan)");
  SuraList.Add("26. Sure (Asch-schu'araa)");
  SuraList.Add("27. Sure (An-naml)");
  SuraList.Add("28. Sure (Al-qasas)");
  SuraList.Add("29. Sure (Al-'ankabut)");
  SuraList.Add("30. Sure (Ar-rum)");
  SuraList.Add("31. Sure (Luqman)");
  SuraList.Add("32. Sure (As-sadschda)");
  SuraList.Add("33. Sure (Al-ahzab)");
  SuraList.Add("34. Sure (Sabaa)");
  SuraList.Add("35. Sure (Fatir)");
  SuraList.Add("36. Sure (Ya-sin)");
  SuraList.Add("37. Sure (As-saffat)");
  SuraList.Add("38. Sure (Sad)");
  SuraList.Add("39. Sure (Az-zumar)");
  SuraList.Add("40. Sure (Ghafir)");
  SuraList.Add("41. Sure (Fus-silat)");
  SuraList.Add("42. Sure (Asch-schura)");
  SuraList.Add("43. Sure (Az-zukhruf)");
  SuraList.Add("44. Sure (Ad-dukhan)");
  SuraList.Add("45. Sure (Adsch-dschathiya)");
  SuraList.Add("46. Sure (Al-ahqaf)");
  SuraList.Add("47. Sure (Muhammad)");
  SuraList.Add("48. Sure (Al-fath)");
  SuraList.Add("49. Sure (Al-hudschurat)");
  SuraList.Add("50. Sure (Qaf)");
  SuraList.Add("51. Sure (Az-zariyat)");
  SuraList.Add("52. Sure (At-tur)");
  SuraList.Add("53. Sure (An-nadschm)");
  SuraList.Add("54. Sure (Al-qamar)");
  SuraList.Add("55. Sure (Ar-rahman)");
  SuraList.Add("56. Sure (Al-waqi'a)");
  SuraList.Add("57. Sure (Al-hadid)");
  SuraList.Add("58. Sure (Al-mudschadalah)");
  SuraList.Add("59. Sure (Al-haschr)");
  SuraList.Add("60. Sure (As-saff)");
  SuraList.Add("61. Sure (Adsch-dschumu'a)");
  SuraList.Add("62. Sure (Al-mumtahina)");
  SuraList.Add("63. Sure (Al-munafiqun)");
  SuraList.Add("64. Sure (At-taghabun)");
  SuraList.Add("65. Sure (At-talaq)");
  SuraList.Add("66. Sure (At-tahrim)");
  SuraList.Add("67. Sure (Al-mulk)");
  SuraList.Add("68. Sure (Al-qalam)");
  SuraList.Add("69. Sure (Al-haqqa)");
  SuraList.Add("70. Sure (Al-ma'aridsch)");
  SuraList.Add("71. Sure (Nuh)");
  SuraList.Add("72. Sure (Al-dschin)");
  SuraList.Add("73. Sure (Al-muzzamil)");
  SuraList.Add("74. Sure (Al-muddaththir)");
  SuraList.Add("75. Sure (Al-qiyama)");
  SuraList.Add("76. Sure (Al-insan)");
  SuraList.Add("77. Sure (Al-mursalat)");
  SuraList.Add("78. Sure (An-nabaa)");
  SuraList.Add("79. Sure (An-nazi'at)");
  SuraList.Add("80. Sure (Abasa)");
  SuraList.Add("81. Sure (At-takwir)");
  SuraList.Add("82. Sure (Al-infitar)");
  SuraList.Add("83. Sure (Al-mutaffi-fin)");
  SuraList.Add("84. Sure (Al-inschiqaq)");
  SuraList.Add("85. Sure (Al-burudsch)");
  SuraList.Add("86. Sure (At-tariq)");
  SuraList.Add("87. Sure (Al-'ala)");
  SuraList.Add("88. Sure (Al-ghaschiya)");
  SuraList.Add("89. Sure (Al-fadschr)");
  SuraList.Add("90. Sure (Al-balad)");
  SuraList.Add("91. Sure (Asch-schams)");
  SuraList.Add("92. Sure (Al-lail)");
  SuraList.Add("93. Sure (Ad-duha)");
  SuraList.Add("94. Sure (Asch-scharh)");
  SuraList.Add("95. Sure (At-tin)");
  SuraList.Add("96. Sure (Al-'alaq)");
  SuraList.Add("97. Sure (Al-qadr)");
  SuraList.Add("98. Sure (Al-bayyina)");
  SuraList.Add("99. Sure (Az-zalzala)");
  SuraList.Add("100. Sure (Al-'adiyat)");
  SuraList.Add("101. Sure (Al-qari'a)");
  SuraList.Add("102. Sure (At-takathur)");
  SuraList.Add("103. Sure (Al-'asr)");
  SuraList.Add("104. Sure (Al-humaza)");
  SuraList.Add("105. Sure (Al-fil)");
  SuraList.Add("106. Sure (Quraisch)");
  SuraList.Add("107. Sure (Al-ma'uun)");
  SuraList.Add("108. Sure (Al-kauthar)");
  SuraList.Add("109. Sure (Al-kafirun)");
  SuraList.Add("110. Sure (An-nasr)");
  SuraList.Add("111. Sure (Al-masad)");
  SuraList.Add("112. Sure (Al-ikhlas)");
  SuraList.Add("113. Sure (Al-falaq)");
  SuraList.Add("114. Sure (An-nas)");

  for (int n = 0; n < SuraList.GetSize(); n++)
  {
    SuraListUsed.Add(SuraList.GetAt(n));
  }

	m_bCaseSensitive = false;
	m_bFindOnlyWord = true; 
  m_richeditResult.SetReadOnly();
  m_richeditResult.LimitText(INT_MAX);

  DWORD dwFlag = SND_RESOURCE;
  //::PlaySound(MAKEINTRESOURCE(IDR_WAVE_BISMILLAH),AfxGetResourceHandle(),dwFlag);

  m_btnFind.EnableWindow(false);
  m_btnSave.EnableWindow(false);
  m_btnSearchAbort.EnableWindow(false);


  return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAyatFinderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CResizableDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAyatFinderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CResizableDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAyatFinderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CAyatFinderDlg::OnClose() 
{
	if (CanExit())
		CResizableDialog::OnClose();
}

void CAyatFinderDlg::OnOK() 
{
	if (CanExit())
		CResizableDialog::OnOK();
}

void CAyatFinderDlg::OnCancel() 
{
	if (CanExit())
		CResizableDialog::OnCancel();
}

BOOL CAyatFinderDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CAyatFinderDlg::OnButtonFind() 
{
  GetDlgItem(IDC_BUTTON_SEARCHABORT)->EnableWindow(true);
  GetDlgItem(IDCANCEL)->EnableWindow(false);

  CStringArray strZipContent;
  //strZipContent.Add("index.txt");
  strZipContent.Add("sure001.txt");
  strZipContent.Add("sure002.txt");
  strZipContent.Add("sure003.txt");
  strZipContent.Add("sure004.txt");
  strZipContent.Add("sure005.txt");
  strZipContent.Add("sure006.txt");
  strZipContent.Add("sure007.txt");
  strZipContent.Add("sure008.txt");
  strZipContent.Add("sure009.txt");
  strZipContent.Add("sure010.txt");
  strZipContent.Add("sure011.txt");
  strZipContent.Add("sure012.txt");
  strZipContent.Add("sure013.txt");
  strZipContent.Add("sure014.txt");
  strZipContent.Add("sure015.txt");
  strZipContent.Add("sure016.txt");
  strZipContent.Add("sure017.txt");
  strZipContent.Add("sure018.txt");
  strZipContent.Add("sure019.txt");
  strZipContent.Add("sure020.txt");
  strZipContent.Add("sure021.txt");
  strZipContent.Add("sure022.txt");
  strZipContent.Add("sure023.txt");
  strZipContent.Add("sure024.txt");
  strZipContent.Add("sure025.txt");
  strZipContent.Add("sure026.txt");
  strZipContent.Add("sure027.txt");
  strZipContent.Add("sure028.txt");
  strZipContent.Add("sure029.txt");
  strZipContent.Add("sure030.txt");
  strZipContent.Add("sure031.txt");
  strZipContent.Add("sure032.txt");
  strZipContent.Add("sure033.txt");
  strZipContent.Add("sure034.txt");
  strZipContent.Add("sure035.txt");
  strZipContent.Add("sure036.txt");
  strZipContent.Add("sure037.txt");
  strZipContent.Add("sure038.txt");
  strZipContent.Add("sure039.txt");
  strZipContent.Add("sure040.txt");
  strZipContent.Add("sure041.txt");
  strZipContent.Add("sure042.txt");
  strZipContent.Add("sure043.txt");
  strZipContent.Add("sure044.txt");
  strZipContent.Add("sure045.txt");
  strZipContent.Add("sure046.txt");
  strZipContent.Add("sure047.txt");
  strZipContent.Add("sure048.txt");
  strZipContent.Add("sure049.txt");
  strZipContent.Add("sure050.txt");
  strZipContent.Add("sure051.txt");
  strZipContent.Add("sure052.txt");
  strZipContent.Add("sure053.txt");
  strZipContent.Add("sure054.txt");
  strZipContent.Add("sure055.txt");
  strZipContent.Add("sure056.txt");
  strZipContent.Add("sure057.txt");
  strZipContent.Add("sure058.txt");
  strZipContent.Add("sure059.txt");
  strZipContent.Add("sure060.txt");
  strZipContent.Add("sure061.txt");
  strZipContent.Add("sure062.txt");
  strZipContent.Add("sure063.txt");
  strZipContent.Add("sure064.txt");
  strZipContent.Add("sure065.txt");
  strZipContent.Add("sure066.txt");
  strZipContent.Add("sure067.txt");
  strZipContent.Add("sure068.txt");
  strZipContent.Add("sure069.txt");
  strZipContent.Add("sure070.txt");
  strZipContent.Add("sure071.txt");
  strZipContent.Add("sure072.txt");
  strZipContent.Add("sure073.txt");
  strZipContent.Add("sure074.txt");
  strZipContent.Add("sure075.txt");
  strZipContent.Add("sure076.txt");
  strZipContent.Add("sure077.txt");
  strZipContent.Add("sure078.txt");
  strZipContent.Add("sure079.txt");
  strZipContent.Add("sure080.txt");
  strZipContent.Add("sure081.txt");
  strZipContent.Add("sure082.txt");
  strZipContent.Add("sure083.txt");
  strZipContent.Add("sure084.txt");
  strZipContent.Add("sure085.txt");
  strZipContent.Add("sure086.txt");
  strZipContent.Add("sure087.txt");
  strZipContent.Add("sure088.txt");
  strZipContent.Add("sure089.txt");
  strZipContent.Add("sure090.txt");
  strZipContent.Add("sure091.txt");
  strZipContent.Add("sure092.txt");
  strZipContent.Add("sure093.txt");
  strZipContent.Add("sure094.txt");
  strZipContent.Add("sure095.txt");
  strZipContent.Add("sure096.txt");
  strZipContent.Add("sure097.txt");
  strZipContent.Add("sure098.txt");
  strZipContent.Add("sure099.txt");
  strZipContent.Add("sure100.txt");
  strZipContent.Add("sure101.txt");
  strZipContent.Add("sure102.txt");
  strZipContent.Add("sure103.txt");
  strZipContent.Add("sure104.txt");
  strZipContent.Add("sure105.txt");
  strZipContent.Add("sure106.txt");
  strZipContent.Add("sure107.txt");
  strZipContent.Add("sure108.txt");
  strZipContent.Add("sure109.txt");
  strZipContent.Add("sure110.txt");
  strZipContent.Add("sure111.txt");
  strZipContent.Add("sure112.txt");
  strZipContent.Add("sure113.txt");
  strZipContent.Add("sure114.txt");
 
  #ifdef _UNICODE
	  ZIPENTRYW ze;
  #else
    ZIPENTRY ze; 
  #endif
  memset(&ze,0,sizeof(ze));

  m_editResult.SetWindowText(_T(""));

  char szTempPath[MAX_PATH] = {0};
  GetTempPath(MAX_PATH,szTempPath);
  CString strTemp = CString(szTempPath)+_T("\\");

  int index,nAyatFound = 0;
  m_prgsState.SetRange32(0,strZipContent.GetSize());
  ZRESULT zr;
  MSG msg;
  
  const CString strRTFDocBegin = _T("{\\rtf1\\ansi\\ansicpg1252\\deff0\\deflang1031\\deflangfe2052{\\fonttbl{\\f0\\fswiss\\fprq2\\fcharset0 Arial;}}{\\colortbl ;\\red0\\green0\\blue128;\\red128\\green128\\blue128;\\red0\\green0\\blue0;\\red250\\green190\\blue15;}{\\*\\generator Ayat Finder by Michael Johne;}\\viewkind4\\uc1\\pard\\nowidctlpar\\f0\\fs28");
  const CString strRTFDocEnd   = _T("}");
  const CString strRTFDefaultFormat = _T("\\cf2 ");
  const CString strRTFParagraph = _T("\\par\\par");
  const CString strRTFAyatFormatBegin = _T("\\cf1 \\i ");
  const CString strRTFAyatFormatEnd   = _T("\\i0 ");
  const CString strRTFFoundItemFormatBegin = _T("\\cf3 \\b ");
  const CString strRTFFoundItemFormatEnd   = _T("\\b0 ");
  const CString strRTFFoundWordFormatBegin = _T("\\cf0 \\b ");
  const CString strRTFFoundWordFormatEnd   = _T("\\b0 ");
  const CString strRTFQuranFormat = _T("\\cf4 ");

  CString strRTFDoc,strRTFContent,strRTFContentWordBefore,strRTFContentWordAfter;
  
  CString strRow,strTempPath,strTemp2,strTemp3,strResult,strAyatFound;
  int
    nSura = 0,
    nAya = 0;
  
  CStdioFile fFile;
  
  SetTimer(1,125,NULL);

  m_stcAyatFound.SetWindowText(_T("0 Ayat gefunden"));
  m_bSearching = true;
  if (FilenameListUsed.GetUpperBound() == -1) m_bSearching = false;
  for (int n = 0; n < FilenameListUsed.GetSize(); n++)
  {
    if (m_bSearching == false) break;
    m_prgsState.SetPos(0);
    CString strZipfileName = FilenameListUsed.GetAt(n);
    TCHAR * pszArchive = _T(strZipfileName.LockBuffer());
	  HZIP hz = OpenZip(pszArchive,0,ZIP_FILENAME);
    m_strQuran = strZipfileName;
    UpdateData(false);
    if (hz) 
    {
      nSura = 0;
      for (int i = 0; i < strZipContent.GetSize(); i++)
      {
        nSura++;
        if (!SuraListUsed.GetAt(i).IsEmpty()) 
        {
          if (m_bSearching == false) break;
          strTempPath = strTemp+strZipContent.GetAt(i);
          TCHAR * pszZipItem = _T(strTempPath.LockBuffer());
          zr = FindZipItem(hz,strZipContent.GetAt(i),false,&index,&ze);
          if (zr == ZR_OK)
          {
            zr = UnzipItem(hz,index,pszZipItem,0,ZIP_FILENAME);
            if (zr == ZR_OK)
            {
              SetFileAttributes(pszZipItem,FILE_ATTRIBUTE_NORMAL);
              m_prgsState.SetPos(i);

              strTemp3.Format(_T("%d"),1+i*100/strZipContent.GetSize());
              strTemp3 += _T(" %");
              m_stcPercent.SetWindowText(strTemp3);
	            while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
              {
      		      TranslateMessage(&msg);
	      	      DispatchMessage(&msg);
              }        
              if (!fFile.Open(strTempPath,CFile::modeRead | CFile::typeText))
              {
                #ifdef _DEBUG
                  afxDump << _T("Unable to open file") << _T("\n");
                #endif
              } else {
                nAya = 0;
                while (fFile.ReadString(strRow) || (!strRow.IsEmpty()))
                {
                  nAya++;
                  if (m_bSearching == false) break;
      	          while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
                  {
  		              TranslateMessage(&msg);
	  	              DispatchMessage(&msg);
                  }
                  strTemp2 = strRow; 
	                if (!m_bCaseSensitive)
                  {
                    strTemp2.MakeLower(); 
                    m_strKeyword.MakeLower();
                  }
                  //                  strTemp3 += strTemp2.GetAt(nPos+1);
                  if (strTemp2.Find(m_strKeyword) != -1)
                  {
                    strResult = _T("[Sure ");
                    strTemp3.Format(_T("%d"),nSura);
                    strResult += strTemp3;
                    strResult += _T(" / Aya ");
                    strTemp3.Format(_T("%d"),nAya);
                    strResult += strTemp3;
                    strResult += _T("] ");
                    strRTFContent += strRTFAyatFormatBegin;
                    strRTFContent += strResult;
                    strRTFContent += strRTFAyatFormatEnd;
                    strRTFContent += strRTFDefaultFormat;
                    strResult += strRow;
                      
                    strRTFContentWordBefore = strRow.Left(strTemp2.Find(m_strKeyword));
                    strRTFContentWordAfter  = strRow.Right(strRow.GetLength()-strRTFContentWordBefore.GetLength()-m_strKeyword.GetLength());

                    strRTFContent += strRTFContentWordBefore;//strRow;                      
                    strRTFContent += strRTFFoundWordFormatBegin;
                    strRTFContent += strRow.Mid(strTemp2.Find(m_strKeyword),m_strKeyword.GetLength());
                    strRTFContent += strRTFFoundWordFormatEnd;
                    strRTFContent += strRTFDefaultFormat;
                    strRTFContent += strRTFContentWordAfter;//strRow;

                    strResult += _T("\r\n\r\n");
                    strRTFContent += _T(" (");
                    strRTFContent += strRTFQuranFormat;
                    strRTFContent += FilenameListUsed.GetAt(n);
                    strRTFContent += strRTFDefaultFormat;
                    strRTFContent += _T(")");
                    strRTFContent += strRTFParagraph;
                    strRTFDoc = strRTFDocBegin;
                    strRTFDoc += strRTFContent;
                    strRTFDoc += strRTFDocEnd;
                    m_richeditResult.SetRTF(strRTFDoc);
                      
                    nAyatFound++;
                    strAyatFound.Format(_T("%d"),nAyatFound);
                    strAyatFound += _T(" Ayat gefunden");
                    m_editResult.SetWindowText(strResult);
                    m_stcAyatFound.SetWindowText(strAyatFound);
                    if (m_bSearching == false) break;
                  }  
                }
                fFile.Close();
                ::DeleteFile(strTempPath);
              }
            }
          }      
        }
      }
      CloseZip(hz);
    }
  }
  KillTimer(1);
  if (m_bSearching) MessageBox(_T("Die Suche ist beendet!"),_T(""),MB_OK + MB_ICONINFORMATION);
  m_bSearching = false;
  if (!m_richeditResult.GetWindowTextLength() == 0) m_btnSave.EnableWindow(true);
  m_btnSearchAbort.EnableWindow(false);
  m_btnExit.EnableWindow(true);
}

void CAyatFinderDlg::OnButtonOption() 
{
	COptionsDlg dlgOptions;
  
  for (int i = 0; i < FilenameList.GetSize(); i++)
  {
    dlgOptions.FilenameList.Add(FilenameList.GetAt(i));
  }

  for (i = 0; i < SuraList.GetSize(); i++)
  {
    dlgOptions.SuraList.Add(SuraList.GetAt(i));
  }

  dlgOptions.m_checkCaseSensitive = m_bCaseSensitive;
  dlgOptions.m_checkWordsOnly = m_bFindOnlyWord;
  if (dlgOptions.DoModal() == IDOK)
  {
    m_bCaseSensitive = dlgOptions.m_checkCaseSensitive;
    m_bFindOnlyWord = dlgOptions.m_checkWordsOnly;
    FilenameListUsed.RemoveAll();
    for (i = 0; i < dlgOptions.FilenameListUsed.GetSize(); i++)
    {
      FilenameListUsed.Add(dlgOptions.FilenameListUsed.GetAt(i));
    }
    SuraListUsed.RemoveAll();
    for (i = 0; i < dlgOptions.SuraList.GetSize(); i++)
    {
      SuraListUsed.Add(dlgOptions.SuraListUsed.GetAt(i));
    }
  }
}

void CAyatFinderDlg::OnButtonSave() 
{
	CSaveResultDlg dlgSaveResult;
  dlgSaveResult.DoModal();	
}

void CAyatFinderDlg::OnButtonInfo() 
{
  CAboutDlg dlgAbout;
  dlgAbout.DoModal();
}

void CAyatFinderDlg::OnButtonSearchAbort() 
{
  m_bSearching = false;
  m_btnSearchAbort.EnableWindow(false);
  m_btnExit.EnableWindow(true);
}

void CAyatFinderDlg::OnSetfocusEditKeyword() 
{
  UpdateData(true);	
	if (m_strKeyword.IsEmpty()) m_btnFind.EnableWindow(false); else m_btnFind.EnableWindow(true);
  UpdateData(false);
}

void CAyatFinderDlg::OnUpdateEditKeyword() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CResizableDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
  
  OnSetfocusEditKeyword();
}

void CAyatFinderDlg::OnSetfocusEditResult() 
{
  UpdateData(true);	
	if (m_richeditResult.GetWindowTextLength() == 0) m_btnSave.EnableWindow(false); else m_btnSave.EnableWindow(true);
  UpdateData(false);	
}

void CAyatFinderDlg::OnUpdateEditResult() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CResizableDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	OnSetfocusEditResult();
}

void CAyatFinderDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
    if (m_iCurIcon == 0) m_aniIcon.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1));
    if (m_iCurIcon == 1) m_aniIcon.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON2));
    if (m_iCurIcon == 2) m_aniIcon.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON3));
    if (m_iCurIcon == 3) m_aniIcon.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON4));
		m_iCurIcon++;
		if (m_iCurIcon >= 4)
		{
			m_iCurIcon = 0;
		}
	}
	CResizableDialog::OnTimer(nIDEvent);
}

void CAyatFinderDlg::OnSize(UINT nType, int cx, int cy) 
{
	CResizableDialog::OnSize(nType, cx, cy);	
}
