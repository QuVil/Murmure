#include "Ennemi.h"

#include "Fichier.h"
#include "Salle.h"
#include <string>
#include <iostream>
#include <math.h>

Ennemi::Ennemi()
{
    type_ia = "chasseur";

    vivant = true;
}

void Ennemi::infliger_degats(float degats)
{
    pv_actuel -= degats;
    if (pv_actuel < 0)
    {
        vivant = false;
    }
}

void Ennemi::soigner(float soin)
{
    pv_actuel += soin;
}

int Ennemi::get_pos_case_x() const
{
    return pos_case_x;
}

int Ennemi::get_pos_case_y() const
{
    return pos_case_y;
}

void Ennemi::deplacer_txt(char direction)
{
    switch (direction)
    {
    case 'g':
        pos_case_x--;
        break;
    case 'd':
        pos_case_x++;
        break;
    case 'h':
        pos_case_y--;
        break;
    case 'b':
        pos_case_y++;
        break;
    default:
        break;
    }
}

void Ennemi::placer_txt(int x, int y)
{
    pos_case_x = x;
    pos_case_y = y;
}
