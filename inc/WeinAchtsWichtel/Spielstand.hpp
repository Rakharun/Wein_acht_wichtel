#ifndef WEIN_ACHT_WICHTEL_SPIELSTAND_HPP
#define WEIN_ACHT_WICHTEL_SPIELSTAND_HPP
#include <iostream>
#include <thread>
#include <vector>
#include <cstring> // Für strcpy
#include <string> //f+r std::to_string(i)
#include <atomic>
#include <mutex> // Mutex-Header
#include "../WeinAchtsWichtel/WichtelEnum.hpp"

namespace WeinAchtsWichtel
{
    class Spielstand
    {
    private:
        /* data */
        std::chrono::system_clock::time_point spielzeitStart;   //der Startzeitpunkt des spiels
        std::mutex meinMutex; // Mutex-Objekt erstellen, atomic reicht nur manchmal

        //Ware
        std::atomic<int> stapelPapierBemalt             ;
        std::atomic<int> stapelVerpackt                 ;
        std::atomic<int> stapelSchlitten                ;
        std::atomic<int> stapelZugestellt               ;
        std::atomic<int> stapelVerpacktMax              ;
        std::atomic<int> stapelSchlittenMaxHaltbarkeit  ;
        std::atomic<int> stapelWichtelMax               ; 

        //Default Werte mit der Ware initialisiert wird im Konstruktor;
        static const int standartStapelPapierBemalt           = 0 ;         
        static const int standartStapelVerpackt               = 0 ; 
        static const int standartStapelSchlitten              = 0 ; 
        static const int standartStapelZugestellt             = 0 ; 
        static const int standartStapelVerpacktMax            = 15;         
        static const int standartStapelSchlittenMaxHaltbarkeit= 35; 
        static const int standartStapelWichtelMax             = 6 ;

        //Verzögerungen Arbeiten
        unsigned spielzeitGesamtlaenge  = 24*10*1000; 
        unsigned zeitBemalen            = 3000      ;
        unsigned zeitVerpacken          = 3000      ;
        unsigned zeitSchlittenAbfahrt   = 30000     ;
        unsigned zeitAufladen           = 2000      ;
        unsigned zeitPause              = 1000      ;
        unsigned zeitAbladen            = 1000      ;
        unsigned zeitHolHilfe           = 100000    ;
        unsigned zeitReparieren         = 1500      ;

        //Token
        unsigned zeitSeitAbgefahren = 0; //Zu welchem Zeitpunkt der Schlitten zuletzt abgefahren ist.
        bool     schlittenZustand = true;

        
        
    public:
        //Konstruktor und Destruktor
        Spielstand();
        ~Spielstand();

        //Spielzeit
        void starteSpielzeit();

        //Spielzeiten Anfrage
        int bekommeZeit(Zeiten Anfrage, Aufgabe AnfrageAufgabe = Aufgabe::UNTAETIG, int seitZeitpunkt = 0);

        //Spielzeit Getter
        void setzeAufgabenabschluss(Aufgabe Anfrage);

        //Wenn diese funktion aufgerufen wird fallen geschenkestapel los, und der Schlitten fährt los.
        void halteSpielregelnEin();

        bool bekommeSchlittenStatus  ();
        int bekommeStapelPapierBemalt();
        int bekommeStapelVerpackt    ();
        int bekommeStapelSchlitten   ();
        int bekommeStapelVerpacktMax ();
        int bekommestapelSchlittenMaxHaltbarkeit();
        int bekommeStapelZugestellt  ();
        int bekommeStapelWichtelMax  ();

    };
    
}

#endif