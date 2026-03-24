#include <iostream>

#include "rectangle/rectangle_2.h"
using namespace std;

int main()
{
    int n;
    cout << "Nombre de rectangles: ";
    cin >> n;

    Rectangle* tab = new Rectangle[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Rectangle " << i+1 << " -> ";
        tab[i].saisir();
    }

    // Calcul de l'intersection cumulative
    Rectangle inter = tab[0];
    bool valide = true;

    for (int i = 1; i < n && valide; i++)
    {
        Rectangle tmp(0,0,0,0);
        if (inter.intersection(tab[i], tmp) == 0)
        {
            cout << "L'intersection est vide." << endl;
            valide = false;
        }
        else
        {
            inter = tmp;
        }
    }

    if (valide)
    {
        cout << "Intersection de tous les rectangles: ";
        inter.afficher();
    }

    delete[] tab;
    return 0;
}