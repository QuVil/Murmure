------------------------Murmure-------------------------
->détails :
Projet réalisé par :
VILLERMET Quentin (11507338) & SUBLET Gary (11506450)
 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _
/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
Le projet n'est pas présent sur la forge car il contient plusieurs fichiers de
plus de 1Mo, ce qui excède la limite de push sur la forge. Le repository se
trouve donc sur http://github.com/lilelvis98/Murmure et est resté en public -
Nous avons tenté d'écrire au support de github.com pour obtenir un repo étudiant
privé, sans succès.
 _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _
/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\

Le programme utilise la bibliothèque SFML, incluse dans le dossier lib.

->Pour compiler le programme :

	make clean

	make

	bin/murmure_sfml.sh

_Sous Windows :
C:/Program Files/CodeBlocks/MinGW/bin/mingw_32_make.exe - f Makefile "cible")

->Pour jouer : Z-Q-S-D pour se déplacer, tirer à la souris (clic droit et gauche
pour les 2 armes), ou à la manette, sticks gauche et droit pour bouger/tirer.

Le joueur peut se déplacer dans et entre les salles, tirer et tuer les ennemis,
prendre des dégâts et mourir, ramasser la clef du boss.
Les Zones et certaines salles sont générées procéduralement.

L'archive contient les dossiers suivants :
	-bin, avec les exécutables et les dll de bibliothèques externes
	-data, avec toutes les ressources imagées du projet
	-doc, contenant la documentation doxygen, l'UML et le GANTT
	-lib, où sont rangées les bibliothèques externes
	-obj, pour les fichiers objets
	-src, avec tout le code source du projet

