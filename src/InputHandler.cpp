#include "InputHandler.hpp"
#include <iostream>

char InputHandler::getUserInput() {
    char move;
    std::cout << "Enter move (w/s/a/d): ";
    std::cin >> move;
    return move;
}
