// FmwRSSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FmwRSS.h"
#include "FmwRSSDlg.h"
#include "DlgProxy.h"
#include "GroupDlg.h"
#include "FeedDlg.h"

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
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
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
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFmwRSSDlg dialog

IMPLEMENT_DYNAMIC(CFmwRSSDlg, CDialog);

CFmwRSSDlg::CFmwRSSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFmwRSSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFmwRSSDlg)
	m_strView = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CFmwRSSDlg::~CFmwRSSDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CFmwRSSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFmwRSSDlg)
	DDX_Control(pDX, IDC_LIST_NEWS, m_lstNews);
	DDX_Control(pDX, IDC_TREE_FEEDS, m_treeFeeds);
	DDX_Control(pDX, IDC_STATIC_VIEW, m_stcView);
	DDX_Control(pDX, IDC_STATIC_NEWS, m_stcNews);
	DDX_Control(pDX, IDC_STATIC_FEED, m_stcFeed);
	DDX_Control(pDX, ID_APP_ABOUT, m_btnAboutApp);
	DDX_Control(pDX, IDC_BUTTON_VIEW0, m_btnViewAll);
	DDX_Control(pDX, IDC_BUTTON_VIEW23, m_btnViewNoFeeds);
	DDX_Control(pDX, IDC_BUTTON_VIEW13, m_btnViewNoNews);
	DDX_Control(pDX, IDC_BUTTON_VIEW12, m_btnViewNoView);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_UPDATE_NOW, m_btnUpdateNow);
	DDX_Control(pDX, IDC_BUTTON_OPTIONS, m_btnSetOptions);
	DDX_Control(pDX, IDC_BUTTON_FEED_NEW, m_btnAddFeed);
	DDX_Control(pDX, IDC_BUTTON_FEED_EDIT, m_btnEditFeed);
	DDX_Control(pDX, IDC_BUTTON_FEED_DELETE, m_btnDeleteFeed);
	DDX_Control(pDX, IDC_BUTTON_OPML_IMPORT, m_btnImportOPML);
	DDX_Control(pDX, IDC_BUTTON_OPML_EXPORT, m_btnExportAsOPML);
	DDX_Control(pDX, IDC_BUTTON_GROUP_NEW, m_btnAddGroup);
	DDX_Control(pDX, IDC_BUTTON_GROUP_DELETE, m_btnDeleteGroup);
	DDX_Control(pDX, IDC_BUTTON_GROUP_EDIT, m_btnEditGroup);
	DDX_Text(pDX, IDC_EDIT_VIEW, m_strView);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFmwRSSDlg, CDialog)
	//{{AFX_MSG_MAP(CFmwRSSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_GROUP_NEW, OnButtonGroupNew)
	ON_BN_CLICKED(IDC_BUTTON_GROUP_EDIT, OnButtonGroupEdit)
	ON_BN_CLICKED(IDC_BUTTON_GROUP_DELETE, OnButtonGroupDelete)
	ON_BN_CLICKED(IDC_BUTTON_FEED_NEW, OnButtonFeedNew)
	ON_BN_CLICKED(IDC_BUTTON_FEED_EDIT, OnButtonFeedEdit)
	ON_BN_CLICKED(IDC_BUTTON_FEED_DELETE, OnButtonFeedDelete)
	ON_BN_CLICKED(IDC_BUTTON_OPML_IMPORT, OnButtonOpmlImport)
	ON_BN_CLICKED(IDC_BUTTON_OPML_EXPORT, OnButtonOpmlExport)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_NOW, OnButtonUpdateNow)
	ON_BN_CLICKED(IDC_BUTTON_OPTIONS, OnButtonOptions)
	ON_BN_CLICKED(IDC_BUTTON_VIEW0, OnButtonView0)
	ON_BN_CLICKED(IDC_BUTTON_VIEW23, OnButtonView23)
	ON_BN_CLICKED(IDC_BUTTON_VIEW13, OnButtonView13)
	ON_BN_CLICKED(IDC_BUTTON_VIEW12, OnButtonView12)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_FILE_FEED_DELETE, OnFileFeedDelete)
	ON_COMMAND(ID_FILE_FEED_EDIT, OnFileFeedEdit)
	ON_COMMAND(ID_FILE_FEED_NEW, OnFileFeedNew)
	ON_COMMAND(ID_FILE_GROUP_DELETE, OnFileGroupDelete)
	ON_COMMAND(ID_FILE_GROUP_EDIT, OnFileGroupEdit)
	ON_COMMAND(ID_FILE_GROUP_NEW, OnFileGroupNew)
	ON_COMMAND(ID_FILE_OPML_EXPORT, OnFileOpmlExport)
	ON_COMMAND(ID_FILE_OPML_IMPORT, OnFileOpmlImport)
	ON_COMMAND(ID_MISC_OPTIONS, OnMiscOptions)
	ON_COMMAND(ID_MISC_UPDATEFEEDSNOW, OnMiscUpdateFeedsNow)
	ON_COMMAND(ID_WINDOW_ALL, OnWindowAll)
	ON_COMMAND(ID_WINDOW_NOFEEDS, OnWindowNoFeeds)
	ON_COMMAND(ID_WINDOW_NONEWS, OnWindowNoNews)
	ON_COMMAND(ID_WINDOW_NOVIEW, OnWindowNoView)
	ON_BN_CLICKED(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFmwRSSDlg message handlers

BOOL CFmwRSSDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
  
  m_btnAddGroup.SetThemeHelper(&m_ThemeHelper);
  m_btnAddGroup.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAddGroup.SetIcon(IDI_ICON_FOLDER_NEW);
  m_btnAddGroup.DrawAsToolbar(true);
  m_btnAddGroup.DrawFlatFocus(false);
  m_btnAddGroup.EnableBalloonTooltip();
  m_btnAddGroup.SetTooltipText("");
	
  m_btnEditGroup.SetThemeHelper(&m_ThemeHelper);
  m_btnEditGroup.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnEditGroup.SetIcon(IDI_ICON_FOLDER_TXT);
  m_btnEditGroup.DrawAsToolbar(true);
  m_btnEditGroup.DrawFlatFocus(false);
  m_btnEditGroup.EnableBalloonTooltip();
  m_btnEditGroup.SetTooltipText("");
	
  m_btnDeleteGroup.SetThemeHelper(&m_ThemeHelper);
  m_btnDeleteGroup.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnDeleteGroup.SetIcon(IDI_ICON_FOLDER_X);
  m_btnDeleteGroup.DrawAsToolbar(true);
  m_btnDeleteGroup.DrawFlatFocus(false);
  m_btnDeleteGroup.EnableBalloonTooltip();
  m_btnDeleteGroup.SetTooltipText("");
	
  m_btnAddFeed.SetThemeHelper(&m_ThemeHelper);
  m_btnAddFeed.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAddFeed.SetIcon(IDI_ICON_RSSFILE_ADD);
  m_btnAddFeed.DrawAsToolbar(true);
  m_btnAddFeed.DrawFlatFocus(false);
  m_btnAddFeed.EnableBalloonTooltip();
  m_btnAddFeed.SetTooltipText("");
	
  m_btnEditFeed.SetThemeHelper(&m_ThemeHelper);
  m_btnEditFeed.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnEditFeed.SetIcon(IDI_ICON_RSSFILE_INFO);
  m_btnEditFeed.DrawAsToolbar(true);
  m_btnEditFeed.DrawFlatFocus(false);
  m_btnEditFeed.EnableBalloonTooltip();
  m_btnEditFeed.SetTooltipText("");
	
  m_btnDeleteFeed.SetThemeHelper(&m_ThemeHelper);
  m_btnDeleteFeed.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnDeleteFeed.SetIcon(IDI_ICON_RSSFILE_DELETE);
  m_btnDeleteFeed.DrawAsToolbar(true);
  m_btnDeleteFeed.DrawFlatFocus(false);
  m_btnDeleteFeed.EnableBalloonTooltip();
  m_btnDeleteFeed.SetTooltipText("");
	
  m_btnImportOPML.SetThemeHelper(&m_ThemeHelper);
  m_btnImportOPML.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnImportOPML.SetIcon(IDI_ICON_INBOX);
  m_btnImportOPML.DrawAsToolbar(true);
  m_btnImportOPML.DrawFlatFocus(false);
  m_btnImportOPML.EnableBalloonTooltip();
  m_btnImportOPML.SetTooltipText("");
	
  m_btnExportAsOPML.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsOPML.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsOPML.SetIcon(IDI_ICON_OUTBOX);
  m_btnExportAsOPML.DrawAsToolbar(true);
  m_btnExportAsOPML.DrawFlatFocus(false);
  m_btnExportAsOPML.EnableBalloonTooltip();
  m_btnExportAsOPML.SetTooltipText("");
	
  m_btnUpdateNow.SetThemeHelper(&m_ThemeHelper);
  m_btnUpdateNow.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnUpdateNow.SetIcon(IDI_ICON_REFRESH);
  m_btnUpdateNow.DrawAsToolbar(true);
  m_btnUpdateNow.DrawFlatFocus(false);
  m_btnUpdateNow.EnableBalloonTooltip();
  m_btnUpdateNow.SetTooltipText("");
	
  m_btnSetOptions.SetThemeHelper(&m_ThemeHelper);
  m_btnSetOptions.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSetOptions.SetIcon(IDI_ICON_OPTIONS);
  m_btnSetOptions.DrawAsToolbar(true);
  m_btnSetOptions.DrawFlatFocus(false);
  m_btnSetOptions.EnableBalloonTooltip();
  m_btnSetOptions.SetTooltipText("");

  m_btnViewAll.SetThemeHelper(&m_ThemeHelper);
  m_btnViewAll.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnViewAll.SetIcon(IDI_ICON_VIEW0);
  m_btnViewAll.DrawAsToolbar(true);
  m_btnViewAll.DrawFlatFocus(false);
  m_btnViewAll.EnableBalloonTooltip();
  m_btnViewAll.SetTooltipText("");
	
  m_btnViewNoFeeds.SetThemeHelper(&m_ThemeHelper);
  m_btnViewNoFeeds.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnViewNoFeeds.SetIcon(IDI_ICON_VIEW23);
  m_btnViewNoFeeds.DrawAsToolbar(true);
  m_btnViewNoFeeds.DrawFlatFocus(false);
  m_btnViewNoFeeds.EnableBalloonTooltip();
  m_btnViewNoFeeds.SetTooltipText("");
	
  m_btnViewNoNews.SetThemeHelper(&m_ThemeHelper);
  m_btnViewNoNews.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnViewNoNews.SetIcon(IDI_ICON_VIEW13);
  m_btnViewNoNews.DrawAsToolbar(true);
  m_btnViewNoNews.DrawFlatFocus(false);
  m_btnViewNoNews.EnableBalloonTooltip();
  m_btnViewNoNews.SetTooltipText("");
	
  m_btnViewNoView.SetThemeHelper(&m_ThemeHelper);
  m_btnViewNoView.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnViewNoView.SetIcon(IDI_ICON_VIEW12);
  m_btnViewNoView.DrawAsToolbar(true);
  m_btnViewNoView.DrawFlatFocus(false);
  m_btnViewNoView.EnableBalloonTooltip();
  m_btnViewNoView.SetTooltipText("");
	
  m_btnAboutApp.SetThemeHelper(&m_ThemeHelper);
  m_btnAboutApp.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAboutApp.SetIcon(IDI_ICON_INFO);
  m_btnAboutApp.DrawAsToolbar(true);
  m_btnAboutApp.DrawFlatFocus(false);
  m_btnAboutApp.EnableBalloonTooltip();
  m_btnAboutApp.SetTooltipText("");
	
  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.SetIcon(IDI_ICON_EXIT);
  m_btnCancel.DrawAsToolbar(true);
  m_btnCancel.DrawFlatFocus(false);
  m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText("");

  CBitmap bmMainframe,bmFolder,bmFolderOpen,bmRSSFile,bmRSSFileNext;
  bmMainframe.LoadBitmap(IDB_BITMAP_FMWRSS);
  bmFolder.LoadBitmap(IDB_BITMAP_FOLDER);
  bmFolderOpen.LoadBitmap(IDB_BITMAP_FOLDER_OPEN);
  bmRSSFile.LoadBitmap(IDB_BITMAP_RSSFILE);
  bmRSSFileNext.LoadBitmap(IDB_BITMAP_NEXT_UNREAD);

  m_imageList.Create(16,16,ILC_COLOR8,1,1);
  m_imageList.Add(&bmMainframe,RGB(0,0,0));
  m_imageList.Add(&bmFolder,RGB(0,0,0));
  m_imageList.Add(&bmFolderOpen,RGB(0,0,0));
  m_imageList.Add(&bmRSSFile,RGB(0,0,0));
  m_imageList.Add(&bmRSSFileNext,RGB(0,0,0));

  m_treeFeeds.SetImageList(&m_imageList,TVSIL_NORMAL);
  
  HTREEITEM level0,level1,level2,level3,level4;
  HTREEITEM level11,level12,level13,level14;
  HTREEITEM level21,level22,level23,level24;
  HTREEITEM level31,level32,level33,level34;
  HTREEITEM level41,level42,level43,level44;

  level0 = m_treeFeeds.InsertItem(_T("All Feeds"),0,0,TVI_ROOT);
  level1 = m_treeFeeds.InsertItem(_T("Busines"),1,2,level0);
  level2 = m_treeFeeds.InsertItem(_T("Entertainment"),1,2,level0);
  level3 = m_treeFeeds.InsertItem(_T("News"),1,2,level0);
  level4 = m_treeFeeds.InsertItem(_T("Tech"),1,2,level0);

  level11 = m_treeFeeds.InsertItem(_T("BusinessWeek Online -- Top News"),3,4,level1);
  level12 = m_treeFeeds.InsertItem(_T("WSJ.com: Markets"),3,4,level1);
  level13 = m_treeFeeds.InsertItem(_T("WSJ.com: US Business"),3,4,level1);
  level14 = m_treeFeeds.InsertItem(_T("BusinessWeek Online -- Investing"),3,4,level1);

  level21 = m_treeFeeds.InsertItem(_T("ABCNews Entertainment"),3,4,level2);
  level22 = m_treeFeeds.InsertItem(_T("Movies.com New Movie Reviews"),3,4,level2);
  level23 = m_treeFeeds.InsertItem(_T("Yahoo! News: Entertainment"),3,4,level2);
  level24 = m_treeFeeds.InsertItem(_T("Cinematical"),3,4,level2);

  level31 = m_treeFeeds.InsertItem(_T("BBC News | News Front Page | UK Edition"),3,4,level3);
  level32 = m_treeFeeds.InsertItem(_T("Guardian Unlimited"),3,4,level3);
  level33 = m_treeFeeds.InsertItem(_T("NYT > Home Page"),3,4,level3);
  level34 = m_treeFeeds.InsertItem(_T("Reuters: Top News"),3,4,level3);

  level41 = m_treeFeeds.InsertItem(_T("BusinessWeek Online -- Technology"),3,4,level4);
  level42 = m_treeFeeds.InsertItem(_T("Engadget"),3,4,level4);
  level43 = m_treeFeeds.InsertItem(_T("Slashdot"),3,4,level4);
  level44 = m_treeFeeds.InsertItem(_T("WSJ.com: Personal Technology"),3,4,level4);
  
  m_treeFeeds.SelectItem(level0);
  m_treeFeeds.Expand(level0,TVE_EXPAND);

  GetClientRect(m_rctWindowRect);
  GetWindowRect(m_rctWindowRectFrame);
  
  GetDlgItem(IDC_STATIC_FEED)->GetClientRect(m_rctLayoutFeedsRect); 
  GetDlgItem(IDC_STATIC_FEED)->GetWindowRect(m_rctLayoutFeedsRectFrame);
  GetDlgItem(IDC_STATIC_NEWS)->GetClientRect(m_rctLayoutNewsRect);
  GetDlgItem(IDC_STATIC_NEWS)->GetWindowRect(m_rctLayoutNewsRectFrame);
  GetDlgItem(IDC_STATIC_VIEW)->GetClientRect(m_rctLayoutViewRect);
  GetDlgItem(IDC_STATIC_VIEW)->GetWindowRect(m_rctLayoutViewRectFrame);

  m_cpLayoutFeedsLeft.x  = (m_rctLayoutFeedsRectFrame.left-m_rctWindowRectFrame.left)-((m_rctWindowRectFrame.right-m_rctWindowRectFrame.left)-m_rctWindowRect.right)+((m_rctLayoutFeedsRectFrame.right-m_rctLayoutFeedsRectFrame.left)-m_rctLayoutFeedsRect.right);
  m_cpLayoutFeedsLeft.y  = (m_rctLayoutFeedsRectFrame.top-m_rctWindowRectFrame.top)-((m_rctWindowRectFrame.bottom-m_rctWindowRectFrame.top)-m_rctWindowRect.bottom)+((m_rctLayoutFeedsRectFrame.bottom-m_rctLayoutFeedsRectFrame.top)-m_rctLayoutFeedsRect.bottom);
  m_cpLayoutFeedsRight.x = (m_rctLayoutFeedsRectFrame.left-m_rctWindowRectFrame.left)-((m_rctWindowRectFrame.right-m_rctWindowRectFrame.left)-m_rctWindowRect.right)+((m_rctLayoutFeedsRectFrame.right-m_rctLayoutFeedsRectFrame.left)-m_rctLayoutFeedsRect.right)+m_rctLayoutFeedsRect.right;
  m_cpLayoutFeedsRight.y = (m_rctLayoutFeedsRectFrame.top-m_rctWindowRectFrame.top)-((m_rctWindowRectFrame.bottom-m_rctWindowRectFrame.top)-m_rctWindowRect.bottom)+((m_rctLayoutFeedsRectFrame.bottom-m_rctLayoutFeedsRectFrame.top)-m_rctLayoutFeedsRect.bottom)+m_rctLayoutFeedsRect.bottom;

  m_cpLayoutNewsLeft.x  = (m_rctLayoutNewsRectFrame.left-m_rctWindowRectFrame.left)-((m_rctWindowRectFrame.right-m_rctWindowRectFrame.left)-m_rctWindowRect.right)+((m_rctLayoutNewsRectFrame.right-m_rctLayoutNewsRectFrame.left)-m_rctLayoutNewsRect.right);
  m_cpLayoutNewsLeft.y  = (m_rctLayoutNewsRectFrame.top-m_rctWindowRectFrame.top)-((m_rctWindowRectFrame.bottom-m_rctWindowRectFrame.top)-m_rctWindowRect.bottom)+((m_rctLayoutNewsRectFrame.bottom-m_rctLayoutNewsRectFrame.top)-m_rctLayoutNewsRect.bottom);
  m_cpLayoutNewsRight.x = (m_rctLayoutNewsRectFrame.left-m_rctWindowRectFrame.left)-((m_rctWindowRectFrame.right-m_rctWindowRectFrame.left)-m_rctWindowRect.right)+((m_rctLayoutNewsRectFrame.right-m_rctLayoutNewsRectFrame.left)-m_rctLayoutNewsRect.right)+m_rctLayoutNewsRect.right;
  m_cpLayoutNewsRight.y = (m_rctLayoutNewsRectFrame.top-m_rctWindowRectFrame.top)-((m_rctWindowRectFrame.bottom-m_rctWindowRectFrame.top)-m_rctWindowRect.bottom)+((m_rctLayoutNewsRectFrame.bottom-m_rctLayoutNewsRectFrame.top)-m_rctLayoutNewsRect.bottom)+m_rctLayoutNewsRect.bottom;
  
  m_cpLayoutViewLeft.x  = (m_rctLayoutViewRectFrame.left-m_rctWindowRectFrame.left)-((m_rctWindowRectFrame.right-m_rctWindowRectFrame.left)-m_rctWindowRect.right)+((m_rctLayoutViewRectFrame.right-m_rctLayoutViewRectFrame.left)-m_rctLayoutViewRect.right);
  m_cpLayoutViewLeft.y  = (m_rctLayoutViewRectFrame.top-m_rctWindowRectFrame.top)-((m_rctWindowRectFrame.bottom-m_rctWindowRectFrame.top)-m_rctWindowRect.bottom)+((m_rctLayoutViewRectFrame.bottom-m_rctLayoutViewRectFrame.top)-m_rctLayoutViewRect.bottom);
  m_cpLayoutViewRight.x = (m_rctLayoutViewRectFrame.left-m_rctWindowRectFrame.left)-((m_rctWindowRectFrame.right-m_rctWindowRectFrame.left)-m_rctWindowRect.right)+((m_rctLayoutViewRectFrame.right-m_rctLayoutViewRectFrame.left)-m_rctLayoutViewRect.right)+m_rctLayoutViewRect.right;
  m_cpLayoutViewRight.y = (m_rctLayoutViewRectFrame.top-m_rctWindowRectFrame.top)-((m_rctWindowRectFrame.bottom-m_rctWindowRectFrame.top)-m_rctWindowRect.bottom)+((m_rctLayoutViewRectFrame.bottom-m_rctLayoutViewRectFrame.top)-m_rctLayoutViewRect.bottom)+m_rctLayoutViewRect.bottom;

  m_lstNews.SetExtendedStyle(LVS_EX_GRIDLINES + LVS_EX_FULLROWSELECT);
  m_lstNews.InsertColumn(0,"",LVCFMT_LEFT,0);
  m_lstNews.InsertColumn(1,"Date",LVCFMT_LEFT,80);
  m_lstNews.InsertColumn(2,"Title",LVCFMT_LEFT,250);
  
  m_lstNews.InsertItem(0,"");
  m_lstNews.SetItemText(0,1,"06.05.08");
  m_lstNews.SetItemText(0,2,"Elvis is back!!!");

  m_lstNews.InsertItem(0,"");
  m_lstNews.SetItemText(0,1,"07.05.08");
  m_lstNews.SetItemText(0,2,"Bill Gates is now poor!!!");

  m_lstNews.InsertItem(0,"");
  m_lstNews.SetItemText(0,1,"08.05.08");
  m_lstNews.SetItemText(0,2,"Today I'm a Moslem!");
  
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFmwRSSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFmwRSSDlg::OnPaint() 
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
HCURSOR CFmwRSSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CFmwRSSDlg::OnClose() 
{
	if (CanExit()) CDialog::OnClose();
}

void CFmwRSSDlg::OnOK() 
{
	if (CanExit()) CDialog::OnOK();
}

void CFmwRSSDlg::OnCancel() 
{
	if (CanExit()) CDialog::OnCancel();
}

BOOL CFmwRSSDlg::CanExit()
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

void CFmwRSSDlg::OnButtonGroupNew() 
{
	CGroupDlg dlgAddGroup;
  dlgAddGroup.DoModal();
}

void CFmwRSSDlg::OnButtonGroupEdit() 
{
	CGroupDlg dlgChangeGroup;
  dlgChangeGroup.DoModal();
}

void CFmwRSSDlg::OnButtonGroupDelete() 
{
	// TODO: Add your control notification handler code here	
}

void CFmwRSSDlg::OnButtonFeedNew() 
{
	CFeedDlg dlgAddFeed;
  dlgAddFeed.DoModal();
}

void CFmwRSSDlg::OnButtonFeedEdit() 
{
	CFeedDlg dlgChangeFeed;
  dlgChangeFeed.DoModal();
}

void CFmwRSSDlg::OnButtonFeedDelete() 
{
	// TODO: Add your control notification handler code here
}

void CFmwRSSDlg::OnButtonOpmlImport() 
{
	// TODO: Add your control notification handler code here
}

void CFmwRSSDlg::OnButtonOpmlExport() 
{
	// TODO: Add your control notification handler code here
}

void CFmwRSSDlg::OnButtonUpdateNow() 
{
	// TODO: Add your control notification handler code here
}

void CFmwRSSDlg::OnButtonOptions() 
{
	// TODO: Add your control notification handler code here	
}

void CFmwRSSDlg::OnButtonView0() 
{
  GetDlgItem(IDC_STATIC_FEED)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_FEED)->ShowWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->EnableWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->ShowWindow(true);
  GetDlgItem(IDC_STATIC_NEWS)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_NEWS)->ShowWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->EnableWindow(true);
  GetDlgItem(IDC_LIST_FEEDS)->ShowWindow(true);	
  GetDlgItem(IDC_STATIC_VIEW)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_VIEW)->ShowWindow(true);
  GetDlgItem(IDC_EDIT_VIEW)->EnableWindow(true);
  GetDlgItem(IDC_EDIT_VIEW)->ShowWindow(true);

  m_stcFeed.MoveWindow(m_cpLayoutFeedsLeft.x+3,m_cpLayoutFeedsLeft.y+3,m_cpLayoutFeedsRight.x-m_cpLayoutFeedsLeft.x,m_cpLayoutFeedsRight.y-m_cpLayoutFeedsLeft.y,true);
  m_stcNews.MoveWindow(m_cpLayoutNewsLeft.x+3,m_cpLayoutNewsLeft.y+3,m_cpLayoutNewsRight.x-m_cpLayoutNewsLeft.x,m_cpLayoutNewsRight.y-m_cpLayoutNewsLeft.y,true);
  m_stcView.MoveWindow(m_cpLayoutViewLeft.x+3,m_cpLayoutViewLeft.y+3,m_cpLayoutViewRight.x-m_cpLayoutViewLeft.x,m_cpLayoutViewRight.y-m_cpLayoutViewLeft.y,true);
  GetDlgItem(IDC_LIST_NEWS)->MoveWindow(m_cpLayoutNewsLeft.x+11,m_cpLayoutNewsLeft.y+19,m_cpLayoutNewsRight.x-m_cpLayoutNewsLeft.x-15,m_cpLayoutNewsRight.y-m_cpLayoutNewsLeft.y-25,true);
  GetDlgItem(IDC_EDIT_VIEW)->MoveWindow(m_cpLayoutViewLeft.x+11,m_cpLayoutViewLeft.y+19,m_cpLayoutViewRight.x-m_cpLayoutViewLeft.x-15,m_cpLayoutViewRight.y-m_cpLayoutViewLeft.y-25,true);
}

