#ifndef TEXTURESFML_H_INCLUDED
#define TEXTURESFML_H_INCLUDED

#include <SFML/Graphics.hpp>

const int nb_texture_herbe_caseSFML= 7;

class TextureSFML
{
private:
    // CaseSFML
    int salle_act_x, salle_act_y;
    sf::RenderStates casesfml[9][17];
    sf::Texture normal;
    sf::Texture herbe[nb_texture_herbe_caseSFML];
    sf::Texture defaut;
    sf::Texture mur_1[8]; /**< \a textures differentes du mur, compter les textures partant de la case en haut à gaughe (coin) et parcourir dans le sens des aiguilles d'une montre */
    sf::Texture trou;
    sf::Texture porte;
    sf::Texture rocher;

    void creation_tableau_textures_caseSFML();


public:
    TextureSFML();

    void charger_textures_caseSFML();

    sf::RenderStates retourne_rendu_texture_caseSFML(const char & type, const int &i, const int &j, const int &x, const int &y);
};

#endif // TEXTURESFML_H_INCLUDED
