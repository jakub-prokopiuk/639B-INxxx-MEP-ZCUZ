/**
 * @brief BFS Solver for the puzzle game.
 * 
 * This class implements the BFS algorithm to solve the sliding puzzle game.
 * It inherits from the `Solver` class and overrides the `solve()` method.
 */
 #pragma once

 #include "Solver.hpp"
 #include <queue>
 #include <unordered_set>
 
 /**
  * @brief BFS solver for the puzzle.
  * 
  * This class uses the Breadth-First Search (BFS) algorithm to solve the sliding
  * puzzle. It extends the `Solver` class and implements the `solve()` method.
  */
 class BFSSolver : public Solver {
 public:
     /**
      * @brief Constructs a BFS solver.
      * 
      * Initializes the BFS solver with the given initial puzzle board.
      * 
      * @param board The initial puzzle board.
      */
     BFSSolver(Board& board);
 
     /**
      * @brief Solves the puzzle using BFS.
      * 
      * Solves the sliding puzzle using the BFS algorithm and returns the
      * sequence of moves required to reach the solution.
      * 
      * @return A vector of characters representing the sequence of moves (e.g., 'w', 'a', 's', 'd').
      */
     std::vector<char> solve() override;
 };
 