TARGET = puzzle

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

INCLUDE_DIR = include

SRC = src/main.cpp src/game.cpp src/board.cpp src/inputhandler.cpp src/solver.cpp

OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $(TARGET) $(OBJ)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)
