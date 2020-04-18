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
    int dystans; // Dystans od centrali (wyrażony w czasie)
public:
    Zdarzenie() {}

    int get_typ_zdarzenia();
    int get_distance();
};

#endif
