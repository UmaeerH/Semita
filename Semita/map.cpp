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

// Descriptions for each location
static const std::unordered_map<std::string, std::string> locationDescriptions = {
    {"Town", "A small, friendly town, located in a vast green landscape."},
    {"Woodlands", "A forest filled with tall trees."},
    {"Fields", "Open fields with tall grass swaying in the wind."},
    {"Shore", "A sandy shore with waves gently lapping the land."},
    {"Fishing village", "A small village, it seems pretty abandoned."},
    {"Mountain path", "A rocky path winding up the mountain."},
    {"Mountain shrine", "An ancient shrine."},
    {"Mountain peak", "The highest point."},
    {"Deep Woodlands", "Dark tall trees, dense vegetation and silence."},
    {"Cave Entrance", "A shadowy cave entrance."},
    {"Deep Cave", "Pitch darkness."},
    {"Pilgrim's path", "A well-trodden path used by travelers and pilgrims."},
    {"Desert", "A vast, arid desert with rolling dunes."},
    {"Desert Temple", "A mysterious temple buried in the sands."},
    {"Oasis", "A lush oasis with palm trees and fresh water."},
    {"Desert village", "A small village located within the desert."}
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

std::string getLocationDescription(const std::string& location) {
    auto it = locationDescriptions.find(location);
    if (it != locationDescriptions.end()) {
        return it->second;
    }
    return "No description available.";
}