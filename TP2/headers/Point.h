#ifndef OPP_POINT_H
#define OPP_POINT_H

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0);

    Point add(const Point &pt) const;

    void afficher() const;

    void getXY(double &outx, double &outy) const;

    void setXY(double x, double y);

    double distance(const Point &pt) const;

    static double vectoriel(const Point &pt, const Point &pt2);
};
#endif //OPP_POINT_H
