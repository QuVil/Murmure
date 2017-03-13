#include <iostream>

using namespace std;

int main(int argc, char ** argv)
{
    cout   <<   "Boom na da noom na na nema " << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                <<   "Da boom na da noom na namena" << endl
                << "Go!" << endl;
        return 0;
}

/**
 * ouaiche, si t'as une erreur du style "truc/bidule mainTest.o : aucun fichier de ce type, vérifie bien que le dossier obj/test existe (sinon tu le créé)
 * le binaire qui va sortir c'est murmure_test_q
 * si tu veux rajouter d'autres fichier en plus, tu les créés dans le dossier test et tu les rajoutes bien dans le makefile (
 * ici : SRCS_TEST_Q = $(CORE) test/mainTest.cpp test/nouveaufichier1.cpp test/nouveaufichier.cpp ... etc
 * et tu as deja acces aux fichier qui se trouvent dans src/core
 */
