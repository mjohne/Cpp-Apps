@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by WORDSTAT.HPJ. >"hlp\WordStat.hm"
echo. >>"hlp\WordStat.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\WordStat.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\WordStat.hm"
echo. >>"hlp\WordStat.hm"
echo // Prompts (IDP_*) >>"hlp\WordStat.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\WordStat.hm"
echo. >>"hlp\WordStat.hm"
echo // Resources (IDR_*) >>"hlp\WordStat.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\WordStat.hm"
echo. >>"hlp\WordStat.hm"
echo // Dialogs (IDD_*) >>"hlp\WordStat.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\WordStat.hm"
echo. >>"hlp\WordStat.hm"
echo // Frame Controls (IDW_*) >>"hlp\WordStat.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\WordStat.hm"
REM -- Make help for Project WORDSTAT


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\WordStat.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\WordStat.hlp" goto :Error
if not exist "hlp\WordStat.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\WordStat.hlp" Debug
if exist Debug\nul copy "hlp\WordStat.cnt" Debug
if exist Release\nul copy "hlp\WordStat.hlp" Release
if exist Release\nul copy "hlp\WordStat.cnt" Release
echo.
goto :done

:Error
echo hlp\WordStat.hpj(1) : error: Problem encountered creating help file

:done
echo.
