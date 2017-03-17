#ifndef MODELE_H_INCLUDED
#define MODELE_H_INCLUDED

/**
 * \file Modele.h
 * \brief Header du module Modele.
 * \author Quentin.V
 * \version 0.1
 * \date 17 mars 2017
 *
 */

#include "ZoneGen.h"
#include <string>

/**
 * \class Modele
 * \brief class gerant une ZoneGen pour generer une Zone facilement.
 * Grace � Modele, il est possible de cr�er et g�n�rer une Zone en
 * seulement quelques lignes.
 * Une instance de Modele contient un generateur de type ZoneGen et un
 * tableau d'entiers correspondant aux operations necessaire � la generation
 * de la Zone voulue.
 */
class Modele
{
private:
    ZoneGen generateur; /**< \a generateur permet la g�n�ration de la Zone.*/
    int tableau_modele[23];/**< \a tableau_modele contient la suite d'instuctions pour le modele.*/
    //Les deux premiers entiers sont le nb minimum et max de cases desirees
    //Puis le patterne de base:
    //1=croix, 2=carre, 3=vide, 4=h, 5=hub

    // Ensuite, les iterations � faire :
    //1=voisins, 2=bruit_neg, 3=bruit_pos, 4=aleatoire, 5=epuration, 6=extension

public:

    /**
     * \brief Constructeur basique de Modele.
     * En pratique, ce constructeur ne sera JAMAIS utilis�.
     */
    Modele();

    /**
     * \brief Constructeur de Modele avec nom de fichier en param�tre.
     * Le constructeur charge directement depuis un fichier le \a tableau_modele,
     * ce qui permet d'utiliser directement generer_zone().
     * \param[in] nom : nom du Fichier contenant le \a tableau_modele du Modele.
     */
    Modele(std::string nom);

    /**
     * \brief proc�dure principale du module.
     * g�n�re le membre \a generateur � l'aide de \a tableau_modele.
     * La ZoneGen pourra alors �tre transf�r�e comme Zone.
     */
    void generer_zone();

    ///TODO: se d�barasser de afficher_tests() qui n'est qu'une proc�dure temporaire.
    void afficher_tests()const;
};

#endif // MODELE_H_INCLUDED
