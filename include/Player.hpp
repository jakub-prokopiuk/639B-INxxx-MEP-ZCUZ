/**
 * @brief Represents a player in the sliding puzzle game.
 * 
 * This class tracks the player's name and the number of moves made during the game.
 */
 #pragma once

 #include <string>
 
 /**
  * @brief Represents a player in the sliding puzzle game.
  * 
  * This class holds the player's name and move count, providing methods to update
  * and retrieve the player's information.
  */
 class Player {
 public:
     /**
      * @brief Constructs a new Player object.
      * 
      * Initializes the player with a specified name.
      * 
      * @param name The name of the player.
      */
     Player(const std::string& name);
 
     /**
      * @brief Increments the move counter.
      * 
      * Increments the number of moves made by the player.
      */
     void incrementMoves();
 
     /**
      * @brief Gets the number of moves made by the player.
      * 
      * @return The total number of moves made by the player.
      */
     int getMoveCount() const;
 
     /**
      * @brief Gets the name of the player.
      * 
      * @return The name of the player.
      */
     std::string getName() const;
 
 private:
     std::string name; ///< The player's name.
     int moveCount; ///< The number of moves made by the player.
 };
 