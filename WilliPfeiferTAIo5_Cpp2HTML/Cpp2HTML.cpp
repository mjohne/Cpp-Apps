// Cpp2HTML.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include "Cpp2HTML.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Willi Pfeifer | TAIo5 | pp-Pruefung_Tag2

CWinApp theApp;

using namespace std;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
////////////////////////////////////////////////////////////////////////////
// FUNKTIONENEN // DEKLARATION //
////////////////////////////////////////////////////////////////////////////

// prüft, ob die nötigen parameter übergeben worden sind
bool CheckParameter(int nAnzahl, TCHAR* param[]);

// prüft, ob sich die CppDatei öffnen lässt
bool OpenCppFile(CString csCppFileName, CStdioFile* cppFile);

// öffnet die OperatorenDatei & die SchluesselwoerterDatei, & speichert sie in CArray
bool Initialize(CArray<CString,CString>* caOperator, CArray<CString,CString>* caKeyword);

// erzeugt die HTML datei. Dateiname wird von CppFile genommen und ".cpp" durch ".html" ersetzt
bool OpenHtmlFile(CString csCppFile, CStdioFile* htmlFile);

// erzeugt den htmlCode in die htmlDatei, gibt die anzahl der zeilen zurück
int GenerateHtml(CStdioFile* cppFile, CStdioFile* htmlFile, CArray<CString,CString>* caOperator, CArray<CString,CString>* caKeyword);

// gibt den fertigen Header mit dem HtmlDateiNamen im title-Tag
CString Header(CString csHtmlFileName);

// inline // gibt 4 Leerzeichen aus für den Tab
CString Tab() { return "&nbsp;&nbsp;&nbsp;&nbsp;"; };

// prüft, ob der übergebene String ein Operator ist
bool IsOperator(CString csText, CArray<CString,CString>* caOperator);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
////////////////////////////////////////////////////////////////////////////
// HAUPTPROGRAMM //
////////////////////////////////////////////////////////////////////////////
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		bool						bResult			= false;		// KontrollVariable
		CArray<CString,CString>		caOperator;						// für Operatoren
		CArray<CString,CString>		caKeyword;						// für Schlüsselwörter
		CStdioFile					cppFile;						// cppDatei
		CStdioFile					htmlFile;						// htmlDatei
		cout << endl << "..::Cpp2HTML Version 1.0::.." << endl;
		
		// Parameter prüfen
		if ( CheckParameter(argc, argv) ) {
			// wenn parameter ok, dann die dateien öffnen
			if ( OpenCppFile(argv[1], &cppFile)) {
				// öffnet Operatoren- & Key-Datei
				if ( Initialize(&caOperator, &caKeyword) ) {
					// HTLM datei zum schreiben öffnen/erstellen
					if ( OpenHtmlFile(argv[1], &htmlFile) ) {
						
						
						// generiert den htmlCode in die htmlDatei
						int nZeilen = GenerateHtml(&cppFile, & htmlFile, &caOperator, &caKeyword);
						if (nZeilen != 0) {
							cout << endl << nZeilen << " Zeilen generiert" << endl;
						} else {
							cout << endl << "Error: !Fehler beim generieren des HTML-Codes!" << endl;
							cout << endl << "Wahrscheinlich ist die Datei leer!" << endl;
						}


					} else {
						cout << endl << "Error: !HTML-Dateie konnte nicht geoeffnet/erstellt werden!" << endl;
					}
				} else {
					cout << endl << "Error: !Operatoren- oder Schluesselwoerter-Dateie konnte nicht geoeffnet werden!" << endl;
				}
			} else {
				cout << endl << "Error: !CppDatei konnte nicht geoeffnet werden!" << endl;
			}
		} else {
			cout << endl << "Error: !Anzahl der Parameter falsch!" << endl;
		}
	
		
		cout << endl;

	}

	return nRetCode;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

