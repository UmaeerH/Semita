#pragma once
#include <string>

enum class Command {
    UNKNOWN,
    // Meta Commands:
    HELP,
    VERBS,
    SAVE,
    LOAD,
    QUIT,
    // Game Commands:
    GO,
    INSERT,
    LOOK,
    MOVE,
    READ,
    TALK,
    LEAVE,
    TAKE,
    HIT,
    USE,
    BUY,
    SELL,
    EQUIP,
    UNEQUIP,
    DISCARD,
    INVENTORY,
    EQUIPPED,
    // Battle Commands:
    ATTACK,
    SKILL,
    DEFEND,
    FLEE,
    STATUS,
    // Debug Commands:
    GIVEEXP
};

Command parseCommand(const std::string& input);
std::string getCommandDescription(Command command);