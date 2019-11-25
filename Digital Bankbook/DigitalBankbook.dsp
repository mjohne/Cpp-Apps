# Microsoft Developer Studio Project File - Name="DigitalBankbook" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DigitalBankbook - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DigitalBankbook.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DigitalBankbook.mak" CFG="DigitalBankbook - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DigitalBankbook - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DigitalBankbook - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DigitalBankbook - Win32 Release"

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

!ELSEIF  "$(CFG)" == "DigitalBankbook - Win32 Debug"

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

# Name "DigitalBankbook - Win32 Release"
# Name "DigitalBankbook - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AppOptionsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=".\DigitalBankbook.cpp"
# End Source File
# Begin Source File

SOURCE=".\DigitalBankbook.rc"
# End Source File
# Begin Source File

SOURCE=".\DigitalBankbookDlg.cpp"
# End Source File
# Begin Source File

SOURCE=.\GraphicOutputDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\HyperLink.cpp
# End Source File
# Begin Source File

SOURCE=.\NewBankbookDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NewUserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OpenBankbookDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\ThemeHelperST.cpp
# End Source File
# Begin Source File

SOURCE=.\TransactionDlg.cpp
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

SOURCE=.\AppOptionsDlg.h
# End Source File
# Begin Source File

SOURCE=.\BCMenu.h
# End Source File
# Begin Source File

SOURCE=.\BtnST.h
# End Source File
# Begin Source File

SOURCE=".\DigitalBankbook.h"
# End Source File
# Begin Source File

SOURCE=".\DigitalBankbookDlg.h"
# End Source File
# Begin Source File

SOURCE=.\GraphicOutputDlg.h
# End Source File
# Begin Source File

SOURCE=.\HyperLink.h
# End Source File
# Begin Source File

SOURCE=.\NewBankbookDlg.h
# End Source File
# Begin Source File

SOURCE=.\NewUserDlg.h
# End Source File
# Begin Source File

SOURCE=.\OpenBankbookDlg.h
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

SOURCE=.\TransactionDlg.h
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

SOURCE=.\res\about_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\add2_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\add_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\arrow_down_blue_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\arrow_left_blue_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\arrow_right_blue_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\arrow_up_blue_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_delete_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_find_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_new_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_next_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_open_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_preferences_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_previous_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\book_view_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\businessman_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\calculator_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\calendar_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\cashier_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\chart_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\check_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\clipboard_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\clock_32.ico
# End Source File
# Begin Source File

SOURCE=".\res\column-chart_32.ico"
# End Source File
# Begin Source File

SOURCE=.\res\copy_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\currency_dollar_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\currency_euro_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\currency_pound_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\currency_yen_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\cut_32.ico
# End Source File
# Begin Source File

SOURCE=".\res\date-time_32.ico"
# End Source File
# Begin Source File

SOURCE=.\res\delete_32.ico
# End Source File
# Begin Source File

SOURCE=".\res\DigitalBankbook.ico"
# End Source File
# Begin Source File

SOURCE=".\res\DigitalBankbook.rc2"
# End Source File
# Begin Source File

SOURCE=.\res\disk_blue_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\document_32.ico
# End Source File
# Begin Source File

SOURCE=".\res\dot-chart_32.ico"
# End Source File
# Begin Source File

SOURCE=.\res\edit_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\exit_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\gear_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\home_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\id_card_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\mail_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\media_begin_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\media_end_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\message_edit_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\mfc4_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\money2_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\moneybag_euro_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\note_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\paperclip_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\paste_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\percent_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\photo_scenery_32.ico
# End Source File
# Begin Source File

SOURCE=".\res\pie-chart_32.ico"
# End Source File
# Begin Source File

SOURCE=.\res\preferences_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\presentation_chart_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\press_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\printer_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\redo_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\refresh_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\sort_ascending_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\sort_descending_32.ico
# End Source File
# Begin Source File

SOURCE=.\res\undo_32.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
