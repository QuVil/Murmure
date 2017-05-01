#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

#include "CarteAffSFML.h"

CarteAffSFML::CarteAffSFML()
{
    cartesallesfml.resize(4);
    cartesallesfml.setPrimitiveType(sf::Quads);
    cartesallesfml[0].position = sf::Vector2f(0, 0);
    cartesallesfml[1].position = sf::Vector2f(0, 0);
    cartesallesfml[2].position = sf::Vector2f(0, 0);
    cartesallesfml[3].position = sf::Vector2f(0, 0);
}

void CarteAffSFML::init(const int& posX, const int& posY, const int& largeur, const int& hauteur, const int& hauteur_tex, const int& largeur_tex)
{
    cartesallesfml.resize(4);
    cartesallesfml.setPrimitiveType(sf::Quads);
    cartesallesfml[0].position = sf::Vector2f(posX,posY);
    cartesallesfml[1].position = sf::Vector2f(posX+largeur, posY);
    cartesallesfml[2].position = sf::Vector2f(posX+largeur, posY+hauteur);
    cartesallesfml[3].position = sf::Vector2f(posX, posY+hauteur);

    cartesallesfml[0].texCoords = sf::Vector2f(0,0);
    cartesallesfml[1].texCoords = sf::Vector2f(largeur_tex, 0);
    cartesallesfml[2].texCoords = sf::Vector2f(largeur_tex,hauteur_tex);
    cartesallesfml[3].texCoords = sf::Vector2f(0,hauteur_tex);
}


sf::VertexArray CarteAffSFML::get_cartesallesfml()
{
    return cartesallesfml;
}
