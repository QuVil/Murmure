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
    window.create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Murmure",sf::Style::Fullscreen);
    /*
    if(desktop.width/jeu.get_salle().get_cases_largeur() <desktop.height/jeu.get_salle().get_cases_hauteur()){scale = desktop.width/jeu.get_salle().get_cases_largeur();}
    else{scale = desktop.height/jeu.get_salle().get_cases_hauteur();}*/

    scale_salle_largeur = desktop.width/17;
    scale_salle_hauteur = desktop.height/9;
    //std::cout << desktop.width << " " << desktop.height << " " << desktop.bitsPerPixel << std::endl;

    posx0salle = (desktop.width -17*scale_salle_largeur)/2;
    posy0salle = (desktop.height - 9*scale_salle_hauteur)/2;

    scale_carte_largeur = desktop.width/11;
    scale_carte_hauteur = desktop.height/11;

    posx0carte = (desktop.width - 11*scale_carte_largeur)/2;
    posy0carte = (desktop.height - 11*scale_carte_hauteur)/2;
}

void JeuSFML::init()
{
    init_caseSFML();
    textures.charger_textures_caseSFML();
    textures.charger_textures_carteAffSFML();
}

void JeuSFML::init_caseSFML()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<17;j++)
        {
            casesfml[i][j].init(posx0salle + j*scale_salle_largeur,
                                          posy0salle + i*scale_salle_hauteur,
                                          scale_salle_largeur,
                                          scale_salle_hauteur);
        }
    }
}

void JeuSFML::init_carteAffSFML()
{

}

void JeuSFML::SFML_boucle()
{
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
                    //afficher_carte();
                }

                if(event.key.code == sf::Keyboard::S)
                {
                    dessiner_salle();
                }
            }


        }


        window.clear(sf::Color::Black);
        dessiner_carte();
        window.display();
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
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            /*
            CaseSFML C(posx0salle +j*scale,
                                   posy0salle +i*scale,
                                   scale,
                                   scale,
                                   c.get_type_string());*/
                                   /*
            CarteAffSFML C(posx0carte + j*scale_carte_largeur,
                                        posy0carte + i*scale_carte_hauteur,
                                        scale_carte_largeur,
                                        scale_carte_hauteur,
                                        jeu.get_zone().get_salle(i, j).get_config_string());*/
            //window.draw(cartget_cartesallesfml(),C.get_states());
            c.init(posx0carte +i*scale_carte_largeur,
                      posy0carte +j*scale_carte_hauteur,
                      scale_carte_largeur,
                      scale_carte_hauteur);
            window.draw(c.get_cartesallesfml(),
                                     textures.retourne_rendu_texture_carteAffSFML(jeu.get_zone().get_salle(i, j).get_config()));
        }
    }
}
