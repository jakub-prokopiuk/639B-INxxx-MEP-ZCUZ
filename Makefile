TARGET = puzzle

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fPIC $(shell pkg-config --cflags Qt5Widgets)

INCLUDE_DIR = include

SRC = src/main.cpp src/Game.cpp src/Board.cpp src/InputHandler.cpp src/Solver.cpp src/BFSSolver.cpp src/Player.cpp src/PuzzleWindow.cpp src/moc_PuzzleWindow.cpp
OBJ = $(SRC:.cpp=.o)

LDFLAGS = $(shell pkg-config --libs Qt5Widgets)

MOC = moc
MOC_SRC = include/PuzzleWindow.hpp
MOC_OUT = src/moc_PuzzleWindow.cpp

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $(TARGET) $(OBJ) $(LDFLAGS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(MOC_OUT): $(MOC_SRC)
	$(MOC) -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET) $(MOC_OUT)

run: $(TARGET)
	./$(TARGET)
