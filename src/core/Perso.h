#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <string>
#include "VecteurM.h"
#include "Coord2D.h"

class Perso
{
private:
    std::string nom;
    ///TODO : implémenter Arme puis revenir un coup sur Perso.
    //Arme arme1;
    //Arme arme2;

    VecteurM orientation, resultante;

    Coord2D position, position_old;

    float coefficient_reducteur;

    float pv_max; /**< \a pv_max est le nombre de coeurs maximum du Perso. */
    float pv_actuel; /**< \a pv_actuel est la "lose condition" si elle atteint 0, et doit être plus petit que pv_max. */

public:

    Perso();

    Perso(std::string n);

    std::string get_nom()const;

    void set_deplacement(const VecteurM &v);

    void set_deplacement(const float &x, const float &y);

    void set_orientation(const VecteurM &v);

    Coord2D get_pos()const;

    float get_pos_x()const;

    float get_pos_y()const;

    float get_pv_max()const;

    float get_pv_actuel()const;


};

#endif // PERSO_H_INCLUDED
