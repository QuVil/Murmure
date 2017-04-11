#include "MenuSFML.h"

MenuSFML::MenuSFML(std::string nom_ecr)
{
    nom_ecran = nom_ecr;
    boucle_menu();
}

MenuSFML::MenuSFML()
{
    nom_ecran = "principal";
    boucle_menu();
}

void MenuSFML::boucle_menu()
{
    //rien
}

void MenuSFML::actualiser_selection_curseur()
{
    float pos_x = position_souris.get_x();
    float pos_y = position_souris.get_y();

    //On check la position du curseur en x,y et on actualise la selection
    // ......
    selection_curseur = "jouer";
}

void MenuSFML::afficher_menu(std::string nom_ecr = "")
{
    if (nom_ecr == "")
    {
        nom_ecr = "principal";
    }

    if (nom_ecr == "principal")
    {
        //affichage du menu principal
    }
    else if (nom_ecr == "options")
    {
        //affichage du menu d'options
    }
    else if (nom_ecr == "stats")
    {
        //affichage de l'écran des stats
    }
}
