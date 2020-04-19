#ifndef centrala_h 
#define centrala_h 
#include "zdarzenie.h"
#include "jednostka.h"
#include <string>
#include <vector>

using namespace std;

class Centrala{
private:
    int czas_odpoczynku; // Czas odpoczynku po akcji dla każdej jednostki
    Zdarzenie historia[20]; // Historia 20 ostatnio zakończonych zdarzeń
    vector<Zdarzenie> zdarzenia;// Aktualne zdarzenia
    Jednostka jednostki[10]; // Jednostki w centrali
public:
    Centrala() {}

    void pokazHistorie();
    void przydziel_jednostke_do_zdarzenia(Jednostka jednostka, Zdarzenie zdarzenie);
    void odbior_jednostki_po_zdarzeniu(Jednostka jednostka);
    void pokazMenu();
    void dodajZdarzenie();
    void pokazAktualneZdarzenia();

};

#endif
