#include "Board.hpp"
#include <algorithm>
#include <random>
#include <iostream>

Board::Board(int size) : size(size) {
    tiles.resize(size, std::vector<int>(size));
    int num = 1;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            tiles[i][j] = num++;
    tiles[size - 1][size - 1] = 0;
    emptyRow = size - 1;
    emptyCol = size - 1;
}

void Board::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());

    std::vector<int> flatTiles;
    for (const auto& row : tiles)
        flatTiles.insert(flatTiles.end(), row.begin(), row.end());

    std::shuffle(flatTiles.begin(), flatTiles.end(), g);

    int index = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tiles[i][j] = flatTiles[index++];
            if (tiles[i][j] == 0) {
                emptyRow = i;
                emptyCol = j;
            }
        }
    }
}

bool Board::isSolvable() const {
    std::vector<int> flatTiles;
    for (const auto& row : tiles) {
        for (int tile : row) {
            if (tile != 0) {
                flatTiles.push_back(tile);
            }
        }
    }

    int inversions = 0;
    for (size_t i = 0; i < flatTiles.size(); ++i) {
        for (size_t j = i + 1; j < flatTiles.size(); ++j) {
            if (flatTiles[i] > flatTiles[j]) {
                ++inversions;
            }
        }
    }

    return inversions % 2 == 0;
}

bool Board::moveTile(char direction) {
    int newRow = emptyRow;
    int newCol = emptyCol;

    switch (direction) {
        case 'w': newRow -= 1; break;
        case 's': newRow += 1; break;
        case 'a': newCol -= 1; break;
        case 'd': newCol += 1; break;
        default: return false;
    }

    if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
        std::swap(tiles[emptyRow][emptyCol], tiles[newRow][newCol]);
        emptyRow = newRow;
        emptyCol = newCol;
        return true;
    }

    return false;
}

bool Board::isSolved() const {
    int num = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == size - 1 && j == size - 1) {
                if (tiles[i][j] != 0) return false;
            } else {
                if (tiles[i][j] != num++) return false;
            }
        }
    }
    return true;
}

void Board::print() const {
    for (const auto& row : tiles) {
        for (int tile : row)
            std::cout << (tile ? std::to_string(tile) : "_") << " ";
        std::cout << "\n";
    }
}