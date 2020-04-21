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
    vector<Jednostka> jednostki; // Jednostki w centrali
public:
    Centrala(); 

    void pokazHistorie();
    void panelPrzydzialuJednostek(Zdarzenie &Z);
    void przydziel_jednostke_do_zdarzenia(Jednostka &jednostka, Zdarzenie &zdarzenie);
    void odbior_jednostek_po_zdarzeniu(Zdarzenie &Z); 
    void pokazMenu();
    void dodajZdarzenie();
    void pokazAktualneZdarzenia();
    void pokazDostepneJednostki();
    void wyswietlOdbiorJednostek();
    void wczytajAktywneZdarzenia();
    void zapiszZdarzenieDoPliku(Zdarzenie &Z);
    void usunAktywneZdarzenieZBazy(Zdarzenie &Z);

};

#endif
