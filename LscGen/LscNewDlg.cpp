// LscNewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LscGen.h"
#include "LscNewDlg.h"
#include "HeightmapPreviewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLscNewDlg dialog


CLscNewDlg::CLscNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLscNewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLscNewDlg)
	m_strLscName = _T("");
	m_uintMethod1 = 500;
	m_uintMethod2 = 12000000;
	m_uintSizeX = 255;
	m_uintSizeY = 255;
	m_uintStartX = 1;
	m_uintStartY = 1;
	m_strLscComments = _T("");
	m_uintHeightDescAfter = 10;
	m_rbtnMethod = -1;
	m_nStartpointXY = -1;
	//}}AFX_DATA_INIT
}

void CLscNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLscNewDlg)
	DDX_Control(pDX, IDC_COMBO_ALGORITHM, m_cmbAlgorithm);
	DDX_Control(pDX, IDC_PROGRESS_GENERATE, m_prgsGenerate);
	DDX_Text(pDX, IDC_EDIT_LSC_NAME, m_strLscName);
	DDX_Text(pDX, IDC_EDIT_METHOD1, m_uintMethod1);
	DDV_MinMaxUInt(pDX, m_uintMethod1, 1, 4294967295);
	DDX_Text(pDX, IDC_EDIT_METHOD2, m_uintMethod2);
	DDV_MinMaxUInt(pDX, m_uintMethod2, 1, 4294967295);
	DDX_Text(pDX, IDC_EDIT_SIZEX, m_uintSizeX);
	DDV_MinMaxUInt(pDX, m_uintSizeX, 1, 2048);
	DDX_Text(pDX, IDC_EDIT_SIZEY, m_uintSizeY);
	DDV_MinMaxUInt(pDX, m_uintSizeY, 1, 2048);
	DDX_Text(pDX, IDC_EDIT_START_X, m_uintStartX);
	DDV_MinMaxUInt(pDX, m_uintStartX, 1, 2048);
	DDX_Text(pDX, IDC_EDIT_START_Y, m_uintStartY);
	DDV_MinMaxUInt(pDX, m_uintStartY, 1, 2048);
	DDX_Text(pDX, IDC_EDIT_LSC_COMMENTS, m_strLscComments);
	DDX_Radio(pDX, IDC_RADIO_METHOD1, m_rbtnMethod);
	DDX_Radio(pDX, IDC_RADIO_START_XY, m_nStartpointXY);
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_BUTTON_GENERATE, m_btnGenerate);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnAbort);

  m_btnGenerate.SetThemeHelper(&m_ThemeHelper);
  m_btnGenerate.SetIcon(IDI_ICON_GEAR);
  m_btnGenerate.SetCheck(1);
  m_btnGenerate.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnGenerate.EnableBalloonTooltip();
  m_btnGenerate.SetTooltipText("Landschaft erstellen");

  m_btnOK.SetThemeHelper(&m_ThemeHelper);
  m_btnOK.SetIcon(IDI_ICON_CHECK2);
  m_btnOK.SetCheck(1);
  m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnOK.EnableBalloonTooltip();
  m_btnOK.SetTooltipText("OK");

  m_btnAbort.SetThemeHelper(&m_ThemeHelper);
  m_btnAbort.SetIcon(IDI_ICON_STOP);
  m_btnAbort.SetCheck(0);
  m_btnAbort.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAbort.EnableBalloonTooltip();
  m_btnAbort.SetTooltipText("Abbruch");

  m_cmbAlgorithm.SetCurSel(0);

  GetDlgItem(IDOK)->EnableWindow(false);
  GetDlgItem(IDC_BUTTON_GENERATE)->EnableWindow(false);
  GetDlgItem(IDC_COMBO_ALGORITHM)->EnableWindow(false);
  GetDlgItem(IDC_RADIO_METHOD1)->EnableWindow(false);
  GetDlgItem(IDC_RADIO_METHOD2)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_METHOD1)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_METHOD2)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_SIZEX)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_SIZEY)->EnableWindow(false);
  GetDlgItem(IDC_RADIO_START_XY)->EnableWindow(false);
  GetDlgItem(IDC_RADIO_START_MIDPOINT)->EnableWindow(false);
  GetDlgItem(IDC_RADIO_START_RANDOM)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_START_X)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_START_Y)->EnableWindow(false);
}


