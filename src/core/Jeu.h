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

    Salle get_salle()const;

    Zone get_zone()const;

    Perso get_perso()const;
};

#endif // JEU_H_INCLUDED
