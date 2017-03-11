#ifndef CASESALLE_H_INCLUDED
#define CASESALLE_H_INCLUDED

#include <string>
/**
*
*/
class CaseSalle
{
private:
        int type;
        // 0 : normal
        // 1 : porte
        // 2 : trou
        // 3 : mur



public:
    CaseSalle();

    CaseSalle(const int & t);

    ~CaseSalle();

    CaseSalle get_CaseSalle();

    CaseSalle& operator =(const CaseSalle & c);

    int get_type();

    std::string get_type_string();

    void set_type(int t);

    void afficher();
};

#endif // CASESALLE_H_INCLUDED
