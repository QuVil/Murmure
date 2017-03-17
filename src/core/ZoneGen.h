#ifndef ZONEGEN_H_INCLUDED
#define ZONEGEN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>

class ZoneGen
{
    private:
        int carte[11][11];
        int carte_validation[11][11];

        std::string patterne; //patterne = le motif de base de la carte à sa création
        std::string methode;  //methode = méthode d'itération de création de carte

        bool pret_iteration;  //pret_iteration = l'instance est-elle prête à itérer ?
        bool valide; //valide = la carte est-elle jouable ?
        //patternes : croix, carre, h, vide, hub
        //methodes : voisins, bruit_neg, bruit_pos, aleatoire, epuration, extension
        int posx_dep; //coordonnées de la salle de départ
        int posy_dep;

        void valider_recursif(int i, int j);

    public:
        ZoneGen();

        ZoneGen(std::string pat, std::string met);

        int get_etat(int x, int y) const;

        bool is_valide() const;

        int get_posx_dep() const;

        int get_posy_dep() const;

        int get_nb_cases() const;

        bool is_nb_cases_assez(int nb_voulu) const;

        bool is_nb_cases_trop(int nb_voulu) const;

        void initialisation_gen(std::string pat, std::string met);

        void afficher_carte()const;

        void iterer(std::string meth = "");

        std::string get_patterne();

        void set_salle(int i, int j, int salle);

        void valider();

        void afficher_validation() const;

        void placer_boss();

        void vider_carte();
};

#endif // ZONEGEN_H_INCLUDED
