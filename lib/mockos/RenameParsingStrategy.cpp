#include "../../include/mockos/RenameParsingStrategy.h"
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
    std::istringstream iss(input);
    std::string existingFile, newName;
    iss >> existingFile >> newName;

    // Constructing commands for Copy and Remove
    return { existingFile + " " + newName, existingFile };
}
