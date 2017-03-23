#include "Perso.h"
#include "Fichier.h"
#include "Salle.h"
#include <string>
#include <iostream>

Perso::Perso()
{
    position.set_x((float)17/2);
    position.set_y((float)9/2);
    orientation.set_x(0);
    orientation.set_y(0);
    resultante.set_x(0);
    resultante.set_y(0);

    coefficient_reducteur = (float)1/10;

    vivant = true;
}

Perso::Perso(std::string n)
{
    nom = n;
    vivant = true;
    Fichier fichier;
    //fichier.charger(*this);
}

std::string Perso::get_nom()const
{
    return nom;
}

void Perso::set_deplacement(const VecteurM& v)
{
    //deplacement = v;
}

void Perso::set_deplacement(const float& x, const float& y)
{
    position_old.set_x(position.get_x());
    position_old.set_y(position.get_y());
    VecteurM deplacement(x, y);
    //std::cout << deplacement.get_x() << " " << deplacement.get_y() << std::endl;
    //resultante = deplacement + resultante;
    resultante = deplacement;
    //std::cout << resultante.get_x() << " " << resultante.get_y() << std::endl;
    position.deplacer(resultante, coefficient_reducteur);
    //std::cout << position.get_x() << " " << position.get_y() << std::endl;
}


void Perso::set_orientation(const VecteurM& v)
{
    orientation = v;
}

Coord2D Perso::get_pos() const
{
    return position;
}

void Perso::set_position(const int& x, const int& y)
{
    position.set_x(x);
    position.set_y(y);
}


void Perso::revenir_ancienne_position()
{
    position.set_x(position_old.get_x());
    position.set_y(position_old.get_y());
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

VecteurM Perso::get_orientation() const
{
    return orientation;
}

void Perso::infliger_degats(float degats)
{
    pv_actuel -= degats;
    if (pv_actuel < 0)
    {
        vivant = false;
    }
}

void Perso::soigner(float soin)
{
    pv_actuel += soin;
    if (pv_actuel > pv_max)
    {
        pv_actuel = pv_max;
    }
}
