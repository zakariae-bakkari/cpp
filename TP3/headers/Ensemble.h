//
// Created by admin on 01-Apr-26.
//

#ifndef CPP_ENSEMBLE_H
#define CPP_ENSEMBLE_H

class Ensemble {
private:
    int size;
    int maxsize;
    int *ensemble;

public:
    Ensemble(int s = 5);

    bool appartient(int e) const;

    int getSize() const;

    void ajouter(int e);

    Ensemble Union(const Ensemble &ens) const;

    void affiche() const ;
};
#endif //CPP_ENSEMBLE_H
