#ifndef PERSOSFML_H_INCLUDED
#define PERSOSFML_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Perso.h"

class PersoSFML
{
private:
    sf::Sprite persosfml;

    Perso * perso;
public:
    PersoSFML();

    void charge_perso(Perso * p,const sf::Texture & texture, const int &taille_case);

    void mettre_a_jour(const int &taille_case, const int &x0, const int &y0);

    sf::Sprite get_persosfml();

    sf::Sprite * get_persosfml_ptr();

    Perso * get_perso_ptr();
};

#endif // PERSOSFML_H_INCLUDED
