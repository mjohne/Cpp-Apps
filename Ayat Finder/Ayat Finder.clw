; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Ayat Finder.h"
ODLFile=Ayat Finder.odl

ClassCount=6
Class1=CAyatFinderApp
Class2=CAyatFinderDlg
Class3=CAboutDlg
Class4=CAyatFinderDlgAutoProxy

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_AYATFINDER_DIALOG
Class5=COptionsDlg
Resource4=IDD_DIALOG_OPTIONS
Class6=CSaveResultDlg
Resource5=IDD_DIALOG_SAVERESULT

[CLS:CAyatFinderApp]
Type=0
HeaderFile=Ayat Finder.h
ImplementationFile=Ayat Finder.cpp
Filter=N

[CLS:CAyatFinderDlg]
Type=0
HeaderFile=Ayat FinderDlg.h
ImplementationFile=Ayat FinderDlg.cpp
Filter=D
LastObject=CAyatFinderDlg
BaseClass=CResizableDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Ayat FinderDlg.h
ImplementationFile=Ayat FinderDlg.cpp
Filter=D
BaseClass=CResizableDialog
VirtualFilter=dWC
LastObject=IDC_STATIC_MYMAIL

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=9
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342177294
Control6=IDC_STATIC_TAWHEDLINK,static,1342308352
Control7=IDC_STATIC,static,1342177296
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC_MYMAIL,static,1342308352

[CLS:CAyatFinderDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_AYATFINDER_DIALOG]
Type=1
Class=CAyatFinderDlg
ControlCount=19
Control1=IDC_STATIC_WORD,static,1342308352
Control2=IDC_EDIT_KEYWORD,edit,1350631552
Control3=IDC_BUTTON_FIND,button,1342259201
Control4=IDC_BUTTON_OPTION,button,1342259200
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC_QURAN,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PROGRESS,msctls_progress32,1350565889
Control9=IDC_STATIC_PERCENT,static,1342308352
Control10=IDC_STATIC_AYATFOUND,static,1342308352
Control11=IDC_ANIICON,static,1342180099
Control12=IDC_BUTTON_SAVE,button,1342259200
Control13=IDC_BUTTON_INFO,button,1342242816
Control14=IDC_BUTTON_SEARCHABORT,button,1342242816
Control15=IDCANCEL,button,1342242816
Control16=IDC_RICHEDIT_RESULT,RICHEDIT,1352667460
Control17=IDC_STATIC_SEARCH,button,1342177287
Control18=IDC_STATIC_PROCESS,button,1342177287
Control19=IDC_STATIC_RESULT,button,1342177287

[DLG:IDD_DIALOG_OPTIONS]
Type=1
Class=COptionsDlg
ControlCount=12
Control1=IDC_STATIC,button,1342193671
Control2=IDC_LIST_QURAN,SysListView32,1350631821
Control3=IDC_STATIC,button,1342193671
Control4=IDC_EDIT_INFO,edit,1352734788
Control5=IDC_STATIC,button,1342193671
Control6=IDC_LIST_SURA,SysListView32,1350631823
Control7=IDC_STATIC,button,1342193671
Control8=IDC_CHECK_CASESENS,button,1342242819
Control9=IDC_CHECK_WORDSONLY,button,1476476931
Control10=IDOK,button,1342242817
Control11=IDCANCEL,button,1342242816
Control12=IDC_CHECK_SURA,button,1342246915

[CLS:COptionsDlg]
Type=0
HeaderFile=OptionsDlg.h
ImplementationFile=OptionsDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST_SURA

[DLG:IDD_DIALOG_SAVERESULT]
Type=1
Class=CSaveResultDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_FORMAT_TXT,button,1342308361
Control4=IDC_RADIO_FORMAT_HTML,button,1342177289
Control5=IDC_RADIO_FORMAT_RTF,button,1342177289
Control6=IDC_RADIO_FORMAT_DOC,button,1342177289
Control7=IDC_RADIO_FORMAT_ODT,button,1342177289
Control8=IDC_STATIC,button,1342177287

[CLS:CSaveResultDlg]
Type=0
HeaderFile=SaveResultDlg.h
ImplementationFile=SaveResultDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO_FORMAT_TXT

