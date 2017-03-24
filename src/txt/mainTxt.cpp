#include <iostream>

#include "JeuTxt.h"
#include "Fichier.h"

int main(int argc, char ** argv)
{
    srand(time(NULL));
    JeuTxt jeu_txt;

    jeu_txt.boucle_txt();

    return 0;
}
