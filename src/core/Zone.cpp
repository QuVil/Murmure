/**
 * \file Zone.cpp
 * \brief Code source pour le module Zone
 * \author Quentin.V
 * \version 0.2
 * \date 18 mars 2017
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Zone.h"
#include "Fichier.h"

//constructeur de base, avec toutes les salles vides et le nom "Zone"
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

//crée une instance de zone en passant en paramètre les coordonnées de la salle
//actuelle et son nom
Zone::Zone(int posx, int posy, int niv = 1)
{
    niveau_zone = niv;

    salle_actuelle_x = posx;
    salle_actuelle_y = posy;
}

Zone::Zone(const ZoneGen &z)
{
    salle_actuelle_x = z.get_posx_dep();
    salle_actuelle_y = z.get_posy_dep();

    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            carte[i][j].set_config(z.get_etat(i, j));
        }
    }
}

Salle Zone::get_salle(int x, int y)
{
    return carte[x][y];
}

Salle Zone::get_salle()const
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
            if (carte[i][j].get_config() == 0)
                std::cout<<"- ";
            else if (carte[i][j].get_config() == 2)
                std::cout<<"b ";
            else if (carte[i][j].get_config() == 3)
                std::cout<<"c ";
            else if (carte[i][j].get_config() == 4)
                std::cout<<"d ";
            else if (carte[i][j].get_config() == 5)
                std::cout<<"o ";
            else
                std::cout<<"X ";
        }
        std::cout<<std::endl;
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

void Zone::zone_depuis_modele(std::string nom)
{
    Modele mod(nom);
    mod.generer_zone();

    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            carte[i][j].set_config(mod.get_salle_generateur(i, j));
        }
    }
}

void Zone::zone_depuis_modele_aleatoire(int taille/* = 0 */)
{
    //taille est entre 1 et 3 si elle est spécifiée. 1=normal, 2=grand, 3=immense.
    std::string nom_aleat;
    //Si la taille générale n'est pas spécifiée, on prend vraiment au hasard.
    if (taille == 0)
    {
        int nb_aleat = rand() % 5;

        switch(nb_aleat)
        {
            case 0:
                nom_aleat = "test";
                break;
            case 1:
                nom_aleat = "test_vide";
                break;
            case 2:
                nom_aleat = "test_croix";
                break;
            case 3:
                nom_aleat = "test_h";
                break;
            default:
                nom_aleat = "defaut";
                break;
        }
    }
    else
    {
        //Sinon, on discrimine en fonction de la taille...
        //La configuration de cette procédure est à faire à la main à chaque nouveau Modele
        //dans les fichiers. Oui c'est embêtant, mais moins que les autres alternatives je suppose.
        if (taille == 1) //si la taille est sur 'normale'
        {
            int nb_aleat1 = rand() % 2;

            switch(nb_aleat1)
            {
                case 0:
                    nom_aleat = "test_croix";
                    break;
                case 1:
                    nom_aleat = "test_h";
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else if (taille == 2) //si la taille est sur 'grande'
        {
            int nb_aleat2 = rand() % 3;
            switch(nb_aleat2)
            {
                case 0:
                    nom_aleat = "test_vide";
                    break;
                case 1:
                    nom_aleat = "test_hub";
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else if (taille == 3) //si la taille est sur 'immense'
        {
            int nb_aleat3 = rand() % 2;
            switch(nb_aleat3)
            {
                case 0:
                    nom_aleat = "test";
                    break;
                case 1:
                    nom_aleat = "test";
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else //si la taille spécifiée est incorrecte, on prend le modele par defaut.
        {
            nom_aleat = "defaut";
        }
    }



    zone_depuis_modele(nom_aleat);
    ///TODO : ces lignes de tests doivent être changées / supprimées...
    CaseSalle case_test;
    case_test.set_type('t');
    carte[salle_actuelle_x][salle_actuelle_y].set_case(3, 5, case_test);
}
