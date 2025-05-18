#pragma once
#include <string>
#include <algorithm>


class Player {
public:
    Player();
    // Get and set location
    std::string getLocation() const;
    void setLocation(const std::string& newLocation);
    int getHP() const;
private:
    std::string location;
    int HP;
};