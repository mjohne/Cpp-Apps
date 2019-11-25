// OpenBankbookDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalBankbook.h"
#include "OpenBankbookDlg.h"
#include "GraphicOutputDlg.h"
#include "TransactionDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenBankbookDlg dialog


COpenBankbookDlg::COpenBankbookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpenBankbookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpenBankbookDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COpenBankbookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenBankbookDlg)
	DDX_Control(pDX, IDC_BUTTON_ENTRY_SORTDESC, m_btnSortDescending);
	DDX_Control(pDX, IDC_BUTTON_ENTRY_SORTASC, m_btnSortAscending);
	DDX_Control(pDX, IDC_BUTTON_ENTRY_UP, m_btnMoveUp);
	DDX_Control(pDX, IDC_BUTTON_ENTRY_DOWN, m_btnMoveDown);
	DDX_Control(pDX, IDC_LIST_TRANSACTIONS, m_lstTransactions);
	DDX_Control(pDX, IDC_BUTTON_GRAPHIC_OUTPUT, m_btnGraphicOutput);
	DDX_Control(pDX, IDC_BUTTON_ENTRY_DELETE, m_btnDeleteEntry);
	DDX_Control(pDX, IDC_BUTTON_ENTRY_CHANGE, m_btnChangeEntry);
	DDX_Control(pDX, IDC_BUTTON_ENTRY_ADD, m_btnAddEntry);
	DDX_Control(pDX, IDC_BUTTON_BANKBOOK_CLOSE, m_btnCloseBankbook);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COpenBankbookDlg, CDialog)
	//{{AFX_MSG_MAP(COpenBankbookDlg)
	ON_BN_CLICKED(IDC_BUTTON_ENTRY_ADD, OnButtonEntryAdd)
	ON_BN_CLICKED(IDC_BUTTON_ENTRY_CHANGE, OnButtonEntryChange)
	ON_BN_CLICKED(IDC_BUTTON_ENTRY_DELETE, OnButtonEntryDelete)
	ON_BN_CLICKED(IDC_BUTTON_GRAPHIC_OUTPUT, OnButtonGraphicOutput)
	ON_BN_CLICKED(IDC_BUTTON_BANKBOOK_CLOSE, OnButtonBankbookClose)
	ON_BN_CLICKED(IDC_BUTTON_ENTRY_SORTASC, OnButtonEntrySortasc)
	ON_BN_CLICKED(IDC_BUTTON_ENTRY_SORTDESC, OnButtonEntrySortdesc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenBankbookDlg message handlers

BOOL COpenBankbookDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_btnMoveUp.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnMoveUp.DrawAsToolbar(false);
  m_btnMoveUp.SetThemeHelper(&m_ThemeHelper);
  m_btnMoveUp.EnableBalloonTooltip();
  m_btnMoveUp.SetTooltipText(IDS_ENTRY_MOVEUP);
  m_btnMoveUp.SetIcon(IDI_ICON_UP_32);

  m_btnMoveDown.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnMoveDown.DrawAsToolbar(false);
  m_btnMoveDown.SetThemeHelper(&m_ThemeHelper);
  m_btnMoveDown.EnableBalloonTooltip();
  m_btnMoveDown.SetTooltipText("");
  m_btnMoveDown.SetIcon(IDI_ICON_DOWN_32);

  m_btnSortAscending.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSortAscending.DrawAsToolbar(false);
  m_btnSortAscending.SetThemeHelper(&m_ThemeHelper);
  m_btnSortAscending.EnableBalloonTooltip();
  m_btnSortAscending.SetTooltipText(IDS_SORTASC);
  m_btnSortAscending.SetIcon(IDI_ICON_SORTASC_32);

  m_btnSortDescending.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnSortDescending.DrawAsToolbar(false);
  m_btnSortDescending.SetThemeHelper(&m_ThemeHelper);
  m_btnSortDescending.EnableBalloonTooltip();
  m_btnSortDescending.SetTooltipText(IDS_SORTDESC);
  m_btnSortDescending.SetIcon(IDI_ICON_SORTDESC_32);

  m_btnAddEntry.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnAddEntry.DrawAsToolbar(false);
  m_btnAddEntry.SetThemeHelper(&m_ThemeHelper);
  m_btnAddEntry.EnableBalloonTooltip();
  m_btnAddEntry.SetTooltipText(IDS_ENTRY_ADD);
  m_btnAddEntry.SetIcon(IDI_ICON_ADD_32);

  m_btnChangeEntry.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnChangeEntry.DrawAsToolbar(false);
  m_btnChangeEntry.SetThemeHelper(&m_ThemeHelper);
  m_btnChangeEntry.EnableBalloonTooltip();
  m_btnChangeEntry.SetTooltipText(IDS_ENTRY_CHANGE);
  m_btnChangeEntry.SetIcon(IDI_ICON_EDIT_32);

  m_btnDeleteEntry.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnDeleteEntry.DrawAsToolbar(false);
  m_btnDeleteEntry.SetThemeHelper(&m_ThemeHelper);
  m_btnDeleteEntry.EnableBalloonTooltip();
  m_btnDeleteEntry.SetTooltipText(IDS_ENTRY_DELETE);
  m_btnDeleteEntry.SetIcon(IDI_ICON_DELETE_32);

  m_btnGraphicOutput.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnGraphicOutput.DrawAsToolbar(false);
  m_btnGraphicOutput.SetThemeHelper(&m_ThemeHelper);
  m_btnGraphicOutput.EnableBalloonTooltip();
  m_btnGraphicOutput.SetTooltipText("");
  m_btnGraphicOutput.SetIcon(IDI_ICON_PRESENT_CHART_32);

  m_btnCloseBankbook.OffsetColor(CButtonST::BTNST_COLOR_BK_IN,100);
  m_btnCloseBankbook.DrawAsToolbar(false);
  m_btnCloseBankbook.SetThemeHelper(&m_ThemeHelper);
  m_btnCloseBankbook.EnableBalloonTooltip();
  m_btnCloseBankbook.SetTooltipText(IDS_BANKBOOK_CLOSE);
  m_btnCloseBankbook.SetIcon(IDI_ICON_EXIT_32);

  m_lstTransactions.SetExtendedStyle(LVS_EX_GRIDLINES + LVS_EX_FULLROWSELECT);
  m_lstTransactions.InsertColumn(0,"ID",LVCFMT_LEFT,40);
  m_lstTransactions.InsertColumn(1,"Buchungsdatum",LVCFMT_LEFT,90);
  m_lstTransactions.InsertColumn(2,"Buchungstext",LVCFMT_LEFT,150);
  m_lstTransactions.InsertColumn(3,"Zusatztext",LVCFMT_LEFT,150);
  m_lstTransactions.InsertColumn(4,"Betrag",LVCFMT_LEFT,60);
  m_lstTransactions.InsertColumn(5,"Guthaben",LVCFMT_LEFT,60);
  m_lstTransactions.InsertItem(0,"0");
  m_lstTransactions.SetItemText(0,1,"01.01.06");
  m_lstTransactions.SetItemText(0,2,"Ausgangsbetrag");
  m_lstTransactions.SetItemText(0,3,"Kein Zugang/Abgang!!!");
  m_lstTransactions.SetItemText(0,4,"0");
  m_lstTransactions.SetItemText(0,5,"100,00");
  m_lstTransactions.InsertItem(0,"1");
  m_lstTransactions.SetItemText(0,1,"02.02.06");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,3,"Einzahlung");
  m_lstTransactions.SetItemText(0,4,"+10,00");
  m_lstTransactions.SetItemText(0,5,"110,00");
  m_lstTransactions.InsertItem(0,"2");
  m_lstTransactions.SetItemText(0,1,"03.03.06");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,3,"");
  m_lstTransactions.SetItemText(0,4,"+20,00");
  m_lstTransactions.SetItemText(0,5,"130,00");
  m_lstTransactions.InsertItem(0,"3");
  m_lstTransactions.SetItemText(0,1,"04.04.06");
  m_lstTransactions.SetItemText(0,2,"BARAUS");
  m_lstTransactions.SetItemText(0,3,"Auszahlung");
  m_lstTransactions.SetItemText(0,4,"-30,00");
  m_lstTransactions.SetItemText(0,5,"100,00");
  m_lstTransactions.InsertItem(0,"4");
  m_lstTransactions.SetItemText(0,1,"05.05.06");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,3,"");
  m_lstTransactions.SetItemText(0,4,"+40,00");
  m_lstTransactions.SetItemText(0,5,"140,00");
  m_lstTransactions.InsertItem(0,"5");
  m_lstTransactions.SetItemText(0,1,"06.06.06");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,3,"");
  m_lstTransactions.SetItemText(0,4,"+50,00");
  m_lstTransactions.SetItemText(0,5,"190,00");
  m_lstTransactions.InsertItem(0,"6");
  m_lstTransactions.SetItemText(0,1,"07.07.06");
  m_lstTransactions.SetItemText(0,2,"BARAUS");
  m_lstTransactions.SetItemText(0,3,"");
  m_lstTransactions.SetItemText(0,4,"-60,00");
  m_lstTransactions.SetItemText(0,5,"130,00");
  m_lstTransactions.InsertItem(0,"7");
  m_lstTransactions.SetItemText(0,1,"08.08.06");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,3,"");
  m_lstTransactions.SetItemText(0,4,"+70,00");
  m_lstTransactions.SetItemText(0,5,"200,00");
  m_lstTransactions.InsertItem(0,"8");
  m_lstTransactions.SetItemText(0,1,"09.09.06");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,3,"");
  m_lstTransactions.SetItemText(0,4,"+80,00");
  m_lstTransactions.SetItemText(0,5,"280,00");
  m_lstTransactions.InsertItem(0,"9");
  m_lstTransactions.SetItemText(0,1,"10.10.06");
  m_lstTransactions.SetItemText(0,2,"BARAUS");
  m_lstTransactions.SetItemText(0,3,"");
  m_lstTransactions.SetItemText(0,4,"-90,00");
  m_lstTransactions.SetItemText(0,5,"190,00");
  m_lstTransactions.InsertItem(0,"10");
  m_lstTransactions.SetItemText(0,1,"11.11.06");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,3,"");
  m_lstTransactions.SetItemText(0,4,"+100,00");
  m_lstTransactions.SetItemText(0,5,"290,00");
  m_lstTransactions.InsertItem(0,"11");
  m_lstTransactions.SetItemText(0,1,"12.12.06");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+110,00");
  m_lstTransactions.SetItemText(0,5,"400,00");

  
  m_lstTransactions.InsertItem(0,"12");
  m_lstTransactions.SetItemText(0,1,"01.01.07");
  m_lstTransactions.SetItemText(0,2,"BARAUS");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"-120,00");
  m_lstTransactions.SetItemText(0,5,"280,00");
  m_lstTransactions.InsertItem(0,"13");
  m_lstTransactions.SetItemText(0,1,"02.02.07");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+130,00");
  m_lstTransactions.SetItemText(0,5,"410,00");
  m_lstTransactions.InsertItem(0,"14");
  m_lstTransactions.SetItemText(0,1,"03.03.07");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+140,00");
  m_lstTransactions.SetItemText(0,5,"550,00");
  m_lstTransactions.InsertItem(0,"15");
  m_lstTransactions.SetItemText(0,1,"04.04.07");
  m_lstTransactions.SetItemText(0,2,"BARAUS");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"-150,00");
  m_lstTransactions.SetItemText(0,5,"400,00");
  m_lstTransactions.InsertItem(0,"16");
  m_lstTransactions.SetItemText(0,1,"05.05.07");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+160,00");
  m_lstTransactions.SetItemText(0,5,"560,00");
  m_lstTransactions.InsertItem(0,"17");
  m_lstTransactions.SetItemText(0,1,"06.06.07");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+170,00");
  m_lstTransactions.SetItemText(0,5,"730,00");
  m_lstTransactions.InsertItem(0,"18");
  m_lstTransactions.SetItemText(0,1,"07.07.07");
  m_lstTransactions.SetItemText(0,2,"BARAUS");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"-180,00");
  m_lstTransactions.SetItemText(0,5,"550,00");
  m_lstTransactions.InsertItem(0,"19");
  m_lstTransactions.SetItemText(0,1,"08.08.07");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+190,00");
  m_lstTransactions.SetItemText(0,5,"740,00");
  m_lstTransactions.InsertItem(0,"20");
  m_lstTransactions.SetItemText(0,1,"09.09.07");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+200,00");
  m_lstTransactions.SetItemText(0,5,"940,00");
  m_lstTransactions.InsertItem(0,"21");
  m_lstTransactions.SetItemText(0,1,"10.10.07");
  m_lstTransactions.SetItemText(0,2,"BARAUS");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"-210,00");
  m_lstTransactions.SetItemText(0,5,"730,00");
  m_lstTransactions.InsertItem(0,"22");
  m_lstTransactions.SetItemText(0,1,"11.11.07");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+220,00");
  m_lstTransactions.SetItemText(0,5,"950,00");
  m_lstTransactions.InsertItem(0,"23");
  m_lstTransactions.SetItemText(0,1,"12.12.07");
  m_lstTransactions.SetItemText(0,2,"BAREIN");
  m_lstTransactions.SetItemText(0,12,"");
  m_lstTransactions.SetItemText(0,4,"+230,00");
  m_lstTransactions.SetItemText(0,5,"1180,00");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COpenBankbookDlg::OnButtonEntryAdd() 
{
  CTransactionDlg dlgTransactionDlg;
  dlgTransactionDlg.DoModal();
}

void COpenBankbookDlg::OnButtonEntryChange() 
{
  CTransactionDlg dlgTransactionDlg;
  dlgTransactionDlg.DoModal();
}

void COpenBankbookDlg::OnButtonEntryDelete() 
{
	// TODO: Add your control notification handler code here
	
}

void COpenBankbookDlg::OnButtonGraphicOutput() 
{
  CGraphicOutputDlg dlgGraphicOutputDlg;
  dlgGraphicOutputDlg.DoModal();
}

void COpenBankbookDlg::OnButtonBankbookClose() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void COpenBankbookDlg::OnButtonEntrySortasc() 
{
	// TODO: Add your control notification handler code here
	
}

void COpenBankbookDlg::OnButtonEntrySortdesc() 
{
	// TODO: Add your control notification handler code here
	
}
