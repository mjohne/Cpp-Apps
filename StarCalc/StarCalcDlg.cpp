// StarCalcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StarCalc.h"
#include "StarCalcDlg.h"
#include "DlgProxy.h"
#include <math.h>

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
// CStarCalcDlg dialog

IMPLEMENT_DYNAMIC(CStarCalcDlg, CDialog);

CStarCalcDlg::CStarCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStarCalcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStarCalcDlg)
	m_Parallax = 0.0f;
	m_MagnitudeVisual = 0.0f;
	m_Distance = 0.0f;
	m_Density = 0.0f;
	m_Luminosity = 0.0f;
	m_MagnitudeAbsolute = 0.0f;
	m_Mass = 0.0f;
	m_MagnitudeBolometric = 0.0f;
	m_SpectralType = _T("");
	m_TemperatureEffective = 0.0f;
	m_Radius = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CStarCalcDlg::~CStarCalcDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CStarCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStarCalcDlg)
	DDX_Control(pDX, IDC_BUTTON_CALC, m_btnCalc);
	DDX_Text(pDX, IDC_EDIT_PARALLAX, m_Parallax);
	DDX_Text(pDX, IDC_EDIT_MVIS, m_MagnitudeVisual);
	DDX_Text(pDX, IDC_EDIT_DISTANCE, m_Distance);
	DDX_Text(pDX, IDC_EDIT_DENSITY, m_Density);
	DDX_Text(pDX, IDC_EDIT_LUMINOSITY, m_Luminosity);
	DDX_Text(pDX, IDC_EDIT_MABS, m_MagnitudeAbsolute);
	DDX_Text(pDX, IDC_EDIT_MASS, m_Mass);
	DDX_Text(pDX, IDC_EDIT_MBOL, m_MagnitudeBolometric);
	DDX_Text(pDX, IDC_EDIT_SPECTYPE, m_SpectralType);
	DDX_Text(pDX, IDC_EDIT_TEFF, m_TemperatureEffective);
	DDX_Text(pDX, IDC_EDIT_RADIUS, m_Radius);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStarCalcDlg, CDialog)
	//{{AFX_MSG_MAP(CStarCalcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT_PARALLAX, OnChangeEditParallax)
	ON_EN_CHANGE(IDC_EDIT_MVIS, OnChangeEditMvis)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStarCalcDlg message handlers

BOOL CStarCalcDlg::OnInitDialog()
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

  m_Distance = 0;
  m_Density = 0;
  m_Radius = 0;
  m_Luminosity = 0;
  m_MagnitudeAbsolute = 0;
  m_MagnitudeBolometric = 0;
  m_MagnitudeVisual = 0;
  m_Mass = 0;
  m_Parallax = 0;
  m_SpectralType = "";
  m_TemperatureEffective = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStarCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CStarCalcDlg::OnPaint() 
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
HCURSOR CStarCalcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CStarCalcDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CStarCalcDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CStarCalcDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CStarCalcDlg::CanExit()
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

void CStarCalcDlg::OnChangeEditParallax() 
{
  UpdateData(true);
}

void CStarCalcDlg::OnChangeEditMvis() 
{
  UpdateData(true);
}

void CStarCalcDlg::OnButtonCalc() 
{
  const double PI = 3.1412;
  const double SOLAR_C = 5.68*pow(10,-8);
  const double STEFAN_BOLTZ_C = 2.8978*pow(10,-3);
  const double MAG_ABS_SUN = 4.8;
  const double MAG_VIS_SUN = 26.8;
  const double LUM_SUN = 3.8*pow(10,26);
  const double TEFF_SUN = 5770;
  const double RAD_SUN = 696000;
  const double DIAM_SUN = 2*696000;
  m_Distance = 1/m_Parallax;
  m_MagnitudeAbsolute = m_MagnitudeVisual+5-5*(log10(m_Distance));
  m_Luminosity = (pow(10,-0.4*(m_MagnitudeAbsolute-MAG_ABS_SUN))); //m_Luminosity = (pow(10,-0.4*(m_MagnitudeAbsolute-MAG_ABS_SUN))*LUM_SUN)/LUM_SUN;
  m_MagnitudeBolometric = 4.7-2.5*log10(m_Luminosity);
  
  m_Mass = pow(m_Luminosity,1/3.5);
  //m_Radius = pow(m_Mass,0.6);
  m_TemperatureEffective = 9600;
  m_Radius = sqrt(m_Luminosity/(4*PI*STEFAN_BOLTZ_C*pow(m_TemperatureEffective,4)));
  double m_Diameter = 2*m_Radius;


  // Näherungsformel m_TemperatureEffective = TEFF_SUN*pow(m_Luminosity/sqrt(m_Diameter),0.25); 
  
  //m_TemperatureEffective = TEFF_SUN*pow(m_Luminosity/pow(m_Radius,2),0.25);
  
  m_Density = (3*m_Mass)/(4*3.1412*pow(m_Diameter/2,3));
  
  UpdateData(false);
}
