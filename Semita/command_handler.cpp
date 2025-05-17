#include "command_handler.h"
#include <iostream>
#include "player.h"
#include "map.h"


using namespace std;

void handleHelp() {
    cout << "Help: Available commands are go, look, take, use, etc." << endl;
}

void handleGo(Player& player, const std::string& arg) {
    string currentLocation = player.getLocation();

    // Check if the new location is a valid neighbour
    if (checkNeighbours(currentLocation, arg)) { // Accept moving the player
        cout << "Moving from " << currentLocation << " to " << arg << endl;
        player.setLocation(arg);
        cout << "You are now at: " << arg << endl;
    } else { // Reject moving the player
        cout << "You can't go to '" << arg << "' from '" << currentLocation << "'." << endl;
    }
}