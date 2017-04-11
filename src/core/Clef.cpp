#include "Clef.h"

Clef::Clef()
{
    type_clef = 'b';
    par_terre = true;

    case_x_apparition = 3;
    case_y_apparition = 3;
}

Clef::Clef(int case_app_x, int case_app_y)
{
    position.set_x((float)case_app_x);
    position.set_y((float)case_app_y);

    case_x_apparition = case_app_x;
    case_y_apparition = case_app_y;

    type_clef = 'b';
    par_terre = true;
}

void Clef::ramasser()
{
    par_terre = false;
}

int Clef::get_case_x_apparition()
{
    return case_x_apparition;
}

int Clef::get_case_y_apparition()
{
    return case_y_apparition;
}

bool Clef::get_par_terre()
{
    return par_terre;
}
