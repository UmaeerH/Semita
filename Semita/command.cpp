#include "command.h"
#include <algorithm>
#include <stdexcept>
#include <unordered_map>

Command parseCommand(const std::string& input) {
    static const std::unordered_map<std::string, Command> commandMap = {
        {"quit", Command::QUIT},
        {"exit", Command::QUIT},
        {"help", Command::HELP},
        {"verbs", Command::VERBS},
        {"commands", Command::VERBS},   // Alias
        {"cmds", Command::VERBS},       // Alias 
        {"v", Command::VERBS},          // Alias 
        {"save", Command::SAVE},
        {"load", Command::LOAD},
        {"go", Command::GO},
        {"travel", Command::GO},        // Alias
        {"insert", Command::INSERT},
        {"put", Command::INSERT}, //a
        {"look", Command::LOOK},
        {"inspect", Command::LOOK}, //a
        {"view", Command::LOOK}, //a
        {"move", Command::MOVE},
        {"press", Command::MOVE}, //a
        {"read", Command::READ},
        {"talk", Command::TALK},
        {"speak", Command::TALK}, //a
        {"leave", Command::LEAVE},
        {"take", Command::TAKE},
        {"hit", Command::HIT},
        {"kick", Command::HIT}, //a
        {"use", Command::USE},
        {"buy", Command::BUY},
        {"purchase", Command::BUY}, //a
        {"sell", Command::SELL},
        {"equip", Command::EQUIP},
        {"unequip", Command::UNEQUIP},
        {"discard", Command::DISCARD},
        {"inventory", Command::INVENTORY},
        {"i", Command::INVENTORY}, //a
        {"storage", Command::INVENTORY}, //a
        {"equipped", Command::EQUIPPED},
        {"e", Command::EQUIPPED}, //a
        {"attack", Command::ATTACK},
        {"skill", Command::SKILL},
        {"defend", Command::DEFEND},
        {"flee", Command::FLEE},
        {"status", Command::STATUS},
        {"s", Command::STATUS} //a
    };

    std::string cmd = input;
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    auto it = commandMap.find(cmd);
    if (it != commandMap.end()) {
        return it->second;
    }
    throw std::invalid_argument("Unknown command");
}

// Command descriptions
static const std::unordered_map<Command, std::string> commandDescriptions = {
    {Command::QUIT, "Exit the game."},
    {Command::HELP, "Show help information. Usage: help <command>"},
    {Command::VERBS, "List all available commands. \nAlias: commands, cmds, v"},
    {Command::SAVE, "Save your current progress."},
    {Command::LOAD, "Load a saved game."},
    {Command::GO, "Move to another location. Usage: go <location> \nAlias: travel"},
    {Command::INSERT, "Insert an item somewhere. Usage: insert <item> <location> \nAlias: put"},
    {Command::LOOK, "Look around the area or inspect something. Usage: look [object]\nGreen text indicates an object you can interact with. Cyan text indicates an NPC you can interact with.\nAlias: inspect, view"},
    {Command::MOVE, "Move an item around. Usage: move <item> \nAlias: press"},
    {Command::READ, "Read an item or sign. Usage: read <item>"},
    {Command::TALK, "Talk to someone. Usage: talk <person> \nAlias: speak"},
    {Command::LEAVE, "Leave the current dialogue."},
    {Command::TAKE, "Take an item. Usage: take <item>"},
    {Command::HIT, "Hit something or someone. Usage: hit <object> \nAlias: kick"},
    {Command::USE, "Use an item. Usage: use <item>"},
    {Command::BUY, "Buy an item. Usage: buy <item> \nAlias: purchase"},
    {Command::SELL, "Sell an item. Usage: sell <item>"},
    {Command::EQUIP, "Equip an item. Usage: equip <item>"},
    {Command::UNEQUIP, "Unequip an item. Usage: unequip <item>"},
    {Command::DISCARD, "Discard an item. Usage: discard <item>"},
    {Command::INVENTORY, "Show your inventory. \nAlias: i, storage"},
    {Command::EQUIPPED, "Show equipped items. \nAlias: e"},
    {Command::ATTACK, "Attack an enemy Optional to specify an enemy. Usage: attack [enemy]"},
    {Command::SKILL, "Use a skill. Usage: skill <skill_name> [enemy]"},
    {Command::DEFEND, "Defend for the next turn."},
    {Command::FLEE, "Attempt to run away from battle."},
    {Command::STATUS, "Show your current stats. \nAlias: s"},
    {Command::UNKNOWN, "Unknown command."}
};

// Helper function to get a command description by Command::TYPE
std::string getCommandDescription(Command command) {
    auto it = commandDescriptions.find(command);
    if (it != commandDescriptions.end()) {
        return it->second;
    }
    return "No description available for this command.";
}