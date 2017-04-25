#ifndef ENNEMISFML_H_INCLUDED
#define ENNEMISFML_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Ennemi.h"

/** \file EnnemiSFML.h
 *
 * \brief Module qui g�re les sprites des ennemis affich�s
 */


class EnnemiSFML
{
private:
    sf::Sprite ennemisfml; /**< Sprite contenant les informations visuelles de l'ennemi � afficher */

    Ennemi * ennemi; /**< Pointeur sur l'ennemi du jeu contenant les informations internes de celui-ci */
public:
    /** \brief Constructeur par d�faut
     *
     *
     */
    EnnemiSFML();

    /** \brief Initialisation
     * Initialise les informations n�cessaires pour l'affichage de l'ennemi
     * \param p_ennemi Ennemi* : pointeur sur l'ennemi venant du Jeu � afficher
     * \param p_texture const sf::Texture& : texture de l'ennemi � afficher
     * \param taille_case const int& : taille de la case (proportionnelle � la taille de l'ecran)
     */
    void init(Ennemi * p_ennemi,const sf::Texture &p_texture, const int &taille_case);

    /** \brief
     *
     * \param taille_case const int&
     * \param x0 const int&
     * \param y0 const int&
     * \return void
     *
     */
    void mettre_a_jour_position(const int &taille_case, const int &x0, const int &y0);

    sf::Sprite get_ennemisfml();

    sf::Sprite * get_ennemisfml_ptr();

    Ennemi * get_ennemi();

    VecteurM get_taille()const;

    Coord2D get_position_hg()const;
};

#endif // ENNEMISFML_H_INCLUDED
