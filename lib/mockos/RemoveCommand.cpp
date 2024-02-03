#include "../../include/mockos/RemoveCommand.h"
#include <iostream>

RemoveCommand::RemoveCommand(AbstractFileSystem* fs) : fileSystem(fs) {}

void RemoveCommand::displayInfo() {
    std::cout << "Removes a file from the file system. Usage: rm <filename>" << std::endl;
}

int RemoveCommand::execute(std::string filename) {
    filename.erase(0, filename.find_first_not_of(' ')); // Leading spaces
    filename.erase(filename.find_last_not_of(' ') + 1); // Trailing spaces

    int result = fileSystem->deleteFile(filename);
    if (result == -1) {
        std::cout << "File does not exist." << std::endl;
    }
    else if (result == -2) {
        std::cout << "File is currently open and cannot be deleted." << std::endl;
    }
    else if (result != 0) {
        std::cout << "An unknown error occurred: " << result << std::endl;
    }
    return result;
}
