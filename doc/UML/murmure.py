class CaseSalle :
	def __init__(self) :
		self.type = None # int
		pass
	def CaseSalle (self) :
		# returns constructor
		pass
	def CaseSalle (self, t) :
		# returns constructor
		pass
	def operator = (self, c) :
		# returns CaseSalle
		pass
	def get_type (self) :
		# returns int
		pass
	def get_type_string (self) :
		# returns string
		pass
	def set_type (self, t) :
		# returns int
		pass
	def  (self) :
		# returns 
		pass
class Fichier :
	def __init__(self) :
		self.chemin = None # string
		self.index_file = None # string
		pass
	def Fichier (self) :
		# returns constructor
		pass
	def creation_index (self) :
		# returns void
		pass
	def charger (self, s) :
		# returns void
		pass
	def charger (self, z) :
		# returns void
		pass
	def charger (self, z) :
		""" 	 """
		# returns void
		pass
	def charger (self, p) :
		# returns void
		pass
	def charger (self, a) :
		# returns void
		pass
	def charger (self, s) :
		# returns void
		pass
	def charger (self, e) :
		# returns void
		pass
class TextureSFML :
	'''(NULL)'''
	def __init__(self) :
		self.normal_CaseSFML = None # Texture
		self.herbe = None # Texture[9]
		self.sol = None # Texture|9]
		self.defaut = None # Texture
		self.mur_1 = None # Texture[8]
		self.trou = None # Texture
		self.porte = None # Texture|4]
		self.rocher = None # Texture
		self.actuel = None # Texture
		self.boss = None # Texture
		self.clef = None # Texture
		self.depart = None # Texture
		self.normal = None # Texture
		self.objet = None # Texture
		self.vide = None # Texture
		self.perso = None # Texture
		self.curseur = None # Texture
		self.proj = None # Texture[8]
		self.ennemi_1 = None # Texture
		self.clef_boss = None # Texture
		self.menu_principal = None # Texture
		self.curseur_menu = None # Texture
		pass
	def charger_textures_caseSFML (self) :
		# returns void
		pass
	def charger_textures_carteAffSFML (self) :
		# returns void
		pass
	def charger_textures_perso (self) :
		# returns void
		pass
	def charger_textures_curseur (self) :
		# returns void
		pass
	def charger_textures_projectile (self) :
		# returns void
		pass
	def charger_textures_ennemi (self) :
		# returns void
		pass
	def charger_textures_clef (self) :
		# returns void
		pass
	def charger_textures_menu_princpal (self) :
		# returns void
		pass
	def charger_textures_menu (self) :
		# returns void
		pass
	def retourne_texture_curseur (self) :
		# returns Texture
		pass
	def retourne_texture_perso (self) :
		# returns Texure
		pass
	def retourne_texture_caseSFML (self, type, i, j) :
		# returns Texture
		pass
	def retourne_texture_carteAffSFML (self, config, case_act) :
		# returns Texture
		pass
	def retourne_texture_projectile (self, id) :
		# returns Texture
		pass
	def retourne_texture_ennemi (self) :
		# returns Texture
		pass
	def retourne_texture_clef (self) :
		# returns Texture
		pass
	def retourne_texture_menu (self) :
		# returns Texture
		pass
	def retourne_texture_curseur_menu (self) :
		# returns Texture
		pass
class Zone (Modele, Salle, Fichier) :
	def __init__(self) :
		self.carte = None # Salle[11][11]
		self.niveau_zone = None # int
		self.salle_actuelle_x = None # int
		self.salle_actuelle_y = None # int
		pass
	def Zone (self) :
		# returns constructor
		pass
	def Zone (self, posx, posy, niv) :
		# returns constructor
		pass
	def Zone (self, z) :
		# returns constructor
		pass
	def get_salle (self, x, y) :
		# returns Salle
		pass
	def get_salle (self) :
		# returns Salle
		pass
	def set_salle (self, x, y, nouvelle_salle) :
		# returns void
		pass
	def get_salle_actuelle_x (self) :
		# returns int
		pass
	def get_salle_actuelle_y (self) :
		# returns int
		pass
	def remplir_salle (self, x, y) :
		# returns void
		pass
	def remplir_salle (self) :
		# returns void
		pass
	def vider_salle (self, x, y) :
		# returns void
		pass
	def vider_salle (self) :
		# returns void
		pass
