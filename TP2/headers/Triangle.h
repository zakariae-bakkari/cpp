#ifndef CPP_TRIANGLE_H
#define CPP_TRIANGLE_H
#include "Forme.h"
#include "Point.h"

class Triangle : public Forme {
public:
    Triangle();
    Triangle(const Point &pt1, const Point &pt2, const Point &pt3);

    double aire() const;
};
#endif //CPP_TRIANGLE_H
