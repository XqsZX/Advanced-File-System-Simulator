#include "../../include/mockos/CatCommand.h"
#include <iostream>
#include <sstream>

CatCommand::CatCommand(AbstractFileSystem* fs) : fileSystem(fs) {}

void CatCommand::displayInfo() {
    std::cout << "cat concatenates a file's contents or appends data to it. Usage: cat <filename> [-a]" << std::endl;
}

int CatCommand::execute(std::string args) {
    std::istringstream iss(args);
    std::string filename, option;
    iss >> filename >> option;

    AbstractFile* file = fileSystem->openFile(filename);
    if (file == nullptr) {
        return 1; // File not found
    }

    bool appendMode = (option == "-a");
    if (appendMode) {
        std::vector<char> contents = file->read();
        for (char ch : contents) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }

    std::string line, data;
    std::cout << "Enter data (':wq' to save and quit, ':q' to quit without saving):" << std::endl;
    int res = 0;
    while (std::getline(std::cin, line)) {
        if (line == ":wq") {
            if (appendMode) {
                if (!data.empty() && data.back() == '\n') {
                    data.pop_back();
                }
                res = file->append(std::vector<char>(data.begin(), data.end()));
            }
            else {
                if (!data.empty() && data.back() == '\n') {
                    data.pop_back();
                }
                res = file->write(std::vector<char>(data.begin(), data.end()));
            }
            break;
        }
        else if (line == ":q") {
            break;
        }
        else {
            data += line + '\n';
        }
    }

    fileSystem->closeFile(file);
    return res;
}
