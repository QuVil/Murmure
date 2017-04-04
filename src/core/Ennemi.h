#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

#include <string>
#include "VecteurM.h"
#include "Coord2D.h"

class Ennemi
{
private:
    std::string nom;
    std::string type_ia;

    VecteurM orientation, resultante;

    Coord2D position, position_old;

    float coefficient_vitesse;

    float pv_actuel;

    int taille;

    bool vivant;

    int pos_case_x;
    int pos_case_y;

public:
    Ennemi();

    void infliger_degats(float degats);

    void soigner(float soin);

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

    float get_pv_actuel()const;

    int get_taille()const;

    VecteurM get_orientation() const;

    void set_coefficient_vitesse(const float &c);
};

#endif // ENNEMI_H_INCLUDED
