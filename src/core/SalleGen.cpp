#include "SalleGen.h"

SalleGen::SalleGen()
{
    p_haut = false;
    p_bas = false;
    p_gauche = false;
    p_droite = false;
}

SalleGen::SalleGen(bool p_h, bool p_b, bool p_g, bool p_d)
{
    p_haut = p_h;
    p_bas = p_b;
    p_gauche = p_g;
    p_droite = p_d;
}

void SalleGen::initialisation_gen()
{

}
