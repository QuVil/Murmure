#ifndef SALLEGEN_H_INCLUDED
#define SALLEGEN_H_INCLUDED

#include <string>

class SalleGen
{
private:
    char grille[9][17];
    //n=normal, p=porte, t=trou, m=mur, c=clef, r=buisson/rocher, e=ennemi (indéterminé)

    char grille_validation[9][17];
    bool p_haut, p_bas, p_gauche, p_droite;
    int config;
    //0=vide, 1=normal, 2=boss, 3=clef, 4=depart, 5=objet

    int difficulte_approx;
    int difficulte_voulue;

    bool valide;

    void placer_amas_recursif(int i, int j, char type, int taille);

    void valider_recursif(int i, int j);

public:
    SalleGen();

    SalleGen(bool p_h, bool p_b, bool p_g, bool p_d, int conf, int diff);

    int get_type(int i, int j)const;

    bool is_valide()const;

    void initialisation_gen();

    void afficher_tests()const;

    void placer_clef();

    void placer_amas(char type, int taille = 2);

    void valider();

    void afficher_validation()const;

    void placer_ennemi();

    int calculer_distance(int x_dep, int y_dep, int x_arr, int y_arr)const;

    int calculer_distance_porte(int x, int y)const;

    void calculer_difficulte();

};


#endif // SALLEGEN_H_INCLUDED
