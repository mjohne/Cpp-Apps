# Microsoft Developer Studio Generated NMAKE File, Based on Salah.dsp
!IF "$(CFG)" == ""
CFG=Salah - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Salah - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Salah - Win32 Release" && "$(CFG)" != "Salah - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Salah.mak" CFG="Salah - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Salah - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Salah - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Salah - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Salah.exe"


CLEAN :
	-@erase "$(INTDIR)\Salah.obj"
	-@erase "$(INTDIR)\Salah.pch"
	-@erase "$(INTDIR)\Salah.res"
	-@erase "$(INTDIR)\SalahDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TabelleSpeichern.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WeltkarteDlg.obj"
	-@erase "$(OUTDIR)\Salah.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Salah.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\Salah.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Salah.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Salah.pdb" /machine:I386 /out:"$(OUTDIR)\Salah.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Salah.obj" \
	"$(INTDIR)\SalahDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WeltkarteDlg.obj" \
	"$(INTDIR)\Salah.res" \
	"$(INTDIR)\TabelleSpeichern.obj"

"$(OUTDIR)\Salah.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Salah - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Salah.exe"


CLEAN :
	-@erase "$(INTDIR)\Salah.obj"
	-@erase "$(INTDIR)\Salah.pch"
	-@erase "$(INTDIR)\Salah.res"
	-@erase "$(INTDIR)\SalahDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TabelleSpeichern.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WeltkarteDlg.obj"
	-@erase "$(OUTDIR)\Salah.exe"
	-@erase "$(OUTDIR)\Salah.ilk"
	-@erase "$(OUTDIR)\Salah.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Salah.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\Salah.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Salah.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Salah.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Salah.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Salah.obj" \
	"$(INTDIR)\SalahDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WeltkarteDlg.obj" \
	"$(INTDIR)\Salah.res" \
	"$(INTDIR)\TabelleSpeichern.obj"

"$(OUTDIR)\Salah.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Salah.dep")
!INCLUDE "Salah.dep"
!ELSE 
!MESSAGE Warning: cannot find "Salah.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Salah - Win32 Release" || "$(CFG)" == "Salah - Win32 Debug"
SOURCE=.\Salah.cpp

"$(INTDIR)\Salah.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Salah.pch"


SOURCE=.\Salah.rc

"$(INTDIR)\Salah.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\SalahDlg.cpp

"$(INTDIR)\SalahDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Salah.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Salah - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Salah.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Salah.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Salah - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Salah.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Salah.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TabelleSpeichern.cpp

"$(INTDIR)\TabelleSpeichern.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Salah.pch"


SOURCE=.\WeltkarteDlg.cpp

"$(INTDIR)\WeltkarteDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Salah.pch"



!ENDIF 

