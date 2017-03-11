#ifndef CARTESFML_H_INCLUDED
#define CARTESFML_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

#include "Zone.h"

// Module qui va gerer chacune des case la grille d'un niveau
// on utilise des vertexarrays pcq il paraît que c'est mieux (cf la
// doc de sfml)

class CarteSFML
{
private:
    sf::VertexArray sallesfml;
    sf::Texture texture;
    sf::RenderStates states;
public:
    CarteSFML();

    //posX,posY correspondent  au pixel haut gauche
    CarteSFML(int posX,int posY, int largeur, int hauteur, const std::string & type);

    sf::VertexArray get_sallesfml();

    sf::Texture get_texture();

    sf::RenderStates get_states();
};

#endif // CARTESFML_H_INCLUDED
