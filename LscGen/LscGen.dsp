# Microsoft Developer Studio Project File - Name="LscGen" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=LscGen - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LscGen.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LscGen.mak" CFG="LscGen - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LscGen - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "LscGen - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LscGen - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
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

!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"

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

# Name "LscGen - Win32 Release"
# Name "LscGen - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\ExportAsGraphicDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ExportAsModelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HeightmapPreviewDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HyperLink.cpp
# End Source File
# Begin Source File

SOURCE=.\LscEditDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LscGen.cpp
# End Source File
# Begin Source File

SOURCE=.\LscGen.rc
# End Source File
# Begin Source File

SOURCE=.\LscGenDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LscNewDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Mtrx.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\ThemeHelperST.cpp
# End Source File
# Begin Source File

SOURCE=.\XPStyleButtonST.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BCMenu.h
# End Source File
# Begin Source File

SOURCE=.\BtnST.h
# End Source File
# Begin Source File

SOURCE=.\ExportAsGraphicDlg.h
# End Source File
# Begin Source File

SOURCE=.\ExportAsModelDlg.h
# End Source File
# Begin Source File

SOURCE=.\HeightmapPreviewDlg.h
# End Source File
# Begin Source File

SOURCE=.\HyperLink.h
# End Source File
# Begin Source File

SOURCE=.\LscEditDlg.h
# End Source File
# Begin Source File

SOURCE=.\LscGen.h
# End Source File
# Begin Source File

SOURCE=.\LscGenDlg.h
# End Source File
# Begin Source File

SOURCE=.\LscNewDlg.h
# End Source File
# Begin Source File

SOURCE=.\Mtrx.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\ThemeHelperST.h
# End Source File
# Begin Source File

SOURCE=.\XPStyleButtonST.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\about.ico
# End Source File
# Begin Source File

SOURCE=.\res\arrow_down_blue.ico
# End Source File
# Begin Source File

SOURCE=.\res\arrow_left_blue.ico
# End Source File
# Begin Source File

SOURCE=.\res\arrow_right_blue.ico
# End Source File
# Begin Source File

SOURCE=.\res\arrow_up_blue.ico
# End Source File
# Begin Source File

SOURCE=.\res\banner_current.bmp
# End Source File
# Begin Source File

SOURCE=.\res\book_blue.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_open.ico
# End Source File
# Begin Source File

SOURCE=.\res\check.ico
# End Source File
# Begin Source File

SOURCE=.\res\check2.ico
# End Source File
# Begin Source File

SOURCE=.\res\clipboard.ico
# End Source File
# Begin Source File

SOURCE=.\res\clipboard_empty.ico
# End Source File
# Begin Source File

SOURCE=.\res\colors.ico
# End Source File
# Begin Source File

SOURCE=.\res\copy.ico
# End Source File
# Begin Source File

SOURCE=.\res\cut.ico
# End Source File
# Begin Source File

SOURCE=.\res\data_into.ico
# End Source File
# Begin Source File

SOURCE=.\res\delete.ico
# End Source File
# Begin Source File

SOURCE=.\res\delete2.ico
# End Source File
# Begin Source File

SOURCE=.\res\document_check.ico
# End Source File
# Begin Source File

SOURCE=.\res\document_info.ico
# End Source File
# Begin Source File

SOURCE=.\res\document_preferences.ico
# End Source File
# Begin Source File

SOURCE=.\res\document_view.ico
# End Source File
# Begin Source File

SOURCE=.\res\download.ico
# End Source File
# Begin Source File

SOURCE=.\res\edit.ico
# End Source File
# Begin Source File

SOURCE=.\res\edit2.ico
# End Source File
# Begin Source File

SOURCE=.\res\environment.ico
# End Source File
# Begin Source File

SOURCE=.\res\error.ico
# End Source File
# Begin Source File

SOURCE=.\res\exchange.ico
# End Source File
# Begin Source File

SOURCE=.\res\exit.ico
# End Source File
# Begin Source File

SOURCE=.\res\faq.ico
# End Source File
# Begin Source File

SOURCE=.\res\fit_to_size.ico
# End Source File
# Begin Source File

SOURCE=.\res\folder_closed.ico
# End Source File
# Begin Source File

SOURCE=.\res\forbidden.ico
# End Source File
# Begin Source File

SOURCE=.\res\gear.ico
# End Source File
# Begin Source File

SOURCE=.\res\glaciate.ico
# End Source File
# Begin Source File

SOURCE=.\res\heightfield.ico
# End Source File
# Begin Source File

SOURCE=.\res\help2.ico
# End Source File
# Begin Source File

