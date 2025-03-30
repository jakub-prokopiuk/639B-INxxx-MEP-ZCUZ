#include "game.hpp"
#include <iostream>

Game::Game(int size) : board(size) {
    board.shuffle();
}

void Game::run() {
    while (!board.isSolved()) {
        board.print();
        char move = InputHandler::getUserInput();
        board.moveTile(move);
    }
    std::cout << "Congratulations! Puzzle solved.\n";
}
