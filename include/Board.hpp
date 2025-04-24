/**
 * @brief Represents the sliding puzzle board.
 * 
 * This class defines the puzzle board for the sliding puzzle game. It handles
 * the puzzle tiles, supports tile movements, and checks whether the puzzle is solved.
 */
 #pragma once

 #include <vector>
 #include <iostream>
 
 /**
  * @brief Represents the puzzle board.
  * 
  * This class manages the tiles of the sliding puzzle. It supports shuffling,
  * moving tiles, checking if the puzzle is solved, and printing the board.
  */
 class Board {
 private:
     std::vector<std::vector<int>> tiles; ///< The 2D vector representing the puzzle tiles.
     int size; ///< The size of the board (e.g., 3x3, 4x4).
     int emptyRow, emptyCol; ///< The position of the empty tile.
 
 public:
     /**
      * @brief Constructs a new Board object.
      * 
      * Initializes a new puzzle board of a given size.
      * 
      * @param size The size of the puzzle board (e.g., 3 for a 3x3 board).
      */
     Board(int size);
 
     /**
      * @brief Shuffles the tiles on the board.
      * 
      * Randomizes the positions of the tiles on the board.
      */
     void shuffle();
 
     /**
      * @brief Moves a tile on the board.
      * 
      * Moves a tile in the specified direction if the move is valid.
      * 
      * @param direction The direction to move the tile ('w', 'a', 's', 'd').
      * @return true If the move was successful.
      * @return false If the move was not possible.
      */
     bool moveTile(char direction);
 
     /**
      * @brief Checks if the puzzle is solved.
      * 
      * Determines if the tiles are in the solved configuration.
      * 
      * @return true If the puzzle is solved.
      * @return false If the puzzle is not solved.
      */
     bool isSolved() const;
 
     /**
      * @brief Prints the current board configuration.
      * 
      * Displays the current state of the board in a readable format.
      */
     void print() const;
 
     /**
      * @brief Makes a move based on whether it is correct.
      * 
      * Updates the board and the move counter based on whether the move is correct.
      * 
      * @param isCorrectMove A flag indicating if the move is correct.
      */
     void moveNumber(bool isCorrectMove);
 
     /**
      * @brief Gets the tiles on the board.
      * 
      * Provides access to the board's tile configuration.
      * 
      * @return A constant reference to the 2D vector of tiles.
      */
     const std::vector<std::vector<int>>& getTiles() const { return tiles; }
 
     /**
      * @brief Checks if the puzzle is solvable.
      * 
      * Determines if the current puzzle configuration can be solved.
      * 
      * @return true If the puzzle is solvable.
      * @return false If the puzzle is unsolvable.
      */
     bool isSolvable() const;
 
     /**
      * @brief Gets the row index of the empty tile.
      * 
      * @return The row index of the empty tile.
      */
     int getEmptyRow() const { return emptyRow; }
 
     /**
      * @brief Gets the column index of the empty tile.
      * 
      * @return The column index of the empty tile.
      */
     int getEmptyCol() const { return emptyCol; }
 
     /**
      * @brief Gets the size of the board.
      * 
      * @return The size of the board (e.g., 3 for a 3x3 board).
      */
     int getSize() const { return size; }
 };
 