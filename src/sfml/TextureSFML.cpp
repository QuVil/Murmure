#include "TextureSFML.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

TextureSFML::TextureSFML()
{

}

void TextureSFML::charger_textures_caseSFML()
{
    std::string path;
    std::stringstream ss;

    salle_act_x = -1;
    salle_act_y = -1;

    path = "data/res/CaseSalle/normal.png";
    normal_CaseSFML.loadFromFile(path);

    path = "data/res/CaseSalle/defaut.png";
    defaut.loadFromFile(path);

    path = "data/res/CaseSalle/rocher.png";
    rocher.loadFromFile(path);

    path = "data/res/CaseSalle/trou.png";
    trou.loadFromFile(path);

    for(int i=0; i<nb_texture_herbe_caseSFML;i++)
    {
        ss.str("");
        ss << "data/res/CaseSalle/herbe_" << i << ".png";
        path = ss.str();
        herbe[i].loadFromFile(path);
    }

    for(int i=0; i<nb_texture_sol_caseSFML;i++)
    {
        ss.str("");
        ss << "data/res/CaseSalle/sol_" << i << ".png";
        path = ss.str();
        sol[i].loadFromFile(path);
    }

    for(int i=0;i<8;i++)
    {
        ss.str("");
        ss << "data/res/CaseSalle/mur_1_" << i << ".png";
        path = ss.str();
        mur_1[i].loadFromFile(path);
    }

    for(int i=0;i<4;i++)
    {
        ss.str("");
        ss << "data/res/CaseSalle/porte_1_" << i << ".png";
        path = ss.str();
        porte[i].loadFromFile(path);
    }
}


void TextureSFML::charger_textures_carteAffSFML()
{
    std::string path;

    path = "data/res/CarteAff/actuel.png";
    actuel.loadFromFile(path);

    path = "data/res/CarteAff/boss.png";
    boss.loadFromFile(path);

    path = "data/res/CarteAff/clef.png";
    clef.loadFromFile(path);

    path = "data/res/CarteAff/depart.png";
    depart.loadFromFile(path);

    path = "data/res/CarteAff/normal.png";
    normal.loadFromFile(path);

    path = "data/res/CarteAff/objet.png";
    objet.loadFromFile(path);

    path = "data/res/CarteAff/vide.png";
    vide.loadFromFile(path);
}

void TextureSFML::charger_texture_perso()
{
    std::string path;
    path = "data/res/Perso/skin/Green.png";
    perso.loadFromFile(path);
    perso.setSmooth(true);
}

void TextureSFML::charger_texture_curseur()
{
    std::string path;
    path = "data/res/Autre/Curseur/curseur.png";
    curseur.loadFromFile(path);
    //curseur.setSmooth(true);
}

void TextureSFML::charger_texture_projectile()
{
    std::string path;
    path = "data/res/Projectile/skins/1.png";
    proj_1.loadFromFile(path);
}

void TextureSFML::charger_texture_ennemi()
{
    std::string path;
    path = "data/res/Ennemi/skins/1.png";
    ennemi_1.loadFromFile(path);
}

void TextureSFML::charger_menu_principal()
{
    std::string path;
    path = "data/res/Menu/principal.png";
    menu_principal.loadFromFile(path);
}

void TextureSFML::charger_curseur_menu()
{
    std::string path;
    path = "data/res/Menu/curseur_menu.png";
    curseur_menu.loadFromFile(path);
}

sf::RenderStates TextureSFML::retourne_rendu_texture_carteAffSFML(const int& config, const bool &salle_act)
{
    sf::RenderStates render;
    if(salle_act)
    {
        render.texture = &actuel;
        return render;
    }
    switch(config)
    {
    case 0:
        render.texture = &vide;
        return render;
    case 1:
        render.texture = &normal;
        return render;
    case 2:
        render.texture = &boss;
        return render;
    case 3:
        render.texture = &clef;
        return render;
    case 4:
        render.texture = &depart;
        return render;
    case 5:
        render.texture = &objet;
        return render;
    default:
        render.texture = &defaut;
        return render;
    }
}

sf::RenderStates TextureSFML::retourne_rendu_texture_caseSFML(const char& type, const int& i, const int& j, const int &x, const int &y)
{
    if((salle_act_x != x)||(salle_act_y != y))
    {
        if(i == 0)
        {
            if(type == 'm')
            {
                switch(j)
                {
                case 0:
                    casesfml[i][j].texture =&mur_1[0];
                    break;
                case 16:
                    casesfml[i][j].texture =&mur_1[2];
                    break;
                default:
                    casesfml[i][j].texture =&mur_1[1];
                    break;
                }
            }
            else
            {
                //casesfml[i][j].texture =&porte;
            }
        }
        else if(i == 8)
        {
            if(type == 'm')
            {
                switch(j)
                {
                case 0:
                    casesfml[i][j].texture =&mur_1[6];
                    break;
                case 16:
                    casesfml[i][j].texture =&mur_1[4];
                    break;
                default:
                    casesfml[i][j].texture =&mur_1[5];
                    break;
                }
            }
            else
            {
                //casesfml[i][j].texture =&porte;
            }
        }
        else
        {
            switch(type)
            {
            case 'n':
                casesfml[i][j].texture =&sol[rand() % nb_texture_sol_caseSFML];
                break;
            case 'p':
                //if(j == 0) {casesfml[i][j].texture =&porte;}
                //else if(j == 16) {casesfml[i][j].texture =&porte;}
                break;
            case 't':
                casesfml[i][j].texture =&trou;
                break;
            case 'r':
                casesfml[i][j].texture =&rocher;
                break;
            case 'm':
                if(j == 0) {casesfml[i][j].texture =&mur_1[7];}
                else if(j == 16) {casesfml[i][j].texture =&mur_1[3];}
                break;
            default:
                casesfml[i][j].texture =&defaut;
                break;
            }
        }
        if((i == 8)&&( j == 16))
        {
            salle_act_x = x;
            salle_act_y = y;
        }
    }
    return casesfml[i][j];
}

