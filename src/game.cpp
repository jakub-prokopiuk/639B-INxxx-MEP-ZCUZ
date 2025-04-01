#include "game.hpp"
#include <iostream>
#include "solver.hpp"
#include <thread>
#include <chrono>
Game::Game(int size) : board(size) {
    do {
        board.shuffle();
    } while (!board.isSolvable());

    std::cout << "Puzzle is solvable. Let's start!\n";
}

void Game::run() {
    bool isCorrectMove = true;
    while (!board.isSolved()) {
        board.moveNumber(isCorrectMove);
        board.print();
        std::cout << "Enter move (w/s/a/d) or 'r' to solve automatically: ";
        char move = InputHandler::getUserInput();

        if (move == 'r') {
            Solver solver(board);
            std::vector<char> solution = solver.solve();
            std::cout << "Solving...\n";
            for (char m : solution) {
                isCorrectMove = board.moveTile(m);
                board.moveNumber(isCorrectMove);
                board.print();
                std::this_thread::sleep_for(std::chrono::milliseconds(300)); 
            }
            std::cout << "Your puzzle was solved automatically in " << board.getNumberOfMoves() - 1 << " moves.\n";
            return;
        }

        isCorrectMove = board.moveTile(move);
        std::system("clear");
    }
    std::cout << "Congratulations! Your puzzle was solved in " << board.getNumberOfMoves() -1 << " moves.\n";
}
