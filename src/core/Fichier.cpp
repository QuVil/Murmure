#include <iostream>
#include <cassert>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#include "Fichier.h"


const std::string CHEMIN="data/res/";
const std::string INDEX_FILE="index.cfg";

Fichier::Fichier()
{
    chemin=CHEMIN;
    index_file=INDEX_FILE;
}


/*void Fichier::creation_index(std::string dir_name, ofstream& index)
{
    DIR* sous_dossier;
    struct dirent* fichierLu = NULL;

    sous_dossier = opendir((chemin+dir_name).c_str());
    fichierLu=readdir(sous_dossier);

    while(fichierLu!=NULL)
    {
        if((strcmp(fichierLu->d_name, ".") != 0) &&
            (strcmp(fichierLu->d_name, "..")!= 0))
        {
            index << fichierLu->d_name << ":" << chemin << dir_name << "/" << fichierLu->d_name << endl;
        }
        fichierLu=readdir(sous_dossier);
    }
}
*/

/*
string Fichier::file_only(char * file)
{
    string nouveau_nom;
    int i=0;
    while(file[i]!='.')
   {
       strcat(nouveau_nom,file[i]);
       nouveau_nom <<  std::string(file[i]);
    }
    return nouveau_nom;
}*/
/*
void Fichier::creation_index()
{
    ofstream index((chemin + index_file).c_str(), ios::out | ios::trunc);

    assert(index);
    struct dirent* fichierLu = NULL;

    DIR* dossier;
    dossier = opendir(chemin.c_str());
    assert(dossier!=NULL);
    rewinddir(dossier);


    fichierLu=readdir(dossier);

    while(fichierLu!=NULL)
    {
        if((strcmp(fichierLu->d_name,".")!=0) &&
            (strcmp(fichierLu->d_name, "..")!= 0)  &&
            (strcmp(fichierLu->d_name,index_file.c_str()) !=0))
        {
            index << fichierLu->d_name << "\\" << endl;
            creation_index(fichierLu->d_name,index);
            index << "\\" << endl << endl;
        }
        fichierLu=readdir(dossier);
    }

    index.close();
}*/


void Fichier::charger(Salle & s)
{
    //Cree un chemin relatif qui pointe sur la configuration en fonction
    //de la valeur config de la salle (par defaut 1)
    std::stringstream ss;
    ss << chemin << "Salle/" << s.get_config() << ".cfg";
    std::string path = ss.str();

    std::ifstream fichier((path).c_str(), std::ios::in);
    assert(fichier);

    char tampon;

    for(int i=0;i<s.get_nb_cases_hauteur();i++)
    {
        //compte les retours à la ligne donc <= 21 pour avoir le bon compte
        for(int j=0;j<s.get_nb_cases_largeur();j++)
        {
            tampon=fichier.get();
            //cout << tampon;
            s.set_case(i,
                               j,
                               tampon);
            //cout << (int) tampon << endl;
        }
        // récupere juste le caractere de changement de ligne
        // (qui ne sert à rien ici)
        tampon=fichier.get();
    }

    fichier.close();
}


void Fichier::charger(Salle& s, const int& id, const int& conf)
{
    //Cree un chemin relatif qui pointe sur la configuration en fonction
    //de la valeur config de la salle (par defaut 1)
    std::stringstream ss;
    std::cout<<chemin << "Salle/" << conf << "_" << id << ".cfg"<<std::endl;
    ss << chemin << "Salle/" << conf << "_" << id << ".cfg";
    std::string path = ss.str();

    //à delete
    //std::cout<<ss<<std::endl;
    //^

    std::ifstream fichier((path).c_str(), std::ios::in);
    assert(fichier);

    char tampon;

    for(int i=0;i<s.get_nb_cases_hauteur();i++)
    {
        //compte les retours à la ligne donc <= 21 pour avoir le bon compte
        for(int j=0;j<s.get_nb_cases_largeur();j++)
        {
            tampon=fichier.get();
            //cout << tampon;
            s.set_case(i, j, tampon);
            //cout << (int) tampon << endl;
        }
        // récupere juste le caractere de changement de ligne
        // (qui ne sert à rien ici)
        tampon=fichier.get();
    }

    fichier.close();
}


void Fichier::charger(ZoneGen & z)
{
    //Cree un chemin relatif qui pointe sur la configuration en fonction
    //de la valeur config de la salle (par defaut 1)
    std::stringstream ss;
    ss << chemin << "ZoneGen/" << z.get_patterne() << ".cfg";
    std::string path = ss.str();

    std::ifstream fichier((path).c_str(), std::ios::in);
    assert(fichier);

    char tampon;

    for(int i=0;i<11;i++)
    {
        //compte les retours à la ligne donc <= 21 pour avoir le bon compte
        for(int j=0;j<11;j++)
        {
            tampon=fichier.get();
            //cout << tampon;
            z.set_etat(i, j, tampon - '0');;
            //cout << (int) tampon << endl;
        }
        // voir la fonction charger(Salle)
        tampon=fichier.get();
    }

    fichier.close();
}

