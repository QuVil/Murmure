#ifndef JEUSFML_H_INCLUDED
#define JESFMLU_H_INCLUDED

#include "Jeu.h"

#include <SFML/Graphics.hpp>

#include "CaseSFML.h"
#include "PersoSFML.h"
#include "TextureSFML.h"

class JeuSFML
{
private:
    //integralite des textures du jeu
    TextureSFML textures;
    // fenetre qu'on utilisera
    sf::RenderWindow window;
    sf::RenderTexture buffer, buffer_salle, buffer_carte;
    sf::Sprite sprite_buffer, sprite_salle,sprite_carte;
    // parametres de l'ecran
    sf::VideoMode desktop;

    sf::Clock clock;

    sf::Time temps_frame;

    int salle_act_x, salle_act_y;

    /// CASESALLE
    //echelle a laquelle on va charger les textures (en fonction de la taille de l'ecran)
    //int scale_salle_largeur, scale_salle_hauteur;
    int scale_salle;
    // positions initiales des cases de la salle pour centrer au mieux la salle sur l'ecran
    int posx0salle,posy0salle;
    CaseSFML casesfml[9][17];

    /// CARTEAFF
    int scale_carte_largeur, scale_carte_hauteur;
    int posx0carte, posy0carte;
    //CarteAffSFML carteaffsfml[11][11];

    int taille_cases;
    PersoSFML persosfml;
    Jeu jeu;

    void recupere_mouvements();
    void recupere_collisions();

    void afficher(const int &mode);

    void init_persoSFML();
    void init_caseSFML();
    void init_carteAffSFML();

    void dessiner_salle();
    void dessiner_carte();
    void dessiner_perso();

public:
    JeuSFML();

    void init();
    void SFML_boucle();
};


#endif // JEUSFML_H_INCLUDED
