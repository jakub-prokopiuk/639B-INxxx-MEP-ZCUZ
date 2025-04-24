/**
 * @brief Solver for the sliding puzzle using Breadth-First Search (BFS).
 * 
 * This class provides an implementation of the BFS algorithm to solve the sliding puzzle.
 * It extends the `Solver` class and overrides the `solve()` method to provide the BFS-specific solution.
 */
 #pragma once

 #include "Solver.hpp"
 #include <queue>
 #include <unordered_set>
 
 /**
  * @brief Solver for the sliding puzzle using Breadth-First Search (BFS).
  * 
  * This class implements the BFS algorithm to find the shortest sequence of moves
  * to solve the sliding puzzle. It overrides the `solve()` method from the `Solver` class.
  */
 class BFSSolver : public Solver {
 public:
     /**
      * @brief Constructs a new BFSSolver object.
      * 
      * Initializes the BFS solver with the given puzzle board.
      * 
      * @param board The initial board configuration for the puzzle.
      */
     BFSSolver(Board& board);
 
     /**
      * @brief Solves the puzzle using the BFS algorithm.
      * 
      * This method implements the BFS algorithm to find the shortest path to solve the puzzle.
      * It returns the sequence of moves necessary to solve the puzzle.
      * 
      * @return A vector of characters representing the sequence of moves (e.g., 'w', 'a', 's', 'd').
      */
     std::vector<char> solve();
 };
 