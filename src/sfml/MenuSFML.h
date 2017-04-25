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

public:
    MenuSFML();

    MenuSFML(std::string nom_ecr);

    std::string get_selection_curseur();

    void actualiser_selection_curseur(const char direction, const int scale_salle);

    void init_menu(const sf::Texture& texture_menu, const int &scale_salle);

    void init_curseur_menu(const sf::Texture& texture_curseur_menu, const int &scale_salle);

    void afficher_menu (std::string nom_ecr /* = "" */);

    void afficher_curseur();

    sf::Sprite get_menusfml()const;

    sf::Sprite get_curseur_menu()const;

    void mettre_a_jour_position_curseur(const int &scale_salle);
};

#endif // MENUSFML_H_INCLUDED
