#include <iostream>

#include <SFML/Graphics.hpp>

#include "CaseSalle.h"

#include "CaseSFML.h"
#include "JeuSFML.h"

JeuSFML::JeuSFML()
{
    // cherche les parametres de l'utilisateur (resolution)
    desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Murmure",sf::Style::Fullscreen);
    /*
    if(desktop.width/jeu.get_salle().get_cases_largeur() <desktop.height/jeu.get_salle().get_cases_hauteur()){scale = desktop.width/jeu.get_salle().get_cases_largeur();}
    else{scale = desktop.height/jeu.get_salle().get_cases_hauteur();}*/
    scale_salle_largeur = desktop.width/jeu.get_salle().get_cases_largeur();
    scale_salle_hauteur = desktop.height/jeu.get_salle().get_cases_hauteur();
    //std::cout << desktop.width << " " << desktop.height << " " << desktop.bitsPerPixel << std::endl;

    posx0salle = (desktop.width -jeu.get_salle().get_cases_largeur()*scale_salle_largeur)/2;
    posy0salle = (desktop.height - jeu.get_salle().get_cases_hauteur()*scale_salle_hauteur)/2;

}

void JeuSFML::SFML_boucle()
{
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
            }
        }
        window.clear(sf::Color::Black);

        afficher_salle();

        window.display();
    }
}

void JeuSFML::afficher_salle()
{
    CaseSalle c;
    for(int i=0;i<jeu.get_salle().get_cases_hauteur();i++)
    {
        for(int j=0;j<jeu.get_salle().get_cases_largeur();j++)
        {
            c=jeu.get_salle().get_case(i,j);
            /*
            CaseSFML C(posx0salle +j*scale,
                                   posy0salle +i*scale,
                                   scale,
                                   scale,
                                   c.get_type_string());*/
            CaseSFML C(posx0salle + j*scale_salle_largeur,
                                   posy0salle + i*scale_salle_hauteur,
                                   scale_salle_largeur,
                                   scale_salle_hauteur,
                                   c.get_type_string());
            window.draw(C.get_casesfml(),C.get_states());
        }
    }
}

void JeuSFML::afficher_carte()
{

}
