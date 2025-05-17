#include "command_handler.h"
#include <iostream>
#include "player.h"



using namespace std;

void handleHelp() {
    cout << "Help: Available commands are go, look, take, use, etc." << endl;
}

void handleGo(Player& player, const std::string& arg) {
    cout << "Moving from " << player.getLocation() << " to " << arg << endl;
    player.setLocation(arg);
    cout << "You are now at: " << arg << endl;
}