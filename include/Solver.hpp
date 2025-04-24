/**
 * @brief Base class for solving the sliding puzzle.
 * 
 * This class provides the common functionality for solving the sliding puzzle.
 * It is an abstract class that can be extended by specific solver algorithms
 * such as BFS or DFS.
 */
 #pragma once

 #include "Board.hpp"
 #include "ISolver.hpp"
 #include <queue>
 #include <set>
 #include <vector>
 
 /**
  * @brief Base class for solving the sliding puzzle.
  * 
  * This class provides common methods for solving the sliding puzzle, including
  * a method to serialize the board. It implements the `ISolver` interface.
  */
 class Solver : public ISolver {
 public:
     /**
      * @brief Constructs a new Solver object.
      * 
      * Initializes the solver with a given puzzle board.
      * 
      * @param board The initial board configuration for the puzzle.
      */
     explicit Solver(Board& board);
 
     /**
      * @brief Solves the puzzle.
      * 
      * This method solves the sliding puzzle using a specific algorithm (e.g., BFS or DFS).
      * It returns the sequence of moves necessary to solve the puzzle.
      * 
      * @return A vector of characters representing the sequence of moves (e.g., 'w', 'a', 's', 'd').
      */
     std::vector<char> solve() override;
 
 protected:
     Board initialBoard; ///< The initial board configuration.
 
     /**
      * @brief Serializes the board into a string.
      * 
      * Converts the current state of the board into a string representation
      * that can be used for comparison or storage.
      * 
      * @param board The board to serialize.
      * @return A string representation of the board.
      */
     std::string serialize(const Board& board) const;
 };
 