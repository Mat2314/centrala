#include <iostream>
#include <string>
#include <vector>
#include "zdarzenie.h"
#include "jednostka.h"

using namespace std;

// Konstruktor parametryczny
Zdarzenie::Zdarzenie(int t, int _id) {
    id = _id;
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

// Funkcja zwracająca unikalne ID zdarzenia
int Zdarzenie::get_id() {return id;}

// Funkcja zwracająca typ wydarzenia
int Zdarzenie::get_typ_zdarzenia() {return typ;}

// Funkcja wypisuje opis danego zdarzenia
void Zdarzenie::pokazOpis() {
    cout << opis << endl;
}

// Funkcja zwraca unikalne id jednostek biorących udział w zdarzeniu 
vector<int> Zdarzenie::zwolnijJednostki() {
    vector<int> zbior_id;

    for(int i=0; i<jednostki.size(); i++) {
        int id_jednostki = jednostki.at(i).get_id();
        zbior_id.push_back(id_jednostki);
    }

    return zbior_id;
}

string Zdarzenie::get_opis() {
    return opis;
}

// Funkcja przypisuje jednostkę do zdarzenia
void Zdarzenie::dodajJednostke(Jednostka &J) {
    jednostki.push_back(J);
}

// Funkcja wypisuje jednostki w odpowiednim formacie do pliku
string Zdarzenie::wypiszJednostki() {
    string result = "";
    for(int i=0; i<jednostki.size(); i++) {
        result += jednostki.at(i).get_typ_jednostki() + " (Poziom: " + to_string(jednostki.at(i).get_poziom()) + ")\n";
    }
    return result;
}
