#ifndef TEXTURESFML_H_INCLUDED
#define TEXTURESFML_H_INCLUDED

#include <string>

#include <SFML/Graphics.hpp>

class TextureSFML
{
private:
    // CaseSFML
    sf::Texture mur;
    sf::Texture normal;
    //sf::Texture trou;
    sf::Texture porte;


public:
    TextureSFML();

    void charger_textures_caseSFML();

    sf::Texture retourne_texture_caseSFML(const char & type);
};

#endif // TEXTURESFML_H_INCLUDED
