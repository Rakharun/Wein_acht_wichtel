# Wein_acht_wichtel
 Programmentwurf SE II 11.12.24
# Weinachtsmann - Ein ressourcenintensives und taktisches Spiel

Der Weihnachtsmann hat leider zu viel Glühwein getrunken, um alle Abläufe in seinem Reich zu managen und sicherzustellen, dass alle Kinder ihre Geschenke erhalten. Ihr seid gefragt, diese Aufgabe zu übernehmen und dem Weihnachtsmann zu helfen.

## Spielanleitung
1. Weist euren 6 Wichteln Aufgaben zu, indem ihr zuerst ihre Namen auf der Tastatur eingebt. Ihr könnt sehen, was ihr eingebt, indem ihr auf das Eingabefeld über der Tastatur schaut. Achtet auf Groß- und Kleinschreibung. (Für Testzwecke könnt ihr auch nur Zahlen verwenden, z.B., 1, 2, 3...)
2. Anschließend könnt ihr die Aufgaben, die ihr ihnen zuweisen möchtet, in der Konsole lesen. Diese müsst ihr dann auch eingeben.
3. Wenn ihr alles richtig gemacht habt, ändert sich die Aufgabe des jeweiligen Wichtels auf eurer Anzeige.

## Spielregeln und Ressourcen
- Ihr könnt Geschenkpapier bemalen, was 3 Sekunden dauert.
- Geschenkpapier bemalt:
- Ihr könnt mit bemaltem Geschenkpapier Geschenke verpacken lassen, was ebenfalls 3 Sekunden dauert.
- Geschenke-Stapel:
  - Wenn der Stapel höher als 15, also 16, wird, fällt er um und die Anzahl der Geschenke wird auf 0 zurückgesetzt.
- Geschenke auf dem Schlitten:
  - Die Geschenke auf dem Schlitten werden alle 30 Sekunden an die Kinder ausgeliefert.
  - Der Schlitten des Weihnachtsmanns kann zuerst 35 Geschenke tragen.
  - Wenn ihr 36 Geschenke versendet (eins mehr als erlaubt), kann er beim nächsten Mal nur noch 34 Geschenke versenden.
- Schlitten Haltbarkeit (35):
  - Ihr könnt eure Wichtel den Schlitten tunen lassen (1,5 Sekunden), was die Gesamtkapazität erhöht und mehr Geschenke versendet werden können.
  - Beachtet jedoch, dass die Haltbarkeit des Schlittens bei Belastung sinkt. Geschenke, die höher als 35 oder die aktuelle Schlitten-Haltbarkeit sind, verringern die Haltbarkeit.
- Maximale Stapelhöhe:
  - Wenn ihr mehr als 15 Geschenke habt, fällt der Stapel um, und alle Geschenke gehen verloren.

## Spielende
Das Spiel endet, wenn eines der folgenden Kriterien erfüllt ist:
- Der Schlitten geht kaputt.
- Die Zeit von 24 Tagen à 10 Sekunden ist abgelaufen.
- Ihr gebt auf und gebt die Zahlen "000000" ein.

## Kompilieren und Starten
## Linux:
**Benötigte Programme:**
- Compiler: gcc und g++ / clang, clang++
- Buildtools: CMake, make
- Betriebssystem: Linux
- (Doxygen)
Das Projekt wird mit CMake bedient. Mit diesem könnt ihr ein Makefile erstellen, das das Projekt baut.

**Linux:**
shell:
# Wechselt ins Projektverzeichnis
cd /WeinAchtsWichtel

# Wechselt ins Build-Verzeichnis
cd build

# Führt CMakeLists.txt aus
cmake ..

# Führt Makefile aus
make

# Führt die ausführbare Datei aus
./WeinAchtWichtel

# Doxygen
es kann mit 'doxygen Doxyfile' zusatzinhalte erstellt werden zur Kokumentation.

