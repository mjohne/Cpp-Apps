// WordStatDoc.cpp : implementation of the CWordStatDoc class
//

#include "stdafx.h"
#include "windows.h"
#include "WordStat.h"
#include "WordStatDoc.h"

#include "LimitXDlg.h" // Wird ben�tigt, um das Dialog-Fenster zur Anzeigenbegrenzung der X-Achse anzuzeigen

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordStatDoc

IMPLEMENT_DYNCREATE(CWordStatDoc, CDocument)

BEGIN_MESSAGE_MAP(CWordStatDoc, CDocument)
	//{{AFX_MSG_MAP(CWordStatDoc)
	ON_COMMAND(ID_BUTTON_KVALUE, OnButtonKvalue)
	ON_COMMAND(ID_BUTTON_WORDLEN_SEQUENCE, OnButtonWordlenSequence)
	ON_COMMAND(ID_BUTTON_WORDDIAG_LENFREQ, OnButtonWorddiagLenfreq)
	ON_COMMAND(ID_BUTTON_WORDLENDIAG_SORTFREQ, OnButtonWordlendiagSortfreq)
	ON_COMMAND(ID_BUTTON_WORDLENDIAG_SORTPOS, OnButtonWordlendiagSortpos)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CWordStatDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CWordStatDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IWordStat to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.
// {49CD1351-5FB5-416A-9E18-A3990CB2E5C5}
static const IID IID_IWordStat =
{ 0x49cd1351, 0x5fb5, 0x416a, { 0x9e, 0x18, 0xa3, 0x99, 0xc, 0xb2, 0xe5, 0xc5 } };

