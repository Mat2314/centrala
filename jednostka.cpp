#include <iostream>
#include <string>
#include "jednostka.h"

using namespace std;

// Funkcja zwracająca typ jednostki
string Jednostka::get_typ_jednostki() {return typ;}

// Funkcja zwracająca status jednostki
int Jednostka::get_status() {return status;}

// Funkcja pokazująca historię jednostki
void Jednostka::show_history() {
    for(int i=0; i<10; i++) {
        //cout << historia[i] << endl;
        cout << "Tutaj będzie historia" << endl;
    }
}
