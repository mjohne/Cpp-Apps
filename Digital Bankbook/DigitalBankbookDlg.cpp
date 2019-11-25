// DigitalBankbookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalBankbook.h"
#include "DigitalBankbookDlg.h"
#include "DigitalBankbookDlg.h"
#include "NewBankbookDlg.h"
#include "OpenBankbookDlg.h"
#include "AppOptionsDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
  CThemeHelperST m_ThemeHelper;
	CXPStyleButtonST	m_btnOK;
	CString	m_strAppNameAndVersion;
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_strAppNameAndVersion = _T("");
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Text(pDX, IDC_STATIC_VERSION, m_strAppNameAndVersion);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDigitalBankbookDlg dialog

CDigitalBankbookDlg::CDigitalBankbookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDigitalBankbookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDigitalBankbookDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDigitalBankbookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDigitalBankbookDlg)
	DDX_Control(pDX, IDC_BUTTON_BANKBOOK_ABOUT, m_btnAbout);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_BANKBOOK_OPEN, m_btnOpenBankbook);
	DDX_Control(pDX, IDC_BUTTON_BANKBOOK_NEW, m_btnAddBankbook);
	DDX_Control(pDX, IDC_BUTTON_APP_OPTIONS, m_btnAppOptions);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDigitalBankbookDlg, CDialog)
	//{{AFX_MSG_MAP(CDigitalBankbookDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BANKBOOK_NEW, OnButtonBankbookNew)
	ON_BN_CLICKED(IDC_BUTTON_BANKBOOK_OPEN, OnButtonBankbookOpen)
	ON_BN_CLICKED(IDC_BUTTON_APP_OPTIONS, OnButtonAppOptions)
	ON_BN_CLICKED(IDC_BUTTON_BANKBOOK_ABOUT, OnButtonBankbookAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDigitalBankbookDlg message handlers

BOOL CDigitalBankbookDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	
  m_btnAddBankbook.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAddBankbook.DrawAsToolbar(false);
  m_btnAddBankbook.SetThemeHelper(&m_ThemeHelper);
  m_btnAddBankbook.EnableBalloonTooltip();
  m_btnAddBankbook.SetTooltipText(IDS_BANKBOOK_CREATE);
  m_btnAddBankbook.SetIcon(IDI_ICON_BANKBOOK_NEW_32);

  m_btnOpenBankbook.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOpenBankbook.DrawAsToolbar(false);
  m_btnOpenBankbook.SetThemeHelper(&m_ThemeHelper);
  m_btnOpenBankbook.EnableBalloonTooltip();
  m_btnOpenBankbook.SetTooltipText(IDS_BANKBOOK_OPEN);
  m_btnOpenBankbook.SetIcon(IDI_ICON_BANKBOOK_OPEN_32);

  m_btnAppOptions.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAppOptions.DrawAsToolbar(false);
  m_btnAppOptions.SetThemeHelper(&m_ThemeHelper);
  m_btnAppOptions.EnableBalloonTooltip();
  m_btnAppOptions.SetTooltipText(IDS_APPOPTIONS);
  m_btnAppOptions.SetIcon(IDI_ICON_GEAR_32);

  m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.DrawAsToolbar(false);
  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText(IDS_EXIT);
  m_btnCancel.SetIcon(IDI_ICON_EXIT_32);

  m_btnAbout.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAbout.DrawAsToolbar(false);
  m_btnAbout.SetThemeHelper(&m_ThemeHelper);
  m_btnAbout.EnableBalloonTooltip();
  m_btnAbout.SetTooltipText(IDS_ABOUTBOX);
  m_btnAbout.SetIcon(IDI_ICON_ABOUT_32);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDigitalBankbookDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDigitalBankbookDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDigitalBankbookDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDigitalBankbookDlg::OnButtonBankbookNew() 
{
  CNewBankbookDlg dlgNewBankbook;
  dlgNewBankbook.DoModal();
}

void CDigitalBankbookDlg::OnButtonBankbookOpen() 
{
  CString strFilter = _T("Digital Bankbook (*.dbb)|*.dbb|");
  strFilter += _T("Alle Dateien (*.*)|*.*|");
  CFileDialog dlgBankbookFile(true,NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,strFilter,NULL);
  dlgBankbookFile.m_ofn.lpstrTitle = _T("Digitales Sparbuch öffnen");
  //dlgBankbookFile.m_ofn.lpstrFileTitle = LPCTSTR(m_strBankbookName);
  if (dlgBankbookFile.DoModal() == IDOK)
  {
    // Datei öffnen hier!!!
    COpenBankbookDlg dlgOpenBankbook;
    dlgOpenBankbook.m_strPathname = dlgBankbookFile.GetPathName();
    dlgOpenBankbook.DoModal();
  }      
}

void CDigitalBankbookDlg::OnButtonAppOptions() 
{
  CAppOptionsDlg dlgAppOptions;
  dlgAppOptions.DoModal();
}

void CDigitalBankbookDlg::OnCancel() 
{
	// TODO: Add extra cleanup here	
	CDialog::OnCancel();
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.DrawAsToolbar(false);
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText(IDS_OK);
  m_btnOK.SetIcon(IDI_ICON_CHECK_32);

  m_strAppNameAndVersion.FormatMessage(IDS_VERSION);
  UpdateData(false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDigitalBankbookDlg::OnButtonBankbookAbout() 
{
  CAboutDlg dlgAbout;
  dlgAbout.DoModal();
}
