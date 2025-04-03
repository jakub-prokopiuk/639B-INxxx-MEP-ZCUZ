#pragma once

#include "IBoardInitializer.hpp"
#include <random>

class RandomBoardInitializer : public IBoardInitializer {
public:
    void initialize(Board& board) override {
        do {
            board.shuffle();
        } while (!board.isSolvable());
    }
};
