#include <iostream>

#include "Modele.h"
#include "Zone.h"
#include "ModeleSalle.h"

using namespace std;

int main(int argc, char ** argv)
{
    srand(time(NULL));
    cout << "Test de regression demarre..." << endl;
    /// ARME

    /// CASESALLE

    /// COORD2D

    /// ENNEMI

    /// ZONE -- ZONEGEN -- MODELE
    //test sympa
    ZoneGen z;
    z.set_etat(2, 2, 1);

    try{
        z.set_etat(18, 99, 5);
        cout<<z.get_etat(18, 99)<<endl;
        throw std::out_of_range("woops... out of range.");
    }
    catch(std::out_of_range){
        cout<<"out of range OK."<<endl;
    }

    z.afficher_carte();
    z.vider_carte();
    z.initialisation_gen("h", "bruit_neg");
    z.iterer();
    z.valider();
    cout<<"validite : "<<z.is_valide()<<endl;
    z.afficher_carte();
    cout<<"patterne : "<<z.get_patterne()<<endl;
    cout<<"nb cases : "<<z.get_nb_cases()<<endl;

    z.placer_boss();
    z.placer_depart();
    z.placer_clef();
    z.placer_objet();
    cout<<"validite : "<<z.is_valide()<<endl; //Hey, j'ai déjà corrigé le comptage cases grâce à ce test :D
    z.teste_nb_cases_assez(17);
    cout<<"validite : "<<z.is_valide()<<endl;
    z.teste_nb_cases_trop(20);

    cout<<"validite : "<<z.is_valide()<<endl;
    z.afficher_carte();
    cout<<"x depart : "<<z.get_posx_dep()<<", y depart : "<<z.get_posy_dep()<<endl;

    z.afficher_carte();
    cout<<endl<<endl;

    //test pas sympa mais qui marche quand même normalement.
    Modele m("regression");
    m.generer_zone();
    m.afficher_tests();
    cout<<"^Une Zone de 55 à 60 salles à partir de Modele vide^"<<endl;

    Zone zo(z); //constructeur depuis ZoneGen
    zo.afficher_zone();

    ///SALLE -- SALLEGEN -- ModeleSalle

    ModeleSalle m_s;
    m_s.generer_salle(1, 1, 0, 0, 1); //genere une Salle normale, avec 2 ennemis et des amas.
    m_s.afficher_tests();
    cout<<endl<<endl;
    Salle s;
    s.afficher();
    cout<<s.get_config()<<endl;
    cout<<s.is_deja_visitee()<<endl;


    cout<<"Test de regression termine."<<endl;
    return 0;
}
