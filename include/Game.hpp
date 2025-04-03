#pragma once

#include "Board.hpp"
#include "Solver.hpp"
#include "Player.hpp"

class Game {
public:
    Game(int size, const std::string& playerName);
    void run();

private:
    Board board;
    Player player;
    void handleSolver();
    void handleMove(char move);
};
