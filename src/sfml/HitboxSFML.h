#ifndef HITBOXSFML_H_INCLUDED
#define HITBOXSFML_H_INCLUDED

#include "PersoSFML.h"
#include "ProjectileSFML.h"
#include "CaseSFML.h"

#include <list>

class HitboxSFML
{
private:

    void actualise_hb_perso();
public:
    HitboxSFML();

    ~HitboxSFML();

    void changer_salle();

    void perso_et_salle(PersoSFML * perso, CaseSFML * casesalle);
    void projectiles_et_salle(std::list<ProjectileSFML *> * projectiles, CaseSFML * casesalle);
};

#endif // HITBOXSFML_H_INCLUDED
