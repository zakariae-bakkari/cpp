#include "rectangle_2.h"
#include <iostream>

Rectangle::Rectangle()
{
    P1 = point(0, 0);
    P2 = point(0, 0);
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
    P1 = point(x1, y1);
    P2 = point(x2, y2);
    ordonner();
}

Rectangle::Rectangle(const point &p1, const point &p2)
{
    P1 = p1;
    P2 = p2;

    ordonner();
}

void Rectangle::ordonner()
{
    if (P1.abscisse() > P2.abscisse())
    {
        int tempX = P1.abscisse();
        P1.setX(P2.abscisse());
        P2.setX(tempX);
    }
    if (P1.ordonnee() < P2.ordonnee())
    {
        int tempY = P1.ordonnee();
        P1.setY(P2.ordonnee());
        P2.setY(tempY);
    }
}

void Rectangle::afficher() const
{
    std::cout << "les cordonnes du points:" << std::endl;
    P1.afficher();
    P2.afficher();
}

void Rectangle::saisir()
{
    int x1, y1, x2, y2;
    std::cout << "Saisir P1.abscisse() : ";
    std::cin >> x1;
    std::cout << "Saisir P1.ordonnee() : ";
    std::cin >> y1;
    std::cout << "Saisir P2.abscisse() : ";
    std::cin >> x2;
    std::cout << "Saisir P1.ordonnee() : ";
    std::cin >> y2;
    P1.setX(x1);
    P1.setY(y1);
    P2.setX(x2);
    P2.setY(y2);
    ordonner();
}

bool Rectangle::carre() const
{
    int X = P2.abscisse() - P1.abscisse();
    int Y = P2.ordonnee() - P1.ordonnee();
    if (X == Y)
        return true;
    return false;
}

int Rectangle::surface() const
{
    int X = P2.abscisse() - P1.abscisse();
    int Y = P2.ordonnee() - P1.ordonnee();
    return X * Y;
}

void Rectangle::rotation90()
{
    int centrex = (P1.abscisse() + P2.abscisse()) / 2;
    int centrey = (P1.ordonnee() + P2.ordonnee()) / 2;

    int milieux = (P2.abscisse() - P1.abscisse()) / 2;
    int milieuy = (P1.ordonnee() - P2.ordonnee()) / 2;

    P1.setX(centrex - milieuy);
    P1.setY(centrey + milieux);
    P2.setX(centrex + milieuy);
    P2.setY(centrey - milieux);

    ordonner();
}

int Rectangle::position(const point &p) const
{
    if (p.abscisse() < P2.abscisse() && p.abscisse() > P1.abscisse() && p.ordonnee() > P2.abscisse() && p.ordonnee() < P1.ordonnee())
        return 1; // exist a l'interieur

    if (p.abscisse() == P1.abscisse() || p.abscisse() == P2.abscisse() || p.ordonnee() == P1.ordonnee() || p.ordonnee() == P2.ordonnee())
        return 0; // exist au bordure
    return -1;    // exist a l'exterieur
}

void Rectangle::translation(const point &origine, const point &p)
{
    int dx = p.abscisse() - origine.abscisse();
    int dy = p.ordonnee() - origine.ordonnee();

    P1.setX(P1.abscisse() + dx);
    P2.setX(P2.abscisse() + dx);
    P1.setY(P1.ordonnee() + dy);
    P2.setY(P2.ordonnee() + dy);
}

int Rectangle::comparer(const Rectangle &r) const
{
    int s1 = surface();
    int s2 = r.surface();
    if (s1 < s2)
        return -1;
    else if (s1 > s2)
        return 1;
    else
        return 0;
}

int Rectangle::position(const Rectangle &r) const
{
    if (P1.abscisse() < r.P1.abscisse() && P1.ordonnee() < r.P1.ordonnee() && P2.abscisse() > r.P2.abscisse() && P1.ordonnee() > r.P1.ordonnee())
        return 1;
    if (r.P1.abscisse() < P1.abscisse() && r.P1.ordonnee() < P1.ordonnee() && r.P2.abscisse() > P2.abscisse() && r.P1.ordonnee() > P1.ordonnee())
        return 2;

    bool vide = (P2.abscisse() < r.P1.abscisse()) || (P1.abscisse() > r.P2.abscisse()) || (P1.ordonnee() < r.P1.ordonnee()) || (P1.ordonnee() > r.P1.ordonnee());
    if (vide)
        return -1;
    return 0;
}

Rectangle Rectangle::unionRect(const Rectangle &r) const
{
    Rectangle u;
    u.P1.setX((P1.abscisse() < r.P1.abscisse()) ? P1.abscisse() : r.P1.abscisse());
    u.P1.setY((P1.ordonnee() < r.P1.ordonnee()) ? P1.ordonnee() : r.P1.ordonnee());
    u.P2.setX((P2.abscisse() > r.P2.abscisse()) ? P2.abscisse() : r.P2.abscisse());
    u.P2.setY((P2.ordonnee() > r.P2.ordonnee()) ? P2.ordonnee() : r.P2.ordonnee()); // ✓ Correction
    return u;
}

Rectangle Rectangle::intersection(const Rectangle &r) const
{
    Rectangle inter;
    inter.P1.setX((P1.abscisse() > r.P1.abscisse()) ? P1.abscisse() : r.P1.abscisse());
    inter.P1.setY((P1.ordonnee() > r.P1.ordonnee()) ? P1.ordonnee() : r.P1.ordonnee());
    inter.P2.setX((P2.abscisse() < r.P2.abscisse()) ? P2.abscisse() : r.P2.abscisse());
    inter.P2.setY((P2.ordonnee() < r.P2.ordonnee()) ? P2.ordonnee() : r.P2.ordonnee());

    if (inter.P1.abscisse() >= inter.P2.abscisse() || inter.P1.ordonnee() >= inter.P2.ordonnee())
    {
        inter.P1.setX(0);
        inter.P1.setY(0);
        inter.P2.setX(0);
        inter.P2.setY(0);
    }
    return inter;
}

int Rectangle::intersection(const Rectangle &r, Rectangle &result) const
{
    result.P1.setX((P1.abscisse() > r.P1.abscisse()) ? P1.abscisse() : r.P1.abscisse());
    result.P1.setY((P1.ordonnee() > r.P1.ordonnee()) ? P1.ordonnee() : r.P1.ordonnee());
    result.P2.setX((P2.abscisse() < r.P2.abscisse()) ? P2.abscisse() : r.P2.abscisse());
    result.P2.setY((P2.ordonnee() < r.P2.ordonnee()) ? P2.ordonnee() : r.P2.ordonnee());

    if (result.P1.abscisse() >= result.P2.abscisse() || result.P1.ordonnee() >= result.P2.ordonnee())
    {
        result.P1.setX(0);
        result.P1.setY(0);
        result.P2.setX(0);
        result.P2.setY(0);
        return 0;
    }
    return 1;
}
