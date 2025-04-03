TARGET = puzzle

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

INCLUDE_DIR = include

SRC = src/main.cpp src/Game.cpp src/Board.cpp src/InputHandler.cpp src/Solver.cpp src/BFSSolver.cpp src/Player.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $(TARGET) $(OBJ)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) $(DEP)

run: $(TARGET)
	./$(TARGET)