////////////////////////////////////////////////////////////////////////////
// FUNKTIONEN // IMPLEMENTATION //
////////////////////////////////////////////////////////////////////////////
// überprüft Parameter
bool CheckParameter(int nAnzahl, TCHAR* param[]) {
	// anzahl der parameter prüfen
	if (nAnzahl != 2) {
		return false;
	}
	return true;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// öffnet die CppDatei
// wenn sich die cpp Datei nicht öffnen lässt	--> return false
// wenn alles ok,								--> return true
bool OpenCppFile(CString csCppFileName, CStdioFile* cppFile)
{
	bool		bResult			= true;			// KontrollVariable

	if (!cppFile->Open(csCppFileName, CFile::modeRead | CFile::shareDenyNone) ) {
		bResult = false;
	}
	return bResult;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// öffnet die OperatorenDatei & die SchluesselwoerterDatei, & speichert sie in CArray
// liest beide dateien aus
// speichert die Operatoren & Schluesselwörter in je ein CArray, welches übergeben wird
// die Dateiname stehen in der StdAfx.h als Konstanten (OPERATOR_FILE_NAME & KEYWORD_FILE_NAME)
// in die Resource.h ging es trotz des includierens nicht, also -> stdafx.h
bool Initialize(CArray<CString,CString>* caOperator, CArray<CString,CString>* caKeyword) {
	
	bool		bResult			= true;			// KontrollVariable
	CString		csLine			= "";			// buffer
	CStdioFile	operatorFile;
	CStdioFile	keywordFile;

	if (! operatorFile.Open(OPERATOR_FILE_NAME, CFile::modeRead | CFile::shareDenyNone) )
		return false;
	if (! keywordFile.Open(KEYWORD_FILE_NAME, CFile::modeRead | CFile::shareDenyNone) )
		return false;
	
	// erst alle Elemente löschen
	caOperator->RemoveAll();
	caKeyword->RemoveAll();

	// erst die Operatoren auslesen & ins Array packen
	while ( operatorFile.ReadString(csLine) && !csLine.IsEmpty() ) {
		caOperator->Add(csLine);
	}
	operatorFile.Close();

	// dann die Schluesselwörter auslesen
	while ( keywordFile.ReadString(csLine) && !csLine.IsEmpty() ) {
		caKeyword->Add(csLine);
	}
	keywordFile.Close();	

	return bResult;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// erzeugt die HTML datei. Dateiname wird von CppFile genommen und ".cpp" durch ".htm" ersetzt
bool OpenHtmlFile(CString csCppFile, CStdioFile* htmlFile) {
	bool		bResult			= false;			// KontrollVariable
	CString		csHtmlFileName	= "";
	if ( !csCppFile.IsEmpty() ) {
		int nPos = csCppFile.ReverseFind('.');
		// wenn punkt überhaupt gefunden
		if(nPos > -1) {
			int nLength = csCppFile.GetLength();
			int nCount = nLength - nPos;
			// cpp extension löschen
			csCppFile.Delete(nPos, nCount);
			// html extension dranhängen
			csCppFile += ".html";

			csHtmlFileName = csCppFile;
			bResult = true;
			// wenn nicht ertsellt werden konnte, dann false und raus aus fkt
			if ( !htmlFile->Open(csHtmlFileName, CFile::modeCreate | CFile::modeWrite) )
				return false;
		}
	}
	return bResult;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// Liest die cppDatei aus.
// Generiert htmlCode in die htmlDatei
int GenerateHtml(CStdioFile* cppFile, CStdioFile* htmlFile, CArray<CString,CString>* caOperator, CArray<CString,CString>* caKeyword) {

	CString			csLine			= "";				// Zeilenpuffer
	CString			csTemp			= "";				// TempVar
	CString			csBuf			= "";				// puffer
	CString			csHtml			= "";				// zwischenspeicher für die htmlDatei
	CString			csFontRed		= "<font color=\"red\">";
	CString			csFontGreen		= "<font color=\"green\">";
	CString			csFontBlue		= "<font color=\"blue\">";
	CString			csEndFont		= "</font>";
	CString			csSpace			= "&nbsp;";			// Leerzeichen
	CString			csOut			= "";				// was in die html geschrieben wird
	int				nStrLength		= 0;				// StringLänge von csLine
	int				nPos			= 0;				// Positionsmerker
	int				nA				= 0;				// Zähler
	int				nZeilen			= 0;				// Zeilenzähler für die rückgabe
	
	
	// htmlHeader schreiben
	csHtml = Header( htmlFile->GetFileName() );
	htmlFile->WriteString(csHtml);
	csHtml.Empty();
	
	// modifiziertes Listing schreiben
	cout << endl;
	while ( cppFile->ReadString(csLine) ) {
		nZeilen++;
		// pro 10 Zeilen einen Punkt als StatusBalken anzeigen
		if (nZeilen%10 == 0)
			cout << ".";

		nStrLength = csLine.GetLength();

		csTemp.Empty(); // string vorher löschen
		nA = 0;
		while(nA<nStrLength) {
			// wenn /*Kommentar*/, dann wurden die stellen schon gelesen, also + nCount
			csBuf = csLine[nA];
					
			if (csBuf == " ") {
				csHtml += csSpace;
			} else {
				if ( csBuf == "/" ) {
					// das nächste Zeichen holen. denn es könnte sein, dass "/*" in cpp steht
					// VORSICHT - LETZTER BUCHHSTABE IN DER ZEILE, deswegen prüfen
					if (nA<nStrLength-1) {
						csTemp = csLine[nA+1];
									
						if (csTemp == "*" ) {
							// Kommentar anfang
							// was schon in csHtml reingeschrieben wurde, aus csLine löschen
							csLine.Delete(0,nA);
							csHtml += csFontGreen;
							int nL = csLine.GetLength();
							csBuf.Empty();
							for (int nB=0; nB<nL; nB++) {
								csTemp = csLine[nB];
								// wenn Leerzeichen
								if (csTemp == " ")
									csHtml += csSpace;
								else
									csHtml += csLine[nB];								
								csTemp = csLine.Mid(nB,2);
								if (csTemp == "*/") {
									csHtml += csTemp + csEndFont;
									// was schon gruen ist, aus csLine löschen
									csLine.Delete(0,nB+2);
									nStrLength = csLine.GetLength();
									nA = -1;
									break;
								}
							}
							
						} else if (csTemp == "/") {
							// kommentar ganze zeile
							csLine.Delete(0,nA);// vielleich war etwas text davor, deswegen bis dahin löschen
							nStrLength = csLine.GetLength();
							csHtml += csFontGreen + csLine + csEndFont;
							break;
						}
					} else {
						// wenn z.b. am ende ein semikolon ist
						// Operand
						csHtml += csFontRed + csLine[nA] + csEndFont;
					}

				} else if (IsOperator(csBuf, caOperator) ) {
					// Operand
					// wenn < oder >
					csTemp = csLine[nA];
					if (csTemp == "<") {
						csTemp = "&lt;";
					} else if (csTemp == ">") {
						csTemp = "&gt;";
					} else {
						csTemp = csLine[nA];
					}
					csHtml += csFontRed + csTemp + csEndFont;
				} else {
					// normaler Text
					csHtml += csBuf;
				}
			}
			nA++;
		}

		csHtml += "<br>\n";

		// alles zwischenspeichern
		csOut += csHtml;
		csHtml.Empty();		

	}



	// Schlüsselwörter mit rot markieren
	int nSize = caKeyword->GetSize();
	for (int nC=0; nC<nSize; nC++) {
		csTemp = caKeyword->GetAt(nC);
		csOut.Replace(csTemp, (csFontBlue+csTemp+csEndFont));
	}

	// in die Datei schreiben
	htmlFile->WriteString(csOut);
	

	// htmlAbschluss schreiben
	csHtml.Empty();
	csHtml = "</body>\n</html>";
	htmlFile->WriteString(csHtml);
	
	// beide Dateien schließen
	cppFile->Close();
	htmlFile->Close();

	return nZeilen;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// gibt den fertigen Header mit dem HtmlDateiNamen im title-Tag
CString Header(CString csHtmlFileName) {
	CString csHtml = "<head>\n<body>\n";
	csHtml += "<title>";
	csHtml += csHtmlFileName;
	csHtml += "</title>\n";
	csHtml += "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\"\n";
	csHtml += "</head>\n";
	csHtml += "<body bgcolor=\"#FFFFFF\" text=\"#000000\"><font face=Courier>\n";
	return csHtml;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// prüft, ob der übergebene String ein Operator ist
bool IsOperator(CString csText, CArray<CString,CString>* caOperator) {
	CString		csTemp	= "";
	int			nSize	= caOperator->GetSize();

	for (int nA=0; nA<nSize; nA++) {
		csTemp = caOperator->GetAt(nA);
		if ( csText == csTemp )
			return true;
	}
	
	return false;}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
