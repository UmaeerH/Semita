#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct GameObject {
    std::string objectName;
    std::string objectDescription;
    int value;

    GameObject(const std::string& name, const std::string& desc, int val)
        : objectName(name), objectDescription(desc), value(val) {}
};

const std::vector<GameObject>& getObjectTable();
const std::unordered_map<std::string, std::string>& getObjectLocationTable();
const std::unordered_map<std::string, std::string>& getItemReadTable();