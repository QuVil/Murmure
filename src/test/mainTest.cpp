#include <iostream>
#include "Zone.h"
#include "Salle.h"

int main(int argc, char ** argv)
{
    srand(time (NULL));
/*
    Zone z;
    z.zone_depuis_modele_aleatoire(0);
    z.afficher_zone();
*/

/*
    SalleGen s_generateur(1, 1, 1, 1, 3, 50);

    s_generateur.initialisation_gen();
    s_generateur.placer_amas('r');
    s_generateur.placer_amas('r', 0);
    s_generateur.placer_amas('t', 1);
    s_generateur.placer_clef();
    s_generateur.placer_ennemi();
    s_generateur.placer_ennemi();

    s_generateur.afficher_tests();
    std::cout<<std::endl;
    std::cout<<std::endl;
    s_generateur.calculer_difficulte();
    s_generateur.valider();
    s_generateur.afficher_validation();
    std::cout<<s_generateur.is_valide();
*/
    Salle s;
    s.salle_depuis_modele_aleatoire(1, 0, 1, 0, 1, 0);
    s.afficher();

    return 0;
}

