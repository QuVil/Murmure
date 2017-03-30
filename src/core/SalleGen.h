#ifndef SALLEGEN_H_INCLUDED
#define SALLEGEN_H_INCLUDED

/**
 * \file SalleGen.h
 * \brief Header du module SalleGen.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 21 mars 2017
 *
 */
#include <string>

/**
 * \class SalleGen
 * \brief analogue de ZoneGen pour les objets type Salle.
 * Peremet de generer une Salle en plaçant des amas de trous ou
 * de rochers et des ennemis.
 */
class SalleGen
{
private:
    char grille[9][17]; /**< \a grille contient les futures CaseSalle de la Salle à générer. */
    //n=normal, p=porte, t=trou, m=mur, c=clef, r=buisson/rocher, e=ennemi (indéterminé)

    char grille_validation[9][17]; /**< grille pour la validation récursive de la Salle. */
    bool p_haut, p_bas, p_gauche, p_droite; /**< indique où se situe les portes de la Salle. */
    int config; /**< Le type de Salle à générer (clef, boss, départ...) */
    //0=vide, 1=normal, 2=boss, 3=clef, 4=depart, 5=objet

    int difficulte_approx; /**< contient la difficulté approximative actuelle de la Salle. */
    int difficulte_voulue; /**< indique la difficulté moyenne voulue à la fin de la génération. */

    bool valide; /**< La Salle est-elle valide (utilisable en jeu) ? */

    /**
    * \brief Procedure de plaçage d'amas récursive.
    * un amas est un groupement de trous où de rochers d'une taille définie.
    * ici, la procédure est appelée uniquement dans le cadre de placer_amas().
    * \param[in] i : coordonnee x du point de depart de la recursivite.
    * \param[in] j : coordonnee y du point de depart de la recursivite.
    * \param[in] type : le type d'amas à placer (5 pour les rochers, 2 pour les trous)
    * \param[in] dist_dep : sert à éviter que l'amas ne s'étende trop loin (s'incrémente à chaque itération).
    */
    void placer_amas_recursif(int i, int j, char type, int taille, int dist_dep);

    /**
    * \brief Procedure de validation recursive.
    * valider_recursif() est en fait uniquement appelée à travers valider()
    * qui lui envoie les coordonnées du point de départ de la récursivité.
    * La procédure est la même que celle de ZoneGen, adaptée au contexte de
    * la génération de Salle.
    * \param[in] i : coordonnee x du point de depart de la recursivite.
    * \param[in] j : coordonnee y du point de depart de la recursivite.
    */
    void valider_recursif(int i, int j);

public:
    /**
    * \brief Constructeur par défaut
    * Initialise les membres à leurs valeurs par défaut et la grille
    * comme une Salle où toutes les CaseSalle sont normales.
    */
    SalleGen();

    /**
    * \brief Constructeur à paramètres
    * Initialise les membres à l'aide des valeurs données.
    * \param[in] p_h : la valeur de départ pour \a p_haut.
    * \param[in] p_b : la valeur de départ pour \a p_bas.
    * \param[in] p_g : la valeur de départ pour \a p_gauche.
    * \param[in] p_d : la valeur de départ pour \a p_droite.
    * \param[in] conf : la configuration de la Salle.
    * \param[in] diff : la valeur de départ de \a difficulte_voulue.
    */
    SalleGen(bool p_h, bool p_b, bool p_g, bool p_d, int conf, int diff);

    /**
    * \brief Accesseur d'une 'CaseSalle' de la salle.
    * \param[in] i : coordonnees x de la case.
    * \param[in] j : coordonnees y de la case.
    * \return le caractère correspondant à la 'CaseSalle' i,j.
    */
    int get_type(int i, int j)const;

    /**
    * \brief Accesseur de \a valide.
    * \return l'état de validité de la \a grille du generateur.
    */
    bool is_valide()const;

    /**
    * \brief Mutateur de \a valide.
    * \param[in] v : nouvelle valeur de \a valide.
    */
    void set_valide(bool v);

