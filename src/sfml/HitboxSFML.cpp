#include "HitboxSFML.h"

HitboxSFML::HitboxSFML()
{

}

void HitboxSFML::init(CaseSFML* p_casesalle, PersoSFML* p_perso, std::list<ProjectileSFML*>* p_projectiles)
{
    casesalle = p_casesalle;
    perso = p_perso;
    projectiles = p_projectiles;
}

void HitboxSFML::changer_salle()
{
    projectiles_hb.clear();
    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<17; ++j)
        {
            casesalle_hb[i][j] = casesalle[i + 17*j].get_casesfml().getBounds();
        }
    }
}

void HitboxSFML::gere_collisions()
{
    actualise_hb_perso();
    // Perso et obstacle
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<17; j++)
        {
            //if(case)
        }
    }

}

void HitboxSFML::actualise_hb_perso()
{
    perso_hb = perso->get_persosfml().getGlobalBounds();
}
