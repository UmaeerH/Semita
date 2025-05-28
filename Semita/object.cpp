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
    { "Seashell", "Looks beautiful. This could be valuable", 15 },
    { "Boulder", "A large boulder. It looks immovable and too heavy to pick up", 0 }
};

// Object location table - affects when the player can interact with the object
const std::unordered_map<std::string, std::string> objectLocationTable = {
    { "Note", "Inventory" }, // For now, inventory will represent if the player has the item.
    { "Leather Helmet", "Fields" },
    { "Small Sack", "Fields" },
    { "Purple Herb", "Woodlands" },
    { "Seashell", "Shore" },
    { "Boulder", "Fields" } // Example of an object that cannot be picked up
};

// Read Table (for the "read" command)
const std::unordered_map<std::string, std::string> itemReadTable = {
    { "Note", "Hi there adventurer. I've noticed you don't seem to be from this area. I advise you talk to the Guard in the town" }
};

// Take table (for the "take" command)
const std::unordered_map<std::string, std::pair<std::string, bool>> itemTakeTable = {
    { "Boulder", { "You cannot take this boulder. It is too heavy.", false } },
    { "Small Sack", { "You pick up the small sack and put the contents in your pockets.", true } },
    { "Leather Helmet", { "You take the helmet. It seems a bit uncomfortable, but it might protect you.", true } },
    { "Purple Herb", { "You carefully pick up the purple herb, trying not to touch it with your bare hands.", true } },
    { "Seashell", { "You pick up the seashell and admire its beauty.", true } }
};

// Accessor functions 
const std::vector<GameObject>& getObjectTable()                                         { return objectTable; }
const std::unordered_map<std::string, std::string>& getObjectLocationTable()            { return objectLocationTable; }
const std::unordered_map<std::string, std::string>& getItemReadTable()                  { return itemReadTable; }
const std::unordered_map<std::string, std::pair<std::string, bool>>& getItemTakeTable() { return itemTakeTable; }