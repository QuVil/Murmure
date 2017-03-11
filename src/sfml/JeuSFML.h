#ifndef JEUSFML_H_INCLUDED
#define JESFMLU_H_INCLUDED

#include "Jeu.h"

#include <SFML/Graphics.hpp>

#include "CaseSFML.h"

class JeuSFML
{
private:
    // fenetre qu'on utilisera
    sf::RenderWindow window;
    // parametres de l'ecran
    sf::VideoMode desktop;
    //echelle a laquelle on va charger les textures
    // (en fonction de la taille de l'ecran)
    int scale;

    int posx0,posy0;

    Jeu jeu;

    void afficher_salle();

public:
    JeuSFML();

};


#endif // JEUSFML_H_INCLUDED
