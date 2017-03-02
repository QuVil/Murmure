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
        CaseSalle grille[15][10];
        bool etat_vide;
        string theme;

    public:
        //-------------------------Construction/Destruction-------------------
        Salle()
        {
            etat_vide = false;
            theme = "base";
        }

        Salle(string the = "base")
        {
            etat_vide = false;
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

        bool get_etat_vide() const
        {
            return etat_vide;
        }

        void set_case(int x, int y, CaseSalle nouvelle_case)
        {
            grille[x][y] = nouvelle_case;
        }

        void set_theme(string the)
        {
            theme = the;
        }

        void set_etat_vide(bool eta)
        {
            etat_vide = eta;
        }

        void vider()
        {
            etat_vide = true;
        }

        void remplir()
        {
            etat_vide = false;
        }

        Salle& operator = (const Salle &salle2)
        {
            for (int i=0; i<15; ++i)
            {
                for (int j=0; j<10; ++j)
                    grille[i][j] = salle2.get_case(i, j);
            }
            etat_vide = salle2.get_etat_vide();
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
        Salle carte[10][10];
        string nom;
        int salle_actuelle_x, salle_actuelle_y;

    public:
        Zone()
        {
            nom = "Zone";
            salle_actuelle_x = 5;
            salle_actuelle_y = 5;
        }

        Zone(int posx, int posy, string nom_zone = "Zone")
        {
            nom = nom_zone;
            salle_actuelle_x = posx;
            salle_actuelle_y = posy;
        }

        Salle get_salle(int x, int y) const
        {
            return carte[x][y];
        }

        void set_salle(int x, int y, Salle nouvelle_salle)
        {
            carte[x][y] = nouvelle_salle;
        }

        Salle donne_salle_actuelle () const
        {
            return carte[salle_actuelle_x][salle_actuelle_y];
        }
};


int main(int argc,char ** argv)
{
    //test lines
    Zone zone_test;
    Salle salle_test;
    CaseSalle case_test;
    case_test.set_motif(0);
    salle_test.set_case(6, 7, case_test);
    zone_test.donne_salle_actuelle().get_case(5,5).set_motif(1);
    zone_test.donne_salle_actuelle().afficher_salle();
    return 0;
}
