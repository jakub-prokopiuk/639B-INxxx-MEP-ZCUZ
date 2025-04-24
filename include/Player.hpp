/**
 * @brief Represents a player in the puzzle game.
 * 
 * This class keeps track of the player's name and the number of moves made
 * during the game.
 */
 #pragma once

 #include <string>
 
 /**
  * @brief Represents a player.
  * 
  * The player has a name and a move count. The class provides methods to
  * track the number of moves the player has made.
  */
 class Player {
 public:
     /**
      * @brief Constructs a new Player object.
      * 
      * Initializes the player with the given name.
      * 
      * @param name The name of the player.
      */
     Player(const std::string& name);
 
     /**
      * @brief Increments the number of moves.
      * 
      * Increases the move count by one each time it is called.
      */
     void incrementMoves();
 
     /**
      * @brief Gets the number of moves made by the player.
      * 
      * @return The current number of moves made by the player.
      */
     int getNumberOfMoves() const;
 
     /**
      * @brief Gets the name of the player.
      * 
      * @return The name of the player.
      */
     std::string getName() const;
 
 private:
     std::string name; ///< The name of the player.
     int moveCount; ///< The number of moves made by the player.
 };
 