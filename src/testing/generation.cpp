#include <iostream>
#include <string>

using namespace std;

class CarteGen
{
    private:
        int carte[11][11];
        string patterne;
        string methode;
        bool pret_iteration = false;
        //patternes : croix, carre, cercle, h, vide
        //methodes : voisins, bruit, aleatoire


    public:
        CarteGen()
        {
            for (int i=0; i<11; ++i)
            {
                for (int j=0; j<11; ++j)
                {
                    carte[i][j] = 0;
                }
            }
            patterne = " ";
            methode = " ";
        }

        CarteGen(string pat, string met)
        {
            patterne = pat;
            methode = met;
        }

        int get_etat(int x, int y) const
        {
            return carte[x][y];
        }


        void initialisation_gen(string pat, string met)
        {
            if (patterne == " ")
            {
                patterne = pat;
            }
            else
            {
                cout<<"patterne deja choisi : "<<patterne<<endl;
            }

            if (methode == " ")
            {
                methode = met;
            }
            else
            {
                cout<<"methode deja choisie : "<<methode<<endl;
            }

            if (patterne == "croix")
            {
                for (int i=0; i<11; ++i)
                {
                    for (int j=0; j<11; ++j)
                    {
                        if (i==5 || j==5)
                            carte[i][j] = 1;
                        else
                            carte[i][j] = 0;
                    }
                }
            }
        }
};



int main()
{
    return 0;
}
