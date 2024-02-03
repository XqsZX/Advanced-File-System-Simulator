#include "../../include/mockos/CommandPrompt.h"
#include <iostream>

CommandPrompt::CommandPrompt() : fileSystem(nullptr), fileFactory(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* fs) {
    fileSystem = fs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* ff) {
    fileFactory = ff;
}

int CommandPrompt::addCommand(const std::string& commandName, AbstractCommand* command) {
    auto result = commands.insert(std::make_pair(commandName, command));
    if (result.second) {
        return 0; // Success
    }
    return 1; // Failure (command already exists)
}

void CommandPrompt::listCommands() const {
    for (const auto& command : commands) {
        std::cout << command.first << std::endl;
    }
}

std::string CommandPrompt::prompt() const {
    std::cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << std::endl;
    std::cout << "$ ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int CommandPrompt::run() {
    while (true) {
        std::string input = prompt();
        std::istringstream iss(input);
        std::string command;
        iss >> command;

        if (command == "q") {
            return 1; // Quit command
        }
        else if (command == "help") {
            if (iss >> command) {
                auto it = commands.find(command);
                if (it != commands.end()) {
                    it->second->displayInfo();
                }
                else {
                    std::cout << "Command not found." << std::endl;
                }
            }
            else {
                listCommands();
            }
        }
        else {
            auto it = commands.find(command);
            if (it != commands.end()) {
                std::string args;
                getline(iss, args);
                int result = it->second->execute(args);
                if (result != 0) {
                    std::cout << "Command failed." << std::endl;
                }
            }
            else {
                std::cout << "Command not found." << std::endl;
            }
        }
    }
}
