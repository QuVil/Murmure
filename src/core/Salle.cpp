#include <iostream>

#include "Salle.h"
#include "Fichier.h"

Salle::Salle()
{
    config = 1;

    Fichier fichier;
    fichier.charger(*this);
}

CaseSalle Salle::get_case(int i,int j)
{
    return grille[i][j];
}

void Salle::set_case(int i, int j, CaseSalle c)
{
    grille[i][j] = c;
}


int Salle::get_config()
{
    return config;
}

void Salle::afficher()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<21;j++)
        {
            grille[i][j].afficher();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
