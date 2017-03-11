#ifndef GENERATION_TESTS_H_INCLUDED
#define GENERATION_TESTS_H_INCLUDED

#include <string>

class CarteGen
{
private:
    int carte[11][11];
    std::string patterne; //patterne = le motif de base de la carte à sa création
    std::string methode;  //methode = méthode d'itération de création de carte
    bool pret_iteration;  //pret_iteration = l'instance est-elle prête à itérer ?
    bool valide; //valide = la carte est-elle jouable ?
    //patternes : croix, carre, h, vide, hub
    //methodes : voisins, bruit, aleatoire, epuration

public:
    CarteGen();

}

#endif // GENERATION_TESTS_H_INCLUDED
