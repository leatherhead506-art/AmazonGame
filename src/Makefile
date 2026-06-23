CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

TARGET = main
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
# SOURCES
SRC = main.cpp \
      controller/GUIController.cpp \
      controller/TerminalController.cpp \
      model/Amazon.cpp \
      model/Direction.cpp \
      model/Position.cpp \
      model/player/Player.cpp \
      model/board/Board.cpp

# OBJECTS (dans un dossier build propre)
OBJ = $(SRC:.cpp=.o)

# BUILD
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all

.PHONY: all clean re