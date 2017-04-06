#ifndef CARTEAFFSFML_H_INCLUDED
#define CARTAFFESFML_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

#include "Zone.h"

//module qui va afficher la carte issou

class CarteAffSFML
{
private:
    sf::VertexArray cartesallesfml;
public:
    CarteAffSFML();

    void init(const int &posX,const int &posY,const int &largeur,const int &hauteur, const int &hauteur_tex, const int &largeur_tex);

    sf::VertexArray get_cartesallesfml();
};

#endif // CARTEAFFSFML_H_INCLUDED
