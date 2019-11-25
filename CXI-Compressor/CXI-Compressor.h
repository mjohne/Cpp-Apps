// CXI-Compressor.h : Hauptheaderdatei für die CXI-Compressor-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error 'stdafx.h' muss vor dieser Datei in PCH eingeschlossen werden.
#endif

#include "resource.h"		// Hauptsymbole


// CCXICompressorApp:
// Siehe CXI-Compressor.cpp für die Implementierung dieser Klasse
//

class CCXICompressorApp : public CWinApp
{
public:
	CCXICompressorApp();

// Überschreibungen
	public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CCXICompressorApp theApp;
