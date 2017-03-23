#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Zone.h"
#include "Salle.h"
#include "Perso.h"

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

    void zone_changer_salle(const char &c);
};

#endif // JEU_H_INCLUDED
