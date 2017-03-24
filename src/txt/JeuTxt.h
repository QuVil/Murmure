#ifndef JEUTXT_H_INCLUDED
#define JEUTXT_H_INCLUDED

#include "Jeu.h"
#include "winTxt.h"

class JeuTxt
{
private:
    Jeu jeu;

public:

    void txtAff(WinTXT & win, Jeu & jeu);

    void boucle_txt();

};

#endif // JEUTXT_H_INCLUDED
