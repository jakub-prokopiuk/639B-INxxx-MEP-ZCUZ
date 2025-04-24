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

class PuzzleWindow : public QWidget {
    Q_OBJECT

public:
    PuzzleWindow(QWidget* parent = nullptr);
    ~PuzzleWindow();

private slots:
    void startGame();
    void handleButtonClick();
    void solvePuzzle();
    void updateMoveCounter();
    
private:
    void setupBoard();
    void updateBoard();
    void performMoves(const std::vector<char>& moves);

    QGridLayout* gridLayout;
    std::vector<std::vector<QPushButton*>> buttons;
    QComboBox* sizeComboBox;
    QPushButton* startButton;
    QPushButton* solveButton;
    QLabel* moveCounterLabel;
    QLineEdit* nameInput;  
    QLabel* playerNameLabel;  

    int moveCount;
    int boardSize;
    Board board;
    Player* player;  
};
