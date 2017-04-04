#include "EnnemiSFML.h"

void EnnemiSFML::init(Ennemi* p_ennemi, sf::Texture* p_texture, const int& taille_case)
{
    ennemi = p_ennemi;
    ennemisfml.setTexture(texture);
    ennemisfml.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    ennemisfml.setScale(ennemi->get_taille()*taille_case/texture.getSize().x, ennemi->get_taille()*taille_case/texture.getSize().y);
}

void EnnemiSFML::mettre_a_jour_position()
{
    ennemi.setPosition(perso->get_pos_x(), perso->get_pos_y());
    //ennemi.setRotation(-perso->get_orientation_degre()+ 180);
}

Sprite EnnemiSFML::get_ennemisfml()
{
    return ennemisfml;
}

Sprite* EnnemiSFML::get_ennemisfml_ptr()
{
    return &ennemisfml;
}

Ennemi* EnnemiSFML::get_ennemi_ptr()
{
    return ennemi;
}
