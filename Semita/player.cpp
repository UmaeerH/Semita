#include "player.h"

// Starting Values
// Add a starting value of 100 for HP
Player::Player() : location("Town"), HP(100) {}


// HP getter and setter
int Player::getHP() const {
    return HP;
}



// Location getter and setter
std::string Player::getLocation() const {
    return location;
}

void Player::setLocation(const std::string& newLocation) {
    location = newLocation;
}
