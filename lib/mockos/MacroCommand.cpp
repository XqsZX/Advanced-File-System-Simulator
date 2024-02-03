#include "../../include/mockos/MacroCommand.h"
#include <iostream>

MacroCommand::MacroCommand() : parseStrategy(nullptr), fileSystem(nullptr) {}

MacroCommand::MacroCommand(AbstractFileSystem* fs) : parseStrategy(nullptr), fileSystem(fs) {}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
    parseStrategy = strategy;
}

void MacroCommand::addCommand(AbstractCommand* cmd) {
    commands.push_back(cmd);
}

int MacroCommand::execute(std::string args) {
    if (!parseStrategy) {
        std::cerr << "Parse strategy not set" << std::endl;
        return -1;
    }

    std::vector<std::string> parsedArgs = parseStrategy->parse(args);
    if (parsedArgs.size() != commands.size()) {
        std::cerr << "Error: Mismatch between commands and arguments" << std::endl;
        return -1;
    }

    for (size_t i = 0; i < commands.size(); ++i) {
        int result = commands[i]->execute(parsedArgs[i]);
        if (result != 0) {
            return result;
        }
    }

    return 0; // Success
}

void MacroCommand::displayInfo() {
    std::cout << "Executes a series of commands. Usage depends on the configured commands and parsing strategy." << std::endl;
}
