#include "TextureSFML.h"
#include <string>
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
    normal.loadFromFile(path);

    path = "data/res/CaseSalle/defaut.png";
    defaut.loadFromFile(path);

    path = "data/res/CaseSalle/porte.png";
    porte.loadFromFile(path);

    path = "data/res/CaseSalle/rocher.png";
    rocher.loadFromFile(path);

    path = "data/res/CaseSalle/trou.png";
    trou.loadFromFile(path);

    for(int i=0; i<nb_texture_herbe_caseSFML;i++)
    {
        ss << "data/res/CaseSalle/herbe_" << i << ".png";
        herbe[i].loadFromFile(path);
    }

    for(int i=0;i<8;i++)
    {
        ss << "data/res/CaseSalle/mur_1_" << i << ".png";
        mur_1[i].loadFromFile(path);
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
                casesfml[i][j].texture =&porte;
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
                casesfml[i][j].texture =&porte;
            }
        }
        else
        {
            switch(type)
            {
            case 'n':
                casesfml[i][j].texture =&herbe[rand() % nb_texture_herbe_caseSFML];
                break;
            case 'p':
                if(j == 0) {casesfml[i][j].texture =&porte;}
                else if(j == 8) {casesfml[i][j].texture =&porte;}
                break;
            case 't':
                casesfml[i][j].texture =&trou;
                break;
            case 'r':
                casesfml[i][j].texture =&rocher;
                break;
            case 'm':
                if(j == 0) {casesfml[i][j].texture =&mur_1[7];}
                else if(j == 8) {casesfml[i][j].texture =&mur_1[3];}
                break;
            default:
                casesfml[i][j].texture =&defaut;
                break;
            }
        }
        // enregistrer la salle pour ne pas la recalculer
        // ensuite
        if((i == 8)&&( j == 17))
        {
            salle_act_x = x;
            salle_act_y = y;
        }
    }
    //sf::RenderStates render;
    /*
    switch(type)
    {
        case 'n' :
                    render.texture = &normal;
                    break;
        case 'p' :
                    render.texture = &porte;
                    break;
        case 't' :
                    render.texture = &trou;
                    break;
        case 'm' :
                    render.texture = &mur;
                    break;

        case 'c' :
                    return "clef";
                    break;
        case 'r' :
                    render.texture = &rocher;
                    break;
        default :
                    render.texture = &normal;
                    break;
    }*/
    //render.texture = &casesfml[i][j];
    return casesfml[i][j];
}
