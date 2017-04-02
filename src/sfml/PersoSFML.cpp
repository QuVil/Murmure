#include "PersoSFML.h"
#include <iostream>

PersoSFML::PersoSFML()
{

}

void PersoSFML::charge_perso(Perso * p,const sf::Texture& texture,const int &taille_case)
{
    perso = p;
    persosfml.setTexture(texture);
    persosfml.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    persosfml.setScale(p->get_taille()*taille_case/texture.getSize().x, p->get_taille()*taille_case/texture.getSize().y);
}

void PersoSFML::mettre_a_jour()
{
    persosfml.setPosition(perso->get_pos_x(), perso->get_pos_y());
    persosfml.setRotation(-perso->get_orientation_degre()+ 180);
}

sf::Sprite PersoSFML::get_persosfml()
{
    return persosfml;
}

sf::Sprite* PersoSFML::get_persosfml_ptr()
{
    return &persosfml;
}

Perso* PersoSFML::get_perso_ptr()
{
    return perso;
}
