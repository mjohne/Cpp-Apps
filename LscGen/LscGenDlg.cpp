// LscGenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LscGen.h"
#include "LscGenDlg.h"
#include "LscNewDlg.h"
#include "LscEditDlg.h"
#include "ExportAsGraphicDlg.h"
#include "ExportAsModelDlg.h"

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
//  m_strAppDescription = "LscGen ist ein zufallsbasierender, fraktaler Landschaftsgenerator. Diese Programm erstellt ein zweidimensionales Feld, das ein komplettes Höhenprofil für eine definierte Fläche erstellt. Diese Werte werden zur weiteren Verarbeitung (z. B. visuelle Präsentationen, 3D-Renderer) in einer Datei abgespeichert oder in andere Forrmate exportiert.";
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
// CLscGenDlg dialog

CLscGenDlg::CLscGenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLscGenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLscGenDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLscGenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLscGenDlg)
	//}}AFX_DATA_MAP
	
	DDX_Control(pDX, IDC_BUTTON_LSC_NEW, m_btnLscNew);
	DDX_Control(pDX, IDC_BUTTON_LSC_LOAD, m_btnLscLoad);
	DDX_Control(pDX, IDC_BUTTON_LSC_SAVE, m_btnLscSave);
	DDX_Control(pDX, IDC_BUTTON_LSC_CLOSE, m_btnLscClose);
	DDX_Control(pDX, IDC_BUTTON_LSC_EDIT, m_btnLscEdit);
	DDX_Control(pDX, IDC_BUTTON_EXPORTAS_MODEL, m_btnExportAsModel);
	DDX_Control(pDX, IDC_BUTTON_EXPORTAS_GRAPHIC, m_btnExportAsGraphic);
	DDX_Control(pDX, IDC_BUTTON_EXPORTAS_SQL, m_btnExportAsSQL);
	DDX_Control(pDX, IDC_BUTTON_APP_ABOUT, m_btnAppAbout);
	DDX_Control(pDX, IDC_BUTTON_APP_EXIT, m_btnAppExit);
}

BEGIN_MESSAGE_MAP(CLscGenDlg, CDialog)
	//{{AFX_MSG_MAP(CLscGenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_APP_EXIT, OnButtonAppExit)
	ON_BN_CLICKED(IDC_BUTTON_APP_ABOUT, OnButtonAppAbout)
	ON_BN_CLICKED(IDC_BUTTON_LSC_NEW, OnButtonLscNew)
	ON_BN_CLICKED(IDC_BUTTON_LSC_CLOSE, OnButtonLscClose)
	ON_BN_CLICKED(IDC_BUTTON_LSC_EDIT, OnButtonLscEdit)
	ON_BN_CLICKED(IDC_BUTTON_EXPORTAS_MODEL, OnButtonExportAsModel)
	ON_BN_CLICKED(IDC_BUTTON_EXPORTAS_GRAPHIC, OnButtonExportAsGraphic)
	ON_BN_CLICKED(IDC_BUTTON_EXPORTAS_SQL, OnButtonExportAsSQL)
	ON_BN_CLICKED(IDC_BUTTON_LSC_SAVE, OnButtonLscSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLscGenDlg message handlers

BOOL CLscGenDlg::OnInitDialog()
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

  srand((unsigned)time(NULL));
	
  m_btnLscNew.SetThemeHelper(&m_ThemeHelper);
  m_btnLscNew.SetIcon(IDI_ICON_LSC_NEW);
  m_btnLscNew.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnLscNew.EnableBalloonTooltip();
  m_btnLscNew.SetTooltipText("Neue Landschaft erstellen");

  m_btnLscLoad.SetThemeHelper(&m_ThemeHelper);
  m_btnLscLoad.SetIcon(IDI_ICON_LSC_LOAD);
  m_btnLscLoad.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnLscLoad.EnableBalloonTooltip();
  m_btnLscLoad.SetTooltipText("Eine Landschaft laden");

  m_btnLscSave.SetThemeHelper(&m_ThemeHelper);
  m_btnLscSave.SetIcon(IDI_ICON_LSC_SAVE);
  m_btnLscSave.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnLscSave.EnableBalloonTooltip();
  m_btnLscSave.SetTooltipText("Aktuelle Landschaft speichern");

  m_btnLscClose.SetThemeHelper(&m_ThemeHelper);
  m_btnLscClose.SetIcon(IDI_ICON_LSC_CLOSE);
  m_btnLscClose.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnLscClose.EnableBalloonTooltip();
  m_btnLscClose.SetTooltipText("Aktuelle Landschaft schließen");

  m_btnLscEdit.SetThemeHelper(&m_ThemeHelper);
  m_btnLscEdit.SetIcon(IDI_ICON_LSC_EDIT);
  m_btnLscEdit.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnLscEdit.EnableBalloonTooltip();
  m_btnLscEdit.SetTooltipText("Aktuelle Landschaft bearbeiten");

  m_btnExportAsModel.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsModel.SetIcon(IDI_ICON_MODEL);
  m_btnExportAsModel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsModel.EnableBalloonTooltip();
  m_btnExportAsModel.SetTooltipText("Als Modell exportieren");

  m_btnExportAsGraphic.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsGraphic.SetIcon(IDI_ICON_HEIGHTFIELD);
  m_btnExportAsGraphic.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsGraphic.EnableBalloonTooltip();
  m_btnExportAsGraphic.SetTooltipText("Als Grafik exportieren");

  m_btnExportAsSQL.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsSQL.SetIcon(IDI_ICON_SCRIPT);
  m_btnExportAsSQL.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsSQL.EnableBalloonTooltip();
  m_btnExportAsSQL.SetTooltipText("Als SQL-Skript exportieren");

  m_btnAppAbout.SetThemeHelper(&m_ThemeHelper);
  m_btnAppAbout.SetIcon(IDI_ICON_APP_ABOUT);
  m_btnAppAbout.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAppAbout.EnableBalloonTooltip();
  m_btnAppAbout.SetTooltipText("Programminformationen anzeigen");

  m_btnAppExit.SetThemeHelper(&m_ThemeHelper);
  m_btnAppExit.SetIcon(IDI_ICON_APP_EXIT);
  m_btnAppExit.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAppExit.EnableBalloonTooltip();
  m_btnAppExit.SetTooltipText("Programm beenden");

  GetDlgItem(IDC_BUTTON_LSC_SAVE)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_LSC_CLOSE)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_LSC_EDIT)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_EXPORTAS_MODEL)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_EXPORTAS_GRAPHIC)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_EXPORTAS_SQL)->EnableWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLscGenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
  } else {
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLscGenDlg::OnPaint() 
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
HCURSOR CLscGenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLscGenDlg::OnButtonLscNew() 
{
  CLscNewDlg dlgLscNew;
  int nResult = dlgLscNew.DoModal();
  if (nResult == IDOK)
  {
    GetDlgItem(IDC_BUTTON_LSC_NEW)->EnableWindow(false);
    GetDlgItem(IDC_BUTTON_LSC_SAVE)->EnableWindow(true);
    GetDlgItem(IDC_BUTTON_LSC_CLOSE)->EnableWindow(true);
    GetDlgItem(IDC_BUTTON_LSC_EDIT)->EnableWindow(true);
    GetDlgItem(IDC_BUTTON_EXPORTAS_MODEL)->EnableWindow(true);
    GetDlgItem(IDC_BUTTON_EXPORTAS_GRAPHIC)->EnableWindow(true);
    GetDlgItem(IDC_BUTTON_EXPORTAS_SQL)->EnableWindow(true);
  }  
}

void CLscGenDlg::OnButtonLscClose() 
{
  GetDlgItem(IDC_BUTTON_LSC_NEW)->EnableWindow(true);
  GetDlgItem(IDC_BUTTON_LSC_SAVE)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_LSC_CLOSE)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_LSC_EDIT)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_EXPORTAS_MODEL)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_EXPORTAS_GRAPHIC)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_EXPORTAS_SQL)->EnableWindow(false);
}

