#include "polynome.h"
#include <iostream>
#include <cmath>

using namespace std;

// 1. Constructeur [cite: 1534]
Polynome::Polynome(int d) {
    if (d < 0) {
        cout << "Erreur: Degre incorrect. Utilisation valeur par defaut = 1" << endl;
        degre = 1;
    } else {
        degre = d;
    }
    contenu = new int[degre + 1]; // Allocation dynamique [cite: 1682]
    for (int i = 0; i <= degre; i++) contenu[i] = 1; // Coeffs mis à 1
}

// 2. Constructeur de recopie (copie profonde) [cite: 1658]
Polynome::Polynome(const Polynome& p) : degre(p.degre) {
    contenu = new int[degre + 1];
    for (int i = 0; i <= degre; i++) contenu[i] = p.contenu[i];
}

// Destructeur [cite: 1670]
Polynome::~Polynome() {
    delete[] contenu; // Libération de la mémoire [cite: 1674]
}

// 3. Méthode affiche()
void Polynome::affiche() const {
    bool premier = true;
    for (int i = 0; i <= degre; i++) {
        if (contenu[i] != 0) {
            if (!premier && contenu[i] > 0) cout << "+";
            if (i == 0) cout << contenu[i];
            else if (i == 1) cout << contenu[i] << "x";
            else cout << contenu[i] << "x^" << i;
            premier = false;
        }
    }
    cout << endl;
}

// 4. Surcharge <<
ostream& operator<<(ostream& os, const Polynome& p) {
    os << "[";
    for (int i = 0; i <= p.degre; i++) {
        os << p.contenu[i] << (i == p.degre ? "" : ",");
    }
    os << "]";
    return os;
}

// 5. Surcharge >>
istream& operator>>(istream& is, Polynome& p) {
    cout << "Saisie des " << p.degre + 1 << " coefficients : " << endl;
    for (int i = 0; i <= p.degre; i++) {
        cout << "Coeff x^" << i << " : ";
        is >> p.contenu[i];
    }
    return is;
}

// 6. Opérateur == [cite: 1887]
bool Polynome::operator==(const Polynome& p) const {
    if (degre != p.degre) return false;
    for (int i = 0; i <= degre; i++) {
        if (contenu[i] != p.contenu[i]) return false;
    }
    return true;
}

// 7. Opérateur * (P * k)
Polynome Polynome::operator*(double k) const {
    Polynome res(degre);
    for (int i = 0; i <= degre; i++) res.contenu[i] = contenu[i] * k;
    return res;
}

// 8. Question théorique et pratique
// Selon vous, est-il possible de calculer k*P ? 
// Non, pas via une méthode membre car le premier opérande est un réel (double). 
// Pour débloquer la situation, il faut définir une fonction amie (friend).
Polynome operator*(double k, const Polynome& p) {
    return p * k; // On réutilise l'opérateur déjà défini (commutativité)
}