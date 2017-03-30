#include "ProjectileSFML.h"

ProjectileSFML::ProjectileSFML()
{

}

void ProjectileSFML::init(const Projectile &p, const sf::Texture& texture,const int &scale_salle)
{
    projectilesfml.setTexture(texture);
    projectilesfml.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    projectilesfml.setRotation(-p.get_orientation_degre()+ 180);
    projectilesfml.setPosition(p.get_position().get_x()*scale_salle, p.get_position().get_y()*scale_salle);
}

void ProjectileSFML::mise_a_jour_position(const Coord2D& position)
{
    projectilesfml.setPosition(position.get_x(), position.get_y());
}

sf::Sprite ProjectileSFML::retourne_projectilesfml()
{
    return projectilesfml;
}