void Fichier::charger(Modele &m, std::string nom)
{
    //Cree un chemin relatif qui pointe sur la configuration en fonction
    //de la valeur config de la salle (par defaut 1)
    std::stringstream ss;
    ss << chemin << "Modele/" << nom << ".cfg";
    std::string path = ss.str();

    std::ifstream fichier((path).c_str(), std::ios::in);
    assert(fichier);

    char tampon, tampon2;
    int tamp, tamp2;

    for (int i=0; i<2; ++i)
    {
        tampon = fichier.get();
        tampon2 = fichier.get();
        tamp = tampon - '0';
        tamp2 = tampon2 - '0';
        tamp = tamp*10 + tamp2;
        m.set_tableau_modele_i(tamp, i);
        tampon = fichier.get();
    }

    for(int i=2; i<23; ++i)
    {
        tampon=fichier.get();

        tamp = tampon - '0';
        m.set_tableau_modele_i(tamp, i);
        tampon=fichier.get();
    }

    fichier.close();
}

void Fichier::charger(ModeleSalle &m, std::string nom)
{
    //Cree un chemin relatif qui pointe sur la configuration en fonction
    //de la valeur config de la salle (par defaut 1)
    std::stringstream ss;
    ss << chemin << "ModeleSalle/" << nom << ".cfg";
    std::string path = ss.str();

    std::ifstream fichier((path).c_str(), std::ios::in);
    assert(fichier);

    char tampon, tampon2, tampon3;
    int tamp, tamp2, tamp3;

    tampon = fichier.get();
    tampon2 = fichier.get();
    tampon3 = fichier.get();

    tamp = tampon - '0';
    tamp2 = tampon2 - '0';
    tamp3 = tampon3 - '0';
    tamp = tamp*100 + tamp2*10 + tamp3;


    m.set_tableau_modele_i(tamp, 0);
    tampon = fichier.get();

    for(int i=1; i<22; ++i)
    {
        tampon=fichier.get();
        tamp = tampon - '0';
        m.set_tableau_modele_i(tamp, i);
        tampon=fichier.get();
    }
    fichier.close();
}

/**
void Fichier::charger(Zone & z)
{
    //Cree un chemin relatif qui pointe sur la configuration en fonction
    //de la valeur config de la salle (par defaut 1)
    stringstream ss;
    ss << chemin << "Zone/" << z.get_patterne() << ".cfg";
    string path = ss.str();

    ifstream fichier((path).c_str(), ios::in);
    assert(fichier);

    char tampon;

    for(int i=0;i<11;i++)
    {
        //compte les retours à la ligne donc <= 21 pour avoir le bon compte
        for(int j=0;j<11;j++)
        {
            tampon=fichier.get();
            //cout << tampon;
            z.set_salle(i, j, tampon - '0');;
            //cout << (int) tampon << endl;
        }
        // voir la fonction charger(Salle)
        tampon=fichier.get();
    }

    fichier.close();
}*/

void Fichier::charger(Perso & p,const std::string &n)
{
    std::stringstream ss;
    ss << chemin << "Perso/cfg/" << n << ".cfg";
    std::string path = ss.str();

    std::ifstream fichier((path).c_str(), std::ios::in);
    assert(fichier);

    std::stringstream buffer;
    buffer << fichier.rdbuf();

    //std::cout << buffer.str() << std::endl;

    int valeur_int;
    float valeur_float;
    std::istringstream is_file(buffer.str());
    std::string ligne;
    std::string variable;
    std::string valeur;
    while( std::getline(is_file, ligne) )
    {
        std::istringstream is_line(ligne);
        if( std::getline(is_line, variable, '=') )
        {
            assert(std::getline(is_line, valeur));
            if(variable.compare("nom") == 0)
            {
              p.set_nom(valeur);
            }
            else if(variable.compare("pv_max") == 0)
            {
              valeur_int = atoi(valeur.c_str());
              p.set_pv_max(valeur_int);
            }
            else if(variable.compare("coefficient_vitesse") == 0)
            {
              valeur_float = atof(valeur.c_str());
              p.set_coefficient_vitesse(valeur_float);
            }
            else if(variable.compare("taille") == 0)
            {
                valeur_float = atof(valeur.c_str());
                p.set_taille(valeur_float);
            }
            else
            {
              std::cout << "Mauvaise Valeur" << std::endl;
              exit(0);
            }
        }
    }
}





