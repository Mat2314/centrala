#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
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
    Jednostka wopr1(0, "WOPR", 1, 0); // lekka
    Jednostka wopr2(1, "WOPR", 1, 0); // lekka 
    Jednostka wopr3(2, "WOPR", 2, 0); // Ciezka
    Jednostka wopr4(3, "WOPR", 2, 0); // Ciezka
    jednostki.push_back(wopr1);
    jednostki.push_back(wopr2);
    jednostki.push_back(wopr3);
    jednostki.push_back(wopr4);

    // Policja
    Jednostka policja1(4, "Policja", 1, 0); 
    Jednostka policja2(5, "Policja", 1, 0); 
    Jednostka policja3(6, "Policja", 2, 0); 
    Jednostka policja4(7, "Policja", 2, 0); 
    jednostki.push_back(policja1);
    jednostki.push_back(policja2);
    jednostki.push_back(policja3);
    jednostki.push_back(policja4);

    // Straż pożarna
    Jednostka straz1(8, "Straz", 1, 0); 
    Jednostka straz2(9, "Straz", 1, 0); 
    Jednostka straz3(10, "Straz", 2, 0); 
    Jednostka straz4(11, "Straz", 2, 0); 
    jednostki.push_back(straz1);
    jednostki.push_back(straz2);
    jednostki.push_back(straz3);
    jednostki.push_back(straz4);

    // Pogotowie
    Jednostka pogotowie1(12, "Pogotowie", 1, 0); 
    Jednostka pogotowie2(13, "Pogotowie", 1, 0); 
    Jednostka pogotowie3(14, "Pogotowie", 2, 0); 
    Jednostka pogotowie4(15, "Pogotowie", 2, 0); 
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
                // Zapisz dane do pliku
                zapiszZdarzenieDoPliku(Z);
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
    cout << "4. Pokaż aktualne zdarzenia" << endl;
    cout << "5. Odbiór jednostek" << endl;
    cout << "6. Zakończ" << endl << endl;

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
        // Pokaż aktualne zdarzenia
        pokazAktualneZdarzenia();
    } else if (wybor == 5) {
        // Pokaż menu odbioru jednostek
        wyswietlOdbiorJednostek();
    } else if (wybor == 6) {
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

void Centrala::wyswietlOdbiorJednostek() {
    int id_zdarzenia;

    cout << "---" << endl;
    cout << "ODBIÓR JEDNOSTEK" << endl;
    pokazAktualneZdarzenia();
    cout << "Podaj ID zdarzenia z którego jednostki powróciły do bazy: ";
    cin >> id_zdarzenia;

    // Poszukaj wśród aktywnych zdarzeń
    for(int i=0; i<zdarzenia.size(); i++) {
        if(zdarzenia.at(i).get_id() == id_zdarzenia) {
            //Zdarzenie *zakonczone = & zdarzenia.at(i);
            //zakonczone->zwolnijJednostki();
            odbior_jednostek_po_zdarzeniu(zdarzenia.at(i));
            cout << "Jednostki powróciły do bazy" << endl;
            zdarzenia.erase(zdarzenia.begin() + i);
            break;
        }
    } 

}

// Funkcja potwierdzająca powrót jednostki do centrali
void Centrala::odbior_jednostek_po_zdarzeniu(Zdarzenie &Z) {
    // Weź id jednostek biorących udział w akcji
    vector<int> id_jednostek;
    id_jednostek = Z.zwolnijJednostki();

    // Potwierdź powrót jednostek do bazy
    for(int i=0; i<id_jednostek.size(); i++){
        for(int j=0; j<jednostki.size(); j++) {
            if(id_jednostek.at(i) == jednostki.at(j).get_id()) {
                jednostki.at(j).powrotDoBazy();
            }
        }
    }
    usunAktywneZdarzenieZBazy(Z);
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
        int index = zdarzenia.size();
        Zdarzenie z(wybor, index);
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
        } else {
            cout << "Unable to open file";
        }
        zdarzenia.push_back(z);
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
void Centrala::przydziel_jednostke_do_zdarzenia(Jednostka &jednostka, Zdarzenie &zdarzenie) {
    zdarzenie.dodajJednostke(jednostka);
}

// Funkcja wyświetla aktualnie trwające zdarzenia
void Centrala::pokazAktualneZdarzenia() {
    cout << "---" << endl;
    cout << "TRWAJĄCE ZDARZENIA" << endl;

    for(int i=0; i<zdarzenia.size(); i++) {
        cout << zdarzenia.at(i).get_opis() << "(ID: " << to_string(zdarzenia.at(i).get_id()) << ")" << endl;
        cout << "Jednostki przypisane do wydarzenia: " << endl;
        cout << zdarzenia.at(i).wypiszJednostki() << endl;
    }
}

// Funkcja zapisuje aktywne zdarzenie w pliku by móc je potem wczytać
void Centrala::zapiszZdarzenieDoPliku(Zdarzenie &Z) {
    vector<int> id_jednostek;

    // Zapisz zdarzenie w pliku zdarzeń aktywnych
    fstream myfile("aktywne_zdarzenia.txt", fstream::app);
    if (myfile.is_open()) {
        myfile << to_string(Z.get_id()) << ";" << to_string(Z.get_typ_zdarzenia()) << ";";
        
        // Dopisz dane jednostek do pliku
        id_jednostek = Z.get_id_jednostek(); 
        for(int i=0; i<id_jednostek.size(); i++){
            myfile << id_jednostek.at(i) << ";";
        }

        myfile << "\n";
        
    } else {
        cout << "Unable to open file";
    }
}

void Centrala::usunAktywneZdarzenieZBazy(Zdarzenie &Z) {
    string zdarzenie = Z.zwrocWierszBazyDanych();

    string line;
    ifstream fin("aktywne_zdarzenia.txt");
    ofstream temp("temp.txt");

    while(getline(fin, line)) {
        if(line != zdarzenie) {
            temp << line << endl;
        }
    }

    fin.close();
    temp.close();

    const char * p = "aktywne_zdarzenia.txt"; // required conversion for remove and rename functions
    remove(p);
    rename("temp.txt", p);
}

// Funkcja rozszyfrowuje zakodowane aktywne zdarzenia i zwraca je w wektorze
vector<int> rozkodujDaneZBazy(string line) {
    vector<int> rozkodowane;
    stringstream ss(line);

    for(int i; ss >> i;) {
        rozkodowane.push_back(i);
        if(ss.peek() == ';'){
            ss.ignore();
        }
    }

    return rozkodowane;
}

// Funkcja wczytuje dane dotyczące bieżących zdarzeń
void Centrala::wczytajAktywneZdarzenia() {
    string line;
    string naglowek;
    ifstream fin("aktywne_zdarzenia.txt");

    getline(fin, naglowek); // Wczytaj sam nagłówek


    while(getline(fin, line)) {
        vector<int> dane;
        dane = rozkodujDaneZBazy(line);

        int id_zdarzenia = dane.at(0);
        int typ_zdarzenia = dane.at(1);
        Zdarzenie Z(typ_zdarzenia, id_zdarzenia);
        zdarzenia.push_back(Z);

        for(int i=2; i<dane.size(); i++) {
            int id_jednostki = dane.at(i);
            przydziel_jednostke_do_zdarzenia(jednostki.at(id_jednostki), zdarzenia.back());
            jednostki.at(id_jednostki).wyruszajZBazy(); 
        }
    }

}
