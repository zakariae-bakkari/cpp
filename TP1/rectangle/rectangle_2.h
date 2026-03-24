#ifndef Rectangle_H
#define Rectangle_H

#include "../point/point.h"

class Rectangle {
private:
    point P1, P2;
    void ordonner();

public:
    Rectangle();
    Rectangle(int x1 , int y1, int x2, int y2 );
    Rectangle(const point &p1, const point &p2);

    point getP1() const { return P1; }
    point getP2() const { return P2; }

    void afficher() const;
    void saisir();
    bool carre() const;
    int surface() const;
    void rotation90();

    int position(const point &p) const;
    void translation(const point &origine, const point &p);

    int comparer(const Rectangle& r) const;
    int position(const Rectangle &r) const;

    Rectangle unionRect(const Rectangle& r) const;

    Rectangle intersection(const Rectangle& r) const;

    int intersection(const Rectangle& r, Rectangle& result) const;


};

#endif