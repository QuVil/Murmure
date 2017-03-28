#include <iostream>
#include "Modele.h"
#include "ModeleSalle.h"
#include "Zone.h"
#include "Salle.h"

int main(int argc, char ** argv)
{

    srand(time (NULL));
/*
    Modele m;
    m.generer_zone();
    m.afficher_tests();
    */
/*
    ZoneGen zg;
    zg.initialisation_gen("h", "bruit_neg");
    zg.afficher_carte();
    zg.iterer();
    zg.afficher_carte();
*/
/*
    ModeleSalle m_s("test");
    m_s.generer_salle(1, 0, 1, 0, 1);
    m_s.afficher_tests();
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

    Zone z;
    z.generer_et_remplir(0);
    z.afficher_zone();
/*
    Salle s;
    s.salle_depuis_modele_aleatoire(1, 0, 1, 0, 1, 0);
    s.afficher();
*/
    return 0;
}

