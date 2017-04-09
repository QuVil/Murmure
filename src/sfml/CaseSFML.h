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

    char type_case;
    int taille;
public:
    CaseSFML();

    void init(int posX,int posY, int largeur, int hauteur);

    void mettre_a_jour_taille_texture(const int &t);

    void mettre_a_jour_type_case(const char &c);

    void check_collision();

    sf::VertexArray get_casesfml()const;

    int get_taille_texture()const;

    char get_type_case()const;
};

#endif // CASESFML_H_INCLUDED
