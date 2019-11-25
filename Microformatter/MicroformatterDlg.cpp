// MicroformatterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "AddressDlg.h"
#include "CodeDlg.h"
#include "GeolocationDlg.h"
#include "hAtomDlg.h"
#include "hCalenderDlg.h"
#include "hCardDlg.h"
#include "hResumeDlg.h"
#include "hReviewDlg.h"
#include "relTagDlg.h"
#include "XFNDlg.h"
#include "xFolkDlg.h"
#include "MicroformatterDlg.h"

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
// CMicroformatterDlg dialog

CMicroformatterDlg::CMicroformatterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMicroformatterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMicroformatterDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMicroformatterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMicroformatterDlg)
	DDX_Control(pDX, IDC_TAB, m_tcRegister);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMicroformatterDlg, CDialog)
	//{{AFX_MSG_MAP(CMicroformatterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_CREATE, OnButtonCreate)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_COPY, OnButtonCopy)
	ON_BN_CLICKED(IDC_BUTTON_PRINT, OnButtonPrint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMicroformatterDlg message handlers

BOOL CMicroformatterDlg::OnInitDialog()
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

  VERIFY(m_dlg_Address.Create(CAddressDlg::IDD,this));
  VERIFY(m_dlg_Geolocation.Create(CGeolocationDlg::IDD,this));
  VERIFY(m_dlg_hAtom.Create(ChAtomDlg::IDD,this));
  VERIFY(m_dlg_hCalender.Create(ChCalenderDlg::IDD,this));
  VERIFY(m_dlg_hCard.Create(ChCardDlg::IDD,this));
  VERIFY(m_dlg_hResume.Create(ChResumeDlg::IDD,this));
  VERIFY(m_dlg_hReview.Create(ChReviewDlg::IDD,this));
  VERIFY(m_dlg_relTag.Create(CrelTagDlg::IDD,this));
  VERIFY(m_dlg_XFN.Create(CXFNDlg::IDD,this));
  VERIFY(m_dlg_xFolk.Create(CxFolkDlg::IDD,this));
  VERIFY(m_dlg_Code.Create(CCodeDlg::IDD,this));
  CString strText;
  m_dlg_Address.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,0,strText,0,0,0,0) == 0);
  m_dlg_Geolocation.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,1,strText,0,0,0,0) == 0);
  m_dlg_hAtom.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,2,strText,0,0,0,0) == 0);
  m_dlg_hCalender.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,3,strText,0,0,0,0) == 0);
  m_dlg_hCard.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,4,strText,0,0,0,0) == 0);
  m_dlg_hResume.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,5,strText,0,0,0,0) == 0);
  m_dlg_hReview.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,6,strText,0,0,0,0) == 0);
  m_dlg_relTag.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,7,strText,0,0,0,0) == 0);
  m_dlg_XFN.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,8,strText,0,0,0,0) == 0);
  m_dlg_xFolk.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,9,strText,0,0,0,0) == 0);
  m_dlg_Code.GetWindowText(strText);
  VERIFY(m_tcRegister.InsertItem(TCIF_TEXT,10,strText,0,0,0,0) == 0);
  VERIFY(m_dlg_Address.SetWindowPos(GetDlgItem(IDC_TAB),8,77,0,0,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_Geolocation.SetWindowPos(GetDlgItem(IDC_TAB),8,77,0,0,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_hAtom.SetWindowPos(GetDlgItem(IDC_TAB),8,77,0,0,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_hCalender.SetWindowPos(GetDlgItem(IDC_TAB),8,77,100,100,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_hCard.SetWindowPos(GetDlgItem(IDC_TAB),8,77,100,100,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_hResume.SetWindowPos(GetDlgItem(IDC_TAB),8,77,100,100,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_hReview.SetWindowPos(GetDlgItem(IDC_TAB),8,77,100,100,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_relTag.SetWindowPos(GetDlgItem(IDC_TAB),8,77,100,100,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_XFN.SetWindowPos(GetDlgItem(IDC_TAB),8,77,100,100,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_xFolk.SetWindowPos(GetDlgItem(IDC_TAB),8,77,100,100,SWP_SHOWWINDOW | SWP_NOSIZE));
  VERIFY(m_dlg_Code.SetWindowPos(GetDlgItem(IDC_TAB),8,77,100,100,SWP_SHOWWINDOW | SWP_NOSIZE));
  UpdateVisibleWindow();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMicroformatterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMicroformatterDlg::OnPaint() 
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
HCURSOR CMicroformatterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMicroformatterDlg::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
   UpdateVisibleWindow();
	*pResult = 0;
}

void CMicroformatterDlg::UpdateVisibleWindow()
{
  int nCurrentTab = m_tcRegister.GetCurSel();
  m_dlg_Address.ShowWindow(nCurrentTab == 0 ? SW_SHOW : SW_HIDE);
  m_dlg_Geolocation.ShowWindow(nCurrentTab == 1 ? SW_SHOW : SW_HIDE);
  m_dlg_hAtom.ShowWindow(nCurrentTab == 2 ? SW_SHOW : SW_HIDE);
  m_dlg_hCalender.ShowWindow(nCurrentTab == 3 ? SW_SHOW : SW_HIDE);
  m_dlg_hCard.ShowWindow(nCurrentTab == 4 ? SW_SHOW : SW_HIDE);
  m_dlg_hResume.ShowWindow(nCurrentTab == 5 ? SW_SHOW : SW_HIDE);
  m_dlg_hReview.ShowWindow(nCurrentTab == 6 ? SW_SHOW : SW_HIDE);
  m_dlg_relTag.ShowWindow(nCurrentTab == 7 ? SW_SHOW : SW_HIDE);
  m_dlg_XFN.ShowWindow(nCurrentTab == 8 ? SW_SHOW : SW_HIDE);
  m_dlg_xFolk.ShowWindow(nCurrentTab == 9 ? SW_SHOW : SW_HIDE);
  m_dlg_Code.ShowWindow(nCurrentTab == 10 ? SW_SHOW : SW_HIDE);
}

void CMicroformatterDlg::OnButtonExit() 
{
  CDialog::OnCancel();
}


void CMicroformatterDlg::OnButtonCreate() 
{
	int nCurrentRegister = m_tcRegister.GetCurSel();
  m_tcRegister.SetCurSel(10);
  m_dlg_Address.ShowWindow(SW_HIDE);
  m_dlg_Geolocation.ShowWindow(SW_HIDE);
  m_dlg_hAtom.ShowWindow(SW_HIDE);
  m_dlg_hCalender.ShowWindow(SW_HIDE);
  m_dlg_hCard.ShowWindow(SW_HIDE);
  m_dlg_hResume.ShowWindow(SW_HIDE);
  m_dlg_hReview.ShowWindow(SW_HIDE);
  m_dlg_relTag.ShowWindow(SW_HIDE);
  m_dlg_XFN.ShowWindow(SW_HIDE);
  m_dlg_xFolk.ShowWindow(SW_HIDE);
  m_dlg_Code.ShowWindow(SW_SHOW);

  switch(nCurrentRegister)
  {
    default :
    {
    }
    case 0:
    {
      m_dlg_Address.UpdateData(true);
      int nCurrentRegister2 = m_dlg_Address.m_cmbxElementTemplate.GetCurSel();
      switch(nCurrentRegister2)
      {
        default :
        {
          break;
        }
        case 0:
        {
          m_dlg_Code.m_strCode = _T("<div class=\"adr\">\x0D\x0A");
          m_dlg_Code.m_strCodeCompact = _T("<div class=\"adr\">");

	        if (m_dlg_Address.m_strStreetAddress != _T(""))
          {
            m_dlg_Code.m_strCode += _T("  <div class=\"street-address\">");
            m_dlg_Code.m_strCode += m_dlg_Address.m_strStreetAddress;
            m_dlg_Code.m_strCode += _T("</div>\x0D\x0A");
            m_dlg_Code.m_strCodeCompact += _T("<div class=\"street-address\">");
            m_dlg_Code.m_strCodeCompact += m_dlg_Address.m_strStreetAddress;
            m_dlg_Code.m_strCodeCompact += _T("</div>");
          }

          if (m_dlg_Address.m_strExtendedAddress != _T(""))
          {
            m_dlg_Code.m_strCode += _T("  <div class=\"extended-address\">");
            m_dlg_Code.m_strCode += m_dlg_Address.m_strExtendedAddress;
            m_dlg_Code.m_strCode += _T("</div>\x0D\x0A");
            m_dlg_Code.m_strCodeCompact += _T("<div class=\"extended-address\">");
            m_dlg_Code.m_strCodeCompact += m_dlg_Address.m_strExtendedAddress;
            m_dlg_Code.m_strCodeCompact += _T("</div>");
          }

	        if (m_dlg_Address.m_strLocality != _T(""))
          {
            m_dlg_Code.m_strCode += _T("  <span class=\"locality\">");
            m_dlg_Code.m_strCode += m_dlg_Address.m_strLocality;
            m_dlg_Code.m_strCode += _T("</span>\x0D\x0A");
            m_dlg_Code.m_strCodeCompact += _T("<span class=\"locality\">");
            m_dlg_Code.m_strCodeCompact += m_dlg_Address.m_strLocality;
            m_dlg_Code.m_strCodeCompact += _T("</span>");
          }

	        if (m_dlg_Address.m_strRegion != _T(""))
          {
            m_dlg_Code.m_strCode += _T("  <span class=\"region\">");
            m_dlg_Code.m_strCode += m_dlg_Address.m_strRegion;
            m_dlg_Code.m_strCode += _T("</span>\x0D\x0A");
            m_dlg_Code.m_strCodeCompact += _T("<span class=\"region\">");
            m_dlg_Code.m_strCodeCompact += m_dlg_Address.m_strRegion;
            m_dlg_Code.m_strCodeCompact += _T("</span>");
          }

	        if (m_dlg_Address.m_strPostalCode != _T(""))
          {
            m_dlg_Code.m_strCode += _T("  <span class=\"postal-code\">");
            m_dlg_Code.m_strCode += m_dlg_Address.m_strPostalCode;
            m_dlg_Code.m_strCode += _T("</span>\x0D\x0A");
            m_dlg_Code.m_strCodeCompact += _T("<span class=\"postal-code\">");
            m_dlg_Code.m_strCodeCompact += m_dlg_Address.m_strPostalCode;
            m_dlg_Code.m_strCodeCompact += _T("</span>");
          }

	        if (m_dlg_Address.m_strCountryName != _T(""))
          {
            m_dlg_Code.m_strCode += _T("  <div class=\"country-name\">");
            m_dlg_Code.m_strCode += m_dlg_Address.m_strCountryName;
            m_dlg_Code.m_strCode += _T("</div>\x0D\x0A");
            m_dlg_Code.m_strCodeCompact += _T("<div class=\"country-name\">");
            m_dlg_Code.m_strCodeCompact += m_dlg_Address.m_strCountryName;
            m_dlg_Code.m_strCodeCompact += _T("</div>");
          }

          m_dlg_Code.m_strCode += _T("</div>");
          m_dlg_Code.m_strCodeCompact += _T("</div>");
          break;
        }
      }
      break;
    }
  }
  m_dlg_Code.UpdateData(false);
}

void CMicroformatterDlg::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	
}

void CMicroformatterDlg::OnButtonCopy() 
{
	// TODO: Add your control notification handler code here
	
}

void CMicroformatterDlg::OnButtonPrint() 
{
	// TODO: Add your control notification handler code here
	
}
