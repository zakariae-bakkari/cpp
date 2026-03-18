//
// Created by admin on 31-Dec-25.
//
#include "../Student.h"
#include <iostream>

int Etudiant::nb_instances = 0;

Etudiant::Etudiant() {
    nb_instances++;
}

Etudiant::~Etudiant() {
    nb_instances--;
}

int Etudiant::getNbInstances() {
    return nb_instances;
}
