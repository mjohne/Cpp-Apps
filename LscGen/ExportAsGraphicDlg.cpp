// ExportAsGraphicDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LscGen.h"
#include "ExportAsGraphicDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExportAsGraphicDlg dialog


CExportAsGraphicDlg::CExportAsGraphicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExportAsGraphicDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExportAsGraphicDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CExportAsGraphicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExportAsGraphicDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

  DDX_Control(pDX, IDC_BUTTON_EXPORTAS_PGM, m_btnExportAsPGM);
  DDX_Control(pDX, IDC_BUTTON_EXPORTAS_RAW, m_btnExportAsRAW);
  DDX_Control(pDX, IDC_BUTTON_EXPORTAS_XPM, m_btnExportAsXPM);

  m_btnExportAsPGM.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsPGM.SetIcon(IDI_ICON_PHOTO_SCENERY);
  m_btnExportAsPGM.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsPGM.EnableBalloonTooltip();
  m_btnExportAsPGM.SetTooltipText("Als PGM exportieren");

  m_btnExportAsRAW.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsRAW.SetIcon(IDI_ICON_PHOTO_SCENERY);
  m_btnExportAsRAW.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsRAW.EnableBalloonTooltip();
  m_btnExportAsRAW.SetTooltipText("Als RAW exportieren");

  m_btnExportAsXPM.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsXPM.SetIcon(IDI_ICON_PHOTO_SCENERY);
  m_btnExportAsXPM.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsXPM.EnableBalloonTooltip();
  m_btnExportAsXPM.SetTooltipText("Als XPM exportieren");
}

BEGIN_MESSAGE_MAP(CExportAsGraphicDlg, CDialog)
	//{{AFX_MSG_MAP(CExportAsGraphicDlg)
	ON_BN_CLICKED(IDC_BUTTON_EXPORTAS_PGM, OnButtonExportAsPgm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExportAsGraphicDlg message handlers

void CExportAsGraphicDlg::OnButtonExportAsPgm() 
{
  CString
    strRW = _T(""),
    strConcatMaster = _T(""),
    strConcatSlave = _T(""),
    strTemp = _T(""),
    inFilename = _T(""),
    outFilename = _T("");
  CFileDialog FileDialog(false,"","",OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,"Portable Graymap (*.pgm)|*.pgm|");
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
        UINT i = 0;
        while(inFile.ReadString(strRW))
        {
          i++;
          switch (i)
          {
            case 1  : { strRW = "P2\n"; break; }
            case 2  : { strRW = "#created with LscGen\n"; break; }
            default : { strRW = strRW+"\n"; }
          }
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

BOOL CExportAsGraphicDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//m_arrHeightfield = new CMatrix<UINT>(2048+2,2048+2);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