BEGIN_MESSAGE_MAP(CLscNewDlg, CDialog)
	//{{AFX_MSG_MAP(CLscNewDlg)
	ON_EN_CHANGE(IDC_EDIT_LSC_NAME, OnChangeEditLscName)
	ON_BN_CLICKED(IDC_RADIO_METHOD1, OnRadioMethod1)
	ON_BN_CLICKED(IDC_RADIO_METHOD2, OnRadioMethod2)
	ON_BN_CLICKED(IDC_RADIO_START_XY, OnRadioStartXY)
	ON_BN_CLICKED(IDC_RADIO_START_RANDOM, OnRadioStartRandom)
	ON_BN_CLICKED(IDC_BUTTON_GENERATE, OnButtonGenerate)
	ON_BN_CLICKED(IDC_RADIO_START_MIDPOINT, OnRadioStartMidpoint)
	ON_BN_CLICKED(IDC_BUTTON_HM_PREVIEW, OnButtonHmPreview)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLscNewDlg message handlers

void CLscNewDlg::OnChangeEditLscName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
  UpdateData(true);
	if (m_strLscName != "")
  {
    GetDlgItem(IDC_COMBO_ALGORITHM)->EnableWindow(true);
    GetDlgItem(IDC_RADIO_METHOD1)->EnableWindow(true);
    GetDlgItem(IDC_RADIO_METHOD2)->EnableWindow(true);
  }
}

void CLscNewDlg::OnRadioMethod1() 
{
  GetDlgItem(IDC_EDIT_METHOD1)->EnableWindow(true);
  GetDlgItem(IDC_EDIT_METHOD2)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_SIZEX)->EnableWindow(true);
  GetDlgItem(IDC_EDIT_SIZEY)->EnableWindow(true);
  GetDlgItem(IDC_RADIO_START_XY)->EnableWindow(true);
  GetDlgItem(IDC_RADIO_START_MIDPOINT)->EnableWindow(true);
  GetDlgItem(IDC_RADIO_START_RANDOM)->EnableWindow(true);
}

void CLscNewDlg::OnRadioMethod2() 
{
  GetDlgItem(IDC_EDIT_METHOD1)->EnableWindow(false);
  GetDlgItem(IDC_EDIT_METHOD2)->EnableWindow(true);
  GetDlgItem(IDC_EDIT_SIZEX)->EnableWindow(true);
  GetDlgItem(IDC_EDIT_SIZEY)->EnableWindow(true);
  GetDlgItem(IDC_RADIO_START_XY)->EnableWindow(true);
  GetDlgItem(IDC_RADIO_START_MIDPOINT)->EnableWindow(true);
  GetDlgItem(IDC_RADIO_START_RANDOM)->EnableWindow(true);
}

void CLscNewDlg::OnRadioStartXY() 
{
  GetDlgItem(IDC_EDIT_START_X)->EnableWindow(true);	
  GetDlgItem(IDC_EDIT_START_Y)->EnableWindow(true);	
  GetDlgItem(IDC_BUTTON_GENERATE)->EnableWindow(true);
}

void CLscNewDlg::OnRadioStartMidpoint() 
{
  GetDlgItem(IDC_EDIT_START_X)->EnableWindow(false);	
  GetDlgItem(IDC_EDIT_START_Y)->EnableWindow(false);	
  GetDlgItem(IDC_BUTTON_GENERATE)->EnableWindow(true);
}

