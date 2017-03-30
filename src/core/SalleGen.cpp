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

    valide = false;
    difficulte_approx = 0;
    difficulte_voulue = -1;
    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            grille[i][j] = 'n';
        }
    }
    //On n'a même pas à placer les murs, initialisation_gen s'en charge.
}

SalleGen::SalleGen(bool p_h, bool p_b, bool p_g, bool p_d, int conf, int diff)
{
    p_haut = p_h;
    p_bas = p_b;
    p_gauche = p_g;
    p_droite = p_d;

    valide = false;
    config = conf;
    difficulte_voulue = 0;
    difficulte_voulue = diff;

    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            grille[i][j] = 'n';
        }
    }
}

int SalleGen::get_type(int i, int j) const
{
    return grille[i][j];
}

bool SalleGen::is_valide() const
{
    return valide;
}

void SalleGen::set_valide(bool v)
{
    valide = v;
}

int SalleGen::get_difficulte_voulue() const
{
    return difficulte_voulue;
}

int SalleGen::get_difficulte_approx() const
{
    return difficulte_approx;
}

void SalleGen::set_difficulte_voulue(int diff)
{
    difficulte_voulue = diff;
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
    //au passage, la taille 4 est une mauvaise idée.
    assert(type == 'r' || type == 't');
    int depart_amas = rand() % 10; //l'amas commence-t-il dans les coins ou au centre ?
    int i_dep, j_dep;
    int dist_dep = taille + 2;

    switch (depart_amas)
    {
    case 0:
        i_dep = rand() % 2 + 2;
        j_dep = rand() % 2 + 2;
        break;
    case 1:
        i_dep = 1;
        j_dep = 14;
        break;
    case 2:
        i_dep = rand() % 2 + 6;
        j_dep = rand() % 2 + 2;
        break;
    case 3:
        i_dep = rand() % 2 + 6;
        j_dep = 14;
    default:
        i_dep = rand() % 3 + 3;
        j_dep = rand() % 11 + 3;
        break;
    }
    placer_amas_recursif(i_dep, j_dep, type, taille, dist_dep);
}

void SalleGen::placer_amas_recursif(int i, int j, char type, int taille, int dist_dep)
{
    //cas d'arrêt
    if (dist_dep <= 0 || grille[i][j] == 'p' || grille[i][j] == 'm' || grille[i-1][j] == 'p' || grille[i+1][j] == 'p'
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
            placer_amas_recursif(i+1, j, type, taille, dist_dep -1);
        }
        aleat_continue = rand() % (5 - taille);
        if (aleat_continue == 1)
        {
            placer_amas_recursif(i-1, j, type, taille, dist_dep -1);
        }
        aleat_continue = rand() % (5 - taille);
        if (aleat_continue == 0)
        {
            placer_amas_recursif(i, j-1, type, taille, dist_dep -1);
        }
        aleat_continue = rand() % (5 - taille);
        if (aleat_continue == 2)
        {
            placer_amas_recursif(i, j+1, type, taille, dist_dep -1);
        }
        aleat_continue = rand() % (9 - taille);
        if (aleat_continue == 4)
        {
            placer_amas_recursif(i+1, j+1, type, taille, dist_dep -1);
        }
        aleat_continue = rand() % (9 - taille);
        if (aleat_continue == 2)
        {
            placer_amas_recursif(i-1, j+1, type, taille, dist_dep -1);
        }
        aleat_continue = rand() % (9 - taille);
        if (aleat_continue == 6)
        {
            placer_amas_recursif(i-1, j-1, type, taille, dist_dep -1);
        }
        aleat_continue = rand() % (9 - taille);
        if (aleat_continue == 3)
        {
            placer_amas_recursif(i+1, j-1, type, taille, dist_dep -1);
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
            if (grille_validation[i][j] == 'p' || grille_validation[i][j] == 'c')
            {
                valide = false;
            }
        }
    }
    calculer_difficulte();
}

void SalleGen::valider_recursif(int i, int j)
{
    //cas d'arrêt
    if (grille_validation[i][j] == 'p' || grille_validation[i][j] == 'c')
    {
        grille_validation[i][j] = '*';
        //on garde les portes en tête pour vérifier qu'elles soient toutes atteignables.
    }
    else if (grille_validation[i][j] == 'm' || grille_validation[i][j] == 't' || grille_validation[i][j] == 'r')
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

void SalleGen::placer_ennemi()
{
    if (config != 4 && config != 2 && config != 0)
    {
        bool ennemi_place = false;
        int nb_break = 0;
        while (!ennemi_place)
        {
            int emplacement_bloc = rand() % 10; //l'ennemi est-il dans un coin ou au milieu ?
            int i_dep, j_dep;

            switch (emplacement_bloc)
            {
            case 0:
                //coin en haut à gauche.
                i_dep = rand() % 2 + 1;
                j_dep = rand() % 2 + 1;
                break;
            case 1:
                i_dep = rand() % 2 + 1;
                j_dep = rand() % 2 + 14;
                break;
            case 2:
                i_dep = rand() % 2 + 6;
                j_dep = rand() % 2 + 1;
                break;
            case 3:
                i_dep = rand() % 2 + 6;
                j_dep = rand() % 2 + 14;;
            default:
                i_dep = rand() % 3 + 3;
                j_dep = rand() % 11 + 3;
                break;
            }
            if (grille[i_dep][j_dep] == 'n')
            {
                grille[i_dep][j_dep] = 'e';
                ennemi_place = true;
            }
            else if (nb_break > 10000)
            {
                break;
            }
            ++nb_break;
        }
    }
}

//exactement la même que celle de ZoneGen. Peut-être trouver une implémentation +propre ?
int SalleGen::calculer_distance(int x_dep, int y_dep, int x_arr, int y_arr) const
{
    int dist_x = x_arr - x_dep;
    int dist_y = y_arr - y_dep;

    if (dist_x < 0){dist_x = 0 - dist_x;}
    if (dist_y < 0){dist_y = 0 - dist_y;}

    return (dist_x + dist_y);
}

int SalleGen::calculer_distance_porte(int x, int y) const
{
    int dist_g = calculer_distance(x, y, 4, 0);
    int dist_d = calculer_distance(x, y, 4, 16);
    int dist_h = calculer_distance(x, y, 0, 8);
    int dist_b = calculer_distance(x, y, 8, 8);
    return std::min(dist_b, std::min(dist_g, std::min(dist_h, dist_d)));
}


void SalleGen::calculer_difficulte()
{
    int diff = 0;
    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<17; ++j)
        {
            switch (grille[i][j])
            {
                case 'e':
                    diff += 25 - calculer_distance_porte(i, j)*2;
                    break;
                case 'r':
                    diff += std::max(4 - calculer_distance_porte(i, j), 0);
                    break;
                case 't':
                    diff += std::max(7 - calculer_distance_porte(i, j), 0);
                    break;
                case 'c':
                    diff += 3;
                default:
                    break;
            }
        }
    }
    difficulte_approx = diff;
}

void SalleGen::vider_salle()
{
    for (int i=1; i<8; ++i)
    {
        for (int j=1; j<16; ++j)
        {
            grille[i][j] = 'n';
        }
    }
}

void SalleGen::placer_portes(int h, int b, int g, int d)
{
    if (h == 1){p_haut = true;}
    if (b == 1){p_bas = true;}
    if (g == 1){p_gauche = true;}
    if (d == 1){p_droite = true;}
}

void SalleGen::set_config(int c)
{
    config = c;
}
