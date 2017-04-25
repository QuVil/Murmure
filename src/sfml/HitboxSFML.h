#ifndef HITBOXSFML_H_INCLUDED
#define HITBOXSFML_H_INCLUDED

#include "PersoSFML.h"
#include "ProjectileSFML.h"
#include "CaseSFML.h"
#include "EnnemiSFML.h"
#include "ClefSFML.h"
#include "Jeu.h"

#include <list>

class HitboxSFML
{
private:

    void actualise_hb_perso();
    void glisser_perso(CaseSFML *casesfml, PersoSFML *perso, const int &taille_case, const int &x0, const int &y0);
public:
    HitboxSFML();

    ~HitboxSFML();

    void changer_salle();

    void perso_et_salle(PersoSFML * perso, CaseSFML * casesalle, Jeu * jeu, const int &taille_case, const int &x0, const int &y0);
    void projectiles_et_salle(std::list<ProjectileSFML *> * projectiles, CaseSFML * casesalle);
    void projectiles_et_ennemis(std::list<ProjectileSFML *> * projectiles, std::list<EnnemiSFML *> * ennemis);
    void ennemis_et_salle(std::list<EnnemiSFML *> *ennemis, CaseSFML * casesalle, const int &taille_case, const int &x0, const int &y0);
    void perso_et_clef(PersoSFML * perso, ClefSFML * clef);
};

#endif // HITBOXSFML_H_INCLUDED
