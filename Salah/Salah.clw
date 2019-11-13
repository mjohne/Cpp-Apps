; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSalahDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Salah.h"

ClassCount=5
Class1=CSalahApp
Class2=CSalahDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_SALAH_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CWeltkarteDlg
Resource4=IDD_DIALOG_WELTKARTE
Class5=CTabelle
Resource5=IDD_DIALOG_TABELLE_SPEICHERN

[CLS:CSalahApp]
Type=0
HeaderFile=Salah.h
ImplementationFile=Salah.cpp
Filter=N

[CLS:CSalahDlg]
Type=0
HeaderFile=SalahDlg.h
ImplementationFile=SalahDlg.cpp
Filter=D
LastObject=CSalahDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=SalahDlg.h
ImplementationFile=SalahDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SALAH_DIALOG]
Type=1
Class=CSalahDlg
ControlCount=24
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO1,button,1342308361
Control3=IDC_RADIO2,button,1342177289
Control4=IDC_RADIO3,button,1342177289
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO1,combobox,1344340227
Control7=IDC_BUTTON_WELTKARTE,button,1342251008
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT1,edit,1350635648
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT2,edit,1350635648
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308352
Control15=IDC_MONTHCALENDAR1,SysMonthCal32,1342242832
Control16=IDC_STATIC,static,1342308352
Control17=IDC_MONTHCALENDAR2,SysMonthCal32,1342242832
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_BUTTON_GEBETSZEITEN,button,1342251009
Control23=IDC_BUTTON_TABELLE,button,1342251008
Control24=IDC_LIST1,SysListView32,1350631425

[DLG:IDD_DIALOG_WELTKARTE]
Type=1
Class=CWeltkarteDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342177283
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDOK,button,1342242817
Control8=IDCANCEL,button,1342242816

[CLS:CWeltkarteDlg]
Type=0
HeaderFile=WeltkarteDlg.h
ImplementationFile=WeltkarteDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CWeltkarteDlg

[DLG:IDD_DIALOG_TABELLE_SPEICHERN]
Type=1
Class=CTabelleDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_RADIO_FORMAT_TXT,button,1342177289
Control5=IDC_RADIO_FORMAT_HTM,button,1342177289
Control6=IDC_RADIO_FORMAT_RTF,button,1342177289
Control7=IDC_RADIO_FORMAT_CSV,button,1342177289
Control8=IDC_RADIO_FORMAT_XML,button,1342177289

[CLS:CTabelleDlg]
Type=0
HeaderFile=TabelleDlg.h
ImplementationFile=TabelleDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTabelleDlg

