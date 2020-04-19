#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "centrala.h"
#include "zdarzenie.h"

using namespace std;

// Funkcja pokazuje menu 
void Centrala::pokazMenu() {
    int wybor;

    cout << "1. Pokaż historię" << endl;
    cout << "2. Dodaj zdarzenie" << endl;
    cout << "3. Zakończ" << endl << endl;

    cout << "Twój wybór: ";
    cin >> wybor;

    if (wybor == 1) {
        // Pokaż historię
        pokazHistorie();
    } else if (wybor == 2 ) {
        // Dodaj zdarzenie
        dodajZdarzenie();
    } else if (wybor == 3) {
        // Zakończ
        exit(0);
    }
}

// Funkcja wyświetlająca całą historię w centrali
void Centrala::pokazHistorie() {
    string line;
    ifstream myfile ("historia_zdarzen.txt");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            cout << line << '\n';
        }
        myfile.close();
    } else { 
        cout << "Unable to open file";        
    }
}

// Funkcja przydzielająca jednostkę do zdarzenia
void Centrala::przydziel_jednostke_do_zdarzenia(Jednostka jednostka, Zdarzenie zdarzenie) {

}

// Funkcja potwierdzająca powrót jednostki do centrali
void Centrala::odbior_jednostki_po_zdarzeniu(Jednostka jednostka) {

}

// Funkcja dodająca zdarzenie w centrali
void Centrala::dodajZdarzenie() {
    int wybor;

    cout << "Możliwe zdarzenia:" << endl;
    cout << "1 - Utonięcie" << endl;
    cout << "2 - Pożar" << endl;
    cout << "3 - Wypadek samochodowy" << endl;
    cout << "4 - Kradzież" << endl << endl;

    cout << "Numer zdarzenia: ";
    cin >> wybor;

    // Utwórz zdarzenie
    if(wybor > 0 && wybor < 5) {
        Zdarzenie z(wybor);
        zdarzenia.push_back(z);
        cout << "Dodano zdarzenie: ";
        z.pokazOpis();

        // Zapisz zdarzenie w pliku
        fstream myfile("historia_zdarzen.txt", fstream::app);
        if (myfile.is_open()) {
            myfile << z.get_opis();
            myfile << "\n";
            myfile.close();
        }
        else {
            cout << "Unable to open file";
        }
    }

}

// Funkcja pokazująca aktualne zdarzenia
void Centrala::pokazAktualneZdarzenia() {
    cout << "Pokazywanie zdarzeń: " << endl;
    for(int i=0; i<zdarzenia.size(); i++) {
        Zdarzenie x = zdarzenia.at(i);
        x.pokazOpis();
    }
}
