#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

/**
 * \file Zone.h
 * \brief Header de la class Zone.
 * \author Quentin.V & Gary.S
 * \version 0.2
 * \date 18 mars 2017
 */

#include "Salle.h"
#include "ZoneGen.h"
#include <string>

/**
 * \class Zone
 * \brief Gère l'instance où crapahute Perso.
 * Une seule Zone sera en général générée à chaque instant.
 * Elle contient des informations sur toutes les Salle de l'instance
 * (rangées dans un tableau 11*11) et instancie toutes les Salle où
 * Perso évoluera.
 */
class Zone
{
private:
    Salle carte[11][11]; /**< \a carte contient toutes les Salle de la Zone dans un tableau. */
    int niveau_zone; /**< \a niveau_zone agit comme indicateur de difficulté et comme nom de Zone. */
    int salle_actuelle_x, salle_actuelle_y; /**< les coordonnées de la Salle où se trouve le Perso. */

public:

    /**
     * \brief Consctructeur
     * Le Constructeur basique de Zone, mettant la position
     * actuelle du Perso en 5,5 et vidant toutes les Salle.
     */
    Zone();

    /**
     * \brief Consctructeur avec salle actuelle et niveau.
     * \param[in] posx : \a salle_actuelle_x pour la nouvelle instance.
     * \param[in] posy : \a salle_actuelle_y pour la nouvelle instance.
     * \param[in] niv : le niveau de la nouvelle Zone.
     */
    Zone(int posx, int posy, int niv);

    /**
     * \brief Consctructeur depuis un generateur ZoneGen.
     * \param[in] z : l'instance de ZoneGen qui sera traduite en Zone.
     * Ne genere pas les instances de Salle, mais prend la \a config necessaire.
     */
    Zone(const ZoneGen &z);

    /**
     * \brief Accesseur de Salle dans la \a carte.
     * \param[in] x : coordonnees x de la Salle voulue dans la \a carte.
     * \param[in] y : coordonnees y de la Salle voulue dans la \a carte.
     * \return la Salle (x,y) de la \a carte.
     */
    Salle get_salle(int x, int y);

    /**
     * \brief Accesseur de Salle actuelle.
     * \return la Salle actuelle.
     */
    Salle get_salle()const;

    /**
     * \brief Mutateur de Salle de la \a carte.
     * \param[in] x : les coordonnees x de la Salle à changer.
     * \param[in] y : les coordonnees y de la Salle à changer.
     * \param[in] nouvelle_salle : la Salle qui remplacera l'ancienne.
     */
    void set_salle(int x, int y, const Salle &nouvelle_salle);

    /**
     * \brief Accesseur de \a salle_actuelle_x
     * \return \a salle_actuelle_x de l'instance.
     */
    int get_salle_actuelle_x ()const;

    /**
     * \brief Accesseur de \a salle_actuelle_y
     * \return \a salle_actuelle_y de l'instance.
     */
    int get_salle_actuelle_y ()const;

    /**
     * \brief Affiche la Zone (txt).
     * Affiche la Zone dans la console en version txt.
     */
    void afficher_zone();

    /**
     * \brief Appelle la procedure remplir() d'une Salle.
     * \param[in] x : coordonnees x de la Salle à vider.
     * \param[in] y : coordonnees y de la Salle à vider.
     */
    void remplir_salle(int x, int y);

    /**
     * \brief Appelle la procedure vider() de la Salle actuelle
     * Sûrement temporaire et à supprimer plus tard.
     */
    void remplir_salle();

    /**
     * \brief Appelle la procedure vider() d'une Salle.
     * \param[in] x : coordonnees x de la Salle à vider.
     * \param[in] y : coordonnees y de la Salle à vider.
     */
    void vider_salle(int x, int y);

    //Vide la salle actuelle (je vois pas pourquoi on s'en servirait mais eh...
    void vider_salle();

    /**
     * \brief Remplit les \a config de la \a carte.
     * Crée un Modele à partir de \a nom et génère la Zone procéduralement à
     * partir de ce Modele.
     * \param[in] nom : le nom du Modele désiré pour la Zone.
     */
    void zone_depuis_modele(std::string nom);

    /**
     * \brief Appelle zone_depuis_modele avec un nom aléatoire.
     * Crée un Modele aléatoirement et génère la Zone procéduralement à
     * partir de ce Modele.
     */
    void zone_depuis_modele_aleatoire(int taille = 0);
};

#endif // ZONE_H_INCLUDED
