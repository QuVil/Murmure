#include <iostream>

#include "Jeu.h"

Jeu::Jeu()
{
    zone.generer_et_remplir(0);

    Salle* adresse_test = zone.get_salle_ptr();
    salle_actuelle.initialise_salle_actuelle(adresse_test);

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

void  Jeu::zone_changer_salle(const char& c)
{
    zone.changer_de_salle(c);
    Salle* adresse_test = zone.get_salle_ptr();
    salle_actuelle.initialise_salle_actuelle(adresse_test);
    salle_actuelle.maj_changement_salle();
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
