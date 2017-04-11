#include "Clef.h"

Clef::Clef()
{
    type_clef = 'b';
    par_terre = true;
}

Clef::Clef(int case_app_x, int case_app_y)
{
    position.set_x((float)case_app_x);
    position.set_y((float)case_app_y);

    type_clef = 'b';
    par_terre = true;
}
