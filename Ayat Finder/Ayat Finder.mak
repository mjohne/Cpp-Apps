# Microsoft Developer Studio Generated NMAKE File, Based on Ayat Finder.dsp
!IF "$(CFG)" == ""
CFG=Ayat Finder - Win32 Shared Debug
!MESSAGE No configuration specified. Defaulting to Ayat Finder - Win32 Shared Debug.
!ENDIF 

!IF "$(CFG)" != "Ayat Finder - Win32 Static Release" && "$(CFG)" != "Ayat Finder - Win32 Static Debug" && "$(CFG)" != "Ayat Finder - Win32 Shared Release" && "$(CFG)" != "Ayat Finder - Win32 Shared Debug" && "$(CFG)" != "Ayat Finder - Win32 Static Release Unicode"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Ayat Finder.mak" CFG="Ayat Finder - Win32 Shared Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Ayat Finder - Win32 Static Release" (based on "Win32 (x86) Application")
!MESSAGE "Ayat Finder - Win32 Static Debug" (based on "Win32 (x86) Application")
!MESSAGE "Ayat Finder - Win32 Shared Release" (based on "Win32 (x86) Application")
!MESSAGE "Ayat Finder - Win32 Shared Debug" (based on "Win32 (x86) Application")
!MESSAGE "Ayat Finder - Win32 Static Release Unicode" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"

OUTDIR=.\Release Static
INTDIR=.\Release Static
# Begin Custom Macros
OutDir=.\Release Static
# End Custom Macros

ALL : "$(OUTDIR)\Ayat Finder.exe" "$(OUTDIR)\Ayat Finder.tlb" "$(OUTDIR)\Ayat Finder.pch" "$(OUTDIR)\Ayat Finder.bsc"


CLEAN :
	-@erase "$(INTDIR)\AutoRichEditCtrl.obj"
	-@erase "$(INTDIR)\AutoRichEditCtrl.sbr"
	-@erase "$(INTDIR)\Ayat Finder.obj"
	-@erase "$(INTDIR)\Ayat Finder.pch"
	-@erase "$(INTDIR)\Ayat Finder.res"
	-@erase "$(INTDIR)\Ayat Finder.sbr"
	-@erase "$(INTDIR)\Ayat Finder.tlb"
	-@erase "$(INTDIR)\Ayat FinderDlg.obj"
	-@erase "$(INTDIR)\Ayat FinderDlg.sbr"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BCMenu.sbr"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\BtnST.sbr"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\DlgProxy.sbr"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\HyperLink.sbr"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\OptionsDlg.sbr"
	-@erase "$(INTDIR)\ResizableDialog.obj"
	-@erase "$(INTDIR)\ResizableDialog.sbr"
	-@erase "$(INTDIR)\SaveResultDlg.obj"
	-@erase "$(INTDIR)\SaveResultDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\ThemeHelperST.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPStyleButtonST.sbr"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(INTDIR)\XPTabCtrl.sbr"
	-@erase "$(INTDIR)\XUnzip.obj"
	-@erase "$(INTDIR)\XUnzip.sbr"
	-@erase "$(INTDIR)\XZip.obj"
	-@erase "$(INTDIR)\XZip.sbr"
	-@erase "$(OUTDIR)\Ayat Finder.bsc"
	-@erase "$(OUTDIR)\Ayat Finder.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ayat Finder.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AutoRichEditCtrl.sbr" \
	"$(INTDIR)\Ayat Finder.sbr" \
	"$(INTDIR)\Ayat FinderDlg.sbr" \
	"$(INTDIR)\BCMenu.sbr" \
	"$(INTDIR)\BtnST.sbr" \
	"$(INTDIR)\DlgProxy.sbr" \
	"$(INTDIR)\HyperLink.sbr" \
	"$(INTDIR)\OptionsDlg.sbr" \
	"$(INTDIR)\ResizableDialog.sbr" \
	"$(INTDIR)\SaveResultDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\ThemeHelperST.sbr" \
	"$(INTDIR)\XPStyleButtonST.sbr" \
	"$(INTDIR)\XPTabCtrl.sbr" \
	"$(INTDIR)\XUnzip.sbr" \
	"$(INTDIR)\XZip.sbr"

"$(OUTDIR)\Ayat Finder.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Ayat Finder.pdb" /machine:I386 /out:"$(OUTDIR)\Ayat Finder.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AutoRichEditCtrl.obj" \
	"$(INTDIR)\Ayat Finder.obj" \
	"$(INTDIR)\Ayat FinderDlg.obj" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\ResizableDialog.obj" \
	"$(INTDIR)\SaveResultDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\XUnzip.obj" \
	"$(INTDIR)\XZip.obj" \
	"$(INTDIR)\Ayat Finder.res"