void CLscGenDlg::OnButtonAppExit() 
{
	if (!DestroyWindow()) 
  {
    delete m_arrHeightfield;
    CDialog::OnOK();
  }
}

void CLscGenDlg::OnButtonAppAbout() 
{
  CAboutDlg dlgAbout;
  dlgAbout.DoModal();
}

void CLscGenDlg::OnButtonLscEdit() 
{
  CLscEditDlg dlgLscEdit;
  int nResult = dlgLscEdit.DoModal();
}

void CLscGenDlg::OnButtonExportAsModel() 
{
  CExportAsModelDlg dlgExportAsModel;
  dlgExportAsModel.DoModal();
}

void CLscGenDlg::OnButtonExportAsGraphic() 
{
  CExportAsGraphicDlg dlgExportAsGraphic;
  dlgExportAsGraphic.DoModal();
}

void CLscGenDlg::OnButtonExportAsSQL() 
{
	// TODO: Add your control notification handler code here
	
}

void CLscGenDlg::OnButtonLscSave() 
{
  CString
    strRW = _T(""),
    strConcatMaster = _T(""),
    strConcatSlave = _T(""),
    strTemp = _T(""),
    inFilename = _T(""),
    outFilename = _T("");
  CFileDialog FileDialog(false,"","",OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,"LscGen - Landschaft (*.lsc)|*.lsc|");
  int nResult = FileDialog.DoModal();
  if (nResult == IDOK)
  {
    BeginWaitCursor();
    char szTempPath[MAX_PATH] = {0};
    GetTempPath(MAX_PATH,szTempPath);
    inFilename = CString(szTempPath)+"\\temp.lsc";
    outFilename = FileDialog.GetPathName();
    CStdioFile inFile, outFile;
    if (inFile.Open(inFilename, CFile::modeRead))
    {
      if (outFile.Open(LPCTSTR(outFilename), CFile::modeCreate | CFile::modeWrite))
      {
        while(inFile.ReadString(strRW))
        {
     		  strRW = strRW+"\n";
          outFile.WriteString(strRW);
        }
      }
      outFile.Close();
    }
    inFile.Close();
    EndWaitCursor();
  }
  MessageBox("Die Datei "+outFilename+" wurde erfolgreich gespeichert!","Erfolgreich gespeichert",MB_ICONINFORMATION | MB_OK);
}
