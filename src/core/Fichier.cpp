#include <iostream>
#include <cassert>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <string>
#include <sstream>

#include "Fichier.h"

using namespace std;

const string CHEMIN="data/res/";
const string INDEX_FILE="index.cfg";

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
    stringstream ss;
    ss << chemin << "Salle/" << s.get_config() << ".cfg";
    string path = ss.str();

    ifstream fichier((path).c_str(), ios::in);
    assert(fichier);

    char tampon;

    for(int i=0;i<s.get_cases_hauteur();i++)
    {
        //compte les retours à la ligne donc <= 21 pour avoir le bon compte
        for(int j=0;j<s.get_cases_largeur();j++)
        {
            tampon=fichier.get();
            //cout << tampon;
            s.set_case(i,
                               j,
                               tampon - '0');
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
    stringstream ss;
    ss << chemin << "ZoneGen/" << z.get_patterne() << ".cfg";
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












