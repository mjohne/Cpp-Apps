// CharacterConverterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CharacterConverter.h"
#include "CharacterConverterDlg.h"

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
	CXPStyleButtonST	m_btnOK;
  CThemeHelperST m_ThemeHelper;
	CHyperLink m_stcAuthor;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDOK, m_btnOK);
  DDX_Control(pDX, IDC_STATIC_MAIL, m_stcAuthor);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharacterConverterDlg dialog

CCharacterConverterDlg::CCharacterConverterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCharacterConverterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCharacterConverterDlg)
	m_strInputFile = _T("");
	m_strOutputFile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCharacterConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCharacterConverterDlg)
	DDX_Control(pDX, IDC_BUTTON_ABOUT, m_btnAbout);
	DDX_Control(pDX, IDCLOSE, m_btnExit);
	DDX_Control(pDX, IDC_BUTTON_CHARSET, m_btnInfoCharset);
	DDX_Control(pDX, IDC_BUTTON_OFILE, m_btnOutputFile);
	DDX_Control(pDX, IDC_BUTTON_IFILE, m_btnInputFile);
	DDX_Control(pDX, IDC_COMBO_CHARSET, m_cmbCharset);
	DDX_Control(pDX, IDC_BUTTON_CONVERT, m_btnConvert);
	DDX_Text(pDX, IDC_EDIT_IFILE, m_strInputFile);
	DDX_Text(pDX, IDC_EDIT_OFILE, m_strOutputFile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCharacterConverterDlg, CDialog)
	//{{AFX_MSG_MAP(CCharacterConverterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_IFILE, OnButtonIFile)
	ON_BN_CLICKED(IDC_BUTTON_CHARSET, OnButtonInfoCharset)
	ON_BN_CLICKED(IDC_BUTTON_OFILE, OnButtonOFile)
	ON_BN_CLICKED(IDC_BUTTON_CONVERT, OnButtonConvert)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDCLOSE, OnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharacterConverterDlg message handlers

BOOL CCharacterConverterDlg::OnInitDialog()
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
	
  m_btnInputFile.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnInputFile.SetIcon(IDI_ICON_FOLDER);
  m_btnInputFile.DrawAsToolbar(true);
  m_btnInputFile.SetThemeHelper(&m_ThemeHelper);
  //m_btnInputFile.EnableBalloonTooltip();
  m_btnInputFile.SetTooltipText(_T("Choose input file"));
	
  m_btnOutputFile.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOutputFile.SetIcon(IDI_ICON_FOLDER);
  m_btnOutputFile.DrawAsToolbar(true);
  m_btnOutputFile.SetThemeHelper(&m_ThemeHelper);
  //m_btnOutputFile.EnableBalloonTooltip();
  m_btnOutputFile.SetTooltipText(_T("Choose output file"));
	
  m_btnInfoCharset.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnInfoCharset.SetIcon(IDI_ICON_INFO);
  m_btnInfoCharset.DrawAsToolbar(true);
  m_btnInfoCharset.SetThemeHelper(&m_ThemeHelper);
  //m_btnInfoCharset.EnableBalloonTooltip();
  m_btnInfoCharset.SetTooltipText(_T("Choose charset"));
	
  m_btnConvert.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnConvert.SetIcon(IDI_ICON_GO);
  m_btnConvert.DrawAsToolbar(false);
  m_btnConvert.SetThemeHelper(&m_ThemeHelper);
  //m_btnConvert.EnableBalloonTooltip();
  m_btnConvert.SetTooltipText(_T("Convert!"));
	
  m_btnAbout.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAbout.SetIcon(IDI_ICON_ABOUT);
  m_btnAbout.DrawAsToolbar(false);
  m_btnAbout.SetThemeHelper(&m_ThemeHelper);
  //m_btnAbout.EnableBalloonTooltip();
  m_btnAbout.SetTooltipText(_T("About..."));
	
  m_btnExit.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExit.SetIcon(IDI_ICON_EXIT);
  m_btnExit.DrawAsToolbar(false);
  m_btnExit.SetThemeHelper(&m_ThemeHelper);
  //m_btnExit.EnableBalloonTooltip();
  m_btnExit.SetTooltipText(_T("Exit"));
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCharacterConverterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCharacterConverterDlg::OnPaint() 
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
HCURSOR CCharacterConverterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCharacterConverterDlg::OnButtonIFile() 
{
  CString strFilter = _T("All files (*.*)|*.*|");
	CFileDialog dlgInputFile(true,NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,strFilter,NULL);
  dlgInputFile.DoModal();
}

void CCharacterConverterDlg::OnButtonInfoCharset() 
{
	// TODO: Add your control notification handler code here
	
}

void CCharacterConverterDlg::OnButtonOFile() 
{
  CString strFilter = _T("All files (*.*)|*.*|");
	CFileDialog dlgOutputFile(false,NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,strFilter,NULL);
  dlgOutputFile.DoModal();
}

void CCharacterConverterDlg::OnButtonConvert() 
{
	// TODO: Add your control notification handler code here
	
}

void CCharacterConverterDlg::OnButtonAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CCharacterConverterDlg::OnClose() 
{
	DestroyWindow();
}

void CAboutDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.SetIcon(IDI_ICON_APPLY);
  m_btnOK.DrawAsToolbar(false);
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  //m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText(_T("OK"));

  m_stcAuthor.SetURL(_T("mailto:michael-johne@gmx.de"));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
