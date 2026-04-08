#include "../headers/Objs_Class.h"

Obj_Class::Obj_Class(char *chaine) {
    this->chaine = strdup(chaine);
}

Obj_Class::Obj_Class(const Obj_Class &obj) {
    this->chaine = strdup(obj.chaine);
}

Obj_Class::Obj_Class() {
    this->chaine = strdup("");
}

Obj_Class::~Obj_Class() {
    free(this->chaine);
}

void Obj_Class::affiche() const {
    std::cout << chaine << std::endl;
}

void Obj_Class::afficheReverse() const {
    int dernierIndice = strlen(chaine) - 1;
    while (dernierIndice >= 0) {
        std::cout << chaine[dernierIndice];
        dernierIndice--;
    }
    std::cout << std::endl;
}

bool Obj_Class::compare(char *n) const {
    return strcmp(n, this->chaine) == 0;
}
