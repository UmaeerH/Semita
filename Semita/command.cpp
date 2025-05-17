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
        {"save", Command::SAVE},
        {"load", Command::LOAD},
        {"go", Command::GO},
        {"insert", Command::INSERT},
        {"look", Command::LOOK},
        {"move", Command::MOVE},
        {"read", Command::READ},
        {"talk", Command::TALK},
        {"leave", Command::LEAVE},
        {"take", Command::TAKE},
        {"hit", Command::HIT},
        {"use", Command::USE},
        {"buy", Command::BUY},
        {"sell", Command::SELL},
        {"equip", Command::EQUIP},
        {"unequip", Command::UNEQUIP},
        {"discard", Command::DISCARD},
        {"inventory", Command::INVENTORY},
        {"equipped", Command::EQUIPPED},
        {"attack", Command::ATTACK},
        {"skill", Command::SKILL},
        {"defend", Command::DEFEND},
        {"flee", Command::FLEE},
        {"status", Command::STATUS}
    };

    std::string cmd = input;
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    auto it = commandMap.find(cmd);
    if (it != commandMap.end()) {
        return it->second;
    }
    throw std::invalid_argument("Unknown command");
}