#include "../inc/WeinAchtsWichtel/Spiel.hpp"

namespace WeinAchtsWichtel
{
    Spiel::Spiel()
    {   
        //Setze Standartwert in Benutzwereingabe.
        memset(this->benutzerEingabe, '_', this->benutzerEingabeLaenge);
        
        //Erstelle die Wichtel
        // Schleife durch die ENUM Helfer und erstelle Wichtel-Objekte für jeden Helfer
        for (int i = 0; i <= static_cast<int>(Helfer::Santa); ++i)
        {
            Helfer helfer = static_cast<Helfer>(i);
            std::shared_ptr<WeinAchtsWichtel::Wichtel> dieserWichtel = std::make_shared<WeinAchtsWichtel::Wichtel>(&meinSpielstand, helfer);
            wichtelVector.push_back(dieserWichtel);
            
        }
        
        //this->ausgabeSchleife
        eingabeThread = std::thread(&Spiel::eingabeSchleife, this);

        //Spiel hauptschleife
        this->spielStart(); //code hiernach wird eventuell nicht erreicht.
    }
    
    Spiel::~Spiel()
    {
        //Beende alle Objekte
        this->meinSpielfeld.~Spielfeld();
        //Printe Wichtel und ihre Aufgabe
        for (int i = 0; i <= static_cast<int>(Helfer::Santa); ++i)
        {
            wichtelVector[i]->wechselAufgabe(Aufgabe::URLAUB);
            wichtelVector[i]->~Wichtel();
        }
        // Überprüfe, ob der Thread ausführbar ist (joinable)
        if (eingabeThread.joinable()) {
            // Beende den Thread und warte auf sein Ende
            eingabeThread.join();
        }
        this->meinSpielstand.~Spielstand();
    }
   
