; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHeightmapPreviewDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lscgen.h"
LastPage=0

ClassCount=10
Class1=CButtonST
Class2=CExportAsGraphicDlg
Class3=CExportAsModelDlg
Class4=CHyperLink
Class5=CLscGenApp
Class6=CAboutDlg
Class7=CLscGenDlg
Class8=CLscNewDlg

ResourceCount=7
Resource1=IDD_LSCGEN_DIALOG
Resource2=IDD_DIALOG_LSC_EDIT
Resource3=IDD_DIALOG_EXPORTAS_GRAPHIC (Neutral (Default))
Resource4=IDD_DIALOG_LSC_NEW
Resource5=IDD_DIALOG_EXPORTAS_MODEL
Class9=CLscEditDlg
Resource6=IDD_ABOUTBOX
Class10=CHeightmapPreviewDlg
Resource7=IDD_DIALOG_HM_PREVIEW

[CLS:CButtonST]
Type=0
BaseClass=CButton
HeaderFile=BtnST.h
ImplementationFile=BtnST.cpp
LastObject=CButtonST

[CLS:CExportAsGraphicDlg]
Type=0
BaseClass=CDialog
HeaderFile=ExportAsGraphicDlg.h
ImplementationFile=ExportAsGraphicDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CExportAsGraphicDlg

[CLS:CExportAsModelDlg]
Type=0
BaseClass=CDialog
HeaderFile=ExportAsModelDlg.h
ImplementationFile=ExportAsModelDlg.cpp
LastObject=CExportAsModelDlg

[CLS:CHyperLink]
Type=0
BaseClass=CStatic
HeaderFile=HyperLink.h
ImplementationFile=HyperLink.cpp
LastObject=CHyperLink

[CLS:CLscGenApp]
Type=0
BaseClass=CWinApp
HeaderFile=LscGen.h
ImplementationFile=LscGen.cpp
LastObject=CLscGenApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=LscGenDlg.cpp
ImplementationFile=LscGenDlg.cpp
LastObject=CAboutDlg

[CLS:CLscGenDlg]
Type=0
BaseClass=CDialog
HeaderFile=LscGenDlg.h
ImplementationFile=LscGenDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CLscGenDlg

[CLS:CLscNewDlg]
Type=0
BaseClass=CDialog
HeaderFile=LscNewDlg.h
ImplementationFile=LscNewDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CLscNewDlg

[DLG:IDD_DIALOG_EXPORTAS_GRAPHIC]
Type=1
Class=CExportAsGraphicDlg

[DLG:IDD_DIALOG_EXPORTAS_MODEL]
Type=1
Class=CExportAsModelDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_BUTTON_EXPORTAS_VRML,button,1342242816
Control3=IDC_BUTTON_EXPORTAS_X3D,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342308481
Control2=IDC_STATIC,static,1342308353
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342177294

[DLG:IDD_LSCGEN_DIALOG]
Type=1
Class=CLscGenDlg
ControlCount=21
Control1=IDC_BUTTON_LSC_NEW,button,1342242816
Control2=IDC_BUTTON_LSC_LOAD,button,1342242816
Control3=IDC_BUTTON_LSC_SAVE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTTON_LSC_EDIT,button,1342242816
Control8=IDC_BUTTON_EXPORTAS_MODEL,button,1342242816
Control9=IDC_BUTTON_EXPORTAS_GRAPHIC,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342181383
Control14=IDC_BUTTON_APP_ABOUT,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_BUTTON_APP_EXIT,button,1342242816
Control17=IDC_STATIC,static,1342308352
Control18=IDC_BUTTON_EXPORTAS_SQL,button,1342242816
Control19=IDC_STATIC,static,1342308352
Control20=IDC_BUTTON_LSC_CLOSE,button,1342242816
Control21=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_LSC_NEW]
Type=1
Class=CLscNewDlg
ControlCount=29
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_LSC_NAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_LSC_COMMENTS,edit,1350631552
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO_ALGORITHM,combobox,1344340035
Control8=IDC_RADIO_METHOD1,button,1342308361
Control9=IDC_EDIT_METHOD1,edit,1350639744
Control10=IDC_RADIO_METHOD2,button,1342177289
Control11=IDC_EDIT_METHOD2,edit,1350639744
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_SIZEX,edit,1350639744
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_SIZEY,edit,1350639744
Control17=IDC_STATIC,button,1342177287
Control18=IDC_RADIO_START_XY,button,1342308361
Control19=IDC_RADIO_START_RANDOM,button,1342177289
Control20=IDC_RADIO_START_MIDPOINT,button,1342177289
Control21=IDC_EDIT_START_X,edit,1350639744
Control22=IDC_STATIC,static,1342308352
Control23=IDC_EDIT_START_Y,edit,1350639744
Control24=IDC_STATIC,static,1342308352
Control25=IDC_PROGRESS_GENERATE,msctls_progress32,1350565889
Control26=IDC_BUTTON_GENERATE,button,1342242817
Control27=IDOK,button,1342242816
Control28=IDCANCEL,button,1342242816
Control29=IDC_BUTTON_HM_PREVIEW,button,1342242816

[DLG:IDD_DIALOG_EXPORTAS_GRAPHIC (Neutral (Default))]
Type=1
Class=CExportAsGraphicDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDC_BUTTON_EXPORTAS_PGM,button,1342242816
Control3=IDC_BUTTON_EXPORTAS_RAW,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BUTTON_EXPORTAS_XPM,button,1342242816
Control8=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_LSC_EDIT]
Type=1
Class=CLscEditDlg
ControlCount=27
Control1=IDC_STATIC,static,1342177284
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_LSC_NAME2,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_LSC_COMMENTS2,edit,1350631552
Control6=IDC_STATIC,button,1342177287
Control7=IDC_BUTTON_RAISE,button,1342242816
Control8=IDC_BUTTON_FLAT,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_BUTTON_ROTATE_LEFT,button,1342242816
Control11=IDC_BUTTON_ROTATE_RIGHT,button,1342242816
Control12=IDC_STATIC,button,1342177287
Control13=IDC_BUTTON_HORIZONTAL,button,1342242816
Control14=IDC_BUTTON_VERTICAL,button,1342242816
Control15=IDC_STATIC,button,1342177287
Control16=IDC_RADIO_CANYONIZE1,button,1342308361
Control17=IDC_RADIO_CANYONIZE2,button,1342177289
Control18=IDC_BUTTON_CANYONIZE,button,1342242816
Control19=IDC_BUTTON_INVERT,button,1342242816
Control20=IDC_BUTTON_GLACIATE,button,1342242816
Control21=IDC_STATIC,button,1342177287
Control22=IDC_BUTTON_UP2,button,1342242816
Control23=IDC_BUTTON_LEFT2,button,1342242816
Control24=IDC_BUTTON_DOWN2,button,1342242816
Control25=IDC_BUTTON_RIGHT2,button,1342242816
Control26=IDOK,button,1342242817
Control27=IDCANCEL,button,1342242816

[CLS:CLscEditDlg]
Type=0
HeaderFile=LscEditDlg.h
ImplementationFile=LscEditDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLscEditDlg

[DLG:IDD_DIALOG_HM_PREVIEW]
Type=1
Class=CHeightmapPreviewDlg
ControlCount=0

[CLS:CHeightmapPreviewDlg]
Type=0
HeaderFile=HeightmapPreviewDlg.h
ImplementationFile=HeightmapPreviewDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CHeightmapPreviewDlg
VirtualFilter=dWC

