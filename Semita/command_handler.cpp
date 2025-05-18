#include "command_handler.h"
#include <iostream>
#include "player.h"
#include "map.h"


using namespace std;

void handleHelp() {
    cout << "Help: Welcome to Semita! This is an Text-Adventure Game." << endl;
    cout << "To get a list of commands, type 'verbs'." << endl;
}

void handleGo(Player& player, const std::string& arg) {
    if (!locationExists(arg)) {
        cout << "This place does not exist." << endl;
        return;
    }

    // Only run if the argument is a valid location
    string currentLocation = player.getLocation();
    // Check if the new location is a neighbour
    if (checkNeighbours(currentLocation, arg)) { // Accept moving the player
        cout << "Moving from " << currentLocation << " to " << arg << endl;
        player.setLocation(arg);
        cout << "You are now at: " << arg << endl;
    } else { // Reject moving the player
        cout << "You can't go to '" << arg << "' from '" << currentLocation << "'." << endl;
    }
}