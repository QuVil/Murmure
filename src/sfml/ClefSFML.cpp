#include "ClefSFML.h"
#include "Config.h"

ClefSFML::ClefSFML()
{

}

void ClefSFML::init(Clef* p_cle, const sf::Texture& p_texture, const int& taille_case)
{
    cle = p_cle;
    clefsfml.setTexture(p_texture);
    clefsfml.setOrigin(p_texture.getSize().x/2,p_texture.getSize().y/2);
    clefsfml.setScale(cle->get_taille()*taille_case/p_texture.getSize().x, cle->get_taille()*taille_case/p_texture.getSize().y);
}

sf::Sprite ClefSFML::get_clefsfml()
{
    return clefsfml;
}
