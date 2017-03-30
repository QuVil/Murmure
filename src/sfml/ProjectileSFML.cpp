#include "ProjectileSFML.h"

#include <iostream>

ProjectileSFML::ProjectileSFML()
{

}

void ProjectileSFML::init(Projectile * p, const sf::Texture& texture,const int &scale_salle)
{
    projectile = p;
    //std::cout << p->get_taille_projectile() << std::endl;
    projectilesfml.setTexture(texture);
    projectilesfml.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    projectilesfml.setScale((float) p->get_taille_projectile()*scale_salle/texture.getSize().x,(float) p->get_taille_projectile()*scale_salle/texture.getSize().y);
    projectilesfml.setRotation(-projectile->get_orientation_degre()+ 180);
    projectilesfml.setPosition(projectile->get_position().get_x()*scale_salle, projectile->get_position().get_y()*scale_salle);
}

void ProjectileSFML::mise_a_jour_position()
{
    projectilesfml.setPosition(projectile->get_position().get_x(), projectile->get_position().get_y());
}

sf::Sprite ProjectileSFML::retourne_projectilesfml()
{
    return projectilesfml;
}

Projectile* ProjectileSFML::get_projectile()
{
    return projectile;
}
