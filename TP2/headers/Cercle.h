#ifndef CPP_CERCLE_H
#define CPP_CERCLE_H
#include "Forme.h"

class Cercle : public  Forme {
private:double rayon;
public:
    Cercle();
    Cercle(const Point &centre, double rayon);
    double aire() const override;
    double perimetre() const;
    inline void SetRayon(double r);
    inline double GetRayon() const;
};
#endif //CPP_CERCLE_H