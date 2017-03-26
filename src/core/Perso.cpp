#include "Perso.h"
#include "Fichier.h"
#include "Salle.h"
#include <string>
#include <iostream>
#include <math.h>

Perso::Perso()
{
    position.set_x((float)17/2);
    position.set_y((float)9/2);
    orientation.set_x(0);
    orientation.set_y(0);
    resultante.set_x(0);
    resultante.set_y(0);

    pos_case_x = 8;
    pos_case_y = 4;

    coefficient_vitesse = (float) 1;

    vivant = true;
}

Perso::Perso(std::string n)
{
    nom = n;
    vivant = true;
    Fichier fichier;
    fichier.charger(*this, n);

    position.set_x((float)17/2);
    position.set_y((float)9/2);
    orientation.set_x(0);
    orientation.set_y(0);
    resultante.set_x(0);
    resultante.set_y(0);
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
    position.deplacer(resultante, coefficient_vitesse);
    //std::cout << position.get_x() << " " << position.get_y() << std::endl;
}


void Perso::set_orientation(const VecteurM& v)
{
    if((v.get_x() != 0)&&(v.get_y() != 0))
    {
        orientation = v;
    }
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

float Perso::get_coefficient_vitesse() const
{
    return coefficient_vitesse;
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

float Perso::get_orientation_degre() const
{
    return (atan2(orientation.get_x(), orientation.get_y())/M_PI) * 180;
}

int Perso::get_pos_case_x() const
{
    return pos_case_x;
}

int Perso::get_pos_case_y() const
{
    return pos_case_y;
}


void Perso::set_nom(const std::string& n)
{
    nom = n;
}

void Perso::set_coefficient_vitesse(const int& c)
{
    coefficient_vitesse = c;
}

void Perso::set_pv_max(const int& p)
{
    pv_max = p;
}

void Perso::charger_perso(const std::string& n)
{
    Fichier fichier;
    fichier.charger(*this, n);
}

void Perso::deplacer_txt(char direction)
{
    switch (direction)
    {
    case 'g':
        pos_case_x--;
        break;
    case 'd':
        pos_case_x++;
        break;
    case 'h':
        pos_case_y--;
        break;
    case 'b':
        pos_case_y++;
        break;
    default:
        break;
    }
}

void Perso::placer_txt(int x, int y)
{
    pos_case_x = x;
    pos_case_y = y;
}
