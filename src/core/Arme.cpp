#include "Arme.h"
#include "Fichier.h"

///TODO : Gary, j'ai besoin de ton aide pour la gestion des projectiles.
//L'instance d'Arme a un vector qui est en fait un tab dynamique de Projectile.
//Le but est d'appeler tirer() avec la position de départ, l'angle et la vitesse
//et que le projectile se gère ensuite tout seul en gros. tu devrais sûrement changer le
//constructeur de Projectile, mais je ne vois pas trop comment tu utilises tes vecteurs.
//GL HF

Arme::Arme()
{

}

void Arme::charger(const int& id, const int& nv)
{
    Fichier fichier;
    fichier.charger(*this, id, nv);
}

void Arme::tirer(float pos_x, float pos_y /*,orientation ?*/)
{
    Projectile p(id_projectiles, degats_projectiles);

}

void Arme::set_id_arme(const int& i)
{
    id_arme = i;
}

void Arme::set_nv_arme(const int& i)
{
    nv_arme = i;
}

void Arme::set_id_projectiles(const int& i)
{
    id_projectiles = i;
}

void Arme::set_degats_projectiles(const int& i)
{
    degats_projectiles = i;
}

void Arme::set_munitions_max(const int& i)
{
    munitions_max = i;
}
