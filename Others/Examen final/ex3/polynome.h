#ifndef POLYNOME_H
#define POLYNOME_H

#include <iostream>

class Polynome {
private:
    int degre;      // L'entier degré
    int* contenu;   // Tableau dynamique pour les coefficients

public:
    // 1. Constructeur avec valeur par défaut
    Polynome(int d = 1);

    // 2. Constructeur de recopie
    Polynome(const Polynome& p);

    // Destructeur (nécessaire pour libérer le tableau dynamique) [cite: 1674]
    ~Polynome();

    // 3. Méthode affiche()
    void affiche() const;

    // 6. Opérateur ==
    bool operator==(const Polynome& p) const;

    // 7. Opérateur * (P * k)
    Polynome operator*(double k) const;

    // 4. & 5. Opérateurs << et >> (déclarés amis)
    friend std::ostream& operator<<(std::ostream& os, const Polynome& p);
    friend std::istream& operator>>(std::istream& is, Polynome& p);

    // 8. Déblocage de k * P (nécessite une fonction amie)
    friend Polynome operator*(double k, const Polynome& p);
};

#endif