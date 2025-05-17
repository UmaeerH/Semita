#include "player.h"

Player::Player() : location("Town") {}

std::string Player::getLocation() const {
    return location;
}

void Player::setLocation(const std::string& newLocation) {
    location = newLocation;
}