#include "../headers/Forme.h"
#include <iostream>

using namespace std;

Forme::Forme(int nbsommets) {
    if (nbsommets <= 0) {
        cout << "Nombre de sommets must be positive" << endl;
        this->NbSommets = 1;
    }

    this->NbSommets = nbsommets;
    this->Sommets = new Point[nbsommets];
}

Forme::~Forme() {
    delete[] this->Sommets;
}

void Forme::SetPoint(int i, const Point &pt) {
    Sommets[i] = pt;
}

Point Forme::GetPoint(int i) const {
    return Sommets[i];
}

int Forme::GetNbSommets() const {
    return NbSommets;
}


void Forme::afficher() const {
    cout << "Sommets: " << NbSommets << endl;;
    for (int i = 0; i < NbSommets; i++) {
        Sommets[i].afficher();
    }
}

double Forme::perimetre() const {
    double perimetre = 0;
    for (int i = 0; i < NbSommets; i++) {
        perimetre += Sommets[i].distance(Sommets[(i + 1) % NbSommets]);
    }
    return perimetre;
}

void Forme::translation(const Point &pt) {
    for (int i = 0; i < NbSommets; i++) {
        Sommets[i] = Sommets[i].add(pt);
    }
}
