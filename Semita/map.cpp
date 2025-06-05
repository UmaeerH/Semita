#include "map.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

// Map layout
static const std::unordered_map<std::string, std::vector<std::string>> adjacencyList = {
    {"Town", {"Woodlands", "Fields", "Pilgrim's Path"}},
    {"Woodlands", {"Town", "Deep Woodlands"}},
    {"Fields", {"Town", "Shore", "Mountain Path"}},
    {"Shore", {"Fields", "Fishing Village"}},
    {"Fishing Village", {"Shore"}},
    {"Mountain Path", {"Fields", "Mountain Shrine"}},
    {"Mountain Shrine", {"Mountain Path", "Mountain Peak"}},
    {"Mountain Peak", {"Mountain Shrine"}},
    {"Deep Woodlands", {"Cave Entrance", "Woodlands"}},
    {"Cave Entrance", {"Deep Cave", "Deep Woodlands"}},
    {"Deep Cave", {"Cave Entrance"}},
    {"Pilgrim's Path", {"Town", "Desert"}},
    {"Desert", {"Desert Temple", "Pilgrim's Path", "Oasis", "Desert Village"}},
    {"Desert Temple", {"Desert"}},
    {"Oasis", {"Desert", "Desert Village"}},
    {"Desert Village", {"Oasis", "Desert"}}
};

// Descriptions for each location
static const std::unordered_map<std::string, std::string> locationDescriptions = {
    {"Town", "A small, friendly town, located in a vast green landscape."},
    {"Woodlands", "A forest filled with tall trees."},
    {"Fields", "Open fields with tall grass swaying in the wind."},
    {"Shore", "A sandy shore with waves gently lapping the land."},
    {"Fishing Village", "A small village, it seems pretty abandoned."},
    {"Mountain Path", "A rocky path winding up the mountain."},
    {"Mountain Shrine", "An ancient shrine."},
    {"Mountain Peak", "The highest point."},
    {"Deep Woodlands", "Dark tall trees, dense vegetation and silence."},
    {"Cave Entrance", "A shadowy cave entrance."},
    {"Deep Cave", "Pitch darkness."},
    {"Pilgrim's Path", "A well-trodden path used by travelers and pilgrims."},
    {"Desert", "A vast, arid desert with rolling dunes."},
    {"Desert Temple", "A mysterious temple buried in the sands."},
    {"Oasis", "A lush oasis with palm trees and fresh water."},
    {"Desert Village", "A small village located within the desert."}
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

std::vector<std::string> getAdjacentLocations(const std::string& location) {
    auto it = adjacencyList.find(location);
    if (it != adjacencyList.end()) {
        return it->second;
    }
    return {};
}
