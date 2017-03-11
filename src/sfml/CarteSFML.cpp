#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

#include "CarteSFML.h"

CarteSFML::CarteSFML()
{
    sallesfml.resize(4);
    sallesfml.setPrimitiveType(sf::Quads);
    sallesfml[0].position = sf::Vector2f(0, 0);
    sallesfml[1].position = sf::Vector2f(0, 0);
    sallesfml[2].position = sf::Vector2f(0, 0);
    sallesfml[3].position = sf::Vector2f(0, 0);
}

CarteSFML::CarteSFML(int posX, int posY, int largeur, int hauteur,const std::string & type)
{
    sallesfml.resize(4);
    sallesfml.setPrimitiveType(sf::Quads);
    sallesfml[0].position = sf::Vector2f(posX,posY);
    sallesfml[1].position = sf::Vector2f(posX+largeur, posY);
    sallesfml[2].position = sf::Vector2f(posX+largeur, posY+hauteur);
    sallesfml[3].position = sf::Vector2f(posX, posY+hauteur);

    sallesfml[0].texCoords = sf::Vector2f(posX,posY);
    sallesfml[1].texCoords = sf::Vector2f(posX+largeur, posY);
    sallesfml[2].texCoords = sf::Vector2f(posX+largeur, posY+hauteur);
    sallesfml[3].texCoords = sf::Vector2f(posX, posY+hauteur);

    std::stringstream ss;
    ss << "data/res/Carte/" << type << ".png";
    std::string path = ss.str();
    texture.loadFromFile(path);

    states.texture = &texture;
}

sf::VertexArray CarteSFML::get_sallesfml()
{
    return sallesfml;
}

sf::Texture CarteSFML::get_texture()
{
    return texture;
}

sf::RenderStates CarteSFML::get_states()
{
    return states;
}