class Jeu (GestionSalle, Perso, Zone) :
	def __init__(self) :
		self.zone = None # Zone
		self.perso = None # Perso
		self.salle_actuelle = None # GestionSalle
		pass
	def Jeu (self) :
		# returns constructor
		pass
	def get_salle_actuelle (self) :
		# returns Salle*
		pass
	def get_zone (self) :
		# returns Zone
		pass
	def get_perso (self) :
		# returns Perso
		pass
	def grille_largeur (self) :
		# returns int
		pass
	def grille_hauteur (self) :
		# returns int
		pass
	def change_perso (self, nom) :
		# returns void
		pass
	def deplacer_perso (self, x, y) :
		# returns void
		pass
	def definir_position_perso (self, x, y) :
		# returns void
		pass
	def definir_orientation_perso (self, v) :
		# returns void
		pass
	def zone_changer_salle (self, c, devmode) :
		# returns bool
		pass
	def ajouter_projectile_perso (self, arme) :
		# returns void
		pass
	def avancer_jeu (self, vitesse_base, taille_cases) :
		# returns void
		pass
	def retourne_projectiles (self) :
		# returns list*
		pass
	def retourne_ennemis (self) :
		# returns list*
		pass
	def retourne_perso (self) :
		# returns Perso*
		pass
	def deplace_ennemis (self) :
		# returns void
		pass
	def retourne_clef (self) :
		# returns Clef*
		pass
	def initialiser_jeu (self, nom_perso, niveau) :
		# returns void
		pass
class GestionSalle :
	def __init__(self) :
		self.ennemis = None # list
		self.projectiles = None # list
		self.clef = None # Clef
		self.taille_case = None # int
		self.salle_actuelle_jeu = None # Salle *
		self.salle_actuelle_pointee = None # bool
		pass
	def ajouter_projectile (self, p) :
		# returns void
		pass
	def mise_a_jour_projectiles (self, vitesse_frame) :
		# returns void
		pass
	def get_projectiles (self) :
		# returns list*
		pass
	def get_ennemis (self) :
		# returns list*
		pass
	def get_clef (self) :
		# returns Clef*
		pass
	def salle_terminee (self) :
		# returns bool
		pass
	def initialise_salle_actuelle (self, adresse_salle) :
		# returns void
		pass
	def get_salle (self) :
		# returns Salle*
		pass
	def vider_projectiles (self) :
		# returns void
		pass
	def vide_ennemis (self) :
		# returns void
		pass
	def vider_clef (self) :
		# returns void
		pass
	def deplacer_ennemis (self, pos_perso, vitesse_frame) :
		# returns void
		pass
	def maj_changement_salle (self) :
		# returns void
		pass
class Arme (Projectile, Fichier) :
	def __init__(self) :
		self.nom = None # string
		self.degat = None # int
		self.nb_munition_total = None # int
		self.nb_munition_actuel = None # int
		pass
	def Arme (self) :
		# returns constructor
		pass
	def tirer (self, i) :
		# returns void
		pass
	def get_degat (self) :
		# returns int
		pass
	def get_munition_actuelle (self) :
		# returns void
		pass
	def get_munitions_total (self) :
		# returns 
		pass
	def get_munition_actuel (self) :
		# returns void
		pass
	def get_nom (self) :
		# returns void
		pass
