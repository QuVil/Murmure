#include "PersoSFML.h"

PersoSFML::PersoSFML()
{

}

void PersoSFML::set_texture(const sf::Texture& texture)
{
    persosfml.setTexture(texture);
    persosfml.setOrigin(32,32);
}

void PersoSFML::mettre_a_jour(const Perso &perso)
{
    /*
    persosfml.setPosition(perso.get_pos_x(),
                                           perso.get_pos_y());*/
    persosfml.setPosition(perso.get_pos_x(), perso.get_pos_y());
}

sf::Sprite PersoSFML::get_persosfml()
{
    return persosfml;
}

sf::Transform PersoSFML::get_transformation_perso()
{

}
