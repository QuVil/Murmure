#ifndef CASESALLE_H_INCLUDED
#define CASESALLE_H_INCLUDED

/**
*
*/
class CaseSalle
{
private:
        int type;
        // 0 : case normale
        // 1 : porte
        // 2 : trou
        // 3 : mur



public:
    CaseSalle();

    CaseSalle(const int & t);

    ~CaseSalle();

    CaseSalle get_CaseSalle();

    CaseSalle& operator =(const CaseSalle & c);

    int get_CaseSalle_type();

    void set_CaseSalle_type(int t);

    void afficher();
};

#endif // CASESALLE_H_INCLUDED
