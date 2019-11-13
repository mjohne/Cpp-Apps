// GrafMathDlg.cpp : implementation file
//

#include <cmath>
#include "stdafx.h"
#include "GrafMath.h"
#include "GrafMathDlg.h"
#include "XPStyleButtonST.h"
#include "ThemeHelperST.h"
#include "AxisOptionsDlg.h"
#include "CreditsDlg.h"
#include "IntegralDlg.h"
#include "InputFunctionDlg.h"
#include "GaussEliminationDlg.h"
#include "GetXofYDlg.h"
#include "GradientDlg.h"
#include "HelpDialog.h"
#include "LengthTwoPoints.h"
#include "MonotonyDlg.h"
#include "TangentDlg.h"
#include "ValueTableDlg.h"

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
	CXPStyleButtonST m_btnOK;
	CHyperLink m_MailAdrStein;
	CHyperLink m_MailAdrJohne;
	CHyperLink m_MailAdrAvcu;
	CHyperLink m_MailAdrSpielmann;
	CString m_strProgramAbstract;
  CThemeHelperST m_ThemeHelper;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	public:
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
	m_strProgramAbstract = _T("");
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDC_STATIC_PS, m_MailAdrStein);
	DDX_Control(pDX, IDC_STATIC_MJ, m_MailAdrJohne);
	DDX_Control(pDX, IDC_STATIC_MA, m_MailAdrAvcu);
	DDX_Control(pDX, IDC_STATIC_ES, m_MailAdrSpielmann);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrafMathDlg dialog