void CFmwRSSDlg::OnButtonView23() 
{
  GetDlgItem(IDC_STATIC_FEED)->EnableWindow(false);
  GetDlgItem(IDC_STATIC_FEED)->ShowWindow(false);
  GetDlgItem(IDC_TREE_FEEDS)->EnableWindow(false);
  GetDlgItem(IDC_TREE_FEEDS)->ShowWindow(false);
  GetDlgItem(IDC_STATIC_NEWS)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_NEWS)->ShowWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->EnableWindow(true);
  GetDlgItem(IDC_LIST_FEEDS)->ShowWindow(true);	
  GetDlgItem(IDC_STATIC_VIEW)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_VIEW)->ShowWindow(true);
  GetDlgItem(IDC_EDIT_VIEW)->EnableWindow(true);
  GetDlgItem(IDC_EDIT_VIEW)->ShowWindow(true);

  m_stcNews.MoveWindow(m_cpLayoutFeedsLeft.x+3,m_cpLayoutNewsLeft.y+3,m_cpLayoutNewsRight.x-m_cpLayoutFeedsLeft.x,m_cpLayoutNewsRight.y-m_cpLayoutFeedsLeft.y,true);
  m_stcView.MoveWindow(m_cpLayoutFeedsLeft.x+3,m_cpLayoutViewLeft.y+3,m_cpLayoutViewRight.x-m_cpLayoutFeedsLeft.x,m_cpLayoutViewRight.y-m_cpLayoutViewLeft.y,true);
  GetDlgItem(IDC_LIST_NEWS)->MoveWindow(m_cpLayoutFeedsLeft.x+11,m_cpLayoutNewsLeft.y+19,m_cpLayoutNewsRight.x-m_cpLayoutFeedsLeft.x-15,m_cpLayoutNewsRight.y-m_cpLayoutFeedsLeft.y-25,true);
  GetDlgItem(IDC_EDIT_VIEW)->MoveWindow(m_cpLayoutFeedsLeft.x+11,m_cpLayoutViewLeft.y+19,m_cpLayoutViewRight.x-m_cpLayoutFeedsLeft.x-15,m_cpLayoutViewRight.y-m_cpLayoutViewLeft.y-25,true);
}

