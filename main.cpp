#include <iostream>
#include <string>
#include "jednostka.h"
#include "zdarzenie.h"
#include "centrala.h"

using namespace std;

int main() {
    Centrala *centrala = new Centrala();
    centrala->wczytajAktywneZdarzenia();
    while(1) {
        centrala->pokazMenu();
    }
    return 0;
}
