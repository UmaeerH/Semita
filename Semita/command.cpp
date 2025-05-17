#include "command.h"
#include <unordered_map>
#include <stdexcept>

Command parseCommand(const std::string& input) {
    static const std::unordered_map<std::string, Command> commandMap = {
        {"HELP", Command::HELP},
        {"VERBS", Command::VERBS},
        {"SAVE", Command::SAVE},
        {"LOAD", Command::LOAD},
        {"QUIT", Command::QUIT},
        {"GO", Command::GO},
        {"INSERT", Command::INSERT},
        {"LOOK", Command::LOOK},
        {"MOVE", Command::MOVE},
        {"READ", Command::READ},
        {"TALK", Command::TALK},
        {"LEAVE", Command::LEAVE},
        {"TAKE", Command::TAKE},
        {"HIT", Command::HIT},
        {"USE", Command::USE},
        {"BUY", Command::BUY},
        {"SELL", Command::SELL},
        {"EQUIP", Command::EQUIP},
        {"UNEQUIP", Command::UNEQUIP},
        {"DISCARD", Command::DISCARD},
        {"INVENTORY", Command::INVENTORY},
        {"EQUIPPED", Command::EQUIPPED},
        {"ATTACK", Command::ATTACK},
        {"SKILL", Command::SKILL},
        {"DEFEND", Command::DEFEND},
        {"FLEE", Command::FLEE},
        {"STATUS", Command::STATUS}
    };

    std::string upperInput = input;
    for (char& c : upperInput) {
        c = toupper(c);
    }

    auto it = commandMap.find(upperInput);
    if (it != commandMap.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Invalid command");
    }
}