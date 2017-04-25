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
 * \brief Module qui g�re l'ensemble du d�roulement du jeu
 */

class Jeu
{
private:
    Zone zone; /**< Zone du jeu */
    Perso perso; /**< Personnage du jeu */
    GestionSalle salle_actuelle; /**< Salle actuelle qui sera g�r�e et affich�e � l'�cran */

public:
    /** \brief Constructeur
     * D�clare les variables par d�faut
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
     * Proc�dure qui va changer le personnage jouable
     * \param[in] n : nom du nouveau personnage
     */
    void changer_perso(const std::string &n);

    /** \brief Deplace le personnage
     * Proc�dure qui va d�placer le personnage
     * \param[in] x : coordonn�e horitontale du d�placement
     * \param[in] y : coordonn�e verticale du d�placement
     */
    void deplacer_perso(const float &x, const float &y);

    /** \brief Mutateur position personnage
     * D�fini la position du personnage
     * \param[in] x : coordonn�e horizontale
     * \param[in] y : coordonn�e verticale
     */
    void definir_position_perso(const float &x, const float &y);

    /** \brief Mutateur orientation personnage
     * D�fini l'orientation du personnage
     * \param[in] v : orientation voulue
     */
    void definir_orientation_perso(const VecteurM &v);

    /** \brief Change de salle
     * Fonction qui va d'abord tester si le changement de salle peut �tre effectu�, et si oui, change de salle
     * \param[in] c : direction de la nouvelle salle (h, b ,g ,d)
     * \return true si le changement est fait, false sinon
     */
    bool zone_changer_salle(const char &c);


    void deplacer_perso_txt(char direction);

    void placer_perso_txt(int x, int y);

    /** \brief Ajoute un projectile perso
     * Lors d'un tir, ajoute un nouveau projectile tir� par le personnage
     * \param[in] arme : num�ro de l'arme du personnage
     */
    void ajouter_projectile_perso(const int &arme);

    /** \brief Actualise le jeu
     * Actualise l'ensemble des entit�s ind�pendantes (ennemis, projectiles)
     * \param[in] vitesse_base : coefficient calcul� � partir du framerate pour avoir une vitesse de base constante
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
     * Actualise les positions et les d�placement des ennemis
     */
    void deplace_ennemis_auto();

    /** \brief Accesseur de la clef
     * \return pointeur sur la clef
     */
    Clef* retourne_clef();
};

#endif // JEU_H_INCLUDED
