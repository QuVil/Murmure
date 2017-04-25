#ifndef CASESFML_H_INCLUDED
#define CASESFML_H_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

#include "CaseSalle.h"

/** \file CaseSalleSFML.h
 *
 * \brief Module qui va gérer les cases des salles à afficher à l'écran
 *
 */

class CaseSFML
{
private:
    sf::VertexArray casesfml; /**< Tableau de Vertex qui comprendra les informations necessaires pour la case */

    char type_case; /**< Le type de la case, duquel dépendra sa texture ainsi que sa boite de collisions */
    int taille; /**< La taille de la texture de la case (qui doit être carrée : taille*taille) comme celle-ci peut varier */
public:
    /** \brief Constructeur par défaut
     *
     *
     */
    CaseSFML();

    /** \brief Initialisation
     * Initialise la position de la case et la taille qu'elle sera ammenée à prendre
     * \param posX int : position horizontale du point en haut à gauche de la case
     * \param posY int : position verticale du point en haut à gauche de la case
     * \param largeur int : largeur de la case
     * \param hauteur int : hauteur de la case
     */
    void init(int posX,int posY, int largeur, int hauteur);

    /** \brief Mise à jour de la texture
     * Change le paramètre de la taille de la texture, au cas où celle ci soit ammenée à avoir une texture de taille différente de la précédente
     * \param t const int& : nouvelle taille de la texture
     */
    void mettre_a_jour_taille_texture(const int &t);

    /** \brief Mise à jour du type de la case
     * Change le type de la case
     * \param c const char& : nouveau type
     *
     */
    void mettre_a_jour_type_case(const char &c);

    /** \brief Accesseur de la case
     * Retourne la case qui comprendra toutes les données initialisées précédemment
     * \return sf::VertexArray : la case
     *
     */
    sf::VertexArray get_casesfml()const;

    /** \brief Accesseur de la taille de la dernière texture utilisée pour la case
     * Retourne la taille de la derniere texture utilisée de la case, pour ainsi voir si celle-ci doit être changée ou non
     * \return int : la taille de la texture
     *
     */
    int get_taille_texture()const;

    /** \brief Retourne le type de la case
     *
     * \return char : le type de la case
     *
     */
    char get_type_case()const;

    void check_collision();
};

#endif // CASESFML_H_INCLUDED
