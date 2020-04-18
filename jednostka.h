#ifndef jednostka_h
#define jednostka_h
#include "zdarzenie.h"
#include <string>

using namespace std;

class Jednostka {
private:
    string typ; // Policja, WOPR, Pogotowie, Straż pożarna
    int status; 
    // 0 - jednostka w bazie, 
    // 1 - jednostka w drodze na miejsce zdarzenia
    // 2 - jednostka na miejscu zdarzenia
    // 3 - jednostka wraca do bazy
    Zdarzenie historia[10]; // Historia 10 ostatnich zdarzeń
    Zdarzenie zdarzenie; // Zdarzenie do którego jest aktualnie oddelegowana jednostka
public:
    Jednostka(){}

    string get_typ_jednostki();
    int get_status();
    void show_history();
    
};

#endif
