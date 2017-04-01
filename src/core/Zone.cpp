/**
 * \file Zone.cpp
 * \brief Code source pour le module Zone
 * \author Quentin.V
 * \version 0.2
 * \date 18 mars 2017
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Zone.h"
#include "Fichier.h"

//constructeur de base, avec toutes les salles vides et le nom "Zone"
Zone::Zone()
{
    niveau_zone = 1;

    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            carte[i][j].vider();
        }
    }
    zone_generee = false;
    difficulte_moyenne = 0;
    salle_actuelle_x = 5;
    salle_actuelle_y = 5;
}

//crée une instance de zone en passant en paramètre les coordonnées de la salle
//actuelle et son nom
Zone::Zone(int posx, int posy, int niv = 1)
{
    niveau_zone = niv;

    zone_generee = false;
    difficulte_moyenne = 0;
    salle_actuelle_x = posx;
    salle_actuelle_y = posy;
}

Zone::Zone(const ZoneGen &z)
{
    salle_actuelle_x = z.get_posx_dep();
    salle_actuelle_y = z.get_posy_dep();

    zone_generee = true;

    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            carte[i][j].set_config(z.get_etat(i, j));
        }
    }
}

Salle Zone::get_salle(int x, int y)
{
    return carte[x][y];
}

Salle Zone::get_salle()const
{
    return carte[salle_actuelle_x][salle_actuelle_y];
}

Salle* Zone::get_salle_ptr()
{
    return &carte[salle_actuelle_x][salle_actuelle_y];
}


void Zone::set_salle(int x, int y, const Salle &nouvelle_salle)
{
    carte[x][y] = nouvelle_salle;
}

int Zone::get_salle_actuelle_x ()const
{
        return salle_actuelle_x;
}

int Zone::get_salle_actuelle_y ()const
{
    return salle_actuelle_y;
}

void Zone::afficher_zone()
{
    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            if (carte[i][j].get_config() == 0)
                std::cout<<"- ";
            else if (carte[i][j].get_config() == 2)
                std::cout<<"b ";
            else if (carte[i][j].get_config() == 3)
                std::cout<<"c ";
            else if (carte[i][j].get_config() == 4)
                std::cout<<"d ";
            else if (carte[i][j].get_config() == 5)
                std::cout<<"o ";
            else
                std::cout<<"X ";
        }
        std::cout<<std::endl;
    }
}

void Zone::remplir_salle(int x, int y)
{
    carte[x][y].remplir();
}

void Zone::remplir_salle()
{
    carte[salle_actuelle_x][salle_actuelle_y].remplir();
}

void Zone::vider_salle(int x, int y)
{
    carte[x][y].vider();
}

void Zone::vider_salle()
{
    carte[salle_actuelle_x][salle_actuelle_y].vider();
}

void Zone::zone_depuis_modele(std::string nom)
{
    Modele mod(nom);
    mod.generer_zone();

    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            carte[i][j].set_config(mod.get_salle_generateur(i, j));
        }
    }
    salle_actuelle_x = mod.get_gen_posx_dep();
    salle_actuelle_y = mod.get_gen_posy_dep();
    zone_generee = true;
}

void Zone::zone_depuis_modele_aleatoire(int taille =0)
{
    //taille est entre 1 et 3 si elle est spécifiée. 1=normal, 2=grand, 3=immense.
    std::string nom_aleat;
    //Si la taille générale n'est pas spécifiée, on prend vraiment au hasard.
    if (taille == 0)
    {
        int nb_aleat = rand() % 11;

        switch(nb_aleat)
        {
            case 0:
                nom_aleat = "test";
                break;
            case 1:
                nom_aleat = "test_vide";
                break;
            case 2:
                nom_aleat = "test_croix";
                break;
            case 3:
                nom_aleat = "test_h";
                break;
            case 4:
                nom_aleat = "h_3";
                break;
            case 5:
                nom_aleat = "test_hub";
                break;
            case 6:
                nom_aleat = "test_huit";
                break;
            case 7:
                nom_aleat = "test_vertical";
                break;
            case 8:
                nom_aleat = "test_diagonale";
                break;
            case 9:
                nom_aleat = "test_bruits";
                break;
            default:
                nom_aleat = "defaut";
                break;
        }
    }
    else
    {
        //Sinon, on discrimine en fonction de la taille...
        //La configuration de cette procédure est à faire à la main à chaque nouveau Modele
        //dans les fichiers. Oui c'est embêtant, mais moins que les autres alternatives je suppose.
        if (taille == 1) //si la taille est sur 'normale'
        {
            int nb_aleat1 = rand() % 5;

            switch(nb_aleat1)
            {
                case 0:
                    nom_aleat = "test_croix";
                    break;
                case 1:
                    nom_aleat = "test_h";
                    break;
                case 2:
                    nom_aleat = "test_vertical";
                    break;
                case 3:
                    nom_aleat = "test_diagonale";
                    break;
                case 4:
                    nom_aleat = "test_bruits";
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else if (taille == 2) //si la taille est sur 'grande'
        {
            int nb_aleat2 = rand() % 3;
            switch(nb_aleat2)
            {
                case 0:
                    nom_aleat = "test_vide";
                    break;
                case 1:
                    nom_aleat = "test_hub";
                    break;
                case 2:
                    nom_aleat = "test_huit";
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else if (taille == 3) //si la taille est sur 'immense'
        {
            int nb_aleat3 = rand() % 2;
            switch(nb_aleat3)
            {
                case 0:
                    nom_aleat = "test";
                    break;
                case 1:
                    nom_aleat = "h_3";
                    break;
                default:
                    nom_aleat = "defaut";
                    break;
            }
        }
        else //si la taille spécifiée est incorrecte, on prend le modele par defaut.
        {
            nom_aleat = "defaut";
        }
    }

    zone_depuis_modele(nom_aleat);
}

void Zone::generer_salle(int i, int j)
{
    int diff_aleat = rand() % 3;
    //La difficulte moyenne est prise en compte 2 fois sur 3.
    int diff = 0;
    if (diff_aleat !=0)
    {
        diff = (niveau_zone*100 + difficulte_moyenne) / 2;
    }

    if (carte[i][j].get_config() != 0)
    {
        //On récupère les portes à poser en faisant attention aux Segmentation Fault...
        bool p_h, p_b, p_g, p_d;
        p_h = false;
        p_d = false;
        p_g = false;
        p_b = false;
        if (i>0)
        {
            if (carte[i-1][j].get_config() != 0){p_g = true;}
        }
        if (i<10)
        {
            if (carte[i+1][j].get_config() != 0){p_d = true;}
        }
        if (j>0)
        {
            if (carte[i][j-1].get_config() != 0){p_h = true;}
        }
        if (j<10)
        {
            if (carte[i][j+1].get_config() != 0){p_b = true;}
        }

        //la Salle est prête pour la génération...
        //on détermine si la Salle sera chargée (prédéterminée) ou générée (procéduralement)

        int type_generation = rand() % 2;
        if (type_generation == 0 && (carte[i][j].get_config() == 1 || carte[i][j].get_config() == 3))
        {
            //On génère la Salle...
            carte[i][j].salle_depuis_modele_aleatoire(p_h, p_b, p_g, p_d, carte[i][j].get_config(), diff);
        }
        else
        {
            //On charge une Salle aléatoirement...

            Fichier fichier;

            // il faut garder à jour ces nombres, représentant l'id le plus haut des Salles prégénérées !!!
            int id_aleat;
            switch(carte[i][j].get_config())
            {
            case 1:
                id_aleat = rand() % 5; //id le plus haut des Salles normales
                break;
            case 2:
                id_aleat = rand() % 1; //id le plus haut des Salles de Boss
                break;
            case 3:
                id_aleat = rand() % 1; //id le plus haut des Salles de Clef
                break;
            case 4:
                id_aleat = rand() % 3; //id le plus haut des Salles de Depart
                break;
            case 5:
                id_aleat = rand() % 1; //id le plus haut des Salles d' Objet
                break;
            default:
                id_aleat = rand() % 1; //le minimum des nb précédents... en cas de souci.
                break;
            }
            int conf = carte[i][j].get_config();
            fichier.charger(carte[i][j], id_aleat, conf);
            CaseSalle porte;
            porte.set_type('p');
            if (p_h){carte[i][j].set_case(0, 8, porte);}
            if (p_b){carte[i][j].set_case(8, 8, porte);}
            if (p_g){carte[i][j].set_case(4, 0, porte);}
            if (p_d){carte[i][j].set_case(4, 16, porte);}
        }
    }
}

void Zone::generer_toutes_les_salles()
{
    for (int i=0; i<11; ++i)
    {
        for (int j=0; j<11; ++j)
        {
            generer_salle(i, j);
        }
    }
}

void Zone::generer_et_remplir(int taille =0)
{
    zone_depuis_modele_aleatoire(taille);
    generer_toutes_les_salles();
}

void Zone::changer_de_salle(char direction)
{
    switch (direction)
    {
    case 'h':
        if (salle_actuelle_x>0)
        {
            if (carte[salle_actuelle_x-1][salle_actuelle_y].get_config() != 0)
            {
                salle_actuelle_x--;
            }
        }
        break;

    case 'b':
        if (salle_actuelle_x<10)
        {
            if (carte[salle_actuelle_x+1][salle_actuelle_y].get_config() != 0)
            {
                salle_actuelle_x++;
            }
        }
        break;

    case 'g':
        if (salle_actuelle_y>0)
        {
            if (carte[salle_actuelle_x][salle_actuelle_y-1].get_config() != 0)
            {
                salle_actuelle_y--;
            }
        }
        break;

    case 'd':
        if (salle_actuelle_y<10)
        {
            if (carte[salle_actuelle_x][salle_actuelle_y+1].get_config() != 0)
            {
                salle_actuelle_y++;
            }
        }
        break;
    default:
        break;
    }
}

