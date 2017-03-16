#include <iostream>
#include "Zone.h"
#include "ZoneGen.h"

using namespace std;

int main(int argc, char ** argv)
{
    ZoneGen generateur; //l'instance peut aussi être construite en passant en paramètre un patterne de départ et une méthode | ex : ZoneGen generateur("carre", "voisins")
    generateur.initialisation_gen("carre", "voisins"); //initialise le generateur avec le patterne et le modèle passé (si un patterne et un modèle ne sont pas déjà présents)
    generateur.iterer();
    generateur.iterer();
    generateur.iterer();
    generateur.iterer();
    generateur.iterer("aleatoire"); //a une chance de changer toutes les cases (sauf la case centrale)
    generateur.iterer("epuration"); //supprime les cases sans voisins
    generateur.iterer("extension"); //a une chance d'étendre les couloirs

    cout<<"voici la carte générée :"<<endl;
    generateur.afficher_carte();
    cout<<"nb cases : "<<generateur.get_nb_cases()<<endl;

    generateur.valider();
    cout<<"la carte est-elle valide ? : "<<generateur.is_valide()<<endl;
    generateur.placer_boss();
    cout<<"validite : "<<generateur.is_valide()<<endl;
    generateur.afficher_carte();
    return 0;
}

