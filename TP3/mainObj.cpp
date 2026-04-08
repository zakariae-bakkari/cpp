#include "headers/Objs_Class.h"
int main() {
    Obj_Class x;// chaine vide appele le constructeur par defaut
    x.affiche();
    x.afficheReverse();
    Obj_Class y("bateau"); // appele le construccteur avec un parametre
    y.affiche();
    y.afficheReverse();
    Obj_Class z=y; // appele le constructor par copies
    z.affiche();
    z.afficheReverse();
    if (z.compare("bateau"))
        std::cout << "identique" << std::endl;
    else std::cout << "different" << std::endl;
    return 0;
}