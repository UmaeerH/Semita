#pragma once
#include <string>
#include <vector>

struct GameObject {
    std::string objectName;
    std::string objectDescription;
    int value;

    GameObject(const std::string& name, const std::string& desc, int val)
        : objectName(name), objectDescription(desc), value(val) {}
};

// Returns a const reference to the static object table
const std::vector<GameObject>& getObjectTable();