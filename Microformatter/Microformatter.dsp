# Microsoft Developer Studio Project File - Name="Microformatter" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Microformatter - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Microformatter.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Microformatter.mak" CFG="Microformatter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Microformatter - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Microformatter - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Microformatter - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Microformatter - Win32 Debug"

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

# Name "Microformatter - Win32 Release"
# Name "Microformatter - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddressDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddressWhatDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CodeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GeolocationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\hAtomDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\hCalenderDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\hCardDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\hResumeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\hReviewDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Microformatter.cpp
# End Source File
# Begin Source File

SOURCE=.\Microformatter.rc
# End Source File
# Begin Source File

SOURCE=.\MicroformatterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\relTagDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\XFNDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\xFolkDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddressDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddressWhatDlg.h
# End Source File
# Begin Source File

SOURCE=.\CodeDlg.h
# End Source File
# Begin Source File

SOURCE=.\GeolocationDlg.h
# End Source File
# Begin Source File

SOURCE=.\hAtomDlg.h
# End Source File
# Begin Source File

SOURCE=.\hCalenderDlg.h
# End Source File
# Begin Source File

SOURCE=.\hCardDlg.h
# End Source File
# Begin Source File

SOURCE=.\hResumeDlg.h
# End Source File
# Begin Source File

SOURCE=.\hReviewDlg.h
# End Source File
# Begin Source File

SOURCE=.\Microformatter.h
# End Source File
# Begin Source File

SOURCE=.\MicroformatterDlg.h
# End Source File
# Begin Source File

SOURCE=.\relTagDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\XFNDlg.h
# End Source File
# Begin Source File

SOURCE=.\xFolkDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\adr_what.bmp
# End Source File
# Begin Source File

SOURCE=.\res\back.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Dragon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hatom.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hcalendar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hcard.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hresume.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Microformatter.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Microformatter.ico
# End Source File
# Begin Source File

SOURCE=.\res\Microformatter.rc2
# End Source File
# Begin Source File

SOURCE=".\res\rel-tag.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\xfn.bmp
# End Source File
# Begin Source File

SOURCE=.\res\xfn.ico
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
