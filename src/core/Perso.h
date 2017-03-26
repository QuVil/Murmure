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

    float coefficient_vitesse;

    float pv_max; /**< \a pv_max est le nombre de coeurs maximum du Perso. */
    float pv_actuel; /**< \a pv_actuel est la "lose condition" si elle atteint 0, et doit être plus petit que pv_max. */

    bool vivant;

    int pos_case_x;
    int pos_case_y;

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

    VecteurM get_orientation()const;

    void infliger_degats(float degats);

    void soigner(float soin);

    void set_nom(const std::string &n);

    void set_coefficient_vitesse(const int &c);

    void set_pv_max(const int &p);

    void charger_perso(const std::string &n);

    //_____________________MODE TXT__________________________
    int get_pos_case_x() const;

    int get_pos_case_y() const;

    void deplacer_txt(char direction);

    void placer_txt(int x, int y);
    //_______________________________________________________
};

#endif // PERSO_H_INCLUDED
