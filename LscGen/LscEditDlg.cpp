// LscEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "lscgen.h"
#include "LscEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLscEditDlg dialog


CLscEditDlg::CLscEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLscEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLscEditDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

}


void CLscEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLscEditDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BUTTON_UP2, m_btnRouteUp);
	DDX_Control(pDX, IDC_BUTTON_DOWN2, m_btnRouteDown);
	DDX_Control(pDX, IDC_BUTTON_LEFT2, m_btnRouteLeft);
	DDX_Control(pDX, IDC_BUTTON_RIGHT2, m_btnRouteRight);
	DDX_Control(pDX, IDC_BUTTON_RAISE, m_btnRaise);
	DDX_Control(pDX, IDC_BUTTON_FLAT, m_btnFlat);
	DDX_Control(pDX, IDC_BUTTON_ROTATE_LEFT, m_btnRotateLeft);
	DDX_Control(pDX, IDC_BUTTON_ROTATE_RIGHT, m_btnRotateRight);
	DDX_Control(pDX, IDC_BUTTON_INVERT, m_btnInvert);
	DDX_Control(pDX, IDC_BUTTON_GLACIATE, m_btnGlaciate);
	DDX_Control(pDX, IDC_BUTTON_HORIZONTAL, m_btnMirrorHorizontal);
	DDX_Control(pDX, IDC_BUTTON_VERTICAL, m_btnMirrorVertical);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnAbort);

  m_btnRouteUp.SetIcon(IDI_ICON_ARROW_UP_BLUE);
  m_btnRouteUp.SetCheck(1);
  m_btnRouteUp.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnRouteUp.EnableBalloonTooltip();
  m_btnRouteUp.SetTooltipText("Oben");

  m_btnRouteDown.SetIcon(IDI_ICON_ARROW_DOWN_BLUE);
  m_btnRouteDown.SetCheck(1);
  m_btnRouteDown.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnRouteDown.EnableBalloonTooltip();
  m_btnRouteDown.SetTooltipText("Unten");

  m_btnRouteLeft.SetIcon(IDI_ICON_ARROW_LEFT_BLUE);
  m_btnRouteLeft.SetCheck(1);
  m_btnRouteLeft.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnRouteLeft.EnableBalloonTooltip();
  m_btnRouteLeft.SetTooltipText("Links");

  m_btnRouteRight.SetIcon(IDI_ICON_ARROW_RIGHT_BLUE);
  m_btnRouteRight.SetCheck(1);
  m_btnRouteRight.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnRouteRight.EnableBalloonTooltip();
  m_btnRouteRight.SetTooltipText("Rechts");

  m_btnRaise.SetThemeHelper(&m_ThemeHelper);
  m_btnRaise.SetIcon(IDI_ICON_NAVIGATE_UP);
  m_btnRaise.SetCheck(1);
  m_btnRaise.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnRaise.EnableBalloonTooltip();
  m_btnRaise.SetTooltipText("Ebene um +1 erhöhen");

  m_btnFlat.SetThemeHelper(&m_ThemeHelper);
  m_btnFlat.SetIcon(IDI_ICON_NAVIGATE_DOWN);
  m_btnFlat.SetCheck(1);
  m_btnFlat.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnFlat.EnableBalloonTooltip();
  m_btnFlat.SetTooltipText("Ebene um -1 senken");

  m_btnRotateLeft.SetThemeHelper(&m_ThemeHelper);
  m_btnRotateLeft.SetIcon(IDI_ICON_UNDO);
  m_btnRotateLeft.SetCheck(1);
  m_btnRotateLeft.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnRotateLeft.EnableBalloonTooltip();
  m_btnRotateLeft.SetTooltipText("Nach links rotieren");

  m_btnRotateRight.SetThemeHelper(&m_ThemeHelper);
  m_btnRotateRight.SetIcon(IDI_ICON_REDO);
  m_btnRotateRight.SetCheck(1);
  m_btnRotateRight.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnRotateRight.EnableBalloonTooltip();
  m_btnRotateRight.SetTooltipText("Nach rechts rotieren");

  m_btnInvert.SetThemeHelper(&m_ThemeHelper);
  m_btnInvert.SetIcon(IDI_ICON_INVERT);
  m_btnInvert.SetCheck(1);
  m_btnInvert.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnInvert.EnableBalloonTooltip();
  m_btnInvert.SetTooltipText("Invertieren");

  m_btnGlaciate.SetThemeHelper(&m_ThemeHelper);
  m_btnGlaciate.SetIcon(IDI_ICON_GLACIATE);
  m_btnGlaciate.SetCheck(1);
  m_btnGlaciate.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnGlaciate.EnableBalloonTooltip();
  m_btnGlaciate.SetTooltipText("Glätten");

  m_btnMirrorVertical.SetThemeHelper(&m_ThemeHelper);
  m_btnMirrorVertical.SetIcon(IDI_ICON_MIRROR_VERT);
  m_btnMirrorVertical.SetCheck(1);
  m_btnMirrorVertical.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnMirrorVertical.EnableBalloonTooltip();
  m_btnMirrorVertical.SetTooltipText("Vertikal spiegeln");

  m_btnMirrorHorizontal.SetThemeHelper(&m_ThemeHelper);
  m_btnMirrorHorizontal.SetIcon(IDI_ICON_MIRROR_HORI);
  m_btnMirrorHorizontal.SetCheck(1);
  m_btnMirrorHorizontal.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnMirrorHorizontal.EnableBalloonTooltip();
  m_btnMirrorHorizontal.SetTooltipText("Horizontal spiegeln");

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
}


BEGIN_MESSAGE_MAP(CLscEditDlg, CDialog)
	//{{AFX_MSG_MAP(CLscEditDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLscEditDlg message handlers
