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

    /// CASESALLE
    //echelle a laquelle on va charger les textures
    // (en fonction de la taille de l'ecran)
    int scale_salle_largeur, scale_salle_hauteur;

    // positions initiales des cases de la salle pour
    // centrer au mieux la salle sur l'ecran
    int posx0salle,posy0salle;

    /// SALLE

    CaseSFML casesfml[17][9];
    int scale_carte_largeur, scale_carte_hauteur;
    int posx0carte, posy0carte;


    Jeu jeu;

    void charger_salle();
    void dessiner_salle();
    void redessiner_salle();
    void mettre_a_jour_salle();

    void afficher_salle();
    void afficher_carte();

public:
    JeuSFML();

    void init();
    void SFML_boucle();
};


#endif // JEUSFML_H_INCLUDED
