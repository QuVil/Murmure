#include "Ennemi.h"

#include "Fichier.h"
#include "Salle.h"
#include <string>
#include <iostream>
#include <math.h>

Ennemi::Ennemi()
{
    type_ia = "chasseur";

    taille = 1;

    vivant = true;
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

void Ennemi::set_deplacement(const float& x, const float& y)
{
    position_old.set_x(position.get_x());
    position_old.set_y(position.get_y());
    VecteurM deplacement(x, y);
    //std::cout << deplacement.get_x() << " " << deplacement.get_y() << std::endl;
    //resultante = deplacement + resultante;
    resultante = deplacement;
    //std::cout << resultante.get_x() << " " << resultante.get_y() << std::endl;
    position.deplacer(resultante, coefficient_vitesse);
    //std::cout << position.get_x() << " " << position.get_y() << std::endl;
}


void Ennemi::set_orientation(const VecteurM& v)
{
    if((v.get_x() != 0)&&(v.get_y() != 0))
    {
        orientation = v;
    }
}

Coord2D Ennemi::get_pos() const
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
