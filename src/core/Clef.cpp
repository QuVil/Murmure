#include "Clef.h"

Clef::Clef()
{
    type_clef = 'b';
    par_terre = true;

    taille = 1;

    case_x_apparition = 3;
    case_y_apparition = 3;
}

Clef::Clef(int case_app_x, int case_app_y)
{
    position.set_x((float)case_app_x);
    position.set_y((float)case_app_y);

    taille = 1;

    case_x_apparition = case_app_x;
    case_y_apparition = case_app_y;

    type_clef = 'b';
    par_terre = true;
}

void Clef::ramasser()
{
    par_terre = false;
}

float Clef::get_taille() const
{
    return taille;
}

int Clef::get_case_x_apparition()const
{
    return case_x_apparition;
}

int Clef::get_case_y_apparition()const
{
    return case_y_apparition;
}

bool Clef::get_par_terre()
{
    return par_terre;
}
