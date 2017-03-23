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

    coefficient_reducteur = 1/50;
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
    //deplacement = v;
}

void Perso::set_deplacement(const float& x, const float& y)
{
    VecteurM deplacement(x, y);
    resultante = resultante + deplacement;
    position.deplacer(resultante, coefficient_reducteur);
    std::cout << position.get_x() << " " << position.get_y() << std::endl;
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
