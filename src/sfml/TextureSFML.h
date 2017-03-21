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
    sf::Texture trou;
    sf::Texture porte;
    sf::Texture rocher;


public:
    TextureSFML();

    void charger_textures_caseSFML();

    sf::RenderStates retourne_rendu_texture_caseSFML(const char & type);

    sf::Texture retourne_texture_caseSFML(const char & type);
};

#endif // TEXTURESFML_H_INCLUDED
