#include "player.h"
#include <vector>
#include <algorithm>
#include <iostream>

// Starting Values
Player::Player() : 
    location("Town"),
    HP(100),
    Mana(100),
    playerClass(PlayerClass::Unselected),
    Strength(10), // Default values for now, changed upon class selection + level up
    Defence(10),
    Agility(10),
    Speed(10),
    Experience(0)
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

int Player::getExperience() const {
    return Experience;
}

// We won't use the setExperience function directly. Instead we'll use addExperience
void Player::setExperience(int newXP) {
    Experience = newXP;
}

void Player::addExperience(int earnedXP) {
    int oldLevel = getLevel();
    Experience += earnedXP;
    int newLevel = getLevel();
    if (newLevel > oldLevel) {
        // Placeholder of just sending a message
        std::cout << "Congratulations! You reached level " << newLevel << "!" << std::endl;
    }
}

static const std::vector<int> levelThresholds = {0, 20, 50, 85, 150, 250};
// I.e. level 1 is 0 XP, level 2 is 20 XP, level 3 is 50 XP, etc.

int Player::getLevel() const {
    // upper_bound returns the first element greater than Experience
    // The index of that element is the player's level
    auto it = std::upper_bound(levelThresholds.begin(), levelThresholds.end(), Experience);
    return static_cast<int>(it - levelThresholds.begin());
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
