#include "../headers/Cercle.h"
#include <numbers>

#include "../headers/Forme.h"
using namespace std::numbers;

Cercle::Cercle() : rayon(0) {
}

Cercle::Cercle(const Point &centre, double rayon) : Forme(1), rayon(rayon) {
    Sommets[0] = centre;
}

void Cercle::SetRayon(double r) {
    rayon = r;
}

double Cercle::GetRayon() const {
    return rayon;
}


double Cercle::perimetre() const {
    return 2 * pi * rayon;
}

double Cercle::aire() const {
    return pi * rayon * rayon;
}
