#include <iostream>
#include "Zone.h"
#include "ZoneGen.h"

using namespace std;

int main(int argc, char ** argv)
{
    ZoneGen tests_gen;
    tests_gen.initialisation_gen("carre", "voisins");
    cout<<"Gary jeune fdp c'est quoi cette merde"<<endl;
    tests_gen.afficher_carte();

    return 0;
}

/**
 * Merci FDP
 */
