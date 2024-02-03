#include "../../include/mockos/CopyCommand.h"
#include <iostream>
#include <sstream>

CopyCommand::CopyCommand(AbstractFileSystem* fs) : fileSystem(fs) {}

void CopyCommand::displayInfo() {
    std::cout << "Copies a file. Usage: cp <file_to_copy> <new_name_with_no_extension>" << std::endl;
}

int CopyCommand::execute(std::string args) {
    std::istringstream iss(args);
    std::string sourceFile, newFileBaseName;
    iss >> sourceFile >> newFileBaseName;

    AbstractFile* file = fileSystem->openFile(sourceFile);
    if (file == nullptr) {
        return 1; // Source file not found
    }

    // Clone the file with a new name
    size_t dotPos = sourceFile.find_last_of('.');
    std::string extension = (dotPos != std::string::npos) ? sourceFile.substr(dotPos) : "";
    std::string newFileName = newFileBaseName + extension;

    AbstractFile* newFile = file->clone(newFileName);
    fileSystem->closeFile(file);

    if (newFile == nullptr) {
        return 2; // Failed to clone file
    }

    int result = fileSystem->addFile(newFileName, newFile);
    if (result != 0) {
        delete newFile; // Clean up
        return result; // Return the error code from addFile
    }

    return 0; // Success
}
