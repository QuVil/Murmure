#include "ModeleSalle.h"
#include "Fichier.h"

#include <iostream>

ModeleSalle::ModeleSalle()
{
    for (int i=0; i<10; ++i)
    {
        tableau_modele[i] = 0;
    }
}

ModeleSalle::ModeleSalle(std::string nom)
{
    for (int i=0; i<10; ++i)
    {
        tableau_modele[i] = 0;
    }
    Fichier fichier;
    fichier.charger(*this, nom);
    ///TODO : faire la fonction (bah ouais).
}

void ModeleSalle::set_tableau_modele_i(int x, int i)
{
    tableau_modele[i] = x;
}

void ModeleSalle::generer_salle()
{

}

int ModeleSalle::get_case_generateur(int x, int y) const
{
    return generateur.get_type(x, y);
}

void ModeleSalle::afficher_tests() const
{
    generateur.afficher_tests();
}
