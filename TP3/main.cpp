#include "headers/Instrument.h"

int main() {
    // Instrument i = Instrument("i1",100.3);
    // char * n=i.getName();
    // i.affiche();
    // n[0]='p';
    // n[1]='p';
    // i.affiche();
    Instrument A("Saxophone",750.80);
    Instrument B=A;
    Instrument C("Guitare",380.96);
    if (C.memePrix(B)) {
        std::cout << "la guitare/saxophone ont meme prix";
    }else {
        std::cout << "la guitare/saxophone ont des prix different";
    }
    return 0;
}