class Salle (ModeleSalle, CaseSalle, Ennemi, Fichier, SalleGen) :
	def __init__(self) :
		self.grille = None # CaseSalle[nb_cases_largeur][nb_cases_hauteur]
		self.config = None # int
		self.difficulte = None # int
		pass
	def Salle (self) :
		# returns constructor
		pass
	def Salle (self, conf) :
		# returns constructor
		pass
	def get_salle (self, i, j) :
		# returns CaseSalle
		pass
	def set_case (self, i, j, c) :
		# returns void
		pass
	def get_config (self) :
		# returns int
		pass
	def set_config (self, c) :
		# returns int
		pass
	def remplir (self) :
		# returns void
		pass
	def vider (self) :
		# returns void
		pass
	def operator = (self, salle2) :
		# returns Salle
		pass
	def afficher (self) :
		# returns void
		pass
	def get_nb_cases_largeur (self) :
		# returns int
		pass
	def get_nb_cases_hauteur (self) :
		# returns int
		pass
	def creer_ennemi (self, nombre) :
		# returns void
		pass
class SalleGen (Fichier) :
	'''(NULL)'''
	def __init__(self) :
		self.grille = None # int[nb_cases_largeur][nb_cases_hauteur]
		self.grille_validation = None # char[9][17]
		self.p_haut = None # bool
		self.p_bas = None # bool
		self.p_gauche = None # 
		self.p_droite = None # 
		self.config = None # int
		self.difficulte_approx = None # int
		self.difficulte_voulue = None # int
		self.valide = None # bool
		pass
	def SalleGen (self) :
		# returns constructor
		pass
	def intitialisation_gen (self) :
		# returns void
		pass
	def afficher_tests (self) :
		# returns void
		pass
	def placer_clef (self) :
		# returns void
		pass
	def placer_amas (self, type, taille) :
		# returns void
		pass
	def valider (self) :
		# returns void
		pass
	def afficher_validation (self) :
		# returns void
		pass
	def placer_ennemis (self) :
		# returns void
		pass
	def calculer_disance (self, x_dep, y_dep, x_arr, y_arr) :
		# returns int
		pass
	def calculer_distance_porte (self, x, y) :
		# returns int
		pass
	def calculer_difficulte (self) :
		# returns void
		pass
	def vider_salle (self) :
		# returns void
		pass
	def placer_portes (self, h, b, g, d) :
		# returns void
		pass
class Modele (ZoneGen) :
	'''(NULL)'''
	def __init__(self) :
		self.generateur = None # ZoneGen
		self.tableau_modele = None # int[23]
		pass
	def Modele (self) :
		# returns constructor
		pass
	def Modele (self, nom) :
		# returns constructor
		pass
	def generer_zone (self) :
		# returns void
		pass
	def afficher_tests (self) :
		# returns void
		pass
	def set_tableau_modele_i (self, x, i) :
		# returns void
		pass
class ModeleSalle (SalleGen) :
	'''(NULL)'''
	def __init__(self) :
		self.generateur = None # SalleGen
		self.tableau_modele = None # int[22]
		pass
	def ModeleSalle (self) :
		# returns constructor
		pass
	def ModeleSalle (self, nom) :
		# returns constructor
		pass
	def generer_salle (self, p_h, p_b, p_g, p_d, conf) :
		# returns void
		pass
	def afficher_tests (self) :
		# returns void
		pass
	def set_tableau_modele_i (self, x, i) :
		# returns void
		pass
class ProjectileSMFL (Projectile) :
	def __init__(self) :
		self.projectilesfml = None # Sprite
		self.projectile = None # Projectile *
		pass
	def ProjectileSMFL (self) :
		# returns constructor
		pass
	def init (self, texture, taille_cases) :
		# returns void
		pass
	def mise_a_jour_position (self) :
		# returns void
		pass
class EnnemiSFML (Ennemi) :
	def __init__(self) :
		self.ennemisfml = None # Sprite
		self.ennemi = None # Ennemi*
		pass
