#ifndef MENUSFML_H_INCLUDED
#define MENUSFML_H_INCLUDED

/**
 * \file MenuSFML.h
 * \brief Header du module de menu.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 15 avril 2017
 *
 */

#include <SFML/Graphics.hpp>

#include "Coord2D.h"
#include <string>

/**
 * \class MenuSFML
 * \brief gère les menus du JeuSFML, principal, d'options, etc.
 *
 */
class MenuSFML
{
private:
    sf::Sprite ecran_menu; /**< sprite du menu actuel, par-dessus lequel on met le curseur*/
    sf::Sprite curseur_selection; /**< sprite du curseur de selection du menu*/

    std::string nom_ecran; /**< nom de l'ecran actuel ("menu principal", "options", etc.)*/

    std::string selection_curseur; /**< l'option actuellement sélectionnée ("options", "jouer", etc.)*/

public:
    /**
     * \brief Consctructeur
     * De base, crée le menu principal et place le curseur
     * sur "jouer".
     */
    MenuSFML();

    /**
     * \brief Consctructeur avec écran en paramètre
     * \param[in] nom_ecr : la valeur de \a nom_ecran
     */
    MenuSFML(std::string nom_ecr);

    /**
     * \brief Accesseur de \a selection_curseur
     * \return \a selection_curseur
     */
    std::string get_selection_curseur();

    /**
     * \brief Déplacement du curseur dans le menu --physique
     * Met aussi à jour la position graphique du curseur par un appel
     * à mettre_a_jour_position_curseur.
     * \param[in] direction : h, b, g ou d pour déplacer le curseur dans les directions cardinales.
     * \param[in] scale_salle : permet de déterminer la taille des sprites relative à l'écran -est juste passé à la suivante
     */
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
