#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

#include <string>
#include "VecteurM.h"
#include "Coord2D.h"

/** \file Ennemi.h
 * \brief Header du module Ennemi
 */


class Ennemi
{
private:
    std::string nom; /**< nom de l'entité ennemi */
    std::string type_ia; /**< type de l'intelligence artificielle qui dirigera l'ennemi. IA signifiant Intelligence Artificielle */

    float orientation; /**< orientation de l'entité (en degré) */

    Coord2D position; /**< position actuelle de l'entité */
    Coord2D position_old; /**< derniere position de l'entité avant la position actuelle */

    VecteurM deplacement; /**< valeur du deplacement actuel de l'entité (selon un vecteur qui a pour origine la derniere position de l'entité) */

    float coefficient_vitesse; /**< veleur qui va definir la vitesse de l'ennemi */

    float pv_actuel; /**< nombre de points de vie actuel */
    float pv_max; /**< nombre de points de vie maximum */

    float taille; /**< taille de l'ennemi (1 coorespondant à la taille d'une case) */

    bool vivant; /**< etat de l'ennemi (true = vivant, false = mort) */

    int case_x_apparition; /**< coordonnée x de la case d'apparition */
    int case_y_apparition; /**< coordonnée y de la case d'apparition */

public:

    /** \brief Constructeur par défaut
     * Attribue les valeurs par défaut au programme
     */

    Ennemi();

    /** \brief Constructeur avec parametres
     * Construit l'entité avec une case d'apparition et un type d'IA
     * \param[in] ia : type d'IA
     * \param[in] case_x_app : coordonnée x de la case d'apparition
     * \param[in] case_y_app : coordonnée y de la case d'apparition
     */

    Ennemi(std::string ia, int case_x_app, int case_y_app);

    /** \brief infliger _degats
     * Procédure qui retire le nombre de points de vie si l'ennemi subit un coup
     * \param[in] degat : nombre de degat subit
     */

    void infliger_degats(float degats);

    /** \brief soigner
     * Procédure qui va permettre à l'ennemi de récupérer des points de vie
     * \param[in] soin : quantité de points de vie récupéré
     */

    void soigner(float soin);

    /** \brief Mutateur du deplacement
     * \param[in] v : valeur du deplacement
     */

    void set_deplacement(const VecteurM &v);

    /** \brief Mutateur du deplacement
     * \param[in] x : valeur du deplacement horizontal
     * \param[in] y : valeur du deplacement vertical
     */

    void set_deplacement(const float &x, const float &y);

    /** \brief Mutateur du deplacement
     * Deplace l'ennemi en direction du personnage
     * \param[in] position_perso : position du personnage sur lequel il faut diriger l'ennemi
     */

    void set_deplacement(const Coord2D &position_perso);

    /** \brief Mutateur de l'orientation
     * Oriente l'ennemi en fonction
     * \param[in] v : orientation souhaitée
     */

    void set_orientation(const VecteurM &v);

    /** \brief Mutateur de la position
     * \param[in] x : coordonnée horizontale de la position
     * \param[in] y : coordonnée verticale de la position
     */

    void set_position(const int &x, const int &y);

    /** \brief Revient à l'ancienne position
     * Permet de définir l'ennemi à l'ancienne position à laquelle il était grâce à \a position_old
     */

    void revenir_ancienne_position();

    /** \brief Accesseur de la position
     * Retourne la position de l'ennemi
     * \return position actuelle
     */

    Coord2D get_position()const;

    /** \brief Accesseur du deplacement
     * Retourne le deplacement de l'ennemi
     * \return deplacement actuel
     */
    VecteurM get_deplacement() const;

    /** \brief Accesseur du coefficient de vitesse
     * Retourne le coefficient de vitesse
     * \return coefficient de vitesse
     */
    float get_coefficient_vitesse()const;

    /** \brief Accesseur de l'orientation de l'ennemi
     * Retourne l'orientation de l'ennemi
     * \return orientation de l'ennemi
     */
    float get_orientation_degre()const;

    /** \brief Accesseur de la position horizontale de l'ennemi
     * Retourne la position horizontale de l'ennemi
     * \return position horizontale de l'ennemi
     */
    float get_pos_x()const;

    /** \brief Accesseur de la position verticale de l'ennemi
     * Retourne la position verticale de l'ennemi
     * \return position verticale de l'ennemi
     */
    float get_pos_y()const;

    /** \brief Accesseur du nombre de points de vie actuel
     * Retourne le nombre de points de vie actuel
     * \return nombre de points de vie actuel
     */
    float get_pv_actuel()const;

    /** \brief Accesseur de la taille
     * Retourne la taille
     * \return taille
     */
    float get_taille()const;

    /** \brief Accesseur de l'orientation
     * Retourne l'orientation
     * \return orientation
     */
    float get_orientation() const;

    /** \brief Angle mouvement chasseur
     * Retourne l'angle entre le personnage à chasser et l'ennemi
     * \return angle entre personnage et ennemi
     */
    float get_angle_perso(const Coord2D &pos_perso)const;

    /** \brief Mutateur coefficient de vitesse
     * \param[in] c : coefficient de vitesse
     */
    void set_coefficient_vitesse(const float &c);

    /** \brief Accesseur de la position horizontale initiale de l'ennemi
     * Retourne la position horizontale initiale de l'ennemi
     * \return position horizontale initiale de l'ennemi
     */
    int get_case_x_apparition()const;

    /** \brief Accesseur de la position verticale initiale de l'ennemi
     * Retourne la position verticale initiale de l'ennemi
     * \return position verticale initiale de l'ennemi
     */
    int get_case_y_apparition()const;

    /** \brief Accesseur de l'etat de l'ennemi
     * Retourne l'etat de l'ennemi
     * \return \a vivant
     */
    bool is_vivant();

    /** \brief Tue ennemi
     * Met l'état de l'ennemi sur mort
     */

    void set_mort();

    /** \brief Gere le deplacement
     * Deplace l'ennemi en fonction de son type d'IA
     * \param[in] position_perso : position du personnage à chasser si l'IA en tient compte
     */

    void trouver_chemin(const Coord2D &position_perso);

    /** \brief Deplace l'ennemi
     * Procedure qui va appeler les fonctions de deplacement de l'ennemi
     * \param pos_perso : position du personnage
     */

    void deplacer_auto(Coord2D pos_perso);
};

#endif // ENNEMI_H_INCLUDED
