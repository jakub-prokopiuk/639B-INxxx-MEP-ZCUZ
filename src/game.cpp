#include "game.hpp"
#include <iostream>

Game::Game(int size) : board(size) {
    board.shuffle();
}

void Game::run() {
    bool isCorrectMove = true;
    while (!board.isSolved()) {
        board.moveNumber(isCorrectMove);
        board.print();
        char move = InputHandler::getUserInput();
        isCorrectMove = board.moveTile(move);
        std::system("clear");
    }
    std::cout << "Congratulations! Puzzle solved.\n";
}
