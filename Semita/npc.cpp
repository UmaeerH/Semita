#include "npc.h"

// NPC table
const std::vector<NPC> npcTable = {
    { "Shopkeeper", "Town" },
    { "Guard", "Town" },
    { "Desert Merchant", "Desert Village" },
    { "Elder", "Pilgrim's Path" },
    { "Camel", "Oasis" },
    { "Rabbit", "Fields" }
};

// NPC dialogue table
const std::unordered_map<std::string, std::string> npcDialogueTable = {
    { "Shopkeeper", "Hi there, looking to buy something?" },
    { "Guard", "I haven\'t seen you before, new around here?" },
    { "Desert Merchant", "Hey check out my new stock!" },
    { "Elder", "Young one, I sense you are not from this world" },
    { "Camel", "*camel noises*" },
    { "Rabbit", "The rabbit hops away quickly. It stops a few meters away" }
};

// NPC look/description table
const std::unordered_map<std::string, std::string> npcLookTable = {
    { "Shopkeeper", "A friendly shopkeeper with a wide array of goods." },
    { "Guard", "A stern-looking guard. I'm sure he protects this town." },
    { "Desert Merchant", "A merchant dressed in desert robes, eager to trade." },
    { "Elder", "An old, thin man. Grey hair, long beard, must be a hermit." },
    { "Camel", "A regular camel." },
    { "Rabbit", "A small, fluffy rabbit. It seems to be watching you." }
};

// Accessor functions
const std::vector<NPC>& getNPCTable() { return npcTable; }
const std::unordered_map<std::string, std::string>& getNPCDialogueTable() { return npcDialogueTable; }
const std::unordered_map<std::string, std::string>& getNPCLookTable() { return npcLookTable; }