void CLscNewDlg::OnRadioStartRandom() 
{
  GetDlgItem(IDC_EDIT_START_X)->EnableWindow(false);	
  GetDlgItem(IDC_EDIT_START_Y)->EnableWindow(false);	
  GetDlgItem(IDC_BUTTON_GENERATE)->EnableWindow(true);
}

void CLscNewDlg::OnButtonGenerate() 
{
  CString
    strConcatMaster = _T(""),
    strConcatSlave = _T(""),
    strTemp = _T("");
  boolean bFirstStart = true;
  UINT i,uintProgressStep = 0;
  m_uintStartX = 1;
  m_uintStartY = 1;
  m_nStartpointXY = 1;
  m_uintAlgorithm = m_cmbAlgorithm.GetCurSel();
  m_arrHeightfield = new CMatrix<UINT>(2048+2,2048+2);
  UpdateData(true);
  m_uintMethod1--;
  m_uintMethod2--;
  m_bAbort = false;
  if (m_rbtnMethod == 0) m_prgsGenerate.SetRange32(0,m_uintMethod1-1); else m_prgsGenerate.SetRange32(0,m_uintMethod2);
  m_prgsGenerate.SetPos(0);
  BeginWaitCursor();
  switch (m_uintAlgorithm)
  {
    case 0 :
    {
      if (m_uintAlgorithm == 0) // Algorithmus 1 
      {
        if (m_rbtnMethod == 0) // Algorithmus 1 Methode 1
        {
          while ((*m_arrHeightfield)[m_uintStartX][m_uintStartY] <= m_uintMethod1-1)
          {
            if (!m_bAbort)
            {
              if (bFirstStart) // Startpunkt setzen
              {
                bFirstStart = false;
                switch(m_nStartpointXY)
                {
                  case 0 :
                  {
                    UpdateData(true);
                    break;
                  }
                  case 1 :
                  { 
                    m_uintStartX = (rand()%m_uintSizeX)+1;
                    m_uintStartY = (rand()%m_uintSizeY)+1;
                    break;
                  }
                  case 2 :
                  {
                    m_uintStartX = m_uintSizeX / 2;
                    m_uintStartY = m_uintSizeY / 2;
                    break;
                  }
                }
              } else {
                m_uintStartX = (rand()%m_uintSizeX)+1;
                m_uintStartY = (rand()%m_uintSizeY)+1;
              }
              (*m_arrHeightfield)[m_uintStartX][m_uintStartY]++;
              uintProgressStep++;
              if (uintProgressStep % 1000 == 0) m_prgsGenerate.SetPos((*m_arrHeightfield)[m_uintStartX][m_uintStartY]);
              MSG msg;
              while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
              {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
              }
            }
          }
        } else if (m_rbtnMethod == 1) { // Algorithmus 1 Methode 2
          for (i = 0; i < m_uintMethod2; i++)
          {
            if (!m_bAbort)
            {
              if (bFirstStart) // Startpunkt setzen
              {
                bFirstStart = false;
                switch(m_nStartpointXY)
                {
                  case 0 :
                  {
                    UpdateData(true);
                    break;
                  }
                  case 1 :
                  { 
                    m_uintStartX = (rand()%m_uintSizeX)+1;
                    m_uintStartY = (rand()%m_uintSizeY)+1;
                    break;
                  }
                  case 2 :
                  {
                    m_uintStartX = m_uintSizeX / 2;
                    m_uintStartY = m_uintSizeY / 2;
                    break;
                  }
                }
              } else {        
                m_uintStartX = (rand()%m_uintSizeX)+1;
                m_uintStartY = (rand()%m_uintSizeY)+1;
                (*m_arrHeightfield)[m_uintStartX][m_uintStartY]++;
              }
              if (i % 100000 == 0) m_prgsGenerate.SetPos(i);
              MSG msg;
              while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
              {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
              }
            }
          }
        }
      }      
      break;
    }
    case 1 :
    {
      if (m_rbtnMethod == 0) // Algorithmus 2 Methode 1
      {
        while ((*m_arrHeightfield)[m_uintStartX][m_uintStartY] <= m_uintMethod1-1)
        {
          if (!m_bAbort)
          {
            if (bFirstStart)// Startpunkt setzen
            {
              bFirstStart = false;
              switch(m_nStartpointXY)
              {
                case 0 :
                {
                  UpdateData(true);
                  break;
                }
                case 1 :
                { 
                  m_uintStartX = (rand()%m_uintSizeX)+1;
                  m_uintStartY = (rand()%m_uintSizeY)+1;
                  break;
                }
                case 2 :
                {
                  m_uintStartX = m_uintSizeX / 2;
                  m_uintStartY = m_uintSizeY / 2;
                  break;
                }
              }
            } else {              
              UINT Move = (rand()%9)+1;
              switch (Move)
              {
                case 1 : { m_uintStartX--; m_uintStartY++; break; }
                case 2 : { m_uintStartY++; break; }
                case 3 : { m_uintStartX++; m_uintStartY++; break; }
                case 4 : { m_uintStartX--; break; }
                case 6 : { m_uintStartX++; break; }
                case 7 : { m_uintStartX--; m_uintStartY--; break; }
                case 8 : { m_uintStartY--; break; }
                case 9 : { m_uintStartX++; m_uintStartY--; break; }
              }
            }
            if (m_uintStartX < 1) m_uintStartX = m_uintStartX+m_uintSizeX;
            if (m_uintStartY < 1) m_uintStartY = m_uintStartY+m_uintSizeY;
            if (m_uintStartX > m_uintSizeX) m_uintStartX = m_uintStartX-m_uintSizeX;
            if (m_uintStartY > m_uintSizeY) m_uintStartY = m_uintStartY-m_uintSizeY;
            (*m_arrHeightfield)[m_uintStartX][m_uintStartY]++;
            uintProgressStep++;
            if (uintProgressStep % 1000 == 0) m_prgsGenerate.SetPos((*m_arrHeightfield)[m_uintStartX][m_uintStartY]);
            MSG msg;
            while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
            {
              TranslateMessage(&msg);
              DispatchMessage(&msg);
            }
          }
        }
      } else if (m_rbtnMethod == 1) { // Algorithmus 2 Methode 2
        for (i = 0; i < m_uintMethod2; i++)
        {
          if (!m_bAbort)
          {
            if (bFirstStart)// Startpunkt setzen
            {
              bFirstStart = false;
              switch(m_nStartpointXY)
              {
                case 0 :
                {
                  UpdateData(true);
                  break;
                }
                case 1 :
                { 
                  m_uintStartX = (rand()%m_uintSizeX)+1;
                  m_uintStartY = (rand()%m_uintSizeY)+1;
                  break;
                }
                case 2 :
                {
                  m_uintStartX = m_uintSizeX / 2;
                  m_uintStartY = m_uintSizeY / 2;
                  break;
                }
              }
            } else {
              UINT Move = (rand()%9)+1;
              switch (Move)
              {
                case 1 : { m_uintStartX--; m_uintStartY++; break; }
                case 2 : { m_uintStartY++; break; }
                case 3 : { m_uintStartX++; m_uintStartY++; break; }
                case 4 : { m_uintStartX--; break; }
                case 6 : { m_uintStartX++; break; }
                case 7 : { m_uintStartX--; m_uintStartY--; break; }
                case 8 : { m_uintStartY--; break; }
                case 9 : { m_uintStartX++; m_uintStartY--; break; }
              }
            }
            if (m_uintStartX < 1) m_uintStartX = m_uintStartX+m_uintSizeX;
            if (m_uintStartY < 1) m_uintStartY = m_uintStartY+m_uintSizeY;
            if (m_uintStartX > m_uintSizeX) m_uintStartX = m_uintStartX-m_uintSizeX;
            if (m_uintStartY > m_uintSizeY) m_uintStartY = m_uintStartY-m_uintSizeY;
            (*m_arrHeightfield)[m_uintStartX][m_uintStartY]++;
            if (i % 100000 == 0) m_prgsGenerate.SetPos(i);
            MSG msg;
            while (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
            {
              TranslateMessage(&msg);
              DispatchMessage(&msg);
            }
          }
        }
      }
    }
    break;
  }
  if (m_rbtnMethod == 0) m_prgsGenerate.SetPos(m_uintMethod1-1); else m_prgsGenerate.SetPos(m_uintMethod2);
  UpdateData(true);
  GetDlgItem(IDOK)->EnableWindow(true);
  EndWaitCursor();
}

void CLscNewDlg::OnCancel() 
{
	m_bAbort = false;
  UpdateData(false);
	CDialog::OnCancel();
}

void CLscNewDlg::OnOK() 
{
  char szTempPath[MAX_PATH] = {0};
  GetTempPath(MAX_PATH,szTempPath);
  CString
    strConcatMaster = _T(""),
    strConcatSlave = _T(""),
    strTemp = _T(""),
    Filename = CString(szTempPath)+"\\temp.lsc";
  CStdioFile File;
  if (File.Open(LPCTSTR(Filename), CFile::modeCreate | CFile::modeWrite))
  {
    BeginWaitCursor();
    strConcatMaster = m_strLscName+"\n"; 
    strConcatMaster = strConcatMaster+m_strLscComments+"\n"; 
    strConcatSlave.Format("%d",m_uintSizeX);
    strConcatMaster += strConcatSlave+" ";
    strConcatSlave.Format("%d",m_uintSizeY);
    strConcatMaster += strConcatSlave+" \n";
    strConcatSlave.Format("%d",(*m_arrHeightfield).GetMaxValue());
    strConcatMaster += strConcatSlave+" \n";
    File.WriteString(strConcatMaster);
    for (UINT y = 1; y <= m_uintSizeY; y++)
    {
      for (UINT x = 1; x <= m_uintSizeX; x++)
      {
        strConcatMaster.Format("%d",(*m_arrHeightfield)[x][y]);
        strConcatMaster += " ";
        File.WriteString(strConcatMaster);
      }
    }
    EndWaitCursor();
  }
  File.Close();
  delete m_arrHeightfield;
	CDialog::OnOK();
}

void CLscNewDlg::OnButtonHmPreview() 
{
  char szTempPath[MAX_PATH] = {0};
  GetTempPath(MAX_PATH,szTempPath);
  CString
    strConcatMaster = _T(""),
    strConcatSlave = _T(""),
    strTemp = _T(""),
    Filename = CString(szTempPath)+"\\temp.lsc";
  CStdioFile File;
  if (File.Open(LPCTSTR(Filename), CFile::modeCreate | CFile::modeWrite))
  {
    BeginWaitCursor();
    strConcatMaster = m_strLscName+"\n"; 
    strConcatMaster = strConcatMaster+m_strLscComments+"\n"; 
    strConcatSlave.Format("%d",m_uintSizeX);
    strConcatMaster += strConcatSlave+" ";
    strConcatSlave.Format("%d",m_uintSizeY);
    strConcatMaster += strConcatSlave+"\n";
    strConcatSlave.Format("%d",(*m_arrHeightfield).GetMaxValue());
    strConcatMaster += strConcatSlave+"\n";
    File.WriteString(strConcatMaster);
    for (UINT y = 1; y <= m_uintSizeY; y++)
    {
      for (UINT x = 1; x <= m_uintSizeX; x++)
      {
        strConcatMaster.Format("%d",(*m_arrHeightfield)[x][y]);
        strConcatMaster += " ";
        File.WriteString(strConcatMaster);
      }
    }
    EndWaitCursor();
  }
  File.Close();
  CHeightmapPreviewDlg dlgHeightmapPreview;
  dlgHeightmapPreview.DoModal();
}
