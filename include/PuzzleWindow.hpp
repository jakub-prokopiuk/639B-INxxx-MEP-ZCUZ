/**
 * @brief Represents the main window for the puzzle game.
 * 
 * This class is responsible for the graphical user interface (GUI) of the
 * sliding puzzle game. It allows users to interact with the puzzle, start the
 * game, and solve the puzzle.
 */
 #pragma once

 #include <QWidget>
 #include <QPushButton>
 #include <QComboBox>
 #include <QLabel>
 #include <QGridLayout>
 #include "Board.hpp"
 #include "Solver.hpp"
 #include <QLineEdit>
 #include "Player.hpp"
 
 /**
  * @brief Main window for the sliding puzzle game.
  * 
  * This class provides the GUI for the puzzle game. It allows the user to
  * interact with the puzzle, view the current board, and track the player's moves.
  */
 class PuzzleWindow : public QWidget {
     Q_OBJECT
 
 public:
     /**
      * @brief Constructs a new PuzzleWindow object.
      * 
      * Initializes the puzzle window and sets up the GUI components.
      * 
      * @param parent The parent widget (default is nullptr).
      */
     PuzzleWindow(QWidget* parent = nullptr);
 
     /// Destructor for cleaning up resources.
     ~PuzzleWindow();
 
 private slots:
     /**
      * @brief Starts the game.
      * 
      * Initializes the game board and begins a new game session.
      */
     void startGame();
 
     /**
      * @brief Handles button clicks on the puzzle board.
      * 
      * Responds to user input when a tile button is clicked.
      */
     void handleButtonClick();
 
     /**
      * @brief Solves the puzzle.
      * 
      * Attempts to solve the puzzle and display the solution.
      */
     void solvePuzzle();
 
     /**
      * @brief Updates the move counter.
      * 
      * Increments and updates the number of moves made by the player.
      */
     void updateMoveCounter();
 
 private:
     /**
      * @brief Sets up the puzzle board in the GUI.
      * 
      * Initializes the layout and tile buttons on the GUI.
      */
     void setupBoard();
 
     /**
      * @brief Updates the puzzle board in the GUI.
      * 
      * Reflects the current state of the board in the GUI.
      */
     void updateBoard();
 
     /**
      * @brief Performs a sequence of moves to solve the puzzle.
      * 
      * Moves the tiles based on the given sequence of move directions.
      * 
      * @param moves The sequence of moves to perform.
      */
     void performMoves(const std::vector<char>& moves);
 
     QGridLayout* gridLayout; ///< The grid layout for the puzzle board.
     std::vector<std::vector<QPushButton*>> buttons; ///< The buttons representing the tiles.
     QComboBox* sizeComboBox; ///< Combo box for selecting the puzzle size.
     QPushButton* startButton; ///< Button to start the game.
     QPushButton* solveButton; ///< Button to solve the puzzle.
     QLabel* moveCounterLabel; ///< Label displaying the number of moves.
     QLineEdit* nameInput; ///< Input field for the player's name.
     QLabel* playerNameLabel; ///< Label displaying the player's name.
 
     int moveCount; ///< The number of moves made by the player.
     int boardSize; ///< The size of the board.
     Board board; ///< The game board.
     Player* player; ///< The player participating in the game.
 };
 