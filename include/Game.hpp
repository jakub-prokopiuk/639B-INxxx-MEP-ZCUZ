/**
 * @brief Represents the game logic for the sliding puzzle.
 * 
 * This class handles the game state, including managing the puzzle board, 
 * player interaction, and invoking the solver.
 */
 #pragma once

 #include "Board.hpp"
 #include "Solver.hpp"
 #include "Player.hpp"
 
 /**
  * @brief Game logic for the sliding puzzle.
  * 
  * This class manages the game state, including the board, player moves, and 
  * invokes the appropriate solver to solve the puzzle.
  */
 class Game {
 public:
     /**
      * @brief Constructs a new Game object.
      * 
      * Initializes the game with a specified board size and player name.
      * 
      * @param size The size of the puzzle board.
      * @param playerName The name of the player.
      */
     Game(int size, const std::string& playerName);
 
     /**
      * @brief Runs the game.
      * 
      * Starts the game loop, handling user input and game progression.
      */
     void run();
 
 private:
     Board board; ///< The puzzle board.
     Player player; ///< The player managing the game.
     
     /**
      * @brief Handles solver logic.
      * 
      * Uses the solver to compute the solution to the puzzle.
      */
     void handleSolver();
 
     /**
      * @brief Handles a move made by the player.
      * 
      * Processes a player's move and updates the game state accordingly.
      * 
      * @param move The direction of the move (e.g., 'w', 'a', 's', 'd').
      */
     void handleMove(char move);
 };
 