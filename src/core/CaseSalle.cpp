/**
 * \file CaseSalle.cpp
 * \brief Code source pour le module CaseSalle
 * \author Quentin.V
 * \version 0.1
 * \date 11 mars 2017
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "CaseSalle.h"

/**
 * \brief Consctructeur
 * Le Constructeur basique de CaseSalle initialisant type sur 0.
 */
CaseSalle::CaseSalle()
{
    type = 0;
}

/**
 * \brief Consctructeur avec type
 * Constructeur prenant le type de CaseSalle désiré en parametre.
 * \param[in] t : le \a type qui sera affecte a la nouvelle instance.
 */
CaseSalle::CaseSalle(const int& t)
{
    type = t;
}

/**
 * \brief Destructeur
 * Le Destructeur basique de CaseSalle -ne faisant rien.
 */
CaseSalle::~CaseSalle()
{

}

/**
 * \brief Surcharge d'affectation de CaseSalle.
 * Surcharge de l'operateur = pour affecter des CaseSalle entre elles.
 * \param[in] c : La CaseSalle dont les membres -ici \a type- doivent etre copies.
 */
CaseSalle& CaseSalle::operator =(const CaseSalle & c)
{
    type=c.type;
    return *this;
}

/**
 * \brief Accesseur de \a type
 * Accesseur du membre \a type de la CaseSalle.
 * \return le \a type de la CaseSalle en question.
 */
int CaseSalle::get_CaseSalle_type()
{
    return type;
}

std::string CaseSalle::get_type_string()
{
    switch(type)
    {
        case 0 : return "normal";
                       break;
        case 1 : return "porte";
                       break;
        case 2 : return "trou";
                       break;
        case 3 : return "mur";
                       break;
        default : return "normal";
                          break;
    }
}

void CaseSalle::set_CaseSalle_type(int t)
{
    type = t;
}

/**
 * \brief Affichage de CaseSalle.
 * Procedure d'affichage de la CaseSalle.
 */
void CaseSalle::afficher()
{
    std::cout << type;
}
