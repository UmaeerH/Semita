// For random functions

#pragma once
#include <string>
#include "player.h"

void introPrint();
int choosePlayerClass(Player& player);
void interpretInput(std::string& input, std::string& word1, std::string& word2, std::string& word3, std::string& phrase);
std::string capitaliseNoun(std::string& input);