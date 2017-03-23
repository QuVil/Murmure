#include <iostream>

#include "Jeu.h"

Jeu::Jeu()
{
    zone.generer_et_remplir(0);
}

Salle Jeu::get_salle()
{
    return zone.get_salle();
}

Zone Jeu::get_zone()
{
    return zone;
}

Perso Jeu::get_perso()
{
    return perso;
}

void Jeu::deplacer_perso(const float& x, const float& y)
{
    perso.set_deplacement(x, y);
}

void Jeu::definir_position_perso(const float& x, const float& y)
{
    perso.set_position(x, y);
}

void Jeu::definir_orientation_perso(const VecteurM& v)
{
    perso.set_orientation(v);
}

void  Jeu::zone_changer_salle(const char& c)
{
    zone.changer_de_salle(c);
}
