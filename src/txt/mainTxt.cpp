#include <iostream>

#include "Jeu.h"
#include "Salle.h"
#include "Fichier.h"

using namespace std;

int main(int argc, char ** argv)
{
    Jeu jeu;
    jeu.get_salle().afficher();
    cout << "Gare y lappe teet bih-t" << endl;

    return 0;
}
