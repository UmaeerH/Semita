#include "player.h"

// Starting Values
Player::Player() : location("Town"), HP(100), playerClass(PlayerClass::Unselected) {}

// HP getter and setter
int Player::getHP() const {
    return HP;
}

void Player::setHP(int newHP) {
    HP = newHP;
}


// Location getter and setter
std::string Player::getLocation() const {
    return location;
}

void Player::setLocation(const std::string& newLocation) {
    location = newLocation;
}


// PlayerClass getter and setter
PlayerClass Player::getClass() const {
    return playerClass;
}

void Player::setClass(PlayerClass newClass) {
    playerClass = newClass;
}
