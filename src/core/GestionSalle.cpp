#include "GestionSalle.h"

GestionSalle::GestionSalle()
{

}

void GestionSalle::change_salle()
{

}

void GestionSalle::mettre_a_jour_projectile_perso()
{
    Projectile p;
}

void GestionSalle::ajouter_projectile(Projectile * p)
{
    projectiles.push_back(p);
}

bool GestionSalle::encore_ennemi()
{
    return ennemis.empty();
}
