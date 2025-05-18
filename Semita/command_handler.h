#pragma once
#include <string>

class Player;

std::string capitaliseNoun(std::string& input);
void handleHelp(); 
void handleGo(Player& player, const std::string& arg);