#include "Perso.h"
#include "Fichier.h"
#include "Salle.h"
#include <string>

Perso::Perso()
{
    position.set_x(17/2);
    position.set_y(9/2);
}

Perso::Perso(std::string n)
{
    nom = n;
    Fichier fichier;
    //fichier.charger(*this);
}

std::string Perso::get_nom()const
{
    return nom;
}

void Perso::set_deplacement(const VecteurM& v)
{
    deplacement = v;
}

void Perso::set_orientation(const VecteurM& v)
{
    orientation = v;
}

Coord2D Perso::get_pos() const
{
    return position;
}



float Perso::get_pos_x() const
{
    return position.get_x();
}

float Perso::get_pos_y() const
{
    return position.get_y();
}

float Perso::get_pv_max() const
{
    return pv_max;
}

float Perso::get_pv_actuel() const
{
    return pv_actuel;
}
