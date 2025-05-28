#include "player.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

#include "../Semita/termcolor/termcolor.hpp"

// Starting Values
Player::Player() : 
    location("Town"),
    HP(100),
    Mana(100),
    playerClass(PlayerClass::Unselected),
    Strength(10), // Default values, changed upon class selection + level up
    Defence(10),
    Agility(10),
    Speed(10),
    Experience(0),
    Gold(20)
{}

// Gold Getter and Setter
int Player::getGold() const {
    return Gold;
}

void Player::setGold(int newGold) {
    Gold = newGold;
}

void Player::addGold(int amount) {
    if (amount < 0) {
        std::cerr << "Error: Cannot add negative gold." << std::endl;
        return;
    }
    Gold += amount;
}

bool Player::spendGold(int amount) {
    if (amount < 0) {
        std::cerr << "Error: Cannot use negative gold." << std::endl;
        return false; // We shouldn't really reach this but just in case an item's price is set as negative somehow
    }
    if (Gold < amount) {
        return false; // Reject purchase if not enough gold -> handle with dialogue
    }
    Gold -= amount;
    return true; // Purchase successful
}

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


// Location getter and setter
std::string Player::getLocation() const {
    return location;
}

void Player::setLocation(const std::string& newLocation) {
    location = newLocation;
}

// PLAYER CLASS SECTION

const std::unordered_map<PlayerClass, ClassStats> classStatsTable = {
    { PlayerClass::Knight,   {10, 4, 10, 6, 6, 2, 8, 1} },
    { PlayerClass::Mage,     {13, 5, 5, 1, 6, 2, 12, 3} },
    { PlayerClass::Assassin, {7, 2, 5, 1, 14, 5, 13, 4} },
    { PlayerClass::Archer,   {16, 6, 9, 3, 5, 1, 7, 1} }
};

/*
What the map above means:
Knight 
startingStrength = 10, levelStrength = 4 // High Strength
startingDefence = 10, levelDefence = 6 // High Defence (scales fast)
startingAgility = 6, levelAgility = 2 // Low agility
startingSpeed = 8, levelSpeed = 1 // Mild speed
*/

// PlayerClass getter and setter
PlayerClass Player::getClass() const {
    return playerClass;
}

void Player::setClass(PlayerClass newClass) {
    playerClass = newClass;
    Player::setStrength(classStatsTable.at(newClass).startingStrength);
    Player::setDefence(classStatsTable.at(newClass).startingDefence);
    Player::setAgility(classStatsTable.at(newClass).startingAgility);
    Player::setSpeed(classStatsTable.at(newClass).startingSpeed);
}

// Player Level & XP Section

int Player::getExperience() const {
    return Experience;
}

static const std::vector<int> levelThresholds = {0, 20, 50, 85, 150, 250};
// I.e. level 1 is 0 XP, level 2 is 20 XP, level 3 is 50 XP, etc.

int Player::getLevel() const {
    // upper_bound returns the first element greater than Experience
    // The index of that element is the player's level
    auto it = std::upper_bound(levelThresholds.begin(), levelThresholds.end(), Experience);
    return static_cast<int>(it - levelThresholds.begin());
}

// We won't use the setExperience function directly. Instead we'll use addExperience
void Player::setExperience(int newXP) {
    Experience = newXP;
}

void Player::addExperience(int earnedXP) {
    if (earnedXP < 0) {
        std::cerr << "Error: Cannot add negative experience." << std::endl;
        return;
    }

    int oldLevel = getLevel();
    Experience += earnedXP;
    int newLevel = getLevel();

    const ClassStats& stats = classStatsTable.at(playerClass);

    for (int lvl = oldLevel + 1; lvl <= newLevel; ++lvl) {
        int prevStrength = Strength;
        int prevDefence  = Defence;
        int prevAgility  = Agility;
        int prevSpeed    = Speed;
        int prevHP       = HP;
        int prevMana     = Mana;

        // Increase stats for this level up
        Strength += stats.levelStrength;
        Defence  += stats.levelDefence;
        Agility  += stats.levelAgility;
        Speed    += stats.levelSpeed;
        HP      += 20; // Increase HP by a fixed amount per level
        Mana    += (playerClass == PlayerClass::Mage ? 5 : 0);  // Increase Mana by 5 for Mages only

        // Print level up message
        std::cout << "================================================" << std::endl;
        std::cout << "You level up to level " << lvl << "! EXP: " << Experience << "/" 
                  << (lvl < static_cast<int>(levelThresholds.size()) ? levelThresholds[lvl] : Experience) << std::endl;
        std::cout << termcolor::red    << "HP:  " << prevHP << "->" << HP 
                  << termcolor::bright_blue << "    MP:  " << prevMana << "->" << Mana << std::endl;
        std::cout << termcolor::yellow << "STR: " << prevStrength << "->" << Strength
                  << "  |  Def: " << prevDefence << "->" << Defence
                  << "  |  AGI: " << prevAgility << "->" << Agility
                  << "  |  SPD: " << prevSpeed   << "->" << Speed << termcolor::reset << std::endl;
        std::cout << "================================================" << std::endl;
    }
}