    //Haupt Spielschleife
    void Spiel::spielStart()
    {   
        //Setze Spielzeit auf aktuellen Zeitpunkt
        this->meinSpielstand.starteSpielzeit();

        while (this->spielStatus)
        {
            this->verarbeiteEingabe();
            this->unterrichteSpielfeld();
            this->befehligeWichtel();
            this->meinSpielstand.halteSpielregelnEin();
            this->ueberpruefeSpielende();
            
            
            //Max 1000Hz 
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        
        //Clear all
        std::string begrenzungLaengs2(meinSpielfeld.bekommeBreite() -4, ' ');
        for (size_t i = 0; i < meinSpielfeld.bekommeHoehe(); i++)
        {
            meinSpielfeld.setBereich(i, 2, (begrenzungLaengs2));
        }
        meinSpielfeld.setBereich(7,  25, "   _____                         ____                 ");
        meinSpielfeld.setBereich(8,  25, "  / ____|                       / __ \\                ");
        meinSpielfeld.setBereich(9,  25, " | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ ");
        meinSpielfeld.setBereich(10, 25, " | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|");
        meinSpielfeld.setBereich(11, 25, " | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   ");
        meinSpielfeld.setBereich(12, 25, "  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   ");
        meinSpielfeld.setBereich(13, 25, "Erreichte Spielzeit  : ",std::to_string(this->meinSpielstand.bekommeZeit(Zeiten::SPIELZEIIT)));
        meinSpielfeld.setBereich(14, 25, "Restliche Spielzeit  : ",std::to_string(this->meinSpielstand.bekommeZeit(Zeiten::RESTSPIELZEIT)));
        meinSpielfeld.setBereich(15, 25, "Erreichte Punkte     : ",std::to_string(this->meinSpielstand.bekommeStapelZugestellt()));
        meinSpielfeld.setBereich(16, 25, "Schlitten Haltbarkeit: ",std::to_string(this->meinSpielstand.bekommestapelSchlittenMaxHaltbarkeit()));
        //Warte auf Beenden
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        

        // Leite Selbstzerstörung ein
        this->~Spiel();
    }

    void Spiel::ueberpruefeSpielende()
    {
        if (
                meinSpielstand.bekommeSchlittenStatus() != true ||
                meinSpielstand.bekommeZeit(Zeiten::RESTSPIELZEIT) <= 0 ||
                (((std::string)this->benutzerEingabe).find("000000")) != std::string::npos)                
            {
                this->spielStatus=false;
            }
    }

    void Spiel::verarbeiteEingabe()
    {
        //Verarbeite Letzte Benutzereingabe
        char spielzugEingabe = '*'; // * == ignore / ungütige eingabe;
        if (this->benutzerEingabe[this->benutzerEingabeLaenge-1] != '_' && this->benutzerEingabe[this->benutzerEingabeLaenge-1] != '#' )
        {
            spielzugEingabe = this->benutzerEingabe[this->benutzerEingabeLaenge-1];
            // Schiebe alle eingabechars im string eins nach links:
            for (size_t i = 0; i < this->benutzerEingabeLaenge; i++)
            {
                    this->benutzerEingabe[i] = this->benutzerEingabe[i+1];
            }
            //Benutzereingabe wird verarbeitet.
            this->benutzerEingabe[this->benutzerEingabeLaenge-1] = '#';
        }
        
        //Programm wartet auf Eingabe
        if (this->benutzerEingabe[this->benutzerEingabeLaenge-1] == '#')
        {
            this->benutzerEingabe[this->benutzerEingabeLaenge-1] = '_';
        }
    }

    void Spiel::unterrichteSpielfeld()
    {
        
        
        meinSpielfeld.setBereich(4, 110, "Spiel  :",meinSpielfeld.zahlZuBuchstabe(this->meinSpielstand.bekommeZeit(Zeiten::SPIELZEIIT))                                                    );
        meinSpielfeld.setBereich(5, 110, "Rest   :",meinSpielfeld.zahlZuBuchstabe((this->meinSpielstand.bekommeZeit(Zeiten::RESTSPIELZEIT))));
        meinSpielfeld.setBereich(6, 110, "Abfahrt:",meinSpielfeld.zahlZuBuchstabe(meinSpielstand.bekommeZeit(Zeiten::BISABFAHRT)));

        meinSpielfeld.setBereich(1,  3, "#Geschenkpapier bemalt  :",meinSpielfeld.zahlZuBuchstabe(this->meinSpielstand.bekommeStapelPapierBemalt())    ,"   ");
        meinSpielfeld.setBereich(2,  3, "#Geschenke-Stapel       :",meinSpielfeld.zahlZuBuchstabe(this->meinSpielstand.bekommeStapelVerpackt())        ,"   ");
        meinSpielfeld.setBereich(3,  3, "#Geschenke auf Schlitten:",meinSpielfeld.zahlZuBuchstabe(this->meinSpielstand.bekommeStapelSchlitten())       ,"   ");
        meinSpielfeld.setBereich(4,  3, "#Geschenke bei Kindern! ---->:",meinSpielfeld.zahlZuBuchstabe(this->meinSpielstand.bekommeStapelZugestellt())      ,"   ");
        meinSpielfeld.setBereich(5,  3, "#Schlitten Haltbarkeit  :",meinSpielfeld.zahlZuBuchstabe(this->meinSpielstand.bekommestapelSchlittenMaxHaltbarkeit())    ,"   ");
        meinSpielfeld.setBereich(6,  3, "#Maximale Stapelhoehe   :",meinSpielfeld.zahlZuBuchstabe(this->meinSpielstand.bekommeStapelVerpacktMax())     ,"   ");

        meinSpielfeld.setBereich(20, 3, "#========================#");
        meinSpielfeld.setBereich(21, 3, "#Euer Befehl: ",this->benutzerEingabe," #");
        meinSpielfeld.setBereich(21, 55, "#Tipp: Papier42 == Freifahrtsschein");
        
        
        std::string begrenzungLaengs(meinSpielfeld.bekommeBreite() -4, '=');
        meinSpielfeld.setBereich(22, 2, (begrenzungLaengs)); //Setzt ===== Querstrich 

            

        //Printe Wichtel und ihre Aufgabe
        for (int i = 0; i <= this->meinSpielstand.bekommeStapelWichtelMax(); ++i)
        {
            meinSpielfeld.setBereich(7+i, 4, wichtelVector[i]->erfahreStatusWichtel());
        }

        //Printe den Status der 
        this->ablaufKonsoleneingabe();
        
        
    
    }

    void Spiel::ablaufKonsoleneingabe()
    {
        //Clear
    
    	meinSpielfeld.setBereich(21,30,"Wichtel:",std::to_string(nutzerKonsole[0]),"Aufgabe:",std::to_string(nutzerKonsole[1]));
        
        if (nutzerKonsole[0] == 0)
        {
            meinSpielfeld.setBereich(24, 10, "Welchen Wichtel oder Helfer moechtest du Befehlen?    ");
            meinSpielfeld.setBereich(25, 10, "Gib einen Namen ein!                                  ");
            for (int i = 0; i <= this->meinSpielstand.bekommeStapelWichtelMax(); ++i)
            {
                
                meinSpielfeld.setBereich(26+i/5, 10+12*i*(1-i/5)+12*(i-5)*(i/5), meinSpielfeld.verketteString(meinSpielfeld.zahlZuBuchstabe(i+1), ":",wichtelNamenRichtig[i]));
            }
        }else
        {
            std::string pronomen = "*regenbogen pronomen*";
            pronomen = (nutzerKonsole[0] >= 4 && nutzerKonsole[0] <= 6) ? "ihr" : "ihm"; //Pronomen zuweisen kurzform

            meinSpielfeld.setBereich(25, 10, meinSpielfeld.verketteString(wichtelNamenRichtig[nutzerKonsole[0]-1], ": Welche aufgabe moechtest du ", pronomen, " geben?"));
            
            for (int i = 0; i < 8; ++i)
            {
                meinSpielfeld.setBereich(26+i/5, 10+12*i*(1-i/5)+12*(i-5)*(i/5), meinSpielfeld.verketteString(meinSpielfeld.zahlZuBuchstabe(i+1), ":",wichtelAufgabenRichtig[i]));
            }
        }
    }

    void Spiel::befehligeWichtel()
    {
        // nutzerKonsole[0] steht für den Wichtel der in der Konsole Grfunden wurde
        if (nutzerKonsole[0]==0)
        {
            for (int i = 0; i <= this->meinSpielstand.bekommeStapelWichtelMax(); ++i)
        {    
            if ((((std::string)this->benutzerEingabe).find(wichtelNamenRichtig[i]) != std::string::npos) || 
               ((((std::string)this->benutzerEingabe).find(std::to_string(i+1))) != std::string::npos))
            {
                nutzerKonsole[0] = i+1;
                memset(this->benutzerEingabe, '_', this->benutzerEingabeLaenge);
                meinSpielfeld.setBereich(24, 10, "                                                                      ");
                meinSpielfeld.setBereich(25, 10, "                                                                      ");
                meinSpielfeld.setBereich(26, 10, "                                                                      ");
                meinSpielfeld.setBereich(27, 10, "                                                                      ");
            }
        }
        }else // nutzerKonsole[0] Es wurde ein wichtel gefunden.
        {
            for (int i = 0; i < 8; ++i) // wichtelAufgaben ist 8 lang
            {    
                if ((((std::string)this->benutzerEingabe).find(wichtelAufgabenRichtig[i]) != std::string::npos) ||
                    (((std::string)this->benutzerEingabe).find(std::to_string(i+1)) != std::string::npos)) 
                {
                nutzerKonsole[1] = i+1;
                memset(this->benutzerEingabe, '_', this->benutzerEingabeLaenge);
                meinSpielfeld.setBereich(24, 10, "                                                                      ");
                meinSpielfeld.setBereich(25, 10, "                                                                      ");
                meinSpielfeld.setBereich(26, 10, "                                                                      ");
                meinSpielfeld.setBereich(27, 10, "                                                                      ");
                }
            }
        }

        if (nutzerKonsole[0]!=0 && nutzerKonsole[1]!=0)
        {
            wichtelVector[nutzerKonsole[0]-1]->wechselAufgabe(static_cast<Aufgabe>(nutzerKonsole[1]-1));
            nutzerKonsole[1]=0;
            nutzerKonsole[0]=0;
            meinSpielfeld.setBereich(24, 10, "                                                                      ");
            meinSpielfeld.setBereich(25, 10, "                                                                      ");
            meinSpielfeld.setBereich(26, 10, "                                                                      ");
            meinSpielfeld.setBereich(27, 10, "                                                                      ");
            
        }
        
    }


           /*
            EXTRACT_ALL            = YES
            EXTRACT_STATIC         = YES
            EXTRACT_LOCAL_CLASSES  = YES
            CLASS_DIAGRAMS         = YES
            HIDE_UNDOC_RELATIONS   = NO

           */

    void Spiel::eingabeSchleife(Spiel* meinSpiel)
    {
        //Initialisieren der EIngabeschleife
        int zeitintervall = meinSpiel->eingabe_verzoegerung;
        // Deaktiviere die Pufferung der Eingabe
        std::cin.sync_with_stdio(false);
        // Verknüpfung von cin und cout aufheben, um Pufferung weiter zu minimieren
        std::cin.tie(nullptr); 

        //Dekativieren der Enterbestätigung. Alles 
        struct termios new_settings;
        tcgetattr(0, &new_settings);
        new_settings.c_lflag &= (~ICANON & ~ECHO);
        tcsetattr(0, TCSANOW, &new_settings);

        //While Eingabeschleife
        while (meinSpiel->spielStatus)
        {
            meinSpiel->eingabe(); //Nimm Eingabe
            std::this_thread::sleep_for(std::chrono::milliseconds(zeitintervall)); //warte mal etwas
        }
    }


    void Spiel::eingabe()
    {
        char eingabe;
        // Nimm die Eingabe
        std::cin >> eingabe;
        if(std::cin.fail())
        {
            //Fehlschlag. Bereinige und starte cin neu. 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        }
        // Pruefe bei einer esc auf eine pfeiltaste.
        else if ((eingabe == '\\')||(eingabe== 27))
        {
            std::cin >> eingabe;  // Das zweite Zeichen lesen
            if (eingabe == '[') 
            {  // Prüfen, ob das zweite Zeichen eine öffnende eckige Klammer ist
                std::cin >> eingabe;  // Das dritte Zeichen lesen, das die Pfeiltaste repräsentiert
                std::cin.clear();
                switch (eingabe) {
                case 'A': eingabe = '+'; break;  // Hoch ↑
                case 'B': eingabe = '-'; break;  // Runter ↓
                case 'C': eingabe = '>'; break;  // Rechts →
                case 'D': eingabe = '<'; break;  // Links ←
                default: eingabe = '*';
            }
            }
            //Schreibe neuen eingabe, falls neue eingabe geschrieben werden kann.
            if (this->benutzerEingabe[this->benutzerEingabeLaenge-1] == '_')
            {
                this->benutzerEingabe[this->benutzerEingabeLaenge-1] = eingabe;
            }  
        }else if ( // Akzeptiere Zeichen: ('A' bis 'Z'), eine Ziffer ('0' bis '9'), ein Leerzeichen (' ')
        (eingabe >= 'a' && eingabe <= 'z') ||
        (eingabe >= 'A' && eingabe <= 'Z') ||
        (eingabe >= '0' && eingabe <= '9') ||
        (eingabe == ' '))
        {
            //Eingabe Akzeptiert
            //std::cin.clear(); //Mehrere eingaben koennen getätigt werden und seriell abgearbeitet werden
            if (this->benutzerEingabe[this->benutzerEingabeLaenge-1] == '_')
            {
                this->benutzerEingabe[this->benutzerEingabeLaenge-1] = eingabe;
            }  
        }else{
            //Eingabe nicht AKzeptiert
            std::cin.clear();
            if (this->benutzerEingabe[this->benutzerEingabeLaenge-1] == '_')
            {
                this->benutzerEingabe[this->benutzerEingabeLaenge-1] = '*';
            }   
        }
    }

    

}
