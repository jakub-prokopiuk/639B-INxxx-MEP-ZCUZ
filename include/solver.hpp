#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "board.hpp"
#include <queue>
#include <set>
#include <vector>

class Solver {
public:
    Solver(Board& board);
    std::vector<char> solve();

private:
    Board initialBoard;
    std::string serialize(const Board& board) const;
};

#endif
