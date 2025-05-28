// For random functions

#pragma once
#include <string>
#include <vector>
#include "player.h"
#include "object.h"
#include "npc.h"

void introPrint();

int choosePlayerClass(Player& player);
std::string playerClassToString(PlayerClass pc);

void interpretInput(std::string& input, std::string& word1, std::string& word2, std::string& word3, std::string& phrase);
std::string capitaliseNoun(const std::string& input);
std::string formatList(const std::vector<std::string>& items);
bool isLocal(const std::string& entityLocation, const Player& player);
bool printLookDescription(const std::string& name, const Player& player);