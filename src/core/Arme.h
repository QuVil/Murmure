#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED

#include "Projectile.h"
#include "VecteurM.h"
#include "Coord2D.h"

/**
 * \file Arme.h
 * \brief Header du module Arme.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 15 avril 2017
 *
 */



class Arme
{
private:
    int id_arme; /**< identifiant de l'arme */
    int nv_arme; /**< niveau de l'arme */
    int id_projectiles; /**< identifiant de ses projectiles */
    int degats_projectiles; /**< degat de ses projectiles */
    int type; /**< type de l'arme */
    float vitesse; /**< vitesse des projectiles de l'arme */
    float taille_projectile; /**< taille de ses projectiles */
    float cadence_tir; /**< cadence de tir de l'arme (nombre de coups tirés par secondes) */

    int munitions_max; /**< nombre de munition maximum de l'arme */
    int munitions_restantes; /**< nombre de munition actuel de l'arme */

public:
    /** \brief Constructeur
     * Le constructeur par defaut qui va uniquement declarer les variables
     */
    Arme();

    /** \brief Charger
     * Appelle la fonction Fichier::charger( \a Arme) pour definir les valeurs des variables de la classe
     * \param[in] id : l'identifiant de l'arme à charger
     * \param[in] nv : le niveau de l'arme à charger
     */
    void charger(const int &id, const int &nv);

    /** \brief Mutateur de l'identifiant
     *
     * \param[in] i : identifiant à copier
     */
    void set_id_arme(const int &i);

    /** \brief Mutateur du niveau de l'arme
     *
     * \param[in] i : niveau de l'arme à copier
     */
    void set_nv_arme(const int &i);

    /** \brief Mutateur de l'identifiant des projectiles
     *
     * \param[in] i : identifiant des projectiles à copier
     */
    void set_id_projectiles(const int &i);

    /** \brief Mutateur des degats des projectiles
     *
     * \param[in] i : degats des projectiles à copier
     */
    void set_degats_projectiles(const int &i);

    /** \brief Mutateur du nombre de munition maximum de l'arme
     *
     * \param[in] i : nombre de munition maximum de l'arme à copier
     */
    void set_munitions_max(const int &i);

    /** \brief Mutateur du type
     *
     * \param[in] i : type à copier
     */
    void set_type(const int &i);

    /** \brief Mutateur de la vitesse
     *
     * \param[in] v : vitesse à copier
     */
    void set_vitesse(const float &v);

    /** \brief Mutateur de la taille des projectiles
     *
     * \param[in] t : taille des projectiles à copier
     */
    void set_taille_projectile(const float &t);

    /** \brief Mutateur de la cadence de tir
     *
     * \param[in] c : cadence de tir à copier
     */
    void set_cadence_tir(const float &c);

    /** \brief Fonction tirer
     * Permet de créer des entités de type \a Projectile pour pouvoir tirer
     * \param[in] orientation : orientation de l'entité qui tire au moment du tir (pour avoir sa direction)
     * \param[in] position : position de l'entité qui tir au moment du tir (pour avoir le point de départ du tir)
     * \return un pointeur de type \a Projectile qui sera l'entité issue de l'arme à présent indépendante de l'arme
     *
     */
    Projectile* tirer(const VecteurM &orientation, const Coord2D &position);

    /** \brief Accesseur de la cadence de tir
     * \return \a cadence
     */
    float get_cadence_tir()const;

    /** \brief Accesseur de la cadence de tir
     * \return \a cadence
     */
    int get_id_proj()const;

};

#endif // ARME_H_INCLUDED
