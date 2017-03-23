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
    //window.create(sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel), "Murmure",sf::Style::Close);

    temps_frame = sf::seconds((float) 1/70); // en seconde
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    taille_cases = desktop.width / 17;

    //window.setMouseCursorVisible(false);

    salle_act_x = -1;
    salle_act_y = -1;

    buffer_salle.create(desktop.width, desktop.height);
    buffer_carte.create(desktop.width, desktop.height);

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
    jeu.definir_position_perso(jeu.get_perso().get_pos_x()*taille_cases, jeu.get_perso().get_pos_y()*taille_cases);
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
                if((event.key.code == sf::Keyboard::Escape))
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

        //
        window.clear();
        afficher(mode);
        //buffer.display();

        //sf::Sprite sprite(buffer.getTexture());
        //static_sprite_buffer.setTexture(buffer.getTexture());
        //window.draw(sprite);
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
            recupere_collisions();
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
    if((salle_act_x != jeu.get_zone().get_salle_actuelle_x())||(salle_act_y != jeu.get_zone().get_salle_actuelle_y()))
    {
        buffer_salle.clear();
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<17;j++)
            {
                buffer_salle.draw(casesfml[i][j].get_casesfml(),
                            textures.retourne_rendu_texture_caseSFML(jeu.get_salle().get_case(i, j).get_type_char(),
                                                                     i,
                                                                     j,
                                                                     jeu.get_zone().get_salle_actuelle_x(),
                                                                     jeu.get_zone().get_salle_actuelle_y()));
            }
        }
        //std::cout << "kek" << std::endl;
        salle_act_x = jeu.get_zone().get_salle_actuelle_x();
        salle_act_y = jeu.get_zone().get_salle_actuelle_y();
        buffer_salle.display();
        sprite_salle.setTexture(buffer_salle.getTexture());
    }
    //sf::Sprite sprite(buffer.getTexture());
    window.draw(sprite_salle);
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
            buffer_carte.draw(c.get_cartesallesfml(),
                                     textures.retourne_rendu_texture_carteAffSFML(jeu.get_zone().get_salle(i, j).get_config(), salle_act));
        }
    }
    buffer_carte.display();
    sprite_carte.setTexture(buffer_carte.getTexture());
    window.draw(sprite_carte);
}

void JeuSFML::dessiner_perso()
{
    persosfml.mettre_a_jour(jeu.get_perso());
    //persosfml.get_persosfml().setPosition(jeu.get_perso().get_pos_x(), jeu.get_perso().get_pos_y());
    window.draw(persosfml.get_persosfml());
}

void JeuSFML::recupere_collisions()
{
    sf::FloatRect hitbox_perso = persosfml.get_persosfml().getGlobalBounds();
    if(jeu.get_salle().get_case(0,8).get_type_char() == 'p')
    {
        //std::cout << "kek" << std::endl;
        sf::FloatRect hitbox_porte_haut = casesfml[0][8].get_casesfml().getBounds();
        if(hitbox_perso.intersects(hitbox_porte_haut))
        {
            jeu.zone_changer_salle('g');
            jeu.definir_position_perso(taille_cases * (8+1.0/2.0),taille_cases * (7 +1.0/2.0));
        }
    }
    if(jeu.get_salle().get_case(4,0).get_type_char()  == 'p')
    {
        sf::FloatRect hitbox_porte_gauche = casesfml[4][0].get_casesfml().getBounds();
        if(hitbox_perso.intersects(hitbox_porte_gauche))
        {
            jeu.zone_changer_salle('h');
            jeu.definir_position_perso(taille_cases * (15 + 1.0/2.0), taille_cases * (4 +1.0/2.0));
        }
    }
    if(jeu.get_salle().get_case(4,16).get_type_char()  == 'p')
    {
        sf::FloatRect hitbox_porte_droite = casesfml[4][16].get_casesfml().getBounds();
        if(hitbox_perso.intersects(hitbox_porte_droite))
        {
            jeu.zone_changer_salle('b');
            jeu.definir_position_perso(taille_cases * (1 +1.0/2.0),taille_cases * (4+ 1.0/2.0));
        }
    }
    if(jeu.get_salle().get_case(8,8).get_type_char()  == 'p')
    {
        sf::FloatRect hitbox_porte_bas = casesfml[8][8].get_casesfml().getBounds();
        if(hitbox_perso.intersects(hitbox_porte_bas))
        {
            jeu.zone_changer_salle('d');
            jeu.definir_position_perso(taille_cases * (8 + 1.0/2.0), taille_cases * (1 + 1.0/2.0));
        }
    }
}

void JeuSFML::recupere_mouvements()
{
    // Clavier
    // Attention l'axe Y pointe vers le bas
    float x = 0;
    float y = 0;

    if(sf::Joystick::isConnected(0))
    {
        x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {x = x - 100;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {x = x + 100;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {y = y - 100;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {y = y + 100;}
    }

    jeu.deplacer_perso(x, y);

    sf::Vector2i souris;
    souris = sf::Mouse::getPosition(window);

    VecteurM orientation;
    if(sf::Joystick::isConnected(0))
    {
        orientation.set_x(sf::Joystick::getAxisPosition(0, sf::Joystick::U));
        orientation.set_y(sf::Joystick::getAxisPosition(0, sf::Joystick::V));
    }
    else
    {
        orientation.set_x(souris.x - jeu.get_perso().get_pos_x());
        orientation.set_y(souris.y - jeu.get_perso().get_pos_y());
    }


    jeu.definir_orientation_perso(orientation);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {jeu.zone_changer_salle('g');}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {jeu.zone_changer_salle('d');}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {jeu.zone_changer_salle('h');}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {jeu.zone_changer_salle('b');}
    //std::cout << "axe x : " << x << " axe y : " << y << std::endl;
    //std::cout << jeu.get_zone().get_salle_actuelle_x() << " " << jeu.get_zone().get_salle_actuelle_y() << std::endl;
}
