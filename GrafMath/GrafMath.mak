# Microsoft Developer Studio Generated NMAKE File, Based on GrafMath.dsp
!IF "$(CFG)" == ""
CFG=GrafMath - Win32 Debug
!MESSAGE No configuration specified. Defaulting to GrafMath - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "GrafMath - Win32 Release" && "$(CFG)" != "GrafMath - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "GrafMath.mak" CFG="GrafMath - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "GrafMath - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "GrafMath - Win32 Debug" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "GrafMath - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\GrafMath.exe" "$(OUTDIR)\GrafMath.pch" "$(OUTDIR)\GrafMath.bsc"


CLEAN :
	-@erase "$(INTDIR)\AxisOptionsDlg.obj"
	-@erase "$(INTDIR)\AxisOptionsDlg.sbr"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BCMenu.sbr"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\BtnST.sbr"
	-@erase "$(INTDIR)\CreditsDlg.obj"
	-@erase "$(INTDIR)\CreditsDlg.sbr"
	-@erase "$(INTDIR)\GaussEliminationDlg.obj"
	-@erase "$(INTDIR)\GaussEliminationDlg.sbr"
	-@erase "$(INTDIR)\GetXofYDlg.obj"
	-@erase "$(INTDIR)\GetXofYDlg.sbr"
	-@erase "$(INTDIR)\GradientDlg.obj"
	-@erase "$(INTDIR)\GradientDlg.sbr"
	-@erase "$(INTDIR)\GrafMath.obj"
	-@erase "$(INTDIR)\GrafMath.pch"
	-@erase "$(INTDIR)\GrafMath.res"
	-@erase "$(INTDIR)\GrafMath.sbr"
	-@erase "$(INTDIR)\GrafMathDlg.obj"
	-@erase "$(INTDIR)\GrafMathDlg.sbr"
	-@erase "$(INTDIR)\HelpDialog.obj"
	-@erase "$(INTDIR)\HelpDialog.sbr"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\HyperLink.sbr"
	-@erase "$(INTDIR)\InputFunctionDlg.obj"
	-@erase "$(INTDIR)\InputFunctionDlg.sbr"
	-@erase "$(INTDIR)\IntegralDlg.obj"
	-@erase "$(INTDIR)\IntegralDlg.sbr"
	-@erase "$(INTDIR)\LengthTwoPoints.obj"
	-@erase "$(INTDIR)\LengthTwoPoints.sbr"
	-@erase "$(INTDIR)\MonotonyDlg.obj"
	-@erase "$(INTDIR)\MonotonyDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\TangentDlg.obj"
	-@erase "$(INTDIR)\TangentDlg.sbr"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\ThemeHelperST.sbr"
	-@erase "$(INTDIR)\ValueTableDlg.obj"
	-@erase "$(INTDIR)\ValueTableDlg.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPStyleButtonST.sbr"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(INTDIR)\XPTabCtrl.sbr"
	-@erase "$(OUTDIR)\GrafMath.bsc"
	-@erase "$(OUTDIR)\GrafMath.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\GrafMath.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GrafMath.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AxisOptionsDlg.sbr" \
	"$(INTDIR)\BCMenu.sbr" \
	"$(INTDIR)\BtnST.sbr" \
	"$(INTDIR)\CreditsDlg.sbr" \
	"$(INTDIR)\GaussEliminationDlg.sbr" \
	"$(INTDIR)\GetXofYDlg.sbr" \
	"$(INTDIR)\GradientDlg.sbr" \
	"$(INTDIR)\GrafMath.sbr" \
	"$(INTDIR)\GrafMathDlg.sbr" \
	"$(INTDIR)\HelpDialog.sbr" \
	"$(INTDIR)\HyperLink.sbr" \
	"$(INTDIR)\InputFunctionDlg.sbr" \
	"$(INTDIR)\IntegralDlg.sbr" \
	"$(INTDIR)\MonotonyDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\TangentDlg.sbr" \
	"$(INTDIR)\ThemeHelperST.sbr" \
	"$(INTDIR)\ValueTableDlg.sbr" \
	"$(INTDIR)\XPStyleButtonST.sbr" \
	"$(INTDIR)\XPTabCtrl.sbr" \
	"$(INTDIR)\LengthTwoPoints.sbr"

"$(OUTDIR)\GrafMath.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\GrafMath.pdb" /machine:I386 /out:"$(OUTDIR)\GrafMath.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AxisOptionsDlg.obj" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\CreditsDlg.obj" \
	"$(INTDIR)\GaussEliminationDlg.obj" \
	"$(INTDIR)\GetXofYDlg.obj" \
	"$(INTDIR)\GradientDlg.obj" \
	"$(INTDIR)\GrafMath.obj" \
	"$(INTDIR)\GrafMathDlg.obj" \
	"$(INTDIR)\HelpDialog.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\InputFunctionDlg.obj" \
	"$(INTDIR)\IntegralDlg.obj" \
	"$(INTDIR)\MonotonyDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TangentDlg.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\ValueTableDlg.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\GrafMath.res" \
	"$(INTDIR)\LengthTwoPoints.obj"

"$(OUTDIR)\GrafMath.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\GrafMath.exe"


