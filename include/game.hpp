#pragma once
#include "board.hpp"
#include "inputhandler.hpp"

class Game {
private:
    Board board;
public:
    Game(int size);
    void run();
};
