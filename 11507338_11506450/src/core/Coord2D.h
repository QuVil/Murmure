#ifndef COORD2D_H_INCLUDED
#define COORD2D_H_INCLUDED

#include "VecteurM.h"

/**
 * \file Coord2D.h
 * \brief Header du module Coord2D.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 12 mars 2017
 *
 */

 /**
 * \class Coord2D
 * \brief Une simple class g�rant les coordonn�es x et y.
 * Les points sont dans un plan simple orthonorm� dirig� par l'axe x des
 * abscisses et y des ordonn�es.
 */
class Coord2D
{
private:
    float x; /**< Coordonn�e x du point */
    float y; /**< Coordonn�e y du point */

public:
    /** \brief Constructeur par d�faut
     * Initialise x � 0 et y � 0
     */
    Coord2D();

    /** \brief Constructeur � parametres
     * Initialise l'objet avec les valeurs donn�es en parametre
     * \param[in] a : valeur pour x
     * \param[in] b : valeur pour y
     */
    Coord2D(float a, float b);


    /** \brief Operateur ==
     * Surcharge de == pour pouvoir faire des tests entre des points
     * \param[in] c2 : la sencode entit� \a Coord2D � comparer avec celle actuelle
     * \return true si elles sont identiques, false sinon
     */
    bool operator ==(const Coord2D &c2);

    /** \brief Operateur !=
     * Surcharge de == pour pouvoir faire des tests entre des points
     * \param[in] c2 : la sencode entit� \a Coord2D � comparer avec celle actuelle
     * \return false si elles sont identiques, true sinon
     */
    bool operator !=(const Coord2D& c2);

    /** \brief Affectation des variables
     * Met � jour les variables x et y
     * \param[in] a : valeur de x
     * \param[in] b : valeur de y
     */
    void coord_set(float a, float b);

    /** \brief Deplace le point
     * Procedure qui va deplacer un point en fonction du mouvement dirig� et d'un coefficient
     * \param[in] vect : la direction et l'intensit� du mouvement
     * \param[in] coeff : coefficient � appliquer au mouvement pour que celui-ci ait plus ou moins d'intensit�
     */
    void deplacer(const VecteurM &vect, const float &coeff);

    /** \brief Mutateur de x
     *
     * \param[in] a : valeur de x
     */
    void set_x(float a);

    /** \brief Mutateur de y
     *
     * \param[in] a : valeur de y
     */
    void set_y(float b);

    /** \brief Accesseur de x
     *
     * \return valeur de x
     */
    float get_x()const;

    /** \brief Accesseur de y
     *
     * \return valeur de y
     */
    float get_y()const;
};

#endif // COORD2D_H_INCLUDED
