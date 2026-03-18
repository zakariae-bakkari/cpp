#include <iostream>
#include "../Student.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    {
        Etudiant e1,e2,e3;
        std::cout << "Resultas" <<std::endl;
        std::cout << Etudiant::getNbInstances()<< std::endl;
        Etudiant e4,e5;
        std::cout << Etudiant::getNbInstances() << std::endl;
    }
    std::cout << Etudiant::getNbInstances() << std::endl;
    return 0;
}