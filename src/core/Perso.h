#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <string>

class Perso
{
private:
    std::string nom;
    ///TODO : implémenter Arme puis revenir un coup sur Perso.
    //Arme arme1;
    //Arme arme2;

    float angle_regard; /**< \a angle_regard de 0 à 360°, où 0 est à droite. */

    float vitesse; /**< \a vitesse du Perso, comme coefficient d'une vitesse de base. */
    float angle_mouvement; /**< \a angle_mouvement est calculé comme angle_regard, mais pour le déplacement. */

    float pos_x; /**< \a pos_x détermine où se trouve Perso dans une Salle; par rapport au centre du Perso. */
    float pos_y; /**< \a pos_y détermine où se trouve Perso dans une Salle; par rapport au centre du Perso. */

    float pv_max; /**< \a pv_max est le nombre de coeurs maximum du Perso. */
    float pv_actuel; /**< \a pv_actuel est la "lose condition" si elle atteint 0, et doit être < pv_max. */

public:

};

#endif // PERSO_H_INCLUDED
