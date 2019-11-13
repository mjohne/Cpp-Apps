# Microsoft Developer Studio Generated NMAKE File, Based on StarCalc.dsp
!IF "$(CFG)" == ""
CFG=StarCalc - Win32 Debug
!MESSAGE No configuration specified. Defaulting to StarCalc - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "StarCalc - Win32 Release" && "$(CFG)" != "StarCalc - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "StarCalc.mak" CFG="StarCalc - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "StarCalc - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "StarCalc - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "StarCalc - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\StarCalc.exe" "$(OUTDIR)\StarCalc.tlb"


CLEAN :
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\StarCalc.obj"
	-@erase "$(INTDIR)\StarCalc.pch"
	-@erase "$(INTDIR)\StarCalc.res"
	-@erase "$(INTDIR)\StarCalc.tlb"
	-@erase "$(INTDIR)\StarCalcDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\StarCalc.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\StarCalc.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\StarCalc.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\StarCalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\StarCalc.pdb" /machine:I386 /out:"$(OUTDIR)\StarCalc.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\StarCalc.obj" \
	"$(INTDIR)\StarCalcDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\StarCalc.res" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\ThemeHelperST.obj"

"$(OUTDIR)\StarCalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "StarCalc - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\StarCalc.exe" "$(OUTDIR)\StarCalc.tlb"


CLEAN :
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\StarCalc.obj"
	-@erase "$(INTDIR)\StarCalc.pch"
	-@erase "$(INTDIR)\StarCalc.res"
	-@erase "$(INTDIR)\StarCalc.tlb"
	-@erase "$(INTDIR)\StarCalcDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\StarCalc.exe"
	-@erase "$(OUTDIR)\StarCalc.ilk"
	-@erase "$(OUTDIR)\StarCalc.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\StarCalc.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\StarCalc.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\StarCalc.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\StarCalc.pdb" /debug /machine:I386 /out:"$(OUTDIR)\StarCalc.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\StarCalc.obj" \
	"$(INTDIR)\StarCalcDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\StarCalc.res" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\ThemeHelperST.obj"

"$(OUTDIR)\StarCalc.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("StarCalc.dep")
!INCLUDE "StarCalc.dep"
!ELSE 
!MESSAGE Warning: cannot find "StarCalc.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "StarCalc - Win32 Release" || "$(CFG)" == "StarCalc - Win32 Debug"
SOURCE=.\BCMenu.cpp

"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"


SOURCE=.\BtnST.cpp

"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"


SOURCE=.\DlgProxy.cpp

"$(INTDIR)\DlgProxy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"


SOURCE=.\HyperLink.cpp

"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"


SOURCE=.\StarCalc.cpp

"$(INTDIR)\StarCalc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"


SOURCE=.\StarCalc.odl

!IF  "$(CFG)" == "StarCalc - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\StarCalc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\StarCalc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "StarCalc - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\StarCalc.tlb" /mktyplib203 /win32 

"$(OUTDIR)\StarCalc.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\StarCalc.rc

!IF  "$(CFG)" == "StarCalc - Win32 Release"


"$(INTDIR)\StarCalc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\StarCalc.res" /i "Release" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "StarCalc - Win32 Debug"


"$(INTDIR)\StarCalc.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\StarCalc.res" /i "Debug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\StarCalcDlg.cpp

"$(INTDIR)\StarCalcDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "StarCalc - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\StarCalc.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StarCalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "StarCalc - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\StarCalc.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StarCalc.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ThemeHelperST.cpp

"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"


SOURCE=.\XPStyleButtonST.cpp

"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"


SOURCE=.\XPTabCtrl.cpp

"$(INTDIR)\XPTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\StarCalc.pch"



!ENDIF 

