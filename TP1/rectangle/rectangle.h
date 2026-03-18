#ifndef OPP_RECTANGLE_H
#define OPP_RECTANGLE_H
#include "../point/point.h"

class rectangle {
private:
    int x1;
    int y1;
    int x2;
    int y2;

public:
    rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : x1(x1), y1(y1), x2(x2), y2(y2) {
        ordoner();
    }
    rectangle(const point &p1, const point &p2) : x1(p1.abscisse()), y1(p1.ordonnee()), x2(p2.abscisse()),
    y2(p2.ordonnee()) {
        ordoner();
    }

    // Getters
    inline int getX1() const { return x1; }
    inline int getY1() const { return y1; }
    inline int getX2() const { return x2; }
    inline int getY2() const { return y2; }

    // Setters
    inline void setX1(int x) { x1 = x; }
    inline void setY1(int y) { y1 = y; }
    inline void setX2(int x) { x2 = x; }
    inline void setY2(int y) { y2 = y; }


    void afficher() const;

    static int *saisier();

    bool carre() const;

    float surface() const;

    void rotation90();


    int position(const point &p) const;

    void translation(const point &origin, const point &p);

    int comparer(const rectangle &r1) const;

    int position(const rectangle &r) const;

    void ordoner();
};


#endif //OPP_RECTANGLE_H
