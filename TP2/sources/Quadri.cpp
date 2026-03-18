#include "../headers/Quadri.h"
#include <cmath>

Quadri::Quadri() : Forme(4) {}

Quadri::Quadri(Point &pt1, Point &pt2, Point &pt3, Point &pt4) : Forme(4) {
    Sommets[0] = pt1;
    Sommets[1] = pt2;
    Sommets[2] = pt3;
    Sommets[3] = pt4;
}

double Quadri::aire() const {

}

