#include "headers/Point.h"
#include "headers/Triangle.h"
int main() {
    Point p = Point(1, 2);
    p.afficher();
    Triangle t = Triangle(1, 2, 3);
    t.afficher();
    return 0;
}
