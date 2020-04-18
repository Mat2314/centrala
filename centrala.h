#ifndef centrala_h 
#define centrala_h 
#include "zdarzenie.h"
#include "jednostka.h"
#include <string>

using namespace std;

class Centrala{
private:
    int czas_odpoczynku; // Czas odpoczynku po akcji dla każdej jednostki
    Zdarzenie historia[20]; // Historia 20 ostatnio zakończonych zdarzeń
    Zdarzenie zdarzenia[10]; // Aktualne zdarzenia
    Jednostka jednostki[4]; // Jednostki w centrali
public:
    Centrala() {}

    void pokaz_historie();
    void przydziel_jednostke_do_zdarzenia(Jednostka jednostka, Zdarzenie zdarzenie);
    void odbior_jednostki_po_zdarzeniu(Jednostka jednostka);

};

#endif
