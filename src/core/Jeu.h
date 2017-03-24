#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Zone.h"
#include "Salle.h"
#include "Perso.h"
#include "VecteurM.h"

class Jeu
{
private:
    Zone zone;
    Perso perso;

public:
    Jeu();

    Salle get_salle();

    Zone get_zone();

    Perso get_perso();

    void deplacer_perso(const float &x, const float &y);

    void definir_position_perso(const float &x, const float &y);

    void definir_orientation_perso(const VecteurM &v);

    void zone_changer_salle(const char &c);

    void deplacer_perso_txt(char direction);

    void placer_perso_txt(int x, int y);
};

#endif // JEU_H_INCLUDED
