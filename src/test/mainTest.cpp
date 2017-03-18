#include <iostream>
#include "Zone.h"

int main(int argc, char ** argv)
{
    srand(time (NULL));
    Zone z;
    z.zone_depuis_modele_aleatoire();

    return 0;
}

