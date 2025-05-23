#include <iostream>
#include <algorithm>

#include "../Semita/termcolor/termcolor.hpp"

#include "command_handler.h"
#include "command.h"
#include "player.h"
#include "object.h"
#include "map.h"

// Forward declaration for getCommandDescription
std::string getCommandDescription(const std::string& command);

using namespace std;

// Not exactly command handling, but a function to capitalise the first letter of a noun (2nd word)



// META COMMANDS
// Help Command
void handleHelp(const std::string& arg) {
    if (arg.empty()) { // If argument is empty show this
        cout << "Help: Welcome to Semita! This is a Text-Adventure Game." << endl;
        cout << "To get a list of commands, type 'verbs'." << endl;
        return;
    }
    // If argument is not empty, show the help for that command
    Command cmd = Command::UNKNOWN;
    try {
        cmd = parseCommand(arg);
    } catch (...) {
        // ignore, will be UNKNOWN
    }
    std::string desc = getCommandDescription(cmd);
    if (cmd != Command::UNKNOWN && desc != "No description available for this command.") {
        cout << termcolor::cyan << "Help: " << desc << termcolor::reset << endl;
    } else { // If command is not recognised
        cout << "I cannot help with " << arg << endl;
    }
}

// Verbs Command
void handleVerbs() {
    cout << "Here is a list of commands you can do: " << endl;
    cout << termcolor::cyan << "---- META COMMANDS ----" << termcolor::reset << endl;
    cout << "Help, Verbs, Save, Load, Quit" << endl;
    cout << termcolor::cyan << "---- Interacting with the World ----" << termcolor::reset << endl;
    cout << "Go, Insert, Look, Move, Read\nTalk, Leave, Take, Hit" << endl;
    cout << termcolor::cyan << "--- Interacting with Items ----" << termcolor::reset << endl;
    cout << "Use, Buy, Sell, Equip, Unequip\nDiscard, Inventory, Equipped" << endl;
    cout << termcolor::cyan << "---- Battle Commands ----" << termcolor::reset << endl;
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

// Insert Command
void handleInsert(Player& player, const std::string& arg, const std::string& location) {
    cout << "You insert " << arg << " into " << location << endl;
}

// Look Command
void handleLook(Player& player, const std::string& arg) {
    string currentLocation = player.getLocation();
    if (arg.empty()) { // No argument given, description of current location
        cout << "You are at: " << currentLocation << endl;
        cout << "You look around your environment: " << getLocationDescription(currentLocation) << endl;
    } else {
         // Search for the object in the object table
        const auto& objects = getObjectTable();
        auto it = std::find_if(objects.begin(), objects.end(),
            [&](const GameObject& obj) {
                return obj.objectName == arg;
            });
        if (it != objects.end()) {
            cout << "You look at: " << it->objectName << endl;
            cout << "Description: " << it->objectDescription << endl;
        } else {
            cout << "There is no " << termcolor::red << arg << termcolor::reset << " around." << endl;
        }
    }
}

// Convert class to string, for printing
std::string playerClassToString(PlayerClass pc) {
    switch (pc) {
        case PlayerClass::Unselected: return "Unselected";
        case PlayerClass::Knight:     return "Knight";
        case PlayerClass::Mage:       return "Mage";
        case PlayerClass::Assassin:   return "Assassin";
        case PlayerClass::Archer:     return "Archer";
        default:                      return "Unknown";
    }
}

// Status Command
void handleStatus(Player& player) {
    cout << "======================================" << endl;
    cout << "Player Status" << endl;
    cout << "Location: " << player.getLocation() << endl;
    cout << termcolor::red << "HP: " << player.getHP() << termcolor::reset << endl;
    cout << termcolor::blue << "Mana: " << player.getMana() << termcolor::reset << endl;
    cout << termcolor::cyan << "Class: " << playerClassToString(player.getClass()) << termcolor::reset << endl;
    cout << termcolor::green << "STR: " << player.getStrength() << "\tDEF: " << player.getDefence() << "\tAGI: " << player.getAgility() << "\tSPD: " << player.getSpeed() << termcolor::reset << endl;
    cout << "======================================" << endl;
}