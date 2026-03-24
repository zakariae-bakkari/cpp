#include "point.h"

int main() {
    point p(1,2);
    point p2;
    p2 = p;
    p2.afficher();
    p2.setX(9);
    p.afficher();
    p2.afficher();

}
