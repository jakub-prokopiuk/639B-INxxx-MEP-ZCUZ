/**
 * @brief Interface for sliding puzzle solvers.
 * 
 * This interface defines the contract for any class that will solve a sliding puzzle.
 * It ensures that solvers implement the `solve()` method.
 */
 #pragma once

 #include <vector>
 
 /**
  * @brief Interface for puzzle solvers.
  * 
  * This abstract class defines the required method for solving a sliding puzzle.
  * Specific solver algorithms (e.g., BFS, DFS) must implement this interface.
  */
 class ISolver {
 public:
     /**
      * @brief Solves the puzzle.
      * 
      * Solves the sliding puzzle and returns the sequence of moves to solve it.
      * 
      * @return A vector of characters representing the sequence of moves.
      */
     virtual std::vector<char> solve() = 0;
 
     /**
      * @brief Virtual destructor.
      * 
      * Ensures proper cleanup for derived classes.
      */
     virtual ~ISolver() = default;
 };
 