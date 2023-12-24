#ifndef WEIN_ACHT_WICHTEL_SPIELFELD_HPP
#define WEIN_ACHT_WICHTEL_SPIELFELD_HPP
#include <iostream>
#include <thread>
#include <vector>
#include <cstring> // Für strcpy
#include <string> //f+r std::to_string(i)
#include <sstream>  // Für std::ostringstream
#include <iomanip>  // Für std::setprecision

namespace WeinAchtsWichtel
{
    class Spielfeld
    {
    private:
        /* data */
        static const int breite = 128; //Breite des Spielfeldes 
        static const int hoehe = 32;   //Höhe des Spielfeldes
        char spielfeld_array[hoehe][breite]; //Ein Array aus Strings als Spielfeld
        std::thread ausgabeThread; //Thread zur asyncronen Ausgabe des Ausgangsstrings
        static const int ausgabe_verzoegerung = 50;   //Ausgabe zeitintervall
        bool spielStatus = true;    //Das spiel lauft bis spiel == false

        // Generiert am anfang die Korrekten strings in dem 2D Array Spielfeld.
        void generieren();

        //Gebe das Gesammte Spielfeld aus
        void ausgeben();

        //Leere das Spielfeld/Konsole
        void leeren();

        //Wird in einen Threat gestartet der Asyncron das Spielfeld ausgibt.
        static void ausgabeSchleife(Spielfeld* diesesSpielfeld);

        //   //Hier werden Anzeige Bilder, Programmzeit und FPS eingeblendet.
        //   static void ausgabeStatistik(Spielfeld* diesesSpielfeld);

    public:
        //Konstruktor und Destruktor
        Spielfeld();
        ~Spielfeld();

        //Gebe Breite und Hoehe aus
        static int bekommeBreite();
        static int bekommeHoehe();
        //Konvertiere eine Zahl zu einem Char*
        template <typename T>
        std::string zahlZuBuchstabe(T zahl);

        //Verkette String Zeichenkette
        std::string verketteString(const std::string& str1 = "", const std::string& str2 = "", const std::string& str3 = "", const std::string& str4 = ""); 

        //Setzt im Zielstring einen bestimmten bereich auf den Quellstring
        void setBereich(int zeile, int start_in_Zeile, const std::string& str1 = "", const std::string& str2 = "", const std::string& str3 = "", const std::string& str4 = "");

        
  
    };
    
}
#endif