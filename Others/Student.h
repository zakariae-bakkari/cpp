//
// Created by admin on 28-Dec-25.
//

#ifndef OPP_STUDENT_H
#define OPP_STUDENT_H
class Etudiant {
private:
    static int  nb_instances;
public:
    Etudiant();
    ~Etudiant();
    static int getNbInstances();
};
#endif //OPP_STUDENT_H