#ifndef SALLE_H_INCLUDED
#define SALLE_H_INCLUDED

/**
 * \file Salle.h
 * \brief Header du module Salle.
 * \author Quentin.V
 * \version 0.1
 * \date 11 mars 2017
 *
 */

#include "CaseSalle.h"

/**
 * \class Salle
 * \brief class des salles de jeu où évolue le joueur.
 * Salle dépend de CaseSalle et se compose d'une grille de
 * CaseSalle, dont les bords sont des murs.
 */
class Salle
{
private:
    //cree un tableau de CaseSalle
    CaseSalle grille[15][21]; /**< \a grille contient les CaseSalle composant la Salle. */

    //config correspond a la disposition de la salle, numerote par un nombre
    int config;

public:
    Salle();

    Salle(int conf);

    CaseSalle get_case(int i,int j);

    void set_case(int i, int j, CaseSalle c);

    int get_config();

    void set_config(int c);

    void remplir();

    void vider();

    Salle& operator = (Salle salle2);

    void afficher();
};

#endif // SALLE_H_INCLUDED
