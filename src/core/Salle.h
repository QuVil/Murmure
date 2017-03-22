#ifndef SALLE_H_INCLUDED
#define SALLE_H_INCLUDED

/**
 * \file Salle.h
 * \brief Header du module Salle.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 11 mars 2017
 *
 */

#include "CaseSalle.h"
#include "SalleGen.h"

const int nb_cases_largeur = 17;
const int nb_cases_hauteur = 9;

/**
 * \class Salle
 * \brief class des salles de jeu où évolue le joueur.
 * Salle dépend de CaseSalle et se compose d'une grille de
 * CaseSalle, dont les bords sont des murs.
 */
class Salle
{
private:
    //cree un tableau de CaseSalle
    CaseSalle grille[nb_cases_hauteur][nb_cases_largeur]; /**< \a grille contient les CaseSalle composant la Salle. */

    int config; /**< \a config est la disposition de la Salle, correspondant à un int. */
    //0=vide, 1=normal, 2=boss, 3=clef, 4=depart, 5=objet

    int difficulte; /**< \a difficulte est la difficulté de la Salle, calculée ou donnée au préalable. */
    bool deja_visitee; /**< determine si la Salle a deja ete visitee par le Perso. */
    ///TODO : vérifier l'implémentation de difficulte et la ranger dans les fichiers contenant les Salle (GARY ?)

public:

    /**
     * \brief Consctructeur
     * Le Constructeur basique de Salle donnant la \a config 1 à l'instance
     * créée, et créant son fichier modèle.
     */
    Salle();

    /**
     * \brief Consctructeur avec \a config
     * Le Constructeur avec paramètre, donnant à l'instance la \a config donnée.
     * \param[in] conf : la \a config donnée à la nouvelle instance.
     * \todo : potentiellement ajouter le paramètre fichier pour copie (GARY ?)
     */
    Salle(int conf);

    /**
     * \brief Accesseur de case dans la grille.
     * \param[in] i : coordonnée de la ligne de la case désirée.
     * \param[in] j : coordonnée de la colonne de la case désirée.
     * \return renvoie la CaseSalle i,j de la grille de l'instance.
     * \warning l'accesseur renvoyant une copie, attention à ne pas vouloir utiliser un membre.
     */
    CaseSalle get_case(int i,int j);

    /**
     * \brief Mutateur de case dans la grille.
     * \param[in] i : coordonnée de la ligne de la case à changer.
     * \param[in] j : coordonnée de la colonne de la case à changer.
     * \param[in] c : la CaseSalle pour remplacer la case i,j.
     */
    void set_case(int i, int j, CaseSalle c);

    /**
     * \brief Accesseur de la \a config.
     * \return la \a config (un int) de la Salle.
     */
    int get_config();

    /**
     * \brief Mutateur de la \a config.
     * \param[in] c : nouvelle config.
     */
    void set_config(int c);

    /**
     * \brief Accesseur de \a deja_visitee.
     * \return l'attribut \a deja_visitee.
     */
    bool is_deja_visitee()const;

    /**
     * \brief Mutateur de \a deja_visitee.
     * \param[in] visite : la nouvelle valeur de \a deja_visitee.
     */
    void set_deja_visitee(bool visite);

    /**
     * \brief Procédure de remplissage de Salle.
     * Techniquement, remplir() est un mutateur de \a config
     * avec paramètre fixé.
     */
    void remplir();


    /**
     * \brief Procédure de vidage de Salle.
     * Techniquement, vider() est un mutateur de \a config
     * avec paramètre fixé.
     */
    void vider();

    /**
     * \brief Surcharge d'affectation de Salle.
     * Surcharge de l'operateur = pour affecter des Salle entre elles.
     * \param[in] salle2 : La Salle dont les membres -ici les CaseSalle de la grille et la \a config- doivent être copiés.
     */
    Salle& operator = (Salle salle2);

    /**
     * \brief Affichage de Salle.
     * Procedure d'affichage de la Salle en mode txt.
     */
    void afficher();

    /**
     * \brief Accesseur du nb de cases en largeur.
     * \return \a nb_cases_largeur de la Salle.
     */
    int get_nb_cases_largeur();

    /**
     * \brief Accesseur du nb de cases en hauteur.
     * \return \a nb_cases_hauteur de la Salle.
     */
    int get_nb_cases_hauteur();

    std::string get_config_string()const;

    /**
     * \brief Genere une Salle proceduralement.
     * Permet, en une seule ligne, de generer la Salle selon un ModeleSalle determine.
     * prend le ModeleSalle 'nom', le charge, genere la SalleGen puis la transforme
     * en Salle.
     * \param[in] nom : le nom du ModeleSalle à utiliser.
     */
    void salle_depuis_modele(std::string nom, bool p_h, bool p_b, bool p_g, bool p_d, int conf);

    /**
     * \brief Genere une Salle proceduralement selon un ModeleSalle pseudo-aleatoire.
     * Permet, en une seule ligne, de generer la Salle selon un ModeleSalle determine.
     * prend le ModeleSalle 'nom', le charge, genere la SalleGen puis la transforme
     * en Salle.
     * \param[in] diff : la difficulte approximatie voulue.
     */
    void salle_depuis_modele_aleatoire(bool p_h, bool p_b, bool p_g, bool p_d, int conf, int diff = 0);

};

#endif // SALLE_H_INCLUDED
