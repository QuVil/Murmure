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
    ///TODO : choisir si Ennemi utilise une Arme ou tire les Projectile manuellement
    //Arme arme1;
    //Arme arme2;

    VecteurM orientation, resultante;

    Coord2D position, position_old;

    float coefficient_reducteur;

    float pv_actuel;

    bool vivant;

    int pos_case_x;
    int pos_case_y;

public:
    Ennemi();

    void infliger_degats(float degats);

    void soigner(float soin);

    //___________________MODE TXT____________________________
    int get_pos_case_x() const;

    int get_pos_case_y() const;

    void deplacer_txt(char direction);

    void placer_txt(int x, int y);
    //_______________________________________________________
};

#endif // ENNEMI_H_INCLUDED
