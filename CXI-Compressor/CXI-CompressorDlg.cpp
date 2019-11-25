// CXI-CompressorDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "CXI-Compressor.h"
#include "CXI-CompressorDlg.h"
#include "DlgProxy.h"
#include ".\cxi-compressordlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl 'Info'

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCXICompressorDlg Dialogfeld




IMPLEMENT_DYNAMIC(CCXICompressorDlg, CDialog);
CCXICompressorDlg::CCXICompressorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCXICompressorDlg::IDD, pParent)
  , m_strInputfileName(_T(""))
  , m_strOutputfileName(_T(""))
  , m_strStatusMessage(_T(""))
  , m_strProgressInPercent(_T(""))
  {
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}
CCXICompressorDlg::~CCXICompressorDlg()
{
	// Existiert für dieses Dialogfeld ein Automatisierungsproxy, setzen Sie
	//  seinen Gegenzeiger auf dieses Dialogfeld auf NULL, um anzuzeigen,
	//  dass das Dialogfeld gelöscht wurde.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CCXICompressorDlg::DoDataExchange(CDataExchange* pDX)
{
CDialog::DoDataExchange(pDX);
DDX_Text(pDX, IDC_EDIT_INPUTFILE, m_strInputfileName);
DDX_Text(pDX, IDC_EDIT_OUTPUTFILE, m_strOutputfileName);
DDX_Control(pDX, IDC_COMBO_INTSIZE, m_cmbIntSize);
DDX_Text(pDX, IDC_STATIC_STATUS, m_strStatusMessage);
DDX_Text(pDX, IDC_STATIC_PERCENT, m_strProgressInPercent);
DDX_Control(pDX, IDC_PROGRESS, m_prgsProgress);
}

BEGIN_MESSAGE_MAP(CCXICompressorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
  ON_BN_CLICKED(IDC_BUTTON_CHOOSE_INPUTFILE, OnBnClickedButtonChooseInputfile)
  ON_BN_CLICKED(IDC_BUTTON_CHOOSE_OUTPUTFILE, OnBnClickedButtonChooseOutputfile)
  ON_BN_CLICKED(IDC_BUTTON_COMPRESS, OnBnClickedButtonCompress)
  ON_CBN_SELCHANGE(IDC_COMBO_INTSIZE, OnCbnSelchangeComboIntsize)
END_MESSAGE_MAP()


// CCXICompressorDlg Meldungshandler

BOOL CCXICompressorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
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

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

  m_prgsProgress.SetPos(0);
  m_prgsProgress.SetRange(0,100);
	m_cmbIntSize.SetCurSel(2);
  m_strStatusMessage = _T("---");
  m_strProgressInPercent = _T("0 %");
  UpdateData(false);
	
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CCXICompressorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CCXICompressorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CCXICompressorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automatisierungsserver sollten nicht beendet werden, wenn der Benutzer
//  das UI schließt und ein Controller eines seiner Objekte nicht freigibt.
//  Diese Nachrichtenhandler stellen sicher, dass das UI ausgeblendet wird,
//  das Dialogfeld beim Schließen aber erhalten bleibt, wenn der Proxy
//  noch verwendet wird.

void CCXICompressorDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CCXICompressorDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CCXICompressorDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CCXICompressorDlg::CanExit()
{
	// Wenn das Proxy-Objekt noch vorhanden ist, gibt der Automatisierungscontroller
	//  diese Anwendung nicht frei. Blenden Sie nur
	//  die Benutzeroberfläche des Dialogfelds aus.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CCXICompressorDlg::OnBnClickedButtonChooseInputfile()
  {
    BOOL bOpenFileDialog = TRUE;
    LPCTSTR lpszDefExt = NULL;
    LPCTSTR lpszFileName = NULL;
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ENABLESIZING;
    LPCTSTR lpszFilter = NULL;
    CWnd* pParentWnd = NULL;
    DWORD dwSize = 0;
    CFileDialog dlgInputfile(bOpenFileDialog,lpszDefExt,lpszFileName,dwFlags,lpszFilter,pParentWnd,dwSize);
    if (dlgInputfile.DoModal() == IDOK)
    {
      m_strInputfileName = dlgInputfile.GetPathName();
      UpdateData(false);
    }
  }

void CCXICompressorDlg::OnBnClickedButtonChooseOutputfile()
  {
    BOOL bOpenFileDialog = FALSE;
    LPCTSTR lpszDefExt = NULL;
    LPCTSTR lpszFileName = NULL;
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ENABLESIZING;
    LPCTSTR lpszFilter = NULL;
    CWnd* pParentWnd = NULL;
    DWORD dwSize = 0;
    CFileDialog dlgOutputfile(bOpenFileDialog,lpszDefExt,lpszFileName,dwFlags,lpszFilter,pParentWnd,dwSize);
    if (dlgOutputfile.DoModal() == IDOK)
    {
      m_strOutputfileName = dlgOutputfile.GetPathName();
      UpdateData(false);
    }
  }

void CCXICompressorDlg::OnBnClickedButtonCompress()
{
  UpdateData(true);
  m_strInputfileName.Trim(_T(" \\/*?<>|\""));
  m_strOutputfileName.Trim(_T(" \\/*?<>|\""));
  if (m_strInputfileName == _T("")) 
    MessageBox(_T("Eingabedatei fehlt oder ist ungültig!"),_T("Error"), MB_ICONERROR | MB_OK);
  else
  {
    if (m_strOutputfileName == _T(""))
      MessageBox(_T("Ausgabedatei fehlt oder ist ungültig!"),_T("Error"), MB_ICONERROR | MB_OK);
    else
    {
      if (m_cmbIntSize.GetCurSel() < 0 && m_cmbIntSize.GetCurSel() > m_cmbIntSize.GetCount()-1)
        MessageBox(_T("Fehlende oder ungültige Integer-Größe!"),_T("Error"), MB_ICONERROR | MB_OK);
      else
      {
        int intsize;
        switch (m_cmbIntSize.GetCount())
        {
          case 0 : { intsize = 1; break; }
          case 1 : { intsize = 2; break; }
          case 2 : { intsize = 4; break; }
          case 3 : { intsize = 8; break; }
          case 4 : { intsize = 16; break; }
          case 5 : { intsize = 32; break; }
          case 6 : { intsize = 64; break; }
          default : { intsize = 4; break; }
        }
        UpdateData(true);
        m_strStatusMessage = _T("Öffne Eingabedatei");
        UpdateData(false);
        CFile f;
        CStdioFile f2;
        CFileException e,e2;
        if (!f.Open(LPCTSTR(m_strInputfileName),CFile::modeRead,&e))
        {
          #ifdef _DEBUG
            afxDump << "File could not be opened " << e.m_cause << "\n";
          #endif
          MessageBox(_T("Eingabedatei konnte nicht geöffnet werden!\n"),_T("Error"), MB_ICONERROR | MB_OK);
        } else { 
          f2.Open(LPCTSTR("file1.tmp"),CFile::modeCreate | CFile::modeWrite,&e2);
          int percent = 0;
          int count = 0;
          char buffer[1];
          CString strtemp;
          DWORD dwRead;
          m_strStatusMessage = _T("Lese Eingabedatei..."); UpdateData(false);
          for (ULONGLONG size = 0; size < f.GetLength(); size++)
          {
            MSG msg;
            while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
            {
              TranslateMessage(&msg);
              DispatchMessage(&msg);
            }
            dwRead = f.Read(buffer,1);
            count++;
            byte i = (int)buffer[0];
            CString strtemp2;
            strtemp2.Format("%x",i);
            if (strtemp2.GetLength() == 1) strtemp2 = _T("0")+strtemp2;
            strtemp = strtemp + strtemp2;
            if (count == 4)
            {
              long a=0;
              a = atol(strtemp);
              strtemp2.Format("%d",a);
              strtemp2 += " ";
              f2.WriteString(strtemp2);
              count = 0;
              strtemp = _T("");
            }


            percent = (100*f.GetPosition())/f.GetLength();
            m_prgsProgress.SetPos(percent);
            m_strProgressInPercent.Format("%d",percent);
            m_strProgressInPercent += _T(" %");
            UpdateData(false);
          }
          f.Close();
          f2.Close();
          

        }
      }
    }
  }
}

void CCXICompressorDlg::OnCbnSelchangeComboIntsize()
  {
  // TODO: Fügen Sie hier Ihren Kontrollbehandlungscode für die Benachrichtigung ein.
  }
