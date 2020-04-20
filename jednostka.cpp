#include <iostream>
#include <string>
#include "jednostka.h"

using namespace std;

Jednostka::Jednostka(int _id, string _typ, int _poziom, int _status) {
    id = _id;
    typ = _typ;
    poziom = _poziom;
    status = _status;
}

// Funkcja zwracająca typ jednostki
string Jednostka::get_typ_jednostki() {return typ;}

// Funkcja zwracająca status jednostki
int Jednostka::get_status() {return status;}

// Funkcja zwraca poziom danej jednostki
int Jednostka::get_poziom() {return poziom;}

// Funkcja zmieniająca status jednostki 
void Jednostka::wyruszajZBazy() {
    status = 1;
}

void Jednostka::powrotDoBazy() {
    status = 0;
}

// Funkcja sprawdza czy dana jednostka jest wolna czy aktualnie zajęta
bool Jednostka::jestWolna() { 
    if (status == 0) {
        return true;
    }
    return false;
}
