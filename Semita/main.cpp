// Library imports
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <functional>

#include "../Semita/termcolor/termcolor.hpp"

// Program imports
#include "command.h"
#include "command_handler.h"
#include "player.h"
#include "object.h"
#include "npc.h"
#include "misc.h" // For misc functions

using namespace std;

/* 
TODO: Make noun list and populate from the table 
TODO: Noun table: location, look dialogue, etc
TODO: Make player class more useful - HP, Mana, inventory, etc.

TODO: Battle system
TODO: NPCs to talk to

*/
int main()
{
    string input; // The entire input
    string word1; // The verb/command
    string word2; // The noun/item
    string word3; // The second noun/item
    string phrase; // word2 + word3
    Command command = Command::UNKNOWN;
    Player player; // Define the player
    bool quit = false;

    // Command handler dispatch table
    std::unordered_map<Command, std::function<void()>> handlers = {
        // Meta Commands
        { Command::HELP,     [&](){ handleHelp(word2); } },
        { Command::VERBS,    [&](){ handleVerbs(); } },
        { Command::SAVE,     [&](){ cout << "Save not implemented yet." << endl; } },
        { Command::LOAD,     [&](){ cout << "Load not implemented yet." << endl; } },
        { Command::QUIT,     [&](){ if (handleQuit()) {quit = true;} } },
        // In-game Commmands
        { Command::GO,       [&](){ handleGo(player, phrase); } },
        { Command::INSERT,   [&](){ handleInsert(player, word2, word3); } }, // Placeholder
        { Command::LOOK,     [&](){ handleLook(player, phrase); } },
        { Command::MOVE,     [&](){ handleMove(player, phrase); } },
        { Command::READ,     [&](){ handleRead(player, phrase); } },
        { Command::TALK,     [&](){ handleTalk(player, phrase); } },
        { Command::LEAVE,    [&](){ cout << "Leave not implemented yet." << endl; } },
        { Command::TAKE,     [&](){ handleTake(player, phrase); } },
        { Command::HIT,      [&](){ cout << "Hit not implemented yet." << endl; } },
        { Command::USE,      [&](){ handleUse(player, phrase); } },
        { Command::EQUIP,    [&](){ cout << "Equip not implemented yet." << endl; } },
        { Command::UNEQUIP,  [&](){ cout << "Unequip not implemented yet." << endl; } },
        { Command::DISCARD,  [&](){ cout << "Discard not implemented yet." << endl; } },
        { Command::INVENTORY,[&](){ handleInventory(player); } },
        { Command::EQUIPPED, [&](){ cout << "Equipped not implemented yet." << endl; } },
        { Command::STATUS,   [&](){ handleStatus(player); } },
        { Command::BUY,      [&](){ cout << "Buy not implemented yet." << endl; } },
        { Command::SELL,     [&](){ cout << "Sell not implemented yet." << endl; } },
        // Battle Commands
        { Command::ATTACK,   [&](){ cout << "Attack not implemented yet." << endl; } },
        { Command::SKILL,    [&](){ cout << "Skill not implemented yet." << endl; } },
        { Command::DEFEND,   [&](){ cout << "Defend not implemented yet." << endl; } },
        { Command::FLEE,     [&](){ cout << "Flee not implemented yet." << endl; } },
        // Debug command
        { Command::GIVEEXP, [&](){player.addExperience(100); cout << "Gave 100 EXP to player." << endl;} } 
        // The debug command is here solely to test the leveling system and is not intended for use in the game
    };

    // Start up dialogue
    introPrint();
    choosePlayerClass(player);  // cannot quit whilst choosing class - very minor issue
    while(!quit)
    {
        cout << "> ";
        getline(cin, input);
        // Placeholder - prints raw input
        cout << termcolor::grey << termcolor::on_cyan <<"Raw command: " << input << termcolor::reset << endl;

        interpretInput(input, word1, word2, word3, phrase);
        try {
            command = parseCommand(word1); // This will actually turn the user input into a command type
        } catch (const std::invalid_argument&) {
            cout << "I do not recognise the command: \'" << word1 << "\', run the \'verbs\' command if you are unsure of the commands you can do." << endl;
            command = Command::UNKNOWN;
            continue;
        }

        // Use the table
        auto it = handlers.find(command);
        if (it != handlers.end()) {
            it->second();
        } else {
            cout << "Unknown or unhandled command." << endl;
        }
    }
    return 0;
}