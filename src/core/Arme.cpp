#include "Arme.h"

///TODO : Gary, j'ai besoin de ton aide pour la gestion des projectiles.
//L'instance d'Arme a un vector qui est en fait un tab dynamique de Projectile.
//Le but est d'appeler tirer() avec la position de départ, l'angle et la vitesse
//et que le projectile se gère ensuite tout seul en gros. tu devrais sûrement changer le
//constructeur de Projectile, mais je ne vois pas trop comment tu utilises tes vecteurs.
//GL HF

Arme::Arme()
{
    liste_balles.reserve(20);
}

void Arme::tirer(float pos_x, float pos_y /*,orientation ?*/)
{
    Projectile p(id_projectiles, degats_projectiles);

    liste_balles.push_back(p);
}
