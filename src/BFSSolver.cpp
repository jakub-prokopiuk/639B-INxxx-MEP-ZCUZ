#include "BFSSolver.hpp"
#include <map>

BFSSolver::BFSSolver(Board& board) : Solver(board) {}

std::vector<char> BFSSolver::solve() {
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
