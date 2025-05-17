#include "map.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

// Map layout
static const std::unordered_map<std::string, std::vector<std::string>> adjacencyList = {
    {"Town", {"Woodlands", "Fields", "Pilgrim\'s Path"}},
    {"Woodlands", {"Town", "Deep Woodlands"}},
    {"Fields", {"Town", "Shore"}},
    {"Shore", {"Fields"}}
};

bool checkNeighbours(const std::string& from, const std::string& to) {
    auto it = adjacencyList.find(from);
    if (it == adjacencyList.end()) return false;
    const auto& neighbours = it->second;
    return std::find(neighbours.begin(), neighbours.end(), to) != neighbours.end();
}