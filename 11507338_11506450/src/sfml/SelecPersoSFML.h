#ifndef SELECPERSOSFML_H_INCLUDED
#define SELECPERSOSFML_H_INCLUDED

#include <string>
#include "Jeu.h"

class SelecPersoSFML
{
private:
    std::string selection;
public:
    SelecPersoSFML();

    void choisir_perso(const Jeu &j);
};

#endif // SELECPERSOSFML_H_INCLUDED