SOURCE=.\res\help_online.ico
# End Source File
# Begin Source File

SOURCE=.\res\id_card.ico
# End Source File
# Begin Source File

SOURCE=.\res\information.ico
# End Source File
# Begin Source File

SOURCE=.\res\invert.ico
# End Source File
# Begin Source File

SOURCE=.\res\lightbulb.ico
# End Source File
# Begin Source File

SOURCE=.\res\lightbulb_on.ico
# End Source File
# Begin Source File

SOURCE=.\res\logic_and.ico
# End Source File
# Begin Source File

SOURCE=.\res\logic_not.ico
# End Source File
# Begin Source File

SOURCE=.\res\logic_or.ico
# End Source File
# Begin Source File

SOURCE=.\res\LscGen.ico
# End Source File
# Begin Source File

SOURCE=.\res\LscGen.rc2
# End Source File
# Begin Source File

SOURCE=.\res\mail.ico
# End Source File
# Begin Source File

SOURCE=.\res\mfc.ico
# End Source File
# Begin Source File

SOURCE=.\res\mfc7.ico
# End Source File
# Begin Source File

SOURCE=.\res\mirror_hori.ico
# End Source File
# Begin Source File

SOURCE=.\res\mirror_vert.ico
# End Source File
# Begin Source File

SOURCE=.\res\model.ico
# End Source File
# Begin Source File

SOURCE=.\res\msvc6.ico
# End Source File
# Begin Source File

SOURCE=.\res\msvc7.ico
# End Source File
# Begin Source File

SOURCE=.\res\nav_down_green.ico
# End Source File
# Begin Source File

SOURCE=.\res\nav_left_green.ico
# End Source File
# Begin Source File

SOURCE=.\res\nav_plain_green.ico
# End Source File
# Begin Source File

SOURCE=.\res\nav_right_green.ico
# End Source File
# Begin Source File

SOURCE=.\res\nav_up_green.ico
# End Source File
# Begin Source File

SOURCE=.\res\navi.ico
# End Source File
# Begin Source File

SOURCE=.\res\navigate_cross.ico
# End Source File
# Begin Source File

SOURCE=.\res\navigate_down.ico
# End Source File
# Begin Source File

SOURCE=.\res\navigate_left.ico
# End Source File
# Begin Source File

SOURCE=.\res\navigate_minus.ico
# End Source File
# Begin Source File

SOURCE=.\res\navigate_plus.ico
# End Source File
# Begin Source File

SOURCE=.\res\navigate_right.ico
# End Source File
# Begin Source File

SOURCE=.\res\navigate_up.ico
# End Source File
# Begin Source File

SOURCE=.\res\new.ico
# End Source File
# Begin Source File

SOURCE=.\res\notebook.ico
# End Source File
# Begin Source File

SOURCE=.\res\notebook_preferences.ico
# End Source File
# Begin Source File

SOURCE=.\res\open.ico
# End Source File
# Begin Source File

SOURCE=.\res\paste.ico
# End Source File
# Begin Source File

SOURCE=.\res\photo_portrait.ico
# End Source File
# Begin Source File

SOURCE=.\res\photo_scenery.ico
# End Source File
# Begin Source File

SOURCE=.\res\recycle.ico
# End Source File
# Begin Source File

SOURCE=.\res\redo.ico
# End Source File
# Begin Source File

SOURCE=.\res\refresh.ico
# End Source File
# Begin Source File

SOURCE=.\res\save.ico
# End Source File
# Begin Source File

SOURCE=.\res\script.ico
# End Source File
# Begin Source File

SOURCE=.\res\stop.ico
# End Source File
# Begin Source File

SOURCE=.\res\transform.ico
# End Source File
# Begin Source File

SOURCE=.\res\transform2.ico
# End Source File
# Begin Source File

SOURCE=.\res\undo.ico
# End Source File
# Begin Source File

SOURCE=.\res\unknown.ico
# End Source File
# Begin Source File

SOURCE=.\res\vrml.ico
# End Source File
# Begin Source File

SOURCE=.\res\warning.ico
# End Source File
# Begin Source File

SOURCE=.\res\window_earth.ico
# End Source File
# Begin Source File

SOURCE=.\res\window_edit.ico
# End Source File
# Begin Source File

SOURCE=.\res\window_environment.ico
# End Source File
# Begin Source File

SOURCE=.\res\window_gear.ico
# End Source File
# Begin Source File

SOURCE=.\res\window_information.ico
# End Source File
# Begin Source File

SOURCE=.\res\window_new.ico
# End Source File
# Begin Source File

SOURCE=.\res\x3d.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\manifest.xml
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
