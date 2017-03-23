#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

#include <string>

class Objet
{
private:

    std::string nom;
    char rarete; /**< détermine la rareté relative de l'Objet. dans l'ordre, 'c', 'r', 's', 'l'*/

    char type_effet[8] /**< Chaque Objet à jusqu'à 8 effets différents. Les nomenclatures sont explicitées en commentaire.*/
    //'d' pour dégâts, 'p' pour PV, 'v' pour vitesse, 's' pour spécial (autres)

    int portee_effet[8]; /**< Le coefficient de l'effet de l'Objet.*/

public:

    Objet();

    Objet(std::string n, char rar, char t_e[8], int por[8]);

    std::string get_nom()const;

    char get_rarete()const;

    char get_type_effet_i (int i)const;

    int get_portee_effet_i (int i)const;

    void set_nom (std:string n);

    void set_rarete (char r);

    void set_type_effet_i (int i, char e);

    void set_portee_effet_i (int i, int p);

}

#endif // OBJET_H_INCLUDED
