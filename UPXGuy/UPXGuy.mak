# Microsoft Developer Studio Generated NMAKE File, Based on UPXGuy.dsp
!IF "$(CFG)" == ""
CFG=UPXGuy - Win32 Debug
!MESSAGE No configuration specified. Defaulting to UPXGuy - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "UPXGuy - Win32 Release" && "$(CFG)" != "UPXGuy - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "UPXGuy.mak" CFG="UPXGuy - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "UPXGuy - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "UPXGuy - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "UPXGuy - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\UPXGuy.exe" "$(OUTDIR)\UPXGuy.tlb" "$(OUTDIR)\UPXGuy.pch"


CLEAN :
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\UPXGuy.obj"
	-@erase "$(INTDIR)\UPXGuy.pch"
	-@erase "$(INTDIR)\UPXGuy.res"
	-@erase "$(INTDIR)\UPXGuy.tlb"
	-@erase "$(INTDIR)\UPXGuyDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\UPXGuy.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GR- /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\UPXGuy.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\UPXGuy.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\UPXGuy.pdb" /machine:I386 /out:"$(OUTDIR)\UPXGuy.exe" 
LINK32_OBJS= \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UPXGuy.obj" \
	"$(INTDIR)\UPXGuyDlg.obj" \
	"$(INTDIR)\UPXGuy.res"

"$(OUTDIR)\UPXGuy.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "UPXGuy - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\UPXGuy.exe" "$(OUTDIR)\UPXGuy.pch" "$(OUTDIR)\UPXGuy.tlb"


CLEAN :
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\UPXGuy.obj"
	-@erase "$(INTDIR)\UPXGuy.pch"
	-@erase "$(INTDIR)\UPXGuy.res"
	-@erase "$(INTDIR)\UPXGuy.tlb"
	-@erase "$(INTDIR)\UPXGuyDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\UPXGuy.exe"
	-@erase "$(OUTDIR)\UPXGuy.ilk"
	-@erase "$(OUTDIR)\UPXGuy.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GR- /GX /ZI /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\UPXGuy.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\UPXGuy.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\UPXGuy.pdb" /debug /machine:I386 /out:"$(OUTDIR)\UPXGuy.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\UPXGuy.obj" \
	"$(INTDIR)\UPXGuyDlg.obj" \
	"$(INTDIR)\UPXGuy.res"

"$(OUTDIR)\UPXGuy.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("UPXGuy.dep")
!INCLUDE "UPXGuy.dep"
!ELSE 
!MESSAGE Warning: cannot find "UPXGuy.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "UPXGuy - Win32 Release" || "$(CFG)" == "UPXGuy - Win32 Debug"
SOURCE=.\DlgProxy.cpp

"$(INTDIR)\DlgProxy.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "UPXGuy - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GR- /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\UPXGuy.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\UPXGuy.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "UPXGuy - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GR- /GX /ZI /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\UPXGuy.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\UPXGuy.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\UPXGuy.cpp

"$(INTDIR)\UPXGuy.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\UPXGuy.odl

!IF  "$(CFG)" == "UPXGuy - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\UPXGuy.tlb" /mktyplib203 /win32 

"$(OUTDIR)\UPXGuy.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "UPXGuy - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\UPXGuy.tlb" /mktyplib203 /win32 

"$(OUTDIR)\UPXGuy.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\UPXGuy.rc

!IF  "$(CFG)" == "UPXGuy - Win32 Release"


"$(INTDIR)\UPXGuy.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\UPXGuy.res" /i "Release" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "UPXGuy - Win32 Debug"


"$(INTDIR)\UPXGuy.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\UPXGuy.res" /i "Debug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\UPXGuyDlg.cpp

"$(INTDIR)\UPXGuyDlg.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

