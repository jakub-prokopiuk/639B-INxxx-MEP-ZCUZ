/**
 * @brief Represents a sliding puzzle board.
 * 
 * This class defines the board of the sliding puzzle, including the grid of tiles,
 * the empty tile position, and methods for manipulating the board.
 */
 #pragma once

 #include <vector>
 #include <iostream>
 
 /**
  * @brief Represents the board of a sliding puzzle.
  * 
  * This class provides methods for manipulating the puzzle board, such as shuffling the tiles,
  * moving tiles, checking if the puzzle is solved, and printing the current board state.
  */
 class Board {
 private:
     std::vector<std::vector<int>> tiles; ///< The grid representing the puzzle tiles.
     int size; ///< The size of the board (e.g., 3x3, 4x4).
     int emptyRow, emptyCol; ///< The position of the empty tile on the board.
 
 public:
     /**
      * @brief Constructs a new Board object.
      * 
      * Initializes the board with a specified size.
      * 
      * @param size The size of the puzzle (e.g., 3 for a 3x3 board).
      */
     Board(int size);
 
     /**
      * @brief Shuffles the tiles on the board.
      * 
      * Randomly shuffles the tiles on the board to create a new puzzle configuration.
      */
     void shuffle();
 
     /**
      * @brief Moves a tile in a specified direction.
      * 
      * Moves a tile (up, down, left, right) on the board.
      * 
      * @param direction The direction to move the tile ('w', 's', 'a', 'd').
      * @return True if the move is valid and the tile is moved; false otherwise.
      */
     bool moveTile(char direction);
 
     /**
      * @brief Checks if the puzzle is solved.
      * 
      * Checks if the current board configuration matches the solved state.
      * 
      * @return True if the puzzle is solved; false otherwise.
      */
     bool isSolved() const;
 
     /**
      * @brief Prints the current board state.
      * 
      * Prints the board to the console.
      */
     void print() const;
 
     /**
      * @brief Makes a move on the board.
      * 
      * Moves a number on the board if it is the correct move.
      * 
      * @param isCorrectMove Whether the move is correct.
      */
     void moveNumber(bool isCorrectMove);
 
     /**
      * @brief Gets the tiles of the board.
      * 
      * Provides access to the board's tiles.
      * 
      * @return A reference to the 2D vector of board tiles.
      */
     const std::vector<std::vector<int>>& getTiles() const { return tiles; }
 
     /**
      * @brief Checks if the puzzle*
 