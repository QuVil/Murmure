#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

#include "CaseSFML.h"

CaseSFML::CaseSFML()
{
    casesfml.resize(4);
    casesfml.setPrimitiveType(sf::Quads);
    casesfml[0].position = sf::Vector2f(0, 0);
    casesfml[1].position = sf::Vector2f(0, 0);
    casesfml[2].position = sf::Vector2f(0, 0);
    casesfml[3].position = sf::Vector2f(0, 0);
}

CaseSFML::CaseSFML(int posX, int posY, int largeur, int hauteur,const std::string & type)
{
    casesfml.resize(4);
    casesfml.setPrimitiveType(sf::Quads);
    casesfml[0].position = sf::Vector2f(posX,posY);
    casesfml[1].position = sf::Vector2f(posX+largeur, posY);
    casesfml[2].position = sf::Vector2f(posX+largeur, posY+hauteur);
    casesfml[3].position = sf::Vector2f(posX, posY+hauteur);

    casesfml[0].texCoords = sf::Vector2f(0,0);
    casesfml[1].texCoords = sf::Vector2f(0+largeur, 0);
    casesfml[2].texCoords = sf::Vector2f(0+largeur, 0+hauteur);
    casesfml[3].texCoords = sf::Vector2f(0, 0+hauteur);

    std::stringstream ss;
    ss << "data/res/CaseSalle/" << type << ".png";
    std::string path = ss.str();
    texture.loadFromFile(path);

    states.texture = &texture;
}

sf::VertexArray CaseSFML::get_casesfml()
{
    return casesfml;
}

sf::Texture CaseSFML::get_texture()
{
    return texture;
}

sf::RenderStates CaseSFML::get_states()
{
    return states;
}
