#include "Player.hpp"

Player::Player(const std::string& name) : name(name), moveCount(0) {}

void Player::incrementMoves() {
    moveCount++;
}

int Player::getMoveCount() const {
    return moveCount;
}

std::string Player::getName() const {
    return name;
}
