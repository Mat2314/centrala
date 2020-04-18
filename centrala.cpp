#include <iostream>
#include <string>
#include "centrala.h"

using namespace std;

// Funkcja wyświetlająca całą historię w centrali
void Centrala::pokaz_historie() {
    for(int i=0; i<20; i++) {
        cout << "Tutaj będzie historia" << endl;
    }
}

// Funkcja przydzielająca jednostkę do zdarzenia
void Centrala::przydziel_jednostke_do_zdarzenia(Jednostka jednostka, Zdarzenie zdarzenie) {

}

// Funkcja potwierdzająca powrót jednostki do centrali
void Centrala::odbior_jednostki_po_zdarzeniu(Jednostka jednostka) {

}
