# Microsoft Developer Studio Generated NMAKE File, Based on DigitalBankbook.dsp
!IF "$(CFG)" == ""
CFG=DigitalBankbook - Win32 Debug
!MESSAGE No configuration specified. Defaulting to DigitalBankbook - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "DigitalBankbook - Win32 Release" && "$(CFG)" != "DigitalBankbook - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DigitalBankbook - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\DigitalBankbook.exe"


CLEAN :
	-@erase "$(INTDIR)\AppOptionsDlg.obj"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DigitalBankbook.obj"
	-@erase "$(INTDIR)\DigitalBankbook.pch"
	-@erase "$(INTDIR)\DigitalBankbook.res"
	-@erase "$(INTDIR)\DigitalBankbookDlg.obj"
	-@erase "$(INTDIR)\GraphicOutputDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\NewBankbookDlg.obj"
	-@erase "$(INTDIR)\NewUserDlg.obj"
	-@erase "$(INTDIR)\OpenBankbookDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\TransactionDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\DigitalBankbook.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\DigitalBankbook.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\DigitalBankbook.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DigitalBankbook.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\DigitalBankbook.pdb" /machine:I386 /out:"$(OUTDIR)\DigitalBankbook.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DigitalBankbook.obj" \
	"$(INTDIR)\DigitalBankbookDlg.obj" \
	"$(INTDIR)\GraphicOutputDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\NewBankbookDlg.obj" \
	"$(INTDIR)\NewUserDlg.obj" \
	"$(INTDIR)\OpenBankbookDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\TransactionDlg.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\DigitalBankbook.res" \
	"$(INTDIR)\AppOptionsDlg.obj"

"$(OUTDIR)\DigitalBankbook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DigitalBankbook - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\DigitalBankbook.exe"


CLEAN :
	-@erase "$(INTDIR)\AppOptionsDlg.obj"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DigitalBankbook.obj"
	-@erase "$(INTDIR)\DigitalBankbook.pch"
	-@erase "$(INTDIR)\DigitalBankbook.res"
	-@erase "$(INTDIR)\DigitalBankbookDlg.obj"
	-@erase "$(INTDIR)\GraphicOutputDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\NewBankbookDlg.obj"
	-@erase "$(INTDIR)\NewUserDlg.obj"
	-@erase "$(INTDIR)\OpenBankbookDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\TransactionDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\DigitalBankbook.exe"
	-@erase "$(OUTDIR)\DigitalBankbook.ilk"
	-@erase "$(OUTDIR)\DigitalBankbook.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\DigitalBankbook.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\DigitalBankbook.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\DigitalBankbook.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\DigitalBankbook.pdb" /debug /machine:I386 /out:"$(OUTDIR)\DigitalBankbook.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DigitalBankbook.obj" \
	"$(INTDIR)\DigitalBankbookDlg.obj" \
	"$(INTDIR)\GraphicOutputDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\NewBankbookDlg.obj" \
	"$(INTDIR)\NewUserDlg.obj" \
	"$(INTDIR)\OpenBankbookDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\TransactionDlg.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\DigitalBankbook.res" \
	"$(INTDIR)\AppOptionsDlg.obj"

"$(OUTDIR)\DigitalBankbook.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("DigitalBankbook.dep")
!INCLUDE "DigitalBankbook.dep"
!ELSE 
!MESSAGE Warning: cannot find "DigitalBankbook.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "DigitalBankbook - Win32 Release" || "$(CFG)" == "DigitalBankbook - Win32 Debug"
SOURCE=.\AppOptionsDlg.cpp

"$(INTDIR)\AppOptionsDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\BCMenu.cpp

"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\BtnST.cpp

"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=".\DigitalBankbook.cpp"

"$(INTDIR)\DigitalBankbook.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=".\DigitalBankbook.rc"

"$(INTDIR)\DigitalBankbook.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=".\DigitalBankbookDlg.cpp"

"$(INTDIR)\DigitalBankbookDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\GraphicOutputDlg.cpp

"$(INTDIR)\GraphicOutputDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\HyperLink.cpp

"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\NewBankbookDlg.cpp

"$(INTDIR)\NewBankbookDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\NewUserDlg.cpp

"$(INTDIR)\NewUserDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\OpenBankbookDlg.cpp

"$(INTDIR)\OpenBankbookDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "DigitalBankbook - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\DigitalBankbook.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DigitalBankbook.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "DigitalBankbook - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\DigitalBankbook.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\DigitalBankbook.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ThemeHelperST.cpp

"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\TransactionDlg.cpp

"$(INTDIR)\TransactionDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\XPStyleButtonST.cpp

"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"


SOURCE=.\XPTabCtrl.cpp

"$(INTDIR)\XPTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\DigitalBankbook.pch"



!ENDIF 

