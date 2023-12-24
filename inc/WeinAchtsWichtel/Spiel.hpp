#ifndef WEIN_ACHT_WICHTEL_SPIEL_HPP
#define WEIN_ACHT_WICHTEL_SPIEL_HPP
#include <iostream>
#include <thread>
#include <vector>
#include <cstring> // Für strcpy
#include <string> //f+r std::to_string(i)
#include <termios.h> //Fuer deaktivieren der Enterbestätigung
#include <atomic>
#include <memory>
#include "../WeinAchtsWichtel/WichtelEnum.hpp"
#include "../WeinAchtsWichtel/Spielfeld.hpp"
#include "../WeinAchtsWichtel/Spielstand.hpp"
#include "../WeinAchtsWichtel/Wichtel.hpp"

namespace WeinAchtsWichtel
{
    class Spiel
    {
    private:
        /* data */
        static const int spielschleife_verzoegerung = 1;  //Verarbeitungszeit zur verarbeitung eines characters aus dem Eingabepuffer
        bool spielStatus = true;    //Das spiel lauft bis spiel == false
        static const int  benutzerEingabeLaenge = 9; //Länge des char* indem eingaben gespeichert und ausgewertet werden
        char benutzerEingabe[benutzerEingabeLaenge]; //Hier werden Benutzereingaben gesperichert auf die reagiert wird
        
        //Thread zur asyncronen Eingabe und Steuerung
        std::thread eingabeThread; 
        static const int eingabe_verzoegerung = 20;  //Verarbeitungszeit zur verarbeitung eines characters aus dem Eingabepuffer
        //Erstelle ein SPielstand
        WeinAchtsWichtel::Spielstand meinSpielstand;
        //Erstelle das Spielfeld
        WeinAchtsWichtel::Spielfeld meinSpielfeld;
        //Erstelle ein Vector für Wichtel
        std::vector<std::shared_ptr<WeinAchtsWichtel::Wichtel>> wichtelVector;
        std::string wichtelNamen[11] = {"Erni    :","Bert    :","Sid     :","Pixxi   :","Romy    :","Zoe     :","Rudolph :","Ruprecht:","Gevatter:","Santa   :","noPerson"};
        //Wichtel zum Stringcheck
        std::string wichtelNamenRichtig[11] = {"Erni","Bert","Sid","Pixxi","Romy","Zoe","Rudolph","Ruprecht","Gevatter","Santa","noPerson"};
        //Aufgaben zum Stringcheck
        std::string wichtelAufgabenRichtig[10] = {"warte","pause","bemal","verpack","aufladen","abladen","holhilfe", "tunen","abruf", "urlaub"};

        //Status der Nutzerkonsole
        int nutzerKonsole[2] = {0,0};
        
        //Nimm eine Usereingabe
        void eingabe();
        //Wird in einen Threat gestartet der Asyncron cin annimmt.
        static void eingabeSchleife(Spiel* meinSpiel);
        //Unternehme einen Spielzug mit der Aktuellen eingabe
        void verarbeiteEingabe();
        // Update Spielfeld
        void unterrichteSpielfeld();
        // Prüfe und Printe die Formatierung der Eingabe
        void ablaufKonsoleneingabe();
        //Ueberprüfe Spielende
        void ueberpruefeSpielende();
        //Reagiere auf Nutzereingaben
        void befehligeWichtel();
        //Lässt den Schlitten abfahren oder Zerbrechen
        void schlittenAbfahrt();
        //Haupt Spiel Schleife
        void spielStart();

    public:
        //Konstruktor und Destruktor
        Spiel();
        ~Spiel();

        
              
    };
    
}

#endif