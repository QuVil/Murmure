#include <iostream>
#include "Zone.h"
#include "ZoneGen.h"

using namespace std;

int main(int argc, char ** argv)
{
    //Salut Gary, voilà une mini-présentation très simple du module ZoneGen pour ton test d'intégration dans Jeu.cpp
    ZoneGen generateur; //l'instance peut aussi être construite en passant en paramètre un patterne de départ et une méthode | ex : ZoneGen generateur("carre", "voisins")

    generateur.afficher_carte();
    cout<<"Le constructeur de base génère un tableau vide d'entiers";

    generateur.initialisation_gen("carre", "voisins"); //initialise le generateur avec le patterne et le modèle passé (si un patterne et un modèle ne sont pas déjà présents)
    cout<<"après initialisation, voici l'état de la carte : "<<endl;
    generateur.afficher_carte();

    //ensuite, tu fais tourner le generateur avec la fonction iterer(). SI tu veux utiliser une autre méthode que celle de l'initialisation,
    //passe un string en parametre de iterer()
    generateur.iterer();
    cout<<"Voilà la carte après une itération : "<<endl;
    generateur.afficher_carte();

    generateur.iterer();
    cout<<"Voilà la carte après deux itérations : "<<endl;
    generateur.afficher_carte();

    //voilà un exemple de génération :
    generateur.iterer();
    generateur.iterer();
    generateur.iterer("aleatoire"); //a une chance de changer toutes les cases (sauf la case centrale)
    generateur.iterer("epuration"); //supprime les cases sans voisins
    generateur.iterer("extension"); //a une chance d'étendre les couloirs

    cout<<"et voici la carte 'finale' :"<<endl;
    generateur.afficher_carte();
    cout<<"never forget : il manque certaines fonctionnalités.";

    //et maintenant, il existe un constructeur de la class Zone prenant en parametre un ZoneGen :
    //Zone zone_test(generateur);
    //mais pour le moment ça marche pas. J'aimerais bien que tu regardes ça, parce que ça me casse bien les couilles.
    return 0;
}

