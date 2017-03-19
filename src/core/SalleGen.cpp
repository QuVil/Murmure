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
            grille[i][j] = 'n';
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
            grille[i][j] = 'n';
        }
    }
}

bool SalleGen::is_valide() const
{
    return valide;
}

void SalleGen::initialisation_gen()
{
    if (!(config == 0))
    {
        for (int i=0; i<9; ++i)
        {
            grille[i][0] = 'm';
            grille[i][16] = 'm';
        }
        for (int j=0; j<17; ++j)
        {
            grille[0][j] = 'm';
            grille[8][j] = 'm';
        }

        if (p_haut){grille[0][8] = 'p';}
        if (p_bas){grille[8][8] = 'p';}
        if (p_gauche){grille[4][0] = 'p';}
        if (p_droite){grille[4][16] = 'p';}
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
                if (grille[i][j] == 'c'){clef_placee = true;}
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
                if (grille[i_aleat][j_aleat] == 'n')
                {
                    grille[i_aleat][j_aleat] = 'c';
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

void SalleGen::placer_amas(char type, int taille) // type = 2 ou 5, taille entre 0 et 4
{
    assert(taille < 5 && taille >= 0);
    assert(type == 'r' || type == 't');
    int depart_amas = rand() % 10; //l'amas commence-t-il dans les coins ou au centre ?
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
    placer_amas_recursif(i_dep, j_dep, type, taille);
}

void SalleGen::placer_amas_recursif(int i, int j, char type, int taille)
{
    //cas d'arrêt
    if (grille[i][j] == 'p' || grille[i][j] == 'm' || grille[i-1][j] == 'p' || grille[i+1][j] == 'p'
        || grille[i][j-1] == 'p' || grille[i][j+1] == 'p' || grille[i+1][j+1] == 'p'
        || grille[i-1][j-1] == 'p' || grille[i+1][j-1] == 'p' || grille[i-1][j+1] == 'p' || grille[i][j] == type)
    {
        //rien
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

void SalleGen::valider()
{
    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            grille_validation[i][j] = grille[i][j];
        }
    }

    int i_dep = 1;
    int j_dep = 8;
    valider_recursif(i_dep, j_dep);
    valide = true;
    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            if (grille_validation[i][j] == 'p')
            {
                valide = false;
            }
        }
    }
}

void SalleGen::valider_recursif(int i, int j)
{
    //cas d'arrêt
    if (grille_validation[i][j] == 'p')
    {
        grille_validation[i][j] = '*';
    }
    else if (grille_validation[i][j] == 'm' || grille_validation[i][j] == 't')
    {
        //rien
    }
    else
    {
        grille_validation[i][j] = 't';

        if (i < 8)
        {
            valider_recursif(i+1, j);
        }
        if (i > 0)
        {
            valider_recursif(i-1, j);
        }
        if (j < 16)
        {
            valider_recursif(i, j+1);
        }
        if (j > 0)
        {
            valider_recursif(i, j-1);
        }
    }
}

void SalleGen::afficher_validation() const
{
    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            std::cout<<grille_validation[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
