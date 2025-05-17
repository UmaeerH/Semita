// Library imports
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

// Program imports
#include "command.h"

using namespace std;

int main()
{
    string input;
    string word1;
    string word2;
    Command command = Command::UNKNOWN;
   
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
            cout << "Unknown command: " << word1 << endl;
            command = Command::UNKNOWN;
            continue;
        }

        cout << "You would like to " << word1;
        if (!word2.empty()) {
            cout << " the " << word2;
        }
        cout << "?" << endl; // test statement

    }
    return 0;
}
