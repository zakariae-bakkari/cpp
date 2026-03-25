//
// Created by admin on 24-Mar-26.
//

#ifndef CPP_RECTANGLE_H
#define CPP_RECTANGLE_H
#include "Point.h"

class Rectangle {
private:
    // composition forte
    Point p1;
    Point p2;

public:
    Rectangle();

    Rectangle(const Point &pt1, const Point &pt2);

    void afficher() const;

    void saisir();

    bool carre() const;

    double surface() const;

    void rotation45();

    Rectangle operator+(const Rectangle &r) const;
    bool operator==(const Rectangle &r) const;

};


#endif //CPP_RECTANGLE_H