CLEAN :
	-@erase "$(INTDIR)\AxisOptionsDlg.obj"
	-@erase "$(INTDIR)\BCMenu.obj"
	-@erase "$(INTDIR)\BtnST.obj"
	-@erase "$(INTDIR)\CreditsDlg.obj"
	-@erase "$(INTDIR)\GaussEliminationDlg.obj"
	-@erase "$(INTDIR)\GetXofYDlg.obj"
	-@erase "$(INTDIR)\GradientDlg.obj"
	-@erase "$(INTDIR)\GrafMath.obj"
	-@erase "$(INTDIR)\GrafMath.pch"
	-@erase "$(INTDIR)\GrafMath.res"
	-@erase "$(INTDIR)\GrafMathDlg.obj"
	-@erase "$(INTDIR)\HelpDialog.obj"
	-@erase "$(INTDIR)\HyperLink.obj"
	-@erase "$(INTDIR)\InputFunctionDlg.obj"
	-@erase "$(INTDIR)\IntegralDlg.obj"
	-@erase "$(INTDIR)\LengthTwoPoints.obj"
	-@erase "$(INTDIR)\MonotonyDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TangentDlg.obj"
	-@erase "$(INTDIR)\ThemeHelperST.obj"
	-@erase "$(INTDIR)\ValueTableDlg.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XPStyleButtonST.obj"
	-@erase "$(INTDIR)\XPTabCtrl.obj"
	-@erase "$(OUTDIR)\GrafMath.exe"
	-@erase "$(OUTDIR)\GrafMath.ilk"
	-@erase "$(OUTDIR)\GrafMath.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\GrafMath.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x407 /fo"$(INTDIR)\GrafMath.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\GrafMath.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\GrafMath.pdb" /debug /machine:I386 /out:"$(OUTDIR)\GrafMath.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AxisOptionsDlg.obj" \
	"$(INTDIR)\BCMenu.obj" \
	"$(INTDIR)\BtnST.obj" \
	"$(INTDIR)\CreditsDlg.obj" \
	"$(INTDIR)\GaussEliminationDlg.obj" \
	"$(INTDIR)\GetXofYDlg.obj" \
	"$(INTDIR)\GradientDlg.obj" \
	"$(INTDIR)\GrafMath.obj" \
	"$(INTDIR)\GrafMathDlg.obj" \
	"$(INTDIR)\HelpDialog.obj" \
	"$(INTDIR)\HyperLink.obj" \
	"$(INTDIR)\InputFunctionDlg.obj" \
	"$(INTDIR)\IntegralDlg.obj" \
	"$(INTDIR)\MonotonyDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TangentDlg.obj" \
	"$(INTDIR)\ThemeHelperST.obj" \
	"$(INTDIR)\ValueTableDlg.obj" \
	"$(INTDIR)\XPStyleButtonST.obj" \
	"$(INTDIR)\XPTabCtrl.obj" \
	"$(INTDIR)\GrafMath.res" \
	"$(INTDIR)\LengthTwoPoints.obj"

"$(OUTDIR)\GrafMath.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("GrafMath.dep")
!INCLUDE "GrafMath.dep"
!ELSE 
!MESSAGE Warning: cannot find "GrafMath.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "GrafMath - Win32 Release" || "$(CFG)" == "GrafMath - Win32 Debug"
SOURCE=.\AxisOptionsDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\AxisOptionsDlg.obj"	"$(INTDIR)\AxisOptionsDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\AxisOptionsDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\BCMenu.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\BCMenu.obj"	"$(INTDIR)\BCMenu.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\BCMenu.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\BtnST.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\BtnST.obj"	"$(INTDIR)\BtnST.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\BtnST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\CreditsDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\CreditsDlg.obj"	"$(INTDIR)\CreditsDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\CreditsDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\GaussEliminationDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\GaussEliminationDlg.obj"	"$(INTDIR)\GaussEliminationDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\GaussEliminationDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\GetXofYDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\GetXofYDlg.obj"	"$(INTDIR)\GetXofYDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\GetXofYDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\GradientDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\GradientDlg.obj"	"$(INTDIR)\GradientDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\GradientDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\GrafMath.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\GrafMath.obj"	"$(INTDIR)\GrafMath.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\GrafMath.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\GrafMath.rc

"$(INTDIR)\GrafMath.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\GrafMathDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\GrafMathDlg.obj"	"$(INTDIR)\GrafMathDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\GrafMathDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\HelpDialog.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\HelpDialog.obj"	"$(INTDIR)\HelpDialog.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\HelpDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\HyperLink.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\HyperLink.obj"	"$(INTDIR)\HyperLink.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\HyperLink.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\InputFunctionDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\InputFunctionDlg.obj"	"$(INTDIR)\InputFunctionDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\InputFunctionDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\IntegralDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\IntegralDlg.obj"	"$(INTDIR)\IntegralDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\IntegralDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\LengthTwoPoints.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\LengthTwoPoints.obj"	"$(INTDIR)\LengthTwoPoints.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\LengthTwoPoints.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\MonotonyDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\MonotonyDlg.obj"	"$(INTDIR)\MonotonyDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\MonotonyDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\GrafMath.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\GrafMath.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\GrafMath.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\GrafMath.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TangentDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\TangentDlg.obj"	"$(INTDIR)\TangentDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\TangentDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\ThemeHelperST.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\ThemeHelperST.obj"	"$(INTDIR)\ThemeHelperST.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\ThemeHelperST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\ValueTableDlg.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\ValueTableDlg.obj"	"$(INTDIR)\ValueTableDlg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\ValueTableDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\XPStyleButtonST.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\XPStyleButtonST.obj"	"$(INTDIR)\XPStyleButtonST.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\XPStyleButtonST.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 

SOURCE=.\XPTabCtrl.cpp

!IF  "$(CFG)" == "GrafMath - Win32 Release"


"$(INTDIR)\XPTabCtrl.obj"	"$(INTDIR)\XPTabCtrl.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "GrafMath - Win32 Debug"


"$(INTDIR)\XPTabCtrl.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\GrafMath.pch"


!ENDIF 


!ENDIF 