CGrafMathDlg::CGrafMathDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGrafMathDlg::IDD, pParent), m_fSizeFaktor(4), m_fZahlFaktor(1), m_bFirstTime(true)
{
	//{{AFX_DATA_INIT(CGrafMathDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGrafMathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGrafMathDlg)
	DDX_Control(pDX, IDC_BUTTON_VIEW_SAVE, m_btnAnsichtSpeichern);
	DDX_Control(pDX, IDC_BUTTON_VIEW_LOAD, m_btnAnsichtLaden);
	DDX_Control(pDX, IDC_BUTTON_HOCHTIEFPUNKT, m_btnHochtiefpunkt);
	DDX_Control(pDX, IDC_BUTTON_INPUT_FUNCTION, m_btnFunktionseingabe);
	DDX_Control(pDX, IDC_BUTTON_AXISOPTIONS, m_btnAxisOptions);
	DDX_Control(pDX, IDC_BUTTON_GETXYRANGE, m_btnGetXYRange);
	DDX_Control(pDX, IDC_BUTTON_ZOOMOUT_XYACHSE, m_btnZoomOutXYAchse);
	DDX_Control(pDX, IDC_BUTTON_ZOOMOUT_YACHSE, m_btnZoomOutYAchse);
	DDX_Control(pDX, IDC_BUTTON_ZOOMOUT_XACHSE, m_btnZoomOutXAchse);
	DDX_Control(pDX, IDC_BUTTON_ZOOMIN_XYACHSE, m_btnZoomInXYAchse);
	DDX_Control(pDX, IDC_BUTTON_ZOOMIN_YACHSE, m_btnZoomInYAchse);
	DDX_Control(pDX, IDC_BUTTON_ZOOMIN_XACHSE, m_btnZoomInXAchse);
	DDX_Control(pDX, IDC_BUTTON_SCHNITTPUNKT_YACHSE, m_btnSchnittpunktYAchse);
	DDX_Control(pDX, IDC_BUTTON_SCHNITTPUNKT_XACHSE, m_btnSchnittpunktXAchse);
	DDX_Control(pDX, IDC_BUTTON_TANGENTE, m_btnTangente);
	DDX_Control(pDX, IDC_BUTTON_STEIGUNG, m_btnSteigung);
	DDX_Control(pDX, IDC_BUTTON_ABLEITUNG, m_btnAbleitung);
	DDX_Control(pDX, IDC_BUTTON_WENDEPUNKT, m_btnWendepunkt);
	DDX_Control(pDX, IDC_BUTTON_DRAW, m_btnGraphZeichnen);
	DDX_Control(pDX, IDC_CANVAS, m_staticCanvas);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGrafMathDlg, CDialog)
	//{{AFX_MSG_MAP(CGrafMathDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DRAW, OnButtonParseAndDraw)
	ON_BN_CLICKED(IDC_BUTTON_WENDEPUNKT, OnButtonWendepunkt)
	ON_BN_CLICKED(IDC_BUTTON_ABLEITUNG, OnButtonAbleitung)
	ON_BN_CLICKED(IDC_BUTTON_TANGENTE, OnButtonTangente)
	ON_BN_CLICKED(IDC_BUTTON_STEIGUNG, OnButtonSteigung)
	ON_BN_CLICKED(IDC_BUTTON_SCHNITTPUNKT_XACHSE, OnButtonSchnittpunktXachse)
	ON_BN_CLICKED(IDC_BUTTON_SCHNITTPUNKT_YACHSE, OnButtonSchnittpunktYachse)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_ZOOMOUT_XYACHSE, OnButtonZoomoutXyachse)
	ON_BN_CLICKED(IDC_BUTTON_ZOOMIN_XYACHSE, OnButtonZoominXyachse)
	ON_BN_CLICKED(IDC_BUTTON_ZOOMOUT_YACHSE, OnButtonZoomoutYachse)
	ON_BN_CLICKED(IDC_BUTTON_ZOOMIN_YACHSE, OnButtonZoominYachse)
	ON_BN_CLICKED(IDC_BUTTON_ZOOMOUT_XACHSE, OnButtonZoomoutXachse)
	ON_BN_CLICKED(IDC_BUTTON_ZOOMIN_XACHSE, OnButtonZoominXachse)
	ON_BN_CLICKED(IDC_BUTTON_GETXYRANGE, OnButtonGetXYRange)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDD_ABOUTBOX, OnAboutbox)
	ON_COMMAND(ID_MNU_APP_HILFE, OnMnuAppHilfe)
	ON_COMMAND(ID_MNU_MISC_ABLEITUNGEN, OnMnuMiscAbleitungen)
	ON_COMMAND(ID_MNU_MISC_GAUSS_ELIMINATION, OnMnuMiscGaussElimination)
	ON_COMMAND(ID_MNU_MISC_TANGENTE_GLEICHUNG, OnMnuMiscTangenteGleichung)
 	ON_COMMAND(ID_MNU_PUNKT_HOCHTIEF, OnMnuPunktHochtief)
	ON_COMMAND(ID_MNU_PUNKT_WENDESTELLE, OnMnuPunktWendestelle)
	ON_COMMAND(ID_MNU_PUNKT_SCHNITTSTELLEN_XACHSE, OnMnuPunktSchnittstellenXachse)
	ON_COMMAND(ID_MNU_PUNKT_SCHNITTSTELLEN_YACHSE, OnMnuPunktSchnittstellenYachse)
	ON_BN_CLICKED(IDC_BUTTON_AXISOPTIONS, OnButtonAxisOptions)
	ON_BN_CLICKED(IDC_BUTTON_INPUT_FUNCTION, OnButtonInputFunction)
	ON_WM_MOUSEWHEEL()
	ON_COMMAND(ID_MNU_MISC_STEIGUNG, OnMnuMiscSteigung)
	ON_COMMAND(ID_MNU_FUNKTION_EINGEBEN, OnMnuFunktionEingeben)
	ON_COMMAND(ID_MNU_FUNKTION_EINGEBENUNDZEICHNEN, OnMnuFunktionEingebenUndZeichnen)
	ON_COMMAND(ID_MNU_FUNKTION_ZEICHNEN, OnMnuFunktionZeichnen)
	ON_BN_CLICKED(IDC_BUTTON_HOCHTIEFPUNKT, OnButtonHochtiefpunkt)
	ON_COMMAND(ID_MNU_MISC_ACHSENSYMMETRIE, OnMnuMiscAchsensymmetrie)
	ON_COMMAND(ID_MNU_ACHSEN_ACHSENSKALIERUNG_ZOOMIN_XY, OnMnuAchsenAchsenskalierungZoominXY)
	ON_COMMAND(ID_MNU_ACHSEN_ACHSENSKALIERUNG_ZOOMOUT_XY, OnMnuAchsenAchsenskalierungZoomoutXY)
	ON_COMMAND(ID_MNU_ACHSEN_ANZEIGE_SKALIERUNG, OnMnuAchsenAnzeigeSkalierung)
	ON_COMMAND(ID_MNU_ACHSEN_EINSTELLUNGEN, OnMnuAchsenEinstellungen)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_LOAD, OnButtonViewLoad)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_SAVE, OnButtonViewSave)
	ON_COMMAND(ID_MNU_APP_ANSICHTLADEN, OnMnuAppAnsichtLaden)
	ON_COMMAND(ID_MNU_APP_ANSICHTSPEICHERN, OnMnuAppAnsichtSpeichern)
	ON_COMMAND(ID_MNU_MISC_WERTETABELLE, OnMnuMiscWertetabelle)
	ON_COMMAND(ID_MNU_APP_CREDITS, OnMnuAppCredits)
	ON_COMMAND(ID_MNU_MISC_AUFLEITUNG, OnMnuMiscAufleitung)
	ON_COMMAND(ID_MNU_MISC_FLAECHENBERECHNUNG, OnMnuMiscFlaechenberechnung)
	ON_COMMAND(ID_MNU_MISC_MONOTONIE, OnMnuMiscMonotonie)
	ON_COMMAND(ID_MNU_PUNKT_SCHEITELPUNKT, OnMnuPunktScheitelpunkt)
	ON_COMMAND(ID_MNU_MISC_LAENGE2P, OnMnuMiscLaengeZwischen2Punkten)
	ON_COMMAND(ID_MNU_MISC_YAUSX, OnMnuMiscYausX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGrafMathDlg message handlers

BOOL CGrafMathDlg::OnInitDialog()
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
	SetIcon(m_hIcon, TRUE);	 // Set big icon
	SetIcon(m_hIcon, FALSE); // Set small icon

  EnableThemeDialogTexture(GetSafeHwnd());

  // Member-Varialen für die Achsenskalierung
	m_fXValueMin = -4; // minimaler Wert auf der X-Achse
	m_fXValueMax = +4; // maximaler Wert auf der X-Achse
	m_fYValueMin = -4; // minimaler Wert auf der Y-Achse
  m_fYValueMax = +4; // maximaler Wert auf der Y-Achse

  m_nAxisDivision = 10;
  m_nHelpAxisWidth = 4;
  m_nDecimalPlaces = 2;
  m_bAxisDescription = true;

  //Member-Variable als CArray dient zum Speichern der Koeffizienten einer Funktion 3. Grades
  m_arrFunction.SetSize(4); // Größe des CArray setzen
  m_arrFunction.SetAt(0,0); // entspricht d aus d*x^0
  m_arrFunction.SetAt(1,0); // entspricht c aus c*x^1
  m_arrFunction.SetAt(2,2); // entspricht b aus b*x^2
  m_arrFunction.SetAt(3,1); // entspricht a aus a*x^3
  m_arrFunction2.SetSize(4); // Größe des CArray setzen

  for (int i = 0; i < m_arrFunction.GetSize(); i++)
  {
    m_arrDerivatedFunction[i].SetSize(4);
    for (int j = 0; j < m_arrDerivatedFunction[i].GetSize(); j++) m_arrDerivatedFunction[i].SetAt(j,0);
  }

  m_fSizeFaktor = m_fSizeFaktor;
  
  CRect rect;
  // Anfangsposition der Zeichenfläche ermitteln
  GetDlgItem(IDC_CANVAS)->GetWindowRect(rect);
  // Anfangsposition korrigieren und in Member-Variablen abspeichern
  m_nXCorr = rect.left-2*GetSystemMetrics(SM_CXBORDER);
  // XP -1
  // Vista -6
  m_nYCorr = rect.top-GetSystemMetrics(SM_CYMENU)-GetSystemMetrics(SM_CYCAPTION)-GetSystemMetrics(SM_CYSIZEFRAME)+1;

  m_btnFunktionseingabe.SetThemeHelper(&m_ThemeHelper);
  //m_btnFunktionseingabe.SetIcon(IDI_ICON_TIEFPUNKT16);
  m_btnFunktionseingabe.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnFunktionseingabe.EnableBalloonTooltip();
  m_btnFunktionseingabe.SetTooltipText("Funktionseingabe");
	
  m_btnAnsichtLaden.SetThemeHelper(&m_ThemeHelper);
  m_btnAnsichtLaden.SetIcon(IDI_ICON_OPEN);
  m_btnAnsichtLaden.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAnsichtLaden.EnableBalloonTooltip();
  m_btnAnsichtLaden.SetTooltipText("Ansicht laden");
	
  m_btnAnsichtSpeichern.SetThemeHelper(&m_ThemeHelper);
  m_btnAnsichtSpeichern.SetIcon(IDI_ICON_SAVE);
  m_btnAnsichtSpeichern.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAnsichtSpeichern.EnableBalloonTooltip();
  m_btnAnsichtSpeichern.SetTooltipText("Ansicht speichern");
	
  m_btnHochtiefpunkt.SetThemeHelper(&m_ThemeHelper);
  m_btnHochtiefpunkt.SetIcon(IDI_ICON_TIEFPUNKT16);
  m_btnHochtiefpunkt.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnHochtiefpunkt.EnableBalloonTooltip();
  m_btnHochtiefpunkt.SetTooltipText("Hoch- und Tiefpunkt");
	
  m_btnWendepunkt.SetThemeHelper(&m_ThemeHelper);
  m_btnWendepunkt.SetIcon(IDI_ICON_WENDEPUNKT16);
  m_btnWendepunkt.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnWendepunkt.EnableBalloonTooltip();
  m_btnWendepunkt.SetTooltipText(ID_MNU_PUNKT_WENDESTELLE);

  m_btnAbleitung.SetThemeHelper(&m_ThemeHelper);
  m_btnAbleitung.SetIcon(IDI_ICON_ABLEITUNG16);
  m_btnAbleitung.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAbleitung.EnableBalloonTooltip();
  m_btnAbleitung.SetTooltipText(ID_MNU_MISC_ABLEITUNGEN);
	
  m_btnTangente.SetThemeHelper(&m_ThemeHelper);
  m_btnTangente.SetIcon(IDI_ICON_TANGENTE16);
  m_btnTangente.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnTangente.EnableBalloonTooltip();
  m_btnTangente.SetTooltipText("Tangente");
	
  m_btnSteigung.SetThemeHelper(&m_ThemeHelper);
  m_btnSteigung.SetIcon(IDI_ICON_STEIGUNG16);
  m_btnSteigung.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSteigung.EnableBalloonTooltip();
  m_btnSteigung.SetTooltipText(ID_MNU_PUNKT_WENDESTELLE);

  m_btnSchnittpunktXAchse.SetThemeHelper(&m_ThemeHelper);
  m_btnSchnittpunktXAchse.SetIcon(IDI_ICON_SCHNITTPUNKT_XACHSE16);
  m_btnSchnittpunktXAchse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSchnittpunktXAchse.EnableBalloonTooltip();
  m_btnSchnittpunktXAchse.SetTooltipText(IDS_SCHNITTPUNKT_YACHSE);
  
  m_btnSchnittpunktYAchse.SetThemeHelper(&m_ThemeHelper);
  m_btnSchnittpunktYAchse.SetIcon(IDI_ICON_SCHNITTPUNKT_YACHSE16);
  m_btnSchnittpunktYAchse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSchnittpunktYAchse.EnableBalloonTooltip();
  m_btnSchnittpunktYAchse.SetTooltipText(IDS_SCHNITTPUNKT_YACHSE);
  
  m_btnGraphZeichnen.SetThemeHelper(&m_ThemeHelper);
  m_btnGraphZeichnen.SetIcon(IDI_ICON_GRAPH16);
  m_btnGraphZeichnen.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnGraphZeichnen.EnableBalloonTooltip();
  m_btnGraphZeichnen.SetTooltipText(IDS_GRAPHZEICHNEN);

  m_btnZoomOutXYAchse.SetThemeHelper(&m_ThemeHelper);
  m_btnZoomOutXYAchse.SetIcon(IDI_ICON_ZOOMOUT_XYACHSE16);
  m_btnZoomOutXYAchse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnZoomOutXYAchse.EnableBalloonTooltip();
  m_btnZoomOutXYAchse.SetTooltipText(IDS_ZOOMOUT_XYACHSE);

  m_btnZoomInXYAchse.SetThemeHelper(&m_ThemeHelper);
  m_btnZoomInXYAchse.SetIcon(IDI_ICON_ZOOMIN_XYACHSE16);
  m_btnZoomInXYAchse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnZoomInXYAchse.EnableBalloonTooltip();
  m_btnZoomInXYAchse.SetTooltipText(IDS_ZOOMIN_XYACHSE);

  m_btnZoomOutXAchse.SetThemeHelper(&m_ThemeHelper);
  m_btnZoomOutXAchse.SetIcon(IDI_ICON_ZOOMOUT_XACHSE16);
  m_btnZoomOutXAchse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnZoomOutXAchse.EnableBalloonTooltip();
  m_btnZoomOutXAchse.SetTooltipText(IDS_ZOOMOUT_XACHSE);

  m_btnZoomInXAchse.SetThemeHelper(&m_ThemeHelper);
  m_btnZoomInXAchse.SetIcon(IDI_ICON_ZOOMIN_XACHSE16);
  m_btnZoomInXAchse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnZoomInXAchse.EnableBalloonTooltip();
  m_btnZoomInXAchse.SetTooltipText(IDS_ZOOMIN_XACHSE);

  m_btnZoomOutYAchse.SetThemeHelper(&m_ThemeHelper);
  m_btnZoomOutYAchse.SetIcon(IDI_ICON_ZOOMOUT_YACHSE16);
  m_btnZoomOutYAchse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnZoomOutYAchse.EnableBalloonTooltip();
  m_btnZoomOutYAchse.SetTooltipText(IDS_ZOOMOUT_YACHSE);

  m_btnZoomInYAchse.SetThemeHelper(&m_ThemeHelper);
  m_btnZoomInYAchse.SetIcon(IDI_ICON_ZOOMIN_YACHSE16);
  m_btnZoomInYAchse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnZoomInYAchse.EnableBalloonTooltip();
  m_btnZoomInYAchse.SetTooltipText(IDS_ZOOMIN_YACHSE);

  m_btnGetXYRange.SetThemeHelper(&m_ThemeHelper);
  m_btnGetXYRange.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnGetXYRange.EnableBalloonTooltip();
  m_btnGetXYRange.SetTooltipText(IDS_GETXYRANGE);

  m_btnAxisOptions.SetThemeHelper(&m_ThemeHelper);
  m_btnAxisOptions.SetIcon(IDI_ICON_AXISOPTIONS);
  m_btnAxisOptions.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAxisOptions.EnableBalloonTooltip();
  m_btnAxisOptions.SetTooltipText(IDS_AXISOPTIONS);	

  // Beschriftungsfelder für die Statuszeile deklarieren/initialisieren
  static UINT BASED_CODE indicators[] =
  {                                    
    IDS_INDICATOR_NISH,
    IDS_INDICATOR_TIME
  };
  // Statusbar erstellen und die Beschriftungsfelder zuweisen
  m_StatusBar.Create(this);
  m_StatusBar.SetIndicators(indicators,2);
  m_StatusBar.SetPaneInfo(0,IDS_INDICATOR_NISH,SBPS_NORMAL,315);
  m_StatusBar.SetPaneInfo(1,IDS_INDICATOR_TIME,SBPS_STRETCH,0);
  RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,IDS_INDICATOR_TIME);
  // einen Timer auf 100 Millisekunden setzen
  SetTimer(100,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGrafMathDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGrafMathDlg::OnPaint() 
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
		CGrafMathDlg::DrawCanvas();
		CClientDC myDC(this);
		CGrafMathDlg::DrawSection(m_cpLeftFenst,m_cpRightFenst,myDC, 0);

	}
  CDialog::OnPaint();
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGrafMathDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();  
  
  EnableThemeDialogTexture(GetSafeHwnd());

  m_MailAdrStein.SetURL(_T("mailto:i7stein@szut.de"));
	m_MailAdrJohne.SetURL(_T("mailto:i7johne@szut.de"));
	m_MailAdrAvcu.SetURL(_T("mailto:i7avcu@szut.de"));
	m_MailAdrSpielmann.SetURL(_T("mailto:i7spiel@szut.de"));

  m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText("");

  UpdateData(false);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonParseAndDraw() 
// ---------------------------------------------
//
//  Diese Funktion parst die eingegebene Funktion und prüft die Eingabe auf mögliche Fehler.
//  Anschließend wird der Graph der Funktion gezeichnet.
//
/***********************************************************************************************************/

