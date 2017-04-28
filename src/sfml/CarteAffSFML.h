#ifndef CARTEAFFSFML_H_INCLUDED
#define CARTEAFFSFML_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

#include "Zone.h"

/** \file CarteAffSFML.h
 *
 * \brief Module qui va charger les cases à afficher lors d'un affichage de la carte
 *
 */


class CarteAffSFML
{
private:
    sf::VertexArray cartesallesfml; /**< Tableau de Vertex qui comprend la position de ladite case */
public:
    /** \brief Constructeur par défaut
     *
     *
     */
    CarteAffSFML();

    /** \brief Initialisation de la case
     * Initialise la position de la case ainsi que la taille de la texture qu'elle va recevoir lors de l'affichage
     * \param posX const int& : position horizontale du point en haut à gauche de la case
     * \param posY const int& : position verticale du point en haut à gauche de la case
     * \param largeur const int& : largeur de la case
     * \param hauteur const int& : hauteur de la case
     * \param hauteur_tex const int& : largeur de la texture de la case
     * \param largeur_tex const int& : hauteur de la texture de la case
     */
    void init(const int &posX,const int &posY,const int &largeur,const int &hauteur, const int &hauteur_tex, const int &largeur_tex);

    /** \brief Accesseur de la case
     * Renvoie la case (sous forme de tableau de Vertex) avec tous les paramètres précedemment initialisés
     * \return sf::VertexArray : la case
     *
     */
    sf::VertexArray get_cartesallesfml();
};

#endif // CARTEAFFSFML_H_INCLUDED
