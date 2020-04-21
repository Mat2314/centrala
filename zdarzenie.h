#ifndef zdarzenie_h
#define zdarzenie_h
#include <string>
#include <vector>
#include "jednostka.h"

using namespace std;

class Zdarzenie {
private:
    int id; // Unikalne ID zdarzenia
    int typ; 
    // Typy zdarzeń:
    // 1 - Utonięcie
    // 2 - Pożar
    // 3 - wypadek samochodowy
    // 4 - kradzież
    string opis; // Słowny opis zdarzenia
    vector<Jednostka> jednostki; // Jednostki biorące udział przy tym zdarzeniu
public:
    Zdarzenie() {}
    Zdarzenie(int t, int _id);

    int get_id();
    int get_typ_zdarzenia();
    void pokazOpis();
    string get_opis();
    void dodajJednostke(Jednostka &J);
    string wypiszJednostki();
    vector<int> zwolnijJednostki();
    vector<int> get_id_jednostek();
    string zwrocWierszBazyDanych();
};

#endif
