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

    inline void SetPoint(int i, const Point &pt);

    inline Point GetPoint(int i) const;

    void afficher() const;

    double perimetre() const;

    virtual double aire() const =0;// purement virtual -> class abstrait

    inline int GetNbSommets() const;

    void translation(const Point &pt);
};
#endif //CPP_FORM_H
