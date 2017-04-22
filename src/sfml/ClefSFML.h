#ifndef CLEFSFML_H_INCLUDED
#define CLEFSFML_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Clef.h"

/** \file ClefSFML.h
 *
 * \brief Module qui va gérer le sprite de la clef
 *
 */


class ClefSFML
{
private:
    sf::Sprite clefsfml; /**< Sprite contenant les informations nécessaires pour l'affichage de la clef */

    Clef* cle; /**< Un pointeur sur la clef du Jeu, pour ains avoir les informations nécessaires */
public:
    /** \brief Constructeur par défaut
     *
     *
     */
    ClefSFML();

    /** \brief Initialisation de la clef
     * Initialise la clef avec sa texture, sa taille (proportionnelle à la taille des autres cases) et ses informations se trouvant dans la clef pointée
     * \param p_cle Clef* : clef du jeu, comprenant toutes les informations insternes de la clef
     * \param p_texture const sf::Texture& : la texture de la clef à afficher à l'écran
     * \param taille_case const int& : la taille des cases sur le moniteur actuelle, pour ainsi l'afficher de façon proportionnelle à celui-ci
     * \param x0 const int& : la position horizontale à prendre comme origine
     * \param y0 const int& : la position verticale à prendre commme origine
     */
    void init(Clef* p_cle,const sf::Texture &p_texture, const int &taille_case,const int &x0, const int &y0);

    ///TODO TODO TODO TODO set_position salope

    /** \brief Accesseur du Sprite
     *
     * \return sf::Sprite : le sprite contenant toutes les informations nécessaires à l'affichage de la clef
     *
     */
    sf::Sprite get_clefsfml();

};

#endif // CLEFSFML_H_INCLUDED
