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

// META COMMANDS
// Help Command
void handleHelp(const std::string& arg) {
    // This is when no command is given following the "help"
    if (arg.empty()) {
        cout << "Help: Welcome to Semita! This is an Text-Adventure Game." << endl;
        cout << "To get a list of commands, type 'verbs'." << endl;
        return;
    }   // HACK: This is a temporary way of handling it. Will add a command "desc" later to read
        // NOTE: 2nd word is capitlised like a noun
    else if (arg == "Verbs" || arg == "Commands" || arg == "V" || arg == "Cmds") {
        cout << "Help: This command lists all the commands you can use!" << endl; 
        return;
    }
    else {
        cout << "I cannot help with " << arg << endl;
    }
}

// Verbs Command
void handleVerbs() {
    cout << "Here is a list of commands you can do: " << endl;
    cout << "---- META COMMANDS ----" << endl;
    cout << "Help, Verbs / Commands, Save, Load, Quit" << endl;
    cout << "---- Interacting with the World ----" << endl;
    cout << "Go, Insert, Look, Move, Read, Talk, Leave, Take, Hit" << endl;
    cout << "--- Interacting with Items ----" << endl;
    cout << "Use, Buy, Sell, Equip, Unequip, Discard, Inventory, Equipped" << endl;
    cout << "---- Battle Commands ----" << endl;
    cout << "Attack, Skill, Defend, Flee, Status" << endl;
    cout << "======================================" << endl;
    cout << "For more information on a command, type \'Help {Command}\'." << endl;
}


// IN-GAME COMMANDS
// Go Command
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
        cout << "Description: " << getLocationDescription(arg) << endl;
    } else { // Reject moving the player - not connected
        cout << "You can't go to '" << arg << "' from '" << currentLocation << "'." << endl;
    }
}

// Look Command
void handleLook(Player& player, const std::string& arg) {
    string currentLocation = player.getLocation();
    if (arg.empty()) { // No argument given, description of current location
        cout << "You are at: " << currentLocation << endl;
        cout << "Description: " << getLocationDescription(currentLocation) << endl;
    } else {
        cout << "You look at: " << arg << endl; // Placeholder for looking at an object
    }
}