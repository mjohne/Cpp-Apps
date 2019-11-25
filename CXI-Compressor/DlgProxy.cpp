// DlgProxy.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "CXI-Compressor.h"
#include "DlgProxy.h"
#include "CXI-CompressorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCXICompressorDlgAutoProxy

IMPLEMENT_DYNCREATE(CCXICompressorDlgAutoProxy, CCmdTarget)

CCXICompressorDlgAutoProxy::CCXICompressorDlgAutoProxy()
{
	EnableAutomation();
	
	// Um die Ausführung der Anwendung fortzusetzen, solange ein Automatisierungsobjekt
	//	aktiv ist, ruft der Konstruktor AfxOleLockApp auf.
	AfxOleLockApp();

	// Greifen Sie über den Hauptfensterzeiger der Anwendung auf das
	//  Dialogfeld zu. Setzen Sie den internen Zeiger des Proxy
	//  auf das Dialogfeld und den Gegenzeiger (Back Pointer) des Dialogfelds 
	//  auf diesen Proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CCXICompressorDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CCXICompressorDlg)))
		{
			m_pDialog = reinterpret_cast<CCXICompressorDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CCXICompressorDlgAutoProxy::~CCXICompressorDlgAutoProxy()
{
	// Um die Anwendung zu beenden, sobald alle mit Automatisierung erstellten
	// Objekte freigegeben sind, ruft der Destruktor AfxOleUnlockApp auf.
	//  Dies zerstört unter anderem das Hauptdialogfeld.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CCXICompressorDlgAutoProxy::OnFinalRelease()
{
	// Wird der letzte Verweis auf ein Automatisierungsobjekt freigegeben,
	// wird OnFinalRelease aufgerufen. Die Basisklasse löscht das Objekt
	// automatisch. Fügen Sie zusätzlichen Bereinigungscode für Ihr Objekt
	// hinzu, bevor Sie die Basisklasse aufrufen.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CCXICompressorDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCXICompressorDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Hinweis: Wir stellen Unterstützung für IID_ICXICompressor zur Verfügung, um typsicheres Binden 
//  von VBA zu unterstützen. Diese IID muss mit der GUID übereinstimmen, die bei der 
//  Disp-Schnittstelle in der .IDL-Datei angegeben ist.

// {E576B3FA-26A8-4403-A39B-A62179D5E1AA}
static const IID IID_ICXICompressor =
{ 0xE576B3FA, 0x26A8, 0x4403, { 0xA3, 0x9B, 0xA6, 0x21, 0x79, 0xD5, 0xE1, 0xAA } };

BEGIN_INTERFACE_MAP(CCXICompressorDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CCXICompressorDlgAutoProxy, IID_ICXICompressor, Dispatch)
END_INTERFACE_MAP()

// Das IMPLEMENT_OLECREATE2-Makro wird in StdAfx.h des Projekts definiert
// {716F7118-EA54-4474-A134-CC153DA99D6E}
IMPLEMENT_OLECREATE2(CCXICompressorDlgAutoProxy, "CXICompressor.Application", 0x716f7118, 0xea54, 0x4474, 0xa1, 0x34, 0xcc, 0x15, 0x3d, 0xa9, 0x9d, 0x6e)


// CCXICompressorDlgAutoProxy Meldungshandler
