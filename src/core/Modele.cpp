/**
 * \file Modele.cpp
 * \brief fichier source du module Modele.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 17 mars 2017
 *
 */
#include "Modele.h"
#include "Fichier.h"

Modele::Modele()
{
    for (int i=11; i<23; ++i)
    {
        tableau_modele[i] = 0;
    }
    tableau_modele[0] = 25;
    tableau_modele[1] = 55;
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
    fichier.charger(*this, nom);
}

void Modele::set_tableau_modele_i(int x, int i)
{
    tableau_modele[i] = x;
}

void Modele::generer_zone()
{
    //std::cout<<"Generation de la zone"<<std::endl; //verbose à retirer...

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

    int k=0; //Si la boucle tourne plus de 100 000 fois, c'est qu'il y a un souci...
    while (!generateur.is_valide())
    {
        generateur.vider_carte();
        generateur.initialisation_gen(pat, "voisins");
        int i=3;
        while(i<22 && tableau_modele[i] != 0)
        {
            std::string met;
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
            generateur.iterer(met);
            ++i;
        }
        generateur.valider();
        generateur.teste_nb_cases_assez(nb_min);
        generateur.teste_nb_cases_trop(nb_max);
        generateur.placer_boss();
        generateur.placer_depart();
        generateur.placer_clef();
        generateur.placer_objet();

        k++;
        if (k > 100000)
        {
            break;
        }
        else if (k % 100 == 0)
        {
            std::cout<<"."<<std::endl;
        }
    }
    if (!generateur.is_valide()) {std::cout<<"Woops... la generation a echoue."<<std::endl;}
}

int Modele::get_salle_generateur(int x, int y)const
{
    return generateur.get_etat(x, y);
}

void Modele::afficher_tests()const
{
    generateur.afficher_carte();
}

int Modele::get_gen_posx_dep()
{
    return generateur.get_posx_dep();
}

int Modele::get_gen_posy_dep()
{
    return generateur.get_posy_dep();
}

