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

    // positions initiales des cases de la salle pour
    // centrer au mieux la salle sur l'ecran
    int posx0salle,posy0salle;

    Jeu jeu;

    void afficher_salle();

    void afficher_carte();

public:
    JeuSFML();

    void SFML_boucle();
};


#endif // JEUSFML_H_INCLUDED
