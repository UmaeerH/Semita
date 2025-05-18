#include "map.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

// Map layout
static const std::unordered_map<std::string, std::vector<std::string>> adjacencyList = {
    {"Town", {"Woodlands", "Fields", "Pilgrim's path"}},
    {"Woodlands", {"Town", "Deep Woodlands"}},
    {"Fields", {"Town", "Shore", "Mountain path"}},
    {"Shore", {"Fields", "Fishing village"}},
    {"Fishing village", {"Shore"}},
    {"Mountain path", {"Fields", "Mountain shrine"}},
    {"Mountain shrine", {"Mountain path", "Mountain peak"}},
    {"Mountain peak", {"Mountain shrine"}},
    {"Deep Woodlands", {"Cave Entrance", "Woodlands"}},
    {"Cave Entrance", {"Deep Cave", "Deep Woodlands"}},
    {"Deep Cave", {"Cave Entrance"}},
    {"Pilgrim's path", {"Town", "Desert"}},
    {"Desert", {"Desert Temple", "Pilgrim's path", "Oasis", "Desert village"}},
    {"Desert Temple", {"Desert"}},
    {"Oasis", {"Desert", "Desert village"}},
    {"Desert village", {"Oasis", "Desert"}}
};

bool locationExists(const std::string& location) {
    return adjacencyList.find(location) != adjacencyList.end();
}

bool checkNeighbours(const std::string& from, const std::string& to) {
    auto it = adjacencyList.find(from);
    if (it == adjacencyList.end()) return false;
    const auto& neighbours = it->second;
    return std::find(neighbours.begin(), neighbours.end(), to) != neighbours.end();
}