class Perso (Arme, Fichier) :
	def __init__(self) :
		self.nom = None # string
		self.angle_regard = None # float
		self.vitesse = None # float
		self.angle_mouvement = None # float
		self.pos_x = None # float
		self.pos_y = None # float
		self.pv_max = None # float
		self.pv_actuel = None # float
		self.arme1 = None # Arme
		self.arme2 = None # Arme
		pass
	def Perso (self) :
		# returns constructor
		pass
	def Perso (self, s) :
		# returns constructor
		pass
	def get_nom (self) :
		# returns string
		pass
	def get_angle_regard (self) :
		# returns float
		pass
	def get_vitesse (self) :
		# returns float
		pass
	def get_angle_mouvement (self) :
		# returns float
		pass
	def get_posx (self) :
		# returns float
		pass
	def get_posy (self) :
		# returns float
		pass
	def get_pv_max (self) :
		# returns float
		pass
	def get_pv_actuel (self) :
		# returns float
		pass
	def deplacement (self, x, y) :
		# returns void
		pass
	def rotation (self, x, y) :
		# returns void
		pass
	def tirer1 (self) :
		# returns void
		pass
	def tirer2 (self) :
		# returns void
		pass
class Projectile :
	def __init__(self) :
		self.collision = None # bool
		self.id_projectile = None # int
		self.type = None # int
		self.degat = None # float
		self.vitesse = None # float
		self.taille_projectile = None # float
		self.angle_orientation = None # 
		self.orientation = None # VecteurM
		self.position = None # Coord2D
		pass
	def avancer (self, vitesse_frame) :
		# returns void
		pass
	def Projectile (self, id, type, degat, vitesse, taille, orientation, position) :
		# returns constructor
		pass
class HitboxSFML :
	'''(NULL)'''
	def __init__(self) :
		pass
	def perso_et_salle (self, perso, casesalle, jeu, taille_case, x0, y0) :
		# returns void
		pass
	def projectiles_et_salle (self, projectiles, casesalle) :
		# returns void
		pass
	def projectiles_et_ennemis (self, projectiles, ennemis) :
		# returns void
		pass
	def ennemis_et_salle (self, ennemis, casesalle) :
		# returns void
		pass
	def perso_et_clef (self, perso, clef) :
		# returns void
		pass
	def perso_et_ennemis (self, perso, ennemis) :
		# returns void
		pass
class ZoneGen (Fichier) :
	def __init__(self) :
		self.carte = None # int[11][11]
		self.patterne = None # string
		self.methode = None # string
		self.pret_iteration = None # bool
		self.valide = None # bool
		self.posx_dep = None # int
		self.posy_dep = None # int
		pass
	def ZoneGen (self) :
		# returns constructor
		pass
	def ZoneGen (self, pat, met) :
		""" 	 """
		# returns constructor
		pass
	def get_etat (self, x, y) :
		# returns int
		pass
	def get_posx_dep (self) :
		# returns int
		pass
	def get_posy_dep (self) :
		# returns int
		pass
	def nb_cases (self) :
		# returns int
		pass
	def initialisation_gen (self, pat, met) :
		# returns void
		pass
	def iterer (self, met) :
		# returns void
		pass
	def get_patterne (self) :
		# returns string
		pass
	def set_salle (self, i, j, salle) :
		# returns void
		pass
	def valider (self) :
		# returns void
		pass
