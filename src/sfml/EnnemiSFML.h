#ifndef ENNEMISFML_H_INCLUDED
#define ENNEMISFML_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Ennemi.h"

class EnnemiSFML
{
private:
    sf::Sprite ennemisfml;

    Ennemi * ennemi;
public:
    Ennemi();

    void init(Ennemi * p_ennemi, sf::Texture * p_texture, const int &taille_case);

    void mettre_a_jour_position();

    sf::Sprite get_ennemisfml();

    sf::Sprite * get_ennemisfml_ptr();

    Ennemi * get_ennemi_ptr();
};

#endif // ENNEMISFML_H_INCLUDED
