#include "misc.h"
#include "termcolor/termcolor.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


void introPrint()
{ // Surely there's a better way to do this
    cout << termcolor::red << "==============================================================================================" << termcolor::green << endl;
    cout << "db   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b      d888888b  .d88b.  " << endl;
    cout << "88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'          `~~88~~' .8P  Y8. " << endl;
    cout << "88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo         88    88    88 " << endl;
    cout << "Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~         88    88    88 " << endl;
    cout << "`8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.             88    `8b  d8' " << endl;
    cout << " `8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P         YP     `Y88P'  " << endl;
    cout << "                                                                                         " << endl;
    cout << "                                                                                         " << endl;
    cout << ".d8888. d88888b .88b  d88. d888888b d888888b  .d8b.  db                                  " << endl;
    cout << "88'  YP 88'     88'YbdP`88   `88'   `~~88~~' d8' `8b 88                                  " << endl;
    cout << "`8bo.   88ooooo 88  88  88    88       88    88ooo88 YP                                  " << endl;
    cout << "  `Y8b. 88~~~~~ 88  88  88    88       88    88~~~88                                     " << endl;
    cout << "db   8D 88.     88  88  88   .88.      88    88   88 db                                  " << endl;
    cout << "`8888Y' Y88888P YP  YP  YP Y888888P    YP    YP   YP YP                                  " << endl;
    cout << termcolor::red << "==============================================================================================" << termcolor::reset << endl;
}

std::string capitaliseNoun(std::string& input) {
    if (input.empty()) return input;
    std::string result = input;
    result[0] = toupper(result[0]);
    for (size_t i = 1; i < result.size(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

void interpretInput(std::string& input, std::string& word1, std::string& word2, std::string& word3, std::string& phrase) {
    word1.clear();
    word2.clear();
    word3.clear();
    phrase.clear();
    size_t pos = input.find(' ');
    if (pos != string::npos) {
        word1 = input.substr(0, pos);
        size_t first_non_space = input.find_first_not_of(' ', pos + 1);
        if (first_non_space != string::npos) {
            size_t second_space = input.find(' ', first_non_space);
            if (second_space != string::npos) {
                word2 = input.substr(first_non_space, second_space - first_non_space);
                size_t second_non_space = input.find_first_not_of(' ', second_space + 1);
                if (second_non_space != string::npos) {
                    word3 = input.substr(second_non_space);
                }
            } else {
                word2 = input.substr(first_non_space);
            }
        }
    } else {
        word1 = input;
    }

    std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    word2 = capitaliseNoun(word2); // Capitalise the noun
    word3 = capitaliseNoun(word3);

    // Phrase will be used for single-noun commands such as go, equip, etc
    // This allows use to use names with spaces in them, such as "Mountain Shrine" and "Leather Helmet"
    if (!word2.empty() && !word3.empty()) {
        phrase = word2 + " " + word3;
    } else if (!word2.empty()) {
        phrase = word2;
    } else if (!word3.empty()) {
        phrase = word3;
    } else {
        phrase.clear();
    }
}

// Utility function to check if an entity is in the player's current location
bool isLocal(const std::string& entityLocation, const Player& player) {
    return entityLocation == player.getLocation();
}

int choosePlayerClass(Player& player) {
    while (true) {
        cout << termcolor::cyan << "Choose your class:\n"
             << "1. Knight\n"
             << "2. Mage\n"
             << "3. Assassin\n"
             << "4. Archer\n"
             << "Type the number or the class name: " << termcolor::reset;
        string classInput;
        getline(cin, classInput);

        // Convert input to lowercase
        std::transform(classInput.begin(), classInput.end(), classInput.begin(), ::tolower);

        if (classInput == "1" || classInput == "knight") {
            player.setClass(PlayerClass::Knight);
            cout << "You have chosen: Knight\n";
            cout << termcolor::green << "Welcome to Semita! We recommend using the 'help' command if you are new!" << termcolor::reset << endl;
            break;
        } else if (classInput == "2" || classInput == "mage") {
            player.setClass(PlayerClass::Mage);
            cout << "You have chosen: Mage\n";
            cout << termcolor::green << "Welcome to Semita! We recommend using the 'help' command if you are new!" << termcolor::reset << endl;
            break;
        } else if (classInput == "3" || classInput == "assassin") {
            player.setClass(PlayerClass::Assassin);
            cout << "You have chosen: Assassin\n";
            cout << termcolor::green << "Welcome to Semita! We recommend using the 'help' command if you are new!" << termcolor::reset << endl;
            break;
        } else if (classInput == "4" || classInput == "archer") {
            player.setClass(PlayerClass::Archer);
            cout << "You have chosen: Archer\n";
            cout << termcolor::green << "Welcome to Semita! We recommend using the 'help' command if you are new!" << termcolor::reset << endl;
            break;
        } else {
            cout << termcolor::bright_red << "Invalid choice. Please try again.\n" << termcolor::reset;
        }
    }
    return 0;
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

// Utility function to format a list with commas and '&'
std::string formatList(const std::vector<std::string>& items) {
    if (items.empty()) return "";
    if (items.size() == 1) return items[0];
    std::string result;
    for (size_t i = 0; i < items.size(); ++i) {
        result += items[i];
        if (i + 2 == items.size())
            result += " & ";
        else if (i + 1 < items.size())
            result += ", ";
    }
    return result;
}


// Helper function to print look description for object or NPC
bool printLookDescription(const std::string& name, const Player& player) {
    // Try object first
    const auto& objects = getObjectTable();
    const auto& locationTable = getObjectLocationTable();
    auto objIt = std::find_if(objects.begin(), objects.end(),
        [&](const GameObject& obj) { return obj.objectName == name; });
    if (objIt != objects.end()) {
        auto locIt = locationTable.find(objIt->objectName);
        if (locIt != locationTable.end() &&
            (isLocal(locIt->second, player) || locIt->second == "Inventory")) {
            std::cout << "You look at: " << objIt->objectName << std::endl;
            std::cout << "Description: " << objIt->objectDescription << std::endl;
            return true;
        }
    }

    // Try NPC
    const auto& npcs = getNPCTable();
    auto npcIt = std::find_if(npcs.begin(), npcs.end(),
        [&](const NPC& npc) { return npc.name == name && isLocal(npc.location, player); });
    if (npcIt != npcs.end()) {
        const auto& npcLookTable = getNPCLookTable();
        auto descIt = npcLookTable.find(npcIt->name);
        std::cout << "You look at: " << npcIt->name << std::endl;
        if (descIt != npcLookTable.end()) {
            std::cout << "Description: " << descIt->second << std::endl;
        } else {
            std::cout << "They look unremarkable." << std::endl;
        }
        return true;
    }

    return false;
}

// Helper function to check if an item is in the player's inventory
bool isInInventory(const std::string& item) {
    const auto& locationTable = getObjectLocationTable();
    auto it = locationTable.find(item);
    return it != locationTable.end() && it->second == "Inventory";
}