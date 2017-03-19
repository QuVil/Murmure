#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cassert>

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

void SalleGen::placer_amas(int type, int taille) // type = 2 ou 5, taille entre 0 et 4
{
    assert(taille < 5 && taille >= 0);
    int depart_amas = rand() % 9; //l'amas commence-t-il dans les coins ou au centre ?
    int i_dep, j_dep;

    switch (depart_amas)
    {
    case 0:
        i_dep = 2;
        j_dep = 2;
        break;
    case 1:
        i_dep = 1;
        j_dep = 14;
        break;
    case 2:
        i_dep = 6;
        j_dep = 2;
        break;
    case 3:
        i_dep = 6;
        j_dep = 14;
    default:
        i_dep = rand() % 3 + 3;
        j_dep = rand() % 11 + 3;
        break;
    }
    std::cout<<i_dep<<", "<<j_dep<<" recursivite"<<std::endl;
    placer_amas_recursif(i_dep, j_dep, type, taille);
}

void SalleGen::placer_amas_recursif(int i, int j, int type, int taille)
{
    //cas d'arrêt
    if (grille[i][j] == 1 || grille[i][j] == 3 || grille[i-1][j] == 1 || grille[i+1][j] == 1
        || grille[i][j-1] == 1 || grille[i][j+1] == 1 || grille[i+1][j+1] == 1
        || grille[i-1][j-1] == 1 || grille[i+1][j-1] == 1 || grille[i-1][j+1] == 1 || grille[i][j] == type)
    {
        std::cout<<"fin de recursivite en "<<i<<" "<<j<<std::endl;
    }
    else
    {
        grille[i][j] = type;
        int aleat_continue = rand() % (5 - taille);
        if (aleat_continue == 2)
        {
            placer_amas_recursif(i+1, j, type, taille);
        }
        aleat_continue = rand() % (5 - taille);
        if (aleat_continue == 1)
        {
            placer_amas_recursif(i-1, j, type, taille);
        }
        aleat_continue = rand() % (5 - taille);
        if (aleat_continue == 0)
        {
            placer_amas_recursif(i, j-1, type, taille);
        }
        aleat_continue = rand() % (5 - taille);
        if (aleat_continue == 2)
        {
            placer_amas_recursif(i, j+1, type, taille);
        }
        aleat_continue = rand() % (9 - taille);
        if (aleat_continue == 4)
        {
            placer_amas_recursif(i+1, j+1, type, taille);
        }
        aleat_continue = rand() % (9 - taille);
        if (aleat_continue == 2)
        {
            placer_amas_recursif(i-1, j+1, type, taille);
        }
        aleat_continue = rand() % (9 - taille);
        if (aleat_continue == 6)
        {
            placer_amas_recursif(i-1, j-1, type, taille);
        }
        aleat_continue = rand() % (9 - taille);
        if (aleat_continue == 3)
        {
            placer_amas_recursif(i+1, j-1, type, taille);
        }
    }
}
