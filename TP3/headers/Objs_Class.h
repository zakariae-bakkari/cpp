//
// Created by admin on 01-Apr-26.
//

#ifndef CPP_OBJS_CLASS_H
#define CPP_OBJS_CLASS_H
#include <iostream>
#include <cstring>
#include <bits/stl_list.h>

class Obj_Class {
private:
    char* chaine;
    public:
    Obj_Class(char* chaine);
    Obj_Class();
    Obj_Class(const Obj_Class &obj);

    ~Obj_Class();

    void affiche() const ;
    void afficheReverse() const;
    bool compare(char *chaine)const;
};
#endif //CPP_OBJS_CLASS_H