"$(OUTDIR)\Ayat Finder.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"

OUTDIR=.\Debug Static
INTDIR=.\Debug Static
# Begin Custom Macros
OutDir=.\Debug Static
# End Custom Macros

ALL : "$(OUTDIR)\Ayat Finder.exe" "$(OUTDIR)\Ayat Finder.tlb"


CLEAN :
	-@erase "$(INTDIR)\AutoRichEditCtrl.obj"
	-@erase "$(INTDIR)\Ayat Finder.obj"
	-@erase "$(INTDIR)\Ayat Finder.pch"
	-@erase "$(INTDIR)\Ayat Finder.res"
	-@erase "$(INTDIR)\Ayat Finder.tlb"
	-@erase "$(INTDIR)\Ayat FinderDlg.obj"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\ResizableDialog.obj"
	-@erase "$(INTDIR)\SaveResultDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(INTDIR)\XUnzip.obj"
	-@erase "$(INTDIR)\XZip.obj"
	-@erase "$(OUTDIR)\Ayat Finder.exe"
	-@erase "$(OUTDIR)\Ayat Finder.ilk"
	-@erase "$(OUTDIR)\Ayat Finder.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Ayat Finder.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ayat Finder.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Ayat Finder.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Ayat Finder.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AutoRichEditCtrl.obj" \
	"$(INTDIR)\Ayat Finder.obj" \
	"$(INTDIR)\Ayat FinderDlg.obj" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\ResizableDialog.obj" \
	"$(INTDIR)\SaveResultDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\XUnzip.obj" \
	"$(INTDIR)\XZip.obj" \
	"$(INTDIR)\Ayat Finder.res"

"$(OUTDIR)\Ayat Finder.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"

OUTDIR=.\Release Shared
INTDIR=.\Release Shared
# Begin Custom Macros
OutDir=.\Release Shared
# End Custom Macros

ALL : "$(OUTDIR)\Ayat Finder.exe" "$(OUTDIR)\Ayat Finder.tlb" "$(OUTDIR)\Ayat Finder.pch"


CLEAN :
	-@erase "$(INTDIR)\AutoRichEditCtrl.obj"
	-@erase "$(INTDIR)\Ayat Finder.obj"
	-@erase "$(INTDIR)\Ayat Finder.pch"
	-@erase "$(INTDIR)\Ayat Finder.res"
	-@erase "$(INTDIR)\Ayat Finder.tlb"
	-@erase "$(INTDIR)\Ayat FinderDlg.obj"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\ResizableDialog.obj"
	-@erase "$(INTDIR)\SaveResultDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(INTDIR)\XUnzip.obj"
	-@erase "$(INTDIR)\XZip.obj"
	-@erase "$(OUTDIR)\Ayat Finder.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ayat Finder.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Ayat Finder.pdb" /machine:I386 /out:"$(OUTDIR)\Ayat Finder.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AutoRichEditCtrl.obj" \
	"$(INTDIR)\Ayat Finder.obj" \
	"$(INTDIR)\Ayat FinderDlg.obj" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\ResizableDialog.obj" \
	"$(INTDIR)\SaveResultDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\XUnzip.obj" \
	"$(INTDIR)\XZip.obj" \
	"$(INTDIR)\Ayat Finder.res"

"$(OUTDIR)\Ayat Finder.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"

OUTDIR=.\Debug Shared
INTDIR=.\Debug Shared
# Begin Custom Macros
OutDir=.\Debug Shared
# End Custom Macros

ALL : "$(OUTDIR)\Ayat Finder.exe" "$(OUTDIR)\Ayat Finder.tlb"


CLEAN :
	-@erase "$(INTDIR)\AutoRichEditCtrl.obj"
	-@erase "$(INTDIR)\Ayat Finder.obj"
	-@erase "$(INTDIR)\Ayat Finder.pch"
	-@erase "$(INTDIR)\Ayat Finder.res"
	-@erase "$(INTDIR)\Ayat Finder.tlb"
	-@erase "$(INTDIR)\Ayat FinderDlg.obj"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\ResizableDialog.obj"
	-@erase "$(INTDIR)\SaveResultDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(INTDIR)\XUnzip.obj"
	-@erase "$(INTDIR)\XZip.obj"
	-@erase "$(OUTDIR)\Ayat Finder.exe"
	-@erase "$(OUTDIR)\Ayat Finder.ilk"
	-@erase "$(OUTDIR)\Ayat Finder.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\Ayat Finder.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ayat Finder.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Ayat Finder.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Ayat Finder.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AutoRichEditCtrl.obj" \
	"$(INTDIR)\Ayat Finder.obj" \
	"$(INTDIR)\Ayat FinderDlg.obj" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\ResizableDialog.obj" \
	"$(INTDIR)\SaveResultDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\XUnzip.obj" \
	"$(INTDIR)\XZip.obj" \
	"$(INTDIR)\Ayat Finder.res"

