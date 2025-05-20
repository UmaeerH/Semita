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

class Player {
public:
    Player();
    // Get and set location
    std::string getLocation() const;
    void setLocation(const std::string& newLocation);
    int getHP() const;
    void setHP(int newHP);
    PlayerClass getClass() const;
    void setClass(PlayerClass newClass);
private:
    std::string location;
    int HP;
    PlayerClass playerClass;
};