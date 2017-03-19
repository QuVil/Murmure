#ifndef ZONEGEN_H_INCLUDED
#define ZONEGEN_H_INCLUDED

/**
 * \file ZoneGen.h
 * \brief Header de la class ZoneGen.
 * \author Quentin.V & Gary.S
 * \version 0.3
 * \date 18 mars 2017
 */
 ///TODO : Finir la doc de ZoneGen...

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

/**
 * \class ZoneGen
 * \brief class principale de generation de carte pour Zone.
 * ZoneGen est une classe de transition entre Modele et Zone,
 * instanciant un generateur contenant une carte semblable aux
 * Zones. Le generateur applique un patterne de base sur sa carte,
 * puis 'itere' dessus avec differentes methodes.
 * une procedure permet ensuite de valider() la carte, en verifiant
 * que toutes les salles sont connectees, puis place le boss et l'objet
 * de la Zone.
 */
class ZoneGen
{
    private:
        int carte[11][11]; /**< \a carte est l'equivalent du meme attribut de Zone, mais en int (par optimisation). */
        int carte_validation[11][11]; /**< \a carte_validation sert uniquement pour valider() la \a carte.*/

        std::string patterne; /**< \a patterne est le motif de base applique au debut de la creation de carte.*/
        std::string methode;  /**< \a methode contient la methode d'iteration actuelle du generateur.*/
        //patternes : croix, carre, h, vide, hub
        //methodes : voisins, bruit_neg, bruit_pos, aleatoire, epuration, extension

        bool pret_iteration;  /**< determine si la carte a ete initialisee.*/
        bool valide; /**< determine si la carte est jouable (un seul 'bloc' de salles).*/

        int posx_dep; /**< contient la coordonnee x de la salle de depart de la Zone.*/
        int posy_dep; /**< contient la coordonnee y de la salle de depart de la Zone.*/

        void valider_recursif(int i, int j);

        int calculer_distance(int x_dep, int y_dep, int x_arr, int y_arr) const;

    public:
        ZoneGen();

        int get_etat(int x, int y) const;

        bool is_valide() const;

        int get_posx_dep() const;

        int get_posy_dep() const;

        int get_nb_cases() const;

        void teste_nb_cases_assez(int nb_voulu);

        void teste_nb_cases_trop(int nb_voulu);

        void initialisation_gen(std::string pat, std::string met);

        void afficher_carte()const;

        void iterer(std::string meth = "");

        std::string get_patterne();

        void set_salle(int i, int j, int salle);

        void valider();

        void afficher_validation() const;

        void placer_boss();

        void vider_carte();

        void placer_depart();

        void placer_clef();

        void placer_objet();
};

#endif // ZONEGEN_H_INCLUDED
