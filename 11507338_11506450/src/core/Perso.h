#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <string>
#include "VecteurM.h"
#include "Arme.h"
#include "Coord2D.h"
#include "Objet.h"
#include "Projectile.h"
#include "Clef.h"


#include <list>

class Perso
{
private:
    std::string nom; /**< Nom du personnage */
    ///TODO : implémenter Arme puis revenir un coup sur Perso.
    int id_arme1; /**< identifiant de l'Arme 1 du perso */
    int nv_arme1; /**< niveau de l'Arme 1 du perso */
    int id_arme2; /**< identifiant de l'Arme 1 du perso */
    int nv_arme2; /**< niveau de l'Arme 1 du perso */
    Arme arme1; /**< Arme 1 du perso */
    Arme arme2;

    VecteurM orientation; /**< Orientation du perso */
    VecteurM resultante; /**< Resultante du deplacement du perso */

    VecteurM deplacement; /**< Deplacement immédiat du perso */

    Coord2D position; /**< Position actuelle du personnage */
    Coord2D position_old; /**< Ancienne position du perso, celle précédant la position actuelle */

    float coefficient_vitesse; /**< Coefficient de vitesse affectant la vitesse des déplacements du perso */

    float taille; /**< Taille du personnage (1 étant la taille d'une case) */

    float pv_max; /**< \a pv_max est le nombre de coeurs maximum du Perso. */
    float pv_actuel; /**< \a pv_actuel est la "lose condition" si elle atteint 0, et doit être plus petit que pv_max. */

    bool vivant; /**< Etat du perso, true = vivant, false = mort */

    int pos_case_x;
    int pos_case_y;

    std::list <Objet*> objets_perso; /**< Liste des objets possédés par le Perso */

    bool possede_clef_boss; /**< true si on possede la clef, false sinon */

public:

    /** \brief Constructeur par défaut
     * Déclare les variables
     */
    Perso();


    /** \brief Constructeur avec paramètres
     * Construit l'instance en fonction du npm du personnage
     * \param n : nom du personnage
     */
    Perso(std::string n);

    /** \brief Accesseur pour le nom
     * \return le nom du personnage
     */
    std::string get_nom()const;

    /** \brief Mutateur du déplacement
     * \param v : deplacement à attribuer
     */
    void set_deplacement(const VecteurM &v);

    /** \brief Mutateur du déplacement
     * \param x : valeur horizontale du déplacement
     * \param y : valeur verticale du déplacement
     */
    void set_deplacement(const float &x, const float &y);

    /** \brief Mutateur de l'orientation
     * \param v : orientation à attribuer
     */
    void set_orientation(const VecteurM &v);

    /** \brief Mutateur de la position
     * \param x : position horizontale à attribuer
     * \param y : position verticale à attribuer
     */
    void set_position(const int &x, const int &y);

    /** \brief Rétablir position
     * Retourne à l'ancienne position (celle sauvegardée dans position_old)
     */
    void revenir_ancienne_position();


    Coord2D get_pos()const;

    float get_coefficient_vitesse()const;

    float get_orientation_degre()const;

    float get_pos_x()const;

    float get_pos_y()const;

    float get_pv_max()const;

    float get_pv_actuel()const;

    float get_taille()const;

    VecteurM get_deplacement()const;

    VecteurM get_orientation()const;

    void infliger_degats(float degats);

    void soigner(float soin);

    void set_nom(const std::string &n);

    /** \brief Mutateur du déplacement
     * \param v : deplacement à attribuer
     */
    void set_coefficient_vitesse(const float &c);

    /** \brief Mutateur du déplacement
     * \param v : deplacement à attribuer
     */
    void set_pv_max(const int &p);

    /** \brief Mutateur du déplacement
     * \param v : deplacement à attribuer
     */
    void set_taille(const float &t);

    /** \brief Mutateur du déplacement
     * \param v : deplacement à attribuer
     */
    void set_id_arme1(const int &i);

    /** \brief Mutateur du déplacement
     * \param v : deplacement à attribuer
     */
    void set_nv_arme1(const int &i);

    void set_id_arme2(const int &i);

    void set_nv_arme2(const int &i);

    /** \brief Mutateur du déplacement
     * \param v : deplacement à attribuer
     */
    void charger_perso(const std::string &n);

    Arme * get_arme1();

    Arme * get_arme2();

    Projectile* tirer_1();

    Projectile* tirer_2();

    void ramasser_clef(Clef* cle);

    bool get_cle_boss()const;

    //_____________________MODE TXT__________________________
    int get_pos_case_x() const;

    int get_pos_case_y() const;

    void deplacer_txt(char direction);

    void placer_txt(int x, int y);
    //_______________________________________________________
};

#endif // PERSO_H_INCLUDED
