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

    float orientation;

    Coord2D position, position_old;

    VecteurM deplacement;

    float coefficient_vitesse;

    float pv_actuel;

    float taille;

    bool vivant;

    int case_x_apparition;
    int case_y_apparition;

public:
    Ennemi();

    Ennemi(std::string ia, int case_x_app, int case_y_app);

    void infliger_degats(float degats);

    void soigner(float soin);

    void set_deplacement(const VecteurM &v);

    void set_deplacement(const float &x, const float &y);

    void set_deplacement(const Coord2D &position_perso);

    void set_orientation(const VecteurM &v);

    void set_position(const int &x, const int &y);

    void revenir_ancienne_position();

    Coord2D get_position()const;

    VecteurM get_deplacement() const;

    float get_coefficient_vitesse()const;

    float get_orientation_degre()const;

    float get_pos_x()const;

    float get_pos_y()const;

    float get_pv_actuel()const;

    float get_taille()const;

    float get_orientation() const;

    float get_angle_perso(const Coord2D &pos_perso)const;

    void set_coefficient_vitesse(const float &c);

    int get_case_x_apparition()const;

    int get_case_y_apparition()const;

    bool is_vivant();

    void set_mort();

    void trouver_chemin(const Coord2D &position_perso);

    void deplacer_auto(Coord2D pos_perso);
};

#endif // ENNEMI_H_INCLUDED
