#ifndef TEXTURESFML_H_INCLUDED
#define TEXTURESFML_H_INCLUDED

#include <SFML/Graphics.hpp>

const int nb_texture_herbe_caseSFML= 7;
const int nb_texture_sol_caseSFML= 6;

class TextureSFML
{
private:
    // CaseSFML
    int salle_act_x, salle_act_y;
    sf::RenderStates casesfml[9][17];
    sf::Texture normal_CaseSFML;
    sf::Texture herbe[nb_texture_herbe_caseSFML];
    sf::Texture sol[nb_texture_sol_caseSFML];
    sf::Texture defaut;
    sf::Texture mur_1[8]; /**< \a textures differentes du mur, compter les textures partant de la case en haut à gaughe (coin) et parcourir dans le sens des aiguilles d'une montre */
    sf::Texture trou;
    sf::Texture porte[4];
    sf::Texture rocher;

    // CarteAffSFML
    sf::Texture actuel;
    sf::Texture boss;
    sf::Texture clef;
    sf::Texture depart;
    sf::Texture normal;
    sf::Texture objet;
    sf::Texture vide;

    // Perso
    sf::Texture perso;

    // Curseur
    sf::Texture curseur;

    // Projectile
    sf::Texture proj_1;

public:
    TextureSFML();

    void charger_textures_caseSFML();

    void charger_textures_carteAffSFML();

    void charger_texture_perso();

    void charger_texture_curseur();

    void charger_texture_projectile();

    sf::RenderStates retourne_rendu_texture_caseSFML(const char & type, const int &i, const int &j, const int &x, const int &y);

    sf::RenderStates retourne_rendu_texture_carteAffSFML(const int & config, const bool &salle_act);

    sf::RenderStates retourne_rendu_texture_perso(const sf::Transform &t);

    sf::Texture& retourne_texture_curseur();

    sf::Texture& retourne_texture_perso();

    sf::Texture& retourne_texture_caseSFML(const char & type, const int &i, const int &j);

    sf::Texture& retourne_texture_projectile();
};

#endif // TEXTURESFML_H_INCLUDED
