#ifndef zdarzenie_h
#define zdarzenie_h
#include <string>

using namespace std;

class Zdarzenie {
private:
    int typ; 
    // Typy zdarzeń:
    // 1 - Utonięcie
    // 2 - Pożar
    // 3 - wypadek samochodowy
    // 4 - kradzież
    int dystans; // Dystans od centrali (wyrażony w czasie)
    string opis; // Słowny opis zdarzenia
public:
    Zdarzenie() {}
    Zdarzenie(int t);

    int get_typ_zdarzenia();
    int get_distance();
    void pokazOpis();
    string get_opis();
};

#endif
