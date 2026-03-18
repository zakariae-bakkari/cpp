#include "../headers/Triangle.h"
#include <cmath>

Triangle::Triangle() : Forme(3) {
}

Triangle::Triangle(const Point &pt1, const Point &pt2, const Point &pt3) : Forme(3) {
    Sommets[0] = pt1;
    Sommets[1] = pt2;
    Sommets[2] = pt3;
}

double Triangle::aire() const {
    double x1, y1, x2, y2, x3, y3;
    Sommets[0].getXY(x1, y1);
    Sommets[1].getXY(x2, y2);
    Sommets[2].getXY(x3, y3);

    double base = Sommets[0].distance(Sommets[1]);
    double hauteur; // a fixer

    return (base * hauteur) / 2;
}
