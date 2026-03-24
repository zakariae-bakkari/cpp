//
// Created by admin on 24-Mar-26.
//

#include "rectangle.h"
#include <iostream>
using namespace std;

void Rectangle::afficher() const {
    cout << "P1: ";
    p1.afficher();
    cout << "P2: ";
    p2.afficher();
}

Rectangle::Rectangle() {
    p1 = Point(0, 0);
    p2 = Point(); // par defaut x=y=0
}

Rectangle::Rectangle(const Point &pt1, const Point &pt2) {
    p1 = pt1;
    p2 = pt2;
}

bool Rectangle::carre() const {
    double width = abs(p2.abscisse() - p1.abscisse());
    double height = abs(p1.ordonnee() - p2.ordonnee());
    return width == height;
}

void Rectangle::saisir() {
    double x1, y1, x2, y2;
    cout << "Saisir les coordonnées de P1 (x y): ";
    cin >> x1 >> y1;
    cout << "Saisir les coordonnées de P2 (x y): ";
    cin >> x2 >> y2;
    p1.setX(x1);
    p1.setY(y1);
    p2.setX(x2);
    p2.setY(y2);
}

double Rectangle::surface() const {
    double width = abs(p2.abscisse() - p1.abscisse());
    double height = abs(p1.ordonnee() - p2.ordonnee());
    return width * height;
}

void Rectangle::rotation45() {
    double centerx = (p2.abscisse() + p1.abscisse()) / 2;
    double centery = (p1.ordonnee() + p2.ordonnee()) / 2;
    // point (centerx,centery) est l'origine du rectangle
}

// le redifinition des operateur
Rectangle Rectangle::operator+(const Rectangle &r) const {
    return Rectangle(p1 + r.p1, p2 + r.p2);
}

bool Rectangle::operator==(const Rectangle &r) const {
    return (p1 == r.p1) && (p2 == r.p2);
}

