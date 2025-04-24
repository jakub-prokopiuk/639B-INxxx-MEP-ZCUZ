#pragma once

#include "Solver.hpp"
#include <queue>
#include <unordered_set>

class BFSSolver : public Solver {
public:
    BFSSolver(Board& board);
    std::vector<char> solve();

};
