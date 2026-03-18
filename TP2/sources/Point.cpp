#include  "../headers/Point.h"
#include <cmath>
#include  <iostream>

using namespace std;

Point::Point(double x, double y) : x(x), y(y) {}

Point Point::add(const Point &pt) const {
    return Point(x + pt.x, y + pt.y);
}

void Point::afficher() const {
    cout << "point(" << x << "," << y << ")" << endl;
}

void Point::getXY(double &outx, double &outy) const {
    outx = x;
    outy = y;
}

void Point::setXY(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::distance(const Point &pt) const {
    return sqrt(pow(x - pt.x, 2) + pow(y - pt.y, 2));
}

double Point::vectoriel(const Point &pt1, const Point &pt2) {
    return (this->)
}
