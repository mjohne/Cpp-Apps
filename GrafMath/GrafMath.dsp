# Microsoft Developer Studio Project File - Name="GrafMath" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=GrafMath - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "GrafMath.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GrafMath.mak" CFG="GrafMath - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GrafMath - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GrafMath - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "GrafMath - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "GrafMath - Win32 Release"
# Name "GrafMath - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AxisOptionsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\CreditsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GaussEliminationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GetXofYDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GradientDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GrafMath.cpp
# End Source File
# Begin Source File

SOURCE=.\GrafMath.rc
# End Source File
# Begin Source File

SOURCE=.\GrafMathDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HelpDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\HyperLink.cpp
# End Source File
# Begin Source File

SOURCE=.\InputFunctionDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\IntegralDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LengthTwoPoints.cpp
# End Source File
# Begin Source File

SOURCE=.\MonotonyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TangentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ThemeHelperST.cpp
# End Source File
# Begin Source File

SOURCE=.\ValueTableDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\XPStyleButtonST.cpp
# End Source File
# Begin Source File

SOURCE=.\XPTabCtrl.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AxisOptionsDlg.h
# End Source File
# Begin Source File

SOURCE=.\BCMenu.h
# End Source File
# Begin Source File

SOURCE=.\BtnST.h
# End Source File
# Begin Source File

SOURCE=.\CreditsDlg.h
# End Source File
# Begin Source File

SOURCE=.\GaussEliminationDlg.h
# End Source File
# Begin Source File

SOURCE=.\GetXofYDlg.h
# End Source File
# Begin Source File

SOURCE=.\GradientDlg.h
# End Source File
# Begin Source File

SOURCE=.\GrafMath.h
# End Source File
# Begin Source File

SOURCE=.\GrafMathDlg.h
# End Source File
# Begin Source File

SOURCE=.\HelpDialog.h
# End Source File
# Begin Source File

SOURCE=.\HyperLink.h
# End Source File
# Begin Source File

SOURCE=.\InputFunctionDlg.h
# End Source File
# Begin Source File

SOURCE=.\IntegralDlg.h
# End Source File
# Begin Source File

SOURCE=.\LengthTwoPoints.h
# End Source File
# Begin Source File

SOURCE=.\MonotonyDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TangentDlg.h
# End Source File
# Begin Source File

SOURCE=.\ThemeHelperST.h
# End Source File
# Begin Source File

SOURCE=.\ValueTableDlg.h
# End Source File
# Begin Source File

SOURCE=.\XPStyleButtonST.h
# End Source File
# Begin Source File

SOURCE=.\XPTabCtrl.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ableitung16.ico
# End Source File
# Begin Source File

SOURCE=.\res\ableitung32.ico
# End Source File
# Begin Source File

SOURCE=.\res\GeometrikerBanner.bmp
# End Source File
# Begin Source File

SOURCE=.\res\GrafMath.ico
# End Source File
# Begin Source File

SOURCE=.\res\GrafMath.rc2
# End Source File
# Begin Source File

SOURCE=.\res\graph_zeichnen.bmp
# End Source File
# Begin Source File

SOURCE=.\res\graph_zeichnen.ico
# End Source File
# Begin Source File

SOURCE=.\res\graph_zeichnen16.ico
# End Source File
# Begin Source File

SOURCE=.\res\graph_zeichnen32.ico
# End Source File
# Begin Source File

SOURCE=.\res\HelpDialog.ico
# End Source File
# Begin Source File

SOURCE=.\res\hochpunkt16.ico
# End Source File
# Begin Source File

SOURCE=.\res\hochpunkt32.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon_axi.ico
# End Source File
# Begin Source File

SOURCE=.\res\ok.ico
# End Source File
# Begin Source File

SOURCE=.\res\open.ico
# End Source File
# Begin Source File

SOURCE=.\res\save.ico
# End Source File
# Begin Source File

SOURCE=.\res\schnittpunkt_xachse16.ico
# End Source File
# Begin Source File

SOURCE=.\res\schnittpunkt_xachse32.ico
# End Source File
# Begin Source File

SOURCE=.\res\schnittpunkt_yachse16.ico
# End Source File
# Begin Source File

SOURCE=.\res\schnittpunkt_yachse32.ico
# End Source File
# Begin Source File

SOURCE=.\res\steigung.bmp
# End Source File
# Begin Source File

SOURCE=.\res\steigung.ico
# End Source File
# Begin Source File

SOURCE=.\res\steigung16.ico
# End Source File
# Begin Source File

SOURCE=.\res\steigung32.ico
# End Source File
# Begin Source File

SOURCE=.\res\tangente16.ico
# End Source File
# Begin Source File

SOURCE=.\res\tangente32.ico
# End Source File
# Begin Source File

SOURCE=.\res\tiefpunkt16.ico
# End Source File
# Begin Source File

SOURCE=.\res\tiefpunkt32.ico
# End Source File
# Begin Source File

SOURCE=.\res\toolbar_.bmp
# End Source File
# Begin Source File

SOURCE=.\res\wendepunkt16.ico
# End Source File
# Begin Source File

SOURCE=.\res\wendepunkt32.ico
# End Source File
# Begin Source File

SOURCE=.\res\wertetabelle16.ico
# End Source File
# Begin Source File

SOURCE=.\res\wertetabelle32.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomin_xachse16.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomin_xachse32.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomin_xyachse16.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomin_xyachse32.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomin_yachse16.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomin_yachse32.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomout_xachse16.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomout_xachse32.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomout_xyachse16.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomout_xyachse32.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomout_yachse16.ico
# End Source File
# Begin Source File

SOURCE=.\res\zoomout_yachse32.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\hilfe.rtf
# End Source File
# Begin Source File

SOURCE=.\res\manifest.xml
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
