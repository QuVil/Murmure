/**
 * \file Zone.cpp
 * \brief Code source pour le module Zone
 * \author Quentin.V
 * \version 0.1
 * \date 12 mars 2017
 * TODO : Finir de commenter les méthodes présentes.
 */

#include <iostream>

#include "Zone.h"
#include "Fichier.h"

/**
 * \brief Consctructeur
 * Le Constructeur basique de Zone, mettant la position
 * actuelle du Perso en 5,5 et vidant toutes les Salle.
 */
Zone::Zone()
{
    niveau_zone = 1;

    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            carte[i][j].vider();
        }
    }
    salle_actuelle_x = 5;
    salle_actuelle_y = 5;
}

Zone::Zone(int posx, int posy, int niv = 1)
{
    niveau_zone = niv;

    salle_actuelle_x = posx;
    salle_actuelle_y = posy;
}

Salle Zone::get_salle(int x, int y)
{
    return carte[x][y];
}

Salle Zone::get_salle()
{
    return carte[salle_actuelle_x][salle_actuelle_y];
}

void Zone::set_salle(int x, int y, const Salle &nouvelle_salle)
{
    carte[x][y] = nouvelle_salle;
}

int Zone::get_salle_actuelle_x ()const
{
        return salle_actuelle_x;
}

int Zone::get_salle_actuelle_y ()const
{
    return salle_actuelle_y;
}

void Zone::afficher_zone()
{
    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            cout<<carte[i][j].get_config()<<" ";
        }
        cout<<endl;
    }
}

void Zone::remplir_salle(int x, int y)
{
    carte[x][y].remplir();
}

void Zone::remplir_salle()
{
    carte[salle_actuelle_x][salle_actuelle_y].remplir();
}

void Zone::vider_salle(int x, int y)
{
    carte[x][y].vider();
}

void Zone::vider_salle()
{
    carte[salle_actuelle_x][salle_actuelle_y].vider();
}
