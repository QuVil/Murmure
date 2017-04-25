#include "MenuSFML.h"

MenuSFML::MenuSFML(std::string nom_ecr)
{
    nom_ecran = nom_ecr;
}

MenuSFML::MenuSFML()
{
    nom_ecran = "principal";
}


void MenuSFML::actualiser_selection_curseur()
{
    //actualiser_position_souris();
    float pos_x = position_souris.get_x();
    float pos_y = position_souris.get_y();

    //On check la position du curseur en x,y et on actualise la selection
    if (nom_ecran == "principal")
    {
        //affichage du menu principal
    }
    selection_curseur = "jouer";
}

void MenuSFML::afficher_menu(std::string nom_ecr = "")
{
    if (nom_ecr == "")
    {
        nom_ecr = nom_ecran;
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
