#include <iostream>

#include "ZoneGen.h"

#include "Fichier.h"

ZoneGen::ZoneGen()
{
    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            carte[i][j] = 0;
        }
    }
    patterne = " ";
    methode = " ";
    pret_iteration = false;
    valide = false;
}

ZoneGen::ZoneGen(string pat, string met)
{
    patterne = pat;
    methode = met;
    pret_iteration = false;
    valide = false;
}

int ZoneGen::get_etat(int x, int y) const
{
    return carte[x][y];
}

int ZoneGen::get_posx_dep() const
{
    return posx_dep;
}

int ZoneGen::get_posy_dep() const
{
    return posy_dep;
}

int ZoneGen::nb_cases ()const
{
    int nb =0;
    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            if (carte[i][j] == 1)
            {
                nb++;
            }
        }
    }
    return nb;
}

void ZoneGen::initialisation_gen(string pat, string met)
{
    //Vérifie qu'un patterne et une méthode valides soient entrées, et dessine le patterne de base.
    if (patterne == " ")
    {
        patterne = pat;
    }
    else
    {
        cout<<"patterne deja choisi : "<<patterne<<endl;
    }

    if (methode == " ")
    {
        methode = met;
    }
    else
    {
        cout<<"methode deja choisie : "<<methode<<endl;
    }

    Fichier fichier;
    fichier.charger(*this);

/*
    if (patterne == "croix")
    {
        for (int i=0; i<11; ++i)
        {
            for (int j=0; j<11; ++j)
            {
                if (i==5 || j==5)
                    carte[i][j] = 1;
                else
                    carte[i][j] = 0;
            }
        }
    }
    else if (patterne == "carre")
    {
        carte[5][5] = 1;
        for (int i=0; i<11; ++i)
        {
            for (int j=0; j<11; ++j)
            {
                if ((i>1 && i<9 && (j==2 || j==8)) || (j>1 && j<9 && (i==2 || i==8)))
                    carte[i][j] = 1;
                else
                    carte[i][j] = 0;
            }
        }
    }
    else if (patterne == "h")
    {
        for (int i=0; i<11; ++i)
        {
            for (int j=0; j<11; ++j)
            {
                if ((i>1 && i<9 && (j==2 || j==8)) || (j>1 && j<8 && i==5))
                    carte[i][j] = 1;
                else
                    carte[i][j] = 0;
            }
        }
    }

    else if (patterne == "vide")
    {
        for (int i=0; i<11; ++i)
        {
            for (int j=0; j<11; ++j)
            {
                carte[i][j] = 0;
            }
        }
    }
    else if (patterne == "hub")
    {
        for (int i=0; i<11; ++i)
        {
            for (int j=0; j<11; ++j)
            {
                if (i<7 && j<7 && i>3 && j>3)
                    carte[i][j] = 1;
                else
                    carte[i][j] = 0;
            }
        }
    }
    else
    {
        cout<<"error : Invalid pattern"<<endl;
        terminate();
    }*/

    if (!(methode == "voisins" || methode == "bruit" || methode == "aleatoire" || methode == "epuration"))
    {
        cout<<"error : Invalid method"<<endl;
        terminate();
    }
    pret_iteration = true;
}

void ZoneGen::afficher_carte()const
{
    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            if (carte[i][j] == 0)
                cout<<"- ";
            else
                cout<<"X ";
        }
        cout<<endl;
    }
}

