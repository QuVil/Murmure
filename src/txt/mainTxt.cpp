#include <iostream>

#include "Jeu.h"
#include "Salle.h"
#include "Fichier.h"

using namespace std;

int main(int argc, char ** argv)
{
    Jeu jeu;
    jeu.get_salle().afficher();
    cout << "KENTIN LA PTITE BEET" << endl;

    return 0;
}
