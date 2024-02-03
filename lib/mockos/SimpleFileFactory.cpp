#include "../../include/mockos/SimpleFileFactory.h"
#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/ImageFile.h"

AbstractFile* SimpleFileFactory::createFile(const std::string& filename) {
    // Extract the file extension
    size_t dotPosition = filename.find_last_of('.');
    std::string extension = (dotPosition != std::string::npos) ? filename.substr(dotPosition + 1) : "";

    // Based on the file extension, create the appropriate file type
    if (extension == "txt") {
        return new TextFile(filename);
    }
    else if (extension == "img") {
        return new ImageFile(filename);
    }

    return nullptr;
}
