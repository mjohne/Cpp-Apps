================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : CXI-Compressor Projekt�bersicht
================================================================================

Der Anwendungs-Assistent hat diese CXI-Compressor-Anwendung erstellt. 
Diese Anwendung zeigt die prinzipielle Anwendung der Microsoft Foundation Classes 
und dient als Ausgangspunkt f�r die Erstellung Ihrer eigenen Anwendungen.

Diese Datei enth�lt die Zusammenfassung der Bestandteile aller Dateien, die 
Ihre CXI-Compressor-Anwendung bilden.

CXI-Compressor.vcproj
    Dies ist die Hauptprojektdatei f�r VC++-Projekte, die vom Anwendungs-Assistenten 
    erstellt wird. Sie enth�lt Informationen �ber die Version von Visual C++, mit der
    die Datei generiert wurde, �ber die Plattformen, Konfigurationen und Projektfeatures,
    die mit dem Anwendungs-Assistenten ausgew�hlt wurden.

CXI-Compressor.h
    Hierbei handelt es sich um die Haupt-Headerdatei der Anwendung. Diese enth�lt 
    andere projektspezifische Header (einschlie�lich Resource.h) und deklariert die
    CCXICompressorApp-Anwendungsklasse.

CXI-Compressor.cpp
    Hierbei handelt es sich um die Haupt-Quellcodedatei der Anwendung. Diese enth�lt die
    Anwendungsklasse CCXICompressorApp.

CXI-Compressor.rc
    Hierbei handelt es sich um eine Auflistung aller Ressourcen von Microsoft Windows, die 
    vom Programm verwendet werden. Sie enth�lt die Symbole, Bitmaps und Cursors, die im 
    Unterverzeichnis RES gespeichert sind. Diese Datei l�sst sich direkt in Microsoft
    Visual C++ bearbeiten. Ihre Projektressourcen befinden sich in 1031.

res\CXICompressor.ico
    Dies ist eine Symboldatei, die als Symbol f�r die Anwendung verwendet wird. Dieses 
    Symbol wird durch die Haupt-Ressourcendatei CXI-Compressor.rc eingebunden.

res\CXICompressor.rc2
    Diese Datei enth�lt Ressourcen, die nicht von Microsoft Visual C++ bearbeitet wurden.
    In dieser Datei werden alle Ressourcen gespeichert, die vom Ressourcen-Editor nicht bearbeitet 
    werden k�nnen.
CXI-Compressor.reg
    Dies ist eine REG-Beispieldatei, die anzeigt, welche Registrierungseinstellungen
    von Framework festgelegt werden. Diese k�nnen Sie als .REG-
    -Datei f�r Ihre Anwendung festlegen.
CXI-Compressor.idl
    Diese Datei enth�lt den "Interface Description Language"-Quellcode f�r die
    Typbibliothek der Anwendung.

/////////////////////////////////////////////////////////////////////////////

Der Anwendungs-Assistent erstellt eine Dialogklasse und eine Automatisierungs-Proxy-Klasse:
CXI-CompressorDlg.h, CXI-CompressorDlg.cpp - das Dialogfeld
    Diese Dateien enthalten die Klasse CCXICompressorDlg. Diese Klasse legt das
    Verhalten des Haupt-Dialogfelds der Anwendung fest. Die Vorlage des Dialog-
    felds befindet sich in CXI-Compressor.rc, die mit Microsoft Visual C++
    bearbeitet werden kann.
DlgProxy.h, DlgProxy.cpp - das Automatisierungsobjekt
    Diese Dateien enthalten die Klasse CCXICompressorDlgAutoProxy. Diese Klasse 
    wird als "Automatisierungs-Proxy"-Klasse f�r das Dialogfeld bezeichnet, 
    da diese darauf achtet, ob die Methoden und Eigenschaften verletzt werden, 
    die die Automatisierungs-Controller f�r den Zugriff auf das Dialogfeld verwenden. 
    Der direkte Zugriff von der Dialogfeldklasse auf diese Methoden und Eigenschaften 
    ist nicht m�glich, da es bei einer modalen dialogfeldbasierten MFC-Anwendung 
    sicherer und einfacher ist, das Automatisierungsobjekt von der
    Benutzeroberfl�che zu trennen.
/////////////////////////////////////////////////////////////////////////////

Weitere Features:

ActiveX-Steuerelemente
    Die Anwendung unterst�tzt die Verwendung von ActiveX-Steuerelementen.

Windows-Sockets
    Die Anwendung unterst�tzt die Kommunikation �ber TCP/IP-Netzwerke.
/////////////////////////////////////////////////////////////////////////////

Weitere Standarddateien:

StdAfx.h, StdAfx.cpp
    Mit diesen Dateien werden vorkompilierte Headerdateien (PCH) mit der Bezeichnung
    CXI-Compressor.pch und eine vorkompilierte Typdatei mit der Bezeichnung 
    StdAfx.obj erstellt.

Resource.h
    Dies ist die Standard-Headerdatei, die neue Ressourcen-IDs definiert.
    Microsoft Visual C++ liest und aktualisiert diese Datei.

/////////////////////////////////////////////////////////////////////////////

Weitere Hinweise:

Der Anwendungs-Assistent verwendet "TODO:", um die Stellen anzuzeigen, 
an denen Sie Erweiterungen oder Anpassungen vornehmen k�nnen.

Wenn Ihre Anwendung die MFC in einer gemeinsam genutzten DLL verwendet und 
eine andere als die aktuell auf dem Betriebssystem eingestellte Sprache verwendet, muss 
die entsprechend lokalisierte Ressource MFC70XXX.DLL von der Microsoft Visual C++ CD-ROM 
in das Verzeichnis system oder system32 kopiert und in MFCLOC.DLL umbenannt werden  
("XXX" steht f�r die Abk�rzung der Sprache. So enth�lt beispielsweise MFC70DEU.DLL die ins Deutsche 
�bersetzten Ressourcen.)  Anderenfalls werden einige Oberfl�chenelemente Ihrer Anwendung 
in der Sprache des Betriebssystems angezeigt.

/////////////////////////////////////////////////////////////////////////////
