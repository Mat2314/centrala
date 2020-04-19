#include <iostream>
#include <string>
#include "zdarzenie.h"

using namespace std;

// Konstruktor parametryczny
Zdarzenie::Zdarzenie(int t) {
    if (t == 1) {
        typ = t;
        opis = "Zarejestrowano utonięcie";
    } else if (t == 2 ) {
        typ = t;
        opis = "Zarejestrowano pożar";
    } else if (t == 3) {
        typ = t;
        opis = "Zarejestrowano wypadek samochodowy";
    } else if (t == 4 ) {
        typ = t;
        opis = "Zarejestrowano kradzież";
    } else {
        cout << "Błąd - nie ma takiego zdarzenia" << endl;
    }
}

// Funkcja zwracająca typ wydarzenia
int Zdarzenie::get_typ_zdarzenia() {return typ;}

// Funkcja zwracająca dystans od centrali do miejsca zdarzenia
int Zdarzenie::get_distance() {return dystans;}

// Funkcja wypisuje opis danego zdarzenia
void Zdarzenie::pokazOpis() {
    cout << opis << endl;
}

string Zdarzenie::get_opis() {
    return opis;
}
