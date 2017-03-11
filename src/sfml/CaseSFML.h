#ifndef CASESFML_H_INCLUDED
#define CASESFML_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

#include "CaseSalle.h"

// Module qui va gerer chacune des case la grille d'un niveau
// on utilise des vertexarrays pcq il paraît que c'est mieux (cf la
// doc de sfml)

class CaseSFML
{
private:
    sf::VertexArray casesfml;
    sf::Texture texture;
    sf::RenderStates states;
public:
    CaseSFML();

    //posX,posY correspondent  au pixel haut gauche
    CaseSFML(int posX,int posY, int largeur, int hauteur, const std::string & type);

    sf::VertexArray get_casesfml();

    sf::Texture get_texture();

    sf::RenderStates get_states();
};

#endif // CASESFML_H_INCLUDED
