#include "../../include/mockos/LSCommand.h"
#include <iostream>
#include <iomanip>

LSCommand::LSCommand(AbstractFileSystem* fs) : fileSystem(fs) {}

void LSCommand::displayInfo() {
    std::cout << "ls displays the names of all files in the system, ls -m displays names and metadata" << std::endl;
}

int LSCommand::execute(std::string args) {
    auto fileNames = fileSystem->getFileNames();

    if (args == "-m") {
        MetadataDisplayVisitor visitor;
        for (const auto& name : fileNames) {
            AbstractFile* file = fileSystem->openFile(name);
            if (file) {
                file->accept(&visitor);
                fileSystem->closeFile(file);
            }
        }
    }
    else {
        int count = 0;
        for (const auto& name : fileNames) {
            std::cout << std::left << std::setw(20) << name;
            if (++count % 2 == 0) std::cout << std::endl;
        }
        if (count % 2 != 0) std::cout << std::endl;
    }

    return 0;
}
