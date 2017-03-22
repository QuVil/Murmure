#include <iostream>

#include "JeuSFML.h"

int main(int argc, char ** argv)
{
    srand(time (NULL));
    JeuSFML jeusfml;
    jeusfml.init();
    jeusfml.SFML_boucle();
    return 0;
}
