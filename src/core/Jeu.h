#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Zone.h"
#include "Salle.h"
#include "Perso.h"
#include "VecteurM.h"
#include "GestionSalle.h"

#include <list>

class Jeu
{
private:
    Zone zone;
    Perso perso;
    GestionSalle salle_actuelle;

public:
    Jeu();

    Salle* get_salle_actuelle();

    Zone get_zone();

    Perso get_perso();

    int grille_largeur();

    int grille_hauteur();

    void changer_perso(const std::string &n);

    void deplacer_perso(const float &x, const float &y);

    void definir_position_perso(const float &x, const float &y);

    void definir_orientation_perso(const VecteurM &v);

    void zone_changer_salle(const char &c);

    void deplacer_perso_txt(char direction);

    void placer_perso_txt(int x, int y);

    void ajouter_projectile_perso(const int &arme);

    void avancer_jeu(const float &vitesse_base, const int &taille_case);

    std::list <Projectile *> * retourne_projectiles();

    std::list <Ennemi *> * retourne_ennemis();

    Perso * retourne_perso_ptr();
};

#endif // JEU_H_INCLUDED
