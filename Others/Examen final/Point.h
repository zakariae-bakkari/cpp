#include <inttypes.h>
#include <iostream>
#ifndef CPP_POINT_H
#define CPP_POINT_H
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {
    };

    int abscisse() const { return x; }

    int ordonnee() const { return y; }

    void setX(int x) { this->x = x; }

    void setY(int y) { this->y = y; }

    void afficher() const {
        cout << "P(" << x << "," << y << ")" << endl;
    }

    // surcharge des operateurs
    Point operator+(const Point &p1) const {
        return Point(x + p1.x, y + p1.y);
    }

    Point operator-(const Point &p1) const {
        return Point(x - p1.x, y - p1.y);
    }

    Point operator*(const Point &p1) const {
        return Point(x * p1.x, y * p1.y);
    }

    Point operator/(const Point &p1) const {
        if (p1.x == 0 || p1.y == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Point(x / p1.x, y / p1.y);
    }

    bool operator==(const Point &p1) const {
        return x == p1.x && y == p1.y;
    }
};
#endif //CPP_POINT_H
