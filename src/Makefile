# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++11
# Libraries to link (ncurses is mandatory)
LDFLAGS = -lncurses

# List of object files
OBJ = main.o GameEngine.o Maze.o Poteridis.o Malfoi.o MagicGem.o GameObject.o

# Target executable name
TARGET = babis_game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)