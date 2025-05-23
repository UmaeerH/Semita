#include "object.h"
#include <unordered_map>


const std::vector<GameObject>& getObjectTable() {
    static const std::vector<GameObject> table = {
        { "Note", "A starting note given to the player from the very beginning", 0 },
        { "Leather Helmet", "A worn leather cap. Probably won't protect against anything more than a humble pebble", 10 },
        { "Small Sack", "A small brown sack. Looks like it has coins inside", 30 },
        { "Purple Herb", "A mysterious and alluring piece of vegetation. Probably best not to touch this with your bare hands", 0 },
        { "Seashell", "Looks beautiful. This could be valuable", 15 }
    };
    return table;
}

//  Object location table
const std::unordered_map<std::string, std::string>& getObjectLocationTable() {
    static const std::unordered_map<std::string, std::string> locationTable = {
        { "Note", "Inventory" },
        { "Leather Helmet", "Fields" },
        { "Small Sack", "Fields" },
        { "Purple Herb", "Woodlands" },
        { "Seashell", "Shore" }
    };
    return locationTable;
}