#include "../../include/mockos/TouchCommand.h"
#include <iostream>

TouchCommand::TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
    : fileSystem(fs), fileFactory(ff) {}

void TouchCommand::displayInfo() {
    std::cout << "touch creates a file, touch can be invoked with the command: touch <filename>, touch -p can encrypt file." << std::endl;
}

int TouchCommand::execute(std::string args) {
    std::istringstream iss(args);
    std::string filename;
    std::string option;
    iss >> filename >> option;

    AbstractFile* file = fileFactory->createFile(filename);
    if (file == nullptr) {
        return 1;
    }

    if (option == "-p") {
        std::string password;
        std::cout << "What is the password? ";
        std::cin >> password;
        file = new PasswordProxy(file, password);
    }

    int result = fileSystem->addFile(filename, file);
    if (result != 0) {
        delete file;
        return result;
    }
    return 0;
}
