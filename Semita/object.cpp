#include "object.h"


const std::vector<GameObject>& getObjectTable() {
    static const std::vector<GameObject> table = {
        { "Note", "A starting note given to the player from the very beginning", 0 },
        { "Leather Helmet", "A worn leather cap. Probably won\'t protect against anything more than a humble pebble", 2 }
    };
    return table;
}