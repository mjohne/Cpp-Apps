// DlgProxy.h: Headerdatei
//

#pragma once

class CCXICompressorDlg;


// CCXICompressorDlgAutoProxy Befehlsziel

class CCXICompressorDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CCXICompressorDlgAutoProxy)

	CCXICompressorDlgAutoProxy();           // Dynamische Erstellung verwendet gesch�tzten Konstruktor

// Attribute
public:
	CCXICompressorDlg* m_pDialog;

// Operationen
public:

// �berschreibungen
	public:
	virtual void OnFinalRelease();

// Implementierung
protected:
	virtual ~CCXICompressorDlgAutoProxy();

	// Generierte Funktionen f�r die Meldungstabellen

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CCXICompressorDlgAutoProxy)

	// Generierte OLE-Dispatchzuordnungsfunktionen

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

