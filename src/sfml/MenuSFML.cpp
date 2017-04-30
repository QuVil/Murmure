#include "MenuSFML.h"

/**
 * \file MenuSFML.h
 * \brief code source de MenuSFML
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 25 avril 2017
 *
 */

MenuSFML::MenuSFML(std::string nom_ecr)
{
    nom_ecran = nom_ecr;
}

MenuSFML::MenuSFML()
{
    nom_ecran = "principal";
    selection_curseur = "jouer";
}

std::string MenuSFML::get_selection_curseur()
{
    return selection_curseur;
}

void MenuSFML::init_menu(const sf::Texture& texture_menu, const int &scale_salle)
{
    ecran_menu.setTexture(texture_menu);
    //ecran_menu.setOrigin(0, 0);
    ecran_menu.setPosition(0, 0);

    sf::Vector2f targetSize(1300.0f, 760.0f);
    ecran_menu.setScale(
    targetSize.x / ecran_menu.getLocalBounds().width,
    targetSize.y / ecran_menu.getLocalBounds().height);
}

void MenuSFML::init_curseur_menu(const sf::Texture& texture_curseur_menu, const int &scale_salle)
{
    curseur_selection.setTexture(texture_curseur_menu);
    curseur_selection.setOrigin(texture_curseur_menu.getSize().x/2, texture_curseur_menu.getSize().y/2);
    curseur_selection.setPosition(0, 0);

    curseur_selection.setScale(100/curseur_selection.getLocalBounds().width, 100/curseur_selection.getLocalBounds().height);
}

void MenuSFML::actualiser_selection_curseur(const char direction, const int scale_salle)
{

    //On check la position du curseur et on actualise la selection
    if (nom_ecran == "principal")
    {
        switch (direction)
        {
            case 'h':
                if (selection_curseur == "options")
                {selection_curseur = "jouer";}
                else if (selection_curseur == "stats" || selection_curseur == "challenge")
                {selection_curseur = "options";}
                break;
            case 'g':
                if (selection_curseur == "challenge")
                {selection_curseur = "stats";}
                break;
            case 'b':
                if (selection_curseur == "jouer")
                {selection_curseur = "options";}
                else if (selection_curseur == "options")
                {selection_curseur = "stats";}
                break;
            case 'd':
                if (selection_curseur == "stats")
                {selection_curseur = "challenge";}
                break;
        }
    }
    mettre_a_jour_position_curseur(scale_salle);
}

void MenuSFML::afficher_menu(std::string nom_ecr = "")
{
    if (nom_ecr == "")
    {
        nom_ecr = nom_ecran;
    }

    if (nom_ecr == "principal")
    {
        //affichage du menu principal
    }
    else if (nom_ecr == "options")
    {
        //affichage du menu d'options
    }
    else if (nom_ecr == "stats")
    {
        //affichage de l'écran des stats
    }
}

sf::Sprite MenuSFML::get_menusfml()const
{
    return ecran_menu;
}

sf::Sprite MenuSFML::get_curseur_menu()const
{
    return curseur_selection;
}

void MenuSFML::mettre_a_jour_position_curseur(const int &scale_salle)
{
    int x0, y0;
    if (nom_ecran == "principal")
    {
        if (selection_curseur == "jouer")
        {
            x0 = 200 *(scale_salle/64);
            y0 = 200 *(scale_salle/64);
        }
        else if (selection_curseur == "options")
        {
            x0 = 200 *(scale_salle/64);
            y0 = 500 *(scale_salle/64);
        }
        else if (selection_curseur == "stats")
        {
            x0 = 200 *(scale_salle/64);
            y0 = 600 *(scale_salle/64);
        }
        else if (selection_curseur == "challenge")
        {
            x0 = 1100 *(scale_salle/64);
            y0 = 500 *(scale_salle/64);
        }
    }
    curseur_selection.setPosition(x0, y0);
}