# Windows:
Für Windows müsst ihr CMake auf diesem Betriebssystem verwenden, um das Projekt zu kompilieren.

## Thread-Beschreibungen
Das Projekt enthält folgende 13 Threads:

1. Mainthread (Überprüfung und ausführung von SPiellogik)
2. Thread zur asynchronen Eingabe und Steuerung
3. Thread zur asynchronen Ausgabe des Ausgangsstrings
4. Thread für die Arbeit der Wichtel und Helfer (10 Wichtel)

## Ressourcen und Zugriffskontrolle
Die geteilten Ressourcen befinden sich im Objekt "Spielstand", das von der Spielklasse erstellt wird. Diese 10 Wichtel-Threads haben eine Referenz auf den Spielstand und greifen darauf zu.

Der Zugriff auf geteilte Ressourcen erfolgt durch atomare Operationen und Mutexe zur Synchronisierung.

## Echtzeitverhalten
Ausgabe: 40 ms Periodizität
Eingabe: 10 ms Periodizität pro character
Spiellogik: 1 ms Periodizität
Wichtel: 10 ms Periodizität

## Zusätzliche Implementierungen:
Zusätzliche Implementierungen
Zeitanpassungen
Hilfe Holen
Schlitten Tunen
Schlittenänderungen
Fokusänderungen
Lustige "Bugs"

Zeitanpassung: //in ms
zeitAbladen            = 1000        ;
zeitHolHilfe           = 100000    ;
zeitReparieren         = 1500      ; 

# Hilfe Holen:
Man kann als Aufgabe Hilfe-holen in 50s Hilfe holen.
Hier bekommt man 1 Helfer dazu, maximum ist 10.

# Schlitten Tunen:
Man kann den Schlitten als Aufgabe in 1,5s tunen.
Dabei erhält der Schlitten 1 Haltbarkeit.

# Schlittenänderung:
Der Schlitten hat standartmäßig 35 Lebenspunkte.

Wenn 36Pakete versendet werden ist das 1 . zu viel. Der schlitten  hat 34 Haltbarkeit.

Wenn du Schlitten mehr als 35 Haltbarkeit hat, also gepimpt wurde ist das nur temporäre Haltbarkeit. Diese wird verbraucht beim benutzen.

**Bsp:** 
- Haltbarkeit=35, Beladen=35 --->Haltbarkeit=35
- Haltbarkeit=35, Beladen=40 --->Haltbarkeit=30
- Haltbarkeit=50, Beladen=50 --->Haltbarkeit=35
- Haltbarkeit=100, Beladen=100 --->Haltbarkeit=35
- Haltbarkeit=100, Beladen=35 --->Haltbarkeit=100
- Haltbarkeit=100, Beladen=36 --->Haltbarkeit=99

# Fokusänderung:
Es wurden 2 "Bugs" eingebaut die beim ausnutzen das Spiel einfacher aber auch lustiger machen um einen höheren wert zu erreichen.

# Bug 1:
Wenn man 42 Geschenkpapier hat, ist die Ressource  Geschenke-Stapel unbegrenzt.

# Bug 2:
Wenn man genauso viel Geschenkpapier wie Wichtel hat, und Geschenke vom Schlitten ablädt, bekommt man direkt einen Helfer mehr.

## Sonstiges:
Wenn man eine Weibliche oder Männlichen Helfer anspricht wird Sie mit ihr oder ihm angesprochen.

Auch vom Untätig sein machen Helfer Pause weil sie sich zuerst Zipfelmütze und Spitzschuhe anziehen müssen.

Warten bis eine ressource verfügbar ist interpretiere ich so dass ein Helfer nur dann tatsächlich arbeitet wenn reccource da ist.
PS: Eine implementierung eines feature-"Bugs" ist gerade damit verknüpft das eine aufgabe auch überprüft wird wenn sie nicht genug reccourcen hat. Ich hoffe ich habe gezeigt das es kein problem wäre das zu implementieren, aber das kostet gerade zu viel zeit. 

