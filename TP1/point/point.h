//
// Created by admin on 07-Jan-26.
//

#ifndef OPP_POINT_H
#define OPP_POINT_H


class point {
private:
    int x;
    int y;
public:
    point(int x=0, int y=0):x(x),y(y){}
    int abscisse() const {return x;}
    int ordonnee() const {return y;}
};


#endif //OPP_POINT_H