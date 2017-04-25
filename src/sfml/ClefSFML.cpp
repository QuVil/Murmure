#include "ClefSFML.h"
#include "Config.h"
#include <iostream>

ClefSFML::ClefSFML()
{

}

void ClefSFML::init(Clef* p_cle, const sf::Texture& p_texture, const int& taille_case, const int &x0, const int &y0)
{
    cle = p_cle;
    clefsfml.setTexture(p_texture);
    clefsfml.setOrigin(p_texture.getSize().x/2,p_texture.getSize().y/2);
    clefsfml.setPosition((cle->get_case_x_apparition()+ 1.0/2.0)*taille_case + x0, (cle->get_case_y_apparition() + 1.0/2.0)*taille_case + y0);
    //std::cout << "x :" << cle->get_case_x_apparition() << " y: " << cle->get_case_y_apparition() << std::endl;
    //clefsfml.setPosition(5*taille_case + x0, 5*taille_case + y0);
    clefsfml.setScale(cle->get_taille()*taille_case/p_texture.getSize().x, cle->get_taille()*taille_case/p_texture.getSize().y);
}

void ClefSFML::clef_possedee(const int& taille_case, const int& x0, const int& y0)
{
    //std::cout << "x :" << (nb_cases_hauteur -1 - 1.0/2.0)*taille_case + x0 << " y: " << (nb_cases_largeur -1 -1.0/2.0)*taille_case + y0 << std::endl;
    clefsfml.setPosition((nb_cases_largeur - 1.0/2.0)*taille_case + x0, (nb_cases_hauteur)*taille_case  + y0);
    //clefsfml.setPosition(0, 0);
}

sf::Sprite ClefSFML::get_clefsfml()
{
    return clefsfml;
}

Clef* ClefSFML::get_cle()
{
    return cle;
}
