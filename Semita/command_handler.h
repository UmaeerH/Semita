#pragma once
#include <string>

class Player;

std::string capitaliseNoun(std::string& input);
void handleHelp(const std::string& arg = ""); 
void handleGo(Player& player, const std::string& arg);
void handleVerbs();
void handleLook(Player& player, const std::string& arg);
void handleStatus(Player& player);