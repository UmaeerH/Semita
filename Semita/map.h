#pragma once
#include <string>
#include <vector>

// Free function declaration
bool checkNeighbours(const std::string& from, const std::string& to);
bool locationExists(const std::string& location);
std::string getLocationDescription(const std::string& location);
std::vector<std::string> getAdjacentLocations(const std::string& location);