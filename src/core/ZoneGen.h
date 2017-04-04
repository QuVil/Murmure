#ifndef ZONEGEN_H_INCLUDED
#define ZONEGEN_H_INCLUDED

/**
 * \file ZoneGen.h
 * \brief Header de la class ZoneGen.
 * \author Quentin.V & Gary.S
 * \version 0.3
 * \date 18 mars 2017
 */

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
        //patternes : croix, carre, h, vide, hub, huit
        //methodes : voisins, bruit_neg, bruit_pos, aleatoire, epuration, extension

        bool pret_iteration;  /**< determine si la carte a ete initialisee.*/
        bool valide; /**< determine si la carte est jouable (un seul 'bloc' de salles).*/

        int posx_dep; /**< contient la coordonnee x de la salle de depart de la Zone.*/
        int posy_dep; /**< contient la coordonnee y de la salle de depart de la Zone.*/

        /**
        * \brief Procedure de validation recursive.
        * valider_recursif() est en fait uniquement appelée à travers valider()
        * qui lui envoie les coordonnées du point de départ de la récursivité.
        * valider_recursif() va ensuite 'peindre' récursivement le 'bloc' de salles
        * adjacentes autour du point de départ. Cela permet ensuite de vérifier si
        * la carte est valide en vérifiant qu'il n'y aie pas de salle non peinte.
        * valider_recursif() travaille uniquement sur \a carte_validation.
        * \param[in] i : coordonnee x du point de depart de la recursivite.
        * \param[in] j : coordonnee y du point de depart de la recursivite.
        */
        void valider_recursif(int i, int j);

        /**
        * \brief Calcule la distance entre deux salles.
        * Prend les coordonnees de deux points et renvoie la distance (Manhattan)
        * entre les points.
        * \param[in] x_dep : coordonnee x du point de depart de la distance.
        * \param[in] y_dep : coordonnee y du point de depart de la distance.
        * \param[in] x_arr : coordonnee x du point d'arrivee de la distance.
        * \param[in] y_arr : coordonnee y du point d'arrivee de la distance.
        * \return : la distance Manhattan séparant les deux salles.
        */
        int calculer_distance(int x_dep, int y_dep, int x_arr, int y_arr) const;

    public:
        /**
        * \brief Constructeur par défaut
        * Initialise toute la carte sur 0, met le \a patterne et la \a methode comme
        * " " et place \a valide et \a pret_iteration sur false.
        */
        ZoneGen();

        /**
        * \brief Accesseur d'une 'salle' de la grille
        * \param[in] x : coordonnees x de la salle.
        * \param[in] y : coordonnees y de la salle.
        * \return l'entier correspondant à la 'salle' x,y.
        */
        int get_etat(int x, int y) const;

        /**
        * \brief Accesseur de \a valide.
        * \return l'état de validité de la \a carte du generateur.
        */
        bool is_valide() const;

        /**
        * \brief Accesseur de \a posx_dep.
        * posx_dep est la coordonnee x de la case de depart de
        * la \a carte.
        * \return l'attribut \a posx_dep de l'instance.
        */
        int get_posx_dep() const;

        /**
        * \brief Accesseur de \a posy_dep.
        * posx_dep est la coordonnee y de la case de depart de
        * la \a carte.
        * \return l'attribut \a posy_dep de l'instance.
        */
        int get_posy_dep() const;

        /**
        * \brief 'Accesseur' du nombre de cases de \a carte.
        * \return le nombre de cases composant la \a carte.
        */
        int get_nb_cases() const;

        /**
        * \brief Vérifie que la nombre de cases est suffisant.
        * fait appel à get_nb_cases() et passe \a valide sur false
        * si la \a carte contient plus de nb_voulu cases.
        * \param[in] nb_voulu : le nbre maximum de cases voulues.
        */
        void teste_nb_cases_assez(int nb_voulu);

        /**
        * \brief Vérifie que la nombre de cases n'est pas trop grand.
        * fait appel à get_nb_cases() et passe \a valide sur false
        * si la \a carte contient moins de nb_voulu cases.
        * \param[in] nb_voulu : le nbre minimum de cases voulues.
        */
        void teste_nb_cases_trop(int nb_voulu);

        /**
        * \brief Initialise la \a carte avec le patterne voulu.
        * passe \a pret_iteration sur true après avoir vérifié que le
        * \a patterne et la \a methode sont correctes, et charge le
        * patterne depuis un Fichier avant de l'appliquer à la \a carte.
        * \param[in] pat : le nom du \a patterne à utiliser : carré, croix, etc..
        * \param[in] met : le nom de \a la methode à utiliser : voisins, aleatoire, etc..
        */
        void initialisation_gen(std::string pat, std::string met);

        /**
        * \brief Affiche la carte dans la console.
        * une procédure très certainement éphémère.
        */
        void afficher_carte()const;

        /**
        * \brief Itère sur le modèle avec la \a methode choisie.
        * Procédure d'itération sur le generateur, qui parcours la \a carte dans
        * le sens de la lecture, et applique des changements selon la \a methode
        * d'iteration.
        * \param[in] meth : \a methode à appliquer pour l'iteration.
        */
        void iterer(std::string meth = "");

        /**
        * \brief Accesseur du \a patterne de l'instance.
        * \return le \a patterne de ZoneGen (string).
        */
        std::string get_patterne();

        /**
        * \brief Mutateur d'une 'salle' de la \a carte (int).
        * \param[in] i : coordonnee x de la 'salle'.
        * \param[in] j : coordonnee y de la 'salle'.
        * \param[in] salle : l'int qui remplacera le carte[i][j] actuel.
        */
        void set_etat(int i, int j, int etat);

        /**
        * \brief Procédure de validation de la \a carte.
        * Recopie \a carte dans \a carte_validation, puis cherche
        * une salle pour commencer la récursivité et appelle valider_recursif()
        * sur cette salle.
        * Ensuite, vérifie que toutes les salles sont peintes et détermine l'état
        * de validité de la \a carte.
        */
        void valider();

        /**
        * \brief Affiche \a carte_validation dans la console (txt)
        * Ceci est une procédure de test -- elle est à détruire en release.
        */
        void afficher_validation() const;

        /**
        * \brief place une salle de boss dans la \a carte.
        * La recherche de boss se fait ainsi : une variable aleatoire
        * decide en premier lieu si la recherche se fait dans le sens de
        * lecture ou dans le sens inverse (pour plus de variation).
        * Ensuite, on cherche une salle n'ayant qu'une seule salle adjacente.
        * Si aucune salle n'est valable, l'attribut \a valide est passé sur
        * false (ce qui implique que la carte est invalidée et repasse à la génération).
        */
        void placer_boss();

        /**
        * \brief vide la \a carte.
        * Met toute la \a carte sur 0, et passe \a pret_iteration sur false.
        */
        void vider_carte();

        /**
        * \brief Place la salle de départ.
        * Fonctionne sur le même principe que placer_boss().
        * Cherche une salle avec 4 salles adjacentes. Mais s'il n'en existe pas,
        * place le départ aléatoirement au lieu d'invalider la carte.
        */
        void placer_depart();

        /**
        * \brief Place la clef du boss.
        * La clef du boss est toujours le plus loin possible du départ (ce qui
        * implique qu'elle sera parfois à côté du boss). La procédure utilise donc
        * logiquement calculer_distance().
        */
        void placer_clef();

        /**
        * \brief Place une salle d'objet.
        * L'objet est simplement placé sur une salle aléatoirement, pourvu qu'elle
        * ne soit pas déjà utilisée à d'autres fins.
        */
        void placer_objet();
};

#endif // ZONEGEN_H_INCLUDED
