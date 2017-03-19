#ifndef MODELE_H_INCLUDED
#define MODELE_H_INCLUDED

/**
 * \file Modele.h
 * \brief Header du module Modele.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 17 mars 2017
 *
 */

#include "ZoneGen.h"
#include <string>

/**
 * \class Modele
 * \brief class gerant une ZoneGen pour generer une Zone facilement.
 * Grace à Modele, il est possible de créer et générer une Zone en
 * seulement quelques lignes.
 * Une instance de Modele contient un generateur de type ZoneGen et un
 * tableau d'entiers correspondant aux operations necessaire à la generation
 * de la Zone voulue.
 */
class Modele
{
private:
    ZoneGen generateur; /**< \a generateur permet la génération de la Zone.*/
    int tableau_modele[23];/**< \a tableau_modele contient la suite d'instuctions pour le modele.*/
    //Les deux premiers entiers sont le nb minimum et max de cases desirees
    //Puis le patterne de base:
    //1=croix, 2=carre, 3=vide, 4=h, 5=hub

    // Ensuite, les iterations à faire :
    //1=voisins, 2=bruit_neg, 3=bruit_pos, 4=aleatoire, 5=epuration, 6=extension

public:

    /**
     * \brief Constructeur basique de Modele.
     * En pratique, ce constructeur ne sera JAMAIS utilisé.
     */
    Modele();

    /**
     * \brief Constructeur de Modele avec nom de fichier en paramètre.
     * Le constructeur charge directement depuis un fichier le \a tableau_modele,
     * ce qui permet d'utiliser directement generer_zone().
     * \param[in] nom : nom du Fichier contenant le \a tableau_modele du Modele.
     */
    Modele(std::string nom);

    /**
     * \brief Mutateur d'une case tableau_modele.
     * \param[in] x : nouveau int qui sera place dans la case.
     * \param[in] i : numero de la case de tableau_modele.
     */
    void set_tableau_modele_i (int x, int i);

    /**
     * \brief procédure principale du module.
     * génère le membre \a generateur à l'aide de \a tableau_modele.
     * La ZoneGen pourra alors être transférée comme Zone.
     */
    void generer_zone();

    /**
     * \brief Accesseur de la config d'une 'salle' de \a generateur.
     * \param[in] x : coordonnee x de la 'salle' dont on veut la config.
     * \param[in] y : coordonnee y de la 'salle' dont on veut la config.
     * \return la config de la 'salle' désirée.
     */
    int get_salle_generateur(int x, int y)const;

    ///TODO: se débarasser de afficher_tests() qui n'est qu'une procédure temporaire.
    void afficher_tests()const;
};

#endif // MODELE_H_INCLUDED
