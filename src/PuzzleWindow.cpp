#include "PuzzleWindow.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTimer>

PuzzleWindow::PuzzleWindow(QWidget* parent)
    : QWidget(parent), boardSize(3), board(boardSize), player(nullptr) {
    setWindowTitle("Puzzle Game");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* controlsLayout = new QHBoxLayout();
    mainLayout->addLayout(controlsLayout);

    nameInput = new QLineEdit();
    nameInput->setPlaceholderText("Enter your name");
    controlsLayout->addWidget(nameInput);

    sizeComboBox = new QComboBox();
    sizeComboBox->addItem("3x3");
    sizeComboBox->addItem("4x4");
    sizeComboBox->addItem("5x5");
    controlsLayout->addWidget(sizeComboBox);

    startButton = new QPushButton("Start Game");
    controlsLayout->addWidget(startButton);
    connect(startButton, &QPushButton::clicked, this, &PuzzleWindow::startGame);

    solveButton = new QPushButton("Solve");
    solveButton->setEnabled(false);
    controlsLayout->addWidget(solveButton);
    connect(solveButton, &QPushButton::clicked, this, &PuzzleWindow::solvePuzzle);

    moveCounterLabel = new QLabel("");
    mainLayout->addWidget(moveCounterLabel);

    playerNameLabel = new QLabel("");
    mainLayout->addWidget(playerNameLabel);

    gridLayout = new QGridLayout();
    mainLayout->addLayout(gridLayout);
}

PuzzleWindow::~PuzzleWindow() {
    delete player;
}

void PuzzleWindow::startGame() {
    QString playerName = nameInput->text();
    if (playerName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter your name.");
        return;
    }

    delete player;
    player = new Player(playerName.toStdString());
    playerNameLabel->setText("Player: " + playerName);
    moveCounterLabel->setText("Moves: 0");

    QString selectedSize = sizeComboBox->currentText();
    if (selectedSize == "3x3") boardSize = 3;
    else if (selectedSize == "4x4") boardSize = 4;
    else if (selectedSize == "5x5") boardSize = 5;

    board = Board(boardSize);
    setupBoard();

    do {
        board.shuffle();
    } while (!board.isSolvable());

    sizeComboBox->setEnabled(false);
    startButton->setEnabled(false);
    solveButton->setEnabled(true);
    nameInput->setEnabled(false);
    updateBoard();
}

void PuzzleWindow::setupBoard() {
    for (auto& row : buttons)
        for (auto* button : row)
            delete button;

    buttons.clear();
    buttons.resize(boardSize, std::vector<QPushButton*>(boardSize, nullptr));

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            QPushButton* button = new QPushButton();
            button->setFixedSize(80, 80);
            gridLayout->addWidget(button, i, j);
            buttons[i][j] = button;

            connect(button, &QPushButton::clicked, this, &PuzzleWindow::handleButtonClick);
        }
    }
}

void PuzzleWindow::updateBoard() {
    const auto& tiles = board.getTiles();
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            int value = tiles[i][j];
            if (value == 0) {
                buttons[i][j]->setText("");
                buttons[i][j]->setStyleSheet("background-color: lightgray;");
            } else {
                buttons[i][j]->setText(QString::number(value));
                buttons[i][j]->setStyleSheet("");
            }
        }
    }
}

void PuzzleWindow::handleButtonClick() {
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    int clickedRow = -1, clickedCol = -1;

    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardSize; ++j)
            if (buttons[i][j] == senderButton) {
                clickedRow = i;
                clickedCol = j;
            }

    int emptyRow = board.getEmptyRow();
    int emptyCol = board.getEmptyCol();

    int dRow = emptyRow - clickedRow;
    int dCol = emptyCol - clickedCol;

    char direction = '\0';
    if (dRow == 1 && dCol == 0) direction = 'w';
    else if (dRow == -1 && dCol == 0) direction = 's';
    else if (dRow == 0 && dCol == 1) direction = 'a';
    else if (dRow == 0 && dCol == -1) direction = 'd';

    if (direction != '\0' && board.moveTile(direction)) {
        player->incrementMoves();
        updateMoveCounter();
        updateBoard();

        if (board.isSolved()) {
            QString playerName = playerNameLabel->text();
            playerName.remove("Player: ");
            QMessageBox::information(this, "Solved", "Congratulations, " + playerName + "! Puzzle solved in " + QString::number(player->getNumberOfMoves()) + " moves.");
        }
    }
}

void PuzzleWindow::solvePuzzle() {
    Solver solver(board);
    auto moves = solver.solve();

    if (moves.empty()) {
        QMessageBox::information(this, "Solver", "No solution found!");
        return;
    }

    performMoves(moves);
}

void PuzzleWindow::performMoves(const std::vector<char>& moves) {
    if (moves.empty()) return;

    std::vector<char> remainingMoves = moves;
    auto nextMove = remainingMoves.front();
    remainingMoves.erase(remainingMoves.begin());

    board.moveTile(nextMove);
    player->incrementMoves();
    updateMoveCounter();
    updateBoard();

    if (board.isSolved()) {
        QString playerName = playerNameLabel->text();
        playerName.remove("Player: ");
        QMessageBox::information(this, "Solved", "Congratulations, " + playerName + "! Puzzle solved in " + QString::number(player->getNumberOfMoves()) + " moves.");

        sizeComboBox->setEnabled(true);
        startButton->setEnabled(true);
        solveButton->setEnabled(false);
        nameInput->setEnabled(true);
    }

    if (!remainingMoves.empty()) {
        QTimer::singleShot(300, this, [this, remainingMoves]() {
            performMoves(remainingMoves);
        });
    }
}

void PuzzleWindow::updateMoveCounter() {
    moveCounterLabel->setText("Moves: " + QString::number(player->getNumberOfMoves()));
}