void CFmwRSSDlg::OnButtonView13() 
{
  GetDlgItem(IDC_STATIC_FEED)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_FEED)->ShowWindow(true);
  GetDlgItem(IDC_STATIC_NEWS)->EnableWindow(false);
  GetDlgItem(IDC_STATIC_NEWS)->ShowWindow(false);
  GetDlgItem(IDC_TREE_FEEDS)->EnableWindow(false);
  GetDlgItem(IDC_LIST_FEEDS)->ShowWindow(false);	
  GetDlgItem(IDC_STATIC_VIEW)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_VIEW)->ShowWindow(true);
  GetDlgItem(IDC_EDIT_VIEW)->EnableWindow(true);
  GetDlgItem(IDC_EDIT_VIEW)->ShowWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->EnableWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->ShowWindow(true);

  m_stcView.MoveWindow(m_cpLayoutViewLeft.x+3,m_cpLayoutNewsLeft.y+3,m_cpLayoutViewRight.x-m_cpLayoutViewLeft.x,m_cpLayoutViewRight.y-m_cpLayoutNewsLeft.y,true);
  GetDlgItem(IDC_EDIT_VIEW)->MoveWindow(m_cpLayoutViewLeft.x+11,m_cpLayoutNewsLeft.y+19,m_cpLayoutViewRight.x-m_cpLayoutViewLeft.x-15,m_cpLayoutViewRight.y-m_cpLayoutNewsLeft.y-25,true);
}

