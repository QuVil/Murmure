--------------------------------------------------------------------------------
Les fichiers de configuration de ModeleSalle sont agencés comme suit :
	-des int, séparés par des espaces, pas de retour à la ligne.

->premier int : doit faire trois caractères, représente la difficulté voulue
(à peu près) pour la Salle à générer.

->ensuite, 20 int représentant les itérations à appliquer à la Salle :
	+1 : placer un ennemi (au hasard) --mieux vaut le faire après le reste
	+2 ou 3 : placer un amas -- doit être suivi d'un int entre 0 et 4 inclus,
		 	  déterminant la taille générale de l'amas. 2 place des rochers, 3 				  des trous.

une fois la série d'itérations voulue complète, on termine la série avec des 0.
Il est important de bien compléter jusqu'à avoir 21 int (sans compter le
premier), quitte à ajouter des neuf jusqu'à la fin -- il s'agit d'éviter les
SegFault--.


--------------------------------------------------------------------------------
exemple : 
080 2 0 2 1 3 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9

tentera de générer une Salle, de difficulté approximativement 80, avec un amas
de rochers de taille 0, un amas de rochers de taille 1, et un amas de trous de
taille 0.

Au bout d'un certain nombre de tentatives de générations, il est possible que
le modèle échoue. Ce nombre peut être réglé dans ModeleSalle.cpp -je crois.

Il est à noter que les portes et l'éventuelle clef, et la configuration générale
de la Salle, ne sont pas gérées par ce fichier de modèle, mais par le programme
ModeleSalle, qui prend ces paramètres depuis la Salle directement.
Pas d'inquiétude, tout est pris en charge automatiquement !

