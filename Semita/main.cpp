#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string command;
    string word1;
    string word2;
   
    while(command != "QUIT")
    {
        command.clear();
        cout << "> ";
        getline(cin, command);
        cout << "Raw command: " << command << endl;     // Placeholder, prints the input
        //Parse the command into words
        word1.clear();
        word2.clear();
        size_t pos = command.find(' ');
        if (pos != string::npos) {
            word1 = command.substr(0, pos);
            word2 = command.substr(pos + 1);
        } else {
            word1 = command;
        }
        cout << "You would like to " << word1 << " the " << word2 << "?" << endl; // test statement

    }
    return 0;
}
