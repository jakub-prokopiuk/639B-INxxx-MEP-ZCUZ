#pragma once
#include <vector>
#include <iostream>

class Board {
private:
    std::vector<std::vector<int>> tiles;
    int size;
    int emptyRow, emptyCol;

public:
    Board(int size);
    void shuffle();
    bool moveTile(char direction);
    bool isSolved() const;
    void print() const;
};