class JeuSFML (Jeu, CarteSFML, ProjectileSMFL, EnnemiSFML, CasesSFML, PersoSFML, TextureSFML, HitboxSFML) :
	def __init__(self) :
		self.window = None # RenderWindow
		self.desktop = None # VideoMode
		self.scale_salle_largeur = None # int
		self.scale_salle_hauteur = None # int
		self.posx0_salle = None # int
		self.posy0_salle = None # int
		self.jeu = None # Jeu
		self.textures = None # TextureSFML
		self.projectilesSFML = None # list
		self.ennemiSFML = None # list
		self.clefsfml = None # ClefSFML
		self.persosfml = None # PersoSFML
		self.menusfml = None # MenuSFML
		self.buffer = None # RenderTexture
		self.clock = None # Clock
		self.temps_frame = None # Time
		pass
	def JeuSFML (self) :
		# returns constructor
		pass
	def ~JeuSFML() (self) :
		# returns destructor
		pass
	def init (self) :
		# returns void
		pass
	def SFML_boucle (self) :
		# returns void
		pass
	def recupere_mouvements (self) :
		# returns void
		pass
	def recupere_mouvements_menu (self) :
		# returns void
		pass
	def recupere_collisions (self) :
		# returns void
		pass
	def avancer_jeu (self) :
		# returns void
		pass
	def afficher (self) :
		# returns void
		pass
	def init_curseur (self) :
		# returns void
		pass
	def init_persoSFML (self) :
		# returns void
		pass
	def init_caseSFML (self) :
		# returns void
		pass
	def init_carteAffSFML (self) :
		# returns void
		pass
	def init_projectileSFML (self) :
		# returns void
		pass
	def init_ennemiSFML (self) :
		# returns void
		pass
	def init_clefSFML (self) :
		# returns void
		pass
	def init_texte (self) :
		# returns void
		pass
	def init_menuSFML (self) :
		# returns void
		pass
	def dessiner_curseur (self) :
		# returns void
		pass
	def dessiner_salle (self) :
		# returns void
		pass
	def dessiner_carte (self) :
		# returns void
		pass
	def dessiner_perso (self) :
		# returns void
		pass
	def dessiner_projectiles (self) :
		# returns void
		pass
	def dessiner_perso (self) :
		# returns void
		pass
	def dessiner_ennemis (self) :
		# returns void
		pass
	def dessiner_clef (self) :
		# returns void
		pass
	def ecrire_texte (self) :
		# returns void
		pass
	def dessiner_menu (self) :
		# returns void
		pass
	def actualiser_salle (self) :
		# returns void
		pass
	def actualiser_ennemis (self) :
		# returns void
		pass
	def actualiser_clef (self) :
		# returns void
		pass
	def actualiser_perso (self) :
		# returns void
		pass
	def actualiser_projectiles (self) :
		# returns void
		pass
class CarteSFML :
	def __init__(self) :
		self.sallesfml = None # VertexArray
		self.texture = None # Texture
		self.states = None # RenderStates
		pass
	def CarteSFML (self) :
		# returns constructor
		pass
	def CarteSFML (self, posX, posY, hauteur, largeur, type) :
		# returns constructor
		pass
	def get_sallesfml (self) :
		# returns VertexArray
		pass
	def get_texture (self) :
		# returns Texture
		pass
	def get_states (self) :
		# returns RenderStates
		pass
class PersoSFML (Perso) :
	def __init__(self) :
		self.persosfml = None # Sprite
		self.perso = None # Perso*
		pass
	def PersoSFML (self) :
		# returns constructor
		pass
	def init (self, texture, posY, ) :
		# returns constructor
		pass
class Ennemi (Fichier) :
	def __init__(self) :
		self.niveau = None # int
		self.type = None # int
		self.arme = None # Arme
		self.pv_max = None # float
		self.pv_actuel = None # float
		self.pos_x = None # float
		self.pos_y = None # float
		self.case_x_apparition = None # int
		self.case_y_apparition = None # int
		pass
	def Ennemi (self) :
		# returns constructor
		pass
	def get_pos_x (self) :
		# returns float
		pass
	def get_pos_y (self) :
		# returns float
		pass
	def get_pv_max (self) :
		# returns float
		pass
	def get_pv_actuel (self) :
		# returns float
		pass
	def get_type (self) :
		# returns int
		pass
	def get_arme (self) :
		# returns Arme
		pass
class CasesSFML :
	def __init__(self) :
		self.casesfml = None # VertexArray
		self.texture = None # Texture
		self.states = None # RenderStates
		pass
	def CaseSFML (self) :
		# returns constructor
		pass
	def CaseSFML (self, posX, posY, largeur, hauteur, type) :
		# returns constructor
		pass
	def get_casesfml (self) :
		# returns VertexArray
		pass
	def get_texture (self) :
		# returns Texture
		pass
	def get_states (self) :
		# returns RenderStates
		pass
