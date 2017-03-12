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
    // cf ici pour les textures + couleurs des VertexArrays
    // https://maksimdan.gitbooks.io/sfml-and-gamedevelopement/content/vertex_arrays.html
    casesfml.resize(4);
    casesfml.setPrimitiveType(sf::Quads);
    casesfml[0].position = sf::Vector2f(posX,posY);
    casesfml[1].position = sf::Vector2f(posX+largeur, posY);
    casesfml[2].position = sf::Vector2f(posX+largeur, posY+hauteur);
    casesfml[3].position = sf::Vector2f(posX, posY+hauteur);

    casesfml[0].texCoords = sf::Vector2f(0,0);
    casesfml[1].texCoords = sf::Vector2f(64, 0);
    casesfml[2].texCoords = sf::Vector2f(64, 64);
    casesfml[3].texCoords = sf::Vector2f(0, 64);
/*
    casesfml[0].color = sf::Color::Blue;
    casesfml[1].color = sf::Color::Blue;
    casesfml[2].color = sf::Color::Blue;
    casesfml[3].color = sf::Color::Blue;*/

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
