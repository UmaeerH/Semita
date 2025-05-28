#pragma once
#include <string>

class Player;

std::string capitaliseNoun(std::string& input);
// Meta Commands
void handleHelp(const std::string& arg); 
void handleVerbs();
bool handleQuit();
// In-game Commands
void handleGo(Player& player, const std::string& arg);
void handleInsert(Player& player, const std::string& arg1, const std::string& arg2);
void handleLook(Player& player, const std::string& arg);
void handleTake(Player& player, const std::string& arg);
void handleUse(Player& player, const std::string& arg);
void handleMove(Player& player, const std::string& arg);
void handleTalk(Player& player, const std::string& arg);
void handleRead(Player& player, const std::string& arg);
void handleInventory(Player& player);
void handleStatus(Player& player);
// Debug Commands
void handleEXP(Player& player, const std::string& arg);