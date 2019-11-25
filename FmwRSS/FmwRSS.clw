; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFmwRSSDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FmwRSS.h"
ODLFile=FmwRSS.odl

ClassCount=6
Class1=CFmwRSSApp
Class2=CFmwRSSDlg
Class3=CAboutDlg
Class4=CFmwRSSDlgAutoProxy

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FMWRSS_DIALOG
Resource4=IDD_DIALOG_GROUP
Resource5=IDD_ABOUTBOX (English (U.S.))
Resource6=IDD_FMWRSS_DIALOG (English (U.S.))
Resource7=IDD_DIALOG_FEED
Class5=CFeedDlg
Class6=CGroupDlg
Resource8=IDR_MENU

[CLS:CFmwRSSApp]
Type=0
HeaderFile=FmwRSS.h
ImplementationFile=FmwRSS.cpp
Filter=N

[CLS:CFmwRSSDlg]
Type=0
HeaderFile=FmwRSSDlg.h
ImplementationFile=FmwRSSDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT_VIEW

[CLS:CAboutDlg]
Type=0
HeaderFile=FmwRSSDlg.h
ImplementationFile=FmwRSSDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[CLS:CFmwRSSDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_FMWRSS_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CFmwRSSDlg

[DLG:IDD_FMWRSS_DIALOG (English (U.S.))]
Type=1
Class=CFmwRSSDlg
ControlCount=27
Control1=IDC_BUTTON_GROUP_NEW,button,1342242816
Control2=IDC_BUTTON_GROUP_EDIT,button,1342242816
Control3=IDC_BUTTON_GROUP_DELETE,button,1342242816
Control4=IDC_STATIC,static,1342177297
Control5=IDC_BUTTON_FEED_NEW,button,1342242816
Control6=IDC_BUTTON_FEED_EDIT,button,1342242816
Control7=IDC_BUTTON_FEED_DELETE,button,1342242816
Control8=IDC_STATIC,static,1342177297
Control9=IDC_BUTTON_OPML_IMPORT,button,1342242816
Control10=IDC_BUTTON_OPML_EXPORT,button,1342242816
Control11=IDC_STATIC,static,1342177297
Control12=IDC_BUTTON_UPDATE_NOW,button,1342242816
Control13=IDC_BUTTON_OPTIONS,button,1342242816
Control14=IDC_STATIC,static,1342177297
Control15=IDC_BUTTON_VIEW0,button,1342242816
Control16=IDC_BUTTON_VIEW23,button,1342242816
Control17=IDC_BUTTON_VIEW13,button,1342242816
Control18=IDC_BUTTON_VIEW12,button,1342242816
Control19=IDC_STATIC,static,1342177297
Control20=ID_APP_ABOUT,button,1342242816
Control21=IDCANCEL,button,1342242816
Control22=IDC_STATIC_FEED,button,1342177287
Control23=IDC_TREE_FEEDS,SysTreeView32,1350655527
Control24=IDC_STATIC_NEWS,button,1342177287
Control25=IDC_LIST_NEWS,SysListView32,1350631437
Control26=IDC_STATIC_VIEW,button,1342177287
Control27=IDC_EDIT_VIEW,edit,1353781444

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MENU]
Type=1
Class=?
Command1=ID_FILE_GROUP_NEW
Command2=ID_FILE_GROUP_EDIT
Command3=ID_FILE_GROUP_DELETE
Command4=ID_FILE_FEED_NEW
Command5=ID_FILE_FEED_EDIT
Command6=ID_FILE_FEED_DELETE
Command7=ID_FILE_OPML_IMPORT
Command8=ID_FILE_OPML_EXPORT
Command9=ID_FILE_EXIT
Command10=ID_MISC_UPDATEFEEDSNOW
Command11=ID_MISC_FEEDCOOKER
Command12=ID_MISC_OPTIONS
Command13=ID_WINDOW_ALL
Command14=ID_WINDOW_NOFEEDS
Command15=ID_WINDOW_NONEWS
Command16=ID_WINDOW_NOVIEW
CommandCount=16

[DLG:IDD_DIALOG_GROUP]
Type=1
Class=CGroupDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_GROUPNAME,edit,1350635648
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG_FEED]
Type=1
Class=CFeedDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_FEEDURL,edit,1350635648
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816

[CLS:CFeedDlg]
Type=0
HeaderFile=FeedDlg.h
ImplementationFile=FeedDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFeedDlg

[CLS:CGroupDlg]
Type=0
HeaderFile=GroupDlg.h
ImplementationFile=GroupDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CGroupDlg

