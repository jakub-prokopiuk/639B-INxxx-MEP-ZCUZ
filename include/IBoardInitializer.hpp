#pragma once

#include "board.hpp"

class IBoardInitializer {
public:
    virtual void initialize(Board& board) = 0;
    virtual ~IBoardInitializer() = default;
};
