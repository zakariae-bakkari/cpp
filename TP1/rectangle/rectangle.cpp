//
// Created by admin on 07-Jan-26.
//

#include "rectangle.h"

#include <complex>
#include <iostream>
#include <ostream>

void rectangle::ordoner() {
    // cas 1 (x1<x2 et y1 > y2)
    if (x1 < x2 && y1 > y2)
        return;
    // cas 2
    if (x1 > x2 && y1 < y2) {
        int tempy1 = y1;
        int tempx1 = x1;
        y1 = y2;
        x1 = x2;
        y2 = tempy1;
        x2 = tempx1;
        return;
    }

    //cas 3
    if (x1 > x2 && y1 > y2) {
        int tempx1 = x1;
        x1 = x2;
        x2 = tempx1;
        return;
    }
    //cas 4
    if (x1 < x2 && y1 < y2) {
        int tempy1 = y1;
        y1 = y2;
        y2 = tempy1;
        return;
    }
}

void rectangle::afficher() const {
    std::cout << "p1(" << x1 << "," << y1 << ")----------" << std::endl;
    std::cout << "----------p2(" << x2 << "," << y2 << ")" << std::endl;
}

int *rectangle::saisier() {
    int *tableau = (int *) malloc(sizeof(int) * 4);
    std::cout << "Entrer les cordonnes du P1:" << std::endl;
    std::cout << "x1= ";
    std::cin >> tableau[0];
    std::cout << "y1= ";
    std::cin >> tableau[1];
    std::cout << "\n Entrer les cordonnes du P2:" << std::endl;
    std::cout << "x2= ";
    std::cin >> tableau[2];
    std::cout << "y2= ";
    std::cin >> tableau[3];
    return tableau;
}

bool rectangle::carre() const {
    return (x2 - x1) == (y2 - y1);
}

float rectangle::surface() const {
    return (float) (x2 - x1) * (float) (y1 - y2);
}

void rectangle::rotation90() {
    int centreX = (x1 + x2) / 2;
    int centreY = (y1 + y2) / 2;

    int milieux_side_x = x1;
    int milieux_side_y = centreY;

    int distance_entre_centre_melieux_side = centreX - milieux_side_x;
    int distance_entre_mileux_side_p1 = y1 - milieux_side_y;

    x1 = centreX - distance_entre_mileux_side_p1;
    y1 = centreY - distance_entre_centre_melieux_side;

    x2 = centreX + distance_entre_mileux_side_p1;
    y2 = centreY + distance_entre_centre_melieux_side;

    ordoner();
}

int rectangle::position(const point &p) const {
    if (p.abscisse() < x2 && p.abscisse() > x1 && p.ordonnee() > y2 && p.ordonnee() < y1)
        return 1; // exist a l'interieur

    if (p.abscisse() == x1 || p.abscisse() == x2 || p.ordonnee() == y1 || p.ordonnee() == y2)
        return 0; // exist au bordure
    return -1; // exist a l'exterieur
}

void rectangle::translation(const point &origin, const point &p) {
    int distance = std::sqrt(
        std::pow((p.abscisse() - origin.abscisse()), 2) + std::pow((p.ordonnee() - origin.ordonnee()), 2));
    x1 = origin.ordonnee() + distance;
    y1 = origin.ordonnee() + distance;
    x2 = p.ordonnee() + distance;
    y2 = origin.ordonnee() + distance;
}

int rectangle::comparer(const rectangle &r1) const {
    if (this->surface() < r1.surface()) {
        return -1;
    } else if (this->surface() > r1.surface()) {
        return 1;
    } else {
        return 0;
    }
}

int rectangle::position(const rectangle &r) const {

}
