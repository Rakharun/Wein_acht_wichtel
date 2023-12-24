#include "../inc/WeinAchtsWichtel/Spielfeld.hpp"
namespace WeinAchtsWichtel{

    

    Spielfeld::Spielfeld(/* args */)
    {
        generieren();
        //debug, setze den Aktuellen Zeitpunkt
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        
        //formatiere 
        std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
        
        //this->ausgabeSchleife
        ausgabeThread = std::thread(&Spielfeld::ausgabeSchleife, this);

    }

    Spielfeld::~Spielfeld()
    {
        //Beende Thread
        this->spielStatus = false;
        // Überprüfe, ob der Thread ausführbar ist (joinable)
        if (this->ausgabeThread.joinable()) {
            // Beende den Thread und warte auf sein Ende
            this->setBereich(5,10,"Beenden this->ausgabeThread Beginnt");
            this->ausgabeThread.join();
            this->setBereich(1,10,"Beenden this->ausgabeThread Endet");
        }
        //Leere den Bildschirm nochmal
        std::cout << "Spielfeld MIT DESTRUKTOR BEENDET TID"<< std::this_thread::get_id() <<"\n";
    }

    int Spielfeld::bekommeBreite()
    {
        return breite;
    }
    int Spielfeld::bekommeHoehe()
    {
        return hoehe;
    }

    //Generiere ein Spielfeld
    void Spielfeld::generieren()
    {
        //Ich weiß nicht merh was es genau macht, aber es ist wichtig.
        memset(spielfeld_array, this->hoehe, sizeof(spielfeld_array));
        
        //Formatiere Spielfeld
        for (size_t i = 0; i < (hoehe); i++)
            {
                //Terminiere Zeile am Ende
                spielfeld_array[i][breite-1] = '\0';
                //Setzte Zeilennummern
                setBereich(i, 0,zahlZuBuchstabe(i));
                //Erstelle Rahmen
                setBereich(i, 2,"=");               //Links
                setBereich(i, this->breite -2,"="); //Rechs
            }
                std::string begrenzungLaengs(this->breite -4, '=');
                setBereich(0, 2, begrenzungLaengs); //Oben
                setBereich(this->hoehe-1, 2, begrenzungLaengs); //Unten
        
    }
    
    //Funktion Verkettet 2 oder 3 CharPtn
    std::string Spielfeld::verketteString(const std::string& str1, const std::string& str2, const std::string& str3, const std::string& str4) 
    {
    return (str1 + str2 + str3 +str4);
    }

    //Setzt im Zielstring einen bestimmten bereich auf den Quellstring
    void Spielfeld::setBereich(int zeile, int start_in_Zeile, const std::string& str1, const std::string& str2, const std::string& str3, const std::string& str4)
    {
        std::string Quelle = (str1 + str2 + str3 +str4);
        //Prüfe das nicht außerhalb des Spielfelds geschrieben wird
        //Vertikal
        zeile = (unsigned int)zeile;
        while(zeile > (hoehe-1))
        {
            zeile = zeile % (hoehe-1);
        }
        //Horrizontal
        start_in_Zeile = (unsigned int)start_in_Zeile;
        while(start_in_Zeile > (breite-2))
        {
            start_in_Zeile = start_in_Zeile % (breite-2);
        }
        //Schreibe in SPielfeld
        int zielLaenge = strlen(spielfeld_array[zeile]);
        int startLaenge1 = Quelle.length();    
        //Kopiere jedes zeichen, sofern nicht 0 von Quelle
        for (int i = start_in_Zeile, n = 0; i < start_in_Zeile + startLaenge1; i++, n++)
        {
            if (i < zielLaenge)
            {
                if (Quelle[n])
                {
                    spielfeld_array[zeile][i] = Quelle[n];
                }
            }
        }
    }

    //Konvertiere eine Zahl zu einem Char*
    template <typename T>
    std::string Spielfeld::zahlZuBuchstabe(T zahl)
    {
        std::ostringstream zahlZeichenkette;
        zahlZeichenkette << std::fixed << std::setprecision(2) << zahl;
        return zahlZeichenkette.str();
    }

    //Gebe das Spielfeld in der Konsole aus
    void Spielfeld::ausgeben()
    {
        std::ostream& ausgabe = std::cout;      // Ausgabe variable
        std::ostream::sync_with_stdio(false);   // Deaktiviere Pufferung
        //Speicher Jede Zeile in eine Ausgabe
        //ausgabe << "\033[0;2;0m"; //FArben kommen später
        //std::cout << "\033[1;0;40m";
        std::cout << "\033[1;31;40mWein achts Mann - A reccource management and type game.\033[0m\n";
        ausgabe << "\033[1;0;40m";
        for (int i = 0; i < hoehe; i++)
        {
            ausgabe << spielfeld_array[i] << '\n'; // Verwende '\n' anstelle von std::endl
        }
        std::cout << "\033[0m\n";
        //ausgabe << "\033[0m"; //oder vielleicht kommen farben auch später nicht.
        ausgabe.flush(); // Manuelles Flushen am Ende
    }

    //Die Spielfeld_console leeren
    void Spielfeld::leeren()
    {
        std::cout << "\x1b[2J\x1b[0;0H";
    }

    //    //Hier werden Anzeige Bilder, Programmzeit und FPS eingeblendet.
    //    void ausgabeStatistik()
    //    {
    //        
    //        
    //    }

    //Ausgabeschleife soll in einem Threat gestartet werden.
    void Spielfeld::ausgabeSchleife(Spielfeld* spielfeld)
    {

        //Bildzaehler
        int bildAktuell = 0;

        //Zeitanzeige
        int zeitPeriode = (int)spielfeld->ausgabe_verzoegerung;
        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        long zeitAktuell = 0;
             
        //FPS (Bilder Pro Sekunde) anzeige
        int bildZuletzt = 1;
        int zeitZuletzt = 1;
        float fps = 0.0;
        
        while (spielfeld->spielStatus)
        {
            //Schreibe aktualisierte Bilder seit Programmstart
            bildAktuell++;
            spielfeld->setBereich(1, 110, "Bild   :",spielfeld->zahlZuBuchstabe(bildAktuell));

            //Schreibe aktuelle Zeit seit Programmstart
            zeitAktuell = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count());
            spielfeld->setBereich(2,110,"Zeit   :",spielfeld->zahlZuBuchstabe(zeitAktuell));
            
            //Berechne und Schreibe FPS (1 mal pro Sekunde)
            if ((((bildAktuell-bildZuletzt) * zeitPeriode) > 1000) && ((bildAktuell-bildZuletzt) !=0) && ((zeitAktuell-zeitZuletzt) !=0) )
            {
                fps = ((1000.0 * ( bildAktuell-bildZuletzt) ) / (1.0*(zeitAktuell-zeitZuletzt)));
                
                zeitZuletzt = zeitAktuell;
                bildZuletzt = bildAktuell;
                spielfeld->setBereich(3,110,"FPS    :",spielfeld->zahlZuBuchstabe(fps));
            }

            //Ausgabe, gebe das gesammte Spielfeld aus.
            spielfeld->ausgeben();
            std::this_thread::sleep_for(std::chrono::milliseconds(zeitPeriode));
            spielfeld->leeren();
        }   
    }
}


