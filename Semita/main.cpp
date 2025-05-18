// Library imports
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

// Program imports
#include "command.h"
#include "command_handler.h"
#include "player.h"

using namespace std;

/* 
TODO: Make the help command more useful ✅
TODO: Add a function to handle the "verbs" command 
TODO: Make noun list and populate from the table
TODO: Make commands not case sensitive
TODO: Make a description for each stage - and it reads this description when you enter the stage
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
    cout << "Player is at: " << player.getLocation() << endl;

    while(command != Command::QUIT)
    {
        cout << "> ";
        getline(cin, input);
        cout << "Raw command: " << input << endl;     // Placeholder, prints the input
        
        //Parse the command into words, split between spaces
        word1.clear();
        word2.clear();
        size_t pos = input.find(' ');

        if (pos != string::npos) {
            word1 = input.substr(0, pos);
            // Remove any leading spaces from word2
            size_t first_non_space = input.find_first_not_of(' ', pos + 1);
            if (first_non_space != string::npos) {
                word2 = input.substr(first_non_space);
            }
        } else {
            word1 = input;
        }

        try {
            command = parseCommand(word1); // This will actually turn the user input into a command type
        } catch (const std::invalid_argument&) {
            cout << "I do not recognise the command: \'" << word1 << "\', run the \'verbs\' command if you are unsure of the commands I can do." << endl;
            command = Command::UNKNOWN;
            continue;
        }

        // Help Command
        if (command == Command::HELP) {
            handleHelp();
        }

        // Go Command
        else if (command == Command::GO) {
            handleGo(player, word2);
        }

        /*
        cout << "You would like to " << word1;
        if (!word2.empty()) {
            cout << " the " << word2;
        }
        cout << "?" << endl; // test statement
        */
       
    }
    return 0;
}
