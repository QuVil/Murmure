CORE = core/Fichier.cpp core/CaseSalle.cpp core/Salle.cpp core/Jeu.cpp core/ZoneGen.cpp core/Perso.cpp core/Model.cpp

SRCS_TXT = $(CORE) txt/mainTxt.cpp
FINAL_TARGET_TXT = murmure_txt

SRCS_TEST = $(CORE) testing/map_testing.cpp
FINAL_TARGET_TEST = murmure_test

SRCS_SFML = $(CORE) sfml/mainSFML.cpp sfml/JeuSFML.cpp sfml/CaseSFML.cpp
FINAL_TARGET_SFML = murmure_sfml

SRCS_GEN_TEST = $(CORE) testing/generation_tests.cpp
FINAL_TARGET_GEN_TEST = murmure_gen_test

SRCS_TEST_Q = $(CORE) test/mainTest.cpp
FINAL_TARGET_TEST_Q = murmure_test_q

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SFML = 	-Ilib\SFML-2.4.2\SFLM-2.4.2_Windows-MinGW-6.1.0\include
	LIBS_SFML = 	-Llib \
			-Llib\SFML-2.4.2\SFLM-2.4.2_Windows-MinGW-6.1.0\lib \
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

default: make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_TEST) $(BIN_DIR)/$(FINAL_TARGET_SFML) $(BIN_DIR)/$(FINAL_TARGET_GEN_TEST) $(BIN_DIR)/$(FINAL_TARGET_TEST_Q)

$(FINAL_TARGET_TXT) : make_dir $(BIN_DIR)/$(FINAL_TARGET_TXT)

$(FINAL_TARGET_TEST) : make_dir $(BIN_DIR)/$(FINAL_TARGET_TEST)

$(FINAL_TARGET_SFML) : make_dir $(BIN_DIR)/$(FINAL_TARGET_SFML)

$(FINAL_TARGET_GEN_TEST) : make_dir $(BIN_DIR)/$(FINAL_TARGET_GEN_TEST)

$(FINAL_TARGET_TEST_Q) : make_dir $(BIN_DIR)/$(FINAL_TARGET_TEST_Q)

make_dir:
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR) $(OBJ_DIR)\txt $(OBJ_DIR)\testing $(OBJ_DIR)\sfml $(OBJ_DIR)\test $(OBJ_DIR)\core
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR) $(OBJ_DIR)/txt $(OBJ_DIR)/testing $(OBJ_DIR)/sfml $(OBJ_DIR)/test $(OBJ_DIR)/core
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

$(BIN_DIR)/$(FINAL_TARGET_SFML): $(SRCS_SFML:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIBS_SFML)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_SFML) $(INCLUDE_DIR) $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR)\txt\*.o $(OBJ_DIR)\core\*.o $(BIN_DIR)\$(FINAL_TARGET_SFML).exe $(BIN_DIR)\$(FINAL_TARGET_GEN_TEST).exe $(BIN_DIR)\$(FINAL_TARGET_TXT).exe $(BIN_DIR)\$(FINAL_TARGET_TEST).exe $(BIN_DIR)\$(FINAL_TARGET_TEST_Q).exe
else
	rm -rf $(OBJ_DIR) $(BIN_DIR)/$(FINAL_TARGET_TXT) $(BIN_DIR)/$(FINAL_TARGET_SFML) $(BIN_DIR)/$(FINAL_TARGET_TEST) $(BIN_DIR)/$(FINAL_TARGET_GEN_TEST) $(BIN_DIR)/$(FINAL_TARGET_TEST_Q)
endif
