#ifndef ZONE_H_INCLUDED
#define ZONE_H_INCLUDED

#include "Salle.h"
#include <string>

using namespace std;

class Zone
{
private:
    Salle carte[11][11];
    string nom;
    int salle_actuelle_x, salle_actuelle_y;

public:
    //constructeur de base, avec toutes les salles vides et le nom "Zone"
    Zone();

    //crée une instance de zone en passant en paramètre les coordonnées de la salle actuelle et son nom
    Zone(int posx, int posy, string nom_zone = "Zone");

    //renvoie la salle x,y
    Salle get_salle(int x, int y);

    //renvoie la salle actuelle
    Salle get_salle();

    //remplace la salle x,y par une salle passée en paramètre
    void set_salle(int x, int y, const Salle &nouvelle_salle);

    //renvoie la coordonnée x de la salle actuelle du joueur
    int get_salle_actuelle_x ()const;

    //renvoie la coordonnée y de la salle actuelle du joueur
    int get_salle_actuelle_y ()const;

    void afficher_zone();

    //remplit la salle x,y (n'affecte que la booléenne associée)
    void remplir_salle(int x, int y);

    //remplit la salle actuelle (n'affecte que la booléenne associée)
    void remplir_salle();

    //Vide la salle x,y
    void vider_salle(int x, int y);

    //Vide la salle actuelle (je vois pas pourquoi on s'en servirait mais eh...
    void vider_salle();
};

#endif // ZONE_H_INCLUDED