void CFmwRSSDlg::OnButtonView12() 
{
  GetDlgItem(IDC_STATIC_FEED)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_FEED)->ShowWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->EnableWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->ShowWindow(true);
  GetDlgItem(IDC_STATIC_NEWS)->EnableWindow(true);
  GetDlgItem(IDC_STATIC_NEWS)->ShowWindow(true);
  GetDlgItem(IDC_TREE_FEEDS)->EnableWindow(true);
  GetDlgItem(IDC_LIST_FEEDS)->ShowWindow(true);	
  GetDlgItem(IDC_STATIC_VIEW)->EnableWindow(false);
  GetDlgItem(IDC_STATIC_VIEW)->ShowWindow(false);
  GetDlgItem(IDC_EDIT_VIEW)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_VIEW)->ShowWindow(false);

  GetDlgItem(IDC_LIST_NEWS)->MoveWindow(m_cpLayoutViewLeft.x+11,m_cpLayoutNewsLeft.y+19,m_cpLayoutViewRight.x-m_cpLayoutViewLeft.x-15,m_cpLayoutViewRight.y-m_cpLayoutNewsLeft.y-25,true);
  m_stcNews.MoveWindow(m_cpLayoutViewLeft.x+3,m_cpLayoutNewsLeft.y+3,m_cpLayoutViewRight.x-m_cpLayoutViewLeft.x,m_cpLayoutViewRight.y-m_cpLayoutNewsLeft.y,true);
}

