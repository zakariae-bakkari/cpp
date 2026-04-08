//
// Created by admin on 01-Apr-26.
//

#ifndef CPP_INSTRUMENT_H
#define CPP_INSTRUMENT_H
#include <iostream>
#include <cstring>

class Instrument {
private:
    char* name;
    double prix;

public:
    Instrument(char* n, double p);

    Instrument(const Instrument &i);

    ~Instrument();


    // setters
    void setName(char *n);
    void setPrix(double p);
    //getters
    char* getName() const;
    double getPrix() const;

    void affiche() const;

    bool memePrix(const Instrument &i) const;

};
#endif //CPP_INSTRUMENT_H
