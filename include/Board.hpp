#pragma once
#include <vector>
#include <iostream>

class Board {
private:
    std::vector<std::vector<int>> tiles;
    int size;
    int emptyRow, emptyCol;
    int numberOfMoves;

public:
    Board(int size);
    void shuffle();
    bool moveTile(char direction);
    bool isSolved() const;
    void print() const;
    void moveNumber(bool isCorrectMove);
    const std::vector<std::vector<int>>& getTiles() const { return tiles; }
    int getNumberOfMoves() const { return numberOfMoves; }
    bool isSolvable() const;
    int getEmptyRow() const { return emptyRow; }
    int getEmptyCol() const { return emptyCol; }
    int getMoveCount() const { return numberOfMoves; }
    int getSize() const { return size; }
};
