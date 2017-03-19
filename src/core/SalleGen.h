#ifndef SALLEGEN_H_INCLUDED
#define SALLEGEN_H_INCLUDED

#include <string>

class SalleGen
{
private:
    char grille[9][17];
    char grille_validation[9][17];
    bool p_haut, p_bas, p_gauche, p_droite;
    int config;
    //n=normal, p=porte, t=trou, m=mur, c=clef, r=buisson/rocher

    bool valide;

    void placer_amas_recursif(int i, int j, char type, int taille);

    void valider_recursif(int i, int j);


public:
    SalleGen();

    SalleGen(bool p_h, bool p_b, bool p_g, bool p_d, int conf);

    bool is_valide()const;

    void initialisation_gen();

    void afficher_tests()const;

    void placer_clef();

    void placer_amas(char type, int taille = 2);

    void valider();

    void afficher_validation()const;

};


#endif // SALLEGEN_H_INCLUDED
