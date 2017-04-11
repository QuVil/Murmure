#ifndef CLEF_H_INCLUDED
#define CLEF_H_INCLUDED

#include "Coord2D.h"

class Clef
{
private:
    char type_clef; /**< le type de clef -- pour le moment, un seul type : 'b' comme boss*/
    Coord2D position;
    bool par_terre;

public:
    Clef();

    Clef(int case_app_x, int case_app_y);

    void ramasser();
};

#endif // CLEF_H_INCLUDED
