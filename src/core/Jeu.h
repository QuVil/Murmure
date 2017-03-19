#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Zone.h"
#include "Salle.h"

class Jeu
{
private:
    Zone zone;

public:
    Jeu();

    Salle get_salle()const;

    Zone get_zone()const;
};

#endif // JEU_H_INCLUDED
