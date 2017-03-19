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

CarteAffSFML::CarteAffSFML(int posX, int posY, int largeur, int hauteur,const std::string & type)
{
    cartesallesfml.resize(4);
    cartesallesfml.setPrimitiveType(sf::Quads);
    cartesallesfml[0].position = sf::Vector2f(posX,posY);
    cartesallesfml[1].position = sf::Vector2f(posX+largeur, posY);
    cartesallesfml[2].position = sf::Vector2f(posX+largeur, posY+hauteur);
    cartesallesfml[3].position = sf::Vector2f(posX, posY+hauteur);

    cartesallesfml[0].texCoords = sf::Vector2f(0,0);
    cartesallesfml[1].texCoords = sf::Vector2f(64, 0);
    cartesallesfml[2].texCoords = sf::Vector2f(64,33);
    cartesallesfml[3].texCoords = sf::Vector2f(0,33);

    std::stringstream ss;
    ss << "data/res/CarteAff/" << type << ".png";
    std::string path = ss.str();
    texture.loadFromFile(path);

    states.texture = &texture;
}

sf::VertexArray CarteAffSFML::get_cartesallesfml()
{
    return cartesallesfml;
}

sf::Texture CarteAffSFML::get_texture()
{
    return texture;
}

sf::RenderStates CarteAffSFML::get_states()
{
    return states;
}
