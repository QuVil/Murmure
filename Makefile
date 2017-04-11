CORE = core/Fichier.cpp core/CaseSalle.cpp core/Salle.cpp core/Zone.cpp core/Jeu.cpp core/ZoneGen.cpp core/Perso.cpp core/Modele.cpp core/SalleGen.cpp core/Coord2D.cpp core/VecteurM.cpp core/ModeleSalle.cpp core/Objet.cpp core/Ennemi.cpp core/Projectile.cpp core/Arme.cpp core/GestionSalle.cpp core/Menu.cpp core/Clef.cpp

SRCS_TXT = $(CORE) txt/mainTxt.cpp txt/JeuTxt.cpp txt/winTxt.cpp
FINAL_TARGET_TXT = murmure_txt

SRCS_TEST = $(CORE) testing/map_testing.cpp
FINAL_TARGET_TEST = murmure_test

SRCS_SFML = $(CORE) sfml/mainSFML.cpp sfml/JeuSFML.cpp sfml/CaseSFML.cpp sfml/CarteAffSFML.cpp sfml/TextureSFML.cpp sfml/PersoSFML.cpp sfml/SelecPersoSFML.cpp sfml/ProjectileSFML.cpp sfml/HitboxSFML.cpp sfml/EnnemiSFML.cpp sfml/MenuSFML.cpp sfml/ClefSFML.cpp
FINAL_TARGET_SFML = murmure_sfml

SRCS_GEN_TEST = $(CORE) testing/generation_tests.cpp
FINAL_TARGET_GEN_TEST = murmure_gen_test

SRCS_TEST_Q = $(CORE) test/mainTest.cpp
FINAL_TARGET_TEST_Q = murmure_test_q

SRCS_TEST_REG = $(CORE) test_regression/mainTESTREG.cpp
FINAL_TARGET_TEST_REG = murmure_test_regression

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SFML = 	-Ilib\SFML-2.4.2\SFML-2.4.2_Windows-MinGW-4.9.2\include
	LIBS_SFML = 	-Llib \
			-Llib\SFML-2.4.2\SFML-2.4.2_Windows-MinGW-4.9.2\lib \
			-lsfml-graphics -lsfml-window -lsfml-system
else
	INCLUDE_DIR_SFML = -Ilib/SFML-2.4.2/SFML-2.4.2_Linux-gcc-5.4.0/include
	LIBS_SFML = -Llib/SFML-2.4.2/SFML-2.4.2_Linux-gcc-5.4.0/lib \
				-lsfml-graphics -lsfml-window -lsfml-system
endif

CC					= g++
LD 					= g++
LDFLAGS  			=
CPPFLAGS 			= -Wall -ggdb   #-O2   # pour optimiser
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
INCLUDE_DIR			= -Isrc -Isrc/core -Isrc/txt -Isrc/sfml -Isrc/test

default: make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_TEST) $(BIN_DIR)/$(FINAL_TARGET_SFML) $(BIN_DIR)/$(FINAL_TARGET_GEN_TEST) $(BIN_DIR)/$(FINAL_TARGET_TEST_Q) $(BIN_DIR)/$(FINAL_TARGET_TEST_REG)

$(FINAL_TARGET_TXT) : make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT)

$(FINAL_TARGET_TEST) : make_dir $(BIN_DIR)/$(FINAL_TARGET_TEST)

$(FINAL_TARGET_SFML) : make_dir $(BIN_DIR)/$(FINAL_TARGET_SFML)

$(FINAL_TARGET_GEN_TEST) : make_dir $(BIN_DIR)/$(FINAL_TARGET_GEN_TEST)

$(FINAL_TARGET_TEST_Q) : make_dir $(BIN_DIR)/$(FINAL_TARGET_TEST_Q)

$(FINAL_TARGET_TEST_REG) : make_dir $(BIN_DIR)/$(FINAL_TARGET_TEST_REG)

make_dir:
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR) $(OBJ_DIR)\txt $(OBJ_DIR)\testing $(OBJ_DIR)\sfml $(OBJ_DIR)\test $(OBJ_DIR)\core $(OBJ_DIR)\test_regression
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR) $(OBJ_DIR)/txt $(OBJ_DIR)/testing $(OBJ_DIR)/sfml $(OBJ_DIR)/test $(OBJ_DIR)/core $(OBJ_DIR)/test_regression
	test -d $(BIN_DIR) || mkdir $(BIN_DIR)
endif

$(BIN_DIR)/$(FINAL_TARGET_TXT): $(SRCS_TXT:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

$(BIN_DIR)/$(FINAL_TARGET_TEST): $(SRCS_TEST:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

$(BIN_DIR)/$(FINAL_TARGET_GEN_TEST): $(SRCS_GEN_TEST:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

$(BIN_DIR)/$(FINAL_TARGET_TEST_Q): $(SRCS_TEST_Q:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

$(BIN_DIR)/$(FINAL_TARGET_TEST_REG): $(SRCS_TEST_REG:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SFML)

$(BIN_DIR)/$(FINAL_TARGET_SFML): $(SRCS_SFML:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SFML)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SFML) $(INCLUDE_DIR) $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR)\txt\*.o $(OBJ_DIR)\sfml\*.o $(OBJ_DIR)\core\*.o  $(OBJ_DIR)\test_regression\*.o $(BIN_DIR)\$(FINAL_TARGET_SFML).exe $(BIN_DIR)\$(FINAL_TARGET_GEN_TEST).exe $(BIN_DIR)\$(FINAL_TARGET_TXT).exe $(BIN_DIR)\$(FINAL_TARGET_TEST).exe $(BIN_DIR)\$(FINAL_TARGET_TEST_Q).exe $(BIN_DIR)\$(FINAL_TARGET_TEST_REG).exe
else
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SFML) $(BIN_DIR)/$(FINAL_TARGET_TEST) $(BIN_DIR)/$(FINAL_TARGET_GEN_TEST) $(BIN_DIR)/$(FINAL_TARGET_TEST_Q) $(BIN_DIR)/$(FINAL_TARGET_TEST_REG)
endif
