#ifndef SALLEGEN_H_INCLUDED
#define SALLEGEN_H_INCLUDED

#include <string>

class SalleGen
{
private:
    int grille[9][17];
    bool p_haut, p_bas, p_gauche, p_droite;
    int config;
    //0=normal, 1=porte, 2=trou, 3=mur, 4=clef, 5=buisson/rocher

    bool valide;

    void placer_amas_recursif(int i, int j, int type, int taille);


public:
    SalleGen();

    SalleGen(bool p_h, bool p_b, bool p_g, bool p_d, int conf);

    void initialisation_gen();

    void afficher_tests()const;

    void placer_clef();

    void placer_amas(int type, int taille = 2);

};


#endif // SALLEGEN_H_INCLUDED
