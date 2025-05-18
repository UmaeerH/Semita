#include "command_handler.h"
#include <iostream>
#include "player.h"
#include "map.h"


using namespace std;

// Not exactly command handling, but a function to capitalise the first letter of a noun (2nd word)
std::string capitaliseNoun(std::string& input) {
    if (input.empty()) return input;
    std::string result = input;
    result[0] = toupper(result[0]);
    for (size_t i = 1; i < result.size(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

// HELP COMMAND
void handleHelp() {
    cout << "Help: Welcome to Semita! This is an Text-Adventure Game." << endl;
    cout << "To get a list of commands, type 'verbs'." << endl;
}

// GO COMMAND
void handleGo(Player& player, const std::string& arg) {
    if (!locationExists(arg)) {
        cout << arg <<" is not a valid location." << endl;
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