#ifndef MODELESALLE_H_INCLUDED
#define MODELESALLE_H_INCLUDED

#include "SalleGen.h"

class ModeleSalle
{
private:
    SalleGen generateur;

    int tableau_modele[22];
    //0e entier : difficulte voulue (moyenne) sur 3 chiffres (ex : 057)
    //ensuite : la config en 1ere position, puis les 4 bool de portes (haut bas gauche droite)
    //puis les actions à faire : 1 pour placer un ennemi, 2 pour placer un amas de rochers,
    //3 pour un amas de trous. Après un placement d'amas, on met un int entre 0 et 4 pour sa taille.
    //un 9 sert à marquer l'arrêt des actions.

public:
    ModeleSalle();

    ModeleSalle(std::string nom);

    void set_tableau_modele_i (int x, int i);

    void generer_salle();

    int get_case_generateur(int x, int y)const;

    ///TODO: se débarasser de afficher_tests() qui n'est qu'une procédure temporaire.
    void afficher_tests()const;
};

#endif // MODELESALLE_H_INCLUDED
