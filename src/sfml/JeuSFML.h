#ifndef JEUSFML_H_INCLUDED
#define JESFMLU_H_INCLUDED

#include "Jeu.h"

#include <SFML/Graphics.hpp>


#include <sstream>

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

    sf::Sprite curseur;
    sf::View view;

    sf::Clock clock;

    sf::Time temps_frame;

    sf::Font police_test;
    sf::Text text_fps;
    sf::Text text_posx, text_posy;
    std::stringstream text_fps_stringstream;
    int fps_actuel;

    int val_max_deplacement;

    int salle_act_x, salle_act_y;

    /// CASESALLE
    int scale_salle;
    int posx0salle,posy0salle;
    CaseSFML casesfml[9][17];

    /// CARTEAFF
    int scale_carte_largeur, scale_carte_hauteur;
    int posx0carte, posy0carte;
    //CarteAffSFML carteaffsfml[11][11];


    PersoSFML persosfml;
    Jeu jeu;

    void recupere_mouvements();
    void recupere_collisions();

    void afficher(const int &mode);

    void init_curseur();
    void init_persoSFML();
    void init_caseSFML();
    void init_carteAffSFML();
    void init_texte();

    void dessiner_curseur();
    void dessiner_salle();
    void dessiner_carte();
    void dessiner_perso();
    void ecrire_texte();

public:
    JeuSFML();

    void init();
    void SFML_boucle();
};


#endif // JEUSFML_H_INCLUDED
