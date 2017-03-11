#ifndef SALLE_H_INCLUDED
#define SALLE_H_INCLUDED

#include "CaseSalle.h"

class Salle
{
private:
    //cree un tableau de CaseSalle
    CaseSalle grille[15][21];
    //config correspond a la disposition de la salle, numerote par un nombre
    int config;

public:
    Salle();

    CaseSalle get_case(int i,int j);

    void set_case(int i, int j, CaseSalle c);

    int get_config();

    void set_config(int c);

    void vider();

    void remplir();

    void afficher();
};

#endif // SALLE_H_INCLUDED
