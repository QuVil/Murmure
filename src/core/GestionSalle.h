#ifndef GESTIONSALLE_H_INCLUDED
#define GESTIONSALLE_H_INCLUDED

#include "Ennemi.h"
#include "Projectile.h"
#include "Salle.h"

#include <list>

class GestionSalle
{
private:

    std::list <Ennemi> ennemis;
    std::list <Projectile *> projectiles;

    int taille_case;

    Salle* salle_actuelle_jeu;

    bool salle_actuelle_pointee; /**< vérifie juste que salle_actuelle_jeu ne pointe pas sur NULL*/
public:
    GestionSalle();

    ~GestionSalle();

    void ajouter_projectile(Projectile * p);

    void mise_a_jour_projectiles(const float &vitesse_frame, const int &taille_case);

    std::list <Projectile *> * get_projectiles();

    void initialise_salle_actuelle(Salle* adresse_salle);

    void maj_changement_salle();
};

#endif // GESTIONSALLE_H_INCLUDED