BEGIN_INTERFACE_MAP(CWordStatDoc, CDocument)
	INTERFACE_PART(CWordStatDoc, IID_IWordStat, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordStatDoc construction/destruction

CWordStatDoc::CWordStatDoc()
{
	// TODO: add one-time construction code here
  ProcessState = 0;
	EnableAutomation();
	AfxOleLockApp();
}

CWordStatDoc::~CWordStatDoc()
{
	AfxOleUnlockApp();
}

BOOL CWordStatDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CWordStatDoc serialization

void CWordStatDoc::Serialize(CArchive& ar)
{
	if (ar.IsLoading())
	{
		// Hier erfolgen s�mtliche Ausf�hrungen, die beim Lesen einer Datei get�tigt werden.
    
    const char Space = ' '; // Variable, die ein Leerzeichen repr�sentiert
    const char Characters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'};
                            // Ein Array mit s�mtlichen Zeichen, die von WordStat als "Buchstaben" interpretiert werden

    LONG // diverse ben�tige Variablen als Z�hler, z. B. Schleifenz�hler
      i = 0,
      j = 0,
      n = 0,
      a = 0;

    CString
      strLine = "", // Zeichenkette zum Einlesen der Zeilen einer Eingabedatei
      strTemp = "", // tempor�re Zeichenkette
      strWord = ""; // Zeichenkette, das ein ermitteltes literisches Wort repr�sentiert

    bool
      isLastLetter = false,  // stellt fest, ob das zuletzt gelesene Zeichen ein Buchstabe war
      isLastSpace = false,   // stellt fest, ob das zuletzt gelesene Zeichen ein Leerzeichen war
      isLastWord = false,    // stellt fest, ob die letzte Aktion ein Ermitteln eines Wortes war
      wasFirstRead = false,  // stellt fest, ob das ermitteltes Wort �berhaupt das erste Wort eines Textes ist
      wasFound = false;      // stellt fest, ob das Wort in der Worttabelle schon vorhanden ist

    Letters = 0;     // Anzahl der ermittelten Buchstaben
    Spaces = 0;      // Anzahl der ermittelten Leerzeichen
    Words = 0;       // Anzahl der ermittelten W�rter
    nWordLenMax = 0; // maximale Wortl�nge

    SWordTable WordTable,WordTable2,WordTable3;
    
    m_WordTable.RemoveAll(); // Der komplette Inhalt der Worttabelle wird "entleert". Dies ist n�tigt,
                             // falls man mehrere Textdateien nacheinander analysiert
    
    ProcessState = 1; // Prozessstatus = 1: Die Eingabedatei wird gelesen.
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
		while(ar.ReadString(strLine)) // Es wird solange gelesen, bis keine Zeile in der Eingabe-
    {                             // datei mehr vorhanden ist.
      strWord = "";
      isLastWord = false;
      for(i = 0; i < strLine.GetLength(); i++) // Es wird mittels einer Z�hlerschleife alle
      {                                        // der gelesenen Zeile analysiert
        if(strLine.GetLength() >= 0) // wenn keine leere Zeile vorliegt
        {
          strTemp = strLine.GetAt(i); // Die einzelnen Zeichen der gelesenen Zeile werden extrahiert...
          strTemp.MakeLower();        // ... und in Kleinbuchstaben umgewandelt.
          // Es wird nun versucht, aus den bereits gelesenen Zeichen ein Wort zu bilden.
          for(n = 0; n < (sizeof Characters / sizeof Characters[0]); n++) // Hierbei wird das gelesene Zeichen mit allen
          {                                                               // unterst�tzten Zeichen von WordStat verglichen
            if(Characters[n] == strTemp) // wenn gelesenes Zeichen = unterst�tztes Zeichen = g�ltiges Zeichen
            {
              isLastLetter = true;
              isLastSpace = false;
              Letters++;
              strWord += strTemp; // Die g�ltigen Zeichen werden zu einem Wort gebildet.
            }
          }
          if(i == strLine.GetLength()-1) { Words++; } // Wenn das gelesene Zeichen das letzte Zeichen aus einer Zeile
                                                      // ist, dann wird ein Wort gebildet.
          if(strTemp == Space || (isLastWord && strWord != "")) // wenn gelesenes Zeichen = Leerzeile oder
          {                                                     // zuletzt ein Wort gebildet
            if(isLastLetter = true) // Wenn das gelesene Zeichen ein g�ltiges Zeichen ist, ...
            {
              Words++;              // ... dann wird ein Wort gebildet.
              if(wasFirstRead == false) // Wenn das gebildete Wort das erste Wort des jeweiligen Text �berhuapt ist, ...
              {                         // ... dann wird das Wort unwiederbringlich in die Worttabelle eingetragen.
                WordTable.WordFrequency = 1;
                WordTable.WordString = strWord;
                WordTable.WordLength = strWord.GetLength();
                // Zus�tzlich wird die maximale Wortl�nge bestimmt. Sie wird sp�ter als
                // Ausgangswert f�r einige Diagramme ben�tigt.
                if(WordTable.WordLength > nWordLenMax) { nWordLenMax = WordTable.WordLength; }
                m_WordTable.Add(WordTable);
                wasFirstRead = true;
              } else {
                // Falls das gebeildete Wort nicht mehr das erste Wort eines Textes ist,
                // dann wird ermittelt, ob Wort in der Worttabelle vorkommt.
                for(a = 0; a < m_WordTable.GetSize(); a++)
                {
                  WordTable = m_WordTable.GetAt(a);                    
                  if(WordTable.WordString == strWord)
                  {
                    wasFound = true; // Hier wird nun festgestellt, ob das Wort in der Worttabelle vorhanden ist.
                    break;
                  }
                }
                if(wasFound == false) // Wenn kein Wort in der Worttabelle vorhanden, ...
                {                     // ... dann wird das gebildete Wort hinzuf�gt, ...
                  if(strWord != "")
                  {
                    WordTable.WordFrequency = 1;
                    WordTable.WordString = strWord;
                    WordTable.WordLength = strWord.GetLength();
                    // Zus�tzlich wird die maximale Wortl�nge bestimmt. Sie wird sp�ter als
                    // Ausgangswert f�r einige Diagramme ben�tigt.
                    if(WordTable.WordLength > nWordLenMax) { nWordLenMax = WordTable.WordLength; }
                    m_WordTable.Add(WordTable);
                  }
                } else { // ... ansonsten wir nur die H�ufigkeit der Wortes in der Worttabelle aktualisiert.
                  WordTable = m_WordTable.GetAt(a);                    
                  if(WordTable.WordString == strWord)
                  {
                    WordTable.WordFrequency++;
                    m_WordTable.SetAt(a,WordTable);
                  }
                }
                wasFound = false;
              }
              strWord = "";
            }              
            isLastLetter = false;
            isLastSpace = true;
            Spaces++;
          }
        } else {
          // Dies ist hier eine Platzhalter f�r weitere m�gliche Codezeilen, falls
          // eine leere Zeile aus der Eingabe gelesen wird.
        }
      }
    }
    ProcessState = 2; // Prozesstatus 2: Sortiere Worttabelle nach Worth�ufigkeit absteigend
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
    j = m_WordTable.GetSize();
    do // Hinter diesem Sortierverfahren versteckt sich Bubblesort.
    {
      i = 0;
      j--;
      for(n = 0; n < j; n++)
      {
        WordTable = m_WordTable.GetAt(n);
        WordTable2 = m_WordTable.GetAt(n+1);
        if(WordTable.WordFrequency > WordTable2.WordFrequency)
        {
          WordTable3 = m_WordTable.GetAt(n);
          m_WordTable.SetAt(n,WordTable2);
          m_WordTable.SetAt(n+1,WordTable3);
          i++;
        }
      }
    } while(i && (j > 2));
    ProcessState = 7; // Prozessstatus = 7: Erstelle Worth�ufigkeit-Tabelle
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
    for(i = 0; i < m_WordTable.GetSize(); i++)
    {
      WordTable = m_WordTable.GetAt(m_WordTable.GetSize()-i-1);
      WordFrequency[i] = WordTable.WordFrequency;
    }
    ProcessState = 8; // Prozessstatus = 8: Erstelle K-Werte
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
    for(i = 0; i < m_WordTable.GetSize(); i++)
    {
      WordTable = m_WordTable.GetAt(m_WordTable.GetSize()-i-1);
      KValue[i] = WordTable.WordFrequency*(i+1);
    }
    ProcessState = 9; // Prozessstatus = 9: Erstelle Wortl�ngen-Tabelle
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
    for(i = 0; i < m_WordTable.GetSize(); i++)
    {
      WordTable = m_WordTable.GetAt(m_WordTable.GetSize()-i-1);
      WordLen[i] = WordTable.WordLength;
    }
    ProcessState = 10; // Prozessstatus = 7: Ausgabe von gez�hlten Buchstaben, Lerrzeichen und gebildeten W�rtern

  } else {
		// Hier erfolgen s�mtliche Ausf�hrungen, die beim Speichern einer Datei get�tigt werden.

    // Abspeicherung der Worttabelle in eine CSV-Datei
  	LONG a = 0;
    SWordTable WordTable2;
    CString strTemp,strWrite;
    for(a = 0; a < m_WordTable.GetSize(); a++)
    {
      strWrite = "";
      strTemp = "";
      WordTable2 = m_WordTable.GetAt(a);
      strWrite += "\"";
      strWrite += WordTable2.WordString;
      strWrite += "\";";
      strTemp.Format("%d",WordTable2.WordLength);
      strWrite += strTemp;
      strWrite += ";";
      strTemp.Format("%d",WordTable2.WordFrequency);
      strWrite += strTemp;
      strWrite += "\x0D\x0A";
      ar.Write(LPCTSTR(strWrite),strWrite.GetLength());
    }
    ProcessState = 20; // Prozessstatus = 20: Abspeicherung
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWordStatDoc diagnostics

#ifdef _DEBUG
void CWordStatDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWordStatDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWordStatDoc commands

void CWordStatDoc::OnButtonWordlendiagSortpos()
{
  // Vorbereitungen zur Anzeige des "Wortl�ngen-Diagramm - sortiert nach L�nge":
  // F�r die Erstellung weiterer Diagramm muss zun�chst eine Dialog angezeigt werden, damit die 
  // bei Bedarf nicht die komplette X-Achse integriert wird, sondern nur ein bestimmter Teil -
  // ausgehend om Koordinatenursprung.
  if(ProcessState >= 10) // Das Anzeigen des Dialog zur X-Achsenbeschr�nkung trifft nur zu,
                         // wenn eine Textdatei eingelesen worden und die Worttabelle geb-
                         // bildet worden ist. Dies wird mit dem Prozesstatus = 10 wiedergegeben.
  {
    ProcessState = 110;  // Prozessstatus = 110: "Wortl�ngen-Diagramm - sortiert nach L�nge"
                         // wird zur Anzeige eingeleitet
    CLimitXDlg dlgLimitX;
    dlgLimitX.m_uintLimitX = nWordLenMax; // "m_uintLimitX" ist hier der Grenzwert f�r die
                                          // Anzeige der X-Achse. Zuerst wird aber der Maximal-
                                          // wert der X-Achse wiedergegeben
    dlgLimitX.DoModal();
    if((dlgLimitX.m_uintLimitX >= 0) && (dlgLimitX.m_uintLimitX <= nWordLenMax))
    {
      m_uintLimitX = dlgLimitX.m_uintLimitX; // "m_uintLimitX" wird nun ggf. durch den eingegebene
                                             // Wert aus dem Dialog �berschrieben, damit die X-Achse
                                             // eingegrenzt wird.
    }
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
  }
}

void CWordStatDoc::OnButtonWordlendiagSortfreq() 
{
  // Vorbereitungen zur Anzeige des "Wortl�ngen-Diagramm - sortiert nach H�ufigkeit":
  // F�r die Erstellung weiterer Diagramm muss zun�chst eine Dialog angezeigt werden, damit die 
  // bei Bedarf nicht die komplette X-Achse integriert wird, sondern nur ein bestimmter Teil -
  // ausgehend om Koordinatenursprung.
  if(ProcessState >= 10) // Das Anzeigen des Dialog zur X-Achsenbeschr�nkung trifft nur zu,
                         // wenn eine Textdatei eingelesen worden und die Worttabelle geb-
                         // bildet worden ist. Dies wird mit dem Prozesstatus = 10 wiedergegeben.
  {
    ProcessState = 120;  // Prozessstatus = 120: "Wortl�ngen-Diagramm - sortiert nach H�ufigkeit"
                         // wird zur Anzeige eingeleitet
    CLimitXDlg dlgLimitX;
    dlgLimitX.m_uintLimitX = m_WordTable.GetSize(); // "m_uintLimitX" ist hier der Grenzwert f�r die
                                                    // Anzeige der X-Achse. Zuerst wird aber der Maximal-
                                                    // wert der X-Achse wiedergegeben
    dlgLimitX.DoModal();
    if((dlgLimitX.m_uintLimitX >= 0) && (dlgLimitX.m_uintLimitX <= (m_WordTable.GetSize()))
    {
      m_uintLimitX = dlgLimitX.m_uintLimitX; // "m_uintLimitX" wird nun ggf. durch den eingegebene
                                             // Wert aus dem Dialog �berschrieben, damit die X-Achse
                                             // eingegrenzt wird.
    }
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
  }
}

void CWordStatDoc::OnButtonWorddiagLenfreq() 
{
  // Vorbereitungen zur Anzeige des "Wort-L�ngen\H�ufigkeits - Diagramm":
  // F�r die Erstellung weiterer Diagramm muss zun�chst eine Dialog angezeigt werden, damit die 
  // bei Bedarf nicht die komplette X-Achse integriert wird, sondern nur ein bestimmter Teil -
  // ausgehend om Koordinatenursprung.
  if(ProcessState >= 10) // Das Anzeigen des Dialog zur X-Achsenbeschr�nkung trifft nur zu,
                         // wenn eine Textdatei eingelesen worden und die Worttabelle geb-
                         // bildet worden ist. Dies wird mit dem Prozesstatus = 10 wiedergegeben.
  {
    ProcessState = 130;  // Prozessstatus = 130: "Wort-L�ngen\H�ufigkeits - Diagramm"
                         // wird zur Anzeige eingeleitet
    CLimitXDlg dlgLimitX;
    dlgLimitX.m_uintLimitX = nWordLenMax; // "m_uintLimitX" ist hier der Grenzwert f�r die
                                          // Anzeige der X-Achse. Zuerst wird aber der Maximal-
                                          // wert der X-Achse wiedergegeben
    dlgLimitX.DoModal();
    if((dlgLimitX.m_uintLimitX >= 0) && (dlgLimitX.m_uintLimitX <= nWordLenMax))
    {
      m_uintLimitX = dlgLimitX.m_uintLimitX; // "m_uintLimitX" wird nun ggf. durch den eingegebene
                                             // Wert aus dem Dialog �berschrieben, damit die X-Achse
                                             // eingegrenzt wird.
    }
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
  }
}

void CWordStatDoc::OnButtonKvalue() 
{
  // Vorbereitungen zur Anzeige des "K-Wert - Diagramm":
  // F�r die Erstellung weiterer Diagramm muss zun�chst eine Dialog angezeigt werden, damit die 
  // bei Bedarf nicht die komplette X-Achse integriert wird, sondern nur ein bestimmter Teil -
  // ausgehend om Koordinatenursprung.
  if(ProcessState >= 10) // Das Anzeigen des Dialog zur X-Achsenbeschr�nkung trifft nur zu,
                         // wenn eine Textdatei eingelesen worden und die Worttabelle geb-
                         // bildet worden ist. Dies wird mit dem Prozesstatus = 10 wiedergegeben.
  {
    ProcessState = 140;  // Prozessstatus = 140: "K-Wert - Diagramm"
                         // wird zur Anzeige eingeleitet
    CLimitXDlg dlgLimitX;
    dlgLimitX.m_uintLimitX = m_WordTable.GetSize(); // "m_uintLimitX" ist hier der Grenzwert f�r die
                                                    // Anzeige der X-Achse. Zuerst wird aber der Maximal-
                                                    // wert der X-Achse wiedergegeben
    dlgLimitX.DoModal();
    if((dlgLimitX.m_uintLimitX >= 0) && (dlgLimitX.m_uintLimitX <= m_WordTable.GetSize()))
    {
      m_uintLimitX = dlgLimitX.m_uintLimitX; // "m_uintLimitX" wird nun ggf. durch den eingegebene
                                             // Wert aus dem Dialog �berschrieben, damit die X-Achse
                                             // eingegrenzt wird.
    }
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
  }
}

void CWordStatDoc::OnButtonWordlenSequence() 
{
  // Vorbereitungen zur Anzeige des "Folge von Wortl�ngen":
  // F�r die Erstellung weiterer Diagramm muss zun�chst eine Dialog angezeigt werden, damit die 
  // bei Bedarf nicht die komplette X-Achse integriert wird, sondern nur ein bestimmter Teil -
  // ausgehend om Koordinatenursprung.
  if(ProcessState >= 10) // Das Anzeigen des Dialog zur X-Achsenbeschr�nkung trifft nur zu,
                         // wenn eine Textdatei eingelesen worden und die Worttabelle geb-
                         // bildet worden ist. Dies wird mit dem Prozesstatus = 10 wiedergegeben.
  {  
    ProcessState = 150;  // Prozessstatus = 150: "Folge von Wortl�ngen"
                         // wird zur Anzeige eingeleitet
    CLimitXDlg dlgLimitX;
    dlgLimitX.m_uintLimitX = m_WordTable.GetSize(); // "m_uintLimitX" ist hier der Grenzwert f�r die
                                                    // Anzeige der X-Achse. Zuerst wird aber der Maximal-
                                                    // wert der X-Achse wiedergegeben
    dlgLimitX.DoModal();
    if((dlgLimitX.m_uintLimitX >= 0) && (dlgLimitX.m_uintLimitX <= m_WordTable.GetSize()))
    {
      m_uintLimitX = dlgLimitX.m_uintLimitX; // "m_uintLimitX" wird nun ggf. durch den eingegebene
                                             // Wert aus dem Dialog �berschrieben, damit die X-Achse
                                             // eingegrenzt wird.
    }
    UpdateAllViews(0,0,0); // Das "View" wird auf m�gliche �nderungen "upgedatet".
  }
}
