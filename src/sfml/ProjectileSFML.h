#ifndef PROJECTILESFML_H_INCLUDED
#define PROJECTILESFML_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "VecteurM.h"
#include "Coord2D.h"
#include "Projectile.h"

class ProjectileSFML
{
private:
    sf::Sprite projectilesfml;
public:
    ProjectileSFML();

    void init(const Projectile &p, const sf::Texture & texture,const int &scale_salle);

    void mise_a_jour_position(const Coord2D &position);

    sf::Sprite retourne_projectilesfml();
};

#endif // PROJECTILESFML_H_INCLUDED
