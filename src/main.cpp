#include "Game.hpp"
#include <iostream>

int main() {
    int size;
    std::string playerName;

    std::cout << "Enter board size (e.g., 3 for 3x3): ";
    std::cin >> size;

    std::cout << "Enter your name: ";
    std::cin >> playerName;

    Game game(size, playerName);
    game.run();

    return 0;
}
