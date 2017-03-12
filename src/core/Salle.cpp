/**
 * \file Salle.cpp
 * \brief Code source pour le module Salle.
 * \author Quentin.V
 * \version 0.1
 * \date 11 mars 2017
 *
 */

#include <iostream>

#include "Salle.h"
#include "Fichier.h"

/**
 * \brief Consctructeur
 * Le Constructeur basique de Salle donnant la \a config 1 à l'instance
 * créée, et créant son fichier modèle.
 */
Salle::Salle()
{
    config = 1;

    Fichier fichier;
    fichier.charger(*this);
}

/**
 * \brief Consctructeur avec \a config
 * Le Constructeur avec paramètre, donnant à l'instance la \a config donnée.
 * \param[in] conf : la \a config donnée à la nouvelle instance.
 * \todo : potentiellement ajouter le paramètre fichier pour copie (GARY ?)
 */
Salle::Salle(int conf)
{
    config = conf;

    Fichier fichier;
    fichier.charger(*this);
}

/**
 * \brief Accesseur de case dans la grille.
 * \param[in] i : coordonnée de la ligne de la case désirée.
 * \param[in] j : coordonnée de la colonne de la case désirée.
 * \return renvoie la CaseSalle i,j de la grille de l'instance.
 * \warning l'accesseur renvoyant une copie, attention à ne pas vouloir utiliser un membre.
 */
CaseSalle Salle::get_case(int i,int j)
{
    return grille[i][j];
}

/**
 * \brief Mutateur de case dans la grille.
 * \param[in] i : coordonnée de la ligne de la case à changer.
 * \param[in] j : coordonnée de la colonne de la case à changer.
 * \param[in] c : la CaseSalle pour remplacer la case i,j.
 */
void Salle::set_case(int i, int j, CaseSalle c)
{
    grille[i][j] = c;
}

/**
 * \brief Accesseur de la \a config.
 * \return la \a config (un int) de la Salle.
 */
int Salle::get_config()
{
    return config;
}

/**
 * \brief Procédure de remplissage de Salle.
 * Techniquement, remplir() est un mutateur de \a config
 * avec paramètre fixé.
 */
void Salle::remplir()
{
    config = 1;
}

/**
 * \brief Procédure de vidage de Salle.
 * Techniquement, vider() est un mutateur de \a config
 * avec paramètre fixé.
 */
void Salle::vider()
{
    config = -1;
}

/**
 * \brief Surcharge d'affectation de Salle.
 * Surcharge de l'operateur = pour affecter des Salle entre elles.
 * \param[in] salle2 : La Salle dont les membres -ici les CaseSalle de la grille et la \a config- doivent être copiés.
 */
Salle& Salle::operator = (Salle salle2)
    {
        for (int i=0; i<15; ++i)
        {
            for (int j=0; j<27; ++j)
                grille[i][j] = salle2.get_case(i, j);
        }
        config = salle2.get_config();
        return *this;
    }

/**
 * \brief Affichage de Salle.
 * Procedure d'affichage de la Salle.
 */
void Salle::afficher()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<27;j++)
        {
            grille[i][j].afficher();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
