#ifndef CASESALLE_H_INCLUDED
#define CASESALLE_H_INCLUDED

#include <string>
/**
 * \file CaseSalle.h
 * \brief Header du module CaseSalle.
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 11 mars 2017
 *
 */

/**
 * \class CaseSalle
 * \brief class des cases qui composent les salles dans le jeu.
 * Une Salle de base est composée d'un tableau de CaseSalle
 * de taille variable. Il est à noter que les CaseSalle servent
 * uniquement à la gestion et la génération de décors et d'ennemis,
 * et que les mouvements d'entités ne dépendent pas de ces CaseSalle.
 */
class CaseSalle
{
private:
        char type; /**< \a type de la CaseSalle. */
        // n : normal
        // p : porte
        // t : trou
        // m : mur
        // c : clef
        // r : rocher/buisson



public:

    /**
     * \brief Consctructeur
     * Le Constructeur basique de CaseSalle initialisant type sur 0.
     */
    CaseSalle();

    /**
     * \brief Consctructeur avec type
     * Constructeur prenant le type de CaseSalle désiré en parametre.
     * \param[in] t : le \a type qui sera affecte a la nouvelle instance.
     */
    CaseSalle(const char & t);

    /**
     * \brief Destructeur
     * Le Destructeur basique de CaseSalle -ne faisant rien.
     */
    ~CaseSalle();

    /**
     * \brief Accesseur de \a type
     * Accesseur du membre \a type de la CaseSalle.
     * \return le \a type de la CaseSalle en question.
     */
    std::string get_type_string();

    char get_type_char()const;

    /**
     * \brief Surcharge d'affectation de CaseSalle.
     * Surcharge de l'operateur = pour affecter des CaseSalle entre elles.
     * \param[in] c : La CaseSalle dont les membres -ici \a type- doivent etre copies.
     */
    CaseSalle& operator =(const CaseSalle & c);

    /**
     * \brief Affichage de CaseSalle.
     * Procedure d'affichage de la CaseSalle.
     */
    void afficher();
};

#endif // CASESALLE_H_INCLUDED
