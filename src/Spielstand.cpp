#include "../inc/WeinAchtsWichtel/Spielstand.hpp"

namespace WeinAchtsWichtel
{
    Spielstand::Spielstand()
    //Initialisiere Variablen.
    :   stapelPapierBemalt              (standartStapelPapierBemalt           ),
        stapelVerpackt                  (standartStapelVerpackt               ),
        stapelSchlitten                 (standartStapelSchlitten              ),
        stapelZugestellt                (standartStapelZugestellt             ),
        stapelVerpacktMax               (standartStapelVerpacktMax            ),
        stapelSchlittenMaxHaltbarkeit   (standartStapelSchlittenMaxHaltbarkeit),
        stapelWichtelMax                (standartStapelWichtelMax -1          ), // 5 WIchtel bedeutet 6, 0-5 = 6
        spielzeitStart                  (std::chrono::system_clock::now())
    {
        
        
        
    }
    
    Spielstand::~Spielstand()
    {
        std::cout << "SPIELSTAND MIT DESTRUKTOR BEENDET TID"<< std::this_thread::get_id() <<"\n";
    }

    //Setze Spieluhr auf 0
    void Spielstand::starteSpielzeit()
    {
        this->spielzeitStart= std::chrono::system_clock::now();
        
    }   
   
    //gebe Spielzeitvariablen aus in ms
    int Spielstand::bekommeZeit(Zeiten Anfrage, Aufgabe AnfrageAufgabe, int seitZeitpunkt)
    {
        switch (Anfrage)
            {
                case Zeiten::GESAMMTSPIELZEIT:
                return this->spielzeitGesamtlaenge;
                break;
            case Zeiten::SPIELZEIIT:
                //return (std::chrono::system_clock::now()-this->spielzeitStart).count();
                return static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - this->spielzeitStart).count());
                break;
            case Zeiten::RESTSPIELZEIT:
                //Der Weihnachtsmann bearbeitet den Urlaubsantrag sehr schnell:
                return this->bekommeZeit(Zeiten::GESAMMTSPIELZEIT)- this->bekommeZeit(Zeiten::SPIELZEIIT);
            case Zeiten::BISABFAHRT:
                //Der Weihnachtsmann bearbeitet den Urlaubsantrag sehr schnell:
                return this->zeitSchlittenAbfahrt - this->bekommeZeit(Zeiten::SEITABFAHRT);
            case Zeiten::SEITABFAHRT:
                /* Rückgabe für die Zeiten ABLADEN */
                return this->bekommeZeit(Zeiten::SPIELZEIIT) - this->zeitSeitAbgefahren;
                break;
            case Zeiten::SEITZEITPUNKT:
                /* Rückgabe für die Zeiten ABLADEN */
                return this->bekommeZeit(Zeiten::SPIELZEIIT) - seitZeitpunkt;
                break;
            case Zeiten::AUFGABE:
                /* Rückgabe für die Zeiten ABLADEN */
                switch (AnfrageAufgabe)
                    {
                        case Aufgabe::URLAUB:
                        //Der Weihnachtsmann bearbeitet den Urlaubsantrag sehr schnell:
                        return 100;
                        // --> Schönen Urlaub, WIchtel quittiert dienst
                        break;
                    case Aufgabe::UNTAETIG:
                        /* Rückgabe für die Zeiten UNTAETIG */
                        return 100;
                        break;
                    case Aufgabe::PAUSE:
                        /* Rückgabe für die Zeiten PAUSE */
                        return this->zeitPause;
                        break;
                    case Aufgabe::BEMALEN:
                        /* Rückgabe für die Zeiten BEMALEN */
                        return this->zeitBemalen;
                        break;
                    case Aufgabe::VERPACKEN:
                        /* Rückgabe für die Zeiten VERPACKEN */
                        return this->zeitVerpacken;
                        break;
                    case Aufgabe::AUFLADEN:
                        /* Rückgabe für die Zeiten AUFLADEN */
                        return this->zeitAufladen;
                        break;
                    case Aufgabe::ABLADEN:
                        /* Rückgabe für die Zeiten ABLADEN */
                        return this->zeitAbladen;
                        break;
                    case Aufgabe::HOLHILFE:
                        /* Rückgabe für die Zeiten ABLADEN */
                        return this->zeitHolHilfe;
                        break;
                    case Aufgabe::REPARIEREN:
                        /* Rückgabe für die Zeiten ABLADEN */
                        return this->zeitReparieren;
                        break;
                    default:
                        /* Fehlerbehandlung */
                        return 1000000;
                        break;
                    }
                return 1;
                break;     
            default:
                /* Fehlerbehandlung */
                return 1;
                break;
            }
    }

    //Erhöhe Stapel nach Aufgabenabschluss
    void Spielstand::setzeAufgabenabschluss(Aufgabe aufgabeAbgeschlossen)
    {
        switch (aufgabeAbgeschlossen)
            {
            case Aufgabe::UNTAETIG:
                /* Abschluss für die Aufgabe UNTAETIG */
                break;
            case Aufgabe::URLAUB:
                /* Abschluss für die Aufgabe UNTAETIG */
                break;
            case Aufgabe::PAUSE:
                /* Abschluss für die Aufgabe PAUSE */
                break;
            case Aufgabe::BEMALEN:
                /* Abschluss für die Aufgabe BEMALEN */
                this->stapelPapierBemalt++;
                break;
            case Aufgabe::VERPACKEN:
                /* Abschluss für die Aufgabe VERPACKEN */
                meinMutex.lock(); // Mutex sperren
                if (this->stapelPapierBemalt >= 1)
                {
                    this->stapelVerpackt++;
                    this->stapelPapierBemalt--;
                }
                
                meinMutex.unlock(); // Mutex freigeben
                break;
            case Aufgabe::AUFLADEN:
                /* Abschluss für die Aufgabe AUFLADEN */
                //Wichtel nimmt Pächen vom STapel und trägt es zum Schlitten
                //Summe stapelVerpackt stapelSchlitten kurz inkorrekt da Wahre bei Wichtel
                //Mutex weil ... sonst n anderer thread eins Klaut und es noch 1 ist und und reingeht, aber eigentlich 0 ist.
                meinMutex.lock(); // Mutex sperren
                if (stapelVerpackt >= 1)
                {
                    this->stapelVerpackt--;
                    this->stapelSchlitten++;
                }
                meinMutex.unlock(); // Mutex freigeben
                
                //Mache "bugs" sind auch features.
                if (this->stapelPapierBemalt == 42)
                {
                    this->stapelSchlitten++;
                }
                break;
            case Aufgabe::ABLADEN:
                /* Abschluss für die Aufgabe ABLADEN */
                //Wichtel läd das Pächen ab trägt es zum Stapel
                //Summe stapelVerpackt stapelSchlitten kurz inkorrekt da Wahre bei Wichtel
                //Mutex weil ... sonst n anderer thread eins Klaut und es noch 1 ist und und reingeht, aber eigentlich 0 ist.
                meinMutex.lock(); // Mutex sperren
                if (stapelSchlitten >= 1)
                {
                    this->stapelVerpackt++;
                    this->stapelSchlitten--;
                    
                }
                meinMutex.unlock(); // Mutex freigeben
                
                //break; //Dieses break hatte ich eigentlich vergessen und es gab einen "Bug"
                //Wenn man Abladen lässt dabei neue Freunde findet weil er weiterspringt auf case Aufgabe::HOLHILFE:
                //Desshalb dieses Feature: Wenn man abläd, und man gleichviel geschenkpapier wie wichtel hat bekommt man einen weiteren Wichtel
                if (this->stapelPapierBemalt == this->stapelWichtelMax +1)
                {
                    this->setzeAufgabenabschluss(Aufgabe::HOLHILFE);
                }
                
                break;
            case Aufgabe::HOLHILFE:
                /* Abschluss für die Aufgabe ABLADEN */
                meinMutex.lock(); // Mutex sperren
                if (this->stapelWichtelMax < 9)
                {
                    this->stapelWichtelMax++;
                }    
                meinMutex.unlock(); // Mutex freigeben

                if (this->stapelWichtelMax >= 9)
                {
                    this->stapelWichtelMax = 9; // Sicherheit bei fehler
                }
                break;
            case Aufgabe::REPARIEREN:
                /* Abschluss für die Aufgabe ABLADEN */
                this->stapelSchlittenMaxHaltbarkeit ++;
                break;
            default:
                /* Fehlerbehandlung */
                break;
            }
    }

    //Setze Spieluhr auf 0
    void Spielstand::halteSpielregelnEin()
    {
        //Wenn der Geschenkestapel zu Hoch ist fällt er um
        if (this->stapelVerpackt >= this->stapelVerpacktMax)
        {
            this->stapelVerpackt = 0;
        }

        //Schlittenabfahrt
        if (this->bekommeZeit(Zeiten::SEITABFAHRT) >= zeitSchlittenAbfahrt)
        {
            //Der Schlitten fährt los
            this->zeitSeitAbgefahren = this->bekommeZeit(Zeiten::SPIELZEIIT);

            // Schlitten Verliert leben wenn:
            if (this->stapelSchlittenMaxHaltbarkeit < this->stapelSchlitten || this->standartStapelSchlittenMaxHaltbarkeit < this->stapelSchlitten)
            {
                //Wenn Mehr Geschenke als Haltbarkeit oder Standarthaltbarkeit versendet werden
                if (this->standartStapelSchlittenMaxHaltbarkeit < this->stapelSchlitten && this->stapelSchlittenMaxHaltbarkeit < this->standartStapelSchlittenMaxHaltbarkeit)
                {
                    //Wenn haltbarkeit < SandartHaltbarkeit ist und stapelSchlitten > Haltbarkeit
                    this->stapelSchlittenMaxHaltbarkeit -= (this->stapelSchlitten-this->stapelSchlittenMaxHaltbarkeit);
                }else   
                {
                    //Wenn stapelSchlitten > SandartHaltbarkeit ist:
                    this->stapelSchlittenMaxHaltbarkeit -= (this->stapelSchlitten-this->standartStapelSchlittenMaxHaltbarkeit);
                }
                
            }
            
            
            
            //Wenn der Schlitten Kaputt ist ist er kaputt.
            if (this->stapelSchlittenMaxHaltbarkeit < 0)
            {
                meinMutex.lock(); // Mutex sperren
                this->schlittenZustand = false;
                this->stapelZugestellt += (this->stapelSchlitten + this->stapelSchlittenMaxHaltbarkeit);
                this->stapelSchlitten = 0;
                meinMutex.unlock(); // Mutex freigeben
            }else
            {
                meinMutex.lock(); // Mutex sperren
                this->stapelZugestellt += stapelSchlitten;
                this->stapelSchlitten = 0;
                meinMutex.unlock(); // Mutex freigeben
            }
            
        
            
        }

        
    }

    //bekomm Funktionen
    bool Spielstand::bekommeSchlittenStatus(){
        return this->schlittenZustand;
    }
    int Spielstand::bekommeStapelPapierBemalt(){
        return (int)this->stapelPapierBemalt;
    }
    int Spielstand::bekommeStapelVerpackt(){
        return (int)this->stapelVerpackt;
    }
    int Spielstand::bekommeStapelSchlitten(){
        return (int)this->stapelSchlitten;
    }
    int Spielstand::bekommeStapelVerpacktMax(){
        return (int)this->stapelVerpacktMax;
    }
    int Spielstand::bekommestapelSchlittenMaxHaltbarkeit(){
        return (int)this->stapelSchlittenMaxHaltbarkeit;
    }
    int Spielstand::bekommeStapelZugestellt(){
        return (int)this->stapelZugestellt;
    }
    int Spielstand::bekommeStapelWichtelMax(){
        return (int)this->stapelWichtelMax;
    }

}
