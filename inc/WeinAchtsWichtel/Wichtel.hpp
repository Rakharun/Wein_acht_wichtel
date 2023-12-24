#ifndef WEIN_ACHT_WICHTEL_WICHTEL_HPP
#define WEIN_ACHT_WICHTEL_WICHTEL_HPP
#include <iostream>
#include <thread>
#include <vector>
#include <cstring> // Für strcpy
#include <string> //f+r std::to_string(i)
#include "../WeinAchtsWichtel/WichtelEnum.hpp"
#include "../WeinAchtsWichtel/Spielstand.hpp"

namespace WeinAchtsWichtel
{
    //Erstellt einen Helfer der in eine Eldlosschleife zum arbeiten geschickt wird. Er Arbeitet mit den Reccourcen des übergebenen Spielstandes.
    class Wichtel
    {
    private:
        /* data */
        Helfer  meinWichtel;
        Aufgabe meineAufgabe;
        Aufgabe meineLetzteAufgabe;
        Aufgabe meinePauseEingehalten;
        Aufgabe jetzigeAufgabe;
        int jetzigeAufgabeDauer;
        int jetzigeAufgabeBegonnenZeitpunkt;

        //Thread zum asyncronen Arbeiten von Wichteln und Helfern
        std::thread helferThread;
        int wichtel_verzoegerung = 10;
        
        //WeinAchtsWichtel::Spiel::meinSpielstand
        Spielstand* meinSpielstand;

        //
        std::string wichtelNamenPrint[11] = {"Erni    :","Bert    :","Sid     :","Pixxi   :","Romy    :","Zoe     :","Rudolph :","Ruprecht:","Gevatter:","Santa  :","notAPerson"};
        std::string wichtelAufgaben[10] = { "ist Untaetig      "  ,"macht Pause       ","bemalt Papier     ","verpackt Geschenke" ,"belaed Schlitten  ","entlaed Schlitten ", "sucht Freunde      ", "pimpt Schlitten   ", "ist Unauffindbar  ", "ist im Urlaub     "};
        //Wichtel zum Stringcheck              
        std::string wichtelNamenRichtig[11] = {"Erni","Bert","Sid","Pixxi","Romy","Zoe","Rudolph","Ruprecht","Gevatter","Santa","notAPerson"};
        //Aufgaben zum Stringcheck
        std::string wichtelAufgabenRichtig[10] = {"warte","pause","bemal","verpack","aufladen","abladen","holhilfe", "wartung","abruf", "urlaub"};
        
        
        //der Wichtel Arbeitet
        static void arbeite(Wichtel* dieserWichtel);
        
    public:
        //Konstruktor und Destruktor
        Wichtel(Spielstand *zugewisenerSpielstand, WeinAchtsWichtel::Helfer zuweisungWichtel, WeinAchtsWichtel::Aufgabe zuweisungAufgabe = Aufgabe::UNTAETIG);//WeinAchtsWichtel::Spiel &diesesSpiel);
        ~Wichtel();

        //Wechsel die Arbeit oder fange an
        void wechselAufgabe(Aufgabe neueAufgabe);
        //Erfahre die aktuelle AUfgabe des Wichtels.
        Aufgabe erfahreAufgabe();
        //Erfahre die nummer des Wichtels
        Helfer erfahreWichtel();
        //Erfahre Status STring
        std::string erfahreStatusWichtel();
        

    };
    
}

#endif