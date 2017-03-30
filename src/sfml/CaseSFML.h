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

    int taille;
public:
    CaseSFML();

    void init(int posX,int posY, int largeur, int hauteur);

    void mettre_a_jour_taille_texture(const int &t);

    sf::VertexArray get_casesfml();

    int get_taille_texture();
};

#endif // CASESFML_H_INCLUDED
