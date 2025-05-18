#pragma once
#include <string>

class Player;

void handleHelp(); 
void handleGo(Player& player, const std::string& arg);