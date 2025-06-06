#include "Solver.hpp"
#include <unordered_set>
#include <map>

Solver::Solver(Board& board) : initialBoard(board) {}

std::string Solver::serialize(const Board& board) const {
    std::string state;
    for (const auto& row : board.getTiles()) {
        for (int tile : row) {
            state += std::to_string(tile) + ",";
        }
    }
    return state;
}

std::vector<char> Solver::solve() {
    std::queue<std::pair<Board, std::vector<char>>> q;
    std::unordered_set<std::string> visited;
    std::map<char, std::pair<int, int>> moves = {{'w', {-1, 0}}, {'s', {1, 0}}, {'a', {0, -1}}, {'d', {0, 1}}};

    q.push({initialBoard, {}});  
    visited.insert(serialize(initialBoard));

    while (!q.empty()) {
        auto [currentBoard, path] = q.front();
        q.pop();

        if (currentBoard.isSolved()) return path;

        for (auto [move, delta] : moves) {
            Board nextBoard = currentBoard;  
            if (nextBoard.moveTile(move)) {  
                std::string nextState = serialize(nextBoard);
                if (visited.find(nextState) == visited.end()) { 
                    visited.insert(nextState);
                    std::vector<char> newPath = path;
                    newPath.push_back(move);
                    q.push({nextBoard, newPath});
                }
            }
        }
    }
    return {}; 
}
