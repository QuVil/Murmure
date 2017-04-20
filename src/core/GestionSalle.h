#ifndef GESTIONSALLE_H_INCLUDED
#define GESTIONSALLE_H_INCLUDED

#include "Ennemi.h"
#include "Projectile.h"
#include "Salle.h"
#include "Clef.h"

#include <list>

/** \file GestionSalle.h
 * \brief Module qui gere la salle actuelle
 */


class GestionSalle
{
private:

    std::list <Ennemi *> ennemis; /**< Liste contenant les ennemis dans la salle actuelle */
    std::list <Projectile *> projectiles; /**< Liste contenant les projectiles dans la salle actuelle */

    Clef* clef; /**< Pointeur sur la clef */

    int taille_case; /**< Taille des cases */

    Salle* salle_actuelle_jeu; /**< Pointeur sur la salle (ensemble de cases) */

    bool salle_actuelle_pointee; /**< vérifie juste que salle_actuelle_jeu ne pointe pas sur NULL*/
public:
    /** \brief Constructeur
     * Déclare les variables du module
     */

    GestionSalle();

    /** \brief Destructeur
     * Supprime et libere la mémoire lors de la derstruction du module
     */

    ~GestionSalle();

    /** \brief Ajout Projectile
     * Ajoute un projectile à la liste
     * \param[in] p : pointeur sur le projectile
     */

    void ajouter_projectile(Projectile * p);

    /** \brief Actualise projectiles
     * Actualise les positions des projectiles
     * \param[in] vitesse_frame : vitesse du framerate (qui sert de coefficient pour la vitesse des projectiles)
     */

    void mise_a_jour_projectiles(const float &vitesse_frame);

    /** \brief Accesseur des projectiles
     * \return pointeur sur \a projectiles
     */

    std::list <Projectile *> * get_projectiles();

    /** \brief Accesseur des ennemis
     * \return pointeur sur \a ennemis
     */

    std::list <Ennemi *> * get_ennemis();

    /** \brief Accesseur de la clef
     * \return pointeur de la \a clef
     */

    Clef* get_clef();

    /** \brief Test etat de la salle
     * Teste si la salle est terminée (tous les ennemis tués)
     * \return true si c'est terminé, false sinon
     */

    bool salle_terminee();

    /** \brief Initialisation salle
     * Initialise la salle lorsque l'on rentre dedans
     * \param[in] adresse_salle : adresse de la salle actuelle (ensemble de cases)
     */

    void initialise_salle_actuelle(Salle* adresse_salle);

    /**
     * \brief création des entités de la Salle
     * crée les ennemis objets et clefs dans la Salle.
     * \warning la procédure est appelée par Jeu. à ne pas utiliser telle quelle svp
     */
    void maj_changement_salle();

    /** \brief Accesseur de la Salle
     * \return pointeur sur la \a salle
     */

    Salle* get_salle_ptr();

    /** \brief Vide projectiles
     * Vide la salle de ses projectiles
     */

    void vider_projectiles();

    /** \brief Vide ennemis
     * Vide la salle de ses ennemis
     * \param[in] dans_destructeur :
     */

    void vider_ennemis(bool dans_destructeur /* =false */);

    /** \brief Actualise ennemis
     * Actualise les deplacement des ennemis
     * \param[in] pos_perso : posisiton actuelle du personnage
     */

    void deplacer_ennemis_auto(Coord2D pos_perso);

    /** \brief Vide clef
     * Vide la clef
     */

    void vider_clef();
};

#endif // GESTIONSALLE_H_INCLUDED
