/**
 * \file CaseSalle.cpp
 * \brief Code source pour le module CaseSalle
 * \author Quentin.V & Gary.S
 * \version 0.1
 * \date 11 mars 2017
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>

#include "CaseSalle.h"

CaseSalle::CaseSalle()
{
    type = 'n';
}


CaseSalle::CaseSalle(const char& t)
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

std::string CaseSalle::get_type_string()
{
    switch(type)
    {
        case 'n' : return "normal";
                    break;
        case 'p' : return "porte";
                    break;
        case 't' : return "trou";
                    break;
        case 'm' : return "mur";
                    break;
        case 'c' : return "clef";
                    break;
        case 'r' : return "rocher";
                    break;
        default : return "normal";
                    break;
    }
}

char CaseSalle::get_type_char() const
{
    return type;
}


void CaseSalle::afficher()
{
    std::cout << type;
}
