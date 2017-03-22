#include "ModeleSalle.h"
#include "Fichier.h"

#include <iostream>

ModeleSalle::ModeleSalle()
{
    for (int i=0; i<22; ++i)
    {
        tableau_modele[i] = 0;
    }
}

ModeleSalle::ModeleSalle(std::string nom)
{
    for (int i=0; i<22; ++i)
    {
        tableau_modele[i] = 0;
    }

    Fichier fichier;
    fichier.charger(*this, nom);
}

void ModeleSalle::set_tableau_modele_i(int x, int i)
{
    tableau_modele[i] = x;
}

void ModeleSalle::generer_salle(bool p_h, bool p_b, bool p_g, bool p_d, int conf)
{
    int nb_break = 0;

    generateur.set_difficulte_voulue(tableau_modele[0]);
    int ecart_diff_acceptable = 5;
    int ecart_diff;

    generateur.placer_portes(p_h, p_b, p_g, p_d);
    generateur.set_config(conf);

    while (!generateur.is_valide())
    {
        generateur.vider_salle();
        generateur.initialisation_gen();
        int i=2;
        while (tableau_modele[i] != 9)
        {
            switch (tableau_modele[i])
            {
                case 1:
                    generateur.placer_ennemi();
                    break;
                case 2:
                    generateur.placer_amas('r', tableau_modele[i+1]);
                    i++;
                    break;
                case 3:
                    generateur.placer_amas('t', tableau_modele[i+1]);
                    i++;
                    break;
                default:
                    //rien
                    break;
            }
            i++;
        }

        generateur.placer_clef();
        generateur.valider();

        ecart_diff = generateur.get_difficulte_approx() - generateur.get_difficulte_voulue();
        if (ecart_diff < 0){ecart_diff = 0 - ecart_diff;}
        if (ecart_diff > ecart_diff_acceptable)
        {
            generateur.set_valide(false);
            ecart_diff_acceptable += 1;
        }
        if (nb_break > 200000)
        {
            break;
        }
        else{++nb_break;}
    }
}

int ModeleSalle::get_case_generateur(int x, int y) const
{
    return generateur.get_type(x, y);
}

void ModeleSalle::afficher_tests() const
{
    generateur.afficher_tests();
}

int ModeleSalle::get_difficulte() const
{
    return generateur.get_difficulte_approx();
}
