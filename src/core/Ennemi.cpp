#include "Ennemi.h"

#include "Fichier.h"
#include "Salle.h"
#include "Config.h"

#include <string>
#include <iostream>
#include <math.h>

Ennemi::Ennemi()
{
    type_ia = "chasseur";

    taille = 1;

    vivant = true;
}

Ennemi::Ennemi(std::string ia, int case_x_app, int case_y_app)
{
    type_ia = ia;
    case_x_apparition = case_x_app;
    case_y_apparition = case_y_app;

    position.set_x((float) facteur*(case_y_app + 1.0/2.0));
    position.set_y((float) facteur*(case_x_app + 1.0/2.0));

    vivant = true;

    taille = 1;

    coefficient_vitesse = 40;
}

void Ennemi::set_deplacement(const VecteurM& v)
{
    ///TODO TODO TODO TODO TODO TODO TODO
}

float Ennemi::get_orientation_degre() const
{
    ///TODO TODO TODO TODO TODO TODO TODO
    return 1.0;
}


void Ennemi::infliger_degats(float degats)
{
    pv_actuel -= degats;
    if (pv_actuel < 0)
    {
        vivant = false;
    }
}

void Ennemi::soigner(float soin)
{
    pv_actuel += soin;
}

void Ennemi::set_deplacement(const Coord2D &position_perso)
{
    position_old.set_x(position.get_x());
    position_old.set_y(position.get_y());
    //std::cout << resultante.get_x() << " " << resultante.get_y() << std::endl;
    trouver_chemin(position_perso);
    //std::cout << position.get_x() << " " << position.get_y() << std::endl;
}


void Ennemi::set_orientation(const VecteurM& v)
{
    if((v.get_x() != 0)&&(v.get_y() != 0))
    {
        orientation = v;
    }
}

Coord2D Ennemi::get_position() const
{
    return position;
}

void Ennemi::set_position(const int& x, const int& y)
{
    position.set_x(x);
    position.set_y(y);
}


void Ennemi::revenir_ancienne_position()
{
    position.set_x(position_old.get_x());
    position.set_y(position_old.get_y());
}

float Ennemi::get_coefficient_vitesse() const
{
    return coefficient_vitesse;
}

float Ennemi::get_pos_x() const
{
    return position.get_x();
}

float Ennemi::get_pos_y() const
{
    return position.get_y();
}

float Ennemi::get_pv_actuel() const
{
    return pv_actuel;
}

int Ennemi::get_taille() const
{
    return taille;
}

VecteurM Ennemi::get_orientation() const
{
    return orientation;
}

void Ennemi::set_coefficient_vitesse(const float& c)
{
    coefficient_vitesse = c;
}

int Ennemi::get_case_x_apparition() const
{
    return case_x_apparition;
}

int Ennemi::get_case_y_apparition() const
{
    return case_y_apparition;
}

bool Ennemi::is_vivant()
{
    return vivant;
}

void Ennemi::set_mort()
{
    vivant = false;
}

void Ennemi::trouver_chemin(const Coord2D &position_perso)
{
    VecteurM deplacement;
    if (type_ia == "chasseur")
    {
        position.set_x(position.get_x() - cos(-get_angle_perso(position_perso) + M_PI_2)* coefficient_vitesse);
        position.set_y(position.get_y() - sin(-get_angle_perso(position_perso) + M_PI_2)* coefficient_vitesse);
        //std::cout << position.get_x() << " " << position.get_y() << std::endl;
    }
}

float Ennemi::get_angle_perso(const Coord2D &pos_perso) const
{
    return (atan2(position.get_x() - pos_perso.get_x(), position.get_y() - pos_perso.get_y())/M_PI) * 180;
}


void Ennemi::deplacer_auto(Coord2D pos_perso)
{
    trouver_chemin(pos_perso);
}



