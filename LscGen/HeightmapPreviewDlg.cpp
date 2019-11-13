// HeightmapPreviewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "lscgen.h"
#include "HeightmapPreviewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHeightmapPreviewDlg dialog


CHeightmapPreviewDlg::CHeightmapPreviewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHeightmapPreviewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHeightmapPreviewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHeightmapPreviewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHeightmapPreviewDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHeightmapPreviewDlg, CDialog)
	//{{AFX_MSG_MAP(CHeightmapPreviewDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHeightmapPreviewDlg message handlers

BOOL CHeightmapPreviewDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  char szTempPath[MAX_PATH] = {0};
  GetTempPath(MAX_PATH,szTempPath);
  CString
    strName = _T(""),
    strComments = _T(""),
    strSize = _T(""),
    strHeight = _T(""),
    strDatas = _T(""),
    Filename = CString(szTempPath)+"\\temp.lsc";
  CStdioFile File;
  if (File.Open(LPCTSTR(Filename), CFile::modeRead))
  {
    BeginWaitCursor();
    File.ReadString(strName);
    File.ReadString(strComments);
    File.ReadString(strSize);
    CString strTemp;
    int n = 0;
    while (n != -1)
    {
      n = strSize.Find(' ');
      strTemp.Format("%d",n);
      MessageBox(strTemp);
    }
    File.ReadString(strHeight);
    File.ReadString(strDatas);
    EndWaitCursor();
  }
  File.Close();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
