// CXI-Compressor.cpp : Definiert das Klassenverhalten f�r die Anwendung.
//

#include "stdafx.h"
#include "CXI-Compressor.h"
#include "CXI-CompressorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCXICompressorApp

BEGIN_MESSAGE_MAP(CCXICompressorApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCXICompressorApp-Erstellung

CCXICompressorApp::CCXICompressorApp()
{
	// TODO: Hier Code zur Konstruktion einf�gen
	// Alle wichtigen Initialisierungen in InitInstance positionieren
}


// Das einzige CCXICompressorApp-Objekt

CCXICompressorApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x28EA988E, 0x540F, 0x4771, { 0xB9, 0x6E, 0x4F, 0xA3, 0xAA, 0x40, 0xE5, 0x6D } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CCXICompressorApp Initialisierung

BOOL CCXICompressorApp::InitInstance()
{
	// InitCommonControls() ist f�r Windows XP erforderlich, wenn ein Anwendungsmanifest
	// die Verwendung von ComCtl32.dll Version 6 oder h�her zum Aktivieren
	// von visuellen Stilen angibt. Ansonsten treten beim Erstellen von Fenstern Fehler auf.
	InitCommonControls();

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// OLE-Bibliotheken initialisieren
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standardinitialisierung
	// Wenn Sie diese Features nicht verwenden und die Gr��e
	// der ausf�hrbaren Datei verringern m�chten, entfernen Sie
	// die nicht erforderlichen Initialisierungsroutinen.
	// �ndern Sie den Registrierungsschl�ssel unter dem Ihre Einstellungen gespeichert sind.
	// TODO: �ndern Sie diese Zeichenfolge entsprechend,
	// z.B. zum Namen Ihrer Firma oder Organisation.
	SetRegistryKey(_T("Vom lokalen Anwendungs-Assistenten generierte Anwendungen"));
	// Befehlszeile f�r die Automatisierung oder Registrierung bzw. das Aufheben der Registrierung von Optionen verarbeiten.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Anwendung wurde mit /Embedding oder /Automation gestartet.
	// F�hren Sie die Anwendung als Automatisierungsserver aus.
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Klassenfactorys �ber CoRegisterClassObject() registrieren.
		COleTemplateServer::RegisterAll();
	}
	// Anwendung wurde mit /Unregserver oder /Unregister gestartet. Entfernen
	// Sie die Eintr�ge aus der Registrierung.
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		COleObjectFactory::UpdateRegistryAll(FALSE);
		AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor);
		return FALSE;
	}
	// Anwendung wurde als Standalone oder mit anderen Optionen gestartet (z.B. /Register
	// oder /Regserver). Aktualisieren Sie die Registrierungseintr�ge, einschl. der Typenbibliothek.
	else
	{
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid);
		if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
			return FALSE;
	}

	CCXICompressorDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: F�gen Sie hier Code ein, um das Schlie�en des
		//  Dialogfelds �ber OK zu steuern
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: F�gen Sie hier Code ein, um das Schlie�en des
		//  Dialogfelds �ber "Abbrechen" zu steuern
	}

	// Da das Dialogfeld geschlossen wurde, FALSE zur�ckliefern, so dass wir die
	//  Anwendung verlassen, anstatt das Nachrichtensystem der Anwendung zu starten.
	return FALSE;
}
