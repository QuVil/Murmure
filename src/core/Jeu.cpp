#include <iostream>

#include "Jeu.h"

Jeu::Jeu()
{
    //zone.generer_et_remplir(0);

    //Salle* adresse_test = zone.get_salle_ptr();
    //salle_actuelle.initialise_salle_actuelle(adresse_test);

}

Salle* Jeu::get_salle_actuelle()
{
    return salle_actuelle.get_salle_ptr();
}

Zone Jeu::get_zone()
{
    return zone;
}

Perso Jeu::get_perso()
{
    return perso;
}

int Jeu::grille_largeur()
{
    return taille_grille_largeur;
}

int Jeu::grille_hauteur()
{
    return taille_grille_hauteur;
}


void Jeu::changer_perso(const std::string& n)
{
    perso.charger_perso(n);
}

void Jeu::deplacer_perso(const float& x, const float& y)
{
    perso.set_deplacement(x, y);
}

void Jeu::definir_position_perso(const float& x, const float& y)
{
    perso.set_position(x, y);
}

void Jeu::definir_orientation_perso(const VecteurM& v)
{
    perso.set_orientation(v);
}

bool Jeu::zone_changer_salle(const char& c, bool devmode)
{
    if((salle_actuelle.salle_terminee())||(devmode))
    {
        zone.changer_de_salle(c);
        Salle* adresse_test = zone.get_salle_ptr();
        salle_actuelle.initialise_salle_actuelle(adresse_test);
        salle_actuelle.maj_changement_salle();
        switch(c)
        {
        case 'g':
            definir_position_perso(facteur * (8+1.0/2.0),facteur * (7 +1.0/2.0));
            break;
        case 'h':
            definir_position_perso(facteur * (15 + 1.0/2.0),facteur * (4 +1.0/2.0));
            break;
        case 'b':
            definir_position_perso(facteur * (1 +1.0/2.0),facteur * (4+ 1.0/2.0));
            break;
        case 'd':
            definir_position_perso(facteur * (8 + 1.0/2.0),facteur *  (1 + 1.0/2.0));
            break;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void Jeu::deplacer_perso_txt(char direction)
{
    perso.deplacer_txt(direction);
}

void Jeu::placer_perso_txt(int x, int y)
{
    perso.placer_txt(x, y);
}

void Jeu::ajouter_projectile_perso(const int& arme)
{
    // arme = 1 -> arme1 du perso
    switch(arme)
    {
    case 1:
        salle_actuelle.ajouter_projectile(perso.tirer_1());
        break;
    }
}

void Jeu::avancer_jeu(const float &vitesse_base, const int &taille_case)
{
    salle_actuelle.mise_a_jour_projectiles(vitesse_base);
    salle_actuelle.deplacer_ennemis_auto(perso.get_pos());
}

std::list <Projectile *> * Jeu::retourne_projectiles()
{
    return salle_actuelle.get_projectiles();
}

std::list <Ennemi *> * Jeu::retourne_ennemis()
{
    return salle_actuelle.get_ennemis();
}


Perso* Jeu::retourne_perso_ptr()
{
    return &perso;
}

void Jeu::deplace_ennemis_auto()
{
    salle_actuelle.deplacer_ennemis_auto(perso.get_pos());
}

Clef* Jeu::retourne_clef()
{
    return salle_actuelle.get_clef();
}

void Jeu::initialiser_jeu(const std::string &nom_joueur, const int &niveau)
{
    zone.generer_et_remplir(0);

    Salle* adresse_test = zone.get_salle_ptr();
    salle_actuelle.initialise_salle_actuelle(adresse_test);

    perso.charger_perso(nom_joueur);
}

