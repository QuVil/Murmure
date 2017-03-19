/**
 * \file Salle.cpp
 * \brief Code source pour le module Salle.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 11 mars 2017
 *
 */

#include <iostream>

#include "Salle.h"
#include "Fichier.h"

Salle::Salle()
{
    config = 1;
    Fichier fichier;
    fichier.charger(*this);
}

Salle::Salle(int conf)
{
    config = conf;
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

void Salle::set_config(int c)
{
    config = c;
}

bool Salle::is_deja_visitee()const
{
    return deja_visitee;
}

void Salle::set_deja_visitee(bool visite)
{
    deja_visitee = visite;
}

void Salle::remplir()
{
    config = 1;
}

void Salle::vider()
{
    config = -1;
}

Salle& Salle::operator = (Salle salle2)
    {
        for (int i=0; i<nb_cases_hauteur; ++i)
        {
            for (int j=0; j<nb_cases_largeur; ++j)
                grille[i][j] = salle2.get_case(i, j);
        }
        config = salle2.get_config();
        return *this;
    }

void Salle::afficher()
{
    for(int i=0;i<nb_cases_hauteur;i++)
    {
        for(int j=0;j<nb_cases_largeur;j++)
        {
            grille[i][j].afficher();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

int Salle::get_nb_cases_largeur()
{
    return nb_cases_largeur;
}

int Salle::get_nb_cases_hauteur()
{
    return nb_cases_hauteur;
}

std::string Salle::get_config_string() const
{
    switch(config)
    {
        case 0:
            return "vide";
            break;
        case 1:
            return "normal";
            break;
        case 2:
            return "boss";
            break;
        case 3:
            return "clef";
            break;
        case 4:
            return "depart";
            break;
        case 5:
            return "objet";
            break;
        default:
            return "vide";
            break;
    }
}
