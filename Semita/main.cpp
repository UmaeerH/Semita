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

using namespace std;

/* 
TODO: Make the help command more useful ✅ 
TODO: Add a function to handle the "verbs" command ✅
TODO: Make noun list and populate from the table 
TODO: Make commands not case sensitive ✅
TODO: Make a description for each stage - and it reads this description when you enter the stage ✅
TODO: Make a description for each command - and it reads this description when you enter the help command ✅
TODO: Make player class more useful - HP, Mana, inventory, etc.

TODO: Battle system
TODO: NPCs to talk to

*/
int main()
{
    string input; // The entire input
    string word1; // The verb/command
    string word2; // The noun/item
    Command command = Command::UNKNOWN;
    Player player;

    // Command handler dispatch table
    std::unordered_map<Command, std::function<void()>> handlers = {
        { Command::HELP,    [&](){ handleHelp(word2); } },
        { Command::GO,      [&](){ handleGo(player, word2); } },
        { Command::VERBS,   [&](){ handleVerbs(); } },
        { Command::LOOK,    [&](){ handleLook(player, word2); } }
        // Add more commands and handlers as needed
    };

    cout << "Player is at: " << player.getLocation() << endl;

    while(command != Command::QUIT)
    {
        cout << "> ";
        getline(cin, input);
        // Placeholder - prints raw input
        cout << termcolor::grey << termcolor::on_cyan <<"Raw command: " << input << termcolor::reset << endl;

        word1.clear();
        word2.clear();
        size_t pos = input.find(' ');
        if (pos != string::npos) {
            word1 = input.substr(0, pos);
            size_t first_non_space = input.find_first_not_of(' ', pos + 1);
            if (first_non_space != string::npos) {
                word2 = input.substr(first_non_space);
            }
        } else {
            word1 = input;
        }

        std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
        word2 = capitaliseNoun(word2); // Capitalise the noun

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
            it->second(); // Call the handler
        } else if (command != Command::QUIT) {
            cout << "Unknown or unhandled command." << endl;
        }
    }
    return 0;
}
