# Microsoft Developer Studio Generated NMAKE File, Based on LscGen.dsp
!IF "$(CFG)" == ""
CFG=LscGen - Win32 Debug
!MESSAGE No configuration specified. Defaulting to LscGen - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "LscGen - Win32 Release" && "$(CFG)" != "LscGen - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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

!IF  "$(CFG)" == "LscGen - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\LscGen.exe" "$(OUTDIR)\LscGen.bsc"


CLEAN :
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BCMenu.sbr"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\BtnST.sbr"
	-@erase "$(INTDIR)\ExportAsGraphicDlg.obj"
	-@erase "$(INTDIR)\ExportAsGraphicDlg.sbr"
	-@erase "$(INTDIR)\ExportAsModelDlg.obj"
	-@erase "$(INTDIR)\ExportAsModelDlg.sbr"
	-@erase "$(INTDIR)\HeightmapPreviewDlg.obj"
	-@erase "$(INTDIR)\HeightmapPreviewDlg.sbr"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\HyperLink.sbr"
	-@erase "$(INTDIR)\LscEditDlg.obj"
	-@erase "$(INTDIR)\LscEditDlg.sbr"
	-@erase "$(INTDIR)\LscGen.obj"
	-@erase "$(INTDIR)\LscGen.pch"
	-@erase "$(INTDIR)\LscGen.res"
	-@erase "$(INTDIR)\LscGen.sbr"
	-@erase "$(INTDIR)\LscGenDlg.obj"
	-@erase "$(INTDIR)\LscGenDlg.sbr"
	-@erase "$(INTDIR)\LscNewDlg.obj"
	-@erase "$(INTDIR)\LscNewDlg.sbr"
	-@erase "$(INTDIR)\Mtrx.obj"
	-@erase "$(INTDIR)\Mtrx.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\ThemeHelperST.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPStyleButtonST.sbr"
	-@erase "$(OUTDIR)\LscGen.bsc"
	-@erase "$(OUTDIR)\LscGen.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\LscGen.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\LscGen.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LscGen.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\BCMenu.sbr" \
	"$(INTDIR)\BtnST.sbr" \
	"$(INTDIR)\ExportAsGraphicDlg.sbr" \
	"$(INTDIR)\ExportAsModelDlg.sbr" \
	"$(INTDIR)\HyperLink.sbr" \
	"$(INTDIR)\LscEditDlg.sbr" \
	"$(INTDIR)\LscGen.sbr" \
	"$(INTDIR)\LscGenDlg.sbr" \
	"$(INTDIR)\LscNewDlg.sbr" \
	"$(INTDIR)\Mtrx.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\ThemeHelperST.sbr" \
	"$(INTDIR)\XPStyleButtonST.sbr" \
	"$(INTDIR)\HeightmapPreviewDlg.sbr"

"$(OUTDIR)\LscGen.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\LscGen.pdb" /machine:I386 /out:"$(OUTDIR)\LscGen.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\ExportAsGraphicDlg.obj" \
	"$(INTDIR)\ExportAsModelDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\LscEditDlg.obj" \
	"$(INTDIR)\LscGen.obj" \
	"$(INTDIR)\LscGenDlg.obj" \
	"$(INTDIR)\LscNewDlg.obj" \
	"$(INTDIR)\Mtrx.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\LscGen.res" \
	"$(INTDIR)\HeightmapPreviewDlg.obj"

"$(OUTDIR)\LscGen.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\LscGen.exe"


CLEAN :
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\ExportAsGraphicDlg.obj"
	-@erase "$(INTDIR)\ExportAsModelDlg.obj"
	-@erase "$(INTDIR)\HeightmapPreviewDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\LscEditDlg.obj"
	-@erase "$(INTDIR)\LscGen.obj"
	-@erase "$(INTDIR)\LscGen.pch"
	-@erase "$(INTDIR)\LscGen.res"
	-@erase "$(INTDIR)\LscGenDlg.obj"
	-@erase "$(INTDIR)\LscNewDlg.obj"
	-@erase "$(INTDIR)\Mtrx.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(OUTDIR)\LscGen.exe"
	-@erase "$(OUTDIR)\LscGen.ilk"
	-@erase "$(OUTDIR)\LscGen.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\LscGen.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\LscGen.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\LscGen.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\LscGen.pdb" /debug /machine:I386 /out:"$(OUTDIR)\LscGen.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\ExportAsGraphicDlg.obj" \
	"$(INTDIR)\ExportAsModelDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\LscEditDlg.obj" \
	"$(INTDIR)\LscGen.obj" \
	"$(INTDIR)\LscGenDlg.obj" \
	"$(INTDIR)\LscNewDlg.obj" \
	"$(INTDIR)\Mtrx.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\LscGen.res" \
	"$(INTDIR)\HeightmapPreviewDlg.obj"

"$(OUTDIR)\LscGen.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("LscGen.dep")
!INCLUDE "LscGen.dep"
!ELSE 
!MESSAGE Warning: cannot find "LscGen.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "LscGen - Win32 Release" || "$(CFG)" == "LscGen - Win32 Debug"
SOURCE=.\BCMenu.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\BCMenu.obj"	"$(INTDIR)\BCMenu.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\BtnST.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\BtnST.obj"	"$(INTDIR)\BtnST.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\ExportAsGraphicDlg.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\ExportAsGraphicDlg.obj"	"$(INTDIR)\ExportAsGraphicDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\ExportAsGraphicDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\ExportAsModelDlg.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\ExportAsModelDlg.obj"	"$(INTDIR)\ExportAsModelDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\ExportAsModelDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\HeightmapPreviewDlg.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\HeightmapPreviewDlg.obj"	"$(INTDIR)\HeightmapPreviewDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\HeightmapPreviewDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\HyperLink.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\HyperLink.obj"	"$(INTDIR)\HyperLink.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\LscEditDlg.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\LscEditDlg.obj"	"$(INTDIR)\LscEditDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\LscEditDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\LscGen.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\LscGen.obj"	"$(INTDIR)\LscGen.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\LscGen.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\LscGen.rc

"$(INTDIR)\LscGen.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\LscGenDlg.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\LscGenDlg.obj"	"$(INTDIR)\LscGenDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\LscGenDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\LscNewDlg.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\LscNewDlg.obj"	"$(INTDIR)\LscNewDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\LscNewDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\Mtrx.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\Mtrx.obj"	"$(INTDIR)\Mtrx.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\Mtrx.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\LscGen.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\LscGen.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\LscGen.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\LscGen.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ThemeHelperST.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\ThemeHelperST.obj"	"$(INTDIR)\ThemeHelperST.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 

SOURCE=.\XPStyleButtonST.cpp

!IF  "$(CFG)" == "LscGen - Win32 Release"


"$(INTDIR)\XPStyleButtonST.obj"	"$(INTDIR)\XPStyleButtonST.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ELSEIF  "$(CFG)" == "LscGen - Win32 Debug"


"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\LscGen.pch"


!ENDIF 


!ENDIF 

