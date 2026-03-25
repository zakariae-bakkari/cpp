#include "Point.h"
#include <iostream>

#include "rectangle.h"

using namespace std;

int main() {
    // p1
    Point p1 = Point(1, 2);
    Point p2 = Point(2, 3);
    Point p3 = p1 + p2;
    p1.afficher();
    p2.afficher();
    p3.afficher();
    if (p1 == p2) {
        cout << "p1 et p2 sont égaux" << endl;
    } else {
        cout << "p1 et p2 sont différents" << endl;
    }
    const Rectangle r1 = Rectangle(p1, p2);
    r1.afficher();
}
