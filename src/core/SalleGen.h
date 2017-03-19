#ifndef SALLEGEN_H_INCLUDED
#define SALLEGEN_H_INCLUDED

#include <string>

class SalleGen
{
private:
    int grille[9][17];
    bool p_haut, p_bas, p_gauche, p_droite;
    int config;
    //0=vide, 1=normal, 2=boss, 3=clef, 4=depart, 5=objet

    bool valide;


public:
    SalleGen();

    SalleGen(bool p_h, bool p_b, bool p_g, bool p_d, int conf);

    void initialisation_gen();

    void afficher_tests()const;

    void placer_clef();

};


#endif // SALLEGEN_H_INCLUDED
