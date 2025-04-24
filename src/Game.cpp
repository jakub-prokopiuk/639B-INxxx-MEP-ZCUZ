#include "Game.hpp"
#include <iostream>
#include <thread>
#include <chrono>

Game::Game(int size, const std::string& playerName) : board(size), player(playerName) {
    do {
        board.shuffle();
    } while (!board.isSolvable());

    std::cout << "Puzzle is solvable. Let's start, " << player.getName() << "!\n";
}

void Game::run() {
    while (!board.isSolved()) {
        board.print();
        std::cout << "Enter move (w/s/a/d) or 'r' to solve automatically: ";
        char move;
        std::cin >> move;

        if (move == 'r') {
            handleSolver();
            return;
        }

        handleMove(move);
    }

    std::cout << "Congratulations, " << player.getName() << "! You solved the puzzle in " 
              << player.getMoveCount() << " moves.\n";
}

void Game::handleMove(char move) {
    if (board.moveTile(move)) {
        player.incrementMoves();
        std::cout << "Move number: " << player.getMoveCount() << "\n";
    }
}

void Game::handleSolver() {
    Solver solver(board);
    std::vector<char> solution = solver.solve();
    
    std::cout << "Solving...\n";
    for (char m : solution) {
        board.moveTile(m);
        player.incrementMoves();
        board.print();
        std::cout << "Current move count: " << player.getMoveCount() << "\n";
        std::cout << "-------------------" << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    std::cout << "Puzzle solved in " << player.getMoveCount() << " moves.\n";
}
