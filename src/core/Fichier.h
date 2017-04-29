#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include <fstream>
#include <string>

#include "Arme.h"
#include "Ennemi.h"
#include "Salle.h"
#include "ZoneGen.h"
#include "Zone.h"
#include "Perso.h"
#include "Modele.h"
#include "ModeleSalle.h"

/** \file Fichier.h
 * \brief Module qui va chercher les valeurs des diff�rentes classes dans des fichiers de configuration
 */

class Fichier
{
private:
    std::string chemin; /**< chemin o� sont les donn�es � enregistrer */
    std::string index_file; /**< nom du fichier comprenant l'index des fichiers de configuration */

    /** \brief Creation de l'index du sous-dossier
     * \param[in] dir_name : nom du dossier
     * \param[in] index : fichier dans lequel implementer l'index
     */

    void creation_index(std::string dir_name, std::ofstream& index);
    //std::string file_only(char  * file);
public:
    /** \brief Constucteur par d�faut
     * Declare les variables et assigne les valeurs par d�faut
     */

    Fichier();

    /** \brief Creation de l'index
     * Cr�� l'index de tous les fichier s de configuration
     */

    void creation_index();

    /** \brief Charge \a Salle d�faut
     * Charge la salle avec les parametres par d�faut
     * \param[in,out] s : salle � implementer
     */

    void charger(Salle & s);

    /** \brief Charge \a Salle
     * Charge la salle avec des parametres definis
     * \param[in,out] s : salle � implementer
     */

    void charger(Salle &s, const int &id, const int &conf);

    /** \brief Charge \a ZoneGen
     * Charge le script de generation de la zone
     * \param[in,out] z : script � charger
     * \param[in] id : identifiant de la salle
     * \param[in] conf : configuration de la salle
     */

    void charger(ZoneGen & z);

    /** \brief Charge \a Zone d�faut
     * Charge la zone avec les parametres par d�faut
     * \param[in,out] z : zone � implementer
     */

    void charger(Zone & z);

    /** \brief Charge \a Arme
     * Charge l'arme avec les parametres definis
     * \param[in,out] a : arme � implementer
     * \param[in] id_arme : indetifiant de l'arme � charger
     * \param[in] nv_arme : niveau de l'arme � charger
     */

    void charger(Arme &a, const int &id_arme, const int &nv_arme);

    /** \brief Charge \a Perso d�faut
     * Charge le personnage avec un nom d�fini
     * \param[in,out] p : personnage � implementer
     * \param[in] n : nom du personnage
     */

    void charger(Perso & p, const std::string &n);


    void charger(Modele & m, std::string nom);


    void charger(ModeleSalle & m, std::string nom);

    void charger(Ennemi &e, std::string nom);
};

#endif // FICHIER_H_INCLUDED
