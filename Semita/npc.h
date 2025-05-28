#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct NPC {
    std::string name;
    std::string location;

    NPC(const std::string& n, const std::string& loc)
        : name(n), location(loc) {}
};

const std::vector<NPC>& getNPCTable();
const std::unordered_map<std::string, std::string>& getNPCDialogueTable();
const std::unordered_map<std::string, std::string>& getNPCLookTable();