#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <string>
#include "VecteurM.h"
#include "Arme.h"
#include "Coord2D.h"
#include "Objet.h"
#include "Projectile.h"


#include <list>

class Perso
{
private:
    std::string nom;
    ///TODO : implémenter Arme puis revenir un coup sur Perso.
    int id_arme1;
    int nv_arme1;
    Arme arme1;
    //Arme arme2;

    VecteurM orientation, resultante;

    VecteurM deplacement;

    Coord2D position, position_old;

    float coefficient_vitesse;

    float taille;

    float pv_max; /**< \a pv_max est le nombre de coeurs maximum du Perso. */
    float pv_actuel; /**< \a pv_actuel est la "lose condition" si elle atteint 0, et doit être plus petit que pv_max. */

    bool vivant;

    int pos_case_x;
    int pos_case_y;

    std::list <Objet*> objets_perso;

    bool possede_clef_boss;

public:

    Perso();

    Perso(std::string n);

    std::string get_nom()const;

    void set_deplacement(const VecteurM &v);

    void set_deplacement(const float &x, const float &y);

    void set_orientation(const VecteurM &v);

    void set_position(const int &x, const int &y);

    void revenir_ancienne_position();

    Coord2D get_pos()const;

    float get_coefficient_vitesse()const;

    float get_orientation_degre()const;

    float get_pos_x()const;

    float get_pos_y()const;

    float get_pv_max()const;

    float get_pv_actuel()const;

    float get_taille()const;

    VecteurM get_deplacement()const;

    VecteurM get_orientation()const;

    void infliger_degats(float degats);

    void soigner(float soin);

    void set_nom(const std::string &n);

    void set_coefficient_vitesse(const float &c);

    void set_pv_max(const int &p);

    void set_taille(const float &t);

    void set_id_arme1(const int &i);

    void set_nv_arme1(const int &i);

    void charger_perso(const std::string &n);

    Arme * get_arme1();

    Projectile* tirer_1();

    void ramasser_clef(Clef* cle);

    //_____________________MODE TXT__________________________
    int get_pos_case_x() const;

    int get_pos_case_y() const;

    void deplacer_txt(char direction);

    void placer_txt(int x, int y);
    //_______________________________________________________
};

#endif // PERSO_H_INCLUDED
