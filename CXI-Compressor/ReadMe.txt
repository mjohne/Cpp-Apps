================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : CXI-Compressor Projektübersicht
================================================================================

Der Anwendungs-Assistent hat diese CXI-Compressor-Anwendung erstellt. 
Diese Anwendung zeigt die prinzipielle Anwendung der Microsoft Foundation Classes 
und dient als Ausgangspunkt für die Erstellung Ihrer eigenen Anwendungen.

Diese Datei enthält die Zusammenfassung der Bestandteile aller Dateien, die 
Ihre CXI-Compressor-Anwendung bilden.

CXI-Compressor.vcproj
    Dies ist die Hauptprojektdatei für VC++-Projekte, die vom Anwendungs-Assistenten 
    erstellt wird. Sie enthält Informationen über die Version von Visual C++, mit der
    die Datei generiert wurde, über die Plattformen, Konfigurationen und Projektfeatures,
    die mit dem Anwendungs-Assistenten ausgewählt wurden.

CXI-Compressor.h
    Hierbei handelt es sich um die Haupt-Headerdatei der Anwendung. Diese enthält 
    andere projektspezifische Header (einschließlich Resource.h) und deklariert die
    CCXICompressorApp-Anwendungsklasse.

CXI-Compressor.cpp
    Hierbei handelt es sich um die Haupt-Quellcodedatei der Anwendung. Diese enthält die
    Anwendungsklasse CCXICompressorApp.

CXI-Compressor.rc
    Hierbei handelt es sich um eine Auflistung aller Ressourcen von Microsoft Windows, die 
    vom Programm verwendet werden. Sie enthält die Symbole, Bitmaps und Cursors, die im 
    Unterverzeichnis RES gespeichert sind. Diese Datei lässt sich direkt in Microsoft
    Visual C++ bearbeiten. Ihre Projektressourcen befinden sich in 1031.

res\CXICompressor.ico
    Dies ist eine Symboldatei, die als Symbol für die Anwendung verwendet wird. Dieses 
    Symbol wird durch die Haupt-Ressourcendatei CXI-Compressor.rc eingebunden.

res\CXICompressor.rc2
    Diese Datei enthält Ressourcen, die nicht von Microsoft Visual C++ bearbeitet wurden.
    In dieser Datei werden alle Ressourcen gespeichert, die vom Ressourcen-Editor nicht bearbeitet 
    werden können.
CXI-Compressor.reg
    Dies ist eine REG-Beispieldatei, die anzeigt, welche Registrierungseinstellungen
    von Framework festgelegt werden. Diese können Sie als .REG-
    -Datei für Ihre Anwendung festlegen.
CXI-Compressor.idl
    Diese Datei enthält den "Interface Description Language"-Quellcode für die
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
    wird als "Automatisierungs-Proxy"-Klasse für das Dialogfeld bezeichnet, 
    da diese darauf achtet, ob die Methoden und Eigenschaften verletzt werden, 
    die die Automatisierungs-Controller für den Zugriff auf das Dialogfeld verwenden. 
    Der direkte Zugriff von der Dialogfeldklasse auf diese Methoden und Eigenschaften 
    ist nicht möglich, da es bei einer modalen dialogfeldbasierten MFC-Anwendung 
    sicherer und einfacher ist, das Automatisierungsobjekt von der
    Benutzeroberfläche zu trennen.
/////////////////////////////////////////////////////////////////////////////

Weitere Features:

ActiveX-Steuerelemente
    Die Anwendung unterstützt die Verwendung von ActiveX-Steuerelementen.

Windows-Sockets
    Die Anwendung unterstützt die Kommunikation über TCP/IP-Netzwerke.
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
an denen Sie Erweiterungen oder Anpassungen vornehmen können.

Wenn Ihre Anwendung die MFC in einer gemeinsam genutzten DLL verwendet und 
eine andere als die aktuell auf dem Betriebssystem eingestellte Sprache verwendet, muss 
die entsprechend lokalisierte Ressource MFC70XXX.DLL von der Microsoft Visual C++ CD-ROM 
in das Verzeichnis system oder system32 kopiert und in MFCLOC.DLL umbenannt werden  
("XXX" steht für die Abkürzung der Sprache. So enthält beispielsweise MFC70DEU.DLL die ins Deutsche 
übersetzten Ressourcen.)  Anderenfalls werden einige Oberflächenelemente Ihrer Anwendung 
in der Sprache des Betriebssystems angezeigt.

/////////////////////////////////////////////////////////////////////////////
