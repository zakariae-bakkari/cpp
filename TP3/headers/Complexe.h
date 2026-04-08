//
// Created by admin on 01-Apr-26.
//

#ifndef CPP_COMPLEXE_H
#define CPP_COMPLEXE_H

class Complexe {
    double re;
    double im;

public:
    Complexe(double r = 1, double i = 0) : re{r}, im{i}{};
    // setters
    void setRe(double r) {
        this->re = r;
    }
    void setIm(double i) {
        this->im = i;
    }

    //getters
    double getRe() const{
        return this->re;
    }
    double getIm() const{
        return this->im;
    }

    // module
    double
};
#endif //CPP_COMPLEXE_H
