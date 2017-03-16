#include <iostream>

#include "Jeu.h"
#include "Salle.h"
#include "Fichier.h"

using namespace std;

int main(int argc, char ** argv)
{
    Jeu jeu;
    jeu.get_salle().afficher();
    cout << jeu.get_salle().get_nb_cases_hauteur() << " bite " << jeu.get_salle().get_nb_cases_largeur() << endl;
    cout << "Gare y lappe teet bih-t" << endl;

    return 0;
}
