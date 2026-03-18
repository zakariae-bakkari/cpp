//
// Created by admin on 11-Feb-26.
//

#ifndef OPP_BASE_H
#define OPP_BASE_H


class base {
public:
    base (int db);
    ~base();
private:
    int m_b;
};

class derive : public base {
public:
    derive(int db, int dd);
    ~derive();
private:
    int m_d;
};




#endif //OPP_BASE_H