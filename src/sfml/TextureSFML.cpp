#include "TextureSFML.h"
#include <iostream>

TextureSFML::TextureSFML()
{

}

void TextureSFML::charger_textures_caseSFML()
{
    std::string path;
    path = "data/res/CaseSalle/normal.png";
    normal.loadFromFile(path);

    path = "data/res/CaseSalle/mur.png";
    mur.loadFromFile(path);

    path = "data/res/CaseSalle/porte.png";
    porte.loadFromFile(path);
}


sf::Texture TextureSFML::retourne_texture_caseSFML(const char &type)
{
    switch(type)
    {
        case 'n' :
                    return normal;
                    break;
        case 'p' :
                    return porte;
                    break;
/*
        case 't' :
                    return "trou";
                    break;*/
        case 'm' :
                    return mur;
                    break;
                    /*
        case 'c' :
                    return "clef";
                    break;
        case 'r' :
                    return "rocher";
                    break;*/
        default :
                    return normal;
                    break;
    }
}
