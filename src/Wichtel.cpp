#include "../inc/WeinAchtsWichtel/Wichtel.hpp"

namespace WeinAchtsWichtel
{
    Wichtel::Wichtel(Spielstand *zugewisenerSpielstand, Helfer zuweisungWichtel, Aufgabe zuweisungAufgabe)
    : meinSpielstand(zugewisenerSpielstand)
    {
        meinWichtel = zuweisungWichtel;
        meineAufgabe = zuweisungAufgabe;
        meineLetzteAufgabe = Aufgabe::UNTAETIG;
        meinePauseEingehalten = Aufgabe::PAUSE;
        jetzigeAufgabe = meineAufgabe;
        jetzigeAufgabeDauer = meinSpielstand->bekommeZeit(Zeiten::AUFGABE, meineAufgabe);
        jetzigeAufgabeBegonnenZeitpunkt = meinSpielstand->bekommeZeit(Zeiten::SPIELZEIIT);
        helferThread = std::thread(&Wichtel::arbeite, this);
    }

    Wichtel::~Wichtel()
    {
        // Überprüfe, ob der Thread ausführbar ist (joinable)
        meineAufgabe = Aufgabe::URLAUB;
        if (helferThread.joinable()) {
            // Beende den Thread und warte auf sein Ende
            helferThread.join();
        }
        std::cout << "WICHTEL " << (int)meinWichtel <<" MIT DESTRUKTOR BEENDET TID"<< std::this_thread::get_id() <<"\n";

    }

    void Wichtel::arbeite(Wichtel* dieserWichtel)
    {
        
        while (dieserWichtel->meineAufgabe != Aufgabe::URLAUB)
        {
            //Prüft ob Aufgabe gewechselt wurde
            if (dieserWichtel->meineLetzteAufgabe != dieserWichtel->meineAufgabe)
            {
                //Aufgabe gewechselt, breche aufgabe ab.
                dieserWichtel->jetzigeAufgabe = dieserWichtel->meineAufgabe;
                dieserWichtel->meineLetzteAufgabe = dieserWichtel->meineAufgabe;
                dieserWichtel->jetzigeAufgabeBegonnenZeitpunkt = dieserWichtel->meinSpielstand->bekommeZeit(Zeiten::SPIELZEIIT);
            }
            
            //Prüft ob er Pausenzeiten eingehalten wurden
            if (dieserWichtel->meinePauseEingehalten != Aufgabe::PAUSE)
            {
                //Keine Pause gemacht,
                //Ändere die jetzige Aufgabe auf Pause
                dieserWichtel->meinePauseEingehalten = Aufgabe::PAUSE;
                dieserWichtel->jetzigeAufgabe = Aufgabe::PAUSE;
                dieserWichtel->jetzigeAufgabeDauer = dieserWichtel->meinSpielstand->bekommeZeit(Zeiten::AUFGABE, Aufgabe::PAUSE);
            }
            
            //Aufgabenabschluss Aufgabe erledigt
            if (dieserWichtel->jetzigeAufgabeBegonnenZeitpunkt+dieserWichtel->jetzigeAufgabeDauer <= dieserWichtel->meinSpielstand->bekommeZeit(Zeiten::SPIELZEIIT) )
            {
                //Abgeschlossen, setze den Abschluss der jetzigen aufgabe
                dieserWichtel->meinSpielstand->setzeAufgabenabschluss(dieserWichtel->jetzigeAufgabe);
                //Starte mit dem Nächsten Zyklus
                dieserWichtel->jetzigeAufgabe = dieserWichtel->meineAufgabe;
                dieserWichtel->jetzigeAufgabeBegonnenZeitpunkt = dieserWichtel->meinSpielstand->bekommeZeit(Zeiten::SPIELZEIIT);
                dieserWichtel->jetzigeAufgabeDauer = dieserWichtel->meinSpielstand->bekommeZeit(Zeiten::AUFGABE, dieserWichtel->jetzigeAufgabe);
            }
            
            //Der Wichtel Arbeitet 10ms bevor er Reagiert
            std::this_thread::sleep_for(std::chrono::milliseconds(dieserWichtel->wichtel_verzoegerung));
        }
        
    }

    void Wichtel::wechselAufgabe(Aufgabe neueAufgabe)
    {
        if (this->meineLetzteAufgabe != neueAufgabe)
        {
        this->meineLetzteAufgabe            = meineAufgabe;
        this->meineAufgabe                  = neueAufgabe;
        this->meinePauseEingehalten         = neueAufgabe; //Beim einteilen in eine neue Aufgabe wurde noch keine Pause gemacht
        }  
    }

    Aufgabe Wichtel::erfahreAufgabe()
    {
        return this->meineAufgabe;   
    } 
    Helfer  Wichtel::erfahreWichtel()
    {
        return this->meinWichtel;   
    }
    std::string Wichtel::erfahreStatusWichtel()
    {
        
        std::string dieserWichtelNummer  = std::to_string((int)this->meinWichtel+1);
        std::string dieserWichtelName    = this->wichtelNamenPrint[(int)this->meinWichtel];
        std::string dieserWichtelAufgabe = this->wichtelAufgaben[(int)this->jetzigeAufgabe];
        int fortschrittZeit = meinSpielstand->bekommeZeit(Zeiten::SEITZEITPUNKT, Aufgabe::UNTAETIG, this->jetzigeAufgabeBegonnenZeitpunkt);
        std::string dieserWichtelFortschritt = std::to_string((fortschrittZeit * 100)/ this->jetzigeAufgabeDauer);
        if (this->jetzigeAufgabeDauer <= 100)
        {
            dieserWichtelFortschritt = "xx";
        }
        
        return (dieserWichtelNummer + "." + dieserWichtelName + dieserWichtelAufgabe + "(" + dieserWichtelFortschritt + "%)   ");
    }

}