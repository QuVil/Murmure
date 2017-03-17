#ifndef MODELE_H_INCLUDED
#define MODELE_H_INCLUDED

#include "ZoneGen.h"
#include <string>

class Modele
{
private:
    ZoneGen generateur;
    int tableau_modele[23];/**< Tableau contenant la suite d'instuctions pour le modele.*/
    //Les deux premiers entiers sont le nb minimum et max de cases desirees
    //Puis le patterne de base:
    //1=croix, 2=carre, 3=vide, 4=h, 5=hub

    // Ensuite, les iterations à faire :
    //1=voisins, 2=bruit_neg, 3=bruit_pos, 4=aleatoire, 5=epuration, 6=extension

public:
    Modele();

    Modele(std::string);

    void generer_zone();


};

#endif // MODELE_H_INCLUDED
