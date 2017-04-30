#ifndef CLEF_H_INCLUDED
#define CLEF_H_INCLUDED

/**
 * \file Clef.h
 * \brief Header du module Clef.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 20 avril 2017
 *
 */

#include "Coord2D.h"

/**
 * \class Clef
 * \brief class de la clef du boss. Elle apparaît dans les Salle de \a config
 * = 3 et peut être ramassée, et permet d'entrer dans la Salle du boss.
 */
class Clef
{
private:
    char type_clef; /**< le type de clef -- pour le moment, un seul type : 'b' comme boss*/
    Coord2D position; /**< la position x,y de la Clef*/
    bool par_terre; /**< la Clef est-elle par terre ou a-t-elle été ramassée ?*/

    int case_x_apparition; /**< la coordonnée x de la case où est apparue la clef */
    int case_y_apparition; /**< la coordonnée x de la case où est apparue la clef */

    float taille; /**< la taille relative de la clef (1 -> une case) */

public:
    /** \brief Constructeur de base
     * pas utilisé en pratique, initialise toutes les valeurs
     * nécessaires.
     */
    Clef();

    /** \brief Constructeur avec parametres
     * Donne la case d'apparition de la Clef en paramètre.
     * \param[in] case_x_app : coordonnée x de la case d'apparition
     * \param[in] case_y_app : coordonnée y de la case d'apparition
     */
    Clef(int case_app_x, int case_app_y);

    /** \brief Pour ramasser la Clef
     * passe simplement \a par_terre sur false pour faire disparaître
     * la clef correctement.
     */
    void ramasser();

    /** \brief Accesseur de \a taille.
     * \return la \a taille de la Clef.
     */
    float get_taille()const;

    /** \brief Accesseur de \a case_x_apparition.
     * \return la \a case_x_apparition de la Clef.
     */
    int get_case_x_apparition()const;

    /** \brief Accesseur de \a case_y_apparition.
     * \return la \a case_y_apparition de la Clef.
     */
    int get_case_y_apparition()const;

    /** \brief Accesseur de \a par_terre.
     * \return l'attribut \a par_terre de la Clef.
     */
    bool get_par_terre();
};

#endif // CLEF_H_INCLUDED
