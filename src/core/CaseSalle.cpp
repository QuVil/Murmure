#include <iostream>

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

int CaseSalle::get_CaseSalle_type()
{
    return type;
}

void CaseSalle::set_CaseSalle_type(int t)
{
    type = t;
}

void CaseSalle::afficher()
{
    std::cout << type;
}
