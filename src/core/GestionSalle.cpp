 #include "GestionSalle.h"
#include <iostream>

GestionSalle::GestionSalle()
{
    salle_actuelle_jeu = NULL;
    salle_actuelle_pointee = false;
}

GestionSalle::~GestionSalle()
{
    for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
    {
        delete (*it);
        it = projectiles.erase(it);
    }
    for (std::list<Ennemi *>::iterator it=ennemis.begin(); it != ennemis.end(); ++it)
    {
        delete (*it);
        it = ennemis.erase(it);
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
            delete (*it);
            it = projectiles.erase(it);
        }
    }
}
std::list <Projectile *> * GestionSalle::get_projectiles()
{
    return &projectiles;
}

void GestionSalle::initialise_salle_actuelle(Salle* adresse_salle)
{
    salle_actuelle_jeu = adresse_salle;
    //std::cout<<salle_actuelle_jeu;
}

void GestionSalle::maj_changement_salle()
{
    for (int i=0; i<nb_cases_hauteur; ++i)
    {
        for (int j=0; j<nb_cases_largeur; ++j)
        {
            char tests_case = salle_actuelle_jeu->get_case(i, j).get_type_char();

            if (tests_case == 'e')
            {
                Ennemi* e = new Ennemi;
                ennemis.push_back(e);
            }
        }
    }
}

Salle* GestionSalle::get_salle_ptr()
{
    return salle_actuelle_jeu;
}
