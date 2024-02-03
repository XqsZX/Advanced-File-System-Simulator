#include "../../include/mockos/SimpleFileSystem.h"
#include <iostream>

// Add a file to the file system
int SimpleFileSystem::addFile(const std::string& filename, AbstractFile* file) {
    if (file == nullptr) {
        return -1;
    }
    auto result = files.insert({ filename, file });
    if (!result.second) {
        return -2;
    }
    return 0;
}

// Create a file in the file system
//int SimpleFileSystem::createFile(const std::string& filename) {
//    if (files.find(filename) != files.end()) {
//        return -1;
//    }
//
//    // Extract the file extension
//    size_t dotPosition = filename.find_last_of('.');
//    std::string extension = (dotPosition != std::string::npos) ? filename.substr(dotPosition) : "";
//
//    AbstractFile* file = nullptr;
//    if (extension == ".txt") {
//        file = new TextFile(filename);
//    }
//    else if (extension == ".img") {
//        //file = new ImageFile(filename);
//    }
//    else {
//        return -2;
//    }
//
//    files[filename] = file;
//    return 0;
//}

// Delete a file from the file system
int SimpleFileSystem::deleteFile(const std::string& filename) {
    std::cout << "Attempting to delete: '" << filename << "'" << std::endl;
    auto fileIter = files.find(filename);
    if (fileIter == files.end()) {
        return -1;
    }

    if (openFiles.find(fileIter->second) != openFiles.end()) {
        return -2;
    }

    delete fileIter->second; // Free the memory
    files.erase(fileIter);
    return 0;
}

// Open a file in the file system
AbstractFile* SimpleFileSystem::openFile(const std::string& filename) {
    auto fileIter = files.find(filename);
    if (fileIter == files.end()) {
        return nullptr;
    }

    if (openFiles.find(fileIter->second) != openFiles.end()) {
        return nullptr;
    }

    openFiles.insert(fileIter->second);
    return fileIter->second; // Return the file pointer
}

// Close a file in the file system
int SimpleFileSystem::closeFile(AbstractFile* file) {
    if (openFiles.find(file) == openFiles.end()) {
        return -1;
    }

    openFiles.erase(file);
    return 0; // Success
}

std::set<std::string> SimpleFileSystem::getFileNames() {
    std::set<std::string> filenames;
    for (const auto& filePair : files) {
        filenames.insert(filePair.first);
    }
    return filenames;
}