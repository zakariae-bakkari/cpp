#ifndef CPP_FORM_H
#define CPP_FORM_H
#include "Point.h"

class Forme {
protected:
    int NbSommets;
    Point *Sommets;

public:
    Forme(int nbsommets = 3);
    ~Forme();
    inline void SetPoint(int i, const Point &pt) { Sommets[i] = pt; }

    inline Point GetPoint(int i) const { return Sommets[i]; }

    void afficher() const;

    double perimetre() const;

    virtual double aire() const;

    inline int GetNbSommets() const { return NbSommets; }

    void translation(const Point &pt);
};
#endif //CPP_FORM_H
