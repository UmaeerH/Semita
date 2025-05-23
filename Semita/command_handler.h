#pragma once
#include <string>

class Player;

std::string capitaliseNoun(std::string& input);
void handleHelp(const std::string& arg = ""); 
void handleVerbs();

void handleGo(Player& player, const std::string& arg);
void handleInsert(Player& player, const std::string& arg1, const std::string& arg2);
void handleLook(Player& player, const std::string& arg);
// Handle Move
void handleRead(Player& player, const std::string& arg);
void handleStatus(Player& player);