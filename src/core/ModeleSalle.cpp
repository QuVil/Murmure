#include "ModeleSalle.h"
#include "Fichier.h"

#include <iostream>

ModeleSalle::ModeleSalle()
{
    for (int i=0; i<22; ++i)
    {
        tableau_modele[i] = 0;
    }
    tableau_modele[0] = 80;
    tableau_modele[1] = 1;
    tableau_modele[2] = 0;
    tableau_modele[3] = 1;
    tableau_modele[4] = 1;
    tableau_modele[5] = 1;
    tableau_modele[6] = 2;
    tableau_modele[7] = 2;
    tableau_modele[8] = 1;
    tableau_modele[9] = 9;
}

ModeleSalle::ModeleSalle(std::string nom)
{
    for (int i=0; i<22; ++i)
    {
        tableau_modele[i] = 0;
    }

    Fichier fichier;
    fichier.charger(*this, nom);
    ///TODO : faire la fonction charger (bah ouais).
}

void ModeleSalle::set_tableau_modele_i(int x, int i)
{
    tableau_modele[i] = x;
}

void ModeleSalle::generer_salle()
{
    generateur.set_difficulte_voulue(tableau_modele[0]);
    int ecart_diff_acceptable = 5;
    int ecart_diff;
    generateur.placer_portes(tableau_modele[2], tableau_modele[3], tableau_modele[4], tableau_modele[5]);
    generateur.set_config(tableau_modele[1]);

    while (!generateur.is_valide())
    {
        generateur.vider_salle();
        generateur.initialisation_gen();
        int i=6;
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
