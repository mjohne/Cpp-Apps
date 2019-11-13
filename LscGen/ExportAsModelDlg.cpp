// ExportAsModelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LscGen.h"
#include "ExportAsModelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExportAsModelDlg dialog


CExportAsModelDlg::CExportAsModelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExportAsModelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExportAsModelDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CExportAsModelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExportAsModelDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP

  DDX_Control(pDX, IDC_BUTTON_EXPORTAS_VRML, m_btnExportAsVRML);
  DDX_Control(pDX, IDC_BUTTON_EXPORTAS_X3D, m_btnExportAsX3D);

  m_btnExportAsVRML.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsVRML.SetIcon(IDI_ICON_VRML);
  m_btnExportAsVRML.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsVRML.EnableBalloonTooltip();
  m_btnExportAsVRML.SetTooltipText("Export as VRML");

  m_btnExportAsX3D.SetThemeHelper(&m_ThemeHelper);
  m_btnExportAsX3D.SetIcon(IDI_ICON_X3D);
  m_btnExportAsX3D.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnExportAsX3D.EnableBalloonTooltip();
  m_btnExportAsX3D.SetTooltipText("Export as X3D");
}


BEGIN_MESSAGE_MAP(CExportAsModelDlg, CDialog)
	//{{AFX_MSG_MAP(CExportAsModelDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExportAsModelDlg message handlers
