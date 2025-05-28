#include "npc.h"

// NPC table
const std::vector<NPC> npcTable = {
    { "Shopkeeper", "Town" },
    { "Guard", "Town" },
    { "Desert Merchant", "Desert Village" },
    { "Elder", "Pilgrim's Path" },
    { "Camel", "Oasis" }
};

// NPC dialogue table
const std::unordered_map<std::string, std::string> npcDialogueTable = {
    { "Shopkeeper", "Hi there, looking to buy something?" },
    { "Guard", "I haven\'t seen you before, new around here?" },
    { "Desert Merchant", "Hey check out my new stock!" },
    { "Elder", "Young one, I sense you are not from this world" },
    { "Camel", "*camel noises*" }
};

// Accessor functions
const std::vector<NPC>& getNPCTable() { return npcTable; }
const std::unordered_map<std::string, std::string>& getNPCDialogueTable() { return npcDialogueTable; }