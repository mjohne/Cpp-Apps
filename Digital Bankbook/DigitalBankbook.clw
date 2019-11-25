; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDigitalBankbookDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DigitalBankbook.h"

ClassCount=9
Class1=CDigitalBankbookApp
Class2=CDigitalBankbookDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_DIALOG_OPENBANKBOOK
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_GRAPHIC_OUTPUT
Resource4=IDD_DIALOG_ENTRY
Resource5=IDD_DIALOG_BANKBOOK_NEW
Class4=CNewUserDlg
Class5=CNewBankbookDlg
Class6=COpenBankbookDlg
Resource6=IDD_ABOUTBOX
Class7=CGraphicOutputDlg
Resource7=IDD_DIGITALBANKBOOK_DIALOG
Class8=CTransactionDlg
Resource8=IDD_DIALOG_USER_NEW
Class9=CAppOptionsDlg
Resource9=IDD_DIALOG_APPOPTIONS

[CLS:CDigitalBankbookApp]
Type=0
HeaderFile=DigitalBankbook.h
ImplementationFile=DigitalBankbook.cpp
Filter=N

[CLS:CDigitalBankbookDlg]
Type=0
HeaderFile=DigitalBankbookDlg.h
ImplementationFile=DigitalBankbookDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDCANCEL

[CLS:CAboutDlg]
Type=0
HeaderFile=DigitalBankbookDlg.h
ImplementationFile=DigitalBankbookDlg.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC_VERSION,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIGITALBANKBOOK_DIALOG]
Type=1
Class=CDigitalBankbookDlg
ControlCount=6
Control1=IDC_BUTTON_BANKBOOK_NEW,button,1342243584
Control2=IDC_BUTTON_BANKBOOK_OPEN,button,1342243584
Control3=IDC_STATIC,static,1342177296
Control4=IDC_BUTTON_BANKBOOK_ABOUT,button,1342251776
Control5=IDC_BUTTON_APP_OPTIONS,button,1342243584
Control6=IDCANCEL,button,1342243584

[DLG:IDD_DIALOG_BANKBOOK_NEW]
Type=1
Class=CNewBankbookDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_BANKBOOK_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_BANKBOOK_DESCRIPTION,edit,1353781444
Control6=IDC_BUTTON_USER,button,1342251008
Control7=IDC_BUTTON_BANKBOOK_CREATE,button,1342242817
Control8=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG_USER_NEW]
Type=1
Class=CNewUserDlg
ControlCount=12
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_USER_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_USER_BIRTHDATE,SysDateTimePick32,1342242864
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_USER_STREET,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_USER_PLACE,edit,1350631552
Control10=IDOK,button,1342242817
Control11=IDCANCEL,button,1342242816
Control12=IDC_BUTTON_VCARDEXPORT,button,1342251008

[CLS:CNewUserDlg]
Type=0
HeaderFile=NewUserDlg.h
ImplementationFile=NewUserDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON_VCARDEXPORT

[CLS:CNewBankbookDlg]
Type=0
HeaderFile=NewBankbookDlg.h
ImplementationFile=NewBankbookDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDCANCEL

[CLS:COpenBankbookDlg]
Type=0
HeaderFile=OpenBankbookDlg.h
ImplementationFile=OpenBankbookDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=COpenBankbookDlg

[DLG:IDD_DIALOG_GRAPHIC_OUTPUT]
Type=1
Class=CGraphicOutputDlg
ControlCount=12
Control1=IDC_STATIC,static,1350565894
Control2=IDC_BUTTON_TIMESCALE_BEGIN,button,1342242816
Control3=IDC_BUTTON_TIMESCALE_BACKWARD,button,1342242816
Control4=IDC_BUTTON_TIMESCALE_FORWARD,button,1342242816
Control5=IDC_BUTTON_TIMESCALE_END,button,1342242816
Control6=IDC_BUTTON_APP_OPTIONS,button,1342242816
Control7=IDC_BUTTON_GRAPHICPRINT,button,1342242816
Control8=IDC_BUTTON_GRAPHICSAVE,button,1342251008
Control9=IDC_BUTTON_COURSE,button,1342251008
Control10=IDC_BUTTON_DCDIFF,button,1342251008
Control11=IDC_BUTTON_DCRATIO,button,1342251008
Control12=IDCANCEL,button,1342251009

[DLG:IDD_DIALOG_OPENBANKBOOK]
Type=1
Class=COpenBankbookDlg
ControlCount=10
Control1=IDC_LIST_TRANSACTIONS,SysListView32,1350631693
Control2=IDC_BUTTON_ENTRY_UP,button,1342275584
Control3=IDC_BUTTON_ENTRY_DOWN,button,1342275584
Control4=IDC_BUTTON_ENTRY_SORTASC,button,1342275584
Control5=IDC_BUTTON_ENTRY_SORTDESC,button,1342275584
Control6=IDC_BUTTON_ENTRY_ADD,button,1342251008
Control7=IDC_BUTTON_ENTRY_CHANGE,button,1342251008
Control8=IDC_BUTTON_ENTRY_DELETE,button,1342251008
Control9=IDC_BUTTON_GRAPHIC_OUTPUT,button,1342251008
Control10=IDC_BUTTON_BANKBOOK_CLOSE,button,1342251009

[CLS:CGraphicOutputDlg]
Type=0
HeaderFile=GraphicOutputDlg.h
ImplementationFile=GraphicOutputDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON_GRAPHICPRINT

[DLG:IDD_DIALOG_ENTRY]
Type=1
Class=CTransactionDlg
ControlCount=16
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_TRANSACTION_ID,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_TRANSACTION_DATE,SysDateTimePick32,1342242864
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_TRANSACTION_TEXT,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_TRANSACTION_TEXT_MORE,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_TRANSACTION_PAYMENT,edit,1350639744
Control12=IDC_STATIC,static,1342308352
Control13=IDC_RADIO_TURNOVER_HAVE,button,1342308361
Control14=IDC_RADIO_TURNOVER_MUST,button,1342177289
Control15=IDOK,button,1342242817
Control16=IDCANCEL,button,1342242816

[CLS:CTransactionDlg]
Type=0
HeaderFile=TransactionDlg.h
ImplementationFile=TransactionDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTransactionDlg

[DLG:IDD_DIALOG_APPOPTIONS]
Type=1
Class=CAppOptionsDlg
ControlCount=14
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_RADIO_SAVE_INI,button,1342308361
Control4=IDC_RADIO_SAVE_REG,button,1342177289
Control5=IDC_STATIC,button,1342177287
Control6=IDC_CHECK_OP_MAINAXIS,button,1342242819
Control7=IDC_CHECK_OP_HELPAXIS,button,1342242819
Control8=IDC_CHECK_OP_SCALE100,button,1342242819
Control9=IDC_CHECK_OP_BGAREA,button,1342242819
Control10=IDC_CHECK_OP_LEGEND,button,1342242819
Control11=IDC_CHECK_OP_TITLE,button,1342242819
Control12=IDC_CHECK_OP_AXISDESCRIPT,button,1342242819
Control13=IDOK,button,1342242817
Control14=IDCANCEL,button,1342242816

[CLS:CAppOptionsDlg]
Type=0
HeaderFile=AppOptionsDlg.h
ImplementationFile=AppOptionsDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAppOptionsDlg

