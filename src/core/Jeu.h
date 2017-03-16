#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Salle.h"

class Jeu
{
private:
    Salle salle;

public:
    Jeu();

    Salle get_salle();
};

#endif // JEU_H_INCLUDED
