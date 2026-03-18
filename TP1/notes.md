## Ambiguïté avec les fonctions surchargées
void imprimer(int valeur) {
std::cout << valeur << std::endl;}
void imprimer(int valeur, int base = 10) {
std::cout << valeur << base << std::endl;
}

int main() {
imprimer(5);
imprimer(5, 16);
return 0;
}
### error: call of overloaded 'imprimer(int)' is ambiguous

### une mauvaise conception la surcharge de fonctions avec des paramètres par défaut peut entraîner des ambiguïtés lors de l'appel de ces fonctions. Dans l'exemple ci-dessus, l'appel à `imprimer(5)` est ambigu car il pourrait correspondre à deux définitions différentes de la fonction `imprimer`.