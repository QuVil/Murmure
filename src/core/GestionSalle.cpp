#include "GestionSalle.h"
#include <iostream>

GestionSalle::GestionSalle()
{

}

GestionSalle::~GestionSalle()
{
    for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
    {
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
    //std::cout << projectiles.size() << " <- taille des proj" << std::endl;
    for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
    {
        //std::cout << (*it)->get_position().get_x() << " " << (*it)->get_position().get_y() << std::endl;
        (*it)->avancer(vitesse_frame);
    }
}
std::list <Projectile *> * GestionSalle::get_projectiles()
{
    return &projectiles;
}
