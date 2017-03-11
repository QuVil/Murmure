#ifndef CASESALLE_H_INCLUDED
#define CASESALLE_H_INCLUDED

/**
 * \file CaseSalle.h
 * \brief Header du module CaseSalle.
 * \author Quentin.V
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
        int type; /**< \a type est le membre principal, et détermine les caractéristiques de la CaseSalle. */
        // 0 : case normale
        // 1 : porte
        // 2 : trou
        // 3 : mur


public:
    CaseSalle();

    CaseSalle(const int & t);

    ~CaseSalle();

    CaseSalle get_CaseSalle();

    CaseSalle& operator =(const CaseSalle & c);

    int get_CaseSalle_type();

    void set_CaseSalle_type(int t);

    void afficher();
};

#endif // CASESALLE_H_INCLUDED
