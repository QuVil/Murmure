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

void Salle::salle_depuis_modele(std::string nom, bool p_h, bool p_b, bool p_g, bool p_d, int conf)
{
    ModeleSalle mod_s(nom);
    mod_s.generer_salle(p_h, p_b, p_g, p_d, conf);

    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            grille[i][j].set_type(mod_s.get_case_generateur(i, j));
        }
    }
    difficulte = mod_s.get_difficulte();
}

void Salle::salle_depuis_modele_aleatoire(bool p_h, bool p_b, bool p_g, bool p_d, int conf, int diff /*= 0 */)
{
    //diff est la difficulte approximative (la salle générée ne sera pas exactement de difficulte = diff...)
    std::string nom_aleat;
    //Si la difficulte n'est pas spécifiée ou =0 : au pif
    if (diff == 0)
    {
        int nb_aleat = rand() % 2;

        switch(nb_aleat)
        {
            case 0:
                nom_aleat = "trous";
                break;
            case 1:
                nom_aleat = "defaut";
                break;
            default:
                nom_aleat = "defaut";
                break;
        }
    }
    else
    {
        //Sinon, on discrimine en fonction de la difficulte...
        //La configuration de cette procédure est à faire à la main à chaque nouveau ModeleSalle
        //dans les fichiers. Oui c'est embêtant, mais moins que les autres alternatives je suppose.
        if (diff < 40)
        {
            int nb_aleat40 = rand() % 1;

            switch(nb_aleat40)
            {
                case 1:
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else if (diff < 90)
        {
            int nb_aleat90 = rand() % 1;
            switch(nb_aleat90)
            {
                case 1:
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else if (diff >= 90)
        {
            int nb_aleat91 = rand() % 1;
            switch(nb_aleat91)
            {
                case 0:
                    nom_aleat = "trous";
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else //si la difficulte spécifiée est incorrecte, on prend le modele par defaut.
        {
            nom_aleat = "defaut";
        }
    }

    salle_depuis_modele(nom_aleat, p_h, p_b, p_g, p_d, conf);
}
