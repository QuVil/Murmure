#ifndef MENUSFML_H_INCLUDED
#define MENUSFML_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Coord2D.h"
#include <string>

class MenuSFML
{
private:
    sf::Sprite ecran_menu;
    sf::Sprite curseur_selection;

    std::string nom_ecran; /**< nom de l'ecran actuel ("menu principal", "options", etc.)*/

    Coord2D position_souris; /**< la position x,y du curseur (de la souris)*/

    std::string selection_curseur; /**< l'option actuellement sélectionnée ("options", "jouer", etc.)*/

    void actualiser_selection_curseur();

public:
    MenuSFML();

    MenuSFML(std::string nom_ecr);

    void actualiser();///TODO maggle

    void afficher_menu (std::string nom_ecr /* = "" */);

};

#endif // MENUSFML_H_INCLUDED
