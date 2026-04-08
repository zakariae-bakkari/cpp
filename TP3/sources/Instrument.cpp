#include "../headers/Instrument.h"

Instrument::Instrument(char *n, double p) {
    this->name = strdup(n);
    this->prix = p;
}

Instrument::Instrument(const Instrument &i) {
    this->name = strdup(i.name);
    this->prix = i.prix;
}

Instrument::~Instrument() {
    free(this->name);
}


void Instrument::setName(char *n) {
    free(this->name);
    this->name = strdup(n);
}

void Instrument::setPrix(double p) {
    this->prix = p;
}

char *Instrument::getName() const {
    return strdup(this->name);
}

double Instrument::getPrix() const {
    return this->prix;
}

void Instrument::affiche() const {
    std::cout << "Name: " << this->name << " Prix: " << this->prix << std::endl;
}

bool Instrument::memePrix(const Instrument &i) const {
    return prix == i.prix;
}