void CGrafMathDlg::OnButtonParseAndDraw() 
{ 
  for (int i = 0; i < m_arrFunction.GetSize(); i++) m_arrFunction.SetAt(i,m_arrFunction2.GetAt(i));
  // Aufrufen, wenn eine eingegebene Funktion neu gezeichnet wird
  CGrafMathDlg::DrawCanvas();
  CClientDC myDc(this);
  CGrafMathDlg::DrawSection(m_cpLeftFenst,m_cpRightFenst,myDc,0);
  CGrafMathDlg::DrawFunction();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::DerivateAll()
// ------------------------------------
//
//  Diese Funktion ermittelt alle Ableitung einer mathematischen Funktion.
//
/***********************************************************************************************************/
void CGrafMathDlg::DerivateAll() 
{
  for (int i = 0; i < m_arrFunction.GetSize(); i++)
  {
    m_arrDerivatedFunction[0].SetAt(i,float(1.0*m_arrFunction.GetAt(i)));
  }
  for (i = 1; i < m_arrFunction.GetSize(); i++)
  {
    for (int j = m_arrDerivatedFunction[i].GetSize()-1; j > 0; j--)
    {
      m_arrDerivatedFunction[i].SetAt(j-1,m_arrDerivatedFunction[i-1].GetAt(j)*(j));
    }
  }
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonHochtiefpunkt() 
// ----------------------------------------------
//
//  Hoch- und Tiefpunkte bei Button
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonHochtiefpunkt() 
{
  CString strOutp1 = _T(""),strOutp2 = _T(""),strOutp3 = _T("");
  CArray<float,float> m_arrZero;
  int nHP = 0;
  float
    fTemp = 0,fP = 0,fQ = 0,fDiskriminante = 0;
	DerivateAll();

  if (m_arrDerivatedFunction[1].GetAt(2) != 0)
  {
    fP = m_arrDerivatedFunction[1].GetAt(1)/m_arrDerivatedFunction[1].GetAt(2);
    fQ = m_arrDerivatedFunction[1].GetAt(0)/m_arrDerivatedFunction[1].GetAt(2);
    fDiskriminante = ((fP*fP)/4)-(fQ);
    if (fDiskriminante >= 0)
    {
      m_arrZero.Add(-(fP/2)+float(sqrt(((fP*fP)/4)-fQ)));
      if (fDiskriminante > 0) m_arrZero.Add(-(fP/2)-float(sqrt(((fP*fP)/4)-fQ)));
      if (-((1.0*m_arrDerivatedFunction[2].GetAt(0))/(1.0*m_arrDerivatedFunction[2].GetAt(1))) == 0) nHP = 0;
      if (-((1.0*m_arrDerivatedFunction[2].GetAt(0))/(1.0*m_arrDerivatedFunction[2].GetAt(1)))  < 0) nHP = -1;
      if (-((1.0*m_arrDerivatedFunction[2].GetAt(0))/(1.0*m_arrDerivatedFunction[2].GetAt(1)))  > 0) nHP = 1;
    } else strOutp1 = _T("Es sind keine Hoch- und Tiefpunkte vorhanden.");
  } else strOutp1 = _T("Es sind keine Hoch- und Tiefpunkte vorhanden.");
  
  if (m_arrZero.GetUpperBound() != (-1))
  {
    strOutp1 += _T("Die Hoch- und Tiefpunkte wurden ermittelt.\n");
    strOutp1 += _T("Sie lauten:\n\n");
    for (int i = 0; i < m_arrZero.GetSize(); i++)
    {
      if ((m_arrDerivatedFunction[2].GetAt(1)*(m_arrZero.GetAt(i)))+m_arrDerivatedFunction[2].GetAt(0) == 0) nHP = 0;
      if ((m_arrDerivatedFunction[2].GetAt(1)*(m_arrZero.GetAt(i)))+m_arrDerivatedFunction[2].GetAt(0) > 0) nHP = -1;
      if ((m_arrDerivatedFunction[2].GetAt(1)*(m_arrZero.GetAt(i)))+m_arrDerivatedFunction[2].GetAt(0) < 0) nHP = 1;

      if (nHP == 0)  strOutp1 += _T("      P(");
      if (nHP == 1)  strOutp1 += _T("      H(");
      if (nHP == -1) strOutp1 += _T("      T(");
      strOutp3 = _T("%0.3f");
      strOutp2.Format(strOutp3,m_arrZero.GetAt(i));
      strOutp1 += strOutp2;
      strOutp1 += _T(" | ");
      strOutp3 = _T("%0.3f");
      strOutp2.Format(strOutp3,GetYofFunction(m_arrZero.GetAt(i)));
      strOutp1 += strOutp2;
      strOutp1 += _T(")\n");
    }
  }
  MessageBox(strOutp1,_T("Hoch- und Tiefpunkte"),MB_OK+MB_ICONINFORMATION);//MB_ICONQUESTION + MB_YESNO
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonWendepunkt() 
// -------------------------------------------
//
//  Wendepunkt bei Button
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonWendepunkt() 
{
  CString strOutp1 = _T(""),strOutp2 = _T(""),strOutp3 = _T("");
  float fTemp = 0,fX = 0,fY = 0;
	DerivateAll();
  if (m_arrFunction.GetAt(3) != 0)
  {    
    float fX = -(m_arrDerivatedFunction[2].GetAt(0)/m_arrDerivatedFunction[2].GetAt(1));
    if (m_arrDerivatedFunction[3].GetAt(0) != 0)
    {
      fY = GetYofFunction(fX);
      strOutp1 += _T("Die Wende wurde ermittelt.\n");
      strOutp1 += _T("Sie lautet:\n\n");
      strOutp1 += _T("      W(");
      strOutp3 = _T("%0.3f");
      strOutp2.Format(strOutp3,fX);
      strOutp1 += strOutp2;
      strOutp1 += _T(" | ");
      strOutp3 = _T("%0.3f");
      strOutp2.Format(strOutp3,fY);
      strOutp1 += strOutp2;

      strOutp1 += _T(")\n");
    } else strOutp1 = _T("Es sind keine Wendestellen vorhanden.");  
  } else strOutp1 = _T("Es sind keine Wendestellen vorhanden.");
  MessageBox(strOutp1,_T("Wendestelle"),MB_OK+MB_ICONINFORMATION);//MB_ICONQUESTION + MB_YESNO
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonAbleitung()  
// ------------------------------------------
//
//  Ableitung bei Button
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonAbleitung() 
{
  DerivateAll();
  
  CString
    strOutp1 = _T(""),
    strOutp2 = _T(""),
    strOutp3 = _T(""),
    strOutp4 = _T("");

  strOutp1 += _T("Die Ableitungen wurden ermittelt.\n");
  strOutp1 += _T("Es sind:\n\n");
  for (int i = 0; i < m_arrFunction.GetSize(); i++)
  {
    strOutp1 += _T("   -   f");
    for (int j = 0; j < i; j++) strOutp1 += _T("'");
    strOutp1 += _T("(x)");
    for (j = m_arrFunction.GetSize()-i; j > 0; j--) strOutp1 += _T(" ");
    strOutp1 += _T(" = ");
    for (j = m_arrFunction.GetSize()-1; j >= 0; j--)
    {
      if (m_arrDerivatedFunction[i].GetAt(j) != 0)
      {
        if (m_arrDerivatedFunction[i].GetAt(j) > 0) strOutp1 += _T(" + "); else 
          if (m_arrDerivatedFunction[i].GetAt(j) < 0) strOutp1 += _T(" ");
        float ftemp = m_arrDerivatedFunction[i].GetAt(j);
        if (ftemp < 0) ftemp = ftemp*(-1);
        if ((ftemp-fabs(m_arrDerivatedFunction[i].GetAt(j))) == 0) strOutp3 = _T("%0.0f"); else strOutp3 = _T("%0.3f");
        strOutp2.Format(strOutp3,m_arrDerivatedFunction[i].GetAt(j));
        strOutp1 += strOutp2;
        if (j != 0)
        {
          strOutp1 += _T("x^");
          strOutp4.Format(_T("%d"),j);
          strOutp1 += strOutp4;
        }
      }
    }
    strOutp1 += _T("\n");
  }
  MessageBox(strOutp1,_T("Ableitungen"),MB_OK+MB_ICONINFORMATION);//MB_ICONQUESTION + MB_YESNO
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonTangente() 
// -----------------------------------------
//
//  Tangente bei Button
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonTangente() 
{
	CTangentDlg dlgTangent;
  dlgTangent.m_arrFunction.SetSize(m_arrFunction.GetSize());
  dlgTangent.m_arr1stDerivatedFunction.SetSize(m_arrFunction.GetSize());
  DerivateAll();
  for (int i = 0; i < m_arrDerivatedFunction[1].GetSize(); i++) dlgTangent.m_arr1stDerivatedFunction.SetAt(i,m_arrDerivatedFunction[1].GetAt(i));
  for (i = 0; i < m_arrFunction.GetSize(); i++) dlgTangent.m_arrFunction.SetAt(i,m_arrFunction.GetAt(i));
  dlgTangent.DoModal();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonSteigung() 
// -----------------------------------------
//
//  Steigung bei Button
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonSteigung() 
{
	CGradientDlg dlgGradient;
  dlgGradient.m_arr1stDerivatedFunction.SetSize(m_arrFunction.GetSize());
  DerivateAll();
  for (int i = 0; i < m_arrDerivatedFunction[1].GetSize(); i++) dlgGradient.m_arr1stDerivatedFunction.SetAt(i,m_arrDerivatedFunction[1].GetAt(i));
  dlgGradient.DoModal();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonSchnittpunktXachse() 
// ---------------------------------------------------
//
//  Schnittpunkt mit X-Achse bei Button
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonSchnittpunktXachse() 
{
  CString strOutp1 = _T(""),strOutp2 = _T(""),strOutp3 = _T("");
  CArray<float,float> m_arrZero,m_arrZero2;
  float fX = 0,fTemp = 0;
  float fQ,fP,fDiskriminante;

  if ((m_arrFunction.GetAt(0) == 0) && 
      (m_arrFunction.GetAt(1) == 0) && 
      (m_arrFunction.GetAt(2) == 0) && 
      (m_arrFunction.GetAt(3) == 0)) strOutp1 = _T("Es sind unendliche Schnittpunkte mit der X-Achse vorhanden."); 

  if ((m_arrFunction.GetAt(0) != 0) && 
      (m_arrFunction.GetAt(1) == 0) && 
      (m_arrFunction.GetAt(2) == 0) && 
      (m_arrFunction.GetAt(3) == 0)) strOutp1 = _T("Es sind keine Schnittpunkte mit der X-Achse vorhanden.");

  if ((m_arrFunction.GetAt(0) != 0) && 
      (m_arrFunction.GetAt(1) != 0) && 
      (m_arrFunction.GetAt(2) == 0) && 
      (m_arrFunction.GetAt(3) == 0)) m_arrZero.Add(-(m_arrFunction.GetAt(0))/m_arrFunction.GetAt(1));


  if ((m_arrFunction.GetAt(2) != 0) && 
      (m_arrFunction.GetAt(3) == 0)) 
  {    
    fP = m_arrFunction.GetAt(1)/m_arrFunction.GetAt(2);
    fQ = m_arrFunction.GetAt(0)/m_arrFunction.GetAt(2);
    fDiskriminante = ((fP*fP)/4)-fQ;
    if (fDiskriminante >= 0)
    {
      m_arrZero.Add(-(fP/2)+float(sqrt(((fP*fP)/4)-fQ)));
      if (fDiskriminante > 0) m_arrZero.Add(-(fP/2)-float(sqrt(((fP*fP)/4)-fQ)));
    } else strOutp1 = _T("Es sind keine Schnittpunkte mit der X-Achse vorhanden.");
  }




  if (m_arrFunction.GetAt(3) != 0)
  {
    if ((m_arrFunction.GetAt(3) == 1) || (m_arrFunction.GetAt(3) == -1)) m_arrZero.Add(0); else
    {
      if (m_arrFunction.GetAt(2) != 0) m_arrZero2.Add(m_arrFunction.GetAt(2)/m_arrFunction.GetAt(3));
      if (m_arrFunction.GetAt(1) != 0) m_arrZero2.Add(m_arrFunction.GetAt(1)/m_arrFunction.GetAt(3));
      if (m_arrFunction.GetAt(0) != 0) m_arrZero2.Add(m_arrFunction.GetAt(0)/m_arrFunction.GetAt(3));
      if (m_arrZero2.GetAt(2) != 0)
      {
        fP = m_arrZero2.GetAt(1)/m_arrZero2.GetAt(2);
        fQ = m_arrZero2.GetAt(0)/m_arrZero2.GetAt(2);
        fDiskriminante = ((fP*fP)/4)-(fQ);
        if (fDiskriminante >= 0)
        {
          m_arrZero.Add(-(fP/2)+float(sqrt((fP*fP)/4)-fQ));
          if (fDiskriminante > 0) m_arrZero.Add(-(fP/2)-float(sqrt((fP*fP)/4)-fQ));
        };
        if ((m_arrZero2.GetAt(0) != 0) && 
            (m_arrZero2.GetAt(1) != 0) && 
            (m_arrZero2.GetAt(2) == 0)) m_arrZero.Add(-(m_arrZero2.GetAt(0)/m_arrZero2.GetAt(1)));
      } 
    }
  }
  



  if (m_arrZero.GetUpperBound() != (-1))
  {
    strOutp1 += _T("Die Schnittpunkte mit der X-Achse wurden ermittelt.\n");
    strOutp1 += _T("Sie lauten:\n\n");
    for (int i = 0; i < m_arrZero.GetSize(); i++)
    {
      strOutp1 += _T("      S_x(");
      strOutp3 = _T("%0.3f");
      strOutp2.Format(strOutp3,m_arrZero.GetAt(i));
      strOutp1 += strOutp2;
      strOutp1 += _T(" | 0)\n");
    }
  }

  MessageBox(strOutp1,_T("Schnittpunkte mit der X-Achse"),MB_OK+MB_ICONINFORMATION);
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonSchnittpunktYachse() 
// ---------------------------------------------------
//
//  Schnittpunkt mit Y-Achse bei Button
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonSchnittpunktYachse() 
{
  CString strOutp1 = _T(""),strOutp2 = _T(""),strOutp3 = _T("");
  float
    fTemp = 0,
    fY = GetYofFunction(0);

  strOutp1 += _T("Der Schnittpunkt mit der Y_Achse wurde ermittelt.\n");
  strOutp1 += _T("Er lautet:\n\n");
  strOutp1 += _T("      S_y(0 | ");
  strOutp3 = _T("%0.3f");
  strOutp2.Format(strOutp3,fY);
  strOutp1 += strOutp2;
  strOutp1 += _T(")\n");
  MessageBox(strOutp1,_T("Schnittpunkt mit der Y-Achse"),MB_OK+MB_ICONINFORMATION);//MB_ICONQUESTION + MB_YESNO
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnTimer(UINT nIDEvent) 
// ---------------------------------------------
//
//  Diese Funktion wird ausgelöst, wenn der Timer sein Maximum erreicht hat.
//  Die ermittelte Uhrzeit wird danach in der Statuszeile angezeigt.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnTimer(UINT nIDEvent) 
{
  // Timer ausführen, wenn 100 Millisekunden erreicht sind
  if(nIDEvent == 100) 
  {
    CTime Time;
    Time = CTime::GetCurrentTime(); // aktuelle Zeit ermitteln...
    // ... und im Beschriftungsfeld eintragen
    m_StatusBar.SetPaneText(1,Time.Format("%y-%m-%d %H:%M:%S"));
  }	
	CDialog::OnTimer(nIDEvent);
}

/***********************************************************************************************************/
//   BOOL CGrafMathDlg::PreTranslateMessage(MSG* pMsg) 
// -----------------------------------------------------
//
//  Diese Funktion wird automatisch aufgerufen, wenn eine Nachricht ausgelöst wird.
//  Bevor die Nachricht behandelt wird, gibt es die Möglichkeit, eine Art "Vorauswahl" zu treffen.
//  Diese Funktion ermittelt, ob der Mauszeiger sich über bestimmte Button befindet und gibt
//  je nach Button einen entsprechenden Hilfstext an die Statuszeile aus.
//
/***********************************************************************************************************/
BOOL CGrafMathDlg::PreTranslateMessage(MSG* pMsg) 
{
	CString strStaticTooltip;
  if (pMsg->message == WM_MOUSEMOVE) // Wenn die Maus bewegt wird,
  // überprüfen, über welchen Kontroll sich die Maus befindet und die entsprechende Statusmeldung ausgeben.
	{
	  if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_DRAW)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_BUTTON_DRAW);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_VIEW_LOAD)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ANSICHT_LADEN);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_VIEW_SAVE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ANSICHT_SPEICHERN);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_SCHNITTPUNKT_XACHSE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_SCHNITTPUNKT_XACHSE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_SCHNITTPUNKT_YACHSE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_SCHNITTPUNKT_YACHSE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_HOCHTIEFPUNKT)->m_hWnd)
    {
      strStaticTooltip.LoadString(ID_MNU_PUNKT_HOCHTIEF);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_WENDEPUNKT)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_WENDESTELLE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_ABLEITUNG)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ABLEITUNG);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_STEIGUNG)->m_hWnd)
    {
      strStaticTooltip.LoadString(ID_MNU_MISC_STEIGUNG);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_TANGENTE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_TANGENTE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_ZOOMOUT_XYACHSE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ZOOMOUT_XYACHSE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_ZOOMIN_XYACHSE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ZOOMIN_XYACHSE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);

    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_ZOOMOUT_XACHSE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ZOOMOUT_XACHSE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_ZOOMIN_XACHSE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ZOOMIN_XACHSE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);

    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_ZOOMOUT_YACHSE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ZOOMOUT_YACHSE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_ZOOMIN_YACHSE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_ZOOMIN_YACHSE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
      
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_GETXYRANGE)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_GETXYRANGE);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_AXISOPTIONS)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_AXISOPTIONS);
      m_StatusBar.SetPaneText(0,strStaticTooltip);
    } else if (pMsg->hwnd == GetDlgItem(IDC_BUTTON_INPUT_FUNCTION)->m_hWnd)
    {
      strStaticTooltip.LoadString(IDS_INPUTFUNCTION);
      m_StatusBar.SetPaneText(0,strStaticTooltip);      
    } else m_StatusBar.SetPaneText(0,"");
  }
	return CDialog::PreTranslateMessage(pMsg);
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonZoominXachse() 
// ---------------------------------------------
//
//  Diese Funktion vergrößert die Skalierungsbereich der X-Achse.
//  Anschließend wird Zeichenoberfläche mit den Koordinatenachsen neu gezeichnet.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonZoominXachse() 
{
  // Skalierungsbereich der X-Achse vergrößern
 	CClientDC myDC(this);
	CGrafMathDlg::DrawCanvas();
  DrawSection(m_cpLeftFenst,m_cpRightFenst,myDC,-1);
	m_fDistanceSize *= 2;
	//m_fZahlFaktor *= 2;
	//m_fSizeFaktor *= 2;
	
  m_fXValueMin = m_fXValueMin/2;
	m_fXValueMax = -(m_fXValueMin);
  // anschließend die Zeichenoberfläche mit Achsen & Graphen neuzeichnen
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonZoomoutXachse() 
// ----------------------------------------------
//
//  Diese Funktion verkleinert die Skalierungsbereich der X-Achse.
//  Anschließend wird Zeichenoberfläche mit den Koordinatenachsen neu gezeichnet.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonZoomoutXachse() 
{
 	CClientDC myDC(this);
	CGrafMathDlg::DrawCanvas();
  DrawSection(m_cpLeftFenst,m_cpRightFenst,myDC,1);
	m_fDistanceSize /= 2;
	//m_fZahlFaktor /= 2;
	//m_fSizeFaktor /= 2;

  // Skalierungsbereich der X-Achse verkleinern
	m_fXValueMin = m_fXValueMin*2;
	m_fXValueMax = -(m_fXValueMin);
  // anschließend die Zeichenoberfläche mit Achsen & Graphen neuzeichnen
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonZoominYachse() 
// ---------------------------------------------
//
//  Diese Funktion vergrößert die Skalierungsbereich der Y-Achse.
//  Anschließend wird Zeichenoberfläche mit den Koordinatenachsen neu gezeichnet.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonZoominYachse() 
{
  // Skalierungsbereich der Y-Achse vergrößern
	m_fYValueMin = m_fYValueMin/2;
	m_fYValueMax = -(m_fYValueMin);
  // anschließend die Zeichenoberfläche mit Achsen & Graphen neuzeichnen
  CGrafMathDlg::DrawCanvas();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonZoomoutYachse() 
// ----------------------------------------------
//
//  Diese Funktion verkleinert die Skalierungsbereich der Y-Achse.
//  Anschließend wird Zeichenoberfläche mit den Koordinatenachsen neu gezeichnet.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonZoomoutYachse() 
{
  // Skalierungsbereich der X-Achse verkleinern
	m_fYValueMin = m_fYValueMin*2;
	m_fYValueMax = -(m_fYValueMin);
  // anschließend die Zeichenoberfläche mit Achsen & Graphen neuzeichnen
  CGrafMathDlg::DrawCanvas();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonZoominXyachse() 
// ----------------------------------------------
//
//  Diese Funktion vergrößert die Skalierungsbereich der X- & Y-Achse.
//  Anschließend wird Zeichenoberfläche mit den Koordinatenachsen neu gezeichnet.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonZoominXyachse() 
{
 	CClientDC myDC(this);
	CGrafMathDlg::DrawCanvas();
  DrawSection(m_cpLeftFenst,m_cpRightFenst,myDC,-1);
/*
  // Skalierungsbereich der X- & Y-Achse verkleinern
	m_fXValueMin = m_fXValueMin/2;
	m_fXValueMax = -(m_fXValueMin);
	m_fYValueMin = m_fYValueMin/2;
	m_fYValueMax = -(m_fYValueMin);
  // anschließend die Zeichenoberfläche mit Achsen & Graphen neuzeichnen
  CGrafMathDlg::DrawCanvas();
*/
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonZoomoutXyachse() 
// -----------------------------------------------
//
//  Diese Funktion verkleinert die Skalierungsbereich der X- & Y-Achse.
//  Anschließend wird Zeichenoberfläche mit den Koordinatenachsen neu gezeichnet.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonZoomoutXyachse() 
{
 	CClientDC myDC(this);
	CGrafMathDlg::DrawCanvas();
  DrawSection(m_cpLeftFenst,m_cpRightFenst,myDC,1);
 /*
  // Skalierungsbereich der X- & Y-Achse vergrößern
	m_fXValueMin = m_fXValueMin*2;
	m_fXValueMax = -(m_fXValueMin);
	m_fYValueMin = m_fYValueMin*2;
	m_fYValueMax = -(m_fYValueMin);
  // anschließend die Zeichenoberfläche mit Achsen & Graphen neuzeichnen
  CGrafMathDlg::DrawCanvas();
*/
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonGetXYRange() 
// -------------------------------------------
//
//  Diese Funktion gibt die Skalierungswerte der X- & Y-Achse über eine Message-Box aus.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonGetXYRange() 
{
  CString strOutputMaster = _T("");
  // Skalierungswerte der X- & Y-Achse in der Nachricht formatieren
  strOutputMaster.Format("Skalierung der Achsen:\n\nMinimum X-Achse: %f\nMaximum X-Achse: %f\nMinimum Y-Achse: %f\nMaximum Y-Achse: %f",m_fXValueMin,m_fXValueMax,m_fYValueMin,m_fYValueMax);
  // und über eine Message-Box ausgeben
	MessageBox(strOutputMaster);
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMouseMove(UINT nFlags, CPoint point)  
// -------------------------------------------------------------
//
//  Diese Funktion wird automatisch aufgerufen. Sie bewirkt, dass die XY-Koordinaten in der Statusbar
//  angezeigt wird, wenn man die linke Maustaste im Koordinatensystem gedrückt hält.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
  // Größe der Zeichenoberfläche ermitteln...
  m_staticCanvas.GetClientRect(m_rctCanvasFormat);

  CPoint //.. und in Punkte abspeichern
    // Angaben der Koordinaten für die linke, obere Ecke relativ zum Client
    pntTopLeft = m_rctCanvasFormat.TopLeft(),
    // Angaben der Koordinaten für die rechte, untere Ecke relativ zum Client
    pntBottomRight = m_rctCanvasFormat.BottomRight();

	if ((nFlags & MK_LBUTTON) == MK_LBUTTON) // Wenn die linke Maustaste gedrückt wurde...
  {
    // und wenn sich der Mauszeiger innerhalb der Zeichenoberfläche befindet, ...
    if ((point.x >= pntTopLeft.x+m_nXCorr) && (point.x <= pntBottomRight.x+m_nXCorr) && (point.y >= pntTopLeft.y+m_nYCorr) && (point.y <= pntBottomRight.y+m_nYCorr))
    { // dann werden die Koordinaten des Mauszeigers in der Statusbar ausgegeben.
      float
        x = float(point.x-m_nXCorr), // X-Koordinate des Mauszeigers ermitteln
        y = float(point.y-m_nYCorr); // Y-Koordinate des Mauszeigers ermitteln

      // Koordinaten des Mauszeigers in X- & Y-Werte der Koordinatensystems umrechnen
      /* X-Wert des Mauszeiger für x < 0 */ if ((point.x >= pntTopLeft.x) && (point.x <= pntBottomRight.x/2)) x = m_fXValueMin-(m_fXValueMin*x)/(pntBottomRight.x/2);
      /* X-Wert des Mauszeiger für x > 0 */ if ((point.x >= pntBottomRight.x/2) && (point.x <= pntBottomRight.x+m_nXCorr)) x = (m_fXValueMax*x)/(pntBottomRight.x/2)-m_fXValueMax;
      /* Y-Wert des Mauszeiger für y < 0 */ if ((point.y >= pntTopLeft.y) && (point.y <= pntBottomRight.y/2)) y = m_fYValueMax-(m_fYValueMax*y)/(pntBottomRight.y/2);
      /* Y-Wert des Mauszeiger für y > 0 */ if ((point.y >= pntBottomRight.y/2) && (point.y <= pntBottomRight.y+m_nYCorr)) y = (m_fYValueMin*y)/(pntBottomRight.y/2)-m_fYValueMin;

      CString strOutp = _T("");
      strOutp.Format("X: %f  Y: %f",x,y); // formatierte Meldung in der Statusbar ausgeben
      m_StatusBar.SetPaneText(0,strOutp);
    }
  }	
	CDialog::OnMouseMove(nFlags, point);
}

/***********************************************************************************************************/
//   void CGrafMathDlg::DrawCanvas()
// -----------------------------------
//
//  Diese Funktion zeichnet die weiße Zeichenoberfläche mit den Koordinatenachsen und ihrer 
//  Beschriftung neu bzw. sie aktualisiert die Zeichenoberfläche.
//  Weißerhin zeichnet sie auch den Graphen der Funktion neu, weil z. B. die Achsenskalierung
//  verändert worden ist.
//
/***********************************************************************************************************/
void CGrafMathDlg::DrawCanvas()
{
	m_staticCanvas.RedrawWindow();   // Zeichenoberfläche hervorholen
	CRect myRect,myRectC,myHF,myHFC; //myRect für die Kordinaten der Zeichenoberfläche & myHF für die Kordinaten des Hauptfensters
	GetDlgItem(IDC_CANVAS)->GetWindowRect(myRect);	// Ermittle die Koordinaten der Zeichenoberfläche mit dem Rahmen
	GetDlgItem(IDC_CANVAS)->GetClientRect(myRectC);	// Ermittle die Koordinaten der Zeichenoberfläche ohne den Rahmen 
	GetWindowRect(myHF);	// Ermittle die Koordinaten für Hauptfenster mit Rahmen
	GetClientRect(myHFC);	// Ermittle die Koordinaten für Hauptfenster ohne Rahmen
	m_cpLeftFenst.x  = (myRect.left-myHF.left)-((myHF.right-myHF.left)-myHFC.right)+((myRect.right-myRect.left)-myRectC.right); // Linke obere Ecke für x berechnen
	m_cpLeftFenst.y  = (myRect.top-myHF.top)-((myHF.bottom-myHF.top)-myHFC.bottom)+((myRect.bottom-myRect.top)-myRectC.bottom); // Linke obere Ecke für y berechnen
	m_cpRightFenst.x = (myRect.left-myHF.left)-((myHF.right-myHF.left)-myHFC.right)+((myRect.right-myRect.left)-myRectC.right)+myRectC.right;  // Rechte untere Ecke für x berechnen
	m_cpRightFenst.y = (myRect.top-myHF.top)-((myHF.bottom-myHF.top)-myHFC.bottom)+((myRect.bottom-myRect.top)-myRectC.bottom)+myRectC.bottom; // Rechte untere Ecke für y berechnen
	CClientDC myDC(this);	// erstelle Objekt für Zeichnen
	CPen myPen;	// Ein Stift erstellen
	myPen.CreatePen(PS_SOLID,1,RGB(10,4,252));// Den Stift mit Farbe und etc. aktualisieren
	myDC.SelectObject(&myPen); // Den Stift verwenden
  // Koordinatenkreuz zeichnen
	myDC.MoveTo(m_cpLeftFenst.x,m_cpLeftFenst.y+((m_cpRightFenst.y-m_cpLeftFenst.y)/2)); //Gehe zu den Punkten x,y
	myDC.LineTo(m_cpRightFenst.x+2,m_cpLeftFenst.y+((m_cpRightFenst.y-m_cpLeftFenst.y)/2));	//Zeichne eine Linie bis zu angegebenen Punkten
	myDC.MoveTo(m_cpRightFenst.x-((m_cpRightFenst.x-m_cpLeftFenst.x)/2),m_cpLeftFenst.y); //Gehe zu den Punkten x,y
	myDC.LineTo(m_cpRightFenst.x-((m_cpRightFenst.x-m_cpLeftFenst.x)/2),m_cpRightFenst.y+2); //Zeichne eine Linie bis zu angegebenen Punkten
}

/***********************************************************************************************************/
//   float CGrafMathDlg::GetYofFunction(float x)
// -----------------------------------------------
//
//  Diese Funktion errechnet den Y-Wert einer Funktion - eingegeben durch einen X-Wert des Koordinaten-
//  systems - und gibt den Y-Wert zurück.
//
/***********************************************************************************************************/
float CGrafMathDlg::GetYofFunction(float x)
{
  float y = 0; // Y-Wert initialisieren
  y = y+(m_arrFunction.GetAt(0)*float(pow(x,0))); // entspricht d*x^0 einer Funktion
  y = y+(m_arrFunction.GetAt(1)*float(pow(x,1))); // entspricht c*x^1 einer Funktion
  y = y+(m_arrFunction.GetAt(2)*float(pow(x,2))); // entspricht b*x^2 einer Funktion
  y = y+(m_arrFunction.GetAt(3)*float(pow(x,3))); // entspricht a*x^3 einer Funktion
  return y; // Y-Wert zurückgeben
}

/***********************************************************************************************************/
//   void CGrafMathDlg::DrawFunction()
// -------------------------------------
//
//  Diese Funktion zeichnet den Graph einer eingegebenen Funktion in die Zeichenoberfläche.
//
/***********************************************************************************************************/
void CGrafMathDlg::DrawFunction()
{
  float fAK,fBK,fCK,fDK;
  fAK = m_arrFunction[3];
  fBK = m_arrFunction[2];
  fCK = m_arrFunction[1];
  fDK = m_arrFunction[0];
  //-------------------------------------VARIABLEN-----------------------------------------
  CClientDC dc(this);	//Für zeichnen der Achse
  float fDistanze = m_fDistanceSize;
  int nSizeOfFenstX = (m_cpRightFenst.x-m_cpLeftFenst.x)/2; 
  int nSizeOfFenstY = (m_cpRightFenst.y-m_cpLeftFenst.y)/2; 
  int nSteps = 0;
	float fPixelCM  = 0;
  float fBufferCM = 0;
  float fBufferPX = 0;
  bool bFirst = true;
  //int nHochFaktor = 3;
  //---------------------------------------------------------------------------------------	

	for (int nAH = -nSizeOfFenstX; nAH <= nSizeOfFenstX; nAH++)
  {
		nSteps = nSizeOfFenstX-nAH;
    fPixelCM = float(nAH)/(fDistanze/m_fZahlFaktor);
    fBufferCM  = fAK*(((-1)*fPixelCM)*((-1)*fPixelCM)*((-1)*fPixelCM));
		fBufferCM += fBK*(((-1)*fPixelCM)*((-1)*fPixelCM));
		fBufferCM += fCK* ((-1)*fPixelCM);
		fBufferCM += fDK;
    
    //fBufferPX = fBufferCM;
    fBufferPX = fBufferCM*(fDistanze/m_fZahlFaktor);
    
    if ((fBufferPX < nSizeOfFenstY) && (fBufferPX > ((-1)*nSizeOfFenstY)) && bFirst)
    {
			dc.MoveTo(int(m_cpLeftFenst.x+nSteps+1),int(m_cpLeftFenst.y+(nSizeOfFenstY-fBufferPX)));
			bFirst = false;
    } else {
			if ((fBufferPX < nSizeOfFenstY) && (fBufferPX > ((-1)*nSizeOfFenstY)))
      {
				dc.LineTo(int(m_cpLeftFenst.x+nSteps+1),int(m_cpLeftFenst.y+(nSizeOfFenstY-fBufferPX)));
			}
		}
	}




/* // Größe der Zeichenoberfläche ermitteln...
  m_staticCanvas.GetClientRect(m_rctCanvasFormat);
  CPoint //.. und in Punkte abspeichern
    // Angaben der Koordinaten für die linke, obere Ecke relativ zum Client
    pntTopLeft = m_rctCanvasFormat.TopLeft(),
    // Angaben der Koordinaten für die rechte, untere Ecke relativ zum Client
    pntBottomRight = m_rctCanvasFormat.BottomRight();
  
  CClientDC dc(this);
  
  CPen MyPen;
  MyPen.CreatePen(PS_SOLID,1,RGB(0,0,255));
  dc.SelectObject(&MyPen);

  float
    x,y,x_old,y_old;
  
  // Zählschleife von der Breite der Zeichenoberfläche ausführen
  for (int i = 0; i < pntBottomRight.x; i++)
  {
    // Jeder X-Wert wird immer um genau 1 Pixel größer.
    x = float(i);

    m_fXFunc = X2XFunc(x); // X-Wert des Koordinatensystems aus X-Wert (Pixel) ermitteln
    m_fYFunc = GetYofFunction(m_fXFunc); // Y-Wert des Koordinatensystems aus X-Wert des Koordinatensystems ermitteln
    y = YFunc2Y(m_fYFunc); // X-Wert (Pixel) aus Y-Wert des Koordinatensystems ermitteln

	  x = x+m_nXCorr; // Anzeige-Korrekur für X-Wert setzen
  	y = y+m_nYCorr; // Anzeige-Korrekur für Y-Wert setzen
	
    if (i == 0) // Für das Zeichnen Graphen zuerst Anfangswert ermitteln
    {
      x_old = x;
      y_old = y;
    }

    // Ausführen, wenn X- & Y-Werte sich  innerhalb der Zeichenoberfläche befinden
    if ((x >= pntTopLeft.x+m_nXCorr) && (x <= pntBottomRight.x+m_nXCorr) && (y >= pntTopLeft.y+m_nYCorr) && (y <= pntBottomRight.y+m_nYCorr))    
    //alternativ: if ((m_fXFunc >= m_fXValueMin) && (m_fXFunc <= m_fXValueMax) && (m_fYFunc >= m_fYValueMin) && (m_fYFunc <= m_fYValueMax))
    {
      //dc.SetPixel(int(x),int(y),RGB(0,0,255));
      dc.MoveTo(int(x_old),int(y_old));
      dc.LineTo(int(x),int(y));
      // akutellen Punkt sichern
      x_old = x;
      y_old = y;
    }
  }*/
}

void CGrafMathDlg::DrawSection(CPoint cpFenstLeft,CPoint cpFenstRight,CClientDC& myDC,float nSizeFaktor)
{
  //-------------------V A R I A B L E N ----------------------------------//
	bool bT=true;		//Hilfsvariable, mit der man erfährt ob die FOR-Schleife zum ersten oder 2ten mal durchläuft, damit wird der nFaktor realisiert (-1) bzw. (+1)
	int nFaktor = 1;	//Wird benötigt um die positive und negative Achsen zu zeichnen für negative (-1) für Positive (+1)
	int nMalFaktor=1;	//Zum Berechnung der Positionen der Zahlen der Achsenabschnitte
	int nBuf=0;			//Zwischenspeicher
	int nXpos=0;		//Zur Berechnung von XPositon bei der Achsenbeschrifftung
	int nMerker = 0;
	int nMerkerXRight = 0;
	int nStelle = 0;		//Wie die Stelle, die beim Durchsuchen des Strings zurückgegeben wird
	CString strText;	//Hier wird der Text bzw. werden die Zahlen für die Achsenbeschrifftung abgelegt
	CString strBuf;
	CClientDC dc(this);	//Für zeichnen der Achse
	LOGFONT LF;			//Für die Schriftauswahl
	CFont *tmpfont = dc.GetCurrentFont();	//Ebenfalls
	CFont font;			//Ebenfalls
  //-----------------------------------------------------------------------//
	tmpfont->GetLogFont(&LF);
	LF.lfHeight = 10; 
	LF.lfWeight = 12;
	strcpy(LF.lfFaceName,"Segoe UI");
	font.CreateFontIndirect(&LF);
	dc.SelectObject(font);

	if (int(m_fSizeFaktor) % 7 == 0 && nSizeFaktor > 0)
  {
	  m_fSizeFaktor = 4;
		m_fZahlFaktor *= 2;
  } else {
		if (int(m_fSizeFaktor) % 4 == 0 && nSizeFaktor < 0)
    {
			m_fSizeFaktor = 7;
			m_fZahlFaktor /= 2;
    } else {
			m_fSizeFaktor += nSizeFaktor;
		}
	}

	float fD = (cpFenstRight.x-((cpFenstRight.x-cpFenstLeft.x)/2))/float(m_fSizeFaktor);
	float fDY = ((cpFenstRight.y-cpFenstLeft.y)/2)/fD;
	m_fDistanceSize = fD;	//Distanze in Membervariable ablegen, damit beim Zeichnen der Kurve die Bekannt wird
	//Zeichne 
	for(float nA = 1; nA < m_fSizeFaktor; nA++)
  {
		myDC.MoveTo(cpFenstRight.x-((cpFenstRight.x-cpFenstLeft.x)/2)+int(nFaktor*nA*int(fD)),cpFenstLeft.y+((cpFenstRight.y-cpFenstLeft.y)/2)-m_nHelpAxisWidth/2);
		myDC.LineTo(cpFenstRight.x-((cpFenstRight.x-cpFenstLeft.x)/2)+int(nFaktor*nA*int(fD)),cpFenstLeft.y+((cpFenstRight.y-cpFenstLeft.y)/2)+m_nHelpAxisWidth);
    strText.Format("%f",float(nA)*m_fZahlFaktor); //Die Kordinatenzahlen ermitteln mithilfe von m_fZahlFaktor
    m_fXValueMin = -(float(nA)*m_fZahlFaktor);
    m_fXValueMax =   float(nA)*m_fZahlFaktor;
		nStelle = strText.Find(".",0);
		strBuf  = strText.Left(nStelle+m_nDecimalPlaces+1);
		if(nFaktor == (-1))
    {
			strText = "-";
    } else {
			strText = "";
		}
		strText += strBuf;
		nBuf = strText.GetLength();
		nMalFaktor = nBuf;
		nXpos = cpFenstRight.x-((cpFenstRight.x-cpFenstLeft.x)/2)+int(nFaktor*nA*fD)-4*nMalFaktor;	
		if (nXpos+(7*nBuf) > m_cpRightFenst.x)
    {
			nMerkerXRight = ((nXpos+(7*nBuf))-m_cpRightFenst.x);
		}
		for (int nStr = 0; nStr < nBuf; nStr++)
    {	
			nXpos = cpFenstRight.x-((cpFenstRight.x-cpFenstLeft.x)/2)+int(nFaktor*nA*fD)-4*nMalFaktor+(nStr*7)+nMerker;
			if (nXpos < m_cpLeftFenst.x)
      {
				nMerker = m_cpLeftFenst.x-nXpos;
				nXpos = m_cpLeftFenst.x;
			}
			if (m_bAxisDescription) dc.TextOut(nXpos-nMerkerXRight,cpFenstLeft.y+((cpFenstRight.y-cpFenstLeft.y)/2)+4,strText.GetAt(nStr)); 
		}
		if (int(nA) == int(m_fSizeFaktor-0.5) && bT)
    {
			nFaktor = (-1);
			nMerkerXRight = 0;
			bT = false;
			nA = 0;
		}
	}
	nFaktor = 1;
	bT = true;
	//Zeichne die Y-Achseabschnitte
	for (float nB = 1; nB < fDY; nB++)
  {
		myDC.MoveTo(cpFenstRight.x-((cpFenstRight.x-cpFenstLeft.x)/2)-m_nHelpAxisWidth/2,cpFenstLeft.y+((cpFenstRight.y-cpFenstLeft.y)/2)+int(nFaktor*nB*int(fD)));
		myDC.LineTo(cpFenstRight.x-((cpFenstRight.x-cpFenstLeft.x)/2)+m_nHelpAxisWidth,cpFenstLeft.y+((cpFenstRight.y-cpFenstLeft.y)/2)+int(nFaktor*nB*int(fD)));
		strText.Format("%f",float(nB*m_fZahlFaktor)); 
    m_fYValueMin = -(float(nB)*m_fZahlFaktor);
    m_fYValueMax =   float(nB)*m_fZahlFaktor;
		nStelle = strText.Find(".",0);
		strBuf  = strText.Left(nStelle+m_nDecimalPlaces+1);
		if(nFaktor == (-1))
    {
			strText = "";
    } else {
			strText = "-";
		}
		strText += strBuf;
		nBuf = strText.GetLength();
		nMalFaktor = nBuf;
		nBuf = cpFenstLeft.y+((cpFenstRight.y-cpFenstLeft.y)/2)+int(nFaktor*nB*fD)-4;
		if (nBuf < m_cpLeftFenst.y)
    {
			nBuf = m_cpLeftFenst.y+2;
		}
		if (nBuf+10 > m_cpRightFenst.y)
    {
			nBuf = m_cpRightFenst.y-12;
		}	
		if (m_bAxisDescription) dc.TextOut(cpFenstRight.x-((cpFenstRight.x-cpFenstLeft.x)/2)-9*nMalFaktor,nBuf,strText); 
		if (int(nB) == int(fDY) && bT)
    {
			nFaktor = (-1);
			bT = false;
			nB = 0;
		}
	}
	UpdateData(true);
  CGrafMathDlg::DrawFunction();
}

BOOL CGrafMathDlg::OnMouseWheel(UINT nFlags,short zDelta,CPoint pt) 
{
	CClientDC myDC(this);
	m_staticCanvas.RedrawWindow();
	CGrafMathDlg::DrawCanvas();
	if (zDelta > 0)
  {	
		DrawSection(m_cpLeftFenst,m_cpRightFenst,myDC,1);	
  } else {
		DrawSection(m_cpLeftFenst,m_cpRightFenst,myDC,-1);
	}
	return CDialog::OnMouseWheel(nFlags,zDelta,pt);
}

/***********************************************************************************************************/
//   float CGrafMathDlg::X2XFunc(float x)
// ----------------------------------------
//
//  Diese Funktion rechnet einen X-Wert als Pixelwert in den X-Wert des Koordinatensystems um.
//
/***********************************************************************************************************/
float CGrafMathDlg::X2XFunc(float x)
{
  // Größe der Zeichenoberfläche ermitteln...
  m_staticCanvas.GetClientRect(m_rctCanvasFormat);
  CPoint //.. und in Punkte abspeichern
    // Angaben der Koordinaten für die linke, obere Ecke relativ zum Client
    pntTopLeft = m_rctCanvasFormat.TopLeft(),
    // Angaben der Koordinaten für die rechte, untere Ecke relativ zum Client
    pntBottomRight = m_rctCanvasFormat.BottomRight();

  // wenn X-Wert größer 0 und maximal halb breit wie die Zeichenoberfläche ist,
  // dann wird ein negativer X-Wert des Koordinatensystem zurückgegeben
  if ((x >= pntTopLeft.x) && (x <= pntBottomRight.x/2)) x = m_fXValueMin-(m_fXValueMin*x)/(pntBottomRight.x/2);
  // wenn X-Wert mehr als halb breit wie die Zeichenoberfläche und maximal so breit wie die Zeichenoberfläche ist,
  // dann wird ein positiver X-Wert des Koordinatensystem zurückgegeben
  if ((x >= pntBottomRight.x/2) && (x <= pntBottomRight.x+m_nXCorr)) x = (m_fXValueMax*x)/(pntBottomRight.x/2)-m_fXValueMax;

  return x;
}

/***********************************************************************************************************/
//   float CGrafMathDlg::XFunc2X(float x)
// ----------------------------------------
//
//  Diese Funktion rechnet einen X-Wert des Koordinatensystems in den X-Wert als Pixelwert um.
//
/***********************************************************************************************************/
float CGrafMathDlg::XFunc2X(float x)
{
  // Größe der Zeichenoberfläche ermitteln...
  m_staticCanvas.GetClientRect(m_rctCanvasFormat);
  CPoint //.. und in Punkte abspeichern
    // Angaben der Koordinaten für die linke, obere Ecke relativ zum Client
    pntTopLeft = m_rctCanvasFormat.TopLeft(),
    // Angaben der Koordinaten für die rechte, untere Ecke relativ zum Client
    pntBottomRight = m_rctCanvasFormat.BottomRight();

  x = 1/x;
  x = (pntBottomRight.x/2)/(x*m_fXValueMin)+pntBottomRight.x/2;
  if (x > 0) x++; else if (x < 0) x--; // eine kleine Korrektur

  return x;
}

/***********************************************************************************************************/
//   float CGrafMathDlg::Y2YFunc(float y)
// ----------------------------------------
//
//  Diese Funktion rechnet einen Y-Wert als Pixelwert in den Y-Wert des Koordinatensystems um.
//
/***********************************************************************************************************/
float CGrafMathDlg::Y2YFunc(float y)
{
  // Größe der Zeichenoberfläche ermitteln...
  m_staticCanvas.GetClientRect(m_rctCanvasFormat);
  CPoint //.. und in Punkte abspeichern
    // Angaben der Koordinaten für die linke, obere Ecke relativ zum Client
    pntTopLeft = m_rctCanvasFormat.TopLeft(),
    // Angaben der Koordinaten für die rechte, untere Ecke relativ zum Client
    pntBottomRight = m_rctCanvasFormat.BottomRight();
  // wenn X-Wert größer 0 und maximal halb breit wie die Zeichenoberfläche ist,
  // dann wird ein negativer X-Wert des Koordinatensystem zurückgegeben
  if ((y >= pntTopLeft.y) && (y <= pntBottomRight.y/2)) y = m_fYValueMin-(m_fYValueMin*y)/(pntBottomRight.y/2);
  // wenn X-Wert mehr als halb breit wie die Zeichenoberfläche und maximal so breit wie die Zeichenoberfläche ist,
  // dann wird ein positiver X-Wert des Koordinatensystem zurückgegeben
  if ((y >= pntBottomRight.y/2) && (y <= pntBottomRight.y+m_nYCorr)) y = (m_fYValueMax*y)/(pntBottomRight.y/2)-m_fYValueMax;

  return y;
}

/***********************************************************************************************************/
//   float CGrafMathDlg::YFunc2Y(float y)
// ----------------------------------------
//
//  Diese Funktion rechnet einen Y-Wert des Koordinatensystems in den Y-Wert als Pixelwert um.
//
/***********************************************************************************************************/
float CGrafMathDlg::YFunc2Y(float y)
{
  // Größe der Zeichenoberfläche ermitteln...
  m_staticCanvas.GetClientRect(m_rctCanvasFormat);
  CPoint //.. und in Punkte abspeichern
    // Angaben der Koordinaten für die linke, obere Ecke relativ zum Client
    pntTopLeft = m_rctCanvasFormat.TopLeft(),
    // Angaben der Koordinaten für die rechte, untere Ecke relativ zum Client
    pntBottomRight = m_rctCanvasFormat.BottomRight();

  y = 1/y;
  y = (pntBottomRight.y/2)/(y*m_fYValueMin)+pntBottomRight.y/2;
  if (y > 0) y++; else if (y < 0) y--; // eine kleine Korrektur

  return y;
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonInputFunction() 
// ----------------------------------------------
//
//  In dieser Methode kann man ganz bequem die Koeffiezienten einer Funktion eingeben.
//  Die Werte der Koeffiezienten werde automatisch in 'm_arrFunction' gespeichert
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonInputFunction() 
{
  CInputFunctionDlg dlgInputFunction;
  // Wert für Koeffizient D zuweisen
  dlgInputFunction.m_fKoeffizientD = m_arrFunction.GetAt(0);
  // Wert für Koeffizient C zuweisen
  dlgInputFunction.m_fKoeffizientC = m_arrFunction.GetAt(1);
  // Wert für Koeffizient B zuweisen
  dlgInputFunction.m_fKoeffizientB = m_arrFunction.GetAt(2);
  // Wert für Koeffizient A zuweisen
  dlgInputFunction.m_fKoeffizientA = m_arrFunction.GetAt(3);

  if (dlgInputFunction.DoModal() == IDOK)
  {
    // Wert für veränderten Koeffizient D zuweisen
    m_arrFunction2.SetAt(0,dlgInputFunction.m_fKoeffizientD);
    // Wert für veränderten Koeffizient C zuweisen
    m_arrFunction2.SetAt(1,dlgInputFunction.m_fKoeffizientC);
    // Wert für veränderten Koeffizient B zuweisen
    m_arrFunction2.SetAt(2,dlgInputFunction.m_fKoeffizientB);
    // Wert für veränderten Koeffizient A zuweisen
    m_arrFunction2.SetAt(3,dlgInputFunction.m_fKoeffizientA);
  }
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnButtonAxisOptions()
// --------------------------------------------
//
//  Diese Funktion ruft den Dialog für die Einstellungen der Koordinatenachsen auf
//  und übernimmt ggf. die Änderungen.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnButtonAxisOptions()
{
  CAxisOptionsDlg dlgAxisOptions;
  // Wert für die Achseneinteilung zuweisen
  dlgAxisOptions.m_nAxisDivision = m_nAxisDivision;
  // Wert für die Dezimalstellen zuweisen
  dlgAxisOptions.m_nDecimalPlaces = m_nDecimalPlaces;
  // Wert für die Breite der Hilfslinien der Achsen zuweisen
  dlgAxisOptions.m_nHelpAxisWidth = m_nHelpAxisWidth;
  // Wert für die Achsenbeschreibung zuweisen
  dlgAxisOptions.m_bAxisDescription = m_bAxisDescription;
  // Wird nur ausgeführt, wenn bei der Dialogbox der OK-Button gedrückt wurde
  
  if (dlgAxisOptions.DoModal() == IDOK)
  {
    // Wert für die veränderte Achseneinteilung zuweisen
    m_nAxisDivision = dlgAxisOptions.m_nAxisDivision;
    // Wert für die veränderten Dezimalstellen zuweisen
    m_nDecimalPlaces = dlgAxisOptions.m_nDecimalPlaces;
    // Wert für die veränderte Breite der Hilfslinien der Achsen zuweisen
    m_nHelpAxisWidth = dlgAxisOptions.m_nHelpAxisWidth;
    // Wird nur ausgeführt, wenn bei der Dialogbox der OK-Button gedrückt wurde
    m_bAxisDescription = dlgAxisOptions.m_bAxisDescription;
    // Zeichenoberfläche neu zeichnen, damit die Änderungen sofort wirksam werden
    CClientDC myDC(this);
    //m_staticCanvas.RedrawWindow();
    CGrafMathDlg::DrawCanvas();
    DrawSection(m_cpLeftFenst,m_cpRightFenst,myDC,0);
  }
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnAboutbox()
// -----------------------------------
//
//  Diese Funktion ruft über das Menü die Info-Box zum Programm auf.
//
/***********************************************************************************************************/
void CGrafMathDlg::OnAboutbox() 
{
  CAboutDlg dlgAbout;
  dlgAbout.DoModal();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuAppHilfe() 
// --------------------------------------
//
//  Ruft die Hilfe auf; Menüpunkt
//  Noch nicht vollständig implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuAppHilfe() 
{
  CHelpDialog hlp(this,IDR_RTF_HILFE);
	hlp.SetTitle(_T("Hilfe zu Graf Math"));
	hlp.DoModal();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuMiscAbleitungen() 
// ---------------------------------------------
//
//  Ruft den Dialog für die Ableitungen der eingegebenen Funktion auf; Menüpunkt
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuMiscAbleitungen() 
{
	OnButtonAbleitung();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuMiscGaussElimination() 
// --------------------------------------------------
//
//  Ruft den Dialog zur Berechnung mit dem Gauss-Eliminationsverfahren auf; Menüpunkt
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuMiscGaussElimination() 
{
  CGaussEliminationDlg dlgGaussElimination;
  dlgGaussElimination.DoModal();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuMiscTangenteGleichung() 
// ---------------------------------------------------
//
//  Ruft den Dialog für die Tangentengleichung der eingegebenen Funktion auf; Menüpunkt
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuMiscTangenteGleichung() 
{
	OnButtonTangente();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuPunktHochtief() 
// -------------------------------------------
//
//  Ruft den Dialog für Hoch- und Tiefpunkte der eingegebenen Funktion auf; Menüpunkt
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuPunktHochtief() 
{
	OnButtonHochtiefpunkt();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuPunktWendestelle() 
// ----------------------------------------------
//
//  Ruft den Dialog für die Wendestelle der eingegebenen Funktion auf; Menüpunkt
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuPunktWendestelle() 
{
	OnButtonWendepunkt();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuPunktSchnittstellenXachse() 
// -------------------------------------------------------
//
//  Ruft den Dialog für die Schnittpunkte mit der X-Achse (so genannte Nullstellen) der eingegebenen Funktion auf; Menüpunkt
//  Noch nicht implementiert!!!
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuPunktSchnittstellenXachse() 
{
	OnButtonSchnittpunktXachse();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuPunktSchnittstellenYachse() 
// -------------------------------------------------------
//
//  Ruft den Dialog für den Schnittpunkt mit der Y-Achse der eingegebenen Funktion auf; Menüpunkt
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuPunktSchnittstellenYachse() 
{
	OnButtonSchnittpunktYachse();
}

/***********************************************************************************************************/
//   void CGrafMathDlg::OnMnuPunktSchnittstellenYachse() 
// -------------------------------------------------------
//
//  Ruft den Dialog für die Steigung eines Wrtes der eingegebenen Funktion auf; Menüpunkt
//
/***********************************************************************************************************/
void CGrafMathDlg::OnMnuMiscSteigung() 
{
	OnButtonSteigung();
}

void CGrafMathDlg::OnMnuFunktionEingeben() 
{
	OnButtonInputFunction();
}

void CGrafMathDlg::OnMnuFunktionZeichnen() 
{
	OnButtonParseAndDraw();
}

void CGrafMathDlg::OnMnuFunktionEingebenUndZeichnen() 
{
	OnMnuFunktionEingeben();
  OnMnuFunktionZeichnen();
}

void CGrafMathDlg::OnMnuMiscAchsensymmetrie() 
{
  CString strOutp =_T("");
  int nEven = 0, nOdd = 0;
  if (m_arrFunction.GetAt(0) != 0) nEven++;
  if (m_arrFunction.GetAt(1) != 0) nOdd++;
  if (m_arrFunction.GetAt(2) != 0) nEven++;
  if (m_arrFunction.GetAt(3) != 0) nOdd++;
  if (nOdd != 0 && nEven == 0) strOutp = _T("Punktsymmetrie zum Koordinatenursprung vorhanden"); else
  if (nOdd == 0 && nEven != 0) strOutp = _T("Spiegelsymmetrie zur Y-Achse vorhanden"); else
  if (nOdd == nEven) strOutp = _T("Keine Symmetrie vorhanden"); else strOutp = _T("Keine Symmetrie vorhanden");
  strOutp += _T("\n");
  MessageBox(strOutp,_T("Achsen-Symmetrie"),MB_OK+MB_ICONINFORMATION);//MB_ICONQUESTION + MB_YESNO
}

void CGrafMathDlg::OnMnuAchsenAchsenskalierungZoominXY() 
{
  OnButtonZoominXyachse();
}

void CGrafMathDlg::OnMnuAchsenAchsenskalierungZoomoutXY() 
{
	OnButtonZoomoutXyachse();	
}

void CGrafMathDlg::OnMnuAchsenAnzeigeSkalierung() 
{
	OnButtonGetXYRange();
}

void CGrafMathDlg::OnMnuAchsenEinstellungen() 
{
	OnButtonAxisOptions();
}

void CGrafMathDlg::OnButtonViewLoad() 
{
	// TODO: Add your control notification handler code here
	
}

void CGrafMathDlg::OnButtonViewSave() 
{
	// TODO: Add your control notification handler code here
	
}

void CGrafMathDlg::OnMnuAppAnsichtLaden() 
{
  OnButtonViewLoad();
}

void CGrafMathDlg::OnMnuAppAnsichtSpeichern() 
{
	OnButtonViewSave();	
}

void CGrafMathDlg::OnMnuMiscWertetabelle() 
{
  CValueTableDlg dlgValueTable;
  dlgValueTable.m_arrFunction.SetSize(m_arrFunction.GetSize());
  for (int i = 0; i < m_arrFunction.GetSize(); i++) dlgValueTable.m_arrFunction.SetAt(i,m_arrFunction.GetAt(i));
  dlgValueTable.DoModal();
}

void CGrafMathDlg::OnMnuAppCredits() 
{
  CCreditsDlg dlgCredits;
  dlgCredits.DoModal();
}

void CGrafMathDlg::OnMnuMiscAufleitung() 
{
	// TODO: Add your command handler code here
}

void CGrafMathDlg::OnMnuMiscFlaechenberechnung() 
{
  CIntegralDlg dlgIntegral;
  dlgIntegral.DoModal();
}

void CGrafMathDlg::OnMnuMiscMonotonie() 
{
  CMonotonyDlg dlgMonotony;
  dlgMonotony.m_arrFunction.SetSize(m_arrFunction.GetSize());
  dlgMonotony.m_arr1stDerivatedFunction.SetSize(m_arrFunction.GetSize());
  DerivateAll();
  for (int i = 0; i < m_arrDerivatedFunction[1].GetSize(); i++) dlgMonotony.m_arr1stDerivatedFunction.SetAt(i,m_arrDerivatedFunction[1].GetAt(i));
  for (i = 0; i < m_arrFunction.GetSize(); i++) dlgMonotony.m_arrFunction.SetAt(i,m_arrFunction.GetAt(i));
  dlgMonotony.DoModal();
}

void CGrafMathDlg::OnMnuPunktScheitelpunkt() 
{
	if (m_arrFunction.GetAt(3) != 0)
  {    
    MessageBox(_T("Die Funktion ist keine quadratische Funktion.\nEin Scheitelpunkt kann nur auf eine quadratische Funktion angewandt werden."),_T("Scheitelpunkt"),MB_OK+MB_ICONEXCLAMATION);
  } else {
    if (m_arrFunction.GetAt(2) == 0)
    {
      MessageBox(_T("Die Funktion ist keine quadratische Funktion.\nEin Scheitelpunkt kann nur auf eine quadratische Funktion angewandt werden."),_T("Scheitelpunkt"),MB_OK+MB_ICONEXCLAMATION);
    } else {
      float
        fP = m_arrFunction.GetAt(1)/m_arrFunction.GetAt(2),
        fQ = m_arrFunction.GetAt(0)/m_arrFunction.GetAt(2),
        fSX = -(fP/2),
        fSY = -((fP*fP)/4)+fQ,
        fTemp = 0;
      CString
        strOutp1 = _T(""),
        strOutp2 = _T(""),
        strOutp3 = _T("");

      strOutp1 += _T("Die Scheitelpunkt wurde ermittelt.\n");
      strOutp1 += _T("Er lautet:\n\n");
      strOutp1 += _T("      S(");

      strOutp2.Format("%0.3f",fSX);
      strOutp1 += strOutp2;
      strOutp1 += _T(" | ");

      strOutp2.Format("%0.3f",2*fSY);
      strOutp1 += strOutp2;
      strOutp1 += _T(")\n");

      MessageBox(strOutp1,_T("Scheitelpunkt"),MB_OK+MB_ICONINFORMATION);
    }
  }	
}

/***********************************************************************************************************/
// Helper functions
/***********************************************************************************************************/
// constant string definitions here (or you can put it into resource string table)
#define IDS_UTIL_UXTHEME      "UxTheme.dll"
#define IDS_UTIL_THEMETEXTURE "EnableThemeDialogTexture"
/////////////////////////////////////////////////////////////////////////////
void EnableThemeDialogTexture(HWND hwndDlg)
{
	HINSTANCE hDll = LoadLibrary(CString((LPCTSTR)IDS_UTIL_UXTHEME)); // 'UxTheme.dll'
	if(hDll == NULL) return;	// the DLL won't be available on anything except Windows XP
	ULONG (PASCAL *lpfnEnableTheme)(HWND,DWORD);
	(FARPROC&)lpfnEnableTheme = GetProcAddress(hDll,CString((LPCTSTR)IDS_UTIL_THEMETEXTURE));	// 'EnableThemeDialogTexture'
	if(lpfnEnableTheme) lpfnEnableTheme(hwndDlg, 6); // ETDT_ENABLETAB = (ETDT_ENABLE | ETDT_USETABTEXTURE) = (2|4) = 6
  else ASSERT(FALSE);
	FreeLibrary(hDll);
}

void CGrafMathDlg::OnMnuMiscLaengeZwischen2Punkten() 
{
	CLengthTwoPoints dlgLengthTwoPoints;
  dlgLengthTwoPoints.m_arrFunction.SetSize(m_arrFunction.GetSize());
  for (int i = 0; i < m_arrFunction.GetSize(); i++) dlgLengthTwoPoints.m_arrFunction.SetAt(i,m_arrFunction.GetAt(i));
  dlgLengthTwoPoints.DoModal();
}

void CGrafMathDlg::OnMnuMiscYausX() 
{
	CGetXofYDlg dlgGetXofY;
  dlgGetXofY.m_arrFunction.SetSize(m_arrFunction.GetSize());
  for (int i = 0; i < m_arrFunction.GetSize(); i++) dlgGetXofY.m_arrFunction.SetAt(i,m_arrFunction.GetAt(i));
  dlgGetXofY.DoModal();
}
