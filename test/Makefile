CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -I../src

SRC = \
../src/model/Position.cpp \
../src/model/Amazon.cpp \
../src/model/Direction.cpp \
../src/model/player/Player.cpp \
../src/model/board/Board.cpp

TESTS = $(wildcard test_*.cpp)

TARGETS = $(TESTS:.cpp=)

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< $(SRC) -o $@

clean:
	rm -f $(TARGETS)