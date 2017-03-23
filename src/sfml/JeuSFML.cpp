#include <iostream>

#include <SFML/Graphics.hpp>

#include "CaseSalle.h"

#include "CaseSFML.h"
#include "CarteAffSFML.h"
#include "JeuSFML.h"

JeuSFML::JeuSFML()
{
    //jeu.get_zone().afficher_zone();
    // cherche les parametres de l'utilisateur (resolution)
    desktop = sf::VideoMode::getDesktopMode();
    //window.create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Murmure",sf::Style::Fullscreen);
    window.create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Murmure",sf::Style::Close);

    temps_frame = sf::seconds((float) 1/10); // en seconde
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(10);


    if(desktop.width/17 <desktop.height/9){scale_salle = desktop.width/17;}
    else{scale_salle = desktop.height/9;}

    //scale_salle_largeur = desktop.width/17;
    //scale_salle_hauteur = desktop.height/9;
    //std::cout << desktop.width << " " << desktop.height << " " << desktop.bitsPerPixel << std::endl;

    posx0salle = (desktop.width -17*scale_salle)/2;
    posy0salle = 0;
    //posy0salle = (desktop.height - 9*scale_salle);

    scale_carte_largeur = desktop.width/11;
    scale_carte_hauteur = desktop.height/11;

    posx0carte = (desktop.width - 11*scale_carte_largeur)/2;
    posy0carte = (desktop.height - 11*scale_carte_hauteur)/2;
}

void JeuSFML::init()
{
    textures.charger_textures_caseSFML();
    textures.charger_textures_carteAffSFML();
    textures.charger_texture_perso();
    init_caseSFML();
    init_persoSFML();
}

void JeuSFML::init_caseSFML()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<17;j++)
        {
            casesfml[i][j].init(posx0salle + j*scale_salle,
                                          posy0salle + i*scale_salle,
                                          scale_salle,
                                          scale_salle);
        }
    }
}

void JeuSFML::init_carteAffSFML()
{

}

void JeuSFML::init_persoSFML()
{
    persosfml.set_texture(textures.retourne_texture_perso());
}


void JeuSFML::SFML_boucle()
{
    int mode = 1;
    clock.restart();
    //init();
    //charger_salle();
    // on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
    while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(event.type == sf::Event::KeyPressed)
            {
                // si appuie sur "echape" -> ferme la fenetre
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }

                if(event.key.code == sf::Keyboard::M)
                {
                    mode = 1;
                }

                if(event.key.code == sf::Keyboard::P)
                {
                    mode = 2;
                }
            }


        }


        //window.clear(sf::Color::Black);
        afficher(mode);
        window.display();
    }
}

void JeuSFML::afficher(const int& mode)
{
    switch(mode)
    {
    case 1:
        if(clock.getElapsedTime() >= temps_frame)
        {
            //std::cout << "kek" << std::endl;
            recupere_mouvements();
            dessiner_salle();
            dessiner_perso();
            clock.restart();
        }
        break;
    case 2:
        dessiner_carte();
        break;
    default:
        dessiner_salle();
        break;
    }
}

void JeuSFML::dessiner_salle()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<17;j++)
        {
            window.draw(casesfml[i][j].get_casesfml(),
                        textures.retourne_rendu_texture_caseSFML(jeu.get_salle().get_case(i, j).get_type_char(),
                                                                 i,
                                                                 j,
                                                                 jeu.get_zone().get_salle_actuelle_x(),
                                                                 jeu.get_zone().get_salle_actuelle_y()));
        }
    }
}


void JeuSFML::dessiner_carte()
{
    CarteAffSFML c;
    bool salle_act = false;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            if((jeu.get_zone().get_salle_actuelle_x() == i)&&(jeu.get_zone().get_salle_actuelle_y() == j)) {salle_act = true;}
            else {salle_act = false;}
            c.init(posx0carte +i*scale_carte_largeur,
                      posy0carte +j*scale_carte_hauteur,
                      scale_carte_largeur,
                      scale_carte_hauteur);
            window.draw(c.get_cartesallesfml(),
                                     textures.retourne_rendu_texture_carteAffSFML(jeu.get_zone().get_salle(i, j).get_config(), salle_act));
        }
    }
}

void JeuSFML::dessiner_perso()
{
    persosfml.mettre_a_jour(jeu.get_perso());
    window.draw(persosfml.get_persosfml());
}


void JeuSFML::recupere_mouvements()
{
    // Clavier
    // Attention l'axe Y pointe vers le bas

    float x = 0;
    float y = 0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {x = x - 100;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {x = x + 100;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {y = y - 100;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {y = y + 100;}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {jeu.zone_changer_salle('h');}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {jeu.zone_changer_salle('b');}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {jeu.zone_changer_salle('g');}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {jeu.zone_changer_salle('d');}
    jeu.deplacer_perso(x, y);
    //std::cout << "axe x : " << x << " axe y : " << y << std::endl;
    //std::cout << jeu.get_zone().get_salle_actuelle_x() << " " << jeu.get_zone().get_salle_actuelle_y() << std::endl;
}

