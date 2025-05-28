#include <iostream>
#include <algorithm>
#include <unordered_map>

#include "../Semita/termcolor/termcolor.hpp"

#include "command_handler.h"
#include "command.h"
#include "misc.h"
#include "player.h"
#include "object.h"
#include "npc.h"
#include "map.h"

// Forward declaration for getObjectLocationTable if not included in object.h
const std::unordered_map<std::string, std::string>& getObjectLocationTable();

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

// Quit Command
bool handleQuit() {
    std::cout << termcolor::red << "Are you sure you want to quit? (\"Y\" to confirm)" << termcolor::reset << std::endl;
    std::cout << "> ";
    std::string input;
    std::getline(std::cin, input);
    if (input == "Y" || input == "y") {
        return true; // Confirm quit
    } else {
        std::cout << "Quit cancelled" << std::endl;
        return false; // Cancel quit
    }
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
        cout << "You can't go to \'" << arg << "\' from \'" << currentLocation << "\'." << endl;
    }
}

// Insert Command
void handleInsert(Player& player, const std::string& arg, const std::string& location) {
    cout << "You cannot insert " << arg << " into " << location << endl;
} // Plceholder for now

// Take Command
void handleTake(Player& player, const std::string& arg) {
    const auto& objects = getObjectTable();
    const auto& locationTable = getObjectLocationTable();
    auto objIt = std::find_if(objects.begin(), objects.end(),
        [&](const GameObject& obj) {
            auto locIt = locationTable.find(obj.objectName);
            return obj.objectName == arg && locIt != locationTable.end() && isLocal(locIt->second, player);
        });

    if (objIt == objects.end()) {
        std::cout << termcolor::red << "I cannot take that" << termcolor::reset << endl;
        return;
    }

    // Check if the object has a Take entry
    const auto& takeTable = getItemTakeTable();
    auto takeIt = takeTable.find(arg);
    if (takeIt != takeTable.end()) {
        const auto& takePair = takeIt->second;
        if (takePair.second) {
            cout << termcolor::green << takePair.first << termcolor::reset << endl;
            cout << termcolor::green << std::string(arg) << " is now in your inventory."  << termcolor::reset << endl;
            // TODO: placeholder for moving obj to inv
            
        } else {
            cout << termcolor::red << takePair.first << termcolor::reset << endl;
        }
    } else { // Generic message if no specific take entry exists
        cout << termcolor::red << arg << " cannot be taken" << termcolor::reset << endl;
    }
}

// Move Command
void handleMove(Player& player, const std::string& arg) {
    const auto& objects = getObjectTable();
    const auto& locationTable = getObjectLocationTable();
    auto objIt = std::find_if(objects.begin(), objects.end(),
        [&](const GameObject& obj) {
            auto locIt = locationTable.find(obj.objectName);
            return obj.objectName == arg && locIt != locationTable.end() && isLocal(locIt->second, player);
        });

    if (objIt == objects.end()) {
        std::cout << "There is no " << termcolor::red << arg << termcolor::reset << " to move" << std::endl;
        return;
    }

    // Get the move table (non-const to allow updating the bool)
    static auto& moveTable = const_cast<std::unordered_map<std::string, MoveEntry>&>(getItemMoveTable());
    auto moveIt = moveTable.find(arg);
    if (moveIt == moveTable.end()) {
        std::cout << "I cannot move " << termcolor::red << arg << termcolor::reset << std::endl;
        return;
    }

    MoveEntry& entry = moveIt->second;
    if (!entry.hasBeenMoved) {
        std::cout << "You move " << termcolor::cyan << arg << termcolor::reset << std::endl;
        std::cout << termcolor::green << entry.dialogue << termcolor::reset << std::endl;
        entry.hasBeenMoved = true;
    } else {
        std::cout << termcolor::red << "I have already done that" << termcolor::reset << std::endl;
    }
}

// Look Command
void handleLook(Player& player, const std::string& arg) {
    string currentLocation = player.getLocation();
    if (arg.empty()) { // No argument given, description of current location
        cout << "You are at: " << currentLocation << endl;
        cout << "You look around your environment: " << getLocationDescription(currentLocation) << endl;
        // List objects in the area
        const auto& objects = getObjectTable();
        const auto& locationTable = getObjectLocationTable();
        std::vector<std::string> foundObjects;
        for (const auto& obj : objects) {
            auto locIt = locationTable.find(obj.objectName);
            if (locIt != locationTable.end() && isLocal(locIt->second, player)) {
                foundObjects.push_back(obj.objectName);
            }
        }
        if (!foundObjects.empty()) {
            cout << termcolor::green << "You spot: " << formatList(foundObjects) << termcolor::reset << endl;
        }

        // List NPCs in the area
        const auto& npcs = getNPCTable();
        std::vector<std::string> foundNPCs;
        for (const auto& npc : npcs) {
            if (isLocal(npc.location, player)) {
                foundNPCs.push_back(npc.name);
            }
        }
        if (!foundNPCs.empty()) {
            cout << termcolor::cyan << "You notice " << formatList(foundNPCs) << termcolor::reset << endl;
        }
    } else {
        if (!printLookDescription(arg, player)) {
            cout << "There is no " << termcolor::red << arg << termcolor::reset << " around." << endl;
        }
    }
}

// Read Command
void handleRead(Player& player, const std::string& arg) {
    // Check if the object is in the read table
    auto it = getItemReadTable().find(arg);
    if (it != getItemReadTable().end()) {
        cout << "You read the " << it->first << endl;
        cout << termcolor::green << it->second << termcolor::reset << endl;
    } else {
        cout << "There's nothing to read on that" << endl;
    }
}

// Talk Command
void handleTalk(Player& player, const std::string& arg) {
    if (arg.empty()) {
        cout << "You talk to yourself." << endl;
    } else {
        // Search for the NPC in the dialogue table
        auto it = getNPCDialogueTable().find(arg);
        if (it != getNPCDialogueTable().end()) {
            cout << "You talk to " << arg << "." << endl;
            cout << termcolor::cyan << it->second << termcolor::reset << endl;
        } else {
            cout << "There is no " << termcolor::red << arg << termcolor::reset << " here to talk to." << endl;
        }
    }
}

// Inventory Commmand
void handleInventory(Player& player) {
    cout << "You check your inventory." << endl;
    const auto& objects = getObjectTable();
    const auto& locationTable = getObjectLocationTable();
    std::vector<std::string> inventoryItems;

    for (const auto& obj : objects) {
        auto locIt = locationTable.find(obj.objectName);
        if (locIt != locationTable.end() && locIt->second == "Inventory") {
            inventoryItems.push_back(obj.objectName);
        }
    }

    if (inventoryItems.empty()) {
        cout << "Your inventory is empty." << endl;
    } else {
        cout << termcolor::cyan << "You have: " << formatList(inventoryItems) << termcolor::reset << endl;
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
    cout << termcolor::green << "STR: " << player.getStrength() << "\tDEF: " << player.getDefence() 
    << "\tAGI: " << player.getAgility() << "\tSPD: " << player.getSpeed() << termcolor::reset << endl;
    cout << "======================================" << endl;
}