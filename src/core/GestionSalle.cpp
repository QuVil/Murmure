#include "GestionSalle.h"
#include <iostream>

GestionSalle::GestionSalle()
{

}

GestionSalle::~GestionSalle()
{
    for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
    {
        std::cout << "projectile supprimé" << std::endl;
        delete &it;
        it = projectiles.erase(it);
    }
}

void GestionSalle::ajouter_projectile(Projectile* p)
{
    projectiles.push_back(p);
}

void GestionSalle::mise_a_jour_projectiles(const float& vitesse_frame)
{
    for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
    {
        (*it)->avancer(vitesse_frame);
    }
}
