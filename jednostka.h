#ifndef jednostka_h
#define jednostka_h
#include <string>
#include <vector>

using namespace std;

class Jednostka {
private:
    int id; // Unikalny identyfikator jednostki
    string typ; // Policja, WOPR, Pogotowie, Straż pożarna
    int poziom; // 1 - lekka, 2 - ciężka
    int status; 
    // 0 - jednostka w bazie, 
    // 1 - jednostka pracuje 
public:
    Jednostka(){}
    Jednostka(int _id, string _typ, int _poziom, int _status); 

    int get_id();
    string get_typ_jednostki();
    int get_status();
    int get_poziom();
    bool jestWolna();
    void wyruszajZBazy();
    void powrotDoBazy();
};

#endif
