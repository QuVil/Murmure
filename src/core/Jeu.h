#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Zone.h"
#include "Salle.h"
#include "Perso.h"
#include "VecteurM.h"
#include "GestionSalle.h"

#include <list>

/** \file Jeu.h
 *
 * \brief Module qui gère l'ensemble du déroulement du jeu
 */

class Jeu
{
private:
    Zone zone; /**< Zone du jeu */
    Perso perso; /**< Personnage du jeu */
    GestionSalle salle_actuelle; /**< Salle actuelle qui sera gérée et affichée à l'écran */

public:
    /** \brief Constructeur
     * Déclare les variables par défaut
     */
    Jeu();

    /** \brief Accesseur salle actuelle
     * \return pointeur sur la \a salle_actuelle
     */
    Salle* get_salle_actuelle();

    /** \brief Accesseur zone
     * \return \a zone
     */
    Zone get_zone();

    /** \brief Accesseur perso
     * \return \a perso
     */
    Perso get_perso();


    int grille_largeur();

    int grille_hauteur();

    /** \brief Change de perso
     * Procédure qui va changer le personnage jouable
     * \param[in] n : nom du nouveau personnage
     */
    void changer_perso(const std::string &n);

    /** \brief Deplace le personnage
     * Procédure qui va déplacer le personnage
     * \param[in] x : coordonnée horitontale du déplacement
     * \param[in] y : coordonnée verticale du déplacement
     */
    void deplacer_perso(const float &x, const float &y);

    /** \brief Mutateur position personnage
     * Défini la position du personnage
     * \param[in] x : coordonnée horizontale
     * \param[in] y : coordonnée verticale
     */
    void definir_position_perso(const float &x, const float &y);

    /** \brief Mutateur orientation personnage
     * Défini l'orientation du personnage
     * \param[in] v : orientation voulue
     */
    void definir_orientation_perso(const VecteurM &v);

    /** \brief Change de salle
     * Fonction qui va d'abord tester si le changement de salle peut être effectué, et si oui, change de salle
     * \param[in] c : direction de la nouvelle salle (h, b ,g ,d)
     * \return true si le changement est fait, false sinon
     */
    bool zone_changer_salle(const char &c);


    void deplacer_perso_txt(char direction);

    void placer_perso_txt(int x, int y);

    /** \brief Ajoute un projectile perso
     * Lors d'un tir, ajoute un nouveau projectile tiré par le personnage
     * \param[in] arme : numéro de l'arme du personnage
     */
    void ajouter_projectile_perso(const int &arme);

    /** \brief Actualise le jeu
     * Actualise l'ensemble des entités indépendantes (ennemis, projectiles)
     * \param[in] vitesse_base : coefficient calculé à partir du framerate pour avoir une vitesse de base constante
     * \param[in] taille_case : taille des cases
     */

    void avancer_jeu(const float &vitesse_base, const int &taille_case);

    /** \brief Accesseur des projectiles
     * \return pointeur sur la liste de projectiles
     */

    std::list <Projectile *> * retourne_projectiles();

    /** \brief Accesseur des ennemis
     * \return pointeur sur la liste des ennemis
     */

    std::list <Ennemi *> * retourne_ennemis();

    /** \brief Accesseur du personnage
     * \return pointeur sur le personnage
     */
    Perso * retourne_perso_ptr();

    /** \brief Actualise les ennemis
     * Actualise les positions et les déplacement des ennemis
     */
    void deplace_ennemis_auto();

    /** \brief Accesseur de la clef
     * \return pointeur sur la clef
     */
    Clef* retourne_clef();
};

#endif // JEU_H_INCLUDED
