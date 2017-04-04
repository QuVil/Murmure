#ifndef JEUSFML_H_INCLUDED
#define JESFMLU_H_INCLUDED

#include "Jeu.h"

#include <SFML/Graphics.hpp>


#include <sstream>
#include <list>

#include "CaseSFML.h"
#include "PersoSFML.h"
#include "TextureSFML.h"
#include "ProjectileSFML.h"
#include "HitboxSFML.h"

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
    sf::Clock timer_arme1_perso;

    sf::Time temps_frame;

    float vitesse_base_deplacement;
    float vitesse_base;

    sf::Font police_test;
    sf::Text text_fps;
    sf::Text text_posx, text_posy;
    sf::Text text_mouseposx,text_mouseposy;
    sf::Text text_projectiles;
    std::stringstream text_fps_stringstream;
    int fps_actuel;

    int val_max_deplacement;

    int salle_act_x, salle_act_y;

    HitboxSFML hitboxes;

    /// CASESALLE
    int scale_salle;
    int posx0salle,posy0salle;
    CaseSFML casesfml[9*17];

    /// CARTEAFF
    int scale_carte_largeur, scale_carte_hauteur;
    int posx0carte, posy0carte;

    /// PROJECTILES
    std::list <ProjectileSFML *> projectilesfml;

    /// ENNEMIS
    std::list <EnnemiSFML *> ennemisfml;

    PersoSFML persosfml;

    Jeu jeu;

    void recupere_mouvements();
    void recupere_collisions();
    void avancer_jeu();

    void afficher(const int &mode);

    void init_curseur();
    void init_persoSFML();
    void init_caseSFML();
    void init_carteAffSFML();
    void init_projectileSFML();
    void init_texte();

    void dessiner_curseur();
    void dessiner_salle();
    void dessiner_carte();
    void dessiner_perso();
    void dessiner_projectiles();
    void ecrire_texte();

    void actualiser_salle();
    void actualiser_projectiles();
    void actualiser_perso();
public:
    JeuSFML();

    ~JeuSFML();

    void init();
    void SFML_boucle();
};


#endif // JEUSFML_H_INCLUDED
