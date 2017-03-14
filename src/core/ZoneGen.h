#ifndef ZONEGEN_H_INCLUDED
#define ZONEGEN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class ZoneGen
{
    private:
        int carte[11][11];

        string patterne; //patterne = le motif de base de la carte à sa création
        string methode;  //methode = méthode d'itération de création de carte

        bool pret_iteration;  //pret_iteration = l'instance est-elle prête à itérer ?
        bool valide; //valide = la carte est-elle jouable ?
        //patternes : croix, carre, h, vide, hub
        //methodes : voisins, bruit, aleatoire, epuration
        int posx_dep; //coordonnées de la salle de départ
        int posy_dep;


    public:
        ZoneGen();

        ZoneGen(string pat, string met);

        int get_etat(int x, int y) const;

        int get_posx_dep() const;

        int get_posy_dep() const;

        int nb_cases ()const;

        void initialisation_gen(string pat, string met);

        void afficher_carte()const;

        void iterer(string meth = "");

        string get_patterne();

        void set_salle(int i, int j, int salle);
};

#endif // ZONEGEN_H_INCLUDED
