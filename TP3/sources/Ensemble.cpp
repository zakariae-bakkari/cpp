#include "../headers/Ensemble.h"

#include <iostream>

void Ensemble::affiche() const {
    std::cout << "{";
    for (int i = 0; i < size; i++) {
        std::cout << ensemble[i] << ",";
    }
    std::cout << "}" << std::endl;
}

Ensemble::Ensemble(int s) {
    maxsize = s;
    size = 0;
    ensemble = new int[size];
}

int Ensemble::getSize() const {
    return size;
}

bool Ensemble::appartient(int e) const {
    for (int i = 0; i < size; i++) {
        if (ensemble[i] == e) return true;
    }
    return false;
}

void Ensemble::ajouter(int e) {
    if (size == maxsize) {
        std::cout << "Erreur de ajouter : le tableau est plein" << std::endl;
        return;
    }
    if (!appartient(e)) {
        ensemble[size++] = e;
    } else {
        std::cout << "Erreur de ajouter : " << e << " est deja exist dans le tableau" << std::endl;
    }
}

Ensemble Ensemble::Union(const Ensemble &ens) const {
    Ensemble unionEnsemble(size+ens.size);
    for (int i = 0; i < size; i++) {
        unionEnsemble.ajouter(ensemble[i]);
    }
    for (int i = 0; i < ens.size; i++) {
        unionEnsemble.ajouter(ens.ensemble[i]);
    }
    return unionEnsemble;
}

