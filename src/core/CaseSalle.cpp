#include <iostream>
#include <string>
#include <stdlib.h>

#include "CaseSalle.h"

CaseSalle::CaseSalle()
{
    type = 0;
}

CaseSalle::CaseSalle(const int& t)
{
    type = t;
}

CaseSalle::~CaseSalle()
{

}

CaseSalle& CaseSalle::operator =(const CaseSalle & c)
{
    type=c.type;
    return *this;
}

int CaseSalle::get_type()
{
    return type;
}

std::string CaseSalle::get_type_string()
{
    switch(type)
    {
        case 0 : return "normal";
                       break;
        case 1 : return "porte";
                       break;
        case 2 : return "trou";
                       break;
        case 3 : return "mur";
                       break;
        default : return "normal";
                          break;
    }
}


void CaseSalle::set_type(int t)
{
    type = t;
}

void CaseSalle::afficher()
{
    std::cout << type;
}
