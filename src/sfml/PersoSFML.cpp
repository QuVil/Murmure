#include "PersoSFML.h"
#include <iostream>

PersoSFML::PersoSFML()
{

}

void PersoSFML::charge_perso(const sf::Texture& texture,const int &taille_case, const float &taille_perso)
{
    persosfml.setTexture(texture);
    persosfml.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    //std::cout << 0.6*taille_case/texture.getSize().x << " " << 0.6*taille_case/texture.getSize().y << std::endl;
    persosfml.setScale(taille_perso*taille_case/texture.getSize().x, taille_perso*taille_case/texture.getSize().y);
}

void PersoSFML::mettre_a_jour(const Perso &perso)
{
    /*
    persosfml.setPosition(perso.get_pos_x(),
                                           perso.get_pos_y());*/
    persosfml.setPosition(perso.get_pos_x(), perso.get_pos_y());
    persosfml.setRotation(-perso.get_orientation_degre()+ 180);
}

sf::Sprite PersoSFML::get_persosfml()
{
    return persosfml;
}
