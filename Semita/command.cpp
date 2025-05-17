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