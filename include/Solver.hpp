#pragma once

#include "Board.hpp"
#include "ISolver.hpp"
#include <queue>
#include <set>
#include <vector>

class Solver : public ISolver {
public:
    explicit Solver(Board& board);
    std::vector<char> solve() override;

protected:
    Board initialBoard;
    std::string serialize(const Board& board) const;
};
