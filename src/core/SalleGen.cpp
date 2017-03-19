#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SalleGen.h"

SalleGen::SalleGen()
{
    p_haut = false;
    p_bas = false;
    p_gauche = false;
    p_droite = false;

    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            grille[i][j] = 0;
        }
    }
}

SalleGen::SalleGen(bool p_h, bool p_b, bool p_g, bool p_d, int conf)
{
    p_haut = p_h;
    p_bas = p_b;
    p_gauche = p_g;
    p_droite = p_d;

    config = conf;

    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            grille[i][j] = 0;
        }
    }
}

void SalleGen::initialisation_gen()
{
    if (!(config == 0))
    {
        for (int i=0; i<9; ++i)
        {
            grille[i][0] = 3;
            grille[i][16] = 3;
        }
        for (int j=0; j<17; ++j)
        {
            grille[0][j] = 3;
            grille[8][j] = 3;
        }

        if (p_haut){grille[0][8] = 1;}
        if (p_bas){grille[8][8] = 1;}
        if (p_gauche){grille[4][0] = 1;}
        if (p_droite){grille[4][16] = 1;}
    }
}

void SalleGen::afficher_tests()const
{
    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            std::cout<<grille[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void SalleGen::placer_clef()
{
    if (config == 3)
    {
        bool clef_placee = false;

        //On vérifie que la clef n'aie pas déjà été placée:
        for (int i=0; i<9; ++i)
        {
            for (int j=0; j<17; ++j)
            {
                if (grille[i][j] == 4){clef_placee = true;}
            }
        }

        //Sinon, on la place au pif sur une CaseSalle valide.
        if (!clef_placee)
        {
            int nb_break = 0;
            while (!clef_placee)
            {
                int i_aleat = rand() % 3 + 3;
                int j_aleat = rand() % 11 + 3;
                if (grille[i_aleat][j_aleat] == 0)
                {
                    grille[i_aleat][j_aleat] = 4;
                    clef_placee = true;
                }

                if (nb_break > 10000)
                {
                    valide = false;
                    break;
                }
                ++nb_break;
            }
        }
    }
}
