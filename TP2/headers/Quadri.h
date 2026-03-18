#ifndef CPP_QUADRI_H
#define CPP_QUADRI_H
#include "Forme.h"

class Quadri: public Forme {
public:
    Quadri();
    Quadri(Point &pt1, Point &pt2, Point &pt3, Point &pt4);

    double aire() const;
};
#endif //CPP_QUADRI_H