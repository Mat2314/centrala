#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "centrala.h"
#include "zdarzenie.h"
#include "jednostka.h"

using namespace std;

string czas() {
    auto now = std::chrono::system_clock::now();
    time_t _time = std::chrono::system_clock::to_time_t(now);
    auto readableTime = ctime(&_time);

    return readableTime;
}

// Konstruktor bezparametryczny
Centrala::Centrala() {
    // Zainicjuj jednostki w centrali
    // WOPR
    Jednostka wopr1(1, "WOPR", 1, 0); // lekka
    Jednostka wopr2(2, "WOPR", 1, 0); // lekka 
    Jednostka wopr3(3, "WOPR", 2, 0); // Ciezka
    Jednostka wopr4(4, "WOPR", 2, 0); // Ciezka
    jednostki.push_back(wopr1);
    jednostki.push_back(wopr2);
    jednostki.push_back(wopr3);
    jednostki.push_back(wopr4);

    // Policja
    Jednostka policja1(5, "Policja", 1, 0); 
    Jednostka policja2(6, "Policja", 1, 0); 
    Jednostka policja3(7, "Policja", 2, 0); 
    Jednostka policja4(8, "Policja", 2, 0); 
    jednostki.push_back(policja1);
    jednostki.push_back(policja2);
    jednostki.push_back(policja3);
    jednostki.push_back(policja4);

    // Straż pożarna
    Jednostka straz1(9, "Straz", 1, 0); 
    Jednostka straz2(10, "Straz", 1, 0); 
    Jednostka straz3(11, "Straz", 2, 0); 
    Jednostka straz4(12, "Straz", 2, 0); 
    jednostki.push_back(straz1);
    jednostki.push_back(straz2);
    jednostki.push_back(straz3);
    jednostki.push_back(straz4);

    // Pogotowie
    Jednostka pogotowie1(13, "Pogotowie", 1, 0); 
    Jednostka pogotowie2(14, "Pogotowie", 1, 0); 
    Jednostka pogotowie3(15, "Pogotowie", 2, 0); 
    Jednostka pogotowie4(16, "Pogotowie", 2, 0); 
    jednostki.push_back(pogotowie1);
    jednostki.push_back(pogotowie1);
    jednostki.push_back(pogotowie3);
    jednostki.push_back(pogotowie4);

}

// Funkcja wyświetla dostępne jednostki i pyta o przydział
void Centrala::panelPrzydzialuJednostek(Zdarzenie &Z) {
    int wybor;

    cout << "Przydziel jednostkę do wydarzenia ->" << Z.get_opis() << endl;
    cout << "Którą jednostkę chcesz przydzielić?" << endl;
    pokazDostepneJednostki();
    
    cout << "Wybierz numer jednostki: ";
    cin >> wybor;

    if(wybor >= 0 && wybor < jednostki.size()) {
        if(jednostki.at(wybor).jestWolna()) {
            char kolejne_jednostki;
            przydziel_jednostke_do_zdarzenia(jednostki.at(wybor), Z); // Jednostka jest przypisywana do zdarzenia
            jednostki.at(wybor).wyruszajZBazy(); // Jednostka wyrusza z bazy

            cout << "Czy chcesz przydzielić kolejną jednostkę do tego wydarzenia? (t/n)" << endl;
            cin >> kolejne_jednostki;

            if(kolejne_jednostki == 't') {
                panelPrzydzialuJednostek(Z);
            } else {
                // Zakończ przydział dla tego wydarzenia
            }
        } else {
            cout << "Tej jednostki nie ma w bazie!" << endl;
            cout << "Niepoprawny wybór, powtarzamy proces..." << endl << endl;
            panelPrzydzialuJednostek(Z);
        }
    } else {
        cout << "Niepoprawny wybór, powtarzamy proces..." << endl << endl;
        panelPrzydzialuJednostek(Z);
    }

}

// Funkcja pokazuje menu 
void Centrala::pokazMenu() {
    int wybor;

    cout << endl;
    cout << "1. Pokaż historię" << endl;
    cout << "2. Dodaj zdarzenie" << endl;
    cout << "3. Pokaż dostępne jednostki" << endl;
    cout << "4. Zakończ" << endl << endl;

    cout << "Twój wybór: ";
    cin >> wybor;

    if (wybor == 1) {
        // Pokaż historię
        pokazHistorie();
    } else if (wybor == 2 ) {
        // Dodaj zdarzenie
        dodajZdarzenie();
    } else if (wybor == 3) {
        // Pokaż jednostki
        pokazDostepneJednostki();
    } else if (wybor == 4) {
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
        
        // Przydziel jednostkę
        panelPrzydzialuJednostek(z);

        // Zapisz zdarzenie w pliku
        fstream myfile("historia_zdarzen.txt", fstream::app);
        if (myfile.is_open()) {
            myfile << "---NOWE ZDARZENIE---\n";
            myfile << czas();
            myfile << z.get_opis() << "\n";
            myfile << "Jednostki biorące udział:\n";
            myfile << z.wypiszJednostki();
            myfile << "\n---\n";
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

// Funkcja pokazuje dostepne jednostki
void Centrala::pokazDostepneJednostki() {
    cout << "JEDNOSTKI DOSTĘPNE W BAZIE:" << endl;
    for(int i=0; i<jednostki.size(); i++) {
        Jednostka j = jednostki.at(i);
        
        if(j.jestWolna()) {
            cout << i << ". " << j.get_typ_jednostki() << " (Poziom: " << j.get_poziom() << ")" << endl; 
        }
    }
    cout << endl;
}

// Funkcja przydziela jednostkę do danego zdarzenia
void Centrala::przydziel_jednostke_do_zdarzenia(Jednostka jednostka, Zdarzenie &zdarzenie) {
    zdarzenie.dodajJednostke(jednostka);
}
