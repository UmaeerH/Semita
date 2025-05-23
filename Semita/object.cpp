#include "object.h"
#include <unordered_map>
#include <vector>
#include <string>

// Object table 
const std::vector<GameObject> objectTable = {
    { "Note", "A starting note.  Maybe reading it can be useful. Hint: read <item>", 0 },
    { "Leather Helmet", "A worn leather cap. Probably won't protect against anything more than a humble pebble", 10 },
    { "Small Sack", "A small brown sack. Looks like it has coins inside", 30 },
    { "Purple Herb", "A mysterious and alluring piece of vegetation. Probably best not to touch this with your bare hands", 0 },
    { "Seashell", "Looks beautiful. This could be valuable", 15 }
};

// Object location table - affects when the player can interact with the object
const std::unordered_map<std::string, std::string> objectLocationTable = {
    { "Note", "Inventory" },
    { "Leather Helmet", "Fields" },
    { "Small Sack", "Fields" },
    { "Purple Herb", "Woodlands" },
    { "Seashell", "Shore" }
};

// Read Table (for the "read" command)
const std::unordered_map<std::string, std::string> itemReadTable = {
    { "Note", "Hi there adventurer. I've noticed you don't seem to be from this area. I advise you talk to the Guard in the town" }
};

// Accessor functions 
const std::vector<GameObject>& getObjectTable() { return objectTable; }
const std::unordered_map<std::string, std::string>& getObjectLocationTable() { return objectLocationTable; }
const std::unordered_map<std::string, std::string>& getItemReadTable() { return itemReadTable; }