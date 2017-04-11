#ifndef GESTIONSALLE_H_INCLUDED
#define GESTIONSALLE_H_INCLUDED

#include "Ennemi.h"
#include "Projectile.h"
#include "Salle.h"
#include "Clef.h"

#include <list>

class GestionSalle
{
private:

    std::list <Ennemi *> ennemis;
    std::list <Projectile *> projectiles;

    Clef* clef;

    int taille_case;

    Salle* salle_actuelle_jeu;

    bool salle_actuelle_pointee; /**< vérifie juste que salle_actuelle_jeu ne pointe pas sur NULL*/
public:
    GestionSalle();

    ~GestionSalle();

    void ajouter_projectile(Projectile * p);

    void mise_a_jour_projectiles(const float &vitesse_frame);

    std::list <Projectile *> * get_projectiles();

    std::list <Ennemi *> * get_ennemis();

    Clef* get_clef();

    void initialise_salle_actuelle(Salle* adresse_salle);

    /**
     * \brief création des entités de la Salle
     * crée les ennemis objets et clefs dans la Salle.
     * \warning la procédure est appelée par Jeu. à ne pas utiliser telle quelle svp
     */
    void maj_changement_salle();

    Salle* get_salle_ptr();

    void vider_projectiles();

    void vider_ennemis(bool dans_destructeur /* =false */);

    void deplacer_ennemis_auto(Coord2D pos_perso);

    void vider_clef();
};

#endif // GESTIONSALLE_H_INCLUDED
