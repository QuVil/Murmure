#include "Perso.h"
#include "Fichier.h"
#include <string>

using namespace std;

Perso::Perso()
{
    angle_mouvement = 0;
    angle_regard = 0;
}

Perso::Perso(string n)
{
    nom = n;
    Fichier fichier;
    //fichier.charger(*this);
}

float Perso::get_angle_regard()const
{
    return angle_regard;
}

float Perso::get_vitesse()const
{
    return vitesse;
}

float Perso::get_angle_mouvement() const
{
    return angle_mouvement;
}


float Perso::get_pos_y() const
{
    return pos_y;
}

float Perso::get_pv_max() const
{
    return pv_max;
}

float Perso::get_pv_actuel() const
{
    return pv_actuel;
}
