# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++17 -Wall -Wextra -I../include

# Dossiers
SRC_DIR = ../src
TEST_DIR = .

# Fichiers sources du projet
SRC = $(SRC_DIR)/Position.cpp \
      $(SRC_DIR)/Board.cpp \
      $(SRC_DIR)/Player.cpp \
      $(SRC_DIR)/Direction.cpp \
      $(SRC_DIR)/Amazon.cpp

# Tous les fichiers de test
TESTS = $(wildcard $(TEST_DIR)/test_*.cpp)

# Noms des exécutables
TARGETS = $(TESTS:.cpp=)

# Règle principale
all: $(TARGETS)

# Compilation de chaque test
%: %.cpp $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Nettoyage
clean:
	rm -f $(TARGETS)