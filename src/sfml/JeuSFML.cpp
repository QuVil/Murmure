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

    if(desktop.width/27 <desktop.height/15){scale = desktop.width/27;}
    else{scale = desktop.height/15;}
    //std::cout << desktop.width << " " << desktop.height << " " << desktop.bitsPerPixel << std::endl;
    posx0salle = (desktop.width -27*scale)/2;
    posy0salle = (desktop.height - 15*scale)/2;
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
        window.clear(sf::Color::White);

        afficher_salle();

        window.display();
    }
}

void JeuSFML::afficher_salle()
{
    CaseSalle c;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<27;j++)
        {
            c=jeu.get_salle().get_case(i,j);
            CaseSFML C(posx0salle +j*scale,
                                   posy0salle +i*scale,
                                   scale,
                                   scale,
                                   c.get_type_string());
            window.draw(C.get_casesfml(),C.get_states());
        }
    }
}

void JeuSFML::afficher_carte()
{

}