sf::RenderStates TextureSFML::retourne_rendu_texture_perso(const sf::Transform& t)
{
    sf::RenderStates render;
    render.texture = &perso;
    render.transform = t;
    return render;
}

sf::Texture& TextureSFML::retourne_texture_caseSFML(const char& type, const int& i, const int& j)
{
    if(i == 0)
    {
        if(type == 'm')
        {
            switch(j)
            {
            case 0:
                return mur_1[0];
                break;
            case 16:
                return mur_1[2];
                break;
            default:
                return mur_1[1];
                break;
            }
        }
        else
        {
            return porte[0];
        }
    }
    else if(i == 8)
    {
        if(type == 'm')
        {
            switch(j)
            {
            case 0:
                return mur_1[6];
                break;
            case 16:
                return mur_1[4];
                break;
            default:
                return mur_1[5];
                break;
            }
        }
        else
        {
            return porte[2];
        }
    }
    else
    {
        int tirage = rand() % 1000;
        switch(type)
        {
        case 'n':
            if(tirage < 690){return sol[0];}
            else if(tirage < 790){return sol[1];}
            else if(tirage < 890){return sol[2];}
            else if(tirage < 988){return sol[3];}
            else if(tirage < 990){return sol[4];}
            else if(tirage < 992){return sol[5];}
            else if(tirage < 994){return sol[6];}
            else if(tirage < 996){return sol[7];}
            else if(tirage < 998){return sol[8];}
            else{return sol[9];}
            break;
        case 'c':
            if(tirage < 690){return sol[0];}
            else if(tirage < 790){return sol[1];}
            else if(tirage < 890){return sol[2];}
            else if(tirage < 988){return sol[3];}
            else if(tirage < 990){return sol[4];}
            else if(tirage < 992){return sol[5];}
            else if(tirage < 994){return sol[6];}
            else if(tirage < 996){return sol[7];}
            else if(tirage < 998){return sol[8];}
            else{return sol[9];}
            break;
        case 'e':
            if(tirage < 690){return sol[0];}
            else if(tirage < 790){return sol[1];}
            else if(tirage < 890){return sol[2];}
            else if(tirage < 988){return sol[3];}
            else if(tirage < 990){return sol[4];}
            else if(tirage < 992){return sol[5];}
            else if(tirage < 994){return sol[6];}
            else if(tirage < 996){return sol[7];}
            else if(tirage < 998){return sol[8];}
            else{return sol[9];}
            break;
        case 'p':
            if(j == 0) {return porte[3];}
            else if(j == 16) {return porte[1];}
            break;
        case 't':
            return trou;
            break;
        case 'r':
            return rocher;
            break;
        case 'm':
            if(j == 0) {return mur_1[7];}
            else if(j == 16) {return mur_1[3];}
            break;
        default:
            return defaut;
            break;
        }
    }
    return defaut;
}

sf::Texture& TextureSFML::retourne_texture_carteAffSFML(const int& config, const bool &salle_act)
{
    if(salle_act)
    {
        return actuel;
    }
    else
    {
        switch(config)
        {
        case 0:
            return vide;
            break;
        case 1:
            return normal;
            break;
        case 2:
            return boss;
            break;
        case 3:
            return clef;
            break;
        case 4:
            return depart;
            break;
        case 5:
            return objet;
            break;
        default:
            return defaut;
            break;
        }
    }
}

sf::Texture& TextureSFML::retourne_texture_perso()
{
    return perso;
}


sf::Texture& TextureSFML::retourne_texture_curseur()
{
    return curseur;
}

sf::Texture& TextureSFML::retourne_texture_projectile()
{
    return proj_1;
}

sf::Texture& TextureSFML::retourne_texture_ennemi()
{
    return ennemi_1;
}

void TextureSFML::charger_texture_clef()
{
    std::string path;
    path = "data/res/clef.png";
    clef_boss.loadFromFile(path);
}

sf::Texture& TextureSFML::retourne_texture_clef()
{
    return clef_boss;
}

sf::Texture& TextureSFML::retourne_texture_menu()
{
    return menu_principal;
}

sf::Texture& TextureSFML::retourne_texture_curseur_menu()
{
    return curseur_menu;
}

