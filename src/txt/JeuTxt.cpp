#include "JeuTxt.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif // WIN32


void JeuTxt::txtAff(WinTXT & win, Jeu & jeu)
{
	win.clear();

    // Affichage de la Salle
	for(int i=0; i<nb_cases_hauteur; ++i)
	{
        for(int j=0; j<nb_cases_largeur; ++j)
        {
            win.print(j, i, jeu.get_salle().get_case(i, j).get_type_char());
        }
	}

    // Affichage du Perso
	win.print(jeu.get_perso().get_pos_case_x(), jeu.get_perso().get_pos_case_y(), 'G');

	win.draw();
}

void JeuTxt::boucle_txt()
{
    WinTXT win (nb_cases_largeur*2, nb_cases_hauteur*2);

    bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
            Sleep(100);
		#else
            usleep(100000);
        #endif // WIN32

		c = win.getCh();
		int posx = jeu.get_perso().get_pos_case_x();
		int posy = jeu.get_perso().get_pos_case_y();

		switch (c)
		{
        case 'q':
            if (jeu.get_salle().get_case(posy, posx - 1).get_type_char() == 'p')
            {
                jeu.zone_changer_salle('h');
                jeu.placer_perso_txt(15, 4);
            }
            else if (jeu.get_salle().get_case(posy, posx - 1).get_type_char() == 'n'
                    || jeu.get_salle().get_case(posy, posx - 1).get_type_char() == 'c')
            {
                jeu.deplacer_perso_txt('g');
            }
            break;
        case 'd':
            if (jeu.get_salle().get_case(posy, posx + 1).get_type_char() == 'p')
            {
                jeu.zone_changer_salle('b');
                jeu.placer_perso_txt(1, 4);
            }
            else if (jeu.get_salle().get_case(posy, posx + 1).get_type_char() == 'n'
                    || jeu.get_salle().get_case(posy, posx + 1).get_type_char() == 'c')
            {
                jeu.deplacer_perso_txt('d');
            }
            break;
        case 'z':
            if (jeu.get_salle().get_case(posy - 1, posx).get_type_char() == 'p')
            {
                jeu.zone_changer_salle('g');
                jeu.placer_perso_txt(8, 7);
            }
            else if (jeu.get_salle().get_case(posy - 1, posx).get_type_char() == 'n'
                    || jeu.get_salle().get_case(posy - 1, posx).get_type_char() == 'c')
            {
                jeu.deplacer_perso_txt('h');
            }
            break;
        case 's':
            if (jeu.get_salle().get_case(posy + 1, posx).get_type_char() == 'p')
            {
                jeu.zone_changer_salle('d');
                jeu.placer_perso_txt(8, 1);
            }
            else if (jeu.get_salle().get_case(posy + 1, posx).get_type_char() == 'n'
                    || jeu.get_salle().get_case(posy + 1, posx).get_type_char() == 'c')
            {
                jeu.deplacer_perso_txt('b');
            }
            break;
        case 'a':
            ok = false;
            break;
		}
        txtAff(win, jeu);
	} while (ok);
}
