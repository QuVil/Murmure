#include "Objet.h"

Objet::Objet()
{
    nom = "NaN";
    rarete = 'c';
    for (int i=0; i<8; ++i)
    {
        type_effet[i] = 0;
        portee_effet[i] = 0;
    }
}

Objet::Objet(std::string n, char rar, char t_e[8], int por[8])
{
    nom = n;
    rarete = rar;
    for (int i=0; i<8; ++i)
    {
        type_effet[i] = t_e[i];
        portee_effet[i] = por[i];
    }
}

string Objet::get_nom() const
{
    return nom;
}

char Objet::get_rarete() const
{
    return rarete;
}

char Objet::get_type_effet_i(int i) const
{
    return type_effet[i]
}

int Objet::get_portee_effet_i(int i) const
{
    return portee_effet[i]
}

void Objet::set_nom(std:string n)
{
    nom = n;
}

void Objet::set_rarete(char r)
{
    rarete = r;
}

void Objet::set_type_effet_i(int i, char e)
{
    type_effet[i] = e;
}

void Objet::set_portee_effet_i(int i, int p)
{
    portee_effet[i] = e;
}
