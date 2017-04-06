 #include "GestionSalle.h"
#include <iostream>

GestionSalle::GestionSalle()
{
    salle_actuelle_jeu = NULL;
    salle_actuelle_pointee = false;
}

GestionSalle::~GestionSalle()
{
    vider_projectiles();
    vider_ennemis(true);
}

void GestionSalle::ajouter_projectile(Projectile* p)
{
    if(p->get_position().get_x())
    projectiles.push_back(p);
}

void GestionSalle::mise_a_jour_projectiles(const float& vitesse_frame)
{
    //std::cout << projectiles.size() << " <- taille des proj" << std::endl;
    for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
    {
        //std::cout << (*it)->get_position().get_x() << " " << (*it)->get_position().get_y() << std::endl;
        if((*it)->get_collision())
        {
            delete (*it);
            it = projectiles.erase(it);
        }
        else
        {
            (*it)->avancer(vitesse_frame);
            if(((*it)->get_position().get_x()<0)||((*it)->get_position().get_x()>17)||((*it)->get_position().get_y()<0)||((*it)->get_position().get_y()>9))
            {
                delete (*it);
                it = projectiles.erase(it);
            }
        }

    }
}

std::list <Projectile *> * GestionSalle::get_projectiles()
{
    return &projectiles;
}

std::list <Ennemi *> * GestionSalle::get_ennemis()
{
    return &ennemis;
}

void GestionSalle::initialise_salle_actuelle(Salle* adresse_salle)
{
    //On supprime les projectiles et les ennemis avant de changer le pointeur de la Salle:
    vider_projectiles();
    vider_ennemis(false);

    //On actualise le pointeur sur la nouvelle salle actuelle:
    salle_actuelle_jeu = adresse_salle;
    //std::cout<<salle_actuelle_jeu;
}

void GestionSalle::maj_changement_salle()
{
    //On ajoute les ennemis
    for (int i=0; i<nb_cases_hauteur; ++i)
    {
        for (int j=0; j<nb_cases_largeur; ++j)
        {
            char tests_case = salle_actuelle_jeu->get_case(i, j).get_type_char();

            if (tests_case == 'e')
            {
                Ennemi* e = new Ennemi("chasseur", i, j);
                ennemis.push_back(e);
                //std::cout << "bite" << std::endl;
            }
        }
    }
}

Salle* GestionSalle::get_salle_ptr()
{
    return salle_actuelle_jeu;
}

void GestionSalle::vider_projectiles()
{
    for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
    {
        delete (*it);
        projectiles.erase(it);
    }
}

void GestionSalle::vider_ennemis(bool dans_destructeur = false)
{
    for (std::list<Ennemi *>::iterator it=ennemis.begin(); it != ennemis.end(); ++it)
    {
        std::cout << "ennemi supprime" << std::endl;
        int case_x = (*it)->get_case_x_apparition();
        int case_y = (*it)->get_case_y_apparition();

        if (salle_actuelle_jeu->get_case(case_x, case_y).get_type_char() == 'e' && (*it)->is_vivant() == false)
        {
            CaseSalle case_normale;
            case_normale.set_type('n');
            salle_actuelle_jeu->set_case(case_x, case_y, case_normale);
        }


        delete (*it);
        ennemis.erase(it);
    }
}
