#pragma once
#include <string>

class Player;

void handleHelp(); // TODO: Implement help command
void handleGo(Player& player, const std::string& arg);