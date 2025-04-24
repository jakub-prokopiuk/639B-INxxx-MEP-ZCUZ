#pragma once

#include <string>

class Player {
public:
    Player(const std::string& name);

    void incrementMoves();
    int getNumberOfMoves() const;
    std::string getName() const;

private:
    std::string name;
    int moveCount;
};
