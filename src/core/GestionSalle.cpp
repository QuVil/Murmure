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
    if(p->get_position().get_x())
    projectiles.push_back(p);
}

void GestionSalle::mise_a_jour_projectiles(const float& vitesse_frame, const int &taille_case)
{
    //std::cout << projectiles.size() << " <- taille des proj" << std::endl;
    for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
    {
        //std::cout << (*it)->get_position().get_x() << " " << (*it)->get_position().get_y() << std::endl;
        (*it)->avancer(vitesse_frame);
        if(((*it)->get_position().get_x()<0)||((*it)->get_position().get_x()>17*taille_case)||((*it)->get_position().get_y()<0)||((*it)->get_position().get_y()>9*taille_case))
        {
            delete &it;
            if(projectiles.size() == 1)
            {
                projectiles.clear();
                break;
                //it = projectiles.end();
            }
            else
            {
                it = projectiles.erase(it);
            }
        }
    }
}
std::list <Projectile *> * GestionSalle::get_projectiles()
{
    return &projectiles;
}
