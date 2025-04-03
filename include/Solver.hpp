#pragma once

#include "Board.hpp"
#include <queue>
#include <set>
#include <vector>

class Solver {
public:
    Solver(Board& board);
    std::vector<char> solve();

protected:
    Board initialBoard;
    std::string serialize(const Board& board) const;
};
