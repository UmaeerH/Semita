#include "player.h"

// Starting Values
Player::Player() : 
    location("Town"),
    HP(100),
    Mana(100),
    playerClass(PlayerClass::Unselected),
    Strength(10), // Default values for now, changed upon class selection + level up
    Defence(10),
    Agility(10),
    Speed(10)
{}

// HP getter and setter
int Player::getHP() const {
    return HP;
}
void Player::setHP(int newHP) {
    HP = newHP;
}

// Mana getter and setter
int Player::getMana() const {
    return Mana;
}
void Player::setMana(int newMana) {
    Mana = newMana;
}

// Combat Stats getters and setters

int Player::getStrength() const {
    return Strength;
}
void Player::setStrength(int newStr) {
    Strength = newStr;
}
int Player::getDefence() const {
    return Defence;
}
void Player::setDefence(int newDef) {
    Defence = newDef;
}
int Player::getAgility() const {
    return Agility;
}
void Player::setAgility(int newAgi) {
    Agility = newAgi;
}
int Player::getSpeed() const {
    return Speed;
}
void Player::setSpeed(int newSpd) {
    Speed = newSpd;
}

// Player Level & XP getter and setter

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
