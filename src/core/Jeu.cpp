#include <iostream>

#include "Jeu.h"

Jeu::Jeu()
{
    zone.generer_et_remplir(0);
}

Salle Jeu::get_salle()const
{
    return zone.get_salle();
}

Zone Jeu::get_zone()const
{
    return zone;
}

Perso Jeu::get_perso() const
{
    return perso;
}
