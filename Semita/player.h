#pragma once
#include <string>

class Player {
public:
    Player();

    // Get and set location
    std::string getLocation() const;
    void setLocation(const std::string& newLocation);

private:
    std::string location;
};