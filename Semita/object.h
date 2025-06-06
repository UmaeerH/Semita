#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include "player.h"

struct GameObject {
    std::string objectName;
    std::string objectDescription;
    int value;

    GameObject(const std::string& name, const std::string& desc, int val)
        : objectName(name), objectDescription(desc), value(val) {}
};

struct MoveEntry {
    std::string dialogue;
    bool hasBeenMoved;
};

const std::vector<GameObject>& getObjectTable();
const std::unordered_map<std::string, std::string>& getObjectLocationTable();
const std::unordered_map<std::string, std::string>& getItemReadTable();
const std::unordered_map<std::string, std::pair<std::string, bool>>& getItemTakeTable();
const std::unordered_map<std::string, MoveEntry>& getItemMoveTable();
const std::unordered_map<std::string, std::function<void(Player&)>>& getItemUseTable();

void toInventory(const std::string& objectName);