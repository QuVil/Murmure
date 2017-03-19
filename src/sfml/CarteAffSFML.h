#ifndef CARTEAFFSFML_H_INCLUDED
#define CARTAFFESFML_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

#include "Zone.h"

//module qui va afficher la carte issou

class CarteAffSFML
{
private:
    sf::VertexArray cartesallesfml;
    sf::Texture texture;
    sf::RenderStates states;
public:
    CarteAffSFML();

    //posX,posY correspondent  au pixel haut gauche
    CarteAffSFML(int posX,int posY, int largeur, int hauteur, const std::string & type);

    sf::VertexArray get_cartesallesfml();

    sf::Texture get_texture();

    sf::RenderStates get_states();
};

#endif // CARTEAFFSFML_H_INCLUDED
