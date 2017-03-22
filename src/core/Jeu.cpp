#include <iostream>

#include "Jeu.h"

Jeu::Jeu()
{
    zone.zone_depuis_modele_aleatoire(0);
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
