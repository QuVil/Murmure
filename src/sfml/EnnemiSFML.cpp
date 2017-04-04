#include "EnnemiSFML.h"

EnnemiSFML::EnnemiSFML()
{

}

void EnnemiSFML::init(Ennemi* p_ennemi, const sf::Texture &p_texture, const int& taille_case)
{
    ennemi = p_ennemi;
    ennemisfml.setTexture(p_texture);
    ennemisfml.setOrigin(p_texture.getSize().x/2,p_texture.getSize().y/2);
    ennemisfml.setScale((float)ennemi->get_taille()*taille_case/p_texture.getSize().x,(float) ennemi->get_taille()*taille_case/p_texture.getSize().y);
}

void EnnemiSFML::mettre_a_jour_position(const int &taille_case, const int &x0, const int &y0)
{
    ennemisfml.setPosition(ennemi->get_pos_x()*taille_case + x0, ennemi->get_pos_y()*taille_case + y0);
    //ennemi.setRotation(-perso->get_orientation_degre()+ 180);
}

sf::Sprite EnnemiSFML::get_ennemisfml()
{
    return ennemisfml;
}

sf::Sprite* EnnemiSFML::get_ennemisfml_ptr()
{
    return &ennemisfml;
}

Ennemi* EnnemiSFML::get_ennemi()
{
    return ennemi;
}
