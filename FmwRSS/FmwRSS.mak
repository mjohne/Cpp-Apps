# Microsoft Developer Studio Generated NMAKE File, Based on FmwRSS.dsp
!IF "$(CFG)" == ""
CFG=FmwRSS - Win32 Debug
!MESSAGE No configuration specified. Defaulting to FmwRSS - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "FmwRSS - Win32 Release" && "$(CFG)" != "FmwRSS - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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

!IF  "$(CFG)" == "FmwRSS - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\FmwRSS.exe" "$(OUTDIR)\FmwRSS.tlb"


CLEAN :
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\FeedDlg.obj"
	-@erase "$(INTDIR)\FmwRSS.obj"
	-@erase "$(INTDIR)\FmwRSS.pch"
	-@erase "$(INTDIR)\FmwRSS.res"
	-@erase "$(INTDIR)\FmwRSS.tlb"
	-@erase "$(INTDIR)\FmwRSSDlg.obj"
	-@erase "$(INTDIR)\GroupDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\FmwRSS.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\FmwRSS.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\FmwRSS.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\FmwRSS.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\FmwRSS.pdb" /machine:I386 /out:"$(OUTDIR)\FmwRSS.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\FeedDlg.obj" \
	"$(INTDIR)\FmwRSS.obj" \
	"$(INTDIR)\FmwRSSDlg.obj" \
	"$(INTDIR)\GroupDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\FmwRSS.res"

"$(OUTDIR)\FmwRSS.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "FmwRSS - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\FmwRSS.exe" "$(OUTDIR)\FmwRSS.tlb"


CLEAN :
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\FeedDlg.obj"
	-@erase "$(INTDIR)\FmwRSS.obj"
	-@erase "$(INTDIR)\FmwRSS.pch"
	-@erase "$(INTDIR)\FmwRSS.res"
	-@erase "$(INTDIR)\FmwRSS.tlb"
	-@erase "$(INTDIR)\FmwRSSDlg.obj"
	-@erase "$(INTDIR)\GroupDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\FmwRSS.exe"
	-@erase "$(OUTDIR)\FmwRSS.ilk"
	-@erase "$(OUTDIR)\FmwRSS.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\FmwRSS.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\FmwRSS.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\FmwRSS.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\FmwRSS.pdb" /debug /machine:I386 /out:"$(OUTDIR)\FmwRSS.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\FeedDlg.obj" \
	"$(INTDIR)\FmwRSS.obj" \
	"$(INTDIR)\FmwRSSDlg.obj" \
	"$(INTDIR)\GroupDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\FmwRSS.res"

"$(OUTDIR)\FmwRSS.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("FmwRSS.dep")
!INCLUDE "FmwRSS.dep"
!ELSE 
!MESSAGE Warning: cannot find "FmwRSS.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "FmwRSS - Win32 Release" || "$(CFG)" == "FmwRSS - Win32 Debug"
SOURCE=.\BCMenu.cpp

"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\BtnST.cpp

"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\DlgProxy.cpp

"$(INTDIR)\DlgProxy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\FeedDlg.cpp

"$(INTDIR)\FeedDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\FmwRSS.cpp

"$(INTDIR)\FmwRSS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\FmwRSS.odl

!IF  "$(CFG)" == "FmwRSS - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\FmwRSS.tlb" /mktyplib203 /win32 

"$(OUTDIR)\FmwRSS.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "FmwRSS - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\FmwRSS.tlb" /mktyplib203 /win32 

"$(OUTDIR)\FmwRSS.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\FmwRSS.rc

!IF  "$(CFG)" == "FmwRSS - Win32 Release"


"$(INTDIR)\FmwRSS.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\FmwRSS.res" /i "Release" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "FmwRSS - Win32 Debug"


"$(INTDIR)\FmwRSS.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\FmwRSS.res" /i "Debug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\FmwRSSDlg.cpp

"$(INTDIR)\FmwRSSDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\GroupDlg.cpp

"$(INTDIR)\GroupDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\HyperLink.cpp

"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "FmwRSS - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\FmwRSS.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\FmwRSS.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "FmwRSS - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\FmwRSS.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\FmwRSS.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ThemeHelperST.cpp

"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\XPStyleButtonST.cpp

"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"


SOURCE=.\XPTabCtrl.cpp

"$(INTDIR)\XPTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\FmwRSS.pch"



!ENDIF 

