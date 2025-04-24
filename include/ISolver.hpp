/**
 * @brief Interface for puzzle solvers.
 * 
 * This interface defines the common functionality for puzzle solvers. It is
 * implemented by different solver strategies such as BFS or DFS.
 */
 #pragma once

 #include <vector>
 
 /**
  * @brief Interface for solving the puzzle.
  * 
  * This interface defines a method for solving the puzzle and retrieving the
  * sequence of moves required to solve it.
  */
 class ISolver {
 public:
     /**
      * @brief Solves the puzzle.
      * 
      * This method should be implemented by classes inheriting from ISolver to
      * solve the puzzle using a specific algorithm.
      * 
      * @return A vector of characters representing the sequence of moves (e.g., 'w', 'a', 's', 'd').
      */
     virtual std::vector<char> solve() = 0;
 
     /// Virtual destructor to allow proper cleanup in derived classes.
     virtual ~ISolver() = default;
 };
 