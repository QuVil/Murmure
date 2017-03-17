#include "Modele.h"
#include "Fichier.h"

Modele::Modele()
{
    for (int i=0; i<23; ++i)
    {
        tableau_modele[i] = 0;
    }
    tableau_modele[0] = 25;
    tableau_modele[1] = 42;
    tableau_modele[2] = 2;

    tableau_modele[3] = 1;
    tableau_modele[4] = 1;
    tableau_modele[5] = 1;
    tableau_modele[6] = 1;
    tableau_modele[7] = 1;
    tableau_modele[8] = 4;
    tableau_modele[9] = 5;
    tableau_modele[10] = 6;
}

Modele::Modele(std::string nom)
{
    for (int i=0; i<23; ++i)
    {
        tableau_modele[i] = 0;
    }
    Fichier fichier;
    fichier.charger(*this);
}

void Modele::generer_zone()
{
    int nb_min = tableau_modele[0];
    int nb_max = tableau_modele[1];
    std::string pat;
    switch(tableau_modele[2])
            {
            case 1:
                pat = "croix";
                break;
            case 2:
                pat = "carre";
                break;
            case 3:
                pat = "vide";
                break;
            case 4:
                pat = "h";
                break;
            case 5:
                pat = "hub";
                break;
            default:
                pat = "carre";
            }

    while (!generateur.is_valide())
    {
        generateur.vider_carte();
        int i=3;
        while(i<22 && tableau_modele[i] != 0)
        {
            std:string met;
            switch(tableau_modele[i])
            {
            case 1:
                met = "voisins";
                break;
            case 2:
                met = "bruit_neg";
                break;
            case 3:
                met = "bruit_pos";
                break;
            case 4:
                met = "aleatoire";
                break;
            case 5:
                met = "epuration";
                break;
            case 6:
                met = "extension";
                break;
            default:
                met = "voisins";
            }


            ++i;
        }
    }
}