    /**
    * \brief Accesseur de \a difficulte_voulue.
    * \return la valeur de la difficulté finale voulue pour la Salle.
    */
    int get_difficulte_voulue() const;

    /**
    * \brief Accesseur de \a difficulte_approx.
    * \return la valeur de la difficulté approximative actuelle de la Salle.
    */
    int get_difficulte_approx() const;

    /**
    * \brief Mutateur de \a difficulte_voulue.
    * \param[in] diff : nouvelle valeur de \a difficulte_voulue.
    */
    void set_difficulte_voulue(int diff);

    /**
    * \brief Initialise la \a grille du generateur.
    * place les murs et les portes (en fonction des attributs p_haut, ...)
    */
    void initialisation_gen();

    //Fonction de tests pour afficher la grille du générateur.
    void afficher_tests()const;

    /**
    * \brief Place la clef dans la Salle.
    * ne fonctionne que si la clef n'a pas déjà été placée ET si la config
    * le permet (i.e. si config = 3).
    */
    void placer_clef();

    /**
    * \brief Place un amas de type \a type et de taille \a taille.
    * appelle placer_amas_recursif() avec un point de départ choisi
    * aléatoirement, créant un amas de rochers ou de trous.
    * \param[in] type : le type d'amas désiré (2=trous, 5=rochers)
    * \param[in] taille : taille (unité arbitraire) de l'amas, entre 0 et 4.
    */
    void placer_amas(char type, int taille /* =2 */);

    /**
    * \brief procédure de validation de la Salle.
    * appelle valider_recursif() depuis un point de départ fixe.
    * vérifie que le Perso puisse atteindre toutes les portes de la Salle,
    * et récupérer la clef si elle est présente.
    */
    void valider();

    //Procédure de test : affiche la grille de validation.
    void afficher_validation()const;

    /**
    * \brief Place un Ennemi aléatoirement dans la Salle.
    * Vérifie au passage que l'Ennemi ne soit pas enfermé entre
    * des rochers.
    */
    void placer_ennemi();

    /**
    * \brief Calcule la distance entre deux cases.
    * Prend les coordonnees de deux cases. et renvoie la distance (Manhattan)
    * entre les cases.
    * \param[in] x_dep : coordonnee x du point de depart de la distance.
    * \param[in] y_dep : coordonnee y du point de depart de la distance.
    * \param[in] x_arr : coordonnee x du point d'arrivee de la distance.
    * \param[in] y_arr : coordonnee y du point d'arrivee de la distance.
    * \return : la distance Manhattan séparant les deux cases.
    */
    int calculer_distance(int x_dep, int y_dep, int x_arr, int y_arr)const;

    /**
    * \brief Calcule la distance entre une case et la porte la plus proche.
    * \param[in] x : la coordonnee x de la case en question.
    * \param[in] y : la coordonnee y de la case en question.
    * \return : la distance Manhattan séparant la case de sa porte la plus proche.
    */
    int calculer_distance_porte(int x, int y)const;

    /**
    * \brief Calcule la difficulte approximative de la Salle du generateur.
    * ne renvoie rien, mais modifie le membre \a difficulte_approx de l'instance.
    * l'algorithme n'est pas folichon, et la difficulté calculée ici reste une
    * simple approximation.
    */
    void calculer_difficulte();

    /**
    * \brief reinitialise la Salle du generateur.
    * remet les cases de l'intérieur de la Salle sur 'n'.
    */
    void vider_salle();

    /**
    * \brief place les portes dans la Salle du generateur.
    * en pratique, ne fait que modifier les membres \a porte_haut
    * et compagnie.
    * \param[in] h : la nouvelle valeur de \a porte_haut.
    * \param[in] b : la nouvelle valeur de \a porte_bas.
    * \param[in] g : la nouvelle valeur de \a porte_gauche.
    * \param[in] d : la nouvelle valeur de \a porte_droite.
    */
    void placer_portes(int h, int b, int g, int d);

    /**
    * \brief Mutateur de \a config.
    * \param[in] c : nouvelle valeur de \a config.
    */
    void set_config(int c);

};


#endif // SALLEGEN_H_INCLUDED