"$(OUTDIR)\Ayat Finder.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"

OUTDIR=.\Static_Release_Unicode
INTDIR=.\Static_Release_Unicode
# Begin Custom Macros
OutDir=.\Static_Release_Unicode
# End Custom Macros

ALL : "$(OUTDIR)\Ayat Finder.exe" "$(OUTDIR)\Ayat Finder.tlb" "$(OUTDIR)\Ayat Finder.pch" "$(OUTDIR)\Ayat Finder.bsc"


CLEAN :
	-@erase "$(INTDIR)\AutoRichEditCtrl.obj"
	-@erase "$(INTDIR)\AutoRichEditCtrl.sbr"
	-@erase "$(INTDIR)\Ayat Finder.obj"
	-@erase "$(INTDIR)\Ayat Finder.pch"
	-@erase "$(INTDIR)\Ayat Finder.res"
	-@erase "$(INTDIR)\Ayat Finder.sbr"
	-@erase "$(INTDIR)\Ayat Finder.tlb"
	-@erase "$(INTDIR)\Ayat FinderDlg.obj"
	-@erase "$(INTDIR)\Ayat FinderDlg.sbr"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BCMenu.sbr"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\BtnST.sbr"
	-@erase "$(INTDIR)\DlgProxy.obj"
	-@erase "$(INTDIR)\DlgProxy.sbr"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\HyperLink.sbr"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\OptionsDlg.sbr"
	-@erase "$(INTDIR)\ResizableDialog.obj"
	-@erase "$(INTDIR)\ResizableDialog.sbr"
	-@erase "$(INTDIR)\SaveResultDlg.obj"
	-@erase "$(INTDIR)\SaveResultDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\ThemeHelperST.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPStyleButtonST.sbr"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(INTDIR)\XPTabCtrl.sbr"
	-@erase "$(INTDIR)\XUnzip.obj"
	-@erase "$(INTDIR)\XUnzip.sbr"
	-@erase "$(INTDIR)\XZip.obj"
	-@erase "$(INTDIR)\XZip.sbr"
	-@erase "$(OUTDIR)\Ayat Finder.bsc"
	-@erase "$(OUTDIR)\Ayat Finder.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Ayat Finder.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AutoRichEditCtrl.sbr" \
	"$(INTDIR)\Ayat Finder.sbr" \
	"$(INTDIR)\Ayat FinderDlg.sbr" \
	"$(INTDIR)\BCMenu.sbr" \
	"$(INTDIR)\BtnST.sbr" \
	"$(INTDIR)\DlgProxy.sbr" \
	"$(INTDIR)\HyperLink.sbr" \
	"$(INTDIR)\OptionsDlg.sbr" \
	"$(INTDIR)\ResizableDialog.sbr" \
	"$(INTDIR)\SaveResultDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\ThemeHelperST.sbr" \
	"$(INTDIR)\XPStyleButtonST.sbr" \
	"$(INTDIR)\XPTabCtrl.sbr" \
	"$(INTDIR)\XUnzip.sbr" \
	"$(INTDIR)\XZip.sbr"

"$(OUTDIR)\Ayat Finder.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Ayat Finder.pdb" /machine:I386 /out:"$(OUTDIR)\Ayat Finder.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AutoRichEditCtrl.obj" \
	"$(INTDIR)\Ayat Finder.obj" \
	"$(INTDIR)\Ayat FinderDlg.obj" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\DlgProxy.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\ResizableDialog.obj" \
	"$(INTDIR)\SaveResultDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\XUnzip.obj" \
	"$(INTDIR)\XZip.obj" \
	"$(INTDIR)\Ayat Finder.res"

"$(OUTDIR)\Ayat Finder.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("Ayat Finder.dep")
!INCLUDE "Ayat Finder.dep"
!ELSE 
!MESSAGE Warning: cannot find "Ayat Finder.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Ayat Finder - Win32 Static Release" || "$(CFG)" == "Ayat Finder - Win32 Static Debug" || "$(CFG)" == "Ayat Finder - Win32 Shared Release" || "$(CFG)" == "Ayat Finder - Win32 Shared Debug" || "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"
SOURCE=.\AutoRichEditCtrl.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\AutoRichEditCtrl.obj"	"$(INTDIR)\AutoRichEditCtrl.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\AutoRichEditCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\AutoRichEditCtrl.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\AutoRichEditCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\AutoRichEditCtrl.obj"	"$(INTDIR)\AutoRichEditCtrl.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=".\Ayat Finder.cpp"

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\Ayat Finder.obj"	"$(INTDIR)\Ayat Finder.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\Ayat Finder.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\Ayat Finder.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\Ayat Finder.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\Ayat Finder.obj"	"$(INTDIR)\Ayat Finder.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=".\Ayat Finder.odl"

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\Ayat Finder.tlb" /mktyplib203 /win32 

