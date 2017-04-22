#ifndef CLEFSFML_H_INCLUDED
#define CLEFSFML_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Clef.h"

/** \file ClefSFML.h
 *
 * \brief Module qui va g�rer le sprite de la clef
 *
 */


class ClefSFML
{
private:
    sf::Sprite clefsfml; /**< Sprite contenant les informations n�cessaires pour l'affichage de la clef */

    Clef* cle; /**< Un pointeur sur la clef du Jeu, pour ains avoir les informations n�cessaires */
public:
    /** \brief Constructeur par d�faut
     *
     *
     */
    ClefSFML();

    /** \brief Initialisation de la clef
     * Initialise la clef avec sa texture, sa taille (proportionnelle � la taille des autres cases) et ses informations se trouvant dans la clef point�e
     * \param p_cle Clef* : clef du jeu, comprenant toutes les informations insternes de la clef
     * \param p_texture const sf::Texture& : la texture de la clef � afficher � l'�cran
     * \param taille_case const int& : la taille des cases sur le moniteur actuelle, pour ainsi l'afficher de fa�on proportionnelle � celui-ci
     * \param x0 const int& : la position horizontale � prendre comme origine
     * \param y0 const int& : la position verticale � prendre commme origine
     */
    void init(Clef* p_cle,const sf::Texture &p_texture, const int &taille_case,const int &x0, const int &y0);

    ///TODO TODO TODO TODO set_position salope

    /** \brief Accesseur du Sprite
     *
     * \return sf::Sprite : le sprite contenant toutes les informations n�cessaires � l'affichage de la clef
     *
     */
    sf::Sprite get_clefsfml();

};

#endif // CLEFSFML_H_INCLUDED
