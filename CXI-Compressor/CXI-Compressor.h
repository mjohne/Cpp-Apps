// CXI-Compressor.h : Hauptheaderdatei f�r die CXI-Compressor-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error 'stdafx.h' muss vor dieser Datei in PCH eingeschlossen werden.
#endif

#include "resource.h"		// Hauptsymbole


// CCXICompressorApp:
// Siehe CXI-Compressor.cpp f�r die Implementierung dieser Klasse
//

class CCXICompressorApp : public CWinApp
{
public:
	CCXICompressorApp();

// �berschreibungen
	public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CCXICompressorApp theApp;
