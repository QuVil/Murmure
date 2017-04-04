--------------------------------------------------------------------------------
Les fichiers de configuration de Modele sont agencés comme suit :
	-des int, séparés par des espaces, pas de retour à la ligne.

->premier et deuxième int : doivent faire 2 caractères, représentent le nombre
minimum et maximum de salles dans la Zone respectivement.

->3e int : le patterne de base pour la Zone :
	+1 : croix
	+2 : carré
	+3 : vide
	+4 : en forme de h
	+5 : hub

->ensuite, 20 int représentant les itérations à appliquer au patterne de base :
	+1 : voisins
	+2 : bruit_neg
	+3 : bruit_pos
	+4 : aleatoire
	+5 : epuration
	+6 : extension
une fois la série d'itérations voulue complète, on termine la série avec des 0.
Il est important de bien compléter jusqu'à avoir 20 int (sans compter les 3
premiers), quitte à ajouter des zéros jusqu'à la fin -- il s'agit d'éviter les
SegFault--.

--------------------------------------------------------------------------------
exemple : 
20 70 4 1 1 1 1 1 5 4 4 5 6 0 0 0 0 0 0 0 0 0 0

tentera de générer une Zone avec entre 20 et 70 salles, partant d'un patterne
en H et suivant les itérations suivantes :
voisins, voisins, voisins, voisins, voisins, epuration, aleatoire, aleatoire,
epuration, extension.

Au bout d'un certain nombre de tentatives de générations, il est possible que
le modèle échoue. Ce nombre peut être réglé dans Modele.cpp -je crois.
Cependant, il est peu probable que le Modele échoue, à moins que les conditions
de la génération soient irréalistes (par exemple une Zone comprenant entre 1 et
3 Salles mais itérant 5 fois sur le Modele.
Pour créer de nouveaux modèles, vous pouvez vous baser sur ceux déjà existants.

