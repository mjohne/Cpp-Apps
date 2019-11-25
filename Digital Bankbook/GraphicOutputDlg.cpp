// GraphicOutputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalBankbook.h"
#include "GraphicOutputDlg.h"
#include "AppOptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGraphicOutputDlg dialog


CGraphicOutputDlg::CGraphicOutputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGraphicOutputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGraphicOutputDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGraphicOutputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGraphicOutputDlg)
	DDX_Control(pDX, IDC_BUTTON_APP_OPTIONS, m_btnAppOptions);
	DDX_Control(pDX, IDC_BUTTON_GRAPHICSAVE, m_btnSaveGraphic);
	DDX_Control(pDX, IDC_BUTTON_GRAPHICPRINT, m_btnPrintGraphic);
	DDX_Control(pDX, IDC_BUTTON_COURSE, m_btnCourse);
	DDX_Control(pDX, IDC_BUTTON_DCDIFF, m_btnDCDiff);
	DDX_Control(pDX, IDC_BUTTON_DCRATIO, m_btnDCRatio);
	DDX_Control(pDX, IDC_BUTTON_TIMESCALE_BACKWARD, m_btnTimescaleBackward);
	DDX_Control(pDX, IDC_BUTTON_TIMESCALE_BEGIN, m_btnTimescaleBegin);
	DDX_Control(pDX, IDC_BUTTON_TIMESCALE_END, m_btnTimescaleEnd);
	DDX_Control(pDX, IDC_BUTTON_TIMESCALE_FORWARD, m_btnTimescaleForward);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGraphicOutputDlg, CDialog)
	//{{AFX_MSG_MAP(CGraphicOutputDlg)
	ON_BN_CLICKED(IDC_BUTTON_TIMESCALE_BEGIN, OnButtonTimescaleBegin)
	ON_BN_CLICKED(IDC_BUTTON_TIMESCALE_BACKWARD, OnButtonTimescaleBackward)
	ON_BN_CLICKED(IDC_BUTTON_TIMESCALE_FORWARD, OnButtonTimescaleForward)
	ON_BN_CLICKED(IDC_BUTTON_TIMESCALE_END, OnButtonTimescaleEnd)
	ON_BN_CLICKED(IDC_BUTTON_COURSE, OnButtonCourse)
	ON_BN_CLICKED(IDC_BUTTON_DCDIFF, OnButtonDcdiff)
	ON_BN_CLICKED(IDC_BUTTON_DCRATIO, OnButtonDcratio)
	ON_BN_CLICKED(IDC_BUTTON_GRAPHICPRINT, OnButtonGraphicPrint)
	ON_BN_CLICKED(IDC_BUTTON_GRAPHICSAVE, OnButtonGraphicSave)
	ON_BN_CLICKED(IDC_BUTTON_APP_OPTIONS, OnButtonAppOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphicOutputDlg message handlers

void CGraphicOutputDlg::OnButtonTimescaleBegin() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnButtonTimescaleBackward() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnButtonTimescaleForward() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnButtonTimescaleEnd() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnButtonCourse() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnButtonDcdiff() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnButtonDcratio() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

BOOL CGraphicOutputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

  m_btnTimescaleBegin.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnTimescaleBegin.DrawAsToolbar(false);
  m_btnTimescaleBegin.SetThemeHelper(&m_ThemeHelper);
  m_btnTimescaleBegin.EnableBalloonTooltip();
  m_btnTimescaleBegin.SetTooltipText(IDS_TIMESCALE_BEGIN);
  m_btnTimescaleBegin.SetIcon(IDI_ICON_ARROW_BEGIN_32);
  	
  m_btnTimescaleBackward.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnTimescaleBackward.DrawAsToolbar(false);
  m_btnTimescaleBackward.SetThemeHelper(&m_ThemeHelper);
  m_btnTimescaleBackward.EnableBalloonTooltip();
  m_btnTimescaleBackward.SetTooltipText(IDS_TIMESCALE_BACKWARD);
  m_btnTimescaleBackward.SetIcon(IDI_ICON_ARROW_LEFT_32);
  	
  m_btnTimescaleForward.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnTimescaleForward.DrawAsToolbar(false);
  m_btnTimescaleForward.SetThemeHelper(&m_ThemeHelper);
  m_btnTimescaleForward.EnableBalloonTooltip();
  m_btnTimescaleForward.SetTooltipText(IDS_TIMESCALE_FORWARD);
  m_btnTimescaleForward.SetIcon(IDI_ICON_ARROW_RIGHT_32);
  	
  m_btnTimescaleEnd.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnTimescaleEnd.DrawAsToolbar(false);
  m_btnTimescaleEnd.SetThemeHelper(&m_ThemeHelper);
  m_btnTimescaleEnd.EnableBalloonTooltip();
  m_btnTimescaleEnd.SetTooltipText(IDS_TIMESCALE_END);
  m_btnTimescaleEnd.SetIcon(IDI_ICON_ARROW_END_32);
  	
  m_btnCourse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCourse.DrawAsToolbar(false);
  m_btnCourse.SetThemeHelper(&m_ThemeHelper);
  m_btnCourse.EnableBalloonTooltip();
  m_btnCourse.SetTooltipText(IDS_COURSE);
  m_btnCourse.SetIcon(IDI_ICON_CHART_32);
  	
  m_btnDCDiff.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnDCDiff.DrawAsToolbar(false);
  m_btnDCDiff.SetThemeHelper(&m_ThemeHelper);
  m_btnDCDiff.EnableBalloonTooltip();
  m_btnDCDiff.SetTooltipText(IDS_DCDIFF);
  m_btnDCDiff.SetIcon(IDI_ICON_COLCHART_32);
  	
  m_btnDCRatio.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnDCRatio.DrawAsToolbar(false);
  m_btnDCRatio.SetThemeHelper(&m_ThemeHelper);
  m_btnDCRatio.EnableBalloonTooltip();
  m_btnDCRatio.SetTooltipText(IDS_DCRATION);
  m_btnDCRatio.SetIcon(IDI_ICON_PIECHART_32);
  	
  m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCancel.DrawAsToolbar(false);
  m_btnCancel.SetThemeHelper(&m_ThemeHelper);
  m_btnCancel.EnableBalloonTooltip();
  m_btnCancel.SetTooltipText(IDS_CANCEL);
  m_btnCancel.SetIcon(IDI_ICON_EXIT_32);

  m_btnSaveGraphic.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSaveGraphic.DrawAsToolbar(false);
  m_btnSaveGraphic.SetThemeHelper(&m_ThemeHelper);
  m_btnSaveGraphic.EnableBalloonTooltip();
  m_btnSaveGraphic.SetTooltipText(IDS_GRAPHIC_SAVE);
  m_btnSaveGraphic.SetIcon(IDI_ICON_IMAGE_32);

  m_btnPrintGraphic.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnPrintGraphic.DrawAsToolbar(false);
  m_btnPrintGraphic.SetThemeHelper(&m_ThemeHelper);
  m_btnPrintGraphic.EnableBalloonTooltip();
  m_btnPrintGraphic.SetTooltipText(IDS_GRAPHIC_PRINT);
  m_btnPrintGraphic.SetIcon(IDI_ICON_PRINT_32);

  m_btnAppOptions.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAppOptions.DrawAsToolbar(false);
  m_btnAppOptions.SetThemeHelper(&m_ThemeHelper);
  m_btnAppOptions.EnableBalloonTooltip();
  m_btnAppOptions.SetTooltipText(IDS_APPOPTIONS);
  m_btnAppOptions.SetIcon(IDI_ICON_GEAR_32);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGraphicOutputDlg::OnButtonGraphicPrint() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnButtonGraphicSave() 
{
	// TODO: Add your control notification handler code here
	
}

void CGraphicOutputDlg::OnButtonAppOptions() 
{
  CAppOptionsDlg dlgAppOptions;
  dlgAppOptions.DoModal();
}