"$(OUTDIR)\Ayat Finder.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\Ayat Finder.tlb" /mktyplib203 /win32 

"$(OUTDIR)\Ayat Finder.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\Ayat Finder.tlb" /mktyplib203 /win32 

"$(OUTDIR)\Ayat Finder.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\Ayat Finder.tlb" /mktyplib203 /win32 

"$(OUTDIR)\Ayat Finder.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\Ayat Finder.tlb" /mktyplib203 /win32 

"$(OUTDIR)\Ayat Finder.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=".\Ayat Finder.rc"

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\Ayat Finder.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /i "Release Static" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\Ayat Finder.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /i "Debug Static" /d "_DEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\Ayat Finder.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /i "Release Shared" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\Ayat Finder.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /i "Debug Shared" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\Ayat Finder.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x407 /fo"$(INTDIR)\Ayat Finder.res" /i "Static_Release_Unicode" /d "NDEBUG" $(SOURCE)


!ENDIF 

SOURCE=".\Ayat FinderDlg.cpp"

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\Ayat FinderDlg.obj"	"$(INTDIR)\Ayat FinderDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\Ayat FinderDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\Ayat FinderDlg.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\Ayat FinderDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\Ayat FinderDlg.obj"	"$(INTDIR)\Ayat FinderDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\BCMenu.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\BCMenu.obj"	"$(INTDIR)\BCMenu.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\BCMenu.obj"	"$(INTDIR)\BCMenu.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\BtnST.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\BtnST.obj"	"$(INTDIR)\BtnST.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\BtnST.obj"	"$(INTDIR)\BtnST.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\DlgProxy.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\DlgProxy.obj"	"$(INTDIR)\DlgProxy.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\DlgProxy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\DlgProxy.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\DlgProxy.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\DlgProxy.obj"	"$(INTDIR)\DlgProxy.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\HyperLink.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\HyperLink.obj"	"$(INTDIR)\HyperLink.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\HyperLink.obj"	"$(INTDIR)\HyperLink.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\OptionsDlg.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\OptionsDlg.obj"	"$(INTDIR)\OptionsDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\OptionsDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\OptionsDlg.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\OptionsDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\OptionsDlg.obj"	"$(INTDIR)\OptionsDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\ResizableDialog.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\ResizableDialog.obj"	"$(INTDIR)\ResizableDialog.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\ResizableDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\ResizableDialog.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\ResizableDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\ResizableDialog.obj"	"$(INTDIR)\ResizableDialog.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\SaveResultDlg.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\SaveResultDlg.obj"	"$(INTDIR)\SaveResultDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\SaveResultDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\SaveResultDlg.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\SaveResultDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\SaveResultDlg.obj"	"$(INTDIR)\SaveResultDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Ayat Finder.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Ayat Finder.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Ayat Finder.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Ayat Finder.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\Ayat Finder.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Ayat Finder.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\Ayat Finder.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Ayat Finder.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Ayat Finder.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Ayat Finder.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ThemeHelperST.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\ThemeHelperST.obj"	"$(INTDIR)\ThemeHelperST.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\ThemeHelperST.obj"	"$(INTDIR)\ThemeHelperST.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XPStyleButtonST.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\XPStyleButtonST.obj"	"$(INTDIR)\XPStyleButtonST.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\XPStyleButtonST.obj"	"$(INTDIR)\XPStyleButtonST.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XPTabCtrl.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\XPTabCtrl.obj"	"$(INTDIR)\XPTabCtrl.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\XPTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\XPTabCtrl.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\XPTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\XPTabCtrl.obj"	"$(INTDIR)\XPTabCtrl.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XUnzip.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\XUnzip.obj"	"$(INTDIR)\XUnzip.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\XUnzip.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\XUnzip.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\XUnzip.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\XUnzip.obj"	"$(INTDIR)\XUnzip.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\XZip.cpp

!IF  "$(CFG)" == "Ayat Finder - Win32 Static Release"


"$(INTDIR)\XZip.obj"	"$(INTDIR)\XZip.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Debug"


"$(INTDIR)\XZip.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Release"


"$(INTDIR)\XZip.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Shared Debug"


"$(INTDIR)\XZip.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Ayat Finder.pch"


!ELSEIF  "$(CFG)" == "Ayat Finder - Win32 Static Release Unicode"


"$(INTDIR)\XZip.obj"	"$(INTDIR)\XZip.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

