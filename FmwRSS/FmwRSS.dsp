# Microsoft Developer Studio Project File - Name="FmwRSS" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=FmwRSS - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FmwRSS.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FmwRSS.mak" CFG="FmwRSS - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FmwRSS - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FmwRSS - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FmwRSS - Win32 Release"

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
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
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

!ELSEIF  "$(CFG)" == "FmwRSS - Win32 Debug"

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

# Name "FmwRSS - Win32 Release"
# Name "FmwRSS - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\FeedDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FmwRSS.cpp
# End Source File
# Begin Source File

SOURCE=.\FmwRSS.odl
# End Source File
# Begin Source File

SOURCE=.\FmwRSS.rc
# End Source File
# Begin Source File

SOURCE=.\FmwRSSDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GroupDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HyperLink.cpp
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
# Begin Source File

SOURCE=.\XPTabCtrl.cpp
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

SOURCE=.\DlgProxy.h
# End Source File
# Begin Source File

SOURCE=.\FeedDlg.h
# End Source File
# Begin Source File

SOURCE=.\FmwRSS.h
# End Source File
# Begin Source File

SOURCE=.\FmwRSSDlg.h
# End Source File
# Begin Source File

SOURCE=.\GroupDlg.h
# End Source File
# Begin Source File

SOURCE=.\HyperLink.h
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
# Begin Source File

SOURCE=.\XPTabCtrl.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\cancel.ico
# End Source File
# Begin Source File

SOURCE=.\res\check.ico
# End Source File
# Begin Source File

SOURCE=.\res\check_all_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\comment_rss_add_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\comment_rss_delete_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\comment_rss_info_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\error.ico
# End Source File
# Begin Source File

SOURCE=.\res\exit.ico
# End Source File
# Begin Source File

SOURCE=.\res\FmwRSS.ico
# End Source File
# Begin Source File

SOURCE=.\res\FmwRSS.rc2
# End Source File
# Begin Source File

SOURCE=.\res\FmwRSS_16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FmwRSS_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\folder.bmp
# End Source File
# Begin Source File

SOURCE=.\res\folder.ico
# End Source File
# Begin Source File

SOURCE=.\res\folder_download.ico
# End Source File
# Begin Source File

SOURCE=.\res\folder_locked.ico
# End Source File
# Begin Source File

SOURCE=.\res\folder_new.ico
# End Source File
# Begin Source File

SOURCE=.\res\folder_open.bmp
# End Source File
# Begin Source File

SOURCE=.\res\folder_open.ico
# End Source File
# Begin Source File

SOURCE=.\res\folder_txt.ico
# End Source File
# Begin Source File

SOURCE=.\res\history.ico
# End Source File
# Begin Source File

SOURCE=.\res\home.ico
# End Source File
# Begin Source File

SOURCE=.\res\inbox.ico
# End Source File
# Begin Source File

SOURCE=.\res\info.ico
# End Source File
# Begin Source File

SOURCE=.\res\mark_as_read_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\network.ico
# End Source File
# Begin Source File

SOURCE=.\res\next_rss_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\next_unread_16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\next_unread_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\options.ico
# End Source File
# Begin Source File

SOURCE=.\res\outbox.ico
# End Source File
# Begin Source File

SOURCE=.\res\previous_rss_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\previous_unread_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\refresh.ico
# End Source File
# Begin Source File

SOURCE=.\res\RSS_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\RSS_file_16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RSS_file_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\rss_file_add_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\rss_file_info_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\rss_file_remove_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\star.ico
# End Source File
# Begin Source File

SOURCE=.\res\stop.ico
# End Source File
# Begin Source File

SOURCE=.\res\subscribe_16.ico
# End Source File
# Begin Source File

SOURCE=.\res\unsubscribe_16.ico
# End Source File
# Begin Source File

SOURCE=".\res\view-0.ico"
# End Source File
# Begin Source File

SOURCE=".\res\view-1.ico"
# End Source File
# Begin Source File

SOURCE=".\res\view-12.ico"
# End Source File
# Begin Source File

SOURCE=".\res\view-13.ico"
# End Source File
# Begin Source File

SOURCE=".\res\view-2.ico"
# End Source File
# Begin Source File

SOURCE=".\res\view-23.ico"
# End Source File
# Begin Source File

SOURCE=".\res\view-3.ico"
# End Source File
# Begin Source File

SOURCE=.\res\warning.ico
# End Source File
# Begin Source File

SOURCE=.\res\web16.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\FmwRSS.reg
# End Source File
# Begin Source File

SOURCE=.\res\manifest.xml
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
