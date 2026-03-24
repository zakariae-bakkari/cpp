//
// Created by admin on 07-Jan-26.
//

#ifndef OPP_POINT_H
#define OPP_POINT_H

#include <iostream>

class point {
private:
    int x;
    int y;

public:
    point(int x = 0, int y = 0) : x(x), y(y) {
    }

    int abscisse() const { return x; }
    int ordonnee() const { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    void afficher() const {
        std::cout << "point(" << x << "," << y << ")" << std::endl;
    }
};


#endif //OPP_POINT_H
