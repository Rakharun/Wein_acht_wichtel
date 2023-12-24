#ifndef WEIN_ACHT_WICHTEL_WICHTELENUM_HPP
#define WEIN_ACHT_WICHTEL_WICHTELENUM_HPP

namespace WeinAchtsWichtel 
{
    enum class Helfer
    {
        Erni    =0,
        Bert    =1,
        Sid     =2,
        Pixxi   =3,
        Romy    =4,
        Zoe     =5,
        Rudolph =6, //special Helfer zum Holen ?
        Ruprecht=7,
        Gevatter=8,
        Santa   =9
    };

    enum class Aufgabe 
    {           
        UNTAETIG     =0, 
        PAUSE        =1, 
        BEMALEN      =2, 
        VERPACKEN    =3, 
        AUFLADEN     =4, 
        ABLADEN      =5, 
        HOLHILFE     =6,
        REPARIEREN   =7, 
        WARTEAUFABRUF=8,
        URLAUB       =9
    };

    enum class Zeiten 
    {
        GESAMMTSPIELZEIT  =-6,
        SPIELZEIIT        =-5,
        RESTSPIELZEIT     =-4,
        SEITABFAHRT       =-3, 
        SEITZEITPUNKT     =-2,
        BISABFAHRT        =-1,
        WARTEAUFABRUF     = 0,
        AUFGABE           = 1,
    };   


}

#endif 
/*
    
    
*/

