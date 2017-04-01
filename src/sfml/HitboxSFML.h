#ifndef HITBOXSFML_H_INCLUDED
#define HITBOXSFML_H_INCLUDED

#include "PersoSFML.h"
#include "ProjectileSFML.h"
#include "CaseSFML.h"

#include <list>

class HitboxSFML
{
private:
    CaseSFML * casesalle;
    PersoSFML * perso;
    std::list<ProjectileSFML> * projectiles;

    sf::FloatRect perso_hb;
    sf::IntRect casesalle_hb[9][17];
    std::list<sf::FloatRect *> projectiles_hb;
public:
    HitboxSFML();

    void init(CaseSFML * p_casesalle, PersoSFML * p_perso, ProjectileSFML * p_projectiles);

    void changer_salle();

    void gere_collisions();
};

#endif // HITBOXSFML_H_INCLUDED
