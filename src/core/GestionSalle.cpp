#include "GestionSalle.h"
#include "Config.h"
#include <iostream>

GestionSalle::GestionSalle()
{
    salle_actuelle_jeu = NULL;
    salle_actuelle_pointee = false;
    clef = NULL;
}

GestionSalle::~GestionSalle()
{
    vider_projectiles();
    vider_ennemis(true);
    vider_clef();
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
            if(((*it)->get_position().get_x()<0)||((*it)->get_position().get_x()>taille_grille_largeur)||((*it)->get_position().get_y()<0)||((*it)->get_position().get_y()>taille_grille_hauteur))
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

Clef* GestionSalle::get_clef()
{
    return clef;
}

bool GestionSalle::salle_terminee()
{
    for (std::list<Ennemi *>::iterator it=ennemis.begin(); it != ennemis.end(); ++it)
    {
        if((*it)->is_vivant())
        {
            return 0;
        }
    }
    return 1;
}

void GestionSalle::initialise_salle_actuelle(Salle* adresse_salle)
{
    //On supprime les projectiles et les ennemis avant de changer le pointeur de la Salle:
    vider_projectiles();
    vider_ennemis(false);
    vider_clef();

    //On actualise le pointeur sur la nouvelle salle actuelle:
    salle_actuelle_jeu = adresse_salle;
    //std::cout<<salle_actuelle_jeu;
}

void GestionSalle::maj_changement_salle()
{
    //On ajoute les ennemis et les clefs
    for (int i=0; i<nb_cases_hauteur; ++i)
    {
        for (int j=0; j<nb_cases_largeur; ++j)
        {
            char tests_case = salle_actuelle_jeu->get_case(i, j).get_type_char();

            if (tests_case == 'e')
            {
                    Ennemi* e = new Ennemi("chasseur", i, j);
                    ennemis.push_back(e);
                    std::cout << "ennemi ++" << std::endl;
                    CaseSalle case_normale;
                    case_normale.set_type('n');
                    salle_actuelle_jeu->set_case(i, j, case_normale);
            }
            else if (tests_case == 'c')
            {
                Clef* c = new Clef(j, i);
                clef = c;
                std::cout<<"clef placee"<<std::endl;
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
    while(projectiles.size() > 0)
    {
        for (std::list<Projectile *>::iterator it=projectiles.begin(); it != projectiles.end(); ++it)
        {
            delete (*it);
            it = projectiles.erase(it);
        }
    }

}

void GestionSalle::vider_ennemis(bool dans_destructeur = false)
{
    while(ennemis.size() > 0)
    {
        for (std::list<Ennemi *>::iterator it=ennemis.begin(); it != ennemis.end(); ++it)
        {
            //std::cout << "ennemi supprime" << std::endl;
            delete (*it);
            it = ennemis.erase(it);
        }
    }
}

void GestionSalle::deplacer_ennemis_auto(Coord2D pos_perso)
{
    for (std::list<Ennemi *>::iterator it=ennemis.begin(); it != ennemis.end(); ++it)
    {
        if((*it)->is_vivant())
        {
            (*it)->deplacer_auto(pos_perso);
        }
        else
        {
            delete (*it);
            it = ennemis.erase(it);
        }
    }
}

void GestionSalle::vider_clef()
{
    if (clef != NULL)
    {
        if (!clef->get_par_terre())
        {
            CaseSalle case_normale;
            case_normale.set_type('n');
            salle_actuelle_jeu->set_case(clef->get_case_x_apparition(), clef->get_case_y_apparition(), case_normale);
        }
        delete clef;
        clef = NULL;
    }
}