void ZoneGen::iterer(string meth /* = "" */)
{
    if (meth != "" && meth != " ") //Si on passe une methode => changement de la methode
    {
        methode = meth;
        cout<<"methode changee"<<endl;
    }
    //itere la creation de la carte selon la méthode donnée dans l'instance au temps t
    if (pret_iteration == false)
        cout<<"erreur : modele potentiellement non initialise..."<<endl;
    srand (time(NULL));

    if (methode == "voisins")
    {
        for (int i=1; i<10; ++i)
        {
            for (int j=1; j<10; ++j)
            {
                int voisins = 0;
                if (carte[i-1][j] == 1)
                {
                    voisins++;
                }
                if (carte[i+1][j] == 1)
                {
                    voisins++;
                }
                if (carte[i][j-1] == 1)
                {
                    voisins++;
                }
                if (carte[i][j+1] == 1)
                {
                    voisins++;
                }

                if((i!=5 || j!=5) && voisins == 1 && carte[i][j] == 1)
                {
                    int nb_aleat = rand() % 12;
                    switch(nb_aleat)
                    {
                    case 1:
                        carte[i][j] = 0;
                        break;
                    case 4:
                        if (carte[i+1][j] == 0)
                        {
                            carte[i+1][j] = 1;
                        }
                        break;
                    case 6:
                        if (carte[i][j-1] == 0)
                        {
                            carte[i][j-1] = 1;
                        }
                        break;
                    case 9:
                        if (carte[i-1][j] == 0)
                        {
                            carte[i-1][j] = 1;
                        }
                        break;
                    default:
                        break;

                    }
                }

                if((i!=5 || j!=5) && voisins == 1 && carte[i][j] == 0)
                {
                    int nb_aleat = rand() % 12;
                    switch(nb_aleat)
                    {
                    case 7:
                        carte[i][j] = 1;
                        break;
                    default:
                        break;

                    }
                }

                if((i!=5 || j!=5) && voisins == 2 && carte[i+1][j] == 0)
                {
                    int nb_aleat = rand() % 12;
                    switch(nb_aleat)
                    {
                    case 6:
                        carte[i+1][j] = 1;
                        break;
                    case 3:
                        carte[i][j] = 1;
                        break;
                    default:
                        break;

                    }
                }

                if((i!=5 || j!=5) && voisins == 3 && carte[i][j] == 0)
                {
                    int nb_aleat = rand() % 6;
                    switch(nb_aleat)
                    {
                    case 2:
                        carte[i][j] = 1;
                        break;
                    default:
                        break;

                    }
                }

                if((i!=5 || j!=5) && voisins == 3 && carte[i][j] == 1)
                {
                    int nb_aleat = rand() % 12
                                   ;
                    switch(nb_aleat)
                    {
                    case 9:
                        carte[i][j] = 0;
                        break;
                    default:
                        break;

                    }
                }

                if((i!=5 || j!=5) && voisins == 0)
                {
                    int nb_aleat = rand() % 5;
                    switch(nb_aleat)
                    {
                    case 4:
                        carte[i][j] = 0;
                        break;
                    default:
                        break;

                    }
                }


                if((i!=5 || j!=5) && voisins == 2)
                {
                    int nb_aleat = rand() % 15;
                    switch(nb_aleat)
                    {
                    case 10:
                        carte[i][j] = 0;
                        break;
                    default:
                        break;

                    }
                }

                if((i!=5 || j!=5) && voisins == 1 && carte[i][j+1] == 0 && carte[i][j-1] == 0)
                {
                    int nb_aleat = rand() % 10;
                    switch(nb_aleat)
                    {
                    case 5:
                        carte[i][j-1] = 1;
                        break;
                    case 7:
                        carte[i][j+1] = 1;
                        break;
                    default:
                        break;

                    }
                }

                if((i!=5 || j!=5) && voisins == 4)
                {
                    int nb_aleat = rand() % 9;
                    switch(nb_aleat)
                    {
                    case 6:
                        carte[i][j] = 0;
                        break;
                    default:
                        break;

                    }
                }
            }
        }
    }


    if (methode == "aleatoire")
    {
        for (int i=1; i<10; ++i)
        {
            for (int j=1; j<10; ++j)
            {
                if (carte[i][j] == 0 && (i !=5 || j != 5))
                {
                    int nb_aleat = rand() % 14;
                    if (nb_aleat == 12)
                    {
                        carte[i][j] = 1;
                    }
                }

                if (carte[i][j] == 1 && (i !=5 || j != 5))
                {
                    int nb_aleat = rand() % 20;
                    if (nb_aleat == 7)
                    {
                        carte[i][j] = 0;
                    }
                }
            }
        }
    }

    if (methode == "epuration" || methode == "extension")
    {
        int v_haut, v_bas, v_gauche, v_droite = 0; //de quel côté sont les voisins ?
        for (int i=0; i<11; ++i)
        {
            for (int j=0; j<11; ++j)
            {
                v_haut = 0;
                v_bas = 0;
                v_gauche = 0;
                v_droite = 0;
                int voisins = 0;
                if (i>0)
                {
                    if (carte[i-1][j] == 1)
                    {
                        voisins++;
                        v_haut = 1;
                    }
                }

                if (i<10)
                {
                    if (carte[i+1][j] == 1)
                    {
                        voisins++;
                        v_bas = 1;
                    }
                }

                if (j>0)
                {
                    if (carte[i][j-1] == 1)
                    {
                        voisins++;
                        v_gauche = 1;
                    }
                }

                if (j<10)
                {
                    if (carte[i][j+1] == 1)
                    {
                        voisins++;
                        v_droite = 1;
                    }
                }

                if (methode == "epuration" && voisins == 0 && carte[i][j] == 1)
                {
                    carte[i][j] = 0;
                }

                if (methode == "extension" && voisins == 1 && carte[i][j] == 1 && i>0 && i<10 && j>0 && j<10)
                {
                    int nb_aleat = rand() % 4;
                    if (v_haut == 1 && nb_aleat == 3)
                    {
                        carte[i+1][j] = 1;
                        cout<<"extension à bas"<<endl;
                    }

                    if (v_bas == 1 && nb_aleat == 2)
                    {
                        carte[i-1][j] = 1;
                        cout<<"extension à haut"<<endl;
                    }

                    if (v_gauche == 1 && nb_aleat == 1)
                    {
                        int nb_bonus = rand() % 1;

                        if (nb_bonus == 0)
                        {
                            carte[i][j+1] = 1;
                            cout<<"extension à droite"<<endl;
                        }
                    }

                    if (v_droite == 1 && nb_aleat == 0)
                    {
                        carte[i][j-1] = 1;
                        cout<<"extension à gauche"<<endl;
                    }
                }
            }
        }
    }
}

string ZoneGen::get_patterne()
{
    return patterne;
}

void ZoneGen::set_salle(int i, int j, int salle)
{
    carte[i][j] = salle;
}
