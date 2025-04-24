#pragma once

#include <vector>

class ISolver {
public:
    virtual std::vector<char> solve() = 0;
    virtual ~ISolver() = default;
};
