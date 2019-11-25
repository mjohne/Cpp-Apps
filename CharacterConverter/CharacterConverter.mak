# Microsoft Developer Studio Generated NMAKE File, Based on CharacterConverter.dsp
!IF "$(CFG)" == ""
CFG=CharacterConverter - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CharacterConverter - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CharacterConverter - Win32 Release" && "$(CFG)" != "CharacterConverter - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CharacterConverter.mak" CFG="CharacterConverter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CharacterConverter - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "CharacterConverter - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "CharacterConverter - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CharacterConverter.exe"


CLEAN :
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\CharacterConverter.obj"
	-@erase "$(INTDIR)\CharacterConverter.pch"
	-@erase "$(INTDIR)\CharacterConverter.res"
	-@erase "$(INTDIR)\CharacterConverterDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\CharacterConverter.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\CharacterConverter.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\CharacterConverter.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CharacterConverter.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\CharacterConverter.pdb" /machine:I386 /out:"$(OUTDIR)\CharacterConverter.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\CharacterConverter.obj" \
	"$(INTDIR)\CharacterConverterDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\CharacterConverter.res"

"$(OUTDIR)\CharacterConverter.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CharacterConverter - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CharacterConverter.exe"


CLEAN :
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\CharacterConverter.obj"
	-@erase "$(INTDIR)\CharacterConverter.pch"
	-@erase "$(INTDIR)\CharacterConverter.res"
	-@erase "$(INTDIR)\CharacterConverterDlg.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\CharacterConverter.exe"
	-@erase "$(OUTDIR)\CharacterConverter.ilk"
	-@erase "$(OUTDIR)\CharacterConverter.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\CharacterConverter.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\CharacterConverter.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CharacterConverter.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\CharacterConverter.pdb" /debug /machine:I386 /out:"$(OUTDIR)\CharacterConverter.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\CharacterConverter.obj" \
	"$(INTDIR)\CharacterConverterDlg.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\CharacterConverter.res"

"$(OUTDIR)\CharacterConverter.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("CharacterConverter.dep")
!INCLUDE "CharacterConverter.dep"
!ELSE 
!MESSAGE Warning: cannot find "CharacterConverter.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CharacterConverter - Win32 Release" || "$(CFG)" == "CharacterConverter - Win32 Debug"
SOURCE=.\BCMenu.cpp

"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CharacterConverter.pch"


SOURCE=.\BtnST.cpp

"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CharacterConverter.pch"


SOURCE=.\CharacterConverter.cpp

"$(INTDIR)\CharacterConverter.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CharacterConverter.pch"


SOURCE=.\CharacterConverter.rc

"$(INTDIR)\CharacterConverter.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\CharacterConverterDlg.cpp

"$(INTDIR)\CharacterConverterDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CharacterConverter.pch"


SOURCE=.\HyperLink.cpp

"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CharacterConverter.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CharacterConverter - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\CharacterConverter.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CharacterConverter.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CharacterConverter - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\CharacterConverter.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CharacterConverter.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ThemeHelperST.cpp

"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CharacterConverter.pch"


SOURCE=.\XPStyleButtonST.cpp

"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CharacterConverter.pch"


SOURCE=.\XPTabCtrl.cpp

"$(INTDIR)\XPTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CharacterConverter.pch"



!ENDIF 

