#ifndef SALLEGEN_H_INCLUDED
#define SALLEGEN_H_INCLUDED


class SalleGen
{
private:
    int grille[9][17];
    bool p_haut, p_bas, p_gauche, p_droite;


public:
    SalleGen();

    SalleGen(bool p_h, bool p_b, bool p_g, bool p_d);

    void initialisation_gen();

}


#endif // SALLEGEN_H_INCLUDED