void CFmwRSSDlg::OnFileExit() 
{
	OnCancel();	
}

void CFmwRSSDlg::OnFileFeedDelete() 
{
	OnButtonFeedDelete();
}

void CFmwRSSDlg::OnFileFeedEdit() 
{
	OnButtonFeedEdit();
}

void CFmwRSSDlg::OnFileFeedNew() 
{
	OnButtonFeedNew();
}

void CFmwRSSDlg::OnFileGroupDelete() 
{
	OnButtonGroupDelete();
}

void CFmwRSSDlg::OnFileGroupEdit() 
{
  OnButtonGroupEdit();
}

void CFmwRSSDlg::OnFileGroupNew() 
{
  OnButtonGroupNew();
}

void CFmwRSSDlg::OnFileOpmlExport() 
{
  OnButtonOpmlExport();
}

void CFmwRSSDlg::OnFileOpmlImport() 
{
  OnButtonOpmlImport();
}

void CFmwRSSDlg::OnMiscOptions() 
{
	OnButtonUpdateNow();
}

void CFmwRSSDlg::OnMiscUpdateFeedsNow() 
{
	OnButtonOptions();
}

void CFmwRSSDlg::OnWindowAll() 
{
	OnButtonView0();	
}

void CFmwRSSDlg::OnWindowNoFeeds() 
{
  OnButtonView23();
}

void CFmwRSSDlg::OnWindowNoNews() 
{
	OnButtonView13();
}

void CFmwRSSDlg::OnWindowNoView() 
{
	OnButtonView12();	
}

void CFmwRSSDlg::OnAppAbout() 
{
  CAboutDlg dlgAbout;
  dlgAbout.DoModal();
}
