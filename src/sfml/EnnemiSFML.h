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
    EnnemiSFML();

    void init(Ennemi * p_ennemi,const sf::Texture &p_texture, const int &taille_case);

    void mettre_a_jour_position(const int &taille_case, const int &x0, const int &y0);

    sf::Sprite get_ennemisfml();

    sf::Sprite * get_ennemisfml_ptr();

    Ennemi * get_ennemi();

    VecteurM get_taille()const;

    Coord2D get_position_hg()const;
};

#endif // ENNEMISFML_H_INCLUDED
