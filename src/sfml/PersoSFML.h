#ifndef PERSOSFML_H_INCLUDED
#define PERSOSFML_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Perso.h"

class PersoSFML
{
private:
    sf::Sprite persosfml;
public:
    PersoSFML();

    void set_texture(const sf::Texture & texture);

    void mettre_a_jour(const Perso &perso);

    sf::Sprite get_persosfml();
};

#endif // PERSOSFML_H_INCLUDED
