#pragma once
#include <string>
#include <algorithm>


// Player class type enumeration
enum class PlayerClass {
    Unselected,
    Knight,
    Mage,
    Assassin,
    Archer
};

struct ClassStats { // This affects the player's stats based on their class
    int startingStrength, levelStrength;
    int startingDefence,  levelDefence;
    int startingAgility,  levelAgility;
    int startingSpeed,    levelSpeed;
};

class Player {
public:
    Player();
    
    // Get and set HP, Mana
    int getHP() const;
    void setHP(int newHP);
    int getMana() const;
    void setMana(int newMana);
    // Combat Stats
    int getStrength() const;
    void setStrength(int newStr);
    int getDefence() const;
    void setDefence(int newDef);
    int getAgility() const;
    void setAgility(int newAgi);
    int getSpeed() const;
    void setSpeed(int newSpd);
    // Player class
    PlayerClass getClass() const;
    void setClass(PlayerClass newClass);
    // Player location
    std::string getLocation() const;
    void setLocation(const std::string& newLocation);

    // Player Level & XP
    int getExperience() const;
    void setExperience(int newExperience); // Not used apart from testing
    void addExperience(int amount);
    int getLevel() const;

    // Player Gold
    int getGold() const;
    void addGold(int amount);
    void setGold(int newGold);
    bool spendGold(int amount);

private:
    int Experience;
    int Gold;
    int HP;
    int Mana;
    int Strength;
    int Defence;
    int Agility;
    int Speed;
    PlayerClass playerClass;
    std::string location;
};