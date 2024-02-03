#include "../../include/mockos/DisplayCommand.h"
#include "../../include/mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>

DisplayCommand::DisplayCommand(AbstractFileSystem* fs) : fileSystem(fs) {}

void DisplayCommand::displayInfo() {
    std::cout << "Displays the contents of a file. Usage: ds <filename> [-d]" << std::endl;
}

int DisplayCommand::execute(std::string args) {
    std::istringstream iss(args);
    std::string filename, option;
    iss >> filename >> option;

    AbstractFile* file = fileSystem->openFile(filename);
    if (file == nullptr) {
        return 1;
    }

    if (option == "-d") {
        std::vector<char> contents = file->read();
        for (char ch : contents) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
    else {
        // Formatted display
        BasicDisplayVisitor visitor;
        file->accept(&visitor);
    }

    fileSystem->closeFile(file);
    return 0;
}
