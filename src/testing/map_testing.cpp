#include <iostream>
#include <string>

//Salut, on fait ça à l'arrache : pas de modules parce que c'est du testing OK ? Ok.
using namespace std;
//Nota Bene : ce code n'a pas ete execute, ni fini; KEK. A prendre avec des pincettes je suppose.

class CaseSalle
{
    private:
        int motif; //TODO: creer classe motif pour les cases si on fait les salles en rectangle par grilles

    public:
        CaseSalle()
        {
            motif = 1;
        }

        ~CaseSalle()
        {
            motif = 0;
        }

        int get_motif()const
        {
            return motif;
        }

        void set_motif(int mo)
        {
            motif = mo;
        }

        CaseSalle& operator = (const CaseSalle& case2)
        {
            motif = case2.get_motif();
            return *this;
        }

};

class Salle
{
    private:
        CaseSalle grille[20][15];
        bool etat_plein;
        string theme;

    public:
        //-------------------------Construction/Destruction-------------------
        Salle()
        {
            etat_plein = false;
            theme = "base";
        }

        Salle(string the)
        {
            etat_plein = false;
            theme = the;
        }

        ~Salle()
        {
            //NaN
        }

        //----------------------------Access-Mutat----------------------------
        CaseSalle get_case(int x, int y) const
        {
            return grille[x][y];
        }

        string get_theme() const
        {
            return theme;
        }

        bool is_etat_plein() const
        {
            return etat_plein;
        }

        void set_case(int x, int y, CaseSalle nouvelle_case)
        {
            grille[x][y] = nouvelle_case;
        }

        void set_theme(string the)
        {
            theme = the;
        }

        void set_etat_plein(bool eta)
        {
            etat_plein = eta;
        }

        void vider()
        {
            etat_plein = false;
            theme = "vide";

        }

        void remplir()
        {
            etat_plein = true;
        }

        Salle& operator = (const Salle &salle2)
        {
            for (int i=0; i<20; ++i)
            {
                for (int j=0; j<15; ++j)
                    grille[i][j] = salle2.get_case(i, j);
            }
            etat_plein = salle2.is_etat_plein();
            theme = salle2.get_theme();
            return *this;
        }

        void afficher_salle()
        {
            for (int i=0; i<10; ++i)
            {
                for (int j=0; j<15; ++j)
                    cout<<grille[j][i].get_motif();
                cout<<endl;
            }

        }

};

class Zone
{
    private:
        Salle carte[11][11];
        string nom;
        int salle_actuelle_x, salle_actuelle_y;

    public:
        Zone()
        {
            nom = "Zone";
            for (int i=0; i<11; ++i)
            {
                for (int j=0; j<11; ++j)
                {
                    carte[i][j].vider();
                }
            }
            salle_actuelle_x = 5;
            salle_actuelle_y = 5;
        }

        Zone(int posx, int posy, string nom_zone = "Zone")
        {
            nom = nom_zone;
            salle_actuelle_x = posx;
            salle_actuelle_y = posy;
        }

        Salle get_salle(int x, int y)
        {
            return carte[x][y];
        }

        Salle get_salle()
        {
            return carte[salle_actuelle_x][salle_actuelle_y];
        }

        void set_salle(int x, int y, const Salle &nouvelle_salle)
        {
            carte[x][y] = nouvelle_salle;
        }

        int get_salle_actuelle_x ()const
        {
            return salle_actuelle_x;
        }

        int get_salle_actuelle_y ()const
        {
            return salle_actuelle_y;
        }

        void afficher_zone()
        {
            for (int i=0; i<11; ++i)
            {
                for (int j=0; j<11; ++j)
                {
                    cout<<carte[i][j].is_etat_plein()<<" ";
                }
                cout<<endl;
            }
        }

        void remplir_salle(int x, int y)
        {
            carte[x][y].remplir();
        }

        void remplir_salle()
        {
            carte[salle_actuelle_x][salle_actuelle_y].remplir();
        }

        void vider_salle(int x, int y)
        {
            carte[x][y].vider();
        }

        void vider_salle()
        {
            carte[salle_actuelle_x][salle_actuelle_y].vider();
        }
};


int main(int argc,char ** argv)
{
    //test lines
    Zone zone_test;
    zone_test.remplir_salle();
    zone_test.afficher_zone();
    return 0